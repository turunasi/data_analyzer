/**
 * @file utill.c
 * @author Yuki NISHII (turunasi@ruri.waseda.jp)
 * @brief utillity functions
 * @date 2021-08-07
 */

#pragma warning(disable: 4996)

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "utill.h" // 自作関数をまとめたヘッダファイル
#include "config/certification.h" // 検定データを纏めたヘッダファイル
#include "config/data_logger.h" // データロガー関連の情報をまとめたヘッダファイル
#include "config/variables.h" // グローバル変数を纏めたヘッダファイル

#define PATH_MAX_STRING_SIZE 256

// unsigned int data_u[CH_NUM][1 << 21];	//バイナリデータ用配列
// unsigned int data_u[CH_NUM][1];	//バイナリデータ用配列
unsigned int data_u[CH_NUM][DEVIDE_DATA];	//バイナリデータ用配列
// unsigned int data_u[CH_NUM][1 << 21];	//バイナリデータ用配列
// unsigned int data_temp[1 << 21];	//CH入れ替え用配列
unsigned int damy[CH_NUM][1];

void print_success(char *comment) {
    printf("\x1b[32m"); 
    printf("%s", comment);
    printf("\x1b[39m");
}

void print_warning(char *comment) {
    printf("\x1b[33m");
    printf("%s", comment);
    printf("\x1b[39m");
}

void print_error(char *comment) {
    printf("\x1b[31m");
    printf("%s", comment);
    printf("\x1b[39m");
}

/* recursive mkdir */
int mkdir_r(const char *dir) {
    char tmp[PATH_MAX_STRING_SIZE];
    char *p = NULL;
    struct stat sb;
    size_t len;
    
    /* copy path */
    len = strnlen (dir, PATH_MAX_STRING_SIZE);
    if (len == 0 || len == PATH_MAX_STRING_SIZE) {
        return -1;
    }
    memcpy (tmp, dir, len);
    tmp[len] = '\0';

    /* remove trailing slash */
    if(tmp[len - 1] == '\b') {
        tmp[len - 1] = '\0';
    }

    /* check if path exists and is a directory */
    if (stat (tmp, &sb) == 0) {
        if (S_ISDIR (sb.st_mode)) {
            return 0;
        }
    }
    /* recursive mkdir */
    for(p = tmp + 1; *p; p++) {
        if(*p == '\b') {
            *p = 0;
            /* test path */
            if (stat(tmp, &sb) != 0) {
                /* path does not exist - create directory */
                if (_mkdir(tmp) < 0) {
                    return -1;
                }
            } else if (!S_ISDIR(sb.st_mode)) {
                /* not a directory */
                return -1;
            }
            *p = '\b';
        }
    }
    /* test path */
    if (stat(tmp, &sb) != 0) {
        /* path does not exist - create directory */
        if (_mkdir(tmp) < 0) {
            return -1;
        }
    } else if (!S_ISDIR(sb.st_mode)) {
        /* not a directory */
        return -1;
    }
    return 0;
}

int sort(int fn, int is_initial, char* input_directory_path, char* output_directory_path, int ch_num1, int ch_num2) {
    // ch_num1とch_num2が指定されていればチャンネルを交換
    int use_swap = 0;
    int temp; // for swapping CH
    if (ch_num1 != 0 && ch_num2 != 0) {
        ch_num1--;
        ch_num2--;
        use_swap = 1;
    }

    int i, j, k, c;
    // unsigned int data_u[CH_NUM][DEVIDE_DATA];	//バイナリデータ用配列
    // unsigned int data_u[CH_NUM][1 << 21];	//バイナリデータ用配列
    // unsigned int data_temp[1 << 21];	//CH入れ替え用配列
    // unsigned int damy[CH_NUM][1];

    // is_initialによって分割データ数を変える
    int devide = is_initial == 1 ? DEVIDE_INITIAL : DEVIDE_DATA;

    char input_file_path[200];
    char output_number_path[200];
    char output_file_path[200];
    char comment[300];

    FILE *fp_in, *fp_out;
    struct stat buff;

    // 入力ファイルを検索
    sprintf(input_file_path, "%s/%08d.DAT", input_directory_path, fn);
    if ((fp_in = fopen(input_file_path, "rb")) == NULL) { // ファイルが見つからなかった場合
        sprintf(comment, "%s が見つかりませんでした。\n", input_file_path);
        print_error(comment);
        return 1;
    }
    // else if (feof(fp_in)){ // 空行しかなかった場合
    //     sprintf(comment, "%s を見つけたけど空でした。\n", input_file_path);
    //     print_error(comment);
    //     return 1;
    // } else { // 見つけた場合
    //     printf("%s を見つけました。\n", input_file_path);
    // }

    // out_put_directory_pathが無かったら作成
    if (stat(output_directory_path, &buff) != 0) {
        sprintf(comment, "%s が見つからないので作成します。\n", output_directory_path);
        print_warning(comment);
        mkdir_r(output_directory_path);
    }

    if (is_initial == 0) { 
        sprintf(output_number_path, "%s/%03d", output_directory_path, fn);
        if (stat(output_number_path, &buff) != 0) {
            sprintf(comment, "%s が見つからないので作成します。\n", output_number_path);
            print_warning(comment);
            mkdir_r(output_number_path);
        }
    }

    if (!is_initial) {
        printf("start count\n");
        c = 0;
        for (i = 0; ; i++) {
            for (j = 0; j < CH_NUM; j++) {
                fread(&damy[j][0], 2, 1, fp_in);
            }
            if (i % DEVIDE_DATA == 0 && i != 0) {
                c++;
                printf("\rdevide into %d files...", c);
            }
            if (feof(fp_in) != 0) {
                printf("complete count\n");
                break;
            }
        }
        // while (fgetc(fp_in) != EOF) l++;
        // c = ceil(l/32/devide);
        printf("%dのファイルに分割します。\n", c);
    } else {
        c = 1;
        printf("イニシャルファイルなので1ファイルだけ作成します。\n");
    }
    fclose(fp_in);

    fp_in = fopen(input_file_path, "rb");
    for (i = 0; i < c; i++) {
        for (j = 0; j < devide; j++) {
            for (k = 0; k < CH_NUM; k++) {
                fread(&data_u[k][j], 2, 1, fp_in);
            }
        }

        if (is_initial) {
            sprintf(output_file_path, "%s/%08di.DAT", output_directory_path, fn);
        } else {
            sprintf(output_file_path, "%s/%08d.DAT", output_number_path, i + 1);
        }
        if ((fp_out = fopen(output_file_path, "wb")) == NULL) {
            sprintf(comment, "出力ファイルの作成に失敗しました。\n");
            print_error(comment);
            return 1;
        }
        for (j = 0; j < devide; j++) {
            for (k = 0; k < CH_NUM; k++) {
                // if (use_swap) {
                // exchange ch_num1 to ch_num2
                //     temp = data_temp[ch_num1];
                //     data_temp[ch_num1] = data_temp[ch_num2];
                //     data_temp[ch_num2] = temp;
                // }
                fwrite(&data_u[k][j], 2, 1, fp_out);
            }
            fseek(fp_in, -32*350000, SEEK_CUR);
        }
        sprintf(comment, "%s の作成に成功しました。\n", output_file_path);
        print_success(comment);
        fclose(fp_out);
    }

    // make_data_logger_log(fn, output_directory_path);
    fclose(fp_in);
    sprintf(comment, "%d番目のデータは全て分割出来ました。\n", fn);
    print_success(comment);
    return 0;
}

int make_bat(int id, int before_init, int after_init, int start_file_id, int end_file_id, char* input_directory_path, char* result_directory_path, char* bat_directory_path, char* initial_directory_path, double before_P, double after_P, double before_T, double after_T, double Nrev, int make_initial, int position, int position_sp) {
    char result_file_path[200];
    char bat_file_path[200];
    char comment[200];

    FILE *fp_out;
    struct stat buff;
    
    if (make_initial != 1 && make_initial != 0) {
        sprintf(comment, "unti\n");
        print_error(comment);
        return 1;
    }
    if (position != 1 && position != 0) {
        sprintf(comment, "\n");
        print_error(comment);
        return 1;
    }
    if (position_sp != 2 && position_sp != 1 && position_sp != 0) {
        sprintf(comment, "\n");
        print_error(comment);
        return 1;
    }

    if (stat(input_directory_path, &buff) != 0) {
        sprintf(comment, "%s\n", input_directory_path);
        print_error(comment);
        return 1;
    }

    if (stat(result_directory_path, &buff) != 0) {
        sprintf(comment, "%s\n", result_directory_path);
        print_warning(comment);
        mkdir_r(result_directory_path);
    }
    sprintf(result_file_path, "%s/%03d", result_directory_path, id);

    if (stat(bat_directory_path, &buff) != 0) {
        sprintf(comment, "%s\n", bat_directory_path);
        print_warning(comment);
        mkdir_r(result_directory_path);
    }
    sprintf(bat_file_path, "%s/%03d.bat", bat_directory_path, id);
    fp_out = fopen(bat_file_path, "w");

    fprintf(fp_out, "@echo off\n");
    fprintf(fp_out, "set P_init=%f\n", before_P);
    fprintf(fp_out, "set P_end=%f\n", after_P);
    fprintf(fp_out, "set T_init=%f\n", before_T);
    fprintf(fp_out, "set T_end=%f\n", after_T);
    fprintf(fp_out, "set init_num_1=%d\n", before_init);
    fprintf(fp_out, "set init_num_2=%d\n", after_init);
    fprintf(fp_out, "set pm_num=%d\n", before_init);
    fprintf(fp_out, "set file_num_1=%d\n", start_file_id);
    fprintf(fp_out, "set file_num_2=%d\n", end_file_id);
    fprintf(fp_out, "set revol=%f\n", Nrev);
    fprintf(fp_out, "set init_or_not=%d\n", make_initial);
    fprintf(fp_out, "set position=%d\n", position);
    fprintf(fp_out, "set position_sp=%d\n", position_sp);
    // fprintf(fp_out, "set /p init_or_not=?ｿｽC?ｿｽj?ｿｽV?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽv?ｿｽ?ｿｽ?ｿｽO?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ鼾??ｿｽﾍ１?ｿｽ?ｿｽ?ｿｽ?ｿｽﾍ　?ｿｽF    \n");
    // fprintf(fp_out, "set /p position=?ｿｽf?ｿｽo?ｿｽﾇで托ｿｽ?ｿｽ?ｿｽ鼾??ｿｽ?ｿｽ1?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ,?ｿｽ?ｿｽ?ｿｽk?ｿｽ@?ｿｽ?ｿｽ?ｿｽﾅ托ｿｽ?ｿｽ?ｿｽ鼾??ｿｽ?ｿｽ0?ｿｽ?ｿｽ?ｿｽ?ｿｽﾍ　?ｿｽF    \n");
    // fprintf(fp_out, "set /p position_sp=inlet?ｿｽﾅ托ｿｽ?ｿｽ?ｿｽ鼾??ｿｽ?ｿｽ2?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ,?ｿｽ?ｿｽ?ｿｽk?ｿｽ@?ｿｽ?ｿｽ?ｿｽﾅ托ｿｽ?ｿｽ?ｿｽ鼾??ｿｽ?ｿｽ0?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ,Sp?ｿｽv?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ1?ｿｽ?ｿｽ?ｿｽ?ｿｽﾍ　?ｿｽF    \n");
    fprintf(fp_out, "\n");
    fprintf(fp_out, "set pass_prg_init=%s\n", INIT_EXE_PATH);
    fprintf(fp_out, "set pass_prg=%s\n", EXE_PATH);
    fprintf(fp_out, "\n");
    fprintf(fp_out, "set pass_init=%s\n", initial_directory_path);
    fprintf(fp_out, "set pass_in=%s\\%03d\\00000\n", input_directory_path, id);
    fprintf(fp_out, "set pass_out=%s\\%03d\n", result_directory_path, id);
    fprintf(fp_out, "if not exist %%pass_out%% mkdir %%pass_out%%\n");
    fprintf(fp_out, "set pass_pm=%s\n", initial_directory_path);
    fprintf(fp_out, "if not exist %%pass_pm%% mkdir %%pass_pm%%");
    fprintf(fp_out, "\n");
    fprintf(fp_out, "set sens_1A=%lf\n", SENS_1A);
    fprintf(fp_out, "set sens_1C=%lf\n", SENS_1C);
    fprintf(fp_out, "set sens_1E=%lf\n", SENS_1E);
    fprintf(fp_out, "set sens_2A=%lf\n", SENS_2A);
    fprintf(fp_out, "set sens_2C=%lf\n", SENS_2C);
    fprintf(fp_out, "set sens_2E=%lf\n", SENS_2E);
    fprintf(fp_out, "set sens_3A=%lf\n", SENS_3A);
    fprintf(fp_out, "set sens_3C=%lf\n", SENS_3C);
    fprintf(fp_out, "set sens_3E=%lf\n", SENS_3E);
    fprintf(fp_out, "set sens_PP=%lf\n", SENS_PP);
    fprintf(fp_out, "\n");
    fprintf(fp_out, "set sens_hwi6=%lf\n", 0.0);
    fprintf(fp_out, "set sens_hwi5=%lf\n", SENS_hwi5);
    fprintf(fp_out, "set sens_hwi4=%lf\n", SENS_hwi4);
    fprintf(fp_out, "set sens_hwi3=%lf\n", SENS_hwi3);
    fprintf(fp_out, "set sens_hwi2=%lf\n", SENS_hwi2);
    fprintf(fp_out, "set sens_hwi1=%lf\n", SENS_hwi1);
    fprintf(fp_out, "set sens_hwi0=%lf\n", SENS_hwi0);
    fprintf(fp_out, "\n");
    fprintf(fp_out, "set sens_hwi2_6=%lf\n", SENS_hwi2_6);
    fprintf(fp_out, "set sens_hwi2_5=%lf\n", SENS_hwi2_5);
    fprintf(fp_out, "set sens_hwi2_4=%lf\n", SENS_hwi2_4);
    fprintf(fp_out, "set sens_hwi2_3=%lf\n", SENS_hwi2_3);
    fprintf(fp_out, "set sens_hwi2_2=%lf\n", SENS_hwi2_2);
    fprintf(fp_out, "set sens_hwi2_1=%lf\n", SENS_hwi2_1);
    fprintf(fp_out, "set sens_hwi2_0=%lf\n", SENS_hwi2_0);
    fprintf(fp_out, "\n");
    fprintf(fp_out, "set sens_hwi3_6=%lf\n", SENS_hwi3_6);
    fprintf(fp_out, "set sens_hwi3_5=%lf\n", SENS_hwi3_5);
    fprintf(fp_out, "set sens_hwi3_4=%lf\n", SENS_hwi3_4);
    fprintf(fp_out, "set sens_hwi3_3=%lf\n", SENS_hwi3_3);
    fprintf(fp_out, "set sens_hwi3_2=%lf\n", SENS_hwi3_2);
    fprintf(fp_out, "set sens_hwi3_1=%lf\n", SENS_hwi3_1);
    fprintf(fp_out, "set sens_hwi3_0=%lf\n", SENS_hwi3_0);
    fprintf(fp_out, "\n");
    fprintf(fp_out, "set sens_hwsp1_A=%lf\n", SENS_hwsp1_A);
    fprintf(fp_out, "set sens_hwsp1_B=%lf\n", SENS_hwsp1_B);
    fprintf(fp_out, "set sens_hwsp1_n=%lf\n", SENS_hwsp1_n);
    fprintf(fp_out, "set sens_hwsp1_V1=%lf\n", SENS_hwsp1_V1);
    fprintf(fp_out, "set sens_hwsp1_K1=%lf\n", SENS_hwsp1_K1);
    fprintf(fp_out, "set sens_hwsp1_V2=%lf\n", SENS_hwsp1_V2);
    fprintf(fp_out, "set sens_hwsp1_K2=%lf\n", SENS_hwsp1_K2);
    fprintf(fp_out, "\n");
    fprintf(fp_out, "set sens_hwsp2_A=%lf\n", SENS_hwsp2_A);
    fprintf(fp_out, "set sens_hwsp2_B=%lf\n", SENS_hwsp2_B);
    fprintf(fp_out, "set sens_hwsp2_n=%lf\n", SENS_hwsp2_n);
    fprintf(fp_out, "set sens_hwsp2_V1=%lf\n", SENS_hwsp2_V1);
    fprintf(fp_out, "set sens_hwsp2_K1=%lf\n", SENS_hwsp2_K1);
    fprintf(fp_out, "set sens_hwsp2_V2=%lf\n", SENS_hwsp2_V2);
    fprintf(fp_out, "set sens_hwsp2_K2=%lf\n", SENS_hwsp2_K2);
    fprintf(fp_out, "\n");
    fprintf(fp_out, "set Q_kousei2=%lf\n", Q_KOUSEI2);
    fprintf(fp_out, "set Q_kousei1=%lf\n", Q_KOUSEI1);
    fprintf(fp_out, "set Q_kousei0=%lf\n", Q_KOUSEI0);
    fprintf(fp_out, "\n");
    fprintf(fp_out, "set P_kousei1=%lf\n", P_KOUSEI1);
    fprintf(fp_out, "set P_kousei0=%lf\n", P_KOUSEI0);
    fprintf(fp_out, "\n");
    fprintf(fp_out, "set cut_bp=%lf\n", CUT_bp);
    fprintf(fp_out, "set cut_pq=%lf\n", CUT_pq);
    fprintf(fp_out, "set cut_bp2=%lf\n", CUT_bp2);
    fprintf(fp_out, "set cut_pq2=%lf\n", CUT_pq2);
    fprintf(fp_out, "\n");
    fprintf(fp_out, "set check_FFTampspec01_1A=%d\n", CHECK_FFTampspec01_1A);
    fprintf(fp_out, "set check_FFTampspec04_2A=%d\n", CHECK_FFTampspec04_2A);
    fprintf(fp_out, "set check_FFTampspec07_3A=%d\n", CHECK_FFTampspec07_3A);
    fprintf(fp_out, "set check_FFTampspec11_hwi=%d\n", CHECK_FFTampspec11_hwi);
    fprintf(fp_out, "set check_FFTampspec12_ptpr=%d\n", CHECK_FFTampspec12_ptpr);
    fprintf(fp_out, "set check_FFTampspec18_hwi2=%d\n", CHECK_FFTampspec18_hwi2);
    fprintf(fp_out, "set check_FFTampspec25_hwi3=%d\n", CHECK_FFTampspec25_hwi3);
    fprintf(fp_out, "\n");
    fprintf(fp_out, "set check_FFTampspec33_hwsp1_vaxis=%d\n", CHECK_FFTampspec33_hwsp1_vaxis);
    fprintf(fp_out, "set check_FFTampspec34_hwsp1_vcir=%d\n", CHECK_FFTampspec34_hwsp1_vcir);
    fprintf(fp_out, "set check_FFTampspec43_hwsp2_vaxis=%d\n", CHECK_FFTampspec43_hwsp2_vaxis);
    fprintf(fp_out, "set check_FFTampspec44_hwsp2_vcir=%d\n", CHECK_FFTampspec44_hwsp2_vcir);
    fprintf(fp_out, "\n");
    fprintf(fp_out, "set check_filter01_1A=%d\n", CHECK_FILTER01_1A);
    fprintf(fp_out, "set check_filter02_1C=%d\n", CHECK_FILTER02_1C);
    fprintf(fp_out, "set check_filter03_1E=%d\n", CHECK_FILTER03_1E);
    fprintf(fp_out, "set check_filter04_2A=%d\n", CHECK_FILTER04_2A);
    fprintf(fp_out, "set check_filter05_2C=%d\n", CHECK_FILTER05_2C);
    fprintf(fp_out, "set check_filter06_2E=%d\n", CHECK_FILTER06_2E);
    fprintf(fp_out, "set check_filter07_3A=%d\n", CHECK_FILTER07_3A);
    fprintf(fp_out, "set check_filter08_3C=%d\n", CHECK_FILTER08_3C);
    fprintf(fp_out, "set check_filter09_3E=%d\n", CHECK_FILTER09_3E);
    fprintf(fp_out, "\n");
    fprintf(fp_out, "set check_filter10_pspr=%d\n", CHECK_FILTER10_pspr);
    fprintf(fp_out, "set check_filter11_hwi=%d\n", CHECK_FILTER11_hwi);
    fprintf(fp_out, "set check_filter12_ptpr=%d\n", CHECK_FILTER12_ptpr);
    fprintf(fp_out, "set check_filter13_averv=%d\n", CHECK_FILTER13_averv);
    fprintf(fp_out, "set check_filter13_spsi=%d\n", CHECK_FILTER13_spsi);
    fprintf(fp_out, "set check_filter14_psi=%d\n", CHECK_FILTER14_psi);
    fprintf(fp_out, "set check_filter15_phi=%d\n", CHECK_FILTER15_phi);
    fprintf(fp_out, "set check_filter16_phi_spsi=%d\n", CHECK_FILTER16_phi_spsi);
    fprintf(fp_out, "set check_filter18_hwi2=%d\n", CHECK_FILTER18_hwi2);
    fprintf(fp_out, "set check_filter20_phi_psi=%d\n", CHECK_FILTER20_phi_psi);
    fprintf(fp_out, "set check_filter25_hwi3=%d\n", CHECK_FILTER25_hwi3);
    fprintf(fp_out, "\n");
    fprintf(fp_out, "set check_filter31_hwsp1_v=%d\n", CHECK_FILTER31_hwsp1_v);
    fprintf(fp_out, "set check_filter32_hwsp1_alpha=%d\n", CHECK_FILTER32_hwsp1_alpha);
    fprintf(fp_out, "set check_filter33_hwsp1_vaxis=%d\n", CHECK_FILTER33_hwsp1_vaxis);
    fprintf(fp_out, "set check_filter34_hwsp1_vcir=%d\n", CHECK_FILTER34_hwsp1_vcir);
    fprintf(fp_out, "set check_filter35_ndvaxis1=%d\n", CHECK_FILTER35_ndvaxis1);
    fprintf(fp_out, "set check_filter36_ndvcir1=%d\n", CHECK_FILTER36_ndvcir1);
    fprintf(fp_out, "set check_filter37_2daverv1=%d\n", CHECK_FILTER37_2daverv1);
    fprintf(fp_out, "set check_filter38_2dphi1=%d\n", CHECK_FILTER38_2dphi1);
    fprintf(fp_out, "set check_filter39_2dphi_spsi1=%d\n", CHECK_FILTER39_2dphi_spsi1);
    fprintf(fp_out, "\n");
    fprintf(fp_out, "set check_filter41_hwsp2_v=%d\n", CHECK_FILTER41_hwsp2_v);
    fprintf(fp_out, "set check_filter42_hwsp2_alpha=%d\n", CHECK_FILTER42_hwsp2_alpha);
    fprintf(fp_out, "set check_filter43_hwsp2_vaxis=%d\n", CHECK_FILTER43_hwsp2_vaxis);
    fprintf(fp_out, "set check_filter44_hwsp2_vcir=%d\n", CHECK_FILTER44_hwsp2_vcir);
    fprintf(fp_out, "set check_filter45_ndvaxis2=%d\n", CHECK_FILTER45_ndvaxis2);
    fprintf(fp_out, "set check_filter46_ndvcir2=%d\n", CHECK_FILTER46_ndvcir2);
    fprintf(fp_out, "set check_filter47_2daverv2=%d\n", CHECK_FILTER47_2daverv2);
    fprintf(fp_out, "set check_filter48_2dphi2=%d\n", CHECK_FILTER48_2dphi2);
    fprintf(fp_out, "set check_filter49_2dphi_spsi2=%d\n", CHECK_FILTER49_2dphi_spsi2);
    fprintf(fp_out, "set check_filter51_ptank=%d\n", CHECK_FILTER51_ptank);
    fprintf(fp_out, "set check_filter52_ptank_psi=%d\n", CHECK_FILTER52_ptank_psi);
    fprintf(fp_out, "\n");
    fprintf(fp_out, "set check_rawdata01_1A=%d\n", CHECK_RAWDATA01_1A);
    fprintf(fp_out, "set check_rawdata02_1C=%d\n", CHECK_RAWDATA02_1C);
    fprintf(fp_out, "set check_rawdata03_1E=%d\n", CHECK_RAWDATA03_1E);
    fprintf(fp_out, "set check_rawdata04_2A=%d\n", CHECK_RAWDATA04_2A);
    fprintf(fp_out, "set check_rawdata05_2C=%d\n", CHECK_RAWDATA05_2C);
    fprintf(fp_out, "set check_rawdata06_2E=%d\n", CHECK_RAWDATA06_2E);
    fprintf(fp_out, "set check_rawdata07_3A=%d\n", CHECK_RAWDATA07_3A);
    fprintf(fp_out, "set check_rawdata08_3C=%d\n", CHECK_RAWDATA08_3C);
    fprintf(fp_out, "set check_rawdata09_3E=%d\n", CHECK_RAWDATA09_3E);
    fprintf(fp_out, "\n");
    fprintf(fp_out, "set check_rawdata10_pspr=%d\n", CHECK_RAWDATA10_pspr);
    fprintf(fp_out, "set check_rawdata11_hwi=%d\n", CHECK_RAWDATA11_hwi);
    fprintf(fp_out, "set check_rawdata12_ptpr=%d\n", CHECK_RAWDATA12_ptpr);
    fprintf(fp_out, "set check_rawdata13_averv=%d\n", CHECK_RAWDATA13_averv);
    fprintf(fp_out, "set check_rawdata13_spsi=%d\n", CHECK_RAWDATA13_spsi);
    fprintf(fp_out, "set check_rawdata14_psi=%d\n", CHECK_RAWDATA14_psi);
    fprintf(fp_out, "set check_rawdata15_phi=%d\n", CHECK_RAWDATA15_phi);
    fprintf(fp_out, "set check_rawdata16_phi_spsi=%d\n", CHECK_RAWDATA16_phi_spsi);
    fprintf(fp_out, "set check_rawdata18_hwi2=%d\n", CHECK_RAWDATA18_hwi2);
    fprintf(fp_out, "set check_rawdata20_phi_psi=%d\n", CHECK_RAWDATA20_phi_psi);
    fprintf(fp_out, "set check_rawdara22_valve=%d\n", CHECK_RAWDATA22_valve);
    fprintf(fp_out, "set check_rawdata25_hwi3=%d\n", CHECK_RAWDATA25_hwi3);
    fprintf(fp_out, "set check_rawdara27_plunge=%d\n", CHECK_RAWDATA27_plunge);
    fprintf(fp_out, "\n");
    fprintf(fp_out, "set check_rawdata31_hwsp1_v=%d\n", CHECK_RAWDATA31_hwsp1_v);
    fprintf(fp_out, "set check_rawdata32_hwsp1_alpha=%d\n", CHECK_RAWDATA32_hwsp1_alpha);
    fprintf(fp_out, "set check_rawdata33_hwsp1_vaxis=%d\n", CHECK_RAWDATA33_hwsp1_vaxis);
    fprintf(fp_out, "set check_rawdata34_hwsp1_vcir=%d\n", CHECK_RAWDATA34_hwsp1_vcir);
    fprintf(fp_out, "set check_rawdata35_ndvaxis1=%d\n", CHECK_RAWDATA35_ndvaxis1);
    fprintf(fp_out, "set check_rawdata36_ndvcir1=%d\n", CHECK_RAWDATA36_ndvcir1);
    fprintf(fp_out, "set check_rawdata37_2daverv1=%d\n", CHECK_RAWDATA37_2daverv1);
    fprintf(fp_out, "set check_rawdata38_2dphi1=%d\n", CHECK_RAWDATA38_2dphi1);
    fprintf(fp_out, "set check_rawdata39_2dphi_spsi1=%d\n", CHECK_RAWDATA39_2dphi_spsi1);
    fprintf(fp_out, "\n");
    fprintf(fp_out, "set check_rawdata41_hwsp2_v=%d\n", CHECK_RAWDATA41_hwsp2_v);
    fprintf(fp_out, "set check_rawdata42_hwsp2_alpha=%d\n", CHECK_RAWDATA42_hwsp2_alpha);
    fprintf(fp_out, "set check_rawdata43_hwsp2_vaxis=%d\n", CHECK_RAWDATA43_hwsp2_vaxis);
    fprintf(fp_out, "set check_rawdata44_hwsp2_vcir=%d\n", CHECK_RAWDATA44_hwsp2_vcir);
    fprintf(fp_out, "set check_rawdata45_ndvaxis2=%d\n", CHECK_RAWDATA45_ndvaxis2);
    fprintf(fp_out, "set check_rawdata46_ndvcir2=%d\n", CHECK_RAWDATA46_ndvcir2);
    fprintf(fp_out, "set check_rawdata47_2daverv2=%d\n", CHECK_RAWDATA47_2daverv2);
    fprintf(fp_out, "set check_rawdata48_2dphi2=%d\n", CHECK_RAWDATA48_2dphi2);
    fprintf(fp_out, "set check_rawdata49_2dphi_spsi2=%d\n", CHECK_RAWDATA49_2dphi_spsi2);
    fprintf(fp_out, "set check_rawdata51_ptank=%d\n", CHECK_RAWDATA51_ptank);
    fprintf(fp_out, "set check_rawdata52_ptank_psi=%d\n", CHECK_RAWDATA52_ptank_psi);
    fprintf(fp_out, "set check_rawdata_dpdt_dqdt=%d\n", CHECK_RAWDATA_dpdt_dqdt);
    fprintf(fp_out, "\n");
    fprintf(fp_out, "set log2check=%d\n", LOG2CHECK);
    fprintf(fp_out, "\n");
    fprintf(fp_out, "if \"%%init_or_not%%\"==\"1\" %%pass_prg_init%% %%init_num_1%% %%init_num_2%% %%pass_in%% %%pass_init%% %%sens_hwi5%% %%sens_hwi4%% %%sens_hwi3%% %%sens_hwi2%% %%sens_hwi1%% %%sens_hwi0%% %%pm_num%% %%sens_hwi6%%\n");
    fprintf(fp_out, "\n");
    fprintf(fp_out, "set /a i=%%file_num_1%%\n");
    fprintf(fp_out, "\n");
    fprintf(fp_out, ":LOOP\n");
    fprintf(fp_out, "   set temp_file_num=000%%i%%\n");
    fprintf(fp_out, "   set file_name=%%temp_file_num:~-3%%_result\n");
    fprintf(fp_out, "   set output_file=%pass_out%%\\%%file_name%%\n");
    fprintf(fp_out, "   if not exist %%output_file%% mkdir %%output_file%%\n");
    fprintf(fp_out, "   %%pass_prg%% %%init_num_1%% %%init_num_2%% %%i%% %%pass_init%% %%pass_in%% %%pass_out%% %%P_init%% %%T_init%% %%sens_1A%% %%sens_1C%% %%sens_1E%% %%sens_2A%% %%sens_2C%% %%sens_2E%% %%sens_3A%% %%sens_3C%% %%sens_3E%% %%sens_PP%% %%sens_hwi6%% %%sens_hwi5%% %%sens_hwi4%% %%sens_hwi3%% %%sens_hwi2%% %%sens_hwi1%% %%sens_hwi0%% %%sens_hwi2_6%% %%sens_hwi2_5%% %%sens_hwi2_4%% %%sens_hwi2_3%% %%sens_hwi2_2%% %%sens_hwi2_1%% %%sens_hwi2_0%% %%sens_hwi3_6%% %%sens_hwi3_5%% %%sens_hwi3_4%% %%sens_hwi3_3%% %%sens_hwi3_2%% %%sens_hwi3_1%% %%sens_hwi3_0%% %%sens_hwsp1_A%% %%sens_hwsp1_B%% %%sens_hwsp1_n%% %%sens_hwsp1_V1%% %%sens_hwsp1_K1%% %%sens_hwsp1_V2%% %%sens_hwsp1_K2%% %%sens_hwsp2_A%% %%sens_hwsp2_B%% %%sens_hwsp2_n%% %%sens_hwsp2_V1%% %%sens_hwsp2_K1%% %%sens_hwsp2_V2%% %%sens_hwsp2_K2%% %%Q_kousei2%% %%Q_kousei1%% %%Q_kousei0%% %%cut_bp%% %%cut_pq%% %%cut_bp2%% %%cut_pq2%% %%check_FFTampspec01_1A%% %%check_FFTampspec04_2A%% %%check_FFTampspec07_3A%% %%check_FFTampspec12_ptpr%% %%check_FFTampspec11_hwi%% %%check_FFTampspec18_hwi2%% %%check_FFTampspec25_hwi3%% %%check_FFTampspec33_hwsp1_vaxis%% %%check_FFTampspec34_hwsp1_vcir%% %%check_FFTampspec43_hwsp2_vaxis%% %%check_FFTampspec44_hwsp2_vcir%% %%check_filter01_1A%% %%check_filter02_1C%% %%check_filter03_1E%% %%check_filter04_2A%% %%check_filter05_2C%% %%check_filter06_2E%% %%check_filter07_3A%% %%check_filter08_3C%% %%check_filter09_3E%% %%check_filter11_hwi%% %%check_filter18_hwi2%% %%check_filter25_hwi3%% %%check_filter31_hwsp1_v%% %%check_filter32_hwsp1_alpha%% %%check_filter33_hwsp1_vaxis%% %%check_filter34_hwsp1_vcir%% %%check_filter35_ndvaxis1%% %%check_filter36_ndvcir1%% %%check_filter37_2daverv1%% %%check_filter38_2dphi1%% %%check_filter39_2dphi_spsi1%% %%check_filter41_hwsp2_v%% %%check_filter42_hwsp2_alpha%% %%check_filter43_hwsp2_vaxis%% %%check_filter44_hwsp2_vcir%% %%check_filter45_ndvaxis2%% %%check_filter46_ndvcir2%% %%check_filter47_2daverv2%% %%check_filter48_2dphi2%% %%check_filter49_2dphi_spsi2%% %%check_filter13_averv%% %%check_filter15_phi%% %%check_filter10_pspr%% %%check_filter12_ptpr%% %%check_filter13_spsi%% %%check_filter14_psi%% %%check_filter20_phi_psi%% %%check_filter16_phi_spsi%% %%check_rawdata01_1A%% %%check_rawdata02_1C%% %%check_rawdata03_1E%% %%check_rawdata04_2A%% %%check_rawdata05_2C%% %%check_rawdata06_2E%% %%check_rawdata07_3A%% %%check_rawdata08_3C%% %%check_rawdata09_3E%% %%check_rawdata11_hwi%% %%check_rawdata18_hwi2%% %%check_rawdata25_hwi3%% %%check_rawdata31_hwsp1_v%% %%check_rawdata32_hwsp1_alpha%% %%check_rawdata33_hwsp1_vaxis%% %%check_rawdata34_hwsp1_vcir%% %%check_rawdata35_ndvaxis1%% %%check_rawdata36_ndvcir1%% %%check_rawdata37_2daverv1%% %%check_rawdata38_2dphi1%% %%check_rawdata39_2dphi_spsi1%% %%check_rawdata41_hwsp2_v%% %%check_rawdata42_hwsp2_alpha%% %%check_rawdata43_hwsp2_vaxis%% %%check_rawdata44_hwsp2_vcir%% %%check_rawdata45_ndvaxis2%% %%check_rawdata46_ndvcir2%% %%check_rawdata47_2daverv2%% %%check_rawdata48_2dphi2%% %%check_rawdata49_2dphi_spsi2%% %%check_rawdata13_averv%% %%check_rawdata15_phi%% %%check_rawdata10_pspr%% %%check_rawdata12_ptpr%% %%check_rawdata13_spsi%% %%check_rawdata14_psi%% %%check_rawdata20_phi_psi%% %%check_rawdata16_phi_spsi%% %%check_rawdata_dpdt_dqdt%% %%check_rawdara22_valve%% %%check_rawdara27_plunge%% %%revol%% %%log2check%% %%pass_pm%% %%pm_num%% %%P_end%% %%T_end%% %%position%% %%position_sp%% %%P_kousei1%% %%P_kousei0%% %%check_rawdata51_ptank%% %%check_rawdata52_ptank_psi%% %%check_filter51_ptank%% %%check_filter52_ptank_psi%%\n");
    fprintf(fp_out, "\n");
    fprintf(fp_out, "    if \"%%i%%\"==\"%%file_num_2%%\" goto EXIT\n");
    fprintf(fp_out, "\n");
    fprintf(fp_out, "    set /a i=i+1\n");
    fprintf(fp_out, "\n");
    fprintf(fp_out, "goto LOOP\n");
    fprintf(fp_out, ":EXIT\n");
    fprintf(fp_out, "pause\n");

    fclose(fp_out);

    return 0;
}

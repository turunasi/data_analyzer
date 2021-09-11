/**
 * @file make_bat.c
 * @author Yuki NISHII (turunasi@ruri.waseda.jp)
 * @brief バッチファイルを作成するプログラムのソース
 * @date 2021-09-10
 */

// scanf等の安全でないスキャン関数に対する警告を無視する設定
#pragma warning(disable: 4996)

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "../utill.h" // よく使う関数を纏めた自作ヘッダ
#include "../config/certification.h" // 検定データを纏めたヘッダ

#define INIT_EXE_PATH "C:/Users/small/Desktop/data_analyzer/bin/make_data.exe"
#define EXE_PATH "C:/Users/small/Desktop/data_analyzer/bin/make_data.exe"

int main(int argc, char *argv[]) {

    int id = atoi(argv[1]);
    int before_init = atoi(argv[3]);
    int after_init = atoi(argv[4]);
    int start_file_id = atoi(argv[5]);
    int end_file_id = atoi(argv[6]);
    char *input_directory_path = argv[7];
    char *result_directory_path = argv[8];
    char *bat_directory_path = argv[9];
    char *initial_directory_path = argv[10];
    double before_P = atof(argv[11]);
    double after_P = atof(argv[12]);
    double before_T = atof(argv[13]);
    double after_T = atof(argv[14]);
    double Nrev = atof(argv[15]);

    // char *posit_out = POSIT_OUT;
    // char *posit_out_2 = POSIT_OUT_2;

    char result_file_path[200];
    char bat_file_path[200];
    char comment[200];

    FILE *fp_out;
    struct stat buff;

    // printf("データフォルダ名(ex  181019_1)\n");  //日付はここで入れてる//
    // scanf("%s", &posint_name_ID);

    // printf("開始ID:\n");
    // scanf("%d", &start_id);
    // printf("終了ID:\n");
    // scanf("%d", &end_id);

    // printf("計算開始ファイル番号:\n");
    // scanf("%d", &start_file_id);
    // printf("終了ファイル番号:\n");
    // scanf("%d", &end_file_id);

    // printf("イニシャルNo１:\n");
    // scanf("%d", &before_init);
    // printf("イニシャルNo2:\n");
    // scanf("%d", &after_init);

    // printf("開始大気圧:\n");
    // scanf("%lf", &before_P);
    // printf("終了大気圧:\n");
    // scanf("%lf", &after_P);
        
    // printf("開始温度:\n");
    // scanf("%lf", &before_T);
    // printf("終了温度:\n");
    // scanf("%lf", &after_T);

    // printf("回転数:\n");
    // scanf("%lf", &Nrev);

    // printf("%s\n", posint_name_ID);

    if (stat(input_directory_path, &buff) != 0) { // 入力データが無かったらエラー
        sprintf(comment, "%s がありません！パスの指定を間違っていませんか？\n", input_directory_path);
        exit_with_error(comment);
    }

    if (stat(result_directory_path, &buff) != 0) {
        sprintf(comment, "%s が無かったので作成します。\n", result_directory_path);
        print_warning(comment);
        mkdir_r_777(result_directory_path);
    }
    sprintf(result_file_path, "%s/%03d", result_directory_path, id);

    if (stat(bat_directory_path, &buff) != 0) {
        sprintf(comment, "%s が無かったので作成します。\n", bat_directory_path);
        print_warning(comment);
        mkdir_r_777(result_directory_path);
    }
    sprintf(bat_file_path, "%s/%03d.bat", bat_directory_path, id);
    fp_out = fopen(bat_file_path, "w");

    fprintf(fp_out, "@echo off\n");
    fprintf(fp_out, "\n");
    fprintf(fp_out, "echo    *******************************************************************************\n");
    fprintf(fp_out, "echo    データ作成を一気に行う、まさに夢のようなバッチです。\n");
    fprintf(fp_out, "echo    *******************************************************************************\n");
    fprintf(fp_out, "\n");
    fprintf(fp_out, "rem ＜***************環境変数に数値を代入***********************＞arrenged by さかてぃー 2018(新データレコーダテスト仕様)\n");
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
    fprintf(fp_out, "set /p init_or_not=イニシャルプログラムかける場合は１を入力　：    \n");
    fprintf(fp_out, "set /p position=吐出管で測る場合は1を入力,圧縮機内で測る場合は0を入力　：    \n");
    fprintf(fp_out, "set /p position_sp=inletで測る場合は2を入力,圧縮機内で測る場合は0を入力,Sp計測無しは1を入力　：    \n");
    fprintf(fp_out, "\n");
    fprintf(fp_out, "set pass_prg_init=%s\n", INIT_EXE_PATH);
    fprintf(fp_out, "set pass_prg=%s\n", EXE_PATH);
    fprintf(fp_out, "\n");
    fprintf(fp_out, "set pass_init=%s\n", initial_directory_path);
    fprintf(fp_out, "set pass_in=%s/%03d/00000\n", input_directory_path, id);
    fprintf(fp_out, "set pass_out=%s/%03d\n", result_directory_path, id);
    fprintf(fp_out, "set pass_pm=%s\n", initial_directory_path);
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
    fprintf(fp_out, "set sens_hwi6=%lf\n", SENS_hwi6);
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
    fprintf(fp_out, "set P_kousei1=%lf\n", P_KOUSEI1);    //必要ない値
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
    fprintf(fp_out, "set check_filter10_pspr=%d\n", CHECK_FILTER10_pspr);  //性能壁圧上昇
    fprintf(fp_out, "set check_filter11_hwi=%d\n", CHECK_FILTER11_hwi);  //軸流速（熱線I型）
    fprintf(fp_out, "set check_filter12_ptpr=%d\n", CHECK_FILTER12_ptpr);  //性能全圧上昇
    fprintf(fp_out, "set check_filter13_averv=%d\n", CHECK_FILTER13_averv);  //圧縮機内平均軸流速
    fprintf(fp_out, "set check_filter13_spsi=%d\n", CHECK_FILTER13_spsi);  //静圧上昇係数ψs
    fprintf(fp_out, "set check_filter14_psi=%d\n", CHECK_FILTER14_psi);  //全圧上昇係数ψ
    fprintf(fp_out, "set check_filter15_phi=%d\n", CHECK_FILTER15_phi);  //流量係数φ
    fprintf(fp_out, "set check_filter16_phi_spsi=%d\n", CHECK_FILTER16_phi_spsi);  //φ-ψ（静圧上昇係数）
    fprintf(fp_out, "set check_filter18_hwi2=%d\n", CHECK_FILTER18_hwi2);  //内部流れ（I型熱線）
    fprintf(fp_out, "set check_filter20_phi_psi=%d\n", CHECK_FILTER20_phi_psi);  //φ-ψ
    fprintf(fp_out, "set check_filter25_hwi3=%d\n", CHECK_FILTER25_hwi3);  //内部流れ（I型熱線）
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
    fprintf(fp_out, "rem ＜***************イニシャルプログラム実行********************＞        \n");
    fprintf(fp_out, "if \"%%init_or_not%%\"==\"1\"  %%pass_prg_init%%  %%init_num_1%%  %%init_num_2%%  %%pass_in%%  %%pass_init%% %%sens_hwi5%% %%sens_hwi4%% %%sens_hwi3%% %%sens_hwi2%% %%sens_hwi1%% %%sens_hwi0%% %%pm_num%% %%sens_hwi6%%        \n");
    fprintf(fp_out, "\n");
    fprintf(fp_out, "rem ＜***************データ作成プログラム実行********************＞        \n");
    fprintf(fp_out, "set /a i=%%file_num_1%%\n");
    fprintf(fp_out, "\n");
    fprintf(fp_out, ":LOOP\n");
    fprintf(fp_out, "%%pass_prg%% %%init_num_1%% %%init_num_2%% %%i%% %%pass_init%% %%pass_in%% %%pass_out%% %%P_init%% %%T_init%% %%sens_1A%% %%sens_1C%% %%sens_1E%% %%sens_2A%% %%sens_2C%% %%sens_2E%% %%sens_3A%% %%sens_3C%%  %%sens_3E%% %%sens_PP%% %%sens_hwi6%% %%sens_hwi5%% %%sens_hwi4%% %%sens_hwi3%% %%sens_hwi2%% %%sens_hwi1%% %%sens_hwi0%% %%sens_hwi2_6%% %%sens_hwi2_5%% %%sens_hwi2_4%% %%sens_hwi2_3%% %%sens_hwi2_2%% %%sens_hwi2_1%% %%sens_hwi2_0%% %%sens_hwi3_6%% %%sens_hwi3_5%% %%sens_hwi3_4%% %%sens_hwi3_3%% %%sens_hwi3_2%% %%sens_hwi3_1%% %%sens_hwi3_0%% %%sens_hwsp1_A%% %%sens_hwsp1_B%% %%sens_hwsp1_n%% %%sens_hwsp1_V1%% %%sens_hwsp1_K1%% %%sens_hwsp1_V2%% %%sens_hwsp1_K2%% %%sens_hwsp2_A%% %%sens_hwsp2_B%% %%sens_hwsp2_n%% %%sens_hwsp2_V1%%%%sens_hwsp2_K1%% %%sens_hwsp2_V2%% %%sens_hwsp2_K2%% %%Q_kousei2%% %%Q_kousei1%% %%Q_kousei0%% %%cut_bp%% %%cut_pq%% %%cut_bp2%% %%cut_pq2%% %%check_FFTampspec01_1A%% %%check_FFTampspec04_2A%% %%check_FFTampspec07_3A%% %%check_FFTampspec12_ptpr%% %%check_FFTampspec11_hwi%% %%check_FFTampspec18_hwi2%% %%check_FFTampspec25_hwi3%% %%check_FFTampspec33_hwsp1_vaxis%% %%check_FFTampspec34_hwsp1_vcir%% %%check_FFTampspec43_hwsp2_vaxis%% %%check_FFTampspec44_hwsp2_vcir%% %%check_filter01_1A%% %%check_filter02_1C%% %%check_filter03_1E%% %%check_filter04_2A%% %%check_filter05_2C%% %%check_filter06_2E%% %%check_filter07_3A%% %%check_filter08_3C%% %%check_filter09_3E%% %%check_filter11_hwi%% %%check_filter18_hwi2%% %%check_filter25_hwi3%% %%check_filter31_hwsp1_v%% %%check_filter32_hwsp1_alpha%% %%check_filter33_hwsp1_vaxis%% %%check_filter34_hwsp1_vcir%% %%check_filter35_ndvaxis1%% %%check_filter36_ndvcir1%% %%check_filter37_2daverv1%% %%check_filter38_2dphi1%% %%check_filter39_2dphi_spsi1%% %%check_filter41_hwsp2_v%% %%check_filter42_hwsp2_alpha%% %%check_filter43_hwsp2_vaxis%% %%check_filter44_hwsp2_vcir%% %%check_filter45_ndvaxis2%% %%check_filter46_ndvcir2%% %%check_filter47_2daverv2%% %%check_filter48_2dphi2%% %%check_filter49_2dphi_spsi2%% %%check_filter13_averv%% %%check_filter15_phi%% %%check_filter10_pspr%% %%check_filter12_ptpr%% %%check_filter13_spsi%% %%check_filter14_psi%% %%check_filter20_phi_psi%% %%check_filter16_phi_spsi%% %%check_rawdata01_1A%% %%check_rawdata02_1C%% %%check_rawdata03_1E%% %%check_rawdata04_2A%% %%check_rawdata05_2C%% %%check_rawdata06_2E%% %%check_rawdata07_3A%%  %%check_rawdata08_3C%% %%check_rawdata09_3E%% %%check_rawdata11_hwi%% %%check_rawdata18_hwi2%% %%check_rawdata25_hwi3%% %%check_rawdata31_hwsp1_v%% %%check_rawdata32_hwsp1_alpha%% %%check_rawdata33_hwsp1_vaxis%% %%check_rawdata34_hwsp1_vcir%% %%check_rawdata35_ndvaxis1%% %%check_rawdata36_ndvcir1%% %%check_rawdata37_2daverv1%% %%check_rawdata38_2dphi1%% %%check_rawdata39_2dphi_spsi1%% %%check_rawdata41_hwsp2_v%% %%check_rawdata42_hwsp2_alpha%% %%check_rawdata43_hwsp2_vaxis%% %%check_rawdata44_hwsp2_vcir%% %%check_rawdata45_ndvaxis2%% %%check_rawdata46_ndvcir2%% %%check_rawdata47_2daverv2%% %%check_rawdata48_2dphi2%% %%check_rawdata49_2dphi_spsi2%% %%check_rawdata13_averv%% %%check_rawdata15_phi%% %%check_rawdata10_pspr%% %%check_rawdata12_ptpr%% %%check_rawdata13_spsi%% %%check_rawdata14_psi%% %%check_rawdata20_phi_psi%% %%check_rawdata16_phi_spsi%% %%check_rawdata_dpdt_dqdt%% %%check_rawdara22_valve%% %%check_rawdara27_plunge%% %%revol%% %%log2check%% %%pass_pm%% %%pm_num%% %%P_end%% %%T_end%% %%position%% %%position_sp%% %%P_kousei1%% %%P_kousei0%% %%check_rawdata51_ptank%% %%check_rawdata52_ptank_psi%% %%check_filter51_ptank%% %%check_filter52_ptank_psi%%        \n");
    fprintf(fp_out, "\n");
    fprintf(fp_out, "    if \"%%i%%\"==\"%%file_num_2%%\" goto EXIT\n");
    fprintf(fp_out, "\n");
    fprintf(fp_out, "    set /a i=i+1\n");
    fprintf(fp_out, "\n");
    fprintf(fp_out, "    goto LOOP\n");
    fprintf(fp_out, ":EXIT\n");
    fprintf(fp_out, "pause\n");

    fclose(fp_out);

    return 0;
}
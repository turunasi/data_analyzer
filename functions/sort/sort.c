/**
 * @file sort.c
 * @author Yuki NISHII (turunasi@ruri.waseda.jp)
 * @brief データロガーで取ってきた1レコード分を分割するコマンド(sort)のソース
 * @date 2021-08-07
 */

// scanf等の安全でないスキャン関数に対する警告を無視する設定
#pragma warning(disable: 4996)

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>
#include "../utill.h" // よく使う関数を纏めた自作ヘッダ
#include "../config/data_logger.h" // データロガーの情報を纏めた自作ヘッダ

#define DEVIDE_INITIAL 105000  // 分割データ数(イニシャル)
#define DEVIDE_DATA    1050000 // 分割データ数(普通のデータ)

/**
 * @param argc コマンド化した時の引数の総数(コマンド自体も含める)
 * @param argv 引数の具体的な値が格納された配列
 * 
 * @param argv[0] コマンド名 使うことはない
 * @param argv[1] データナンバー
 * @param argv[2] イニシャルなら1,そうでないなら0
 * @param argv[3] 入力データが格納されたパス 2021-8-7ではdata/210807
 * @param argv[4] 出力データが格納されたパス 2021-8-7ではsorted_data/210807
 * @param argv[5] スワップチャンネル数1 データロガーのチャンネルを間違えた場合に交換するCH
 * @param argv[6] スワップチャンネル数2 データロガーのチャンネルを間違えた場合に交換するCH
 */
int main(int argc, char *argv[]) {

    bool use_swap = (argc == 7); // スワップチャンネルが入力されているかどうか. 入力されていればスワップを使うと判定.
    int fn = atoi(argv[1]);
    bool is_initial = atoi(argv[2]) == 1 ? true : false;
    char *input_directory_path = argv[3];
    char *output_directory_path = argv[4];

    // スワップするCHを定義
    int ch_num1,ch_num2;
    unsigned int temp; // for swapping CH
    if (use_swap) {
        ch_num1 = atoi(argv[5]) - 1;
        ch_num2 = atoi(argv[6]) - 1;
    }

    int i, j, k, c= 0;
    unsigned int data_u[CH_NUM];
    // 三項演算子を用いてデータ分割数をイニシャルかどうかで値を切り替える
    int devide = is_initial ? DEVIDE_INITIAL : DEVIDE_DATA;
    
    printf("devide : %d", devide);

    char input_file_path[200];
    char output_number_path[200];
    char output_file_path[200];
    char comment[300];

    FILE *fp_in, *fp_out;
    struct stat buff;

    // インプットファイルのパスを作成
    sprintf(input_file_path, "%s/%08d.DAT", input_directory_path, fn);
    if ((fp_in = fopen(input_file_path, "rb")) == NULL) { // インプットファイルが無かったら
        sprintf(comment, "%s is not found.\n", input_file_path);
        exit_with_error(comment);
    } else if (feof(fp_in)){ // インプットファイルはあるけど中身が空だったら
        sprintf(comment, "%s contains nothing.\n", input_file_path);
        exit_with_error(comment);
    } else { // インプットファイルがちゃんとあったら
        printf("found %s\n", input_file_path);
    }

    // イニシャルならフォルダ名にiをつける
    if (is_initial) { 
        sprintf(output_number_path, "%s/%03di", output_directory_path, fn);
    } else {
        sprintf(output_number_path, "%s/%03d", output_directory_path, fn);
    }
    if (stat(output_number_path, &buff) != 0) { // フォルダが無かったら作成
        sprintf(comment, "%s is not exist. make directory.\n", output_number_path);
        print_warning(comment);
        mkdir_r_777(output_number_path);
    }

    // イニシャルでないならファイルの行数をデータ分割数で割った商分ファイルを小分けする
    if (!is_initial) {
        i = 1;
        while ((c = fgetc(fp_in)) != EOF) i++;
        c = i/devide;
        printf("%d columns, devined into %d files.\n", i, c);
    } else { // イニシャルなら入力データが短いので1こで十分
        c = 1;
    }

    for (i = 0; i < c; i++) {
        // イニシャルなら保存ファイル名にiをつける
        if (is_initial) {
            sprintf(output_file_path, "%s/%08di.dat", output_number_path, i + 1);
        } else {
            sprintf(output_file_path, "%s/%08d.dat", output_number_path, i + 1);
        }
        if ((fp_out = fopen(output_file_path, "wb")) == NULL) { // 保存ファイルが開けなかったら
            sprintf(comment, "failed to make %s.\n", output_file_path);
            exit_with_error(comment);
        }
        // データ抽出
        for (j = 0; j < devide; j++) {
            for (k = 0; k < CH_NUM; k++) {
                fread(&data_u[k], 2, 1, fp_in);
                if (use_swap) { // CHを入れ替えるなら
                    // exchange ch_num1 to ch_num2
                    temp = data_u[ch_num1];
                    data_u[ch_num1] = data_u[ch_num2];
                    data_u[ch_num2] = temp;
                }
                fwrite(&data_u[k], 2, 1, fp_out);
            }
        }
        sprintf(comment, "%s was made successfully.\n", output_file_path);
        print_success(comment);
        fclose(fp_out);
    }

    fclose(fp_in);

    make_data_logger_log(fn, output_number_path);
    sprintf(comment, "complete data %d.\n", fn);
    exit_with_success(comment);
}



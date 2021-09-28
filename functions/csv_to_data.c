/**
 * @file csv_to_data.c
 * @author Yuki NISHII (turunasi@ruri.waseda.jp)
 * @brief データ分割→バッチ作成→バッチ実行を纏めて行う。
 * @date 2021-09-10
 */

// scanf等の安全でないスキャン関数に対する警告を無視する設定
#pragma warning(disable: 4996)

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "utill.h" // よく使う関数を纏めた自作ヘッダ
#include "config/variables.h" // グローバル定数を纏めたヘッダ
#include "config/csv.h" // CSV読み込みに使う関数等を纏めたヘッダ

#define DEFAULT_DATA_DIRECTORY "DAT"
#define DEFAULT_SORTED_DATA_DIRECTORY "DAT2"
#define DEFAULT_INITIAL_DIRECTORY "initial"
#define DEFAULT_RESULT_DIRECTORY "result"
#define DEFAULT_BATCH_DIRECTORY "bat"

int main(void) {
    int i,j;
    int fn;
    int is_skip;
    int is_initial;
    int before_init;
    int after_init;
    int csv_row_num;
    int make_initial;
    int position;
    int position_sp;
    int ch_num1, ch_num2;
    double before_P, after_P, before_T, after_T, Nrev;

    char* csv_file_path;
    char* home_directory_path;
    char* date_name;
    char* input_directory_path;
    char* output_directory_path;
    char* initial_directory_path;
    char* result_directory_path;
    char* batch_directory_path;

    char comment[300];

    FILE *fp_csv;
    struct stat buff;

    scanf("CSVファイルのパスを入力してください : %s", csv_file_path);

    double csv_data[TOTAL_ROW_NUM][TOTAL_COL_NUM];
    if (get_csv_value(csv_file_path, csv_data) == -1.0) {
        sprintf(comment, "CSVデータの取得に失敗しました...\n");
        exit_with_error(comment);
    }

    scanf("データが纏められているディレクトリのパスを入力してください ex) 21Axial/21data : %s", home_directory_path);
    if (stat(home_directory_path, &buff) != 0) {
        sprintf(comment, "%s がありませんでした...\n", home_directory_path);
        exit_with_error(comment);
    }

    scanf("データ取得日を入力してください ex) 210915 : %s", date_name);

    while(1) {
        scanf("イニシャルファイルを作成する場合は1を、作成しないならば0を指定してください : %d", &make_initial);
        if (make_initial != 1 && make_initial != 0) {
            sprintf(comment, "イニシャルファイルを作成する場合は1を、作成しないならば0を指定してください。\n");
            print_warning(comment);
        } else {
            break;
        }
    }
    while(1) {
        scanf("計測した系の設定が吐出管なら1、圧縮機なら0を指定してください : %d", &position);
        if (position != 1 && position != 0) {
            sprintf(comment, "計測した系の設定が不正です。吐出管なら1、圧縮機なら0を指定してください。\n");
            print_warning(comment);
        } else {
            break;
        }
    }
    while(1) {
        scanf("静圧を測定した場所がインレットなら2を、圧縮機内部なら1を、測定しなければ指定してください。 : %d", &position_sp);
        if (position_sp != 2 && position_sp != 1 && position_sp != 0) {
            sprintf(comment, "静圧を測定した場所の指定が不正です。インレットなら2を、圧縮機内部なら1を、測定しなければ指定してください。\n");
            print_warning(comment);
        } else {
            break;
        }
    }
    
    sprintf(input_directory_path, "%s/%s/%s", home_directory_path, DEFAULT_DATA_DIRECTORY, date_name);
    sprintf(output_directory_path, "%s/%s/%s", home_directory_path, DEFAULT_SORTED_DATA_DIRECTORY, date_name);
    
    // データを分割
    for (int i = 0; i <= TOTAL_ROW_NUM; i++){
        fn = (int)csv_data[i][ID_COL-2];
        is_skip = (int)csv_data[i][SKIP_COL-2];
        is_initial = (int)csv_data[i][INITIAL_COL-2];
        ch_num1 = 0;
        ch_num2 = 0;
        if (sort(fn, is_initial, input_directory_path, output_directory_path, ch_num1, ch_num2)) {
            sprintf(comment, "%dの分割に失敗しました。\n", fn);
            exit_with_error(comment);
        }
    }

    sprintf(initial_directory_path, "%s/%s/%s", home_directory_path, DEFAULT_INITIAL_DIRECTORY, date_name);
    sprintf(result_directory_path, "%s/%s/%s", home_directory_path, DEFAULT_RESULT_DIRECTORY, date_name);
    sprintf(batch_directory_path, "%s/%s/%s", home_directory_path, DEFAULT_BATCH_DIRECTORY, date_name);

    for (int i = 0; i <= TOTAL_ROW_NUM; i++){
        fn = (int)csv_data[i][ID_COL-2];
        is_skip = (int)csv_data[i][SKIP_COL-2];
        is_initial = (int)csv_data[i][INITIAL_COL-2];
        before_init = (int)csv_data[i][BEFORE_INI_COL-2];
        after_init = (int)csv_data[i][AFTER_INI_COL-2];
        before_P = csv_data[before_init][P_COL-2];
        after_P = csv_data[after_init][P_COL-2];
        before_T = csv_data[before_init][T_COL-2];
        after_T = csv_data[after_init][T_COL-2];

        ch_num1 = 0;
        ch_num2 = 0;
        if (make_bat(fn, before_init, after_init, 1, 100, input_directory_path, result_directory_path, batch_directory_path, initial_directory_path, before_P, after_P, before_T, after_T, Nrev, make_initial, position, position_sp)) {
            sprintf(comment, "%dのバッチファイル作成に失敗しました。\n", fn);
            exit_with_error(comment);
        }
    }
}

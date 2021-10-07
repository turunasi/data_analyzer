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
#include "utill.h" // よく使う関数を纏めた自作ヘッダ

/**
 * @param argc コマンド化した時の引数の総数(コマンド自体も含める)
 * @param argv 引数の具体的な値が格納された配列
 * 
 * @param argv[0] コマンド名 使うことはない
 * @param argv[1] データナンバー
 * @param argv[2] 実験開始時initial
 * @param argv[3] 実験終了時initial
 * @param argv[4] 分割後データを取り込む開始ID
 * @param argv[5] 分割後データを取り込む終了ID
 * @param argv[6] 入力データが格納されたパス 2021-8-7ではsorted_data/210807
 * @param argv[7] 出力データを格納するパス 2021-8-7ではresult/210807
 * @param argv[8] バッチファイルを格納するパス 2021-8-7ではbat/210807
 * @param argv[9] イニシャルファイルを格納するパス 2021-8-7ではinitial/210807
 * @param argv[10] 実験開始時圧力(mmHg)
 * @param argv[11] 実験終了時圧力(mmHg)
 * @param argv[12] 実験開始時温度(℃)
 * @param argv[13] 実験開始時温度(℃)
 * @param argv[14] 修正回転数(Hz)
 * @param argv[15] イニシャルファイルを作成するか 1:Yes/0:No
 * @param argv[16] 吐出管か圧縮機か 1:吐出管/0:圧縮機
 * @param argv[17] 静圧をどこで計測するか 2:inlet/1:圧縮機内部/0:計測なし
 */
int main(int argc, char *argv[]) {
    int id = atoi(argv[1]);
    int before_init = atoi(argv[2]);
    int after_init = atoi(argv[3]);
    int start_file_id = atoi(argv[4]);
    int end_file_id = atoi(argv[5]);
    char *input_directory_path = argv[6];
    char *result_directory_path = argv[7];
    char *bat_directory_path = argv[8];
    char *initial_directory_path = argv[9];
    double before_P = atof(argv[10]);
    double after_P = atof(argv[11]);
    double before_T = atof(argv[12]);
    double after_T = atof(argv[13]);
    double Nrev = atof(argv[14]);
    int make_initial = atoi(argv[15]);
    int position = atoi(argv[16]);
    int position_sp = atoi(argv[17]);
    
    return make_bat(id, before_init, after_init, start_file_id, end_file_id, input_directory_path, result_directory_path, bat_directory_path, initial_directory_path, before_P, after_P, before_T, after_T, Nrev, make_initial, position, position_sp);
}
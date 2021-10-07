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
#include "utill.h" // よく使う関数を纏めた自作ヘッダ

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
    int fn = atoi(argv[1]);
    int is_initial = atoi(argv[2]);
    char *input_directory_path = argv[3];
    char *output_directory_path = argv[4];
    int ch_num1 = argv[5] != NULL ? atoi(argv[5]) : 0;
    int ch_num2 = argv[6] != NULL ? atoi(argv[6]) : 0;
    return sort(fn, is_initial, input_directory_path, output_directory_path, ch_num1, ch_num1);
}
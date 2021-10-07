// scanf等の安全でないスキャン関数に対する警告を無視する設定
#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "csv.h"
#include "../utill.h" // よく使う関数を纏めた自作ヘッダ

double get_csv_value(char* csv_file_path, double csv_data[TOTAL_ROW_NUM][TOTAL_COL_NUM]) {
    int No;
    char comment[300];
    char row[1000];
    char* str; 
    FILE *fp;

    if ((fp = fopen(csv_file_path, "r")) == NULL) { // CSVが無かったら
        sprintf(comment, "%s が無いですよ！\n", csv_file_path);
        print_error(comment);
        return -1.0;
    }

    for (int i = HEADER_ROW; i < TOTAL_ROW_NUM; i++) {
        fgets(row, sizeof(row), fp);
        if (i == HEADER_ROW) continue; // ヘッダ行は無視
        // 1列目(No)
        str = strtok(row, ",");
        No = atoi(str) - 1; // idは1始まりだが配列は0始まりであるため
        if (No == 0) break; // id未定義ならCSVを全て読み切ったと判断
        // 2列目以降
        for (int j = 0; j < TOTAL_COL_NUM; j++) {
            switch (j + 1) {
            case SKIP_COL:
            case INITIAL_COL:
                csv_data[i][j] = str == "Y" ? 1.0 : 0.0;
                break;
            default:
                csv_data[i][j] = atof(str);
                break;
            }
        }
    }
}
// scanf等の安全でないスキャン関数に対する警告を無視する設定
#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "csv.h"
#include "../utill.h" // よく使う関数を纏めた自作ヘッダ

int get_row_num(char* csv_file_path) {
    int i = 0;
    int c = 0;
    char comment[300];
    char* col;
    FILE *fp;

    if ((fp = fopen(csv_file_path, "r")) == NULL) { // CSVが無かったら
        sprintf(comment, "%s が無いですよ！\n", csv_file_path);
        print_error(comment);
        return -1;
    }
    while (fgetc(fp) != EOF) i++;
    return i;
}

void get_csv_value(char* csv_file_path, double csv_data[][TOTAL_COL_NUM]) {
    int i = 0;
    int id, col;
    int row_num = get_row_num(csv_file_path);
    if (row_num == -1) return;
    char comment[300];
    char* row;
    char* str; 
    FILE *fp;

    if ((fp = fopen(csv_file_path, "r")) == NULL) { // CSVが無かったら
        sprintf(comment, "%s が無いですよ！\n", csv_file_path);
        print_error(comment);
        return;
    }

    while ((row = fgetc(fp) ) != EOF) {
        // 1列目(id)
        str = strtok(row, ",");
        id = atoi(str)-HEADER_ROW;
        col = 0;
        // 2列目以降
        while((str = strtok(NULL, ",")) != NULL) {
            // 元CSVからレコードID列分引く&配列に入れるので-2
            switch (col - 2) {
            case SKIP_COL:
            case INITIAL_COL:
                csv_data[id][col] = str == "Y" ? 1.0 : 0.0;
                break;
            default:
                csv_data[id][col] = atof(str);
                break;
            }
            col++;
        }
    }
}
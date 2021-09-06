// scanf等の安全でないスキャン関数に対する警告を無視する設定
#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>
#include "../utill.h" // よく使う関数を纏めた自作ヘッダ

int main(int argc, char *argv[]) {
    int i, j, num;
    int init_num[10] = {};
    int init_flg;
    char answer;
    char init_row[200];
    char *tp;
    char input_file_path[200];
    char output_file_path[200];
    char command[300];
    printf("sort all data");
    scanf("input total number:%d", &num);
    scanf("input initial data number(separated space):%s", &init_row);
    tp = strtok(init_row, " ");
    i = 0;
    while( tp != NULL ) {
        init_num[i] = (int)tp;
        i++;
    }
    scanf("input input directory path:%s", &input_file_path);
    scanf("input output directory path:%s", &output_file_path);
    printf("\x1b[32m");
    printf("total number : %d", num);
    printf("initial      : ");
    for (size_t i = 0; i < SIZE_OF_ARRAY(init_num); i++) {
        if (init_num[i] == 0) continue;
        printf("%d ", init_num[i]);
    }
    printf("input path   : %s", input_file_path);
    printf("output path  : %s", output_file_path);
    printf("\x1b[39m");
    scanf("Continue? [y/N] :%c", &answer);
    if (answer != 'y') {
        exit_with_error("Aborted.");
    }
    init_flg = 0;
    for (i = 1; i <= num; i++) {
        for (j = 0; j < SIZE_OF_ARRAY(init_num); j++) {
            if (i == init_num[j]){
                init_flg = 1
                ./sort $i 1 $IN_PATH $OUT_PATH
                break;
            }
        }
        sprintf(command, "./sort %d 1 %s %s", input_file_path);
        init_flg=0
    }
}
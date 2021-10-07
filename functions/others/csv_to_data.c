/**
 * @file csv_to_data.c
 * @author Yuki NISHII (turunasi@ruri.waseda.jp)
 * @brief �f�[�^�������o�b�`�쐬���o�b�`���s��Z�߂čs���B
 * @date 2021-09-10
 */

// scanf���̈��S�łȂ��X�L�����֐��ɑ΂���x���𖳎�����ݒ�
#pragma warning(disable: 4996)

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "utill.h" // �悭�g���֐���Z�߂�����w�b�_
#include "config/variables.h" // �O���[�o���萔��Z�߂��w�b�_
#include "config/csv.h" // CSV�ǂݍ��݂Ɏg���֐�����Z�߂��w�b�_

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

    scanf("CSV�t�@�C���̃p�X����͂��Ă������� : %s", csv_file_path);

    double csv_data[TOTAL_ROW_NUM][TOTAL_COL_NUM];
    if (get_csv_value(csv_file_path, csv_data) == -1.0) {
        sprintf(comment, "CSV�f�[�^�̎擾�Ɏ��s���܂���...\n");
        print_error(comment);
        return 1;
    }

    scanf("�f�[�^���Z�߂��Ă���f�B���N�g���̃p�X����͂��Ă������� ex) 21Axial/21data : %s", home_directory_path);
    if (stat(home_directory_path, &buff) != 0) {
        sprintf(comment, "%s ������܂���ł���...\n", home_directory_path);
        print_error(comment);
        return 1;
    }

    scanf("�f�[�^�擾������͂��Ă������� ex) 210915 : %s", date_name);

    while(1) {
        scanf("�C�j�V�����t�@�C�����쐬����ꍇ��1���A�쐬���Ȃ��Ȃ��0���w�肵�Ă������� : %d", &make_initial);
        if (make_initial != 1 && make_initial != 0) {
            sprintf(comment, "�C�j�V�����t�@�C�����쐬����ꍇ��1���A�쐬���Ȃ��Ȃ��0���w�肵�Ă��������B\n");
            print_warning(comment);
        } else {
            break;
        }
    }
    while(1) {
        scanf("�v�������n�̐ݒ肪�f�o�ǂȂ�1�A���k�@�Ȃ�0���w�肵�Ă������� : %d", &position);
        if (position != 1 && position != 0) {
            sprintf(comment, "�v�������n�̐ݒ肪�s���ł��B�f�o�ǂȂ�1�A���k�@�Ȃ�0���w�肵�Ă��������B\n");
            print_warning(comment);
        } else {
            break;
        }
    }
    while(1) {
        scanf("�È��𑪒肵���ꏊ���C�����b�g�Ȃ�2���A���k�@�����Ȃ�1���A���肵�Ȃ���Ύw�肵�Ă��������B : %d", &position_sp);
        if (position_sp != 2 && position_sp != 1 && position_sp != 0) {
            sprintf(comment, "�È��𑪒肵���ꏊ�̎w�肪�s���ł��B�C�����b�g�Ȃ�2���A���k�@�����Ȃ�1���A���肵�Ȃ���Ύw�肵�Ă��������B\n");
            print_warning(comment);
        } else {
            break;
        }
    }
    
    sprintf(input_directory_path, "%s/%s/%s", home_directory_path, DEFAULT_DATA_DIRECTORY, date_name);
    sprintf(output_directory_path, "%s/%s/%s", home_directory_path, DEFAULT_SORTED_DATA_DIRECTORY, date_name);
    
    // �f�[�^�𕪊�
    for (int i = 0; i <= TOTAL_ROW_NUM; i++){
        fn = (int)csv_data[i][ID_COL-2];
        is_skip = (int)csv_data[i][SKIP_COL-2];
        is_initial = (int)csv_data[i][INITIAL_COL-2];
        ch_num1 = 0;
        ch_num2 = 0;
        if (sort(fn, is_initial, input_directory_path, output_directory_path, ch_num1, ch_num2)) {
            sprintf(comment, "%d�̕����Ɏ��s���܂����B\n", fn);
            print_error(comment);
            return 1;
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
            sprintf(comment, "%d�̃o�b�`�t�@�C���쐬�Ɏ��s���܂����B\n", fn);
            print_error(comment);
            return 1;
        }
    }
}

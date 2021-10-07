/**
 * @file sort.c
 * @author Yuki NISHII (turunasi@ruri.waseda.jp)
 * @brief �f�[�^���K�[�Ŏ���Ă���1���R�[�h���𕪊�����R�}���h(sort)�̃\�[�X
 * @date 2021-08-07
 */

// scanf���̈��S�łȂ��X�L�����֐��ɑ΂���x���𖳎�����ݒ�
#pragma warning(disable: 4996)
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "utill.h" // �悭�g���֐���Z�߂�����w�b�_

/**
 * @param argc �R�}���h���������̈����̑���(�R�}���h���̂��܂߂�)
 * @param argv �����̋�̓I�Ȓl���i�[���ꂽ�z��
 * 
 * @param argv[0] �R�}���h�� �g�����Ƃ͂Ȃ�
 * @param argv[1] �f�[�^�i���o�[
 * @param argv[2] �C�j�V�����Ȃ�1,�����łȂ��Ȃ�0
 * @param argv[3] ���̓f�[�^���i�[���ꂽ�p�X 2021-8-7�ł�data/210807
 * @param argv[4] �o�̓f�[�^���i�[���ꂽ�p�X 2021-8-7�ł�sorted_data/210807
 * @param argv[5] �X���b�v�`�����l����1 �f�[�^���K�[�̃`�����l�����ԈႦ���ꍇ�Ɍ�������CH
 * @param argv[6] �X���b�v�`�����l����2 �f�[�^���K�[�̃`�����l�����ԈႦ���ꍇ�Ɍ�������CH
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
/**
 * @file make_bat.c
 * @author Yuki NISHII (turunasi@ruri.waseda.jp)
 * @brief �o�b�`�t�@�C�����쐬����v���O�����̃\�[�X
 * @date 2021-09-10
 */

// scanf���̈��S�łȂ��X�L�����֐��ɑ΂���x���𖳎�����ݒ�
#pragma warning(disable: 4996)

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "utill.h" // �悭�g���֐���Z�߂�����w�b�_
#include "config/certification.h" // ����f�[�^��Z�߂��w�b�_�t�@�C��

/**
 * @param argc �R�}���h���������̈����̑���(�R�}���h���̂��܂߂�)
 * @param argv �����̋�̓I�Ȓl���i�[���ꂽ�z��
 * 
 * @param argv[0] �R�}���h�� �g�����Ƃ͂Ȃ�
 * @param argv[1] �f�[�^�i���o�[
 * @param argv[2] �����J�n��initial
 * @param argv[3] �����I����initial
 * @param argv[4] ������f�[�^����荞�ފJ�nID
 * @param argv[5] ������f�[�^����荞�ޏI��ID
 * @param argv[6] ���̓f�[�^���i�[���ꂽ�p�X 2021-8-7�ł�sorted_data/210807
 * @param argv[7] �o�̓f�[�^���i�[����p�X 2021-8-7�ł�result/210807
 * @param argv[8] �o�b�`�t�@�C�����i�[����p�X 2021-8-7�ł�bat/210807
 * @param argv[9] �C�j�V�����t�@�C�����i�[����p�X 2021-8-7�ł�initial/210807
 * @param argv[10] �����J�n������(mmHg)
 * @param argv[11] �����I��������(mmHg)
 * @param argv[12] �����J�n�����x(��)
 * @param argv[13] �����J�n�����x(��)
 * @param argv[14] �C����]��(Hz)
 * @param argv[15] �C�j�V�����t�@�C�����쐬���邩 1:Yes/0:No
 * @param argv[16] �f�o�ǂ����k�@�� 1:�f�o��/0:���k�@
 * @param argv[17] �È����ǂ��Ōv�����邩 2:inlet/1:���k�@����/0:�v���Ȃ�
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
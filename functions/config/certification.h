/**
 * @file certification.h
 * @author Yuki NISHII (turunasi@ruri.waseda.jp)
 * @brief ����f�[�^��Z�߂��w�b�_
 * @date 2021-09-10
 */
#ifndef CERTIFICATION
#define CERTIFICATION

// �Z���T�[�֘A�W��
// ���̓Z���T
#define SENS_1A 4.144556586 // 3��
#define SENS_1C 3.972407086 // 5��
#define SENS_1E 0.0         // �s�g�p
#define SENS_2A 4.016772575 // 7��
#define SENS_2C 0.0         // �s�g�p
#define SENS_2E 3.961821536 // 9��
#define SENS_3A 0.0         // �s�g�p
#define SENS_3C 3.958681297 // 11��
#define SENS_3E 8.018976385 // tank
#define SENS_PP 7.989149673 // ���\

// �M��(hot wire)
// ���\
#define SENS_hwi6 0.0
#define SENS_hwi5 0.44262
#define SENS_hwi4 -5.74981
#define SENS_hwi3 30.32191
#define SENS_hwi2 -73.17994
#define SENS_hwi1 80.88207
#define SENS_hwi0 -33.25097
// ����(21-09-09)�s�g�p
#define SENS_hwi2_6 0.0
#define SENS_hwi2_5 0.0
#define SENS_hwi2_4 0.0
#define SENS_hwi2_3 0.0
#define SENS_hwi2_2 0.0
#define SENS_hwi2_1 0.0
#define SENS_hwi2_0 0.0
// ARB
#define SENS_hwi3_6 0.0
#define SENS_hwi3_5 0.19627
#define SENS_hwi3_4 -1.97060
#define SENS_hwi3_3 9.18070
#define SENS_hwi3_2 -19.61043
#define SENS_hwi3_1 15.12872
#define SENS_hwi3_0 0.0
// �X�v���b�g1(�s�g�p)
#define SENS_hwsp1_A 5.070829616
#define SENS_hwsp1_B 3.889611319
#define SENS_hwsp1_n 0.461122582
#define SENS_hwsp1_V1 -0.918641477
#define SENS_hwsp1_K1 0.000131454
#define SENS_hwsp1_V2 -0.028414113
#define SENS_hwsp1_K2 -0.02670639
// �X�v���b�g2(�s�g�p)
#define SENS_hwsp2_A 3.305689449
#define SENS_hwsp2_B 2.747121643
#define SENS_hwsp2_n 0.466596201
#define SENS_hwsp2_V1 3.066784144
#define SENS_hwsp2_K1 0.00155836
#define SENS_hwsp2_V2 -0.284716625
#define SENS_hwsp2_K2 0.019539874

// ���ʍZ���l
#define Q_KOUSEI2 0.0
#define Q_KOUSEI1 0.0
#define Q_KOUSEI0 0.92861
#define P_KOUSEI1 0.0
#define P_KOUSEI0 0.0

// �t�B���^�[�p�X
#define CUT_bp 3000.0
#define CUT_pq 10.0
#define CUT_bp2 20.0
#define CUT_pq2 0.0

// �ǂ̃f�[�^���o�͂��邩 0:�o�͂��Ȃ� 1:�o�͂���
// FFT
#define CHECK_FFTampspec01_1A 1
#define CHECK_FFTampspec04_2A 1
#define CHECK_FFTampspec07_3A 1
#define CHECK_FFTampspec11_hwi 1
#define CHECK_FFTampspec12_ptpr 1
#define CHECK_FFTampspec18_hwi2 0
#define CHECK_FFTampspec25_hwi3 1
#define CHECK_FFTampspec33_hwsp1_vaxis 0
#define CHECK_FFTampspec34_hwsp1_vcir 0
#define CHECK_FFTampspec43_hwsp2_vaxis 0
#define CHECK_FFTampspec44_hwsp2_vcir 0
// �t�B���^�[�g�`
#define CHECK_FILTER01_1A 1
#define CHECK_FILTER02_1C 1
#define CHECK_FILTER03_1E 0
#define CHECK_FILTER04_2A 1
#define CHECK_FILTER05_2C 0
#define CHECK_FILTER06_2E 1
#define CHECK_FILTER07_3A 0
#define CHECK_FILTER08_3C 1
#define CHECK_FILTER09_3E 1
#define CHECK_FILTER10_pspr 1 // ���\�ǈ��㏸
#define CHECK_FILTER11_hwi 1 // ������(�M��I�^)
#define CHECK_FILTER12_ptpr 1 // ���\�S���㏸
#define CHECK_FILTER13_averv 1 // ���k�@�����ώ�����
#define CHECK_FILTER13_spsi 1 // �È��㏸�W����s
#define CHECK_FILTER14_psi 1 // �S���㏸�W����
#define CHECK_FILTER15_phi 1 // ���ʌW����
#define CHECK_FILTER16_phi_spsi 1 //��-��(�È��㏸�W��)
#define CHECK_FILTER18_hwi2 0 //��������(I�^�M��)
#define CHECK_FILTER20_phi_psi 1 //��-��
#define CHECK_FILTER25_hwi3 1 //��������(I�^�M��)
#define CHECK_FILTER31_hwsp1_v 0
#define CHECK_FILTER32_hwsp1_alpha 0
#define CHECK_FILTER33_hwsp1_vaxis 0
#define CHECK_FILTER34_hwsp1_vcir 0
#define CHECK_FILTER35_ndvaxis1 0
#define CHECK_FILTER36_ndvcir1 0
#define CHECK_FILTER37_2daverv1 0
#define CHECK_FILTER38_2dphi1 0
#define CHECK_FILTER39_2dphi_spsi1 0
#define CHECK_FILTER41_hwsp2_v 0
#define CHECK_FILTER42_hwsp2_alpha 0
#define CHECK_FILTER43_hwsp2_vaxis 0
#define CHECK_FILTER44_hwsp2_vcir 0
#define CHECK_FILTER45_ndvaxis2 0
#define CHECK_FILTER46_ndvcir2 0
#define CHECK_FILTER47_2daverv2 0
#define CHECK_FILTER48_2dphi2 0
#define CHECK_FILTER49_2dphi_spsi2 0
#define CHECK_FILTER51_ptank 1
#define CHECK_FILTER52_ptank_psi 1
// ���g�`
#define CHECK_RAWDATA01_1A 1
#define CHECK_RAWDATA02_1C 1
#define CHECK_RAWDATA03_1E 0
#define CHECK_RAWDATA04_2A 1
#define CHECK_RAWDATA05_2C 0
#define CHECK_RAWDATA06_2E 1
#define CHECK_RAWDATA07_3A 0
#define CHECK_RAWDATA08_3C 1
#define CHECK_RAWDATA09_3E 1
#define CHECK_RAWDATA10_pspr 1
#define CHECK_RAWDATA11_hwi 1
#define CHECK_RAWDATA12_ptpr 1
#define CHECK_RAWDATA13_averv 1
#define CHECK_RAWDATA13_spsi 1
#define CHECK_RAWDATA14_psi 1
#define CHECK_RAWDATA15_phi 1
#define CHECK_RAWDATA16_phi_spsi 1
#define CHECK_RAWDATA18_hwi2 0
#define CHECK_RAWDATA20_phi_psi 1
#define CHECK_RAWDATA22_valve 1
#define CHECK_RAWDATA25_hwi3 1
#define CHECK_RAWDATA27_plunge 0
#define CHECK_RAWDATA31_hwsp1_v 0
#define CHECK_RAWDATA32_hwsp1_alpha 0
#define CHECK_RAWDATA33_hwsp1_vaxis 0
#define CHECK_RAWDATA34_hwsp1_vcir 0
#define CHECK_RAWDATA35_ndvaxis1 0
#define CHECK_RAWDATA36_ndvcir1 0
#define CHECK_RAWDATA37_2daverv1 0
#define CHECK_RAWDATA38_2dphi1 0
#define CHECK_RAWDATA39_2dphi_spsi1 0
#define CHECK_RAWDATA41_hwsp2_v 0
#define CHECK_RAWDATA42_hwsp2_alpha 0
#define CHECK_RAWDATA43_hwsp2_vaxis 0
#define CHECK_RAWDATA44_hwsp2_vcir 0
#define CHECK_RAWDATA45_ndvaxis2 0
#define CHECK_RAWDATA46_ndvcir2 0
#define CHECK_RAWDATA47_2daverv2 0
#define CHECK_RAWDATA48_2dphi2 0
#define CHECK_RAWDATA49_2dphi_spsi2 0
#define CHECK_RAWDATA_dpdt_dqdt 1
#define CHECK_RAWDATA51_ptank 1
#define CHECK_RAWDATA52_ptank_psi 1

#define LOG2CHECK 1

#endif

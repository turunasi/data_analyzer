/**
 * @file certification.h
 * @author Yuki NISHII (turunasi@ruri.waseda.jp)
 * @brief 検定データを纏めたヘッダ
 * @date 2021-09-10
 */
#ifndef CERTIFICATION
#define CERTIFICATION

// センサー関連係数
// 圧力センサ
#define SENS_1A 4.526199698
#define SENS_1C 4.845398644
#define SENS_1E 0.0
#define SENS_2A 4.120702845
#define SENS_2C 0.0
#define SENS_2E 4.025784603
#define SENS_3A 0.0
#define SENS_3C 4.021323379
#define SENS_3E 8.056979258
#define SENS_PP 7.911825119 // 性能
// 熱線(hot wire)
// 性能
#define SENS_hwi6 0.0
#define SENS_hwi5 0.24732
#define SENS_hwi4 -2.76090
#define SENS_hwi3 12.80764
#define SENS_hwi2 -24.04679
#define SENS_hwi1 15.31619
#define SENS_hwi0 0.0
// 現状(21-09-09)不使用
#define SENS_hwi2_6 0.0
#define SENS_hwi2_5 0.0
#define SENS_hwi2_4 0.0
#define SENS_hwi2_3 0.0
#define SENS_hwi2_2 0.0
#define SENS_hwi2_1 0.0
#define SENS_hwi2_0 0.0
// ARB
#define SENS_hwi3_6 0.09973
#define SENS_hwi3_5 -1.37642
#define SENS_hwi3_4 7.34643
#define SENS_hwi3_3 -17.33213
#define SENS_hwi3_2 18.68650
#define SENS_hwi3_1 -7.61247
#define SENS_hwi3_0 0.0
// スプリット1(不使用)
#define SENS_hwsp1_A 5.070829616
#define SENS_hwsp1_B 3.889611319
#define SENS_hwsp1_n 0.461122582
#define SENS_hwsp1_V1 -0.918641477
#define SENS_hwsp1_K1 0.000131454
#define SENS_hwsp1_V2 -0.028414113
#define SENS_hwsp1_K2 -0.02670639
// スプリット2(不使用)
#define SENS_hwsp2_A 3.305689449
#define SENS_hwsp2_B 2.747121643
#define SENS_hwsp2_n 0.466596201
#define SENS_hwsp2_V1 3.066784144
#define SENS_hwsp2_K1 0.00155836
#define SENS_hwsp2_V2 -0.284716625
#define SENS_hwsp2_K2 0.019539874

// 流量校正値
#define Q_KOUSEI2 0.90366
#define Q_KOUSEI1 0.866918477
#define Q_KOUSEI0 0.88256
#define P_KOUSEI1 3388.8
#define P_KOUSEI0 0.0

// フィルターパス
#define CUT_bp 3000.0
#define CUT_pq 20.0
#define CUT_bp2 20.0
#define CUT_pq2 0.0

// どのデータを出力するか 0:出力しない 1:出力する
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
// フィルター波形
#define CHECK_FILTER01_1A 1
#define CHECK_FILTER02_1C 1
#define CHECK_FILTER03_1E 0
#define CHECK_FILTER04_2A 1
#define CHECK_FILTER05_2C 0
#define CHECK_FILTER06_2E 1
#define CHECK_FILTER07_3A 0
#define CHECK_FILTER08_3C 1
#define CHECK_FILTER09_3E 1
#define CHECK_FILTER10_pspr 1 // 性能壁圧上昇
#define CHECK_FILTER11_hwi 1 // 軸流速(熱線I型)
#define CHECK_FILTER12_ptpr 1 // 性能全圧上昇
#define CHECK_FILTER13_averv 1 // 圧縮機内平均軸流速
#define CHECK_FILTER13_spsi 1 // 静圧上昇係数ψs
#define CHECK_FILTER14_psi 1 // 全圧上昇係数ψ
#define CHECK_FILTER15_phi 1 // 流量係数φ
#define CHECK_FILTER16_phi_spsi 1 //φ-ψ(静圧上昇係数)
#define CHECK_FILTER18_hwi2 0 //内部流れ(I型熱線)
#define CHECK_FILTER20_phi_psi 1 //φ-ψ
#define CHECK_FILTER25_hwi3 1 //内部流れ(I型熱線)
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
// 生波形
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
//*************************************************************************************************************
//コマンドライン引数を変数に代入するための関数
//*************************************************************************************************************
//＜（重要）センサ感度とアンプ増幅率について＞
//・アンプ
//		センサ供給電圧：5[V]、増幅率：100[倍]
//・エントラン製圧力センサ
//		センサ供給電圧が5[V]の場合、25[psi]で感度[mV]出力される。
//・キュライト製圧力センサ
//		電源電圧が10[V]の場合、1[PSI]あたり感度[mV]出力される。
//		でも、電源電圧は半分の5[V]で使ってるから、感度も半分になるお。（重要）
//
//（参考）1[psi] = 6.89476 [kPa]
//*************************************************************************************************************

//標準ライブラリのインクルード
#include <stdlib.h>
#include "定数・構造体定義.h"

//-------------------------------------------------------------------------------------------------------------
//コマンドライン引数を変数に代入するための関数
//-------------------------------------------------------------------------------------------------------------
void Substitution_CL( char *argv[], st_kojiku *kojiku){

	//コマンドライン引数を変数に代入----------------------------------------------------------------
	kojiku->file.num.init1		= atoi(argv[1]);	//文字列をint型に型変換
	kojiku->file.num.init2		= atoi(argv[2]);
	kojiku->file.num.data		= atoi(argv[3]);
	kojiku->file.posit.init		= argv[4];
	kojiku->file.posit.in		= argv[5];
	kojiku->file.posit.out		= argv[6];
	kojiku->atm.P_init				= atof(argv[7]);	//文字列をdouble型に型変換・[kPa]に換算
	kojiku->atm.T_init				= atof(argv[8]);	//文字列をdouble型に型変換・[kPa]に換算

	//圧力センサの感度について
	// ＜具体例＞
	//	1[psi] = 6.89476[kPa] (※psi = pound per square inch)
	//	sens = 57.06[mV/FS]  (※FS = Range = 25[psi])
	//	25[psi]/57.06[mV]
	//	→ (25 / 57.06[psi])/1[mV]
	//	→ (25 * 1000 / 57.06[psi])/1[V]
	//	→ ここで、検出された値が3[V]なら、アンプによって100倍に増幅されているため本当は3/100[V]で、
	//　→ (3/100) * 25 * 1000 / 57.06[psi] が検出されていることになり、
	//　→ 1[psi] = 6.89476[kPa]　なので、
	//　→ (3/100) * 25 * 1000 * 6.89476 / 57.06[kPa] のように圧力が算出できる。
	//	∴ 25 * 1000 * 6.89476 / (100 * 57.06)[kPa/V]
	//	として、センサ感度を設定することで、検出された電圧値[V]をかけるだけで圧力値[kPa]に換算できる

	kojiku->sens.wp1A			= 1000.0/100.0*6.89476/atof(argv[9])*2.0;	//文字列を変換して圧力センサの感度に換算
	kojiku->sens.wp1C			= 1000.0/100.0*6.89476/atof(argv[10])*2.0;
	kojiku->sens.wp1E			= 1000.0/100.0*6.89476/atof(argv[11])*2.0;
	kojiku->sens.wp2A			= 1000.0/100.0*6.89476/atof(argv[12])*2.0;
	kojiku->sens.wp2C			= 1000.0/100.0*6.89476/atof(argv[13])*2.0;
	kojiku->sens.wp2E			= 1000.0/100.0*6.89476/atof(argv[14])*2.0;
	kojiku->sens.wp3A			= 1000.0/100.0*6.89476/atof(argv[15])*2.0;
	kojiku->sens.wp3C			= 1000.0/100.0*6.89476/atof(argv[16])*2.0;
	kojiku->sens.wp3E			= 1000.0/100.0*6.89476/atof(argv[17])*2.0;
	kojiku->sens.pspr			= 1000.0/100.0*6.89476/atof(argv[18])*2.0;

	kojiku->sens.hwi.__6		= atof(argv[19]);//検定結果をバッチファイルから読み込む
	kojiku->sens.hwi.__5		= atof(argv[20]);
	kojiku->sens.hwi.__4		= atof(argv[21]);
	kojiku->sens.hwi.__3		= atof(argv[22]);
	kojiku->sens.hwi.__2		= atof(argv[23]);
	kojiku->sens.hwi.__1		= atof(argv[24]);
	kojiku->sens.hwi.__0		= atof(argv[25]);
	kojiku->sens.hwi2.__6		= atof(argv[25]);//検定結果をバッチファイルから読み込む
	kojiku->sens.hwi2.__5		= atof(argv[27]);
	kojiku->sens.hwi2.__4		= atof(argv[28]);
	kojiku->sens.hwi2.__3		= atof(argv[29]);
	kojiku->sens.hwi2.__2		= atof(argv[30]);
	kojiku->sens.hwi2.__1		= atof(argv[31]);
	kojiku->sens.hwi2.__0		= atof(argv[32]);
	kojiku->sens.hwi3.__6		= atof(argv[33]);//検定結果をバッチファイルから読み込む
	kojiku->sens.hwi3.__5 = atof(argv[34]);
	kojiku->sens.hwi3.__4 = atof(argv[35]);
	kojiku->sens.hwi3.__3 = atof(argv[36]);
	kojiku->sens.hwi3.__2 = atof(argv[37]);
	kojiku->sens.hwi3.__1 = atof(argv[38]);
	kojiku->sens.hwi3.__0 = atof(argv[39]);

	kojiku->sens.hwsp1.A			= atof(argv[40]);//検定結果をバッチファイルから読み込む
	kojiku->sens.hwsp1.B			= atof(argv[41]);
	kojiku->sens.hwsp1.n			= atof(argv[42]);
	kojiku->sens.hwsp1.K1		= atof(argv[43]);
	kojiku->sens.hwsp1.V1		= atof(argv[44]);
	kojiku->sens.hwsp1.K2		= atof(argv[45]);
	kojiku->sens.hwsp1.V2		= atof(argv[46]);

	kojiku->sens.hwsp2.A			= atof(argv[47]);//検定結果をバッチファイルから読み込む
	kojiku->sens.hwsp2.B			= atof(argv[48]);
	kojiku->sens.hwsp2.n			= atof(argv[49]);
	kojiku->sens.hwsp2.K1		= atof(argv[50]);
	kojiku->sens.hwsp2.V1		= atof(argv[51]);
	kojiku->sens.hwsp2.K2		= atof(argv[52]);
	kojiku->sens.hwsp2.V2		= atof(argv[53]);

	kojiku->sens.kousei.__2		= atof(argv[54]);//流量校正の結果をバッチファイルから読み込む
	kojiku->sens.kousei.__1		= atof(argv[55]);
	kojiku->sens.kousei.__0		= atof(argv[56]);

	kojiku->freq.cut1			= atof(argv[57]);//1stBPFの半分以上の周波数はカット
	kojiku->freq.cut2			= atof(argv[58]);//20Hz以上の周波数をカットしてサージングを見やすくする
	kojiku->freq.cut3			= atof(argv[59]);
	kojiku->freq.cut4			= atof(argv[60]);

	//バッチファイルの値が0か1かで出力を判断できる
	kojiku->check.check_FFTampspec01_1A			= atoi(argv[61]);
	kojiku->check.check_FFTampspec04_2A			= atoi(argv[62]);
	kojiku->check.check_FFTampspec07_3A			= atoi(argv[63]);
	kojiku->check.check_FFTampspec12_ptpr		= atoi(argv[64]);
	kojiku->check.check_FFTampspec11_hwi		= atoi(argv[65]);
	kojiku->check.check_FFTampspec18_hwi2		= atoi(argv[66]);	
	kojiku->check.check_FFTampspec25_hwi3		= atoi(argv[67]);
	kojiku->check.check_FFTampspec33_hwsp1_vaxis		= atoi(argv[68]);
	kojiku->check.check_FFTampspec34_hwsp1_vcir		= atoi(argv[69]);
	kojiku->check.check_FFTampspec43_hwsp2_vaxis		= atoi(argv[70]);
	kojiku->check.check_FFTampspec44_hwsp2_vcir		= atoi(argv[71]);

	kojiku->check.check_filter01_1A				= atoi(argv[72]);
	kojiku->check.check_filter02_1C				= atoi(argv[73]);
	kojiku->check.check_filter03_1E				= atoi(argv[74]);
	kojiku->check.check_filter04_2A				= atoi(argv[75]);
	kojiku->check.check_filter05_2C				= atoi(argv[76]);
	kojiku->check.check_filter06_2E				= atoi(argv[77]);
	kojiku->check.check_filter07_3A				= atoi(argv[78]);
	kojiku->check.check_filter08_3C				= atoi(argv[79]);
	kojiku->check.check_filter09_3E				= atoi(argv[80]);

	kojiku->check.check_filter11_hwi			= atoi(argv[81]);
	kojiku->check.check_filter18_hwi2			= atoi(argv[82]);
	kojiku->check.check_filter25_hwi3			= atoi(argv[83]);

	kojiku->check.check_filter31_hwsp1_v			= atoi(argv[84]);
	kojiku->check.check_filter32_hwsp1_alpha		= atoi(argv[85]);
	kojiku->check.check_filter33_hwsp1_vaxis		= atoi(argv[86]);
	kojiku->check.check_filter34_hwsp1_vcir		= atoi(argv[87]);
	kojiku->check.check_filter35_ndvaxis1		= atoi(argv[88]);
	kojiku->check.check_filter36_ndvcir1			= atoi(argv[89]);
	kojiku->check.check_filter37_2daverv1		= atoi(argv[90]);
	kojiku->check.check_filter38_2dphi1		= atoi(argv[91]);
	kojiku->check.check_filter39_2dphi_psi1		= atoi(argv[92]);

	kojiku->check.check_filter41_hwsp2_v			= atoi(argv[93]);
	kojiku->check.check_filter42_hwsp2_alpha		= atoi(argv[94]);
	kojiku->check.check_filter43_hwsp2_vaxis		= atoi(argv[95]);
	kojiku->check.check_filter44_hwsp2_vcir		= atoi(argv[96]);
	kojiku->check.check_filter45_ndvaxis2		= atoi(argv[97]);
	kojiku->check.check_filter46_ndvcir2			= atoi(argv[98]);
	kojiku->check.check_filter47_2daverv2		= atoi(argv[99]);
	kojiku->check.check_filter48_2dphi2		= atoi(argv[100]);
	kojiku->check.check_filter49_2dphi_psi2		= atoi(argv[101]);

	kojiku->check.check_filter13_averv			= atoi(argv[102]);
	kojiku->check.check_filter15_phi			= atoi(argv[103]);
	kojiku->check.check_filter10_pspr			= atoi(argv[104]);
	kojiku->check.check_filter12_ptpr			= atoi(argv[105]);
	kojiku->check.check_filter13_spsi			= atoi(argv[106]);
	kojiku->check.check_filter14_psi			= atoi(argv[107]);
	kojiku->check.check_filter20_phi_psi		= atoi(argv[108]);
	kojiku->check.check_filter16_phi_spsi		= atoi(argv[109]);

	kojiku->check.check_rawdata01_1A			= atoi(argv[110]);
	kojiku->check.check_rawdata02_1C			= atoi(argv[111]);
	kojiku->check.check_rawdata03_1E			= atoi(argv[112]);
	kojiku->check.check_rawdata04_2A			= atoi(argv[113]);
	kojiku->check.check_rawdata05_2C			= atoi(argv[114]);
	kojiku->check.check_rawdata06_2E			= atoi(argv[115]);
	kojiku->check.check_rawdata07_3A			= atoi(argv[116]);
	kojiku->check.check_rawdata08_3C			= atoi(argv[117]);
	kojiku->check.check_rawdata09_3E			= atoi(argv[118]);

	kojiku->check.check_rawdata11_hwi			= atoi(argv[119]);
	kojiku->check.check_rawdata18_hwi2			= atoi(argv[120]);
	kojiku->check.check_rawdata25_hwi3			= atoi(argv[121]);

	kojiku->check.check_rawdata31_hwsp1_v			= atoi(argv[122]);
	kojiku->check.check_rawdata32_hwsp1_alpha		= atoi(argv[123]);
	kojiku->check.check_rawdata33_hwsp1_vaxis		= atoi(argv[124]);
	kojiku->check.check_rawdata34_hwsp1_vcir		= atoi(argv[125]);
	kojiku->check.check_rawdata35_ndvaxis1		= atoi(argv[126]);
	kojiku->check.check_rawdata36_ndvcir1			= atoi(argv[127]);
	kojiku->check.check_rawdata37_2daverv1		= atoi(argv[128]);
	kojiku->check.check_rawdata38_2dphi1		= atoi(argv[129]);
	kojiku->check.check_rawdata39_2dphi_psi1		= atoi(argv[130]);

	kojiku->check.check_rawdata41_hwsp2_v			= atoi(argv[131]);
	kojiku->check.check_rawdata42_hwsp2_alpha		= atoi(argv[132]);
	kojiku->check.check_rawdata43_hwsp2_vaxis		= atoi(argv[133]);
	kojiku->check.check_rawdata44_hwsp2_vcir		= atoi(argv[134]);
	kojiku->check.check_rawdata45_ndvaxis2		= atoi(argv[135]);
	kojiku->check.check_rawdata46_ndvcir2			= atoi(argv[136]);
	kojiku->check.check_rawdata47_2daverv2		= atoi(argv[137]);
	kojiku->check.check_rawdata48_2dphi2		= atoi(argv[138]);
	kojiku->check.check_rawdata49_2dphi_psi2		= atoi(argv[139]);

	kojiku->check.check_rawdata13_averv			= atoi(argv[140]);
	kojiku->check.check_rawdata15_phi			= atoi(argv[141]);
	kojiku->check.check_rawdata10_pspr			= atoi(argv[142]);
	kojiku->check.check_rawdata12_ptpr			= atoi(argv[143]);
	kojiku->check.check_rawdata13_spsi			= atoi(argv[144]);
	kojiku->check.check_rawdata14_psi			= atoi(argv[145]);
	kojiku->check.check_rawdata20_phi_psi		= atoi(argv[146]);
	kojiku->check.check_rawdata16_phi_spsi		= atoi(argv[147]);

	kojiku->check.check_rawdata_dpdt_dqdt		= atoi(argv[148]);
	kojiku->check.check_rawdata22_valve			= atoi(argv[149]);
	kojiku->check.check_rawdata27_plunge = atoi(argv[150]);
	kojiku->atm.Nrev		= atof(argv[151]);
	kojiku->check.log2check						= atoi(argv[152]);

	kojiku->file.posit.p_max					= argv[153];
	kojiku->file.num.p_max					= atoi(argv[154]);
	kojiku->atm.P_end				= atof(argv[155]);
	kojiku->atm.T_end				= atof(argv[156]);
	kojiku->check.check_position	= atoi(argv[157]);
	kojiku->check.check_position_sp	= atoi(argv[158]);

	kojiku->sens.kousei.P_1		= atof(argv[159]);

	printf("command_line_error_3\n");

	kojiku->sens.kousei.P_0		= atof(argv[160]);

	printf("command_line_error_4\n");

	kojiku->check.check_rawdata51_ptank	= atoi(argv[161]);
	kojiku->check.check_rawdata52_ptank_psi	= atoi(argv[163]);
	kojiku->check.check_filter51_ptank	= atoi(argv[163]);
	kojiku->check.check_filter52_ptank_psi	= atoi(argv[164]);

	//printf("go!!%lf\t%lf\n",kojiku->sens.kousei.P_1,kojiku->sens.kousei.P_0);
}
//*******************************************************************************************************
//バッチファイル作成プログラム　　大気条件をあらかじめいれておくパターン
//
//*******************************************************************************************************

#pragma warning( disable: 4996 )       // コード先頭に記載


#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<direct.h>


#define POSIT_OUT	"F:/Axial21/21data/result"		//ディレクトリ作成出力先
//ここ変える 1/2 2つの変更ポイントの1つ目
#define POSIT_OUT_2	"F:/Axial21/21data/bat/210701"	//ＢＡＴ出力先

/*#define START		33//ファイル開始No
#define END			45//ファイル終了No*/

int main(void) {

	//--------------------------------------------------------------------------------
	//変数宣言
	int i, j, START, END, init1, init2, START1, END1;
	double P1, P2, T1, T2, Nrev;


	char *posit_out = POSIT_OUT;
	char *posit_out_2 = POSIT_OUT_2;

	char posit_name_in[100];
	char posit_name_out[100];
	char posit_name_out2[100];
	char posit_name_folda1[150];
	char posint_name_ID[150];

	FILE *fp_in, *fp_out, *fp_out2;

	printf("データフォルダ名(ex  181019_1)\n");  //日付はここで入れてる//
	scanf("%s", &posint_name_ID);

	printf("開始ID:\n");
	scanf("%d", &START);
	printf("終了ID:\n");
	scanf("%d", &END);

	printf("計算開始ファイル番号:\n");
	scanf("%d", &START1);
	printf("終了ファイル番号:\n");
	scanf("%d", &END1);

	printf("イニシャルNo１:\n");
	scanf("%d", &init1);
	printf("イニシャルNo2:\n");
	scanf("%d", &init2);

	printf("開始大気圧:\n");
	scanf("%lf", &P1);
	printf("終了大気圧:\n");
	scanf("%lf", &P2);
		
	printf("開始温度:\n");
	scanf("%lf", &T1);
	printf("終了温度:\n");
	scanf("%lf", &T2);

	printf("回転数:\n");
	scanf("%lf", &Nrev);
	//--------------------------------------------------------------------------------
	//ディレクトリ作成

	for (i = START; i<END + 1; i++) {

		printf("%s\n", posint_name_ID);

		printf("%03dディレクトリ作成......", i);
		sprintf(posit_name_folda1, "F:/Axial21/21data/result/%s", posint_name_ID);
		_mkdir(posit_name_folda1);           ///ディレクトリ作ってます//
		sprintf(posit_name_folda1, "F:/Axial21/21data/result/%s/%03d", posint_name_ID, i);
		_mkdir(posit_name_folda1);
		printf("完了\n");


		printf("%s/%03d.bat\n", posit_out_2, i);

		sprintf(posit_name_out2, "%s/%03d.bat", posit_out_2, i);

		fp_out2 = fopen(posit_name_out2, "w");

		fprintf(fp_out2, "@echo	off\n");
		fprintf(fp_out2, "	\n");
		fprintf(fp_out2, "echo	*******************************************************************************\n");
		fprintf(fp_out2, "echo	データ作成を一気に行う、まさに夢のようなバッチです。\n");
		fprintf(fp_out2, "echo	*******************************************************************************\n");
		fprintf(fp_out2, "	\n");
		fprintf(fp_out2, "rem ＜***************環境変数に数値を代入***********************＞arrenged by さかてぃー 2018(新データレコーダテスト仕様)\n");
		fprintf(fp_out2, "set P_init=%f	\n", P1);
		fprintf(fp_out2, "set P_end=%f\n", P2);
		fprintf(fp_out2, "set T_init=%f \n", T1);
		fprintf(fp_out2, "set T_end=%f \n", T2);
		fprintf(fp_out2, "set  init_num_1=%d		\n", init1);
		fprintf(fp_out2, "set init_num_2=%d		\n", init2);
		fprintf(fp_out2, "set pm_num=%d		\n", init1);
		fprintf(fp_out2, "set file_num_1=%d\n", START1);
		fprintf(fp_out2, "set file_num_2=%d\n", END1);
		fprintf(fp_out2, "set  revol=%f\n", Nrev);
		fprintf(fp_out2, "set /p init_or_not=イニシャルプログラムかける場合は１を入力　：	\n");
		fprintf(fp_out2, "set /p position=吐出管で測る場合は1を入力,圧縮機内で測る場合は0を入力　：	\n");
		fprintf(fp_out2, "set /p position_sp=inletで測る場合は2を入力,圧縮機内で測る場合は0を入力,Sp計測無しは1を入力　：	\n");
		fprintf(fp_out2, "	\n");
		fprintf(fp_out2, "set pass_prg_init=F:/Axial21/データ作成プログラム/イニシャルver1.4/Release/イニシャルver1.4.exe	\n");
		fprintf(fp_out2, "set pass_prg=F:/Axial21/データ作成プログラム/データ作成ver9.0_test/Release/データ作成ver9.0_test.exe	\n");//0°
		fprintf(fp_out2, "	\n");

		fprintf(fp_out2, "set pass_init=F:/Axial21/21data/initial/%s\n", posint_name_ID);
		fprintf(fp_out2, "set pass_in=F:/Axial21/21data/DAT2/%s/%03d/00000\n", posint_name_ID, i);
		fprintf(fp_out2, "set pass_out=F:/Axial21/21data/result/%s/%03d\n", posint_name_ID, i);
		fprintf(fp_out2, "set pass_pm=F:/Axial21/21data/initial/%s	\n", posint_name_ID);
		fprintf(fp_out2, "	\n");
		fprintf(fp_out2, "set sens_1A=4.526199698	\n");
		fprintf(fp_out2, "set sens_1C=4.845398644	\n");
		fprintf(fp_out2, "set sens_1E=0.0	\n");
		fprintf(fp_out2, "set sens_2A=4.120702845\n");
		fprintf(fp_out2, "set sens_2C=0.0	\n");
		fprintf(fp_out2, "set sens_2E=4.025784603	\n");
		fprintf(fp_out2, "set sens_3A=0.0	\n");
		fprintf(fp_out2, "set sens_3C=4.021323379	\n");
		fprintf(fp_out2, "set sens_3E=8.056979258	\n");
		fprintf(fp_out2, "	\n");
		fprintf(fp_out2, "set sens_PP=7.911825119	\n");
		fprintf(fp_out2, "	\n");
		fprintf(fp_out2, "set sens_hwi6=0.0	\n");
		fprintf(fp_out2, "set sens_hwi5=0.24732		\n");
		fprintf(fp_out2, "set sens_hwi4=-2.76090	\n");
		fprintf(fp_out2, "set sens_hwi3=12.80764	\n");
		fprintf(fp_out2, "set sens_hwi2=-24.04679	\n");
		fprintf(fp_out2, "set sens_hwi1=15.31619		\n");
		fprintf(fp_out2, "set sens_hwi0=0.0	\n");
		fprintf(fp_out2, "	\n");
		fprintf(fp_out2, "set sens_hwi2_6=0.0	\n");
		fprintf(fp_out2, "set sens_hwi2_5=0.0		\n");
		fprintf(fp_out2, "set sens_hwi2_4=0.0\n");
		fprintf(fp_out2, "set sens_hwi2_3=0.0		\n");
		fprintf(fp_out2, "set sens_hwi2_2=0.0	\n");
		fprintf(fp_out2, "set sens_hwi2_1=0.0	\n");
		fprintf(fp_out2, "set sens_hwi2_0=0.0	\n");
		fprintf(fp_out2, "	\n");
		fprintf(fp_out2, "set sens_hwi3_6=0.09973	\n");
		fprintf(fp_out2, "set sens_hwi3_5=-1.37642		\n");
		fprintf(fp_out2, "set sens_hwi3_4=7.34643	\n");
		fprintf(fp_out2, "set sens_hwi3_3=-17.33213	\n");
		fprintf(fp_out2, "set sens_hwi3_2=18.68650\n");
		fprintf(fp_out2, "set sens_hwi3_1=-7.61247\n");
		fprintf(fp_out2, "set sens_hwi3_0=0.0\n");
		fprintf(fp_out2, "	\n");
		fprintf(fp_out2, "set sens_hwsp1_A=5.070829616	\n");
		fprintf(fp_out2, "set sens_hwsp1_B=3.889611319	\n");
		fprintf(fp_out2, "set sens_hwsp1_n=0.461122582	\n");
		fprintf(fp_out2, "set sens_hwsp1_V1=-0.918641477	\n");
		fprintf(fp_out2, "set sens_hwsp1_K1=0.000131454		\n");
		fprintf(fp_out2, "set sens_hwsp1_V2=-0.028414113\n");
		fprintf(fp_out2, "set sens_hwsp1_K2=-0.02670639		\n");
		fprintf(fp_out2, "	\n");
		fprintf(fp_out2, "set sens_hwsp2_A=3.305689449	\n");
		fprintf(fp_out2, "set sens_hwsp2_B=2.747121643  \n");
		fprintf(fp_out2, "set sens_hwsp2_n=0.466596201	\n");
		fprintf(fp_out2, "set sens_hwsp2_V1=3.066784144		\n");
		fprintf(fp_out2, "set sens_hwsp2_K1=0.00155836	\n");
		fprintf(fp_out2, "set sens_hwsp2_V2=-0.284716625 \n");
		fprintf(fp_out2, "set sens_hwsp2_K2=0.019539874	\n");
		fprintf(fp_out2, "	\n");
		fprintf(fp_out2, "set Q_kousei2=0.90366 	\n");
		fprintf(fp_out2, "set Q_kousei1=0.866918477	\n");
		fprintf(fp_out2, "set Q_kousei0=0.88256	\n");     //3年前の流量校正の値．
		fprintf(fp_out2, "	\n");
		fprintf(fp_out2, "set P_kousei1=3388.8	\n");    //必要ない値
		fprintf(fp_out2, "set P_kousei0=0	\n");
		fprintf(fp_out2, "	\n");
		fprintf(fp_out2, "set cut_bp=3000.0	\n");
		fprintf(fp_out2, "set cut_pq=20.0	\n");
		fprintf(fp_out2, "set cut_bp2=20.0	\n");
		fprintf(fp_out2, "set cut_pq2=0.0	\n");
		fprintf(fp_out2, "	\n");
		fprintf(fp_out2, "	\n");
		fprintf(fp_out2, "rem <**********　　出力する->1,出力しない->0　　***********>	\n");
		fprintf(fp_out2, "set check_FFTampspec01_1A=1\n");
		fprintf(fp_out2, "set check_FFTampspec04_2A=	1\n");
		fprintf(fp_out2, "set check_FFTampspec07_3A=	1\n");
		fprintf(fp_out2, "set check_FFTampspec11_hwi=	1\n");
		fprintf(fp_out2, "set check_FFTampspec12_ptpr=	1\n");
		fprintf(fp_out2, "set check_FFTampspec18_hwi2=	0\n");
		fprintf(fp_out2, "set check_FFTampspec25_hwi3=	1\n");
		fprintf(fp_out2, "	\n");
		fprintf(fp_out2, "set check_FFTampspec33_hwsp1_vaxis=	0\n");
		fprintf(fp_out2, "set check_FFTampspec34_hwsp1_vcir=	0\n");
		fprintf(fp_out2, "set check_FFTampspec43_hwsp2_vaxis=	0\n");
		fprintf(fp_out2, "set check_FFTampspec44_hwsp2_vcir=	0\n");
		fprintf(fp_out2, "	\n");
		fprintf(fp_out2, "set check_filter01_1A=		1\n");
		fprintf(fp_out2, "set check_filter02_1C=		1\n");
		fprintf(fp_out2, "set check_filter03_1E=		0\n");
		fprintf(fp_out2, "set check_filter04_2A=		1\n");
		fprintf(fp_out2, "set check_filter05_2C=		0\n");
		fprintf(fp_out2, "set check_filter06_2E=		1\n");
		fprintf(fp_out2, "set check_filter07_3A=		0\n");
		fprintf(fp_out2, "set check_filter08_3C=		1\n");
		fprintf(fp_out2, "set check_filter09_3E=		1\n");
		fprintf(fp_out2, "	\n");
		fprintf(fp_out2, "set check_filter10_pspr=		1\n");  //性能壁圧上昇
		fprintf(fp_out2, "set check_filter11_hwi=			1\n");  //軸流速（熱線I型）
		fprintf(fp_out2, "set check_filter12_ptpr=			1\n");  //性能全圧上昇
		fprintf(fp_out2, "set check_filter13_averv=		1\n");  //圧縮機内平均軸流速
		fprintf(fp_out2, "set check_filter13_spsi=	        1\n");  //静圧上昇係数ψs
		fprintf(fp_out2, "set check_filter14_psi=			1\n");  //全圧上昇係数ψ
		fprintf(fp_out2, "set check_filter15_phi=			1\n");  //流量係数φ
		fprintf(fp_out2, "set check_filter16_phi_spsi=	1\n");  //φ-ψ（静圧上昇係数）
		fprintf(fp_out2, "set check_filter18_hwi2=		0	\n");  //内部流れ（I型熱線）
		fprintf(fp_out2, "set check_filter20_phi_psi=	1	\n");  //φ-ψ
		fprintf(fp_out2, "set check_filter25_hwi3=		1\n");  //内部流れ（I型熱線）
		fprintf(fp_out2, "	\n");
		fprintf(fp_out2, "set check_filter31_hwsp1_v=			0\n");
		fprintf(fp_out2, "set check_filter32_hwsp1_alpha=	0\n");
		fprintf(fp_out2, "set check_filter33_hwsp1_vaxis=	0\n");
		fprintf(fp_out2, "set check_filter34_hwsp1_vcir=		0\n");
		fprintf(fp_out2, "set check_filter35_ndvaxis1=			0\n");
		fprintf(fp_out2, "set check_filter36_ndvcir1=			0\n");
		fprintf(fp_out2, "set check_filter37_2daverv1=			0\n");
		fprintf(fp_out2, "set check_filter38_2dphi1=			    0\n");
		fprintf(fp_out2, "set check_filter39_2dphi_spsi1=		0\n");
		fprintf(fp_out2, "	\n");
		fprintf(fp_out2, "set check_filter41_hwsp2_v=		0\n");
		fprintf(fp_out2, "set check_filter42_hwsp2_alpha=		0\n");
		fprintf(fp_out2, "set check_filter43_hwsp2_vaxis=		0\n");
		fprintf(fp_out2, "set check_filter44_hwsp2_vcir=		0\n");
		fprintf(fp_out2, "set check_filter45_ndvaxis2=			0\n");
		fprintf(fp_out2, "set check_filter46_ndvcir2=			0\n");
		fprintf(fp_out2, "set check_filter47_2daverv2=			0\n");
		fprintf(fp_out2, "set check_filter48_2dphi2=				0\n");
		fprintf(fp_out2, "set check_filter49_2dphi_spsi2=		0\n");
		fprintf(fp_out2, "	\n");
		fprintf(fp_out2, "set check_rawdata01_1A=		1\n");
		fprintf(fp_out2, "set check_rawdata02_1C=		1\n");
		fprintf(fp_out2, "set check_rawdata03_1E=		0\n");
		fprintf(fp_out2, "set check_rawdata04_2A=		1\n");
		fprintf(fp_out2, "set check_rawdata05_2C=		0\n");
		fprintf(fp_out2, "set check_rawdata06_2E=		1\n");
		fprintf(fp_out2, "set check_rawdata07_3A=		0\n");
		fprintf(fp_out2, "set check_rawdata08_3C=		1\n");
		fprintf(fp_out2, "set check_rawdata09_3E=		1\n");
		fprintf(fp_out2, "set check_rawdata10_pspr=		1\n");
		fprintf(fp_out2, "set check_rawdata11_hwi=		1\n");
		fprintf(fp_out2, "set check_rawdata12_ptpr=		1\n");
		fprintf(fp_out2, "set check_rawdata13_averv=		1\n");
		fprintf(fp_out2, "set check_rawdata13_spsi=		1\n");
		fprintf(fp_out2, "set check_rawdata14_psi=		1\n");
		fprintf(fp_out2, "set check_rawdata15_phi=		1\n");
		fprintf(fp_out2, "set check_rawdata16_phi_spsi=		1\n");
		fprintf(fp_out2, "set check_rawdata18_hwi2=		0\n");
		fprintf(fp_out2, "set check_rawdata20_phi_psi=		1\n");
		fprintf(fp_out2, "set check_rawdara22_valve=		1\n");
		fprintf(fp_out2, "set check_rawdata25_hwi3=		1\n");
		fprintf(fp_out2, "set check_rawdara27_plunge=		0\n");
		fprintf(fp_out2, "	\n");
		fprintf(fp_out2, "set check_rawdata31_hwsp1_v=		0\n");
		fprintf(fp_out2, "set check_rawdata32_hwsp1_alpha=	0\n");
		fprintf(fp_out2, "set check_rawdata33_hwsp1_vaxis=	0\n");
		fprintf(fp_out2, "set check_rawdata34_hwsp1_vcir=		0\n");
		fprintf(fp_out2, "set check_rawdata35_ndvaxis1=		0\n");
		fprintf(fp_out2, "set check_rawdata36_ndvcir1=		0\n");
		fprintf(fp_out2, "set check_rawdata37_2daverv1=		0\n");
		fprintf(fp_out2, "set check_rawdata38_2dphi1=		0\n");
		fprintf(fp_out2, "set check_rawdata39_2dphi_spsi1=	0\n");
		fprintf(fp_out2, "	\n");
		fprintf(fp_out2, "set check_rawdata41_hwsp2_v=		0\n");
		fprintf(fp_out2, "set check_rawdata42_hwsp2_alpha=	0\n");
		fprintf(fp_out2, "set check_rawdata43_hwsp2_vaxis=	0\n");
		fprintf(fp_out2, "set check_rawdata44_hwsp2_vcir=		0\n");
		fprintf(fp_out2, "set check_rawdata45_ndvaxis2=		0\n");
		fprintf(fp_out2, "set check_rawdata46_ndvcir2=		0\n");
		fprintf(fp_out2, "set check_rawdata47_2daverv2=		0\n");
		fprintf(fp_out2, "set check_rawdata48_2dphi2=		0\n");
		fprintf(fp_out2, "set check_rawdata49_2dphi_spsi2=	0\n");
		fprintf(fp_out2, "		\n");
		fprintf(fp_out2, "set log2check=			1\n");
		fprintf(fp_out2, "set check_rawdata_dpdt_dqdt=		1\n");
		fprintf(fp_out2, "		\n");
		fprintf(fp_out2, "set check_rawdata51_ptank=		1\n");
		fprintf(fp_out2, "set check_rawdata52_ptank_psi=		1\n");
		fprintf(fp_out2, "set check_filter51_ptank=		1\n");
		fprintf(fp_out2, "set check_filter52_ptank_psi=		1\n");
		fprintf(fp_out2, "		\n");
		fprintf(fp_out2, "		\n");
		fprintf(fp_out2, "rem ＜***************イニシャルプログラム実行********************＞		\n");
		fprintf(fp_out2, "if \"%%init_or_not%%\"==\"1\"  %%pass_prg_init%%  %%init_num_1%%  %%init_num_2%%  %%pass_in%%  %%pass_init%% %%sens_hwi5%% %%sens_hwi4%% %%sens_hwi3%% %%sens_hwi2%% %%sens_hwi1%% %%sens_hwi0%% %%pm_num%% %%sens_hwi6%%		\n");
		fprintf(fp_out2, "		\n");
		fprintf(fp_out2, "rem ＜***************データ作成プログラム実行********************＞		\n");
		fprintf(fp_out2, "set /a i=%%file_num_1%%		\n");
		fprintf(fp_out2, " 		\n");
		fprintf(fp_out2, ":LOOP		\n");
		fprintf(fp_out2, "%%pass_prg%% %%init_num_1%% %%init_num_2%% %%i%% %%pass_init%% %%pass_in%% %%pass_out%% %%P_init%% %%T_init%% %%sens_1A%% %%sens_1C%% %%sens_1E%% %%sens_2A%% %%sens_2C%% %%sens_2E%% %%sens_3A%% %%sens_3C%%  %%sens_3E%% %%sens_PP%% %%sens_hwi6%% %%sens_hwi5%% %%sens_hwi4%% %%sens_hwi3%% %%sens_hwi2%% %%sens_hwi1%% %%sens_hwi0%% %%sens_hwi2_6%% %%sens_hwi2_5%% %%sens_hwi2_4%% %%sens_hwi2_3%% %%sens_hwi2_2%% %%sens_hwi2_1%% %%sens_hwi2_0%% %%sens_hwi3_6%% %%sens_hwi3_5%% %%sens_hwi3_4%% %%sens_hwi3_3%% %%sens_hwi3_2%% %%sens_hwi3_1%% %%sens_hwi3_0%% %%sens_hwsp1_A%% %%sens_hwsp1_B%% %%sens_hwsp1_n%% %%sens_hwsp1_V1%% %%sens_hwsp1_K1%% %%sens_hwsp1_V2%% %%sens_hwsp1_K2%% %%sens_hwsp2_A%% %%sens_hwsp2_B%% %%sens_hwsp2_n%% %%sens_hwsp2_V1%%%%sens_hwsp2_K1%% %%sens_hwsp2_V2%% %%sens_hwsp2_K2%% %%Q_kousei2%% %%Q_kousei1%% %%Q_kousei0%% %%cut_bp%% %%cut_pq%% %%cut_bp2%% %%cut_pq2%% %%check_FFTampspec01_1A%% %%check_FFTampspec04_2A%% %%check_FFTampspec07_3A%% %%check_FFTampspec12_ptpr%% %%check_FFTampspec11_hwi%% %%check_FFTampspec18_hwi2%% %%check_FFTampspec25_hwi3%% %%check_FFTampspec33_hwsp1_vaxis%% %%check_FFTampspec34_hwsp1_vcir%% %%check_FFTampspec43_hwsp2_vaxis%% %%check_FFTampspec44_hwsp2_vcir%% %%check_filter01_1A%% %%check_filter02_1C%% %%check_filter03_1E%% %%check_filter04_2A%% %%check_filter05_2C%% %%check_filter06_2E%% %%check_filter07_3A%% %%check_filter08_3C%% %%check_filter09_3E%% %%check_filter11_hwi%% %%check_filter18_hwi2%% %%check_filter25_hwi3%% %%check_filter31_hwsp1_v%% %%check_filter32_hwsp1_alpha%% %%check_filter33_hwsp1_vaxis%% %%check_filter34_hwsp1_vcir%% %%check_filter35_ndvaxis1%% %%check_filter36_ndvcir1%% %%check_filter37_2daverv1%% %%check_filter38_2dphi1%% %%check_filter39_2dphi_spsi1%% %%check_filter41_hwsp2_v%% %%check_filter42_hwsp2_alpha%% %%check_filter43_hwsp2_vaxis%% %%check_filter44_hwsp2_vcir%% %%check_filter45_ndvaxis2%% %%check_filter46_ndvcir2%% %%check_filter47_2daverv2%% %%check_filter48_2dphi2%% %%check_filter49_2dphi_spsi2%% %%check_filter13_averv%% %%check_filter15_phi%% %%check_filter10_pspr%% %%check_filter12_ptpr%% %%check_filter13_spsi%% %%check_filter14_psi%% %%check_filter20_phi_psi%% %%check_filter16_phi_spsi%% %%check_rawdata01_1A%% %%check_rawdata02_1C%% %%check_rawdata03_1E%% %%check_rawdata04_2A%% %%check_rawdata05_2C%% %%check_rawdata06_2E%% %%check_rawdata07_3A%%  %%check_rawdata08_3C%% %%check_rawdata09_3E%% %%check_rawdata11_hwi%% %%check_rawdata18_hwi2%% %%check_rawdata25_hwi3%% %%check_rawdata31_hwsp1_v%% %%check_rawdata32_hwsp1_alpha%% %%check_rawdata33_hwsp1_vaxis%% %%check_rawdata34_hwsp1_vcir%% %%check_rawdata35_ndvaxis1%% %%check_rawdata36_ndvcir1%% %%check_rawdata37_2daverv1%% %%check_rawdata38_2dphi1%% %%check_rawdata39_2dphi_spsi1%% %%check_rawdata41_hwsp2_v%% %%check_rawdata42_hwsp2_alpha%% %%check_rawdata43_hwsp2_vaxis%% %%check_rawdata44_hwsp2_vcir%% %%check_rawdata45_ndvaxis2%% %%check_rawdata46_ndvcir2%% %%check_rawdata47_2daverv2%% %%check_rawdata48_2dphi2%% %%check_rawdata49_2dphi_spsi2%% %%check_rawdata13_averv%% %%check_rawdata15_phi%% %%check_rawdata10_pspr%% %%check_rawdata12_ptpr%% %%check_rawdata13_spsi%% %%check_rawdata14_psi%% %%check_rawdata20_phi_psi%% %%check_rawdata16_phi_spsi%% %%check_rawdata_dpdt_dqdt%% %%check_rawdara22_valve%% %%check_rawdara27_plunge%% %%revol%% %%log2check%% %%pass_pm%% %%pm_num%% %%P_end%% %%T_end%% %%position%% %%position_sp%% %%P_kousei1%% %%P_kousei0%% %%check_rawdata51_ptank%% %%check_rawdata52_ptank_psi%% %%check_filter51_ptank%% %%check_filter52_ptank_psi%%		\n");
		fprintf(fp_out2, "		\n");
		fprintf(fp_out2, "	if \"%%i%%\"==\"%%file_num_2%%\" goto EXIT	\n");
		fprintf(fp_out2, "		\n");
		fprintf(fp_out2, "	set /a i=i+1	\n");
		fprintf(fp_out2, "		\n");
		fprintf(fp_out2, "	goto LOOP	\n");
		fprintf(fp_out2, ":EXIT		\n");
		fprintf(fp_out2, "pause		\n");


		fclose(fp_out2);

	}

	return 0;
}

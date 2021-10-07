//*************************************************************************************************************
//イニシャルプログラムのメモリに関する関数
//*************************************************************************************************************

//標準ライブラリのインクルード
#include	<stdio.h>
#include	<stdlib.h>
#include	"定数・構造体定義.h"
#include	"自作関数定義.h"		//自作ヘッダ

//-------------------------------------------------------------------------------------------------------------
//バイナリデータ用メモリ確保関数（unsigned int）
//-------------------------------------------------------------------------------------------------------------
void Reserve_Memory_UInt_2D( unsigned int ***data_u, unsigned int ii, unsigned int jj ){

	//変数宣言---------------------------------------------------------------------------------------
	unsigned int	j;	//列カウンタ

	//メモリ確保--------------------------------------------------------------------------------------
	*data_u = (unsigned int **)calloc(jj, sizeof(unsigned int *));
	for( j=0; j<jj; j++ ){
		(*data_u)[j] = (unsigned int *)calloc(ii, sizeof(unsigned int));
		if( (*data_u)[j]==NULL ){
			printf("メモリーが足りません。\n\a\a\a");
			while(1);
		}
	}

}


//------------------------------------------------------------------------------------------------------------
//バイナリデータ用メモリ開放関数（unsigned int）
//------------------------------------------------------------------------------------------------------------
void Free_Memory_UInt_2D( unsigned int ***data_u, unsigned int jj ){

	//変数宣言---------------------------------------------------------------------------------------
	unsigned int	j;			//列カウンタ

	//メモリ開放--------------------------------------------------------------------------------------
	for( j=0; j<jj; j++ ){
		free( (*data_u)[j] );
	}
	free( *data_u );
}


//-------------------------------------------------------------------------------------------------------------
//計算データ用メモリ確保関数
//-------------------------------------------------------------------------------------------------------------
void Reserve_Memory( st_kojiku *kojiku ){
	if(kojiku->check.log2check == 0){
		//メモリ確保-------------------------------------------------------------------------------------
		Reserve_Memory_Double_2D( &kojiku->data.data_d, kojiku->line.newline, J );

		if(kojiku->check.check_rawdata01_1A==1 || kojiku->check.check_filter01_1A==1 || kojiku->check.check_FFTampspec01_1A==1){
			Reserve_Memory_Double_1D( &kojiku->data.wp1A.real,	kojiku->line.newline );
			Reserve_Memory_Double_1D( &kojiku->data.wp1A.imag,	kojiku->line.newline );
			Reserve_Memory_Double_1D( &kojiku->data.wp1A.abs,	kojiku->line.ampspec );
		}

		if(kojiku->check.check_rawdata02_1C==1 || kojiku->check.check_filter02_1C==1){
			Reserve_Memory_Double_1D( &kojiku->data.wp1C.real,	kojiku->line.newline );
			Reserve_Memory_Double_1D( &kojiku->data.wp1C.imag,	kojiku->line.newline );
		}

		if(kojiku->check.check_rawdata03_1E==1 || kojiku->check.check_filter03_1E==1){
			Reserve_Memory_Double_1D( &kojiku->data.wp1E.real,	kojiku->line.newline );
			Reserve_Memory_Double_1D( &kojiku->data.wp1E.imag,	kojiku->line.newline );
		}

		if(kojiku->check.check_rawdata04_2A==1 || kojiku->check.check_filter04_2A==1 || kojiku->check.check_FFTampspec04_2A==1){
			Reserve_Memory_Double_1D( &kojiku->data.wp2A.real,	kojiku->line.newline );
			Reserve_Memory_Double_1D( &kojiku->data.wp2A.imag,	kojiku->line.newline );
			Reserve_Memory_Double_1D( &kojiku->data.wp2A.abs,	kojiku->line.ampspec );
		}

		if(kojiku->check.check_rawdata05_2C==1 || kojiku->check.check_filter05_2C==1){
			Reserve_Memory_Double_1D( &kojiku->data.wp2C.real,	kojiku->line.newline );
			Reserve_Memory_Double_1D( &kojiku->data.wp2C.imag,	kojiku->line.newline );
		}

		if(kojiku->check.check_rawdata06_2E==1 || kojiku->check.check_filter06_2E==1){
			Reserve_Memory_Double_1D( &kojiku->data.wp2E.real,	kojiku->line.newline );
			Reserve_Memory_Double_1D( &kojiku->data.wp2E.imag,	kojiku->line.newline );
		}

		if(kojiku->check.check_rawdata07_3A==1 || kojiku->check.check_filter07_3A==1 || kojiku->check.check_FFTampspec07_3A==1){
			Reserve_Memory_Double_1D( &kojiku->data.wp3A.real,	kojiku->line.newline );
			Reserve_Memory_Double_1D( &kojiku->data.wp3A.imag,	kojiku->line.newline );
			Reserve_Memory_Double_1D( &kojiku->data.wp3A.abs,	kojiku->line.ampspec );
		}

		if(kojiku->check.check_rawdata08_3C==1 || kojiku->check.check_filter08_3C==1){
			Reserve_Memory_Double_1D( &kojiku->data.wp3C.real,	kojiku->line.newline );
			Reserve_Memory_Double_1D( &kojiku->data.wp3C.imag,	kojiku->line.newline );
		}

		if(kojiku->check.check_rawdata09_3E==1 || kojiku->check.check_filter09_3E==1 ){
			Reserve_Memory_Double_1D( &kojiku->data.wp3E.real,	kojiku->line.newline );
			Reserve_Memory_Double_1D( &kojiku->data.wp3E.imag,	kojiku->line.newline );
		}

		if(kojiku->check.check_rawdata51_ptank==1 || kojiku->check.check_filter51_ptank==1){
			Reserve_Memory_Double_1D( &(kojiku->data.ptank.real),	kojiku->line.newline );
			Reserve_Memory_Double_1D( &(kojiku->data.ptank.imag),	kojiku->line.newline );
		}

		if(kojiku->check.check_rawdata52_ptank_psi==1 || kojiku->check.check_filter52_ptank_psi==1){
			Reserve_Memory_Double_1D( &(kojiku->data.ptank_psi.real),	kojiku->line.newline );
			Reserve_Memory_Double_1D( &(kojiku->data.ptank_psi.imag),	kojiku->line.newline );
		}

		if(kojiku->check.check_rawdata10_pspr==1 || kojiku->check.check_filter10_pspr==1 || kojiku->check.check_rawdata12_ptpr==1 || kojiku->check.check_filter12_ptpr==1 || kojiku->check.check_rawdata14_psi==1 || kojiku->check.check_filter14_psi==1 || kojiku->check.check_rawdata20_phi_psi==1 || kojiku->check.check_filter20_phi_psi==1 || kojiku->check.check_FFTampspec12_ptpr==1 || kojiku->check.check_rawdata13_spsi==1 || kojiku->check.check_filter13_spsi==1 || kojiku->check.check_rawdata16_phi_spsi==1 || kojiku->check.check_filter16_phi_spsi==1){
			Reserve_Memory_Double_1D( &kojiku->data.pspr.real, kojiku->line.newline );
			Reserve_Memory_Double_1D( &kojiku->data.pspr.imag, kojiku->line.newline );
		}

		if(kojiku->check.check_rawdata11_hwi==1 || kojiku->check.check_filter11_hwi==1 || kojiku->check.check_rawdata13_averv==1 || kojiku->check.check_filter13_averv==1 || kojiku->check.check_rawdata15_phi==1 || kojiku->check.check_filter15_phi==1 || kojiku->check.check_rawdata20_phi_psi==1 || kojiku->check.check_filter20_phi_psi==1 || kojiku->check.check_FFTampspec11_hwi==1 || kojiku->check.check_rawdata16_phi_spsi==1 || kojiku->check.check_filter16_phi_spsi==1){
			Reserve_Memory_Double_1D( &(kojiku->data.hwi.real),	kojiku->line.newline );
			Reserve_Memory_Double_1D( &(kojiku->data.hwi.imag),	kojiku->line.newline );
			Reserve_Memory_Double_1D( &(kojiku->data.hwi.abs),	kojiku->line.ampspec );
		}

		if(kojiku->check.check_rawdata12_ptpr==1 || kojiku->check.check_filter12_ptpr==1 || kojiku->check.check_rawdata14_psi==1 || kojiku->check.check_filter14_psi==1 || kojiku->check.check_rawdata20_phi_psi==1 || kojiku->check.check_filter20_phi_psi==1 || kojiku->check.check_FFTampspec12_ptpr==1 || kojiku->check.check_rawdata13_spsi==1 || kojiku->check.check_filter13_spsi==1 || kojiku->check.check_rawdata16_phi_spsi==1 || kojiku->check.check_filter16_phi_spsi==1){
			Reserve_Memory_Double_1D( &(kojiku->data.ptpr.real),	kojiku->line.newline );
			Reserve_Memory_Double_1D( &(kojiku->data.ptpr.imag),	kojiku->line.newline );
			Reserve_Memory_Double_1D( &(kojiku->data.ptpr.abs),		kojiku->line.ampspec );
		}

		if(kojiku->check.check_rawdata13_averv==1 || kojiku->check.check_filter13_averv==1 || kojiku->check.check_rawdata15_phi==1 || kojiku->check.check_filter15_phi==1 || kojiku->check.check_rawdata20_phi_psi==1 || kojiku->check.check_filter20_phi_psi==1 || kojiku->check.check_rawdata16_phi_spsi==1 || kojiku->check.check_filter16_phi_spsi==1){
			Reserve_Memory_Double_1D( &(kojiku->data.averv.real),	kojiku->line.newline );
			Reserve_Memory_Double_1D( &(kojiku->data.averv.imag),	kojiku->line.newline );
		}

		if(kojiku->check.check_rawdata14_psi==1 || kojiku->check.check_filter14_psi==1 || kojiku->check.check_rawdata20_phi_psi==1 || kojiku->check.check_filter20_phi_psi==1){
			Reserve_Memory_Double_1D( &(kojiku->data.psi.real),	kojiku->line.newline );
			Reserve_Memory_Double_1D( &(kojiku->data.psi.imag),	kojiku->line.newline );
		}

		if(kojiku->check.check_rawdata15_phi==1 || kojiku->check.check_filter15_phi==1 || kojiku->check.check_rawdata20_phi_psi==1 || kojiku->check.check_filter20_phi_psi==1 || kojiku->check.check_rawdata16_phi_spsi==1 || kojiku->check.check_filter16_phi_spsi==1){
			Reserve_Memory_Double_1D( &(kojiku->data.phi.real),	kojiku->line.newline );
			Reserve_Memory_Double_1D( &(kojiku->data.phi.imag),	kojiku->line.newline );
		}

		if(kojiku->check.check_rawdata18_hwi2==1 || kojiku->check.check_filter18_hwi2==1 || kojiku->check.check_FFTampspec18_hwi2==1){
			Reserve_Memory_Double_1D( &(kojiku->data.hwi2.real),	kojiku->line.newline );
			Reserve_Memory_Double_1D( &(kojiku->data.hwi2.imag),	kojiku->line.newline );
			Reserve_Memory_Double_1D( &(kojiku->data.hwi2.abs),	kojiku->line.newline );

			Reserve_Memory_Double_1D( &(kojiku->data.phi2.real),	kojiku->line.newline );
			Reserve_Memory_Double_1D( &(kojiku->data.phi2.imag),	kojiku->line.newline );
		}

		if (kojiku->check.check_rawdata25_hwi3 == 1 || kojiku->check.check_filter25_hwi3 == 1 || kojiku->check.check_FFTampspec25_hwi3 == 1){
			Reserve_Memory_Double_1D(&(kojiku->data.hwi3.real), kojiku->line.newline);
			Reserve_Memory_Double_1D(&(kojiku->data.hwi3.imag), kojiku->line.newline);
			Reserve_Memory_Double_1D(&(kojiku->data.hwi3.abs), kojiku->line.newline);

			Reserve_Memory_Double_1D(&(kojiku->data.phi3.real), kojiku->line.newline);
			Reserve_Memory_Double_1D(&(kojiku->data.phi3.imag), kojiku->line.newline);
		}

		if(kojiku->check.check_rawdata13_spsi==1 || kojiku->check.check_filter13_spsi==1 || kojiku->check.check_rawdata10_pspr==1 || kojiku->check.check_rawdata16_phi_spsi==1 || kojiku->check.check_filter16_phi_spsi==1){
			Reserve_Memory_Double_1D( &(kojiku->data.psi_s.real), kojiku->line.newline );
			Reserve_Memory_Double_1D( &(kojiku->data.psi_s.imag), kojiku->line.newline );
		}

		if(kojiku->check.check_rawdata22_valve==1){
			Reserve_Memory_Double_1D( &(kojiku->data.valve.real), kojiku->line.newline );
		}

		if (kojiku->check.check_rawdata27_plunge == 1) {
			Reserve_Memory_Double_1D(&(kojiku->data.plunge.real), kojiku->line.newline);
		}

		if(kojiku->check.check_rawdata_dpdt_dqdt==1){
			Reserve_Memory_Double_1D( &(kojiku->data.dpdt.real), kojiku->line.newline );
			Reserve_Memory_Double_1D( &(kojiku->data.dqdt.real), kojiku->line.newline );
		}

		if (kojiku->check. check_rawdata31_hwsp1_v == 1 || kojiku->check. check_filter31_hwsp1_v == 1|| kojiku->check. check_rawdata37_2daverv1 == 1 || kojiku->check.check_filter37_2daverv1  == 1 || kojiku->check. check_rawdata38_2dphi1 == 1 || kojiku->check.check_filter38_2dphi1  == 1){
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp1_v.real),	kojiku->line.newline );
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp1_v.imag),	kojiku->line.newline );
		}

		if (kojiku->check. check_rawdata32_hwsp1_alpha == 1 || kojiku->check. check_filter32_hwsp1_alpha == 1|| kojiku->check. check_rawdata37_2daverv1 == 1 || kojiku->check.check_filter37_2daverv1  == 1 || kojiku->check. check_rawdata38_2dphi1 == 1 || kojiku->check.check_filter38_2dphi1  == 1){
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp1_alpha.real),	kojiku->line.newline );
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp1_alpha.imag),	kojiku->line.newline );
		}

		if (kojiku->check. check_rawdata33_hwsp1_vaxis == 1 || kojiku->check. check_filter33_hwsp1_vaxis == 1 || kojiku->check. check_FFTampspec33_hwsp1_vaxis == 1 || kojiku->check. check_rawdata37_2daverv1 == 1 || kojiku->check.check_filter37_2daverv1  == 1 || kojiku->check. check_rawdata38_2dphi1 == 1 || kojiku->check.check_filter38_2dphi1  == 1 ){
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp1_vaxis.real),	kojiku->line.newline );
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp1_vaxis.imag),	kojiku->line.newline );
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp1_vaxis.abs),	kojiku->line.newline );
		}

		if (kojiku->check. check_rawdata34_hwsp1_vcir == 1 || kojiku->check. check_filter34_hwsp1_vcir == 1 || kojiku->check. check_FFTampspec34_hwsp1_vcir == 1){
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp1_vcir.real),	kojiku->line.newline );
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp1_vcir.imag),	kojiku->line.newline );
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp1_vcir.abs),	kojiku->line.newline );
		}

		if (kojiku->check. check_rawdata35_ndvaxis1 == 1 || kojiku->check. check_filter35_ndvaxis1 == 1){
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp1_ndvaxis.real), kojiku->line.newline );
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp1_ndvaxis.imag), kojiku->line.newline );
		}

		if (kojiku->check. check_rawdata36_ndvcir1 == 1 || kojiku->check. check_filter36_ndvcir1 == 1){
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp1_ndvcir.real),	 kojiku->line.newline );
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp1_ndvcir.imag),	 kojiku->line.newline );
		}

		if (kojiku->check. check_rawdata37_2daverv1 == 1 || kojiku->check.check_filter37_2daverv1  == 1 || kojiku->check. check_rawdata38_2dphi1 == 1 || kojiku->check.check_filter38_2dphi1  == 1 ){
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp1_twod_averv.real),	kojiku->line.newline );
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp1_twod_averv.imag),	kojiku->line.newline );
		}

		if (kojiku->check. check_rawdata38_2dphi1 == 1 || kojiku->check.check_filter38_2dphi1  == 1){
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp1_twod_phi.real),	kojiku->line.newline );
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp1_twod_phi.imag),	kojiku->line.newline );
		}

		if (kojiku->check. check_rawdata41_hwsp2_v == 1 || kojiku->check. check_filter41_hwsp2_v == 1||kojiku->check. check_rawdata47_2daverv2 == 1 || kojiku->check.check_filter47_2daverv2  == 1 ||kojiku->check. check_rawdata48_2dphi2 == 1 || kojiku->check.check_filter48_2dphi2  == 1){
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp2_v.real),	kojiku->line.newline );
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp2_v.imag),	kojiku->line.newline );
		}

		if (kojiku->check. check_rawdata42_hwsp2_alpha == 1 || kojiku->check. check_filter42_hwsp2_alpha == 1||kojiku->check. check_rawdata47_2daverv2 == 1 || kojiku->check.check_filter47_2daverv2  == 1 ||kojiku->check. check_rawdata48_2dphi2 == 1 || kojiku->check.check_filter48_2dphi2  == 1){
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp2_alpha.real),	kojiku->line.newline );
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp2_alpha.imag),	kojiku->line.newline );
		}

		if (kojiku->check. check_rawdata43_hwsp2_vaxis == 1 || kojiku->check. check_filter43_hwsp2_vaxis == 1 || kojiku->check.check_FFTampspec43_hwsp2_vaxis == 1||kojiku->check. check_rawdata47_2daverv2 == 1 || kojiku->check.check_filter47_2daverv2  == 1 ||kojiku->check. check_rawdata48_2dphi2 == 1 || kojiku->check.check_filter48_2dphi2  == 1){
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp2_vaxis.real),	kojiku->line.newline );
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp2_vaxis.imag),	kojiku->line.newline );
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp2_vaxis.abs),	kojiku->line.newline );
		}

		if (kojiku->check. check_rawdata44_hwsp2_vcir == 1 || kojiku->check. check_filter44_hwsp2_vcir == 1 || kojiku->check.check_FFTampspec44_hwsp2_vcir == 1){
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp2_vcir.real),	kojiku->line.newline );
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp2_vcir.imag),	kojiku->line.newline );
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp2_vcir.abs),	kojiku->line.newline );
		}

		if (kojiku->check. check_rawdata45_ndvaxis2 == 1 || kojiku->check. check_filter45_ndvaxis2 == 1){
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp2_ndvaxis.real), kojiku->line.newline );
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp2_ndvaxis.imag), kojiku->line.newline );
		}

		if (kojiku->check. check_rawdata46_ndvcir2 == 1 || kojiku->check. check_filter46_ndvcir2 == 1){
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp2_ndvcir.real),	 kojiku->line.newline );
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp2_ndvcir.imag),	 kojiku->line.newline );
		}

		if (kojiku->check. check_rawdata47_2daverv2 == 1 || kojiku->check.check_filter47_2daverv2  == 1 ||kojiku->check. check_rawdata48_2dphi2 == 1 || kojiku->check.check_filter48_2dphi2  == 1){
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp2_twod_averv.real),	kojiku->line.newline );
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp2_twod_averv.imag),	kojiku->line.newline );
		}

		if (kojiku->check. check_rawdata48_2dphi2 == 1 || kojiku->check.check_filter48_2dphi2  == 1){
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp2_twod_phi.real),	kojiku->line.newline );
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp2_twod_phi.imag),	kojiku->line.newline );
		}


		Reserve_Memory_Double_1D( &(kojiku->freq.axis_ampspec), kojiku->line.ampspec );
	}else{
		//メモリ確保-------------------------------------------------------------------------------------
		Reserve_Memory_Double_2D( &kojiku->data.data_d, kojiku->line.line, J );

		if(kojiku->check.check_rawdata01_1A==1 || kojiku->check.check_filter01_1A==1 || kojiku->check.check_FFTampspec01_1A==1){
			Reserve_Memory_Double_1D( &kojiku->data.wp1A.real,	kojiku->line.line );
			Reserve_Memory_Double_1D( &kojiku->data.wp1A.imag,	kojiku->line.line );
			Reserve_Memory_Double_1D( &kojiku->data.wp1A.abs,	kojiku->line.ampspec );
		}

		if(kojiku->check.check_rawdata02_1C==1 || kojiku->check.check_filter02_1C==1){
			Reserve_Memory_Double_1D( &kojiku->data.wp1C.real,	kojiku->line.line );
			Reserve_Memory_Double_1D( &kojiku->data.wp1C.imag,	kojiku->line.line );
		}

		if(kojiku->check.check_rawdata03_1E==1 || kojiku->check.check_filter03_1E==1){
			Reserve_Memory_Double_1D( &kojiku->data.wp1E.real,	kojiku->line.line );
			Reserve_Memory_Double_1D( &kojiku->data.wp1E.imag,	kojiku->line.line );
		}

		if(kojiku->check.check_rawdata04_2A==1 || kojiku->check.check_filter04_2A==1 || kojiku->check.check_FFTampspec04_2A==1){
			Reserve_Memory_Double_1D( &kojiku->data.wp2A.real,	kojiku->line.line );
			Reserve_Memory_Double_1D( &kojiku->data.wp2A.imag,	kojiku->line.line );
			Reserve_Memory_Double_1D( &kojiku->data.wp2A.abs,	kojiku->line.ampspec );
		}

		if(kojiku->check.check_rawdata05_2C==1 || kojiku->check.check_filter05_2C==1){
			Reserve_Memory_Double_1D( &kojiku->data.wp2C.real,	kojiku->line.line );
			Reserve_Memory_Double_1D( &kojiku->data.wp2C.imag,	kojiku->line.line );
		}

		if(kojiku->check.check_rawdata06_2E==1 || kojiku->check.check_filter06_2E==1){
			Reserve_Memory_Double_1D( &kojiku->data.wp2E.real,	kojiku->line.line );
			Reserve_Memory_Double_1D( &kojiku->data.wp2E.imag,	kojiku->line.line );
		}

		if(kojiku->check.check_rawdata07_3A==1 || kojiku->check.check_filter07_3A==1 || kojiku->check.check_FFTampspec07_3A==1){
			Reserve_Memory_Double_1D( &kojiku->data.wp3A.real,	kojiku->line.line );
			Reserve_Memory_Double_1D( &kojiku->data.wp3A.imag,	kojiku->line.line );
			Reserve_Memory_Double_1D( &kojiku->data.wp3A.abs,	kojiku->line.ampspec );
		}

		if(kojiku->check.check_rawdata08_3C==1 || kojiku->check.check_filter08_3C==1){
			Reserve_Memory_Double_1D( &kojiku->data.wp3C.real,	kojiku->line.line );
			Reserve_Memory_Double_1D( &kojiku->data.wp3C.imag,	kojiku->line.line );
		}

		if(kojiku->check.check_rawdata09_3E==1 || kojiku->check.check_filter09_3E==1){
			Reserve_Memory_Double_1D( &kojiku->data.wp3E.real,	kojiku->line.line );
			Reserve_Memory_Double_1D( &kojiku->data.wp3E.imag,	kojiku->line.line );
		}

		if(kojiku->check.check_rawdata10_pspr==1 || kojiku->check.check_filter10_pspr==1 || kojiku->check.check_rawdata12_ptpr==1 || kojiku->check.check_filter12_ptpr==1 || kojiku->check.check_rawdata14_psi==1 || kojiku->check.check_filter14_psi==1 || kojiku->check.check_rawdata20_phi_psi==1 || kojiku->check.check_filter20_phi_psi==1 || kojiku->check.check_FFTampspec12_ptpr==1 || kojiku->check.check_rawdata13_spsi==1 || kojiku->check.check_filter13_spsi==1 || kojiku->check.check_rawdata16_phi_spsi==1 || kojiku->check.check_filter16_phi_spsi==1){
			Reserve_Memory_Double_1D( &kojiku->data.pspr.real, kojiku->line.line );
			Reserve_Memory_Double_1D( &kojiku->data.pspr.imag, kojiku->line.line );
		}

		if(kojiku->check.check_rawdata11_hwi==1 || kojiku->check.check_filter11_hwi==1 || kojiku->check.check_rawdata13_averv==1 || kojiku->check.check_filter13_averv==1 || kojiku->check.check_rawdata15_phi==1 || kojiku->check.check_filter15_phi==1 || kojiku->check.check_rawdata20_phi_psi==1 || kojiku->check.check_filter20_phi_psi==1 || kojiku->check.check_FFTampspec11_hwi==1 || kojiku->check.check_rawdata16_phi_spsi==1 || kojiku->check.check_filter16_phi_spsi==1){
			Reserve_Memory_Double_1D( &(kojiku->data.hwi.real),	kojiku->line.line );
			Reserve_Memory_Double_1D( &(kojiku->data.hwi.imag),	kojiku->line.line );
			Reserve_Memory_Double_1D( &(kojiku->data.hwi.abs),	kojiku->line.ampspec );
		}

		if(kojiku->check.check_rawdata12_ptpr==1 || kojiku->check.check_filter12_ptpr==1 || kojiku->check.check_rawdata14_psi==1 || kojiku->check.check_filter14_psi==1 || kojiku->check.check_rawdata20_phi_psi==1 || kojiku->check.check_filter20_phi_psi==1 || kojiku->check.check_FFTampspec12_ptpr==1 || kojiku->check.check_rawdata13_spsi==1 || kojiku->check.check_filter13_spsi==1 || kojiku->check.check_rawdata16_phi_spsi==1 || kojiku->check.check_filter16_phi_spsi==1){
			Reserve_Memory_Double_1D( &(kojiku->data.ptpr.real),	kojiku->line.line );
			Reserve_Memory_Double_1D( &(kojiku->data.ptpr.imag),	kojiku->line.line );
			Reserve_Memory_Double_1D( &(kojiku->data.ptpr.abs),		kojiku->line.ampspec );
		}

		if(kojiku->check.check_rawdata13_averv==1 || kojiku->check.check_filter13_averv==1 || kojiku->check.check_rawdata15_phi==1 || kojiku->check.check_filter15_phi==1 || kojiku->check.check_rawdata20_phi_psi==1 || kojiku->check.check_filter20_phi_psi==1 || kojiku->check.check_rawdata16_phi_spsi==1 || kojiku->check.check_filter16_phi_spsi==1){
			Reserve_Memory_Double_1D( &(kojiku->data.averv.real),	kojiku->line.line );
			Reserve_Memory_Double_1D( &(kojiku->data.averv.imag),	kojiku->line.line );
		}

		if(kojiku->check.check_rawdata14_psi==1 || kojiku->check.check_filter14_psi==1 || kojiku->check.check_rawdata20_phi_psi==1 || kojiku->check.check_filter20_phi_psi==1){
			Reserve_Memory_Double_1D( &(kojiku->data.psi.real),	kojiku->line.line );
			Reserve_Memory_Double_1D( &(kojiku->data.psi.imag),	kojiku->line.line );
		}

		if(kojiku->check.check_rawdata15_phi==1 || kojiku->check.check_filter15_phi==1 || kojiku->check.check_rawdata20_phi_psi==1 || kojiku->check.check_filter20_phi_psi==1 || kojiku->check.check_rawdata16_phi_spsi==1 || kojiku->check.check_filter16_phi_spsi==1){
			Reserve_Memory_Double_1D( &(kojiku->data.phi.real),	kojiku->line.line );
			Reserve_Memory_Double_1D( &(kojiku->data.phi.imag),	kojiku->line.line );
		}

		if(kojiku->check.check_rawdata18_hwi2==1 || kojiku->check.check_filter18_hwi2==1 || kojiku->check.check_FFTampspec18_hwi2==1){
			Reserve_Memory_Double_1D( &(kojiku->data.phi2.real), kojiku->line.line );
			Reserve_Memory_Double_1D( &(kojiku->data.phi2.imag), kojiku->line.line );

			Reserve_Memory_Double_1D( &(kojiku->data.hwi2.real),kojiku->line.line );
			Reserve_Memory_Double_1D( &(kojiku->data.hwi2.imag),kojiku->line.line );
			Reserve_Memory_Double_1D( &(kojiku->data.hwi2.abs),	kojiku->line.line );
		}

		if (kojiku->check.check_rawdata25_hwi3 == 1 || kojiku->check.check_filter25_hwi3 == 1 || kojiku->check.check_FFTampspec25_hwi3 == 1){
			Reserve_Memory_Double_1D(&(kojiku->data.phi3.real), kojiku->line.line);
			Reserve_Memory_Double_1D(&(kojiku->data.phi3.imag), kojiku->line.line);

			Reserve_Memory_Double_1D(&(kojiku->data.hwi3.real), kojiku->line.line);
			Reserve_Memory_Double_1D(&(kojiku->data.hwi3.imag), kojiku->line.line);
			Reserve_Memory_Double_1D(&(kojiku->data.hwi3.abs), kojiku->line.line);
		}

		if(kojiku->check.check_rawdata13_spsi==1 || kojiku->check.check_filter13_spsi==1 || kojiku->check.check_rawdata10_pspr==1 || kojiku->check.check_filter20_phi_psi==1 || kojiku->check.check_rawdata16_phi_spsi==1 || kojiku->check.check_filter16_phi_spsi==1){
			Reserve_Memory_Double_1D( &(kojiku->data.psi_s.real), kojiku->line.line );
			Reserve_Memory_Double_1D( &(kojiku->data.psi_s.imag), kojiku->line.line );
		}

		if(kojiku->check.check_rawdata22_valve==1){
			Reserve_Memory_Double_1D( &(kojiku->data.valve.real), kojiku->line.line );
		}

		if (kojiku->check.check_rawdata27_plunge == 1) {
			Reserve_Memory_Double_1D(&(kojiku->data.plunge.real), kojiku->line.line);
		}

		if(kojiku->check.check_rawdata_dpdt_dqdt==1){
			Reserve_Memory_Double_1D( &(kojiku->data.dpdt.real), kojiku->line.line );
			Reserve_Memory_Double_1D( &(kojiku->data.dqdt.real), kojiku->line.line );
		}

		if (kojiku->check. check_rawdata31_hwsp1_v == 1 || kojiku->check. check_filter31_hwsp1_v == 1|| kojiku->check. check_rawdata37_2daverv1 == 1 || kojiku->check.check_filter37_2daverv1  == 1 || kojiku->check. check_rawdata38_2dphi1 == 1 || kojiku->check.check_filter38_2dphi1  == 1){
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp1_v.real),	kojiku->line.line );
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp1_v.imag),	kojiku->line.line );
		}

		if (kojiku->check. check_rawdata32_hwsp1_alpha == 1 || kojiku->check. check_filter32_hwsp1_alpha == 1|| kojiku->check. check_rawdata37_2daverv1 == 1 || kojiku->check.check_filter37_2daverv1  == 1 || kojiku->check. check_rawdata38_2dphi1 == 1 || kojiku->check.check_filter38_2dphi1  == 1){
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp1_alpha.real),	kojiku->line.line );
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp1_alpha.imag),	kojiku->line.line );
		}

		if (kojiku->check. check_rawdata33_hwsp1_vaxis == 1 || kojiku->check. check_filter33_hwsp1_vaxis == 1 || kojiku->check. check_FFTampspec33_hwsp1_vaxis == 1 || kojiku->check. check_rawdata37_2daverv1 == 1 || kojiku->check.check_filter37_2daverv1  == 1 || kojiku->check. check_rawdata38_2dphi1 == 1 || kojiku->check.check_filter38_2dphi1  == 1 ){
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp1_vaxis.real),	kojiku->line.line );
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp1_vaxis.imag),	kojiku->line.line );
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp1_vaxis.abs),	kojiku->line.line );
		}

		if (kojiku->check. check_rawdata34_hwsp1_vcir == 1 || kojiku->check. check_filter34_hwsp1_vcir == 1 || kojiku->check. check_FFTampspec34_hwsp1_vcir == 1){
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp1_vcir.real),	kojiku->line.line );
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp1_vcir.imag),	kojiku->line.line );
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp1_vcir.abs),	kojiku->line.line );
		}

		if (kojiku->check. check_rawdata35_ndvaxis1 == 1 || kojiku->check. check_filter35_ndvaxis1 == 1){
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp1_ndvaxis.real), kojiku->line.line );
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp1_ndvaxis.imag), kojiku->line.line );
		}

		if (kojiku->check. check_rawdata36_ndvcir1 == 1 || kojiku->check. check_filter36_ndvcir1 == 1){
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp1_ndvcir.real),	 kojiku->line.line );
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp1_ndvcir.imag),	 kojiku->line.line );
		}

		if (kojiku->check. check_rawdata37_2daverv1 == 1 || kojiku->check.check_filter37_2daverv1  == 1 || kojiku->check. check_rawdata38_2dphi1 == 1 || kojiku->check.check_filter38_2dphi1  == 1 ){
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp1_twod_averv.real),	kojiku->line.line );
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp1_twod_averv.imag),	kojiku->line.line );
		}

		if (kojiku->check. check_rawdata38_2dphi1 == 1 || kojiku->check.check_filter38_2dphi1  == 1){
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp1_twod_phi.real),	kojiku->line.line );
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp1_twod_phi.imag),	kojiku->line.line );
		}

		if (kojiku->check. check_rawdata41_hwsp2_v == 1 || kojiku->check. check_filter41_hwsp2_v == 1||kojiku->check. check_rawdata47_2daverv2 == 1 || kojiku->check.check_filter47_2daverv2  == 1 ||kojiku->check. check_rawdata48_2dphi2 == 1 || kojiku->check.check_filter48_2dphi2  == 1){
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp2_v.real),	kojiku->line.line );
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp2_v.imag),	kojiku->line.line );
		}

		if (kojiku->check. check_rawdata42_hwsp2_alpha == 1 || kojiku->check. check_filter42_hwsp2_alpha == 1||kojiku->check. check_rawdata47_2daverv2 == 1 || kojiku->check.check_filter47_2daverv2  == 1 ||kojiku->check. check_rawdata48_2dphi2 == 1 || kojiku->check.check_filter48_2dphi2  == 1){
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp2_alpha.real),	kojiku->line.line );
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp2_alpha.imag),	kojiku->line.line );
		}

		if (kojiku->check. check_rawdata43_hwsp2_vaxis == 1 || kojiku->check. check_filter43_hwsp2_vaxis == 1 || kojiku->check.check_FFTampspec43_hwsp2_vaxis == 1||kojiku->check. check_rawdata47_2daverv2 == 1 || kojiku->check.check_filter47_2daverv2  == 1 ||kojiku->check. check_rawdata48_2dphi2 == 1 || kojiku->check.check_filter48_2dphi2  == 1){
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp2_vaxis.real),	kojiku->line.line );
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp2_vaxis.imag),	kojiku->line.line );
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp2_vaxis.abs),	kojiku->line.line );
		}

		if (kojiku->check. check_rawdata44_hwsp2_vcir == 1 || kojiku->check. check_filter44_hwsp2_vcir == 1 || kojiku->check.check_FFTampspec44_hwsp2_vcir == 1){
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp2_vcir.real),	kojiku->line.line );
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp2_vcir.imag),	kojiku->line.line );
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp2_vcir.abs),	kojiku->line.line );
		}

		if (kojiku->check. check_rawdata45_ndvaxis2 == 1 || kojiku->check. check_filter45_ndvaxis2 == 1){
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp2_ndvaxis.real), kojiku->line.line );
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp2_ndvaxis.imag), kojiku->line.line );
		}

		if (kojiku->check. check_rawdata46_ndvcir2 == 1 || kojiku->check. check_filter46_ndvcir2 == 1){
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp2_ndvcir.real),	 kojiku->line.line );
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp2_ndvcir.imag),	 kojiku->line.line );
		}

		if (kojiku->check. check_rawdata47_2daverv2 == 1 || kojiku->check.check_filter47_2daverv2  == 1 ||kojiku->check. check_rawdata48_2dphi2 == 1 || kojiku->check.check_filter48_2dphi2  == 1){
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp2_twod_averv.real),	kojiku->line.line );
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp2_twod_averv.imag),	kojiku->line.line );
		}

		if (kojiku->check. check_rawdata48_2dphi2 == 1 || kojiku->check.check_filter48_2dphi2  == 1){
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp2_twod_phi.real),	kojiku->line.line );
			Reserve_Memory_Double_1D( &(kojiku->data.hwsp2_twod_phi.imag),	kojiku->line.line );
		}

		if(kojiku->check.check_rawdata51_ptank==1 || kojiku->check.check_filter51_ptank==1){
			Reserve_Memory_Double_1D( &(kojiku->data.ptank.real),	kojiku->line.line );
			Reserve_Memory_Double_1D( &(kojiku->data.ptank.imag),	kojiku->line.line );
		}

		if(kojiku->check.check_rawdata52_ptank_psi==1 || kojiku->check.check_filter52_ptank_psi==1){
			Reserve_Memory_Double_1D( &(kojiku->data.ptank_psi.real),	kojiku->line.line );
			Reserve_Memory_Double_1D( &(kojiku->data.ptank_psi.imag),	kojiku->line.line );
		}

		Reserve_Memory_Double_1D( &(kojiku->freq.axis_ampspec), kojiku->line.ampspec );
	}
	//printf("memori%lf\n",kojiku->sens.kousei.P_1);
}


//-------------------------------------------------------------------------------------------------------------
//メモリ確保関数(double・1次元)
//-------------------------------------------------------------------------------------------------------------
void Reserve_Memory_Double_1D( double **data_d, unsigned int ii){

	//__メモリ確保-----------------------------------------------------------------------------------
	*data_d = (double *)calloc(ii, sizeof(double));
	if( *data_d==NULL ){
		printf("メモリーが足りません。\n\a");
		while(1);
	}
}

//-------------------------------------------------------------------------------------------------------------
//メモリ確保関数(int ・1次元)
//-------------------------------------------------------------------------------------------------------------
void Reserve_Memory_INT_1D( int **data_d, unsigned int ii){

	//__メモリ確保-----------------------------------------------------------------------------------
	*data_d = (int *)calloc(ii, sizeof(int));
	if( *data_d==NULL ){
		printf("メモリーが足りません。\n\a");
		while(1);
	}
}



//-------------------------------------------------------------------------------------------------------------
//メモリ確保関数(double・2次元)
//-------------------------------------------------------------------------------------------------------------
void Reserve_Memory_Double_2D( double ***data_d, unsigned int ii, unsigned int jj ){

	//変数宣言---------------------------------------------------------------------------------------
	unsigned int	j;			//列カウンタ

	//__メモリ確保-----------------------------------------------------------------------------------
	*data_d = (double **)calloc(jj, sizeof(double *));
	for(j=0; j<jj; j++){
		(*data_d)[j] = (double *)calloc(ii, sizeof(double));
		if( (*data_d)[j]==NULL ){
			printf("メモリーが足りません。\n");
			while(1);
		}
	}
}

//------------------------------------------------------------------------------------------------------------
//計算データ用メモリ確保関数
//------------------------------------------------------------------------------------------------------------
void Free_Memory( st_kojiku *kojiku ){
	//メモリ開放--------------------------------------------------------------------------------------
	if(kojiku->check.check_rawdata01_1A==1 || kojiku->check.check_filter01_1A==1 || kojiku->check.check_FFTampspec01_1A==1){
		free( kojiku->data.wp1A.real );
		free( kojiku->data.wp1A.imag );
		free( kojiku->data.wp1A.abs );
		puts("1");
	}
	if(kojiku->check.check_rawdata02_1C==1 || kojiku->check.check_filter02_1C==1){
		free( kojiku->data.wp1C.real );
		free( kojiku->data.wp1C.imag );
		puts("2");
	}
	if(kojiku->check.check_rawdata03_1E==1 || kojiku->check.check_filter03_1E==1){
		free( kojiku->data.wp1E.real );
		free( kojiku->data.wp1E.imag );
		puts("3");
	}
	if(kojiku->check.check_rawdata04_2A==1 || kojiku->check.check_filter04_2A==1 || kojiku->check.check_FFTampspec04_2A==1){
		free( kojiku->data.wp2A.real );
		free( kojiku->data.wp2A.imag );
		free( kojiku->data.wp2A.abs );
		puts("4");
	}
	if(kojiku->check.check_rawdata05_2C==1 || kojiku->check.check_filter05_2C==1){
		free( kojiku->data.wp2C.real );
		free( kojiku->data.wp2C.imag );
		puts("5");
	}
	if(kojiku->check.check_rawdata06_2E==1 || kojiku->check.check_filter06_2E==1){
		free( kojiku->data.wp2E.real );
		free( kojiku->data.wp2E.imag );
		puts("6");
	}
	if(kojiku->check.check_rawdata07_3A==1 || kojiku->check.check_filter07_3A==1 || kojiku->check.check_FFTampspec07_3A==1){
		free( kojiku->data.wp3A.real );
		free( kojiku->data.wp3A.imag );
		free( kojiku->data.wp3A.abs );
		puts("7");
	}
	if(kojiku->check.check_rawdata08_3C==1 || kojiku->check.check_filter08_3C==1){
		free( kojiku->data.wp3C.real );
		free( kojiku->data.wp3C.imag );
		puts("8");
	}
	if(kojiku->check.check_rawdata09_3E==1 || kojiku->check.check_filter09_3E==1){
		free( kojiku->data.wp3E.real );
		free( kojiku->data.wp3E.imag );
		puts("9");
	}
	if(kojiku->check.check_rawdata10_pspr==1 || kojiku->check.check_filter10_pspr==1 || kojiku->check.check_rawdata12_ptpr==1 || kojiku->check.check_filter12_ptpr==1 || kojiku->check.check_rawdata14_psi==1 || kojiku->check.check_filter14_psi==1 || kojiku->check.check_rawdata20_phi_psi==1 || kojiku->check.check_filter20_phi_psi==1 || kojiku->check.check_FFTampspec12_ptpr==1 || kojiku->check.check_rawdata16_phi_spsi==1 || kojiku->check.check_filter16_phi_spsi==1 || kojiku->check.check_rawdata13_spsi==1 || kojiku->check.check_filter13_spsi==1){
		free( kojiku->data.pspr.real );
		free( kojiku->data.pspr.imag );
		puts("10");
	}
	if(kojiku->check.check_rawdata11_hwi==1 || kojiku->check.check_filter11_hwi==1 || kojiku->check.check_rawdata13_averv==1 || kojiku->check.check_filter13_averv==1 || kojiku->check.check_rawdata15_phi==1 || kojiku->check.check_filter15_phi==1 || kojiku->check.check_rawdata20_phi_psi==1 || kojiku->check.check_filter20_phi_psi==1 || kojiku->check.check_FFTampspec11_hwi==1 || kojiku->check.check_rawdata16_phi_spsi==1 || kojiku->check.check_filter16_phi_spsi==1){
		free( kojiku->data.hwi.real );
		free( kojiku->data.hwi.imag );
		free( kojiku->data.hwi.abs );
		puts("11");
	}
	if(kojiku->check.check_rawdata12_ptpr==1 || kojiku->check.check_filter12_ptpr==1 || kojiku->check.check_rawdata14_psi==1 || kojiku->check.check_filter14_psi==1 || kojiku->check.check_rawdata20_phi_psi==1 || kojiku->check.check_filter20_phi_psi==1 || kojiku->check.check_FFTampspec12_ptpr==1 || kojiku->check.check_rawdata13_spsi==1 || kojiku->check.check_filter13_spsi==1 || kojiku->check.check_rawdata16_phi_spsi==1 || kojiku->check.check_filter16_phi_spsi==1){
		free( kojiku->data.ptpr.real );
		free( kojiku->data.ptpr.imag );
		free( kojiku->data.ptpr.abs );
		puts("12");
	}
	if(kojiku->check.check_rawdata13_averv==1 || kojiku->check.check_filter13_averv==1 || kojiku->check.check_rawdata15_phi==1 || kojiku->check.check_filter15_phi==1 || kojiku->check.check_rawdata20_phi_psi==1 || kojiku->check.check_filter20_phi_psi==1 || kojiku->check.check_rawdata16_phi_spsi==1 || kojiku->check.check_filter16_phi_spsi==1){
		free( kojiku->data.averv.real );
		free( kojiku->data.averv.imag );
		puts("13");
	}
	if(kojiku->check.check_rawdata13_spsi==1 || kojiku->check.check_filter13_spsi==1 || kojiku->check.check_rawdata16_phi_spsi==1 || kojiku->check.check_filter16_phi_spsi==1){
		free( kojiku->data.psi_s.real );
		free( kojiku->data.psi_s.imag );
		puts("13.5");
	}
	if(kojiku->check.check_rawdata14_psi==1 || kojiku->check.check_filter14_psi==1 || kojiku->check.check_rawdata20_phi_psi==1 || kojiku->check.check_filter20_phi_psi==1){
		free( kojiku->data.psi.real );
		free( kojiku->data.psi.imag );
		puts("14");
	}
	if(kojiku->check.check_rawdata15_phi==1 || kojiku->check.check_filter15_phi==1 || kojiku->check.check_rawdata20_phi_psi==1 || kojiku->check.check_filter20_phi_psi==1 || kojiku->check.check_rawdata16_phi_spsi==1 || kojiku->check.check_filter16_phi_spsi==1){
		free( kojiku->data.phi.real );
		free( kojiku->data.phi.imag );
		puts("15");
	}
	if(kojiku->check.check_rawdata18_hwi2==1 || kojiku->check.check_filter18_hwi2==1 || kojiku->check.check_FFTampspec18_hwi2==1){
		free( kojiku->data.phi2.real );
		free( kojiku->data.phi2.imag );
		free( kojiku->data.hwi2.real );
		free( kojiku->data.hwi2.imag );
		free( kojiku->data.hwi2.abs );
		puts("18");
	}
	if (kojiku->check.check_rawdata22_valve == 1) {
		free(kojiku->data.valve.real);
		puts("22");
	}
	if (kojiku->check.check_rawdata25_hwi3 == 1 || kojiku->check.check_filter25_hwi3 == 1 || kojiku->check.check_FFTampspec25_hwi3 == 1){
		free(kojiku->data.phi3.real);
		free(kojiku->data.phi3.imag);
		free( kojiku->data.hwi3.real );
		free( kojiku->data.hwi3.imag );
		free(kojiku->data.hwi3.abs);
		puts("25");
	}
	if (kojiku->check.check_rawdata27_plunge == 1) {
		free(kojiku->data.plunge.real);
		puts("27");
	}

	free( kojiku->freq.axis_ampspec );
	puts("axis");

	if (kojiku->check.check_rawdata_dpdt_dqdt == 1) {
		free(kojiku->data.dpdt.real);
		free(kojiku->data.dqdt.real);
		puts("dqdt,dpdt");
	}

	if (kojiku->check. check_rawdata31_hwsp1_v == 1 || kojiku->check. check_filter31_hwsp1_v == 1|| kojiku->check. check_rawdata37_2daverv1 == 1 || kojiku->check.check_filter37_2daverv1  == 1 || kojiku->check. check_rawdata38_2dphi1 == 1 || kojiku->check.check_filter38_2dphi1  == 1){
		free(kojiku->data.hwsp1_v.real);
		free(kojiku->data.hwsp1_v.imag);
		puts("31");
	}

	if (kojiku->check. check_rawdata32_hwsp1_alpha == 1 || kojiku->check. check_filter32_hwsp1_alpha == 1|| kojiku->check. check_rawdata37_2daverv1 == 1 || kojiku->check.check_filter37_2daverv1  == 1 || kojiku->check. check_rawdata38_2dphi1 == 1 || kojiku->check.check_filter38_2dphi1  == 1){
		free(kojiku->data.hwsp1_alpha.real);
		free(kojiku->data.hwsp1_alpha.imag);
		puts("32");
	}

	if (kojiku->check. check_rawdata33_hwsp1_vaxis == 1 || kojiku->check. check_filter33_hwsp1_vaxis == 1 || kojiku->check. check_FFTampspec33_hwsp1_vaxis == 1 || kojiku->check. check_rawdata37_2daverv1 == 1 || kojiku->check.check_filter37_2daverv1  == 1 || kojiku->check. check_rawdata38_2dphi1 == 1 || kojiku->check.check_filter38_2dphi1  == 1 ){
		free(kojiku->data.hwsp1_vaxis.real);
		free(kojiku->data.hwsp1_vaxis.imag);
		free(kojiku->data.hwsp1_vaxis.abs);
		puts("33");
	}

	if (kojiku->check. check_rawdata34_hwsp1_vcir == 1 || kojiku->check. check_filter34_hwsp1_vcir == 1 || kojiku->check. check_FFTampspec34_hwsp1_vcir == 1){
		free(kojiku->data.hwsp1_vcir.real);
		free(kojiku->data.hwsp1_vcir.imag);
		free(kojiku->data.hwsp1_vcir.abs);
		puts("34");
	}

	if (kojiku->check. check_rawdata35_ndvaxis1 == 1 || kojiku->check. check_filter35_ndvaxis1 == 1){
		free(kojiku->data.hwsp1_ndvaxis.real);
		free(kojiku->data.hwsp1_ndvaxis.imag);
		puts("35");
	}

	if (kojiku->check. check_rawdata36_ndvcir1 == 1 || kojiku->check. check_filter36_ndvcir1 == 1){
		free(kojiku->data.hwsp1_ndvcir.real);
		free(kojiku->data.hwsp1_ndvcir.imag);
		puts("36");
	}

	if (kojiku->check. check_rawdata37_2daverv1 == 1 || kojiku->check.check_filter37_2daverv1  == 1 || kojiku->check. check_rawdata38_2dphi1 == 1 || kojiku->check.check_filter38_2dphi1  == 1 ){
		free(kojiku->data.hwsp1_twod_averv.real);
		free(kojiku->data.hwsp1_twod_averv.imag);
		puts("37");
	}

	if (kojiku->check. check_rawdata38_2dphi1 == 1 || kojiku->check.check_filter38_2dphi1  == 1){
		free(kojiku->data.hwsp1_twod_phi.real);
		free(kojiku->data.hwsp1_twod_phi.imag);
		puts("38");
	}

	if (kojiku->check. check_rawdata41_hwsp2_v == 1 || kojiku->check. check_filter41_hwsp2_v == 1||kojiku->check. check_rawdata47_2daverv2 == 1 || kojiku->check.check_filter47_2daverv2  == 1 ||kojiku->check. check_rawdata48_2dphi2 == 1 || kojiku->check.check_filter48_2dphi2  == 1){
		free(kojiku->data.hwsp2_v.real);
		free(kojiku->data.hwsp2_v.imag);
		puts("41");
	}

	if (kojiku->check. check_rawdata42_hwsp2_alpha == 1 || kojiku->check. check_filter42_hwsp2_alpha == 1||kojiku->check. check_rawdata47_2daverv2 == 1 || kojiku->check.check_filter47_2daverv2  == 1 ||kojiku->check. check_rawdata48_2dphi2 == 1 || kojiku->check.check_filter48_2dphi2  == 1){
		free(kojiku->data.hwsp2_alpha.real);
		free(kojiku->data.hwsp2_alpha.imag);
		puts("42");
	}

	if (kojiku->check. check_rawdata43_hwsp2_vaxis == 1 || kojiku->check. check_filter43_hwsp2_vaxis == 1 || kojiku->check.check_FFTampspec43_hwsp2_vaxis == 1||kojiku->check. check_rawdata47_2daverv2 == 1 || kojiku->check.check_filter47_2daverv2  == 1 ||kojiku->check. check_rawdata48_2dphi2 == 1 || kojiku->check.check_filter48_2dphi2  == 1){
		free(kojiku->data.hwsp2_vaxis.real);
		free(kojiku->data.hwsp2_vaxis.imag);
		free(kojiku->data.hwsp2_vaxis.abs);
		puts("43");
	}

	if (kojiku->check. check_rawdata44_hwsp2_vcir == 1 || kojiku->check. check_filter44_hwsp2_vcir == 1 || kojiku->check.check_FFTampspec44_hwsp2_vcir == 1){
		free(kojiku->data.hwsp2_vcir.real);
		free(kojiku->data.hwsp2_vcir.imag);
		free(kojiku->data.hwsp2_vcir.abs);
		puts("44");
	}

	if (kojiku->check. check_rawdata45_ndvaxis2 == 1 || kojiku->check. check_filter45_ndvaxis2 == 1){
		free(kojiku->data.hwsp2_ndvaxis.real);
		free(kojiku->data.hwsp2_ndvaxis.imag);
		puts("45");
	}

	if (kojiku->check. check_rawdata46_ndvcir2 == 1 || kojiku->check. check_filter46_ndvcir2 == 1){
		free(kojiku->data.hwsp2_ndvcir.real);
		free(kojiku->data.hwsp2_ndvcir.imag);
		puts("46");
	}

	if (kojiku->check. check_rawdata47_2daverv2 == 1 || kojiku->check.check_filter47_2daverv2  == 1 ||kojiku->check. check_rawdata48_2dphi2 == 1 || kojiku->check.check_filter48_2dphi2  == 1){
		free(kojiku->data.hwsp2_twod_averv.real);
		free(kojiku->data.hwsp2_twod_averv.imag);
		puts("47");
	}

	if (kojiku->check. check_rawdata48_2dphi2 == 1 || kojiku->check.check_filter48_2dphi2  == 1){
		free(kojiku->data.hwsp2_twod_phi.real);
		free(kojiku->data.hwsp2_twod_phi.imag);
		puts("48");
	}

	
		if(kojiku->check.check_rawdata51_ptank==1 || kojiku->check.check_filter51_ptank==1){
			free(kojiku->data.ptank.real);
			free(kojiku->data.ptank.imag);
			puts("51");
		}

		if(kojiku->check.check_rawdata52_ptank_psi==1 || kojiku->check.check_filter52_ptank_psi==1){
			free(kojiku->data.ptank_psi.real);
			free(kojiku->data.ptank_psi.imag);
				puts("52");
		}

}

//------------------------------------------------------------------------------------------------------------
//メモリ開放関数（double）
//------------------------------------------------------------------------------------------------------------
void Free_Memory_Double_2D(	double ***data_d, unsigned int jj ){

	//変数宣言---------------------------------------------------------------------------------------
	unsigned int j;			//列カウンタ

	//メモリ開放--------------------------------------------------------------------------------------
	for( j=0; j<jj; j++ ){
		free( (*data_d)[j] );
	}
	free( *data_d );
}
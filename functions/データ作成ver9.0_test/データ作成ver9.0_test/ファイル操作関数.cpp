//*************************************************************************************************************
//ファイル操作に関する関数
//*************************************************************************************************************

#pragma warning( disable: 4996 )       // コード先頭に記載

//ライブラリ、自作ヘッダのインクルード
#include	<stdio.h>
#include	<windows.h>				//CreateDirectory()を使うのに必要
#include	<direct.h>				//madir()を使うのに必要
#include	<time.h>				//Random関数で用いる
#include	<stdlib.h>				//Random関数で用いる
#include	"定数・構造体定義.h"
#include	"自作関数定義.h"		//自作ヘッダ


//-------------------------------------------------------------------------------------------------------------
//結果を収めるフォルダを作る関数
//-------------------------------------------------------------------------------------------------------------
void Create_Directory( st_kojiku *kojiku ){

	//パスと名前をくっつける---------------------------------------------------------------------------
	sprintf( kojiku->file.posit_num_dir, "%s/%03d_result", kojiku->file.posit.out, kojiku->file.num.data );

	//フォルダ作成------------------------------------------------------------------------------------
	//CreateDirectory( kojiku->file.posit_num_dir, NULL );	//「windows.h」のインクルードが必要
	mkdir( kojiku->file.posit_num_dir );					//「direct.h」のインクルードが必要
}


//-------------------------------------------------------------------------------------------------------------
//ファイルを開く関数
//-------------------------------------------------------------------------------------------------------------
void Open_File( st_kojiku *kojiku ){
	//ファイルを開く----------------------------------------------------------------------------------
	Open_File_Init( kojiku );
	Open_File_P_Max( kojiku );
	Open_File_In( kojiku );

	//フォルダを作成
	Create_Directory( kojiku );

	//__生データ-----------------------------------------------
	Open_File_Out(	&kojiku->file.fp.wp1A.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata01_wp01.txt",
		kojiku->file.num.data
		);
	Open_File_Out(	&kojiku->file.fp.wp1C.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata02_wp02.txt",
		kojiku->file.num.data
		);
	Open_File_Out(	&kojiku->file.fp.wp1E.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata03_ACF1.txt",
		kojiku->file.num.data
		);
	Open_File_Out(	&kojiku->file.fp.wp2A.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata04_wp03.txt",
		kojiku->file.num.data
		);
	Open_File_Out(	&kojiku->file.fp.wp2C.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata05_wp04.txt",
		kojiku->file.num.data
		);
	Open_File_Out(	&kojiku->file.fp.wp2E.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata06_ACF2.txt",
		kojiku->file.num.data
		);
	Open_File_Out(	&kojiku->file.fp.wp3A.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata07_wp05.txt",
		kojiku->file.num.data
		);
	Open_File_Out(	&kojiku->file.fp.wp3C.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata08_wp06.txt",
		kojiku->file.num.data
		);
	Open_File_Out(	&kojiku->file.fp.wp3E.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata09_ACF3.txt",
		kojiku->file.num.data
		);
	Open_File_Out(	&kojiku->file.fp.pspr.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata10_pspr.txt",
		kojiku->file.num.data
		);
	Open_File_Out(	&kojiku->file.fp.hwi.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata11_hwi.txt",
		kojiku->file.num.data
		);
	Open_File_Out(	&kojiku->file.fp.ptpr.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata12_ptpr.txt",
		kojiku->file.num.data
		);
	Open_File_Out(	&kojiku->file.fp.averv.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata13_averv.txt",
		kojiku->file.num.data
		);
	Open_File_Out(	&kojiku->file.fp.psi.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata14_tpsi.txt",
		kojiku->file.num.data
		);
	Open_File_Out(	&kojiku->file.fp.phi.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata15_phi.txt",
		kojiku->file.num.data
		);
	Open_File_Out(	&kojiku->file.fp.hwi2.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata18_hwi2.txt",
		kojiku->file.num.data
		);
	Open_File_Out(	&kojiku->file.fp.phi2.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata19_phi2.txt",
		kojiku->file.num.data
		);

	Open_File_Out(&kojiku->file.fp.hwi3.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata25_hwi3.txt",
		kojiku->file.num.data
		);
	Open_File_Out(&kojiku->file.fp.phi3.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata26_phi3.txt",
		kojiku->file.num.data
		);

	Open_File_Out(	&kojiku->file.fp.phi_psi.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata17_phi_tpsi.txt",
		kojiku->file.num.data
		);
	Open_File_Out(	&kojiku->file.fp.psi_s.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata13_spsi.txt",
		kojiku->file.num.data
		);
	Open_File_Out(	&kojiku->file.fp.phi_psi_s.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata16_phi_spsi.txt",
		kojiku->file.num.data
		);

	Open_File_Out(	&kojiku->file.fp.valve.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata22_valve.txt",
		kojiku->file.num.data
		);

	Open_File_Out(	&kojiku->file.fp.dpdt.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata23_dpdt.txt",
		kojiku->file.num.data
		);

	Open_File_Out(	&kojiku->file.fp.dqdt.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata24_dqdt.txt",
		kojiku->file.num.data
		);

	Open_File_Out(&kojiku->file.fp.plunge.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata27_plunge.txt",
		kojiku->file.num.data
		);

	Open_File_Out(	&kojiku->file.fp.hwsp1_v.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata31_hwsp1_v.txt",
		kojiku->file.num.data
		);

	Open_File_Out(	&kojiku->file.fp.hwsp1_alpha.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata32_hwsp1_alpha.txt",
		kojiku->file.num.data
		);

	Open_File_Out(	&kojiku->file.fp.hwsp1_vaxis.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata33_hwsp1_vaxis.txt",
		kojiku->file.num.data
		);

	Open_File_Out(	&kojiku->file.fp.hwsp1_vcir.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata34_hwsp1_vcir.txt",
		kojiku->file.num.data
		);

	Open_File_Out(	&kojiku->file.fp.hwsp1_ndvaxis.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata35_ndvaxis1.txt",
		kojiku->file.num.data
		);

	Open_File_Out(	&kojiku->file.fp.hwsp1_ndvcir.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata36_ndvcir1.txt",
		kojiku->file.num.data
		);

	Open_File_Out(	&kojiku->file.fp.hwsp1_twod_averv.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata37_2daverv1.txt",
		kojiku->file.num.data
		);

	Open_File_Out(	&kojiku->file.fp.hwsp1_twod_phi.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata38_2dphi1.txt",
		kojiku->file.num.data
		);

	Open_File_Out(	&kojiku->file.fp.hwsp1_twod_phi_psi.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata39_2dphi_psi1.txt",
		kojiku->file.num.data
		);

	Open_File_Out(	&kojiku->file.fp.hwsp2_v.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata41_hwsp2_v.txt" ,
		kojiku->file.num.data
		);

	Open_File_Out(	&kojiku->file.fp.hwsp2_alpha.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata42_hwsp2_alpha.txt" ,
		kojiku->file.num.data
		);

	Open_File_Out(	&kojiku->file.fp.hwsp2_vaxis.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata43_hwsp2_vaxis.txt" ,
		kojiku->file.num.data
		);

	Open_File_Out(	&kojiku->file.fp.hwsp2_vcir.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata44_hwsp2_vcir.txt" ,
		kojiku->file.num.data
		);

	Open_File_Out(	&kojiku->file.fp.hwsp2_ndvaxis.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata45_ndvaxis2.txt" ,
		kojiku->file.num.data
		);

	Open_File_Out(	&kojiku->file.fp.hwsp2_ndvcir.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata46_ndvcir2.txt" ,
		kojiku->file.num.data
		);

	Open_File_Out(	&kojiku->file.fp.hwsp2_twod_averv.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata47_2daverv2.txt",
		kojiku->file.num.data
		);

	Open_File_Out(	&kojiku->file.fp.hwsp2_twod_phi.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata48_2dphi2.txt",
		kojiku->file.num.data
		);

	Open_File_Out(	&kojiku->file.fp.hwsp2_twod_phi_psi.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata49_2dphi_psi2.txt",
		kojiku->file.num.data
		);

	Open_File_Out(	&kojiku->file.fp.ptank.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata51_ptank.txt",
		kojiku->file.num.data
		);

	Open_File_Out(	&kojiku->file.fp.ptank_psi.rawdata,
		kojiku->file.posit_num_dir,
		"rawdata52_ptank_psi.txt",
		kojiku->file.num.data
		);


	//__フィルタ---------------------------------------------

	Open_File_Out(	&kojiku->file.fp.wp1A.filter,
		kojiku->file.posit_num_dir,
		"filter01_wp01.txt",
		kojiku->file.num.data
		);
	Open_File_Out(	&kojiku->file.fp.wp1C.filter,
		kojiku->file.posit_num_dir,
		"filter02_wp02.txt",
		kojiku->file.num.data
		);
	Open_File_Out(	&kojiku->file.fp.wp1E.filter,
		kojiku->file.posit_num_dir,
		"filter03_ACF1.txt",
		kojiku->file.num.data
		);
	Open_File_Out(	&kojiku->file.fp.wp2A.filter,
		kojiku->file.posit_num_dir,
		"filter04_wp03.txt",
		kojiku->file.num.data
		);
	Open_File_Out(	&kojiku->file.fp.wp2C.filter,
		kojiku->file.posit_num_dir,
		"filter05_wp04.txt",
		kojiku->file.num.data
		);
	Open_File_Out(	&kojiku->file.fp.wp2E.filter,
		kojiku->file.posit_num_dir,
		"filter06_ACF2.txt",
		kojiku->file.num.data
		);
	Open_File_Out(	&kojiku->file.fp.wp3A.filter,
		kojiku->file.posit_num_dir,
		"filter07_wp05.txt",
		kojiku->file.num.data
		);
	Open_File_Out(	&kojiku->file.fp.wp3C.filter,
		kojiku->file.posit_num_dir,
		"filter08_wp06.txt",
		kojiku->file.num.data
		);
	Open_File_Out(	&kojiku->file.fp.wp3E.filter,
		kojiku->file.posit_num_dir,
		"filter09_ACF3.txt",
		kojiku->file.num.data
		);
	Open_File_Out(	&kojiku->file.fp.pspr.filter,
		kojiku->file.posit_num_dir,
		"filter10_pspr.txt",
		kojiku->file.num.data
		);
	Open_File_Out(	&kojiku->file.fp.hwi.filter,
		kojiku->file.posit_num_dir,
		"filter11_hwi.txt",
		kojiku->file.num.data
		);
	Open_File_Out(	&kojiku->file.fp.ptpr.filter,
		kojiku->file.posit_num_dir,
		"filter12_ptpr.txt",
		kojiku->file.num.data
		);
	Open_File_Out(	&kojiku->file.fp.averv.filter,
		kojiku->file.posit_num_dir,
		"filter13_averv.txt",
		kojiku->file.num.data
		);
	Open_File_Out(	&kojiku->file.fp.psi.filter,
		kojiku->file.posit_num_dir,
		"filter14_tpsi.txt",
		kojiku->file.num.data
		);
	Open_File_Out(	&kojiku->file.fp.phi.filter,
		kojiku->file.posit_num_dir,
		"filter15_phi.txt",
		kojiku->file.num.data
		);
	Open_File_Out(	&kojiku->file.fp.hwi2.filter,
		kojiku->file.posit_num_dir,
		"filter18_hwi2.txt",
		kojiku->file.num.data
		);
	Open_File_Out(	&kojiku->file.fp.phi2.filter,
		kojiku->file.posit_num_dir,
		"filter19_phi2.txt",
		kojiku->file.num.data
		);

	Open_File_Out(&kojiku->file.fp.hwi3.filter,
		kojiku->file.posit_num_dir,
		"filter25_hwi3.txt",
		kojiku->file.num.data
		);
	Open_File_Out(&kojiku->file.fp.phi3.filter,
		kojiku->file.posit_num_dir,
		"filter26_phi3.txt",
		kojiku->file.num.data
		);

	Open_File_Out(	&(kojiku->file.fp.phi_psi.filter),
		kojiku->file.posit_num_dir,
		"filter17_phi_tpsi.txt",
		kojiku->file.num.data
		);
	Open_File_Out(	&kojiku->file.fp.psi_s.filter,
		kojiku->file.posit_num_dir,
		"filter13_spsi.txt"	,	//  静圧上昇係数ψs
		kojiku->file.num.data
		);
	Open_File_Out(	&(kojiku->file.fp.phi_psi_s.filter),
		kojiku->file.posit_num_dir,
		"filter16_phi_spsi.txt",
		kojiku->file.num.data
		);

	Open_File_Out(	&kojiku->file.fp.hwsp1_v.filter,
		kojiku->file.posit_num_dir,
		"filter31_hwsp1_v.txt",
		kojiku->file.num.data
		);

	Open_File_Out(	&kojiku->file.fp.hwsp1_alpha.filter,
		kojiku->file.posit_num_dir,
		"filter32_hwsp1_alpha.txt",
		kojiku->file.num.data
		);

	Open_File_Out(	&kojiku->file.fp.hwsp1_vaxis.filter,
		kojiku->file.posit_num_dir,
		"filter33_hwsp1_vaxis.txt",
		kojiku->file.num.data
		);

	Open_File_Out(	&kojiku->file.fp.hwsp1_vcir.filter,
		kojiku->file.posit_num_dir,
		"filter34_hwsp1_vcir.txt",
		kojiku->file.num.data
		);

	Open_File_Out(	&kojiku->file.fp.hwsp1_ndvaxis.filter,
		kojiku->file.posit_num_dir,
		"filter35_ndvaxis1.txt",
		kojiku->file.num.data
		);

	Open_File_Out(	&kojiku->file.fp.hwsp1_ndvcir.filter,
		kojiku->file.posit_num_dir,
		"filter36_ndvcir1.txt",
		kojiku->file.num.data
		);

	Open_File_Out(	&kojiku->file.fp.hwsp1_twod_averv.filter,
		kojiku->file.posit_num_dir,
		"filter37_2daverv1.txt",
		kojiku->file.num.data
		);

	Open_File_Out(	&kojiku->file.fp.hwsp1_twod_phi.filter,
		kojiku->file.posit_num_dir,
		"filter38_2dphi1.txt",
		kojiku->file.num.data
		);

	Open_File_Out(	&kojiku->file.fp.hwsp1_twod_phi_psi.filter,
		kojiku->file.posit_num_dir,
		"filter39_2dphi_psi1.txt",
		kojiku->file.num.data
		);

	Open_File_Out(	&kojiku->file.fp.hwsp2_v.filter,
		kojiku->file.posit_num_dir,
		"filter41_hwsp2_v.txt" ,
		kojiku->file.num.data
		);

	Open_File_Out(	&kojiku->file.fp.hwsp2_alpha.filter,
		kojiku->file.posit_num_dir,
		"filter42_hwsp2_alpha.txt" ,
		kojiku->file.num.data
		);

	Open_File_Out(	&kojiku->file.fp.hwsp2_vaxis.filter,
		kojiku->file.posit_num_dir,
		"filter43_hwsp2_vaxis.txt" ,
		kojiku->file.num.data
		);

	Open_File_Out(	&kojiku->file.fp.hwsp2_vcir.filter,
		kojiku->file.posit_num_dir,
		"filter44_hwsp2_vcir.txt" ,
		kojiku->file.num.data
		);

	Open_File_Out(	&kojiku->file.fp.hwsp2_ndvaxis.filter,
		kojiku->file.posit_num_dir,
		"filter45_ndvaxis2.txt" ,
		kojiku->file.num.data
		);

	Open_File_Out(	&kojiku->file.fp.hwsp2_ndvcir.filter,
		kojiku->file.posit_num_dir,
		"filter46_ndvcir2.txt" ,
		kojiku->file.num.data
		);

	Open_File_Out(	&kojiku->file.fp.hwsp2_twod_averv.filter,
		kojiku->file.posit_num_dir,
		"filter47_2daverv2.txt",
		kojiku->file.num.data
		);

	Open_File_Out(	&kojiku->file.fp.hwsp2_twod_phi.filter,
		kojiku->file.posit_num_dir,
		"filter48_2dphi2.txt",
		kojiku->file.num.data
		);

	Open_File_Out(	&kojiku->file.fp.hwsp2_twod_phi_psi.filter,
		kojiku->file.posit_num_dir,
		"filter49_2dphi_psi2.txt",
		kojiku->file.num.data
		);

	Open_File_Out(	&kojiku->file.fp.ptank.filter,
		kojiku->file.posit_num_dir,
		"filter51_ptank.txt",
		kojiku->file.num.data
		);

	Open_File_Out(	&kojiku->file.fp.ptank_psi.filter,
		kojiku->file.posit_num_dir,
		"filter52_ptank_psi.txt",
		kojiku->file.num.data
		);


	//振幅スペクトル-------------------------------------------
	Open_File_Out(	&kojiku->file.fp.wp1A.ampspec,
		kojiku->file.posit_num_dir,
		"FFTampspec01_1A.txt",
		kojiku->file.num.data
		);
	Open_File_Out(	&kojiku->file.fp.wp2A.ampspec,
		kojiku->file.posit_num_dir,
		"FFTampspec04_2A.txt",
		kojiku->file.num.data
		);
	Open_File_Out(	&kojiku->file.fp.wp3A.ampspec,
		kojiku->file.posit_num_dir,
		"FFTampspec07_3A.txt",
		kojiku->file.num.data
		);
	Open_File_Out(	&kojiku->file.fp.hwi.ampspec,
		kojiku->file.posit_num_dir,
		"FFTampspec11_hwi.txt",
		kojiku->file.num.data
		);
	Open_File_Out(	&kojiku->file.fp.ptpr.ampspec,
		kojiku->file.posit_num_dir,
		"FFTampspec12_ptpr.txt",
		kojiku->file.num.data
		);
	Open_File_Out(	&kojiku->file.fp.hwi2.ampspec,
		kojiku->file.posit_num_dir,	
		"FFTampspec18_hwi2.txt",
		kojiku->file.num.data
		);
	Open_File_Out(&kojiku->file.fp.hwi3.ampspec,
		kojiku->file.posit_num_dir,
		"FFTampspec25_hwi3.txt",
		kojiku->file.num.data
		);

	Open_File_Out(&kojiku->file.fp. hwsp1_vaxis.ampspec,
		kojiku->file.posit_num_dir,
		"FFTampspec33_hwsp1_vaxis.txt",
		kojiku->file.num.data
		);
	Open_File_Out(&kojiku->file.fp. hwsp1_vcir.ampspec,
		kojiku->file.posit_num_dir,
		"FFTampspec34_hwsp1_vcir.txt",
		kojiku->file.num.data
		);
	Open_File_Out(&kojiku->file.fp. hwsp2_vaxis.ampspec,
		kojiku->file.posit_num_dir,
		"FFTampspec43_hwsp2_vaxis.txt",
		kojiku->file.num.data
		);
	Open_File_Out(&kojiku->file.fp. hwsp2_vcir.ampspec,
		kojiku->file.posit_num_dir,
		"FFTampspec44_hwsp2_vcir.txt",
		kojiku->file.num.data
		);


	//printf("file%lf\n",kojiku->sens.kousei.P_1);
}

//-------------------------------------------------------------------------------------------------------------
//ファイルを閉じる関数
//-------------------------------------------------------------------------------------------------------------
void Close_File( st_kojiku *kojiku ){

	//ファイルを閉じる-----------------------------------------------------------------------------
	fclose( kojiku->file.fp.init );
	fclose( kojiku->file.fp.in );
	fclose( kojiku->file.fp.wp1A.rawdata );
	fclose( kojiku->file.fp.wp1C.rawdata );
	fclose( kojiku->file.fp.wp1E.rawdata );
	fclose( kojiku->file.fp.wp2A.rawdata );
	fclose( kojiku->file.fp.wp2C.rawdata );
	fclose( kojiku->file.fp.wp2E.rawdata );
	fclose( kojiku->file.fp.wp3A.rawdata );
	fclose( kojiku->file.fp.wp3C.rawdata );
	fclose( kojiku->file.fp.wp3E.rawdata );
	fclose( kojiku->file.fp.pspr.rawdata );
	fclose( kojiku->file.fp.hwi.rawdata );
	fclose( kojiku->file.fp.ptpr.rawdata );
	fclose( kojiku->file.fp.averv.rawdata );
	fclose( kojiku->file.fp.hwi2.rawdata );
	fclose( kojiku->file.fp.phi2.rawdata );
	fclose( kojiku->file.fp.hwi3.rawdata );
	fclose( kojiku->file.fp.phi3.rawdata );
	fclose( kojiku->file.fp.phi_psi.rawdata );
	fclose( kojiku->file.fp.psi_s.rawdata );
	fclose( kojiku->file.fp.phi_psi_s.rawdata );
	fclose( kojiku->file.fp.ptank.rawdata );
	fclose( kojiku->file.fp.ptank_psi.rawdata );

	fclose( kojiku->file.fp.hwsp1_v.rawdata );
	fclose( kojiku->file.fp.hwsp1_alpha.rawdata );
	fclose( kojiku->file.fp.hwsp1_vaxis.rawdata );
	fclose( kojiku->file.fp.hwsp1_vcir.rawdata );
	fclose( kojiku->file.fp.hwsp1_ndvaxis.rawdata );
	fclose( kojiku->file.fp.hwsp1_ndvcir.rawdata );
	fclose( kojiku->file.fp.hwsp1_twod_averv.rawdata );
	fclose( kojiku->file.fp.hwsp1_twod_phi.rawdata );
	fclose( kojiku->file.fp.hwsp1_twod_phi_psi.rawdata );

	fclose( kojiku->file.fp.hwsp2_v.rawdata );
	fclose( kojiku->file.fp.hwsp2_alpha.rawdata );
	fclose( kojiku->file.fp.hwsp2_vaxis.rawdata );
	fclose( kojiku->file.fp.hwsp2_vcir.rawdata );
	fclose( kojiku->file.fp.hwsp2_ndvaxis.rawdata );
	fclose( kojiku->file.fp.hwsp2_ndvcir.rawdata );
	fclose( kojiku->file.fp.hwsp2_twod_averv.rawdata );
	fclose( kojiku->file.fp.hwsp2_twod_phi.rawdata );
	fclose( kojiku->file.fp.hwsp2_twod_phi_psi.rawdata );

	fclose( kojiku->file.fp.wp1A.filter );
	fclose( kojiku->file.fp.wp1C.filter );
	fclose( kojiku->file.fp.wp1E.filter );
	fclose( kojiku->file.fp.wp2A.filter );
	fclose( kojiku->file.fp.wp2C.filter );
	fclose( kojiku->file.fp.wp2E.filter );
	fclose( kojiku->file.fp.wp3A.filter );
	fclose( kojiku->file.fp.wp3C.filter );
	fclose( kojiku->file.fp.wp3E.filter );
	fclose( kojiku->file.fp.pspr.filter );
	fclose( kojiku->file.fp.hwi.filter );
	fclose( kojiku->file.fp.ptpr.filter );
	fclose( kojiku->file.fp.averv.filter );
	fclose( kojiku->file.fp.hwi2.filter );
	fclose( kojiku->file.fp.phi2.filter );
	fclose( kojiku->file.fp.hwi3.filter );
	fclose( kojiku->file.fp.phi3.filter );
	fclose( kojiku->file.fp.phi_psi.filter );
	fclose( kojiku->file.fp.psi_s.filter );
	fclose( kojiku->file.fp.phi_psi_s.filter );
	fclose( kojiku->file.fp.ptank.filter );
	fclose( kojiku->file.fp.ptank_psi.filter );

	fclose( kojiku->file.fp.hwsp1_v.filter );
	fclose( kojiku->file.fp.hwsp1_alpha.filter );
	fclose( kojiku->file.fp.hwsp1_vaxis.filter );
	fclose( kojiku->file.fp.hwsp1_vcir.filter );
	fclose( kojiku->file.fp.hwsp1_ndvaxis.filter );
	fclose( kojiku->file.fp.hwsp1_ndvcir.filter );
	fclose( kojiku->file.fp.hwsp1_twod_averv.filter );
	fclose( kojiku->file.fp.hwsp1_twod_phi.filter );
	fclose( kojiku->file.fp.hwsp1_twod_phi_psi.filter );

	fclose( kojiku->file.fp.hwsp2_v.filter );
	fclose( kojiku->file.fp.hwsp2_alpha.filter );
	fclose( kojiku->file.fp.hwsp2_vaxis.filter );
	fclose( kojiku->file.fp.hwsp2_vcir.filter );
	fclose( kojiku->file.fp.hwsp2_ndvaxis.filter );
	fclose( kojiku->file.fp.hwsp2_ndvcir.filter );
	fclose( kojiku->file.fp.hwsp2_twod_averv.filter );
	fclose( kojiku->file.fp.hwsp2_twod_phi.filter );
	fclose( kojiku->file.fp.hwsp2_twod_phi_psi.filter );

	fclose( kojiku->file.fp.wp1A.ampspec );
	fclose( kojiku->file.fp.wp2A.ampspec );
	fclose( kojiku->file.fp.wp3A.ampspec );
	fclose( kojiku->file.fp.hwi.ampspec );
	fclose( kojiku->file.fp.ptpr.ampspec );
	fclose( kojiku->file.fp.hwi2.ampspec );
	fclose( kojiku->file.fp.hwi3.ampspec );

	fclose( kojiku->file.fp.hwsp1_vaxis.ampspec );
	fclose( kojiku->file.fp.hwsp1_vcir.ampspec );
	fclose( kojiku->file.fp.hwsp2_vaxis.ampspec );
	fclose( kojiku->file.fp.hwsp2_vcir.ampspec );

	fclose( kojiku->file.fp.valve.rawdata );
	fclose( kojiku->file.fp.dpdt.rawdata );
	fclose( kojiku->file.fp.dqdt.rawdata );
	fclose( kojiku->file.fp.plunge.rawdata );

}

//-------------------------------------------------------------------------------------------------------------
//イニシャルファイルを開く関数
//-------------------------------------------------------------------------------------------------------------
void Open_File_Init( st_kojiku *kojiku ){

	//変数宣言---------------------------------------------------------------------------------------
	char	posit_num_init[256];	//パスと番号をくっつけた文字列

	//入力フォルダパスとファイル番号をくっつけた文字列を作成--------------------------------------------
	sprintf( posit_num_init, "%s/%03di_%03di.txt",
		kojiku->file.posit.init, kojiku->file.num.init1, kojiku->file.num.init2 );

	//ファイルをテキストモードでオープン---------------------------------------------------------------
	if(  ( kojiku->file.fp.init = fopen(posit_num_init, "r") ) == NULL  ){
		printf( "「%03di_%03di.txt」は存在しません。\n",
			kojiku->file.num.init1, kojiku->file.num.init2 );

		//イニシャルファイルが存在しないときに実行されるバーボンハウス関数

		printf("\n\n\n\n\n\n");

		printf("やあ　（´・ω・｀)\a\a\a\n");Sleep(3000);
		printf("\n");
		printf("ようこそ、バーボンハウスへ。\a\a\a\n");Sleep(3000);
		printf("このテキーラはサービスだから、まず飲んで落ち着いて欲しい。\a\a\a\n");Sleep(3000);
		printf("\n");
		printf("うん、「また」なんだ。済まない。\a\a\a\n");Sleep(3000);
		printf("仏の顔もって言うしね、謝って許してもらおうとも思っていない。\a\a\a\n");Sleep(3000);
		printf("\n");
		printf("でも、イニシャルファイルをまだ作っていないことに気づいた時、\a\a\a\n");Sleep(3000);
		printf("君は、きっと言葉では言い表せない「ときめき」みたいなものを感じてくれたと思う。\a\a\a\n");Sleep(3000);
		printf("殺伐とした世の中で、そういう気持ちを忘れないで欲しい、\a\a\a\n");Sleep(3000);
		printf("そう思ってこれを作ったんだ。\a\a\a\n");Sleep(3000);
		printf("\n");
		printf("じゃあ、注文を聞こうか。\a\a\a\n");Sleep(1000);


		printf( "\n\n" );

		//printf( "プログラムを終了してください。\n\n" );

		printf( "じゃあの。\n\n" );
		while(1){printf("\a");};
	}
}

//-------------------------------------------------------------------------------------------------------------
//プチテストファイルを開く関数
//-------------------------------------------------------------------------------------------------------------
void Open_File_P_Max( st_kojiku *kojiku ){

	//変数宣言---------------------------------------------------------------------------------------
	char	posit_num_pm[256];	//パスと番号をくっつけた文字列

	//入力フォルダパスとファイル番号をくっつけた文字列を作成--------------------------------------------
	sprintf( posit_num_pm, "%s/%03d_p_max.txt",
		kojiku->file.posit.p_max, kojiku->file.num.p_max );

	//ファイルをテキストモードでオープン---------------------------------------------------------------
	if(  ( kojiku->file.fp.p_max = fopen(posit_num_pm, "r") ) == NULL  ){
		printf( "「%03d_p_max.txt」は存在しません。\n",
			kojiku->file.num.p_max );
	}
}


//-------------------------------------------------------------------------------------------------------------
//入力ファイルを開く関数
//-------------------------------------------------------------------------------------------------------------
void Open_File_In( st_kojiku *kojiku ){

	//変数宣言---------------------------------------------------------------------------------------
	char	posit_num_in[256];		//入力ファイルのパスと番号をくっつけた文字列

	//入力フォルダパスとファイル番号をくっつけた文字列を作成--------------------------------------------
	sprintf( posit_num_in, "%s%03d.DAT", kojiku->file.posit.in, kojiku->file.num.data );

	//ファイルをバイナリモードでオープン---------------------------------------------------------------
	if(  ( kojiku->file.fp.in = fopen(posit_num_in, "rb") ) == NULL  ){
		printf("\t「%03d.DAT」は存在しません。\n", kojiku->file.num.data);
		exit(1);
	}
}


//-------------------------------------------------------------------------------------------------------------
//出力ファイルを開く関数
//-------------------------------------------------------------------------------------------------------------
void Open_File_Out( FILE **fp, char *posit_num_dir, char name[256] ,unsigned int data){

	//変数宣言---------------------------------------------------------------------------------------
	char	posit_num_out[256];				//出力ファイルのパスと番号をくっつけた文字列
	//--------------------------------------------
	sprintf(posit_num_out, "%s/%03d%s", posit_num_dir,data, name );

	//ファイルをテキストモードでオープン---------------------------------------------------------------
	*fp = fopen(posit_num_out, "w");
}


// Random関数定義

int Random(void){
	int rnd;
	static int flag = 0;
	if(flag==0){
		srand(time(NULL));	// 乱数の初期化
		flag++;
		rnd = rand();
	}else {
		rnd = rand();		// 乱数の取得
	}
	return rnd;
}

//ランダム出力と確認圧力
void FUJITAvoid( st_kojiku *kojiku ){
	FILE *ff;
	char string[100];
	int rnd;

	rnd = Random()%100;


	sprintf(string,"%s/%03d.txt",kojiku->file.posit_num_dir,kojiku->file.num.data);


	ff = fopen(string,"w");

	if(rnd<14){
		fprintf(ff,"\n　　　　　　　　 　 ★\n　　　　　　　　 　 │\n　　　　　　　　γ ⌒ヽ　　　 　／￣￣￣￣￣￣￣\n　　　　　　　　i　・∀・ｉ　　＜　愛、忘れてませんか？\n　　　　　　 ／i　　　　ｉ＼　　＼＿＿＿＿＿＿＿\n　　　　　⊂／ｉ　　★ ｉ＼つ\n　　　　　　 　 ゝ　　 /\n　　　　　　～/　　　 ＼\n　　　　　　　/　 /~＼　＼\n　　　　　　 /　 /　　　>　 ）\n　　　　　／　ノ　 　 /　／\n　　　　/　／ 　 .　 / ./\n　　　 / ./　　　　 （　ヽ､\n　　 （＿_)　　　　　 ＼__つ\n\n");
	}else if(rnd >= 14 && rnd < 35){
		fprintf(ff,"　　　| ＼\n　　　|Д｀)　ﾀﾞﾚﾓｲﾅｲ･･ ｲﾏﾉｳﾁ\n　　　|⊂\n　　　|\n\n\n　　　　　♪　　Å\n　　　♪　　　／ ＼　　　ｵﾋﾙﾔｽﾐﾊ\n　　　　　　ヽ(´Д｀;)ﾉ 　　ｳｷｳｷｳｫｯﾁﾝｸﾞ\n　　 　 　　　 (　 へ) 　　　\n　 　 　 　 　　く 　　　　　　\n\n\n\n　　　♪　　　　Å\n　　　　　♪　／ ＼　　　ｱｯﾁｺｯﾁ\n　　　　　　ヽ（;´Д｀）ﾉ　　ｿｯﾁｺｯﾁ\n　　 　 　　　 (へ　 ) 　　　ｲｲｰﾄｰﾓｰ\n　 　 　 　 　　　　 >　　　　\n						\n\n");
	}else if(rnd >= 35 && rnd <49 ){
		fprintf(ff,"\n　　　　　 ★\n　　　　　　|\n　 　 　γ ⌒ヽ 　 　 ／￣￣￣￣￣￣￣\n　　　　i　・∀・i 　＜　愛、忘れてませんか？\n　　　　i ⊃★ i) 　　 ＼＿＿＿＿＿＿＿\n　　　　ゝ　 　〈\n　　 　（＿_）＿）\n\n");
	}else if(rnd >= 49 && rnd <50 ){
		fprintf(ff,"　　　 ＿＿＿＿＿＿＿＿＿＿___\n　　　／|：： ┌──────┐ ：：|\n　　/.　 |：： ｜ 　　　　　　　　 ｜ ：：|\n　　|....　|：： ｜　　　　　　　　　｜ ：：|\n　　|....　|：： ｜　　　　　　　　　｜ ：：|\n　　|....　|：： └──────┘ ：：|\n　　＼_｜　　　 ┌────┐　　 .|　　　　 ∧∧\n　　　　 ￣￣￣￣￣￣￣￣￣￣￣　　 　 ( 　＿)　　　　俺がデータ整理をしないことで\n　　　　　　　　　　　　　／￣￣￣￣￣旦￣(_,　　 ）\n　　　　　　　　　　　 ／　　　　　　　　　　　　　＼ 　｀\n　　　　　　　　　　　|￣￣￣￣￣￣￣￣￣￣￣|、＿）\n　　　　　　　　　　　 ￣|￣|￣￣￣￣￣￣|￣|￣\n\n　　　　　|　　　　　　　　　　 .( (　|　|＼\n　　　　　| )　　　　　　　　　 　) ) |　|　.|\n　　　　　|＿＿＿＿＿＿＿＿(__|　.＼|　　　　　　　　俺の代わりにだれか一人、データ整理ができる\n　　　 ／― 　　∧ ∧　　――-＼≒\n　　／　　　 　 ( 　　　)　　　　　　　＼\n　　|￣￣￣￣￣￣￣￣￣￣￣￣￣ |\n　　|＿＿＿＿＿＿＿＿＿＿＿＿＿_|\n\n　　　∧∧\n　　（　 ･ω･）\n　 ＿|　⊃／(＿＿_\n／　└-(＿＿＿_／\n￣￣￣￣￣￣￣\n　　　　　　　　　　　　　　　　　　　　　　　　　　　 　俺はそういうことに幸せを感じるんだ\n　 ＜⌒／ヽ-、_＿_\n／＜_/＿＿＿＿／\n\n");
	}else if(rnd >= 50 && rnd <55){
		fprintf(ff,"　　／⌒ヽ\n　 ∩ ＾ω＾）　うはｗｗｗ\n　 |　　 ⊂ﾉ\n　｜　　 _⊃\n　 し ⌒\n\n　　／⌒ヽ\n　（＾ω＾ ∩　うはｗｗｗ\n　 t⊃　　｜\n　⊂_ 　　｜\n　　　⌒ J\n\n");
	}else if(rnd >= 55 && rnd <75){
		fprintf(ff,"　　　 ＿＿＿\n　 　／　　　　＼　　_....－⌒ー―、\n　　.|　^　　　^　|　｢　 　／　　　　　＼　　　あまり私を\n　　| .>ﾉ(､_, )ヽ､.|ノ ´／―、＿　　　　ヽ　イナバウアーさせない方がいい\n　 　! ! -=ﾆ=-　ﾉ　∥　／／　ーｒ　　｜　　\n　　　＼｀ﾆﾆ´／ 　人　´｜　　/　　　　|\n　　　　`'ｰ_--ｙ‐ '''　 |、　|　　〈　　　　　|＼　\n　　　　＝-u´　　　　./　｜　　ヽ　　　　　　＼\n　　　　　　　　　_　　/　／　　　|　　　人　　　＼\n　　　　　　　　　＝￣ノ　　　　/　　　/　.＼　　　＼\n　　　　　　　　　￣￣　　　　/　　　/　　　　＼　　｜\n　　　　　　　　　　　　　　　/　　　/　　　　　　/　　|\n　　　　　　　　　　　　　／￣　／　　　　　　　|　　｜　\n　　　　　　　　　　　　／　　／　　　　　　　　　|　　|　\n　　　　　　　　　　　／　／　　　　　　　　　　　｜　|　\n　　　　　　　　　　ゝ　　|　　　　　　　　　　　　　/＿ﾕ\n　　　　　　　　　/＼　/　　　　　　　　　　　　　　|＿|\n　　　　　　　　ヽ　／　　　　　　　　　　　　　　　　∥　\n　　　　　　　　//　　　　　　　　　　　 \n\n");
	}else if(rnd >= 75 && rnd <85){
		fprintf(ff,"　　 ／￣＼\n　　| 　＾o＾　|　＜ コーラ　おいしい　です\n　　 ＼_[]⊂／）\n　　 ＿|　|/　｜\n　　|　　　　／　\n　　　　　　　　 ／￣＼\n　　　　　　　　|　　　　 |　＜ それは　しょうゆ　です\n\n　　　　　　　　 ＼＿／\n　　　　　　　　 ＿|　|＿\n　　　　　　　　|　　　　　|\n\n");
	}else if(rnd >=85 && rnd <90){
		fprintf(ff,"　　　 ／￣＼\n　　　| 　^o^　|　＜ わたしです\n　　　 ＼＿／　　　\n　　　 ＿|　|＿\n　　　|　　　　　|\n\n\n");
	}else{
		fprintf(ff,"　 　／￣＼\n　　| 　^o^　|　＜犯人は　この中に　いる\n　　 ＼＿／　　　\n　　 ＿|　|＿\n　　|　　　　　|\n\n　　　　　　　　 ／￣＼\n　　　　　　　　|　　　　 |　＜わかりません\n　　　　　　　　 ＼＿／\n　　　　　　　　 ＿|　|＿\n　　　　　　　　|　　　　　|\n\n　 　／￣＼\n　　| 　^o^　|　＜わたしです\n　　 ＼＿／　　　\n　　 ＿|　|＿\n　　|　　　　　|\n\n　　　　　　　　 ／￣＼\n　　　　　　　　|　　　　 |　\n　　　　　　　　 ＼＿／\n　　　　　　　　 ＿|　|＿\n　　　　　　　　|　　　　　| \n");
	}

	//かけたイニシャルの確認
	fprintf(ff,"私がかけたイニシャルは%diと%diです.\n",kojiku->file.num.init1,kojiku->file.num.init2);
	fprintf(ff,"私がかけたP-maxは%diです.\n",kojiku->file.num.p_max);
	fprintf(ff,"温度は%3.1fと%3.1fです.\n",kojiku->atm.T_init,kojiku->atm.T_end);
	fprintf(ff,"大気圧は%4.1fと%4.1fです.\n",kojiku->atm.P_init,kojiku->atm.P_end);
	fprintf(ff,"私は%lfと%lf以上の周波数をカットしました.\n",kojiku->freq.cut1,kojiku->freq.cut2);
	//ﾃﾞｰﾀ番号.txtファイルに圧力計の感度を出力する

	fprintf(ff,"	1A:%10.9f\n", kojiku->sens.wp1A);
	fprintf(ff,"	1C:%10.9f\n", kojiku->sens.wp1C);
	fprintf(ff,"	1E:%10.9f\n", kojiku->sens.wp1E);
	fprintf(ff,"	2A:%10.9f\n", kojiku->sens.wp2A);
	fprintf(ff,"	2C:%10.9f\n", kojiku->sens.wp2C);
	fprintf(ff,"	2E:%10.9f\n", kojiku->sens.wp2E);
	fprintf(ff,"	3A:%10.9f\n", kojiku->sens.wp3A);
	fprintf(ff,"	3C:%10.9f\n", kojiku->sens.wp3C);
	fprintf(ff,"	3E:%10.9f\n", kojiku->sens.wp3E);
	fprintf(ff,"	pspr:%10.9f\n", kojiku->sens.pspr);

	fprintf(ff,"	sens.hwi.__6	:%8.5f\n",	kojiku->sens.hwi.__6	);
	fprintf(ff,"	sens.hwi.__5	:%8.5f\n",	kojiku->sens.hwi.__5	);
	fprintf(ff,"	sens.hwi.__4	:%8.5f\n",	kojiku->sens.hwi.__4	);
	fprintf(ff,"	sens.hwi.__3	:%8.5f\n",	kojiku->sens.hwi.__3	);
	fprintf(ff,"	sens.hwi.__2	:%8.5f\n",	kojiku->sens.hwi.__2	);
	fprintf(ff,"	sens.hwi.__1	:%8.5f\n",	kojiku->sens.hwi.__1	);
	fprintf(ff,"	sens.hwi.__0	:%8.5f\n",	kojiku->sens.hwi.__0	);
	fprintf(ff,"	sens.hwi2.__6	:%8.5f\n",	kojiku->sens.hwi2.__6	);
	fprintf(ff,"	sens.hwi2.__5	:%8.5f\n",	kojiku->sens.hwi2.__5	);
	fprintf(ff,"	sens.hwi2.__4	:%8.5f\n",	kojiku->sens.hwi2.__4	);
	fprintf(ff,"	sens.hwi2.__3	:%8.5f\n",	kojiku->sens.hwi2.__3	);
	fprintf(ff,"	sens.hwi2.__2	:%8.5f\n",	kojiku->sens.hwi2.__2	);
	fprintf(ff,"	sens.hwi2.__1	:%8.5f\n",	kojiku->sens.hwi2.__1	);
	fprintf(ff,"	sens.hwi2.__0	:%8.5f\n",	kojiku->sens.hwi2.__0	);
	fprintf(ff,"	sens.hwi3.__6	:%8.5f\n",	kojiku->sens.hwi3.__6	);
	fprintf(ff,"	sens.hwi3.__5	:%8.5f\n",	kojiku->sens.hwi3.__5	);
	fprintf(ff,"	sens.hwi3.__4	:%8.5f\n",	kojiku->sens.hwi3.__4	);
	fprintf(ff,"	sens.hwi3.__3	:%8.5f\n",	kojiku->sens.hwi3.__3	);
	fprintf(ff,"	sens.hwi3.__2	:%8.5f\n",	kojiku->sens.hwi3.__2	);
	fprintf(ff,"	sens.hwi3.__1	:%8.5f\n",	kojiku->sens.hwi3.__1	);
	fprintf(ff,"	sens.hwi3.__0	:%8.5f\n",	kojiku->sens.hwi3.__0	);

	fprintf(ff,"	sens.hwsp1.A	:%8.5f\n",	kojiku->sens.hwsp1.A	);
	fprintf(ff,"	sens.hwsp1.B	:%8.5f\n",	kojiku->sens.hwsp1.B	);
	fprintf(ff,"	sens.hwsp1.n	:%8.5f\n",	kojiku->sens.hwsp1.n	);
	fprintf(ff,"	sens.hwsp1.K1	:%8.5f\n",	kojiku->sens.hwsp1.K1	);
	fprintf(ff,"	sens.hwsp1.V1	:%8.5f\n",	kojiku->sens.hwsp1.V1	);
	fprintf(ff,"	sens.hwsp1.K2	:%8.5f\n",	kojiku->sens.hwsp1.K2	);
	fprintf(ff,"	sens.hwsp1.V2	:%8.5f\n",	kojiku->sens.hwsp1.V2	);

	fprintf(ff,"	sens.hwsp2.A	:%8.5f\n",	kojiku->sens.hwsp2.A	);
	fprintf(ff,"	sens.hwsp2.B	:%8.5f\n",	kojiku->sens.hwsp2.B	);
	fprintf(ff,"	sens.hwsp2.n	:%8.5f\n",	kojiku->sens.hwsp2.n	);
	fprintf(ff,"	sens.hwsp2.K1	:%8.5f\n",	kojiku->sens.hwsp2.K1	);
	fprintf(ff,"	sens.hwsp2.V1	:%8.5f\n",	kojiku->sens.hwsp2.V1	);
	fprintf(ff,"	sens.hwsp2.K2	:%8.5f\n",	kojiku->sens.hwsp2.K2	);
	fprintf(ff,"	sens.hwsp2.V2	:%8.5f\n",	kojiku->sens.hwsp2.V2	);

	fprintf(ff,"	sens.kousei.__2	:%6.5f\n",	kojiku->sens.kousei.__2	);
	fprintf(ff,"	sens.kousei.__1	:%6.5f\n",	kojiku->sens.kousei.__1	);
	fprintf(ff,"	sens.kousei.__0	:%6.5f\n",	kojiku->sens.kousei.__0	);

	fprintf(ff,"	freq.cut1	:%3.2f\n",	kojiku->freq.cut1	);
	fprintf(ff,"	freq.cut2	:%3.2f\n",	kojiku->freq.cut2	);
	fprintf(ff,"	freq.cut3	:%3.2f\n",	kojiku->freq.cut3	);
	fprintf(ff,"	freq.cut4	:%3.2f\n",	kojiku->freq.cut4	);


	fclose(ff);
	//printf("fujitasan%lf\n",kojiku->sens.kousei.P_1);
}

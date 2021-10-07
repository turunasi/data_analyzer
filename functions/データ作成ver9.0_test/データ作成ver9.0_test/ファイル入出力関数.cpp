//*************************************************************************************************************
//ファイルへの入出力に関する関数
//*************************************************************************************************************

#pragma warning( disable: 4996 )       // コード先頭に記載

#include	<stdio.h>
#include	"定数・構造体定義.h"	//自作ヘッダファイル
#include	"自作関数定義.h"	//自作ヘッダファイル


//-------------------------------------------------------------------------------------------------------------
//イニシャルを読み込む関数
//-------------------------------------------------------------------------------------------------------------
void Read_File_Init( st_kojiku *kojiku ){

	//イニシャル読み込み------------------------------------------------------------------------------
	fscanf( kojiku->file.fp.init,
			"%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",
			&(kojiku->init.wp1A),
			&(kojiku->init.wp1C),
			&(kojiku->init.wp1E),
			&(kojiku->init.wp2A),
			&(kojiku->init.wp2C),
			&(kojiku->init.wp2E),
			&(kojiku->init.wp3A),
			&(kojiku->init.wp3C),
			&(kojiku->init.wp3E),
			&(kojiku->init.pspr)
	);
	//printf("readinit%lf\n",kojiku->sens.kousei.P_1);
}

//-------------------------------------------------------------------------------------------------------------
//プチテストファイルを読み込む関数
//-------------------------------------------------------------------------------------------------------------

void Read_P_Max_File( st_kojiku *kojiku ){

	//プチテストファイル読み込み----------------------------------------------------------------------
	fscanf( kojiku->file.fp.p_max,
			"%lf %lf %lf %lf %lf",
			&(kojiku->p_max.p_ave),
			&(kojiku->p_max.v_ave),
			&(kojiku->p_max.DA1),
			&(kojiku->p_max.DA2),
			&(kojiku->p_max.DA3)
			);
 //printf("readP_max%lf\n",kojiku->sens.kousei.P_1);
}

//-------------------------------------------------------------------------------------------------------------
//ファイルからデータを読み込む関数　ついでに行数も勘定
//-------------------------------------------------------------------------------------------------------------
void Read_File_Data( st_kojiku *kojiku ){

	//変数宣言---------------------------------------------------------------------------------------
	unsigned int	i;	//行カウンタ
	unsigned int	j;	//列カウンタ

	//読み込み----------------------------------------------------------------------------------------
	kojiku->line.line = 0;

	for( i=0; ; i++ ){

		for( j=0; j<J; j++ ){
			fread(	&kojiku->data.data_u[j][i],
					2,
					1,
					kojiku->file.fp.in
			);
		}

		//printf("i = %d\n",i);

		if( feof( kojiku->file.fp.in ) != 0 ){
			break;
		}else{
		( kojiku->line.line )++;
			/*if((kojiku->line.line)%10000 == 0){
				printf("%d", kojiku->line.line);
				printf("\n");
			}*/
		}
	}
	//printf("Readfile%lf\n",kojiku->sens.kousei.P_1);
}

//-------------------------------------------------------------------------------------------------------------
//ファイルに書き込む関数（1列）
//-------------------------------------------------------------------------------------------------------------
void Write_1(	FILE			*fp,
				double			*data,
				unsigned int	ii){

	//変数宣言---------------------------------------------------------------------------------------
	double	*p;

	//書き込み---------------------------------------------------------------------------------------
	for( p=data; p<data+ii; p++ ){
		fprintf( fp, "%+5.8E\n", *p );
	}
}


//-------------------------------------------------------------------------------------------------------------
//ファイルに書き込む関数（2列）
//-------------------------------------------------------------------------------------------------------------
void Write_2(	FILE			*fp,
				double			*data_0,
				double			*data_1,
				unsigned int	ii){

	//変数宣言---------------------------------------------------------------------------------------
	double	*p1;
	double	*p2;

	//書き込み---------------------------------------------------------------------------------------
	for(	p1 = data_0,
			p2 = data_1;
			p1 < data_0 + ii,
			p2 < data_1 + ii;
			p1++,
			p2++ ){
		fprintf( fp, "%+5.8E\t%+5.8E\n", *p1, *p2 );
	}
}


//-------------------------------------------------------------------------------------------------------------
//ファイルに書き込む関数
//-------------------------------------------------------------------------------------------------------------
void Write_RawData( st_kojiku *kojiku ){

	//書き込み---------------------------------------------------------------------------------------

	if(kojiku->check.check_rawdata01_1A==1){	
	printf("\t\t動翼前縁壁圧　1A");
	Write_1(	kojiku->file.fp.wp1A.rawdata,
				kojiku->data.wp1A.real,
				kojiku->line.newline
	);
	}
	if(kojiku->check.check_rawdata02_1C==1){
	printf("、1C");
	Write_1(	kojiku->file.fp.wp1C.rawdata,
				kojiku->data.wp1C.real,
				kojiku->line.newline
	);
	}
	if(kojiku->check.check_rawdata03_1E==1){
	printf("、1ACF");
	Write_1(	kojiku->file.fp.wp1E.rawdata,
				kojiku->data.wp1E.real,
				kojiku->line.newline
	);
	}
	if(kojiku->check.check_rawdata04_2A==1){
	printf("、2A");
	Write_1(	kojiku->file.fp.wp2A.rawdata,
				kojiku->data.wp2A.real,
				kojiku->line.newline
	);
	}
	if(kojiku->check.check_rawdata05_2C==1){
	printf("、2C");
	Write_1(	kojiku->file.fp.wp2C.rawdata,
				kojiku->data.wp2C.real,
				kojiku->line.newline
	);
	}
	if(kojiku->check.check_rawdata06_2E==1){
	printf("、2ACF");
	Write_1(	kojiku->file.fp.wp2E.rawdata,
				kojiku->data.wp2E.real,
				kojiku->line.newline
	);
	}
	if(kojiku->check.check_rawdata07_3A==1){
	printf("、3A");
	Write_1(	kojiku->file.fp.wp3A.rawdata,
				kojiku->data.wp3A.real,
				kojiku->line.newline
	);
	}
	if(kojiku->check.check_rawdata08_3C==1){
	printf("、3C");
	Write_1(	kojiku->file.fp.wp3C.rawdata,
				kojiku->data.wp3C.real,
				kojiku->line.newline
	);
	}
	if(kojiku->check.check_rawdata09_3E==1){
	printf("、3ACF");
	Write_1(	kojiku->file.fp.wp3E.rawdata,
				kojiku->data.wp3E.real,
				kojiku->line.newline
	);
	}
	printf("\n");
	if(kojiku->check.check_rawdata10_pspr==1){
	printf("\t\t性能静圧上昇\n");
	Write_1(	kojiku->file.fp.pspr.rawdata,
				kojiku->data.pspr.real,
				kojiku->line.newline
	);
	}
	if(kojiku->check.check_rawdata11_hwi==1){
	printf("\t\t流速（I型熱線）\n");
	Write_1(	kojiku->file.fp.hwi.rawdata,
				kojiku->data.hwi.real,
				kojiku->line.newline
	);
	}
	if(kojiku->check.check_rawdata12_ptpr==1){
	printf("\t\t性能全圧上昇\n");
	Write_1(	kojiku->file.fp.ptpr.rawdata,
				kojiku->data.ptpr.real,
				kojiku->line.newline
	);
	}
	if(kojiku->check.check_rawdata13_averv==1){
	printf("\t\t圧縮機内平均軸流速\n");
	Write_1(	kojiku->file.fp.averv.rawdata,
				kojiku->data.averv.real,
				kojiku->line.newline
	);
	}
	if(kojiku->check.check_rawdata14_psi==1){
	printf("\t\t全圧上昇係数\n");
	Write_1(	kojiku->file.fp.psi.rawdata,
				kojiku->data.psi.real,
				kojiku->line.newline
	);
	}
	if(kojiku->check.check_rawdata13_spsi==1){
	printf("\t\t静圧上昇係数\n");
	Write_1(	kojiku->file.fp.psi_s.rawdata,
				kojiku->data.psi_s.real,
				kojiku->line.newline
	);
	}
	if(kojiku->check.check_rawdata15_phi==1){
	printf("\t\t流量係数\n");
	Write_1(	kojiku->file.fp.phi.rawdata,
				kojiku->data.phi.real,
				kojiku->line.newline
	);
	}
	if(kojiku->check.check_rawdata18_hwi2==1){
	printf("\t\t内部流れ（I型熱線）\n");
	Write_1(	kojiku->file.fp.hwi2.rawdata,
				kojiku->data.hwi2.real,
				kojiku->line.newline
	);
	}
	if(kojiku->check.check_rawdata18_hwi2==1){
	printf("\t\t内部流れ（無次元）\n");
	Write_1(	kojiku->file.fp.phi2.rawdata,
				kojiku->data.phi2.real,
				kojiku->line.newline
	);
	}
	if (kojiku->check.check_rawdata25_hwi3 == 1){
	printf("\t\t内部流れ2（I型熱線）\n");
	Write_1(	kojiku->file.fp.hwi3.rawdata,
				kojiku->data.hwi3.real,
				kojiku->line.newline
	);
	}
	if (kojiku->check.check_rawdata25_hwi3 == 1){
	printf("\t\t内部流れ2（無次元）\n");
	Write_1(	kojiku->file.fp.phi3.rawdata,
				kojiku->data.phi3.real,
				kojiku->line.newline
	);
	}
	if(kojiku->check.check_rawdata20_phi_psi==1){
	printf("\t\tψ-φ\n");
	Write_2(	kojiku->file.fp.phi_psi.rawdata,
				kojiku->data.phi.real, 
				kojiku->data.psi.real, 
				kojiku->line.newline
	);
	}
	if(kojiku->check.check_rawdata16_phi_spsi==1){
	printf("\t\tψs-φ\n");
	Write_2(	kojiku->file.fp.phi_psi_s.rawdata,
				kojiku->data.phi.real, 
				kojiku->data.psi_s.real, 
				kojiku->line.newline
	);
	}

	if(kojiku->check.check_rawdata22_valve==1){
	printf("\t\tValve......\n");
	Write_1(	kojiku->file.fp.valve.rawdata,
				kojiku->data.valve.real,
				kojiku->line.newline
	);
	}

	if (kojiku->check.check_rawdata27_plunge == 1) {
		printf("\t\tPlunge......\n");
		Write_1(kojiku->file.fp.plunge.rawdata,
			kojiku->data.plunge.real,
			kojiku->line.newline
			);
	}

	if (kojiku->check.check_rawdata31_hwsp1_v == 1) {
		printf("\t\tHwsp1_v......\n");
		Write_1(kojiku->file.fp.hwsp1_v.rawdata,
			kojiku->data.hwsp1_v.real,
			kojiku->line.newline
			);
	}

	if (kojiku->check.check_rawdata32_hwsp1_alpha == 1) {
		printf("\t\tHwsp1_alpha......\n");
		Write_1(kojiku->file.fp.hwsp1_alpha.rawdata,
			kojiku->data.hwsp1_alpha.real,
			kojiku->line.newline
			);
	}

	if (kojiku->check.check_rawdata33_hwsp1_vaxis == 1) {
		printf("\t\tHwsp1_vaxis......\n");
		Write_1(kojiku->file.fp.hwsp1_vaxis.rawdata,
			kojiku->data.hwsp1_vaxis.real,
			kojiku->line.newline
			);
	}

	if (kojiku->check.check_rawdata34_hwsp1_vcir == 1) {
		printf("\t\tHwsp1_vcir......\n");
		Write_1(kojiku->file.fp.hwsp1_vcir.rawdata,
			kojiku->data.hwsp1_vcir.real,
			kojiku->line.newline
			);
	}

	
	if (kojiku->check.check_rawdata35_ndvaxis1 == 1) {
		printf("\t\tHwsp1_ndvaxis......\n");
		Write_1(kojiku->file.fp.hwsp1_ndvaxis.rawdata,
			kojiku->data.hwsp1_ndvaxis.real,
			kojiku->line.newline
			);
	}

	if (kojiku->check.check_rawdata36_ndvcir1 == 1) {
		printf("\t\tHwsp1_ndvcir......\n");
		Write_1(kojiku->file.fp.hwsp1_ndvcir.rawdata,
			kojiku->data.hwsp1_ndvcir.real,
			kojiku->line.newline
			);
	}

	if (kojiku->check.check_rawdata37_2daverv1 == 1) {
		printf("\t\tHwsp1_2daverv......\n");
		Write_1(kojiku->file.fp.hwsp1_twod_averv.rawdata,
			kojiku->data.hwsp1_twod_averv.real,
			kojiku->line.newline
			);
	}

	if (kojiku->check.check_rawdata38_2dphi1 == 1) {
		printf("\t\tHwsp1_2dphi......\n");
		Write_1(kojiku->file.fp.hwsp1_twod_phi.rawdata,
			kojiku->data.hwsp1_twod_phi.real,
			kojiku->line.newline
			);
	}

	if(kojiku->check.check_rawdata39_2dphi_psi1 ==1){
	printf("\t\tHwsp1_2dphi_psi......\n");
	Write_2(	kojiku->file.fp.hwsp1_twod_phi_psi.rawdata,
		kojiku->data.hwsp1_twod_phi.real, 
				kojiku->data.psi.real, 
				kojiku->line.newline
	);
	}

	if (kojiku->check.check_rawdata41_hwsp2_v == 1) {
		printf("\t\tHwsp2_v......\n");
		Write_1(kojiku->file.fp.hwsp2_v.rawdata,
			kojiku->data.hwsp2_v.real,
			kojiku->line.newline
			);
	}

	if (kojiku->check.check_rawdata42_hwsp2_alpha == 1) {
		printf("\t\tHwsp2_alpha......\n");
		Write_1(kojiku->file.fp.hwsp2_alpha.rawdata,
			kojiku->data.hwsp2_alpha.real,
			kojiku->line.newline
			);
	}

	if (kojiku->check.check_rawdata43_hwsp2_vaxis == 1) {
		printf("\t\thwsp2_vaxis......\n");
		Write_1(kojiku->file.fp.hwsp2_vaxis.rawdata,
			kojiku->data.hwsp2_vaxis.real,
			kojiku->line.newline
			);
	}

	if (kojiku->check.check_rawdata44_hwsp2_vcir == 1) {
		printf("\t\thwsp2_vcir......\n");
		Write_1(kojiku->file.fp.hwsp2_vcir.rawdata,
			kojiku->data.hwsp2_vcir.real,
			kojiku->line.newline
			);
	}

	
	if (kojiku->check.check_rawdata45_ndvaxis2 == 1) {
		printf("\t\thwsp2_ndvaxis......\n");
		Write_1(kojiku->file.fp.hwsp2_ndvaxis.rawdata,
			kojiku->data.hwsp2_ndvaxis.real,
			kojiku->line.newline
			);
	}

	if (kojiku->check.check_rawdata46_ndvcir2 == 1) {
		printf("\t\thwsp2_ndvcir......\n");
		Write_1(kojiku->file.fp.hwsp2_ndvcir.rawdata,
			kojiku->data.hwsp2_ndvcir.real,
			kojiku->line.newline
			);
	}

	if (kojiku->check.check_rawdata47_2daverv2 == 1) {
		printf("\t\thwsp2_2daverv......\n");
		Write_1(kojiku->file.fp.hwsp2_twod_averv.rawdata,
			kojiku->data.hwsp2_twod_averv.real,
			kojiku->line.newline
			);
	}

	if (kojiku->check.check_rawdata48_2dphi2 == 1) {
		printf("\t\thwsp2_2dphi......\n");
		Write_1(kojiku->file.fp.hwsp2_twod_phi.rawdata,
			kojiku->data.hwsp2_twod_phi.real,
			kojiku->line.newline
			);
	}

	if(kojiku->check.check_rawdata49_2dphi_psi2 ==1){
	printf("\t\thwsp2_2dphi_psi......\n");
	Write_2(	kojiku->file.fp.hwsp2_twod_phi_psi.rawdata,
		kojiku->data.hwsp2_twod_phi.real, 
				kojiku->data.psi.real, 
				kojiku->line.newline
	);
	}

	printf("\n");
	if(kojiku->check.check_rawdata51_ptank==1){
	printf("\t\tタンク入り口静圧上昇\n");
	Write_1(	kojiku->file.fp.ptank.rawdata,
				kojiku->data.ptank.real,
				kojiku->line.newline
	);
	}
	if(kojiku->check.check_rawdata52_ptank_psi==1){
	printf("\t\tタンク入り口静圧上昇係数\n");
	Write_1(	kojiku->file.fp.ptank_psi.rawdata,
				kojiku->data.ptank_psi.real,
				kojiku->line.newline
	);
	}

}


//-------------------------------------------------------------------------------------------------------------
//FFT振幅スペクトルをファイルに書き込む関数
//-------------------------------------------------------------------------------------------------------------
void Write_AmpSpec( st_kojiku *kojiku ){

	//書き込み---------------------------------------------------------------------------------------
	if(kojiku->check.check_FFTampspec01_1A==1){
	printf("\t\t動翼前縁壁圧　1A");
	Write_2(	kojiku->file.fp.wp1A.ampspec,
				kojiku->freq.axis_ampspec, 
				kojiku->data.wp1A.abs,
				kojiku->line.ampspec
	);
	}
	if(kojiku->check.check_FFTampspec04_2A==1){
	printf("、2A");
	Write_2(	kojiku->file.fp.wp2A.ampspec,
				kojiku->freq.axis_ampspec, 
				kojiku->data.wp2A.abs,
				kojiku->line.ampspec
	);
	}
	if(kojiku->check.check_FFTampspec07_3A==1){
	printf("、3A\n");
	Write_2(	kojiku->file.fp.wp3A.ampspec,
				kojiku->freq.axis_ampspec, 
				kojiku->data.wp3A.abs,
				kojiku->line.ampspec
	);
	}
	if(kojiku->check.check_FFTampspec11_hwi==1){
	printf("\t\t流速（I型熱線）\n");
	Write_2(	kojiku->file.fp.hwi.ampspec,
				kojiku->freq.axis_ampspec, 
				kojiku->data.hwi.abs,
				kojiku->line.ampspec
	);
	}
	if(kojiku->check.check_FFTampspec12_ptpr==1){
	printf("\t\t性能全圧上昇\n");
	Write_2(	kojiku->file.fp.ptpr.ampspec,
				kojiku->freq.axis_ampspec, 
				kojiku->data.ptpr.abs,
				kojiku->line.ampspec
	);
	}
	if(kojiku->check.check_FFTampspec18_hwi2==1){
	printf("\t\t内部流れ（I型熱線）\n");
	Write_2(	kojiku->file.fp.hwi2.ampspec,
				kojiku->freq.axis_ampspec, 
				kojiku->data.hwi2.abs,
				kojiku->line.ampspec
	);
	}
	if (kojiku->check.check_FFTampspec25_hwi3 == 1){
	printf("\t\t内部流れ2（I型熱線）\n");
	Write_2(	kojiku->file.fp.hwi3.ampspec,
				kojiku->freq.axis_ampspec,
				kojiku->data.hwi3.abs,
				kojiku->line.ampspec
	);
	}

	if (kojiku->check.check_FFTampspec33_hwsp1_vaxis == 1){
	printf("\t\thwsp1_vaxis......\n");
	Write_2(	kojiku->file.fp.hwsp1_vaxis.ampspec,
				kojiku->freq.axis_ampspec,
				kojiku->data.hwsp1_vaxis.abs,
				kojiku->line.ampspec
	);
	}

	if (kojiku->check.check_FFTampspec34_hwsp1_vcir == 1){
	printf("\t\thwsp1_vcir......\n");
	Write_2(	kojiku->file.fp.hwsp2_vcir.ampspec,
				kojiku->freq.axis_ampspec,
				kojiku->data.hwsp2_vcir.abs,
				kojiku->line.ampspec
	);
	}

	if (kojiku->check.check_FFTampspec43_hwsp2_vaxis == 1){
	printf("\t\thwsp2_vaxis......\n");
	Write_2(	kojiku->file.fp.hwsp2_vaxis.ampspec,
				kojiku->freq.axis_ampspec,
				kojiku->data.hwsp2_vaxis.abs,
				kojiku->line.ampspec
	);
	}

	if (kojiku->check.check_FFTampspec44_hwsp2_vcir == 1){
	printf("\t\thwsp2_vcir......\n");
	Write_2(	kojiku->file.fp.hwsp2_vcir.ampspec,
				kojiku->freq.axis_ampspec,
				kojiku->data.hwsp2_vcir.abs,
				kojiku->line.ampspec
	);
	}

}

//-------------------------------------------------------------------------------------------------------------
//ファイルにフィルタ結果を書き込む関数
//-------------------------------------------------------------------------------------------------------------
void Write_Filter( st_kojiku *kojiku ){

	if(kojiku->check.check_filter01_1A==1){
	printf("\t\t動翼前縁壁圧　1A");
	Write_1(	kojiku->file.fp.wp1A.filter,
				kojiku->data.wp1A.real,
				kojiku->line.newline
	);
	}
	if(kojiku->check.check_filter02_1C==1){
	printf("、1D");
	Write_1(	kojiku->file.fp.wp1C.filter,
				kojiku->data.wp1C.real,
				kojiku->line.newline
	);
	}
	if(kojiku->check.check_filter03_1E==1){
	printf("、1E");
	Write_1(	kojiku->file.fp.wp1E.filter,
				kojiku->data.wp1E.real,
				kojiku->line.newline
	);
	}
	if(kojiku->check.check_filter04_2A==1){
	printf("、2A");
	Write_1(	kojiku->file.fp.wp2A.filter,
				kojiku->data.wp2A.real,
				kojiku->line.newline
	);
	}
	if(kojiku->check.check_filter05_2C==1){
	printf("、2D");
	Write_1(	kojiku->file.fp.wp2C.filter,
				kojiku->data.wp2C.real,
				kojiku->line.newline
	);
	}
	if(kojiku->check.check_filter06_2E==1){
	printf("、2E");
	Write_1(	kojiku->file.fp.wp2E.filter,
				kojiku->data.wp2E.real,	
				kojiku->line.newline
	);
	}
	if(kojiku->check.check_filter07_3A==1){
	printf("、3A");
	Write_1(	kojiku->file.fp.wp3A.filter,
				kojiku->data.wp3A.real,
				kojiku->line.newline
	);
	}
	if(kojiku->check.check_filter08_3C==1){
	printf("、3D");
	Write_1(	kojiku->file.fp.wp3C.filter,
				kojiku->data.wp3C.real,
				kojiku->line.newline
	);
	}
	if(kojiku->check.check_filter09_3E==1){
	printf("、3E\n");
	Write_1(	kojiku->file.fp.wp3E.filter,
				kojiku->data.wp3E.real,
				kojiku->line.newline
	);
	}
	if(kojiku->check.check_filter10_pspr==1){
	printf("\t\t性能静圧上昇\n");
	Write_1(	kojiku->file.fp.pspr.filter,
				kojiku->data.pspr.real,
				kojiku->line.newline
	);
	}
	if(kojiku->check.check_filter11_hwi==1){
	printf("\t\t流速（I型熱線）\n");
	Write_1(	kojiku->file.fp.hwi.filter,
				kojiku->data.hwi.real,
				kojiku->line.newline
	);
	}
	if(kojiku->check.check_filter12_ptpr==1){
	printf("\t\t性能全圧上昇\n");
	Write_1(	kojiku->file.fp.ptpr.filter,
				kojiku->data.ptpr.real,
				kojiku->line.newline
	);
	}
	if(kojiku->check.check_filter13_averv==1){
	printf("\t\t圧縮機内平均軸流速\n");
	Write_1(	kojiku->file.fp.averv.filter,
				kojiku->data.averv.real,
				kojiku->line.newline
	);
	}
	if(kojiku->check.check_filter14_psi==1){
	printf("\t\t全圧上昇係数\n");
	Write_1(	kojiku->file.fp.psi.filter,
				kojiku->data.psi.real,
				kojiku->line.newline
	);
	}
	if(kojiku->check.check_filter13_spsi==1){
	printf("\t\t静圧上昇係数\n");
	Write_1(	kojiku->file.fp.psi_s.filter,
				kojiku->data.psi_s.real,
				kojiku->line.newline
	);
	}
	if(kojiku->check.check_filter15_phi==1){
	printf("\t\t流量係数\n");
	Write_1(	kojiku->file.fp.phi.filter,
					kojiku->data.phi.real,
					kojiku->line.newline
	);
	}
	if(kojiku->check.check_filter18_hwi2==1){
	printf("\t\t内部流れ（I型熱線）\n");
	Write_1(	kojiku->file.fp.hwi2.filter,
				kojiku->data.hwi2.real,
				kojiku->line.newline
	);
	}
	if(kojiku->check.check_filter18_hwi2==1){
	printf("\t\t内部流れ（無次元）\n");
	Write_1(	kojiku->file.fp.phi2.filter,
				kojiku->data.phi2.real,
				kojiku->line.newline
	);
	}
	if (kojiku->check.check_filter25_hwi3 == 1){
		printf("\t\t内部流れ（I型熱線）\n");
		Write_1(kojiku->file.fp.hwi3.filter,
			kojiku->data.hwi3.real,
			kojiku->line.newline
			);
	}
	if (kojiku->check.check_filter25_hwi3 == 1){
		printf("\t\t内部流れ（無次元）\n");
		Write_1(kojiku->file.fp.phi3.filter,
			kojiku->data.phi3.real,
			kojiku->line.newline
			);
	}
	if(kojiku->check.check_filter20_phi_psi==1){
	printf("\t\tψ-φ\n");
	Write_2(	kojiku->file.fp.phi_psi.filter,
				kojiku->data.phi.real, 
				kojiku->data.psi.real, 
				kojiku->line.newline
	);
	}
	if(kojiku->check.check_filter16_phi_spsi==1){
	printf("\t\tψs-φ\n");
	Write_2(	kojiku->file.fp.phi_psi_s.filter,
				kojiku->data.phi.real, 
				kojiku->data.psi_s.real, 
				kojiku->line.newline
	);
	}

	
	if (kojiku->check.check_filter31_hwsp1_v == 1) {
		printf("\t\tHwsp1_v......\n");
		Write_1(kojiku->file.fp.hwsp1_v.filter,
			kojiku->data.hwsp1_v.real,
			kojiku->line.newline
			);
	}

	if (kojiku->check.check_filter32_hwsp1_alpha == 1) {
		printf("\t\tHwsp1_alpha......\n");
		Write_1(kojiku->file.fp.hwsp1_alpha.filter,
			kojiku->data.hwsp1_alpha.real,
			kojiku->line.newline
			);
	}

	if (kojiku->check.check_filter33_hwsp1_vaxis == 1) {
		printf("\t\tHwsp1_vaxis......\n");
		Write_1(kojiku->file.fp.hwsp1_vaxis.filter,
			kojiku->data.hwsp1_vaxis.real,
			kojiku->line.newline
			);
	}

	if (kojiku->check.check_filter34_hwsp1_vcir == 1) {
		printf("\t\tHwsp1_vcir......\n");
		Write_1(kojiku->file.fp.hwsp1_vcir.filter,
			kojiku->data.hwsp1_vcir.real,
			kojiku->line.newline
			);
	}

	
	if (kojiku->check.check_filter35_ndvaxis1 == 1) {
		printf("\t\tHwsp1_ndvaxis......\n");
		Write_1(kojiku->file.fp.hwsp1_ndvaxis.filter,
			kojiku->data.hwsp1_ndvaxis.real,
			kojiku->line.newline
			);
	}

	if (kojiku->check.check_filter36_ndvcir1 == 1) {
		printf("\t\tHwsp1_ndvcir......\n");
		Write_1(kojiku->file.fp.hwsp1_ndvcir.filter,
			kojiku->data.hwsp1_ndvcir.real,
			kojiku->line.newline
			);
	}

	if (kojiku->check.check_filter37_2daverv1 == 1) {
		printf("\t\tHwsp1_2daverv......\n");
		Write_1(kojiku->file.fp.hwsp1_twod_averv.filter,
			kojiku->data.hwsp1_twod_averv.real,
			kojiku->line.newline
			);
	}

	if (kojiku->check.check_filter38_2dphi1 == 1) {
		printf("\t\tHwsp1_2dphi......\n");
		Write_1(kojiku->file.fp.hwsp1_twod_phi.filter,
			kojiku->data.hwsp1_twod_phi.real,
			kojiku->line.newline
			);
	}

	if(kojiku->check.check_filter39_2dphi_psi1 == 1){
	printf("\t\tHwsp1_2dphi_psi......\n");
	Write_2(	kojiku->file.fp.hwsp1_twod_phi_psi.filter,
		kojiku->data.hwsp1_twod_phi.real, 
				kojiku->data.psi.real, 
				kojiku->line.newline
	);
	}

	if (kojiku->check.check_filter41_hwsp2_v == 1) {
		printf("\t\tHwsp2_v......\n");
		Write_1(kojiku->file.fp.hwsp2_v.filter,
			kojiku->data.hwsp2_v.real,
			kojiku->line.newline
			);
	}

	if (kojiku->check.check_filter42_hwsp2_alpha == 1) {
		printf("\t\tHwsp2_alpha......\n");
		Write_1(kojiku->file.fp.hwsp2_alpha.filter,
			kojiku->data.hwsp2_alpha.real,
			kojiku->line.newline
			);
	}

	if (kojiku->check.check_filter43_hwsp2_vaxis == 1) {
		printf("\t\thwsp2_vaxis......\n");
		Write_1(kojiku->file.fp.hwsp2_vaxis.filter,
			kojiku->data.hwsp2_vaxis.real,
			kojiku->line.newline
			);
	}

	if (kojiku->check.check_filter44_hwsp2_vcir == 1) {
		printf("\t\thwsp2_vcir......\n");
		Write_1(kojiku->file.fp.hwsp2_vcir.filter,
			kojiku->data.hwsp2_vcir.real,
			kojiku->line.newline
			);
	}

	
	if (kojiku->check.check_filter45_ndvaxis2 == 1) {
		printf("\t\thwsp2_ndvaxis......\n");
		Write_1(kojiku->file.fp.hwsp2_ndvaxis.filter,
			kojiku->data.hwsp2_ndvaxis.real,
			kojiku->line.newline
			);
	}

	if (kojiku->check.check_filter46_ndvcir2 == 1) {
		printf("\t\thwsp2_ndvcir......\n");
		Write_1(kojiku->file.fp.hwsp2_ndvcir.filter,
			kojiku->data.hwsp2_ndvcir.real,
			kojiku->line.newline
			);
	}

	if (kojiku->check.check_filter47_2daverv2 == 1) {
		printf("\t\thwsp2_2daverv......\n");
		Write_1(kojiku->file.fp.hwsp2_twod_averv.filter,
			kojiku->data.hwsp2_twod_averv.real,
			kojiku->line.newline
			);
	}

	if (kojiku->check.check_filter48_2dphi2 == 1) {
		printf("\t\thwsp2_2dphi......\n");
		Write_1(kojiku->file.fp.hwsp2_twod_phi.filter,
			kojiku->data.hwsp2_twod_phi.real,
			kojiku->line.newline
			);
	}

	if(kojiku->check.check_filter49_2dphi_psi2 == 1){
	printf("\t\thwsp2_2dphi_psi......\n");
	Write_2(	kojiku->file.fp.hwsp2_twod_phi_psi.filter,
		kojiku->data.hwsp2_twod_phi.real, 
				kojiku->data.psi.real, 
				kojiku->line.newline
	);
	}

	if(kojiku->check.check_filter51_ptank==1){
	printf("\t\tタンク静圧上昇\n");
	Write_1(	kojiku->file.fp.ptank.filter,
				kojiku->data.ptank.real,
				kojiku->line.newline
	);
	}

	if(kojiku->check.check_filter52_ptank_psi==1){
	printf("\t\tタンク静圧上昇係数\n");
	Write_1(	kojiku->file.fp.ptank_psi.filter,
				kojiku->data.ptank_psi.real,
				kojiku->line.newline
	);
	}

}
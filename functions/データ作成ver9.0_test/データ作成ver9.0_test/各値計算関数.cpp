//*************************************************************************************************************
//電圧値から
//	動翼前縁壁面静圧
//	性能静圧上昇
//	軸流速（I型熱線）
//	性能全圧上昇
//	圧縮機内平均軸流速
//	全圧上昇係数
//	流量係数
//  とかを計算する関数たち
//*************************************************************************************************************

//標準ライブラリのインクルード
#include<stdio.h>
#include<math.h>
#include "定数・構造体定義.h"
#include "自作関数定義.h"		//自作ヘッダ

//------------------------------------------------------------------------------------------------------------
//各値計算関数
//------------------------------------------------------------------------------------------------------------
void Calculation( st_kojiku *kojiku ){
	//計算------------------------------------------------------------------------------
	Cal_Wp( kojiku );
	Cal_Pspr( kojiku );
	Cal_Fwi( kojiku );
	Cal_Averv( kojiku );
	Cal_Ptpr( kojiku );
	Cal_Psi( kojiku );
	Cal_Psi_s( kojiku );
	Cal_Fwi2( kojiku );
	Cal_Fwi3( kojiku );
	Cal_Phi( kojiku );
	Cal_Valve( kojiku );
	Cal_Plunge(kojiku);
	Cal_Fwsp1(kojiku);
	Cal_Fwsp2(kojiku);
	Cal_Ptank(kojiku);
	Cal_Ptank_psi(kojiku);
}

//圧縮波入射時にdpdt,dqdtをチェックする

void Cal_dpdt( st_kojiku *kojiku ){
	if(kojiku->check.log2check==1){
		if(kojiku->check.check_rawdata_dpdt_dqdt==1){
			double *p1;
			double *p2;
			double *p3;
			p3 = kojiku->data.psi.real;
			for(	p1 = kojiku->data.dpdt.real,
				p2 = kojiku->data.psi.real;
				p1 < kojiku->data.dpdt.real + kojiku->line.line,
				p2 < kojiku->data.psi.real + kojiku->line.line;
			p1=p1+480,
				p2=p2+480 ){
					if(p3+480 < kojiku->data.psi.real + kojiku->line.line){
						p3=p3+480;}
					*p1 = *p3-*p2;
			}

			printf("\t\tdpdt......\n");
			Write_1(	kojiku->file.fp.dpdt.rawdata,
				kojiku->data.dpdt.real,
				kojiku->line.newline
				);
		}
	}
}

void Cal_dqdt( st_kojiku *kojiku ){
	if(kojiku->check.log2check==1){
		if(kojiku->check.check_rawdata_dpdt_dqdt==1){
			double *p1;
			double *p2;
			double *p3;
			p3 = kojiku->data.phi.real;
			for(	p1 = kojiku->data.dqdt.real,
				p2 = kojiku->data.phi.real;
				p1 < kojiku->data.dqdt.real + kojiku->line.line,
				p2 < kojiku->data.phi.real + kojiku->line.line;
			p1=p1+480,
				p2=p2+480 ){
					if(p3+480 < kojiku->data.phi.real + kojiku->line.line){
						p3=p3+480;}
					*p1 = *p3-*p2;
			}
			//	kojiku->line.newline = kojiku->line.newline/480.;
			printf("\t\tdqdt......\n");
			Write_1(	kojiku->file.fp.dqdt.rawdata,
				kojiku->data.dqdt.real,
				kojiku->line.newline
				);
		}
	}
}

//ジェット噴射のバルブ開閉関数

void Cal_Valve( st_kojiku *kojiku ){
	double *p1;
	double *p2;
	if(kojiku->check.check_rawdata22_valve==1){
		for(	p1 = kojiku->data.valve.real,
			p2 = kojiku->data.data_d[15];
			p1 < kojiku->data.valve.real + kojiku->line.line,
			p2 < kojiku->data.data_d[15] + kojiku->line.line;
		p1++,
			p2++ ){
				*p1 = *p2;
		}
	}
}

//撃針の信号波形関数

void Cal_Plunge(st_kojiku *kojiku) {
	double *p1;
	double *p2;
	if (kojiku->check.check_rawdata27_plunge == 1) {
		for (p1 = kojiku->data.plunge.real,
			p2 = kojiku->data.data_d[0];
			p1 < kojiku->data.plunge.real + kojiku->line.line,
			p2 < kojiku->data.data_d[0] + kojiku->line.line;
		p1++,
			p2++) {
				*p1 = *p2;
		}
	}
	printf("撃針…\n");
}

//------------------------------------------------------------------------------------------------------------
//動翼壁圧計算関数・自己相関係数結果出力関数
//------------------------------------------------------------------------------------------------------------
void Cal_Wp( st_kojiku *kojiku ){
	//変数宣言---------------------------------------------------------------------------------------
	double	*p1;
	double	*p2;

	//計算------------------------------------------------------------------------------
	if(kojiku->check.check_rawdata01_1A==1 || kojiku->check.check_filter01_1A==1 || kojiku->check.check_FFTampspec01_1A==1){
		for(	p1 = kojiku->data.wp1A.real,
			p2 = kojiku->data.data_d[4];
			p1 < kojiku->data.wp1A.real + kojiku->line.line,
			p2 < kojiku->data.data_d[4] + kojiku->line.line;
		p1++,
			p2++ ){
				*p1= ( *p2 - kojiku->init.wp1A ) * kojiku->sens.wp1A /(0.5 * kojiku->atm.dens * kojiku->atm.Uc * kojiku->atm.Uc /1000.0 );
		}
		//フィルター用に配列の中身が0のものをなくす
		for(	p1 = kojiku->data.wp1A.real + kojiku->line.line;
			p1 < kojiku->data.wp1A.real + kojiku->line.newline;
			p1++ ){
				*p1 = kojiku->data.wp1A.real[kojiku->line.line-1];
		}

	}
	if(kojiku->check.check_rawdata02_1C==1 || kojiku->check.check_filter02_1C==1){
		for(	p1 = kojiku->data.wp1C.real,
			p2 = kojiku->data.data_d[5];
			p1 < kojiku->data.wp1C.real + kojiku->line.line,
			p2 < kojiku->data.data_d[5] + kojiku->line.line;
		p1++,
			p2++ ){
				*p1 = ( *p2 - kojiku->init.wp1C ) * kojiku->sens.wp1C/(0.5 * kojiku->atm.dens * kojiku->atm.Uc * kojiku->atm.Uc /1000.0 );
		}
		for(	p1 = kojiku->data.wp1C.real + kojiku->line.line;
			p1 < kojiku->data.wp1C.real + kojiku->line.newline;
			p1++ ){
				*p1 = kojiku->data.wp1C.real[kojiku->line.line-1];
		}

	}
	if(kojiku->check.check_rawdata03_1E==1 || kojiku->check.check_filter03_1E==1){
		for(	p1 = kojiku->data.wp1E.real,
			p2 = kojiku->data.data_d[6];
			p1 < kojiku->data.wp1E.real + kojiku->line.line,
			p2 < kojiku->data.data_d[6] + kojiku->line.line;
		p1++,
			p2++ ){
				//		*p1 = *p2 / kojiku->p_max.DA1;	//自己相関係数計算結果出力
				*p1 = ( *p2 - kojiku->init.wp1E ) * kojiku->sens.wp1E/(0.5 * kojiku->atm.dens * kojiku->atm.Uc * kojiku->atm.Uc /1000.0 );
		}
		for(	p1 = kojiku->data.wp1E.real + kojiku->line.line;
			p1 < kojiku->data.wp1E.real + kojiku->line.newline;
			p1++ ){
				*p1 = kojiku->data.wp1E.real[kojiku->line.line-1];
		}
	}
	if(kojiku->check.check_rawdata04_2A==1 || kojiku->check.check_filter04_2A==1 || kojiku->check.check_FFTampspec04_2A==1){
		for(	p1 = kojiku->data.wp2A.real,
			p2 = kojiku->data.data_d[7];
			p1 < kojiku->data.wp2A.real + kojiku->line.line,
			p2 < kojiku->data.data_d[7] + kojiku->line.line;
		p1++,
			p2++ ){
				*p1 = ( *p2 - kojiku->init.wp2A ) * kojiku->sens.wp2A/(0.5 * kojiku->atm.dens * kojiku->atm.Uc * kojiku->atm.Uc /1000.0 );
		}
		for(	p1 = kojiku->data.wp2A.real + kojiku->line.line;
			p1 < kojiku->data.wp2A.real + kojiku->line.newline;
			p1++ ){
				*p1 = kojiku->data.wp2A.real[kojiku->line.line-1];
		}

	}
	if(kojiku->check.check_rawdata05_2C==1 || kojiku->check.check_filter05_2C==1){
		for(	p1 = kojiku->data.wp2C.real,
			p2 = kojiku->data.data_d[8];
			p1 < kojiku->data.wp2C.real + kojiku->line.line,
			p2 < kojiku->data.data_d[8] + kojiku->line.line;
		p1++,
			p2++ ){
				*p1 = ( *p2 - kojiku->init.wp2C ) * kojiku->sens.wp2C/(0.5 * kojiku->atm.dens * kojiku->atm.Uc * kojiku->atm.Uc /1000.0 );
		}
		for(	p1 = kojiku->data.wp2C.real + kojiku->line.line;
			p1 < kojiku->data.wp2C.real + kojiku->line.newline;
			p1++ ){
				*p1 = kojiku->data.wp2C.real[kojiku->line.line-1];
		}

	}
	if(kojiku->check.check_rawdata06_2E==1 || kojiku->check.check_filter06_2E==1){
		for(	p1 = kojiku->data.wp2E.real,
			p2 = kojiku->data.data_d[9];
			p1 < kojiku->data.wp2E.real + kojiku->line.line,
			p2 < kojiku->data.data_d[9] + kojiku->line.line;
		p1++,
			p2++ ){
				//			*p1 = *p2 / kojiku->p_max.DA2; //自己相関係数計算結果出力
				*p1 = ( *p2 - kojiku->init.wp2E ) * kojiku->sens.wp2E/(0.5 * kojiku->atm.dens * kojiku->atm.Uc * kojiku->atm.Uc /1000.0 );
		}
		for(	p1 = kojiku->data.wp2E.real + kojiku->line.line;
			p1 < kojiku->data.wp2E.real + kojiku->line.newline;
			p1++ ){
				*p1 = kojiku->data.wp2E.real[kojiku->line.line-1];
		}
	}
	if(kojiku->check.check_rawdata07_3A==1 || kojiku->check.check_filter07_3A==1 || kojiku->check.check_FFTampspec07_3A==1){
		for(	p1 = kojiku->data.wp3A.real,
			p2 = kojiku->data.data_d[10];
			p1 < kojiku->data.wp3A.real + kojiku->line.line,
			p2 < kojiku->data.data_d[10] + kojiku->line.line;
		p1++,
			p2++ ){
				*p1 = ( *p2 - kojiku->init.wp3A ) * kojiku->sens.wp3A/(0.5 * kojiku->atm.dens * kojiku->atm.Uc * kojiku->atm.Uc /1000.0 );
		}
		for(	p1 = kojiku->data.wp3A.real + kojiku->line.line;
			p1 < kojiku->data.wp3A.real + kojiku->line.newline;
			p1++ ){				
				*p1 = kojiku->data.wp3A.real[kojiku->line.line-1];
		}

	}

	if(kojiku->check.check_rawdata08_3C==1 || kojiku->check.check_filter08_3C==1){
		for(	p1 = kojiku->data.wp3C.real,
			p2 = kojiku->data.data_d[11];
			p1 < kojiku->data.wp3C.real + kojiku->line.line,
			p2 < kojiku->data.data_d[11] + kojiku->line.line;
		p1++,
			p2++ ){
				*p1 = ( *p2 - kojiku->init.wp3C ) * kojiku->sens.wp3C/(0.5 * kojiku->atm.dens * kojiku->atm.Uc * kojiku->atm.Uc /1000.0 );
		}
		for(	p1 = kojiku->data.wp3C.real + kojiku->line.line;
			p1 < kojiku->data.wp3C.real + kojiku->line.newline;
			p1++ ){
				*p1 = kojiku->data.wp3C.real[kojiku->line.line-1];
		}
	}

	if(kojiku->check.check_rawdata09_3E==1 || kojiku->check.check_filter09_3E==1){
		for(	p1 = kojiku->data.wp3E.real,
			p2 = kojiku->data.data_d[12];
			p1 < kojiku->data.wp3E.real + kojiku->line.line,
			p2 < kojiku->data.data_d[12] + kojiku->line.line;
		p1++,
			p2++ ){
				*p1 = *p2 / kojiku->p_max.DA3; //自己相関係数計算結果出力
				//		*p1 = ( *p2 - kojiku->init.wp3E ) * kojiku->sens.wp3E/(0.5 * kojiku->atm.dens * kojiku->atm.Uc * kojiku->atm.Uc /1000.0 );
		}
		for(	p1 = kojiku->data.wp3E.real + kojiku->line.line;
			p1 < kojiku->data.wp3E.real + kojiku->line.newline;
			p1++ ){
				*p1 = kojiku->data.wp3E.real[kojiku->line.line-1];
		}

	}

}

//------------------------------------------------------------------------------------------------------------
//性能静圧上昇計算関数
//------------------------------------------------------------------------------------------------------------
void Cal_Pspr( st_kojiku *kojiku ){

	//変数宣言---------------------------------------------------------------------------------------
	double	*pspr;
	double	*p2;
	double  kosei0 = ( (100.0 - kojiku->sens.kousei.P_0) / kojiku->sens.kousei.P_1) - (kojiku->p_max.p_ave - kojiku->init.pspr);  //100[mmAq]のときのp-maxと校正曲線のx方向のズレ
	double  kosei1 = kosei0 * kojiku->sens.kousei.P_1; //この値だけ縦軸をずらして出力させる.

	//printf("突然ですが%lf\n",kojiku->sens.kousei.P_1);

	if(kojiku->check.check_rawdata10_pspr==1 || kojiku->check.check_filter10_pspr==1 || kojiku->check.check_rawdata12_ptpr==1 || kojiku->check.check_filter12_ptpr==1 || kojiku->check.check_rawdata14_psi==1 || kojiku->check.check_filter14_psi==1 || kojiku->check.check_rawdata20_phi_psi==1 || kojiku->check.check_filter20_phi_psi==1 || kojiku->check.check_FFTampspec12_ptpr==1 || kojiku->check.check_rawdata13_spsi==1 || kojiku->check.check_filter13_spsi==1 || kojiku->check.check_rawdata16_phi_spsi==1 || kojiku->check.check_filter16_phi_spsi==1 || kojiku->check.check_rawdata_dpdt_dqdt==1){
		//計算------------------------------------------------------------------------------
		for(	pspr = kojiku->data.pspr.real,
			p2 = kojiku->data.data_d[13];
			pspr < kojiku->data.pspr.real + kojiku->line.line,
			p2 < kojiku->data.data_d[13] + kojiku->line.line;
		pspr++,
			p2++ ){
				*pspr = ( *p2 - kojiku->init.pspr ) * kojiku->sens.pspr;
				//*pspr = ( kojiku->sens.kousei.P_1 * (*p2 - kojiku->init.pspr) + kojiku->sens.kousei.P_0 + kosei1 )* 9.80665 / 1000.0;//kPa
		}
		//フィルター用作業------------------------------------------------------------------
		for(	pspr = kojiku->data.pspr.real + kojiku->line.line;
			pspr < kojiku->data.pspr.real + kojiku->line.newline;
			pspr++ ){
				*pspr = kojiku->data.pspr.real[kojiku->line.line-1];
		}
	}
}

//------------------------------------------------------------------------------------------------------------
//軸流速計算関数
//------------------------------------------------------------------------------------------------------------
void Cal_Fwi( st_kojiku *kojiku ){

	//変数宣言---------------------------------------------------------------------------------------
	double	*hwi;
	double	*p2;

	if(kojiku->check.check_rawdata11_hwi==1 || kojiku->check.check_filter11_hwi==1 || kojiku->check.check_rawdata13_averv==1 || kojiku->check.check_filter13_averv==1 || kojiku->check.check_rawdata15_phi==1 || kojiku->check.check_filter15_phi==1 || kojiku->check.check_rawdata20_phi_psi==1 || kojiku->check.check_filter20_phi_psi==1 || kojiku->check.check_FFTampspec11_hwi==1 || kojiku->check.check_rawdata_dpdt_dqdt==1){
		//計算------------------------------------------------------------------------------
		for(	hwi = kojiku->data.hwi.real,
			p2 = kojiku->data.data_d[14];
			hwi < kojiku->data.hwi.real + kojiku->line.line,
			p2 < kojiku->data.data_d[14] + kojiku->line.line;
		hwi++,
			p2++ ){
				*hwi= kojiku->sens.hwi.__6 * (*p2) * (*p2) * (*p2) * (*p2) * (*p2) * (*p2)
					+ kojiku->sens.hwi.__5 * (*p2) * (*p2) * (*p2) * (*p2) * (*p2)	//5乗
					+ kojiku->sens.hwi.__4 * (*p2) * (*p2) * (*p2) * (*p2)			//4乗
					+ kojiku->sens.hwi.__3 * (*p2) * (*p2) * (*p2)					//3乗
					+ kojiku->sens.hwi.__2 * (*p2) * (*p2)							//2乗
					+ kojiku->sens.hwi.__1 * (*p2)									//1乗
					+ kojiku->sens.hwi.__0;											//0乗*/
		}
		//フィルター用作業------------------------------------------------------------------
		for(	hwi = kojiku->data.hwi.real + kojiku->line.line;
			hwi < kojiku->data.hwi.real + kojiku->line.newline;
			hwi++ ){
				*hwi = kojiku->data.hwi.real[kojiku->line.line-1];
		}
	}
}

//------------------------------------------------------------------------------------------------------------
//内部流れ計算関数①
//------------------------------------------------------------------------------------------------------------
void Cal_Fwi2( st_kojiku *kojiku ){

	//変数宣言---------------------------------------------------------------------------------------
	double	*hwi;
	double	*p2;
	if(kojiku->check.check_rawdata18_hwi2==1 || kojiku->check.check_filter18_hwi2==1 || kojiku->check.check_FFTampspec18_hwi2==1){
		//計算------------------------------------------------------------------------------
		for(	hwi = kojiku->data.hwi2.real,
			p2 = kojiku->data.data_d[1];
			hwi < kojiku->data.hwi2.real + kojiku->line.line,
			p2 < kojiku->data.data_d[1] + kojiku->line.line;
		hwi++,
			p2++ ){
				*hwi= kojiku->sens.hwi2.__6 * (*p2) * (*p2) * (*p2) * (*p2) * (*p2) * (*p2)
					+ kojiku->sens.hwi2.__5 * (*p2) * (*p2) * (*p2) * (*p2) * (*p2)	//5乗
					+ kojiku->sens.hwi2.__4 * (*p2) * (*p2) * (*p2) * (*p2)			//4乗
					+ kojiku->sens.hwi2.__3 * (*p2) * (*p2) * (*p2)					//3乗
					+ kojiku->sens.hwi2.__2 * (*p2) * (*p2)							//2乗
					+ kojiku->sens.hwi2.__1 * (*p2)									//1乗			
					+ kojiku->sens.hwi2.__0;										//0乗*/
		}
		//フィルター用作業------------------------------------------------------------------
		for(	hwi = kojiku->data.hwi2.real + kojiku->line.line;
			hwi < kojiku->data.hwi2.real + kojiku->line.newline;
			hwi++ ){
				*hwi = kojiku->data.hwi2.real[kojiku->line.line-1];
		}
	}
}

//------------------------------------------------------------------------------------------------------------
//内部流れ計算関数②
//------------------------------------------------------------------------------------------------------------
void Cal_Fwi3(st_kojiku *kojiku){

	//変数宣言---------------------------------------------------------------------------------------
	double	*hwi;
	double	*p3;
	if (kojiku->check.check_rawdata25_hwi3 == 1 || kojiku->check.check_filter25_hwi3 == 1 || kojiku->check.check_FFTampspec25_hwi3 == 1){
		//計算------------------------------------------------------------------------------
		for (hwi = kojiku->data.hwi3.real,
			p3 = kojiku->data.data_d[10];
			hwi < kojiku->data.hwi3.real + kojiku->line.line,
			p3 < kojiku->data.data_d[10] + kojiku->line.line;
		hwi++,
			p3++){
				*hwi = kojiku->sens.hwi3.__6 * (*p3) * (*p3) * (*p3) * (*p3) * (*p3) * (*p3) 
					+ kojiku->sens.hwi3.__5 * (*p3) * (*p3) * (*p3) * (*p3) * (*p3)	//5乗
					+ kojiku->sens.hwi3.__4 * (*p3) * (*p3) * (*p3) * (*p3)			//4乗
					+ kojiku->sens.hwi3.__3 * (*p3) * (*p3) * (*p3)					//3乗
					+ kojiku->sens.hwi3.__2 * (*p3) * (*p3)							//2乗
					+ kojiku->sens.hwi3.__1 * (*p3)									//1乗			
					+ kojiku->sens.hwi3.__0;										//0乗*/
		}
		//フィルター用作業------------------------------------------------------------------
		for (hwi = kojiku->data.hwi3.real + kojiku->line.line;
			hwi < kojiku->data.hwi3.real + kojiku->line.newline;
			hwi++){
				*hwi = kojiku->data.hwi3.real[kojiku->line.line - 1];
		}
	}
}

//------------------------------------------------------------------------------------------------------------
//圧縮機内平均軸流速計算関数
//------------------------------------------------------------------------------------------------------------
void Cal_Averv( st_kojiku *kojiku ){

	//変数宣言---------------------------------------------------------------------------------------
	double	*averv;
	double	*hwi;
	double	shuusei_v;
	if(kojiku->check.check_rawdata13_averv==1 || kojiku->check.check_filter13_averv==1 || kojiku->check.check_rawdata15_phi==1 || kojiku->check.check_filter15_phi==1 || kojiku->check.check_rawdata20_phi_psi==1 || kojiku->check.check_filter20_phi_psi==1 || kojiku->check.check_rawdata_dpdt_dqdt==1){

		//計算------------------------------------------------------------------------------
		for(	averv = kojiku->data.averv.real,
			hwi = kojiku->data.hwi.real;
			averv < kojiku->data.averv.real + kojiku->line.line,
			hwi < kojiku->data.hwi.real + kojiku->line.line;
		averv++,
			hwi++ ){
				shuusei_v	= (*hwi) ;//* sqrt( kojiku->atm.T_ave / T0 ) * ( P0 / kojiku->atm.P_ave );
				//* ( 0.13 * 0.13 - 0.062 * 0.062 ) / ( 0.131 * 0.131 - 0.08 * 0.08 );
				if(kojiku->check.check_position == 1){
					*averv	= ( kojiku->sens.kousei.__1 * (shuusei_v) );
					*averv	=  *averv  * ( 0.13 * 0.13 - 0.062 * 0.062 ) / ( 0.131 * 0.131 - 0.08 * 0.08 );}
				else{
					*averv	= ( kojiku->sens.kousei.__0 * (shuusei_v) );
					//printf("%d\n",kojiku->check.check_position);
				}
				//		*averv	= ( kojiku->p_max.mmAq_v / kojiku->p_max.v_ave)* ( *hwi );

		}
		//フィルター用作業------------------------------------------------------------------
		for( averv = kojiku->data.averv.real + kojiku->line.line; 
			averv < kojiku->data.averv.real + kojiku->line.newline;
			averv++ ){
				*averv = kojiku->data.averv.real[kojiku->line.line-1];
		}
	}
}

//------------------------------------------------------------------------------------------------------------
//全圧上昇計算関数
//------------------------------------------------------------------------------------------------------------
void Cal_Ptpr( st_kojiku *kojiku ){

	//変数宣言---------------------------------------------------------------------------------------
	double	*ptpr;
	double	*p2;
	double	*p3;
	if(kojiku->check.check_rawdata12_ptpr==1 || kojiku->check.check_filter12_ptpr==1 || kojiku->check.check_rawdata14_psi==1 || kojiku->check.check_filter14_psi==1 || kojiku->check.check_rawdata20_phi_psi==1 || kojiku->check.check_filter20_phi_psi==1 || kojiku->check.check_FFTampspec12_ptpr==1 || kojiku->check.check_rawdata_dpdt_dqdt==1){

		//計算------------------------------------------------------------------------------
		for(	ptpr = kojiku->data.ptpr.real,
			p2 = kojiku->data.pspr.real,
			p3 = kojiku->data.averv.real;
		ptpr < kojiku->data.ptpr.real + kojiku->line.line,
			p2 < kojiku->data.pspr.real + kojiku->line.line,
			p3 < kojiku->data.averv.real + kojiku->line.line;
		ptpr++,
			p2++,
			p3++ ){
				*ptpr = (*p2) + ( kojiku->atm.dens * (*p3) * (*p3) / 2000.0);
		}
		//フィルター用作業------------------------------------------------------------------
		for(	ptpr = kojiku->data.ptpr.real + kojiku->line.line;
			ptpr < kojiku->data.ptpr.real + kojiku->line.newline;
			ptpr++ ){
				*ptpr = kojiku->data.ptpr.real[kojiku->line.line-1];
		}
	}
}

//------------------------------------------------------------------------------------------------------------
//全圧上昇係数計算関数
//------------------------------------------------------------------------------------------------------------
void Cal_Psi( st_kojiku *kojiku ){

	//変数宣言---------------------------------------------------------------------------------------
	double	*psi;
	double	*p2;
	double	*p3;
	//	double MAXpsi=0.0;
	if(kojiku->check.check_rawdata14_psi==1 || kojiku->check.check_filter14_psi==1 || kojiku->check.check_rawdata20_phi_psi==1 || kojiku->check.check_filter20_phi_psi==1 || kojiku->check.check_rawdata_dpdt_dqdt==1){

		//計算------------------------------------------------------------------------------
		for(	psi = kojiku->data.psi.real,
			p2  = kojiku->data.ptpr.real,
			p3  = kojiku->data.averv.real;
		psi < kojiku->data.psi.real + kojiku->line.line,
			p2 < kojiku->data.ptpr.real + kojiku->line.line,
			p3 < kojiku->data.averv.real + kojiku->line.line;
		psi++,
			p2++,
			p3++){
				//	for(	psi = kojiku->data.psi.real,
				//			p2 = kojiku->data.data_d[13],
				//			p3 = kojiku->data.averv.real;
				//			psi < kojiku->data.psi.real + kojiku->line.line,
				//			p2 < kojiku->data.data_d[13] + kojiku->line.line,
				//			p3 < kojiku->data.averv.real + kojiku->line.line;
				//			psi++,
				//			p2++,
				//			p3++){
				//				*psi = kojiku->petit.mmAq /( kojiku->p_max.p_ave - kojiku->init.pspr ) * ( *p2 - kojiku->init.pspr );		//mmAqで出力
				//				*psi = 0.00980665 * (*psi) + kojiku->atm.dens * (*p3) * (*p3) / 2000.0;	//kPaに単位変換して動圧にする
				//		 		*psi = ( *psi ) / ( kojiku->atm.dens * kojiku->atm.Uc * kojiku->atm.Uc / 2000.0);	//無次元化
				*psi = (*p2) / (kojiku->atm.dens * kojiku->atm.Uc * kojiku->atm.Uc / 2000.0);
				//				if(MAXpsi<*psi){MAXpsi=*psi;}
		}
		//フィルター用作業------------------------------------------------------------------
		for( psi = kojiku->data.psi.real + kojiku->line.line;
			psi < kojiku->data.psi.real + kojiku->line.newline;
			psi++ ){
				*psi = kojiku->data.psi.real[kojiku->line.line-1];
		}
	}
}

//------------------------------------------------------------------------------------------------------------
//静圧上昇係数計算関数
//------------------------------------------------------------------------------------------------------------
void Cal_Psi_s( st_kojiku *kojiku ){

	//変数宣言---------------------------------------------------------------------------------------
	double	*psi_s;
	double	*p2;
	double  *p3;

	if( kojiku->check.check_rawdata13_spsi==1 || kojiku->check.check_filter13_spsi==1 || kojiku->check.check_rawdata16_phi_spsi==1 || kojiku->check.check_filter16_phi_spsi==1){

		//計算------------------------------------------------------------------------------
		for(	psi_s = kojiku->data.psi_s.real,
			p2 = kojiku->data.data_d[13],
			p3 = kojiku->data.pspr.real;
		psi_s < kojiku->data.psi_s.real + kojiku->line.line,
			p2 < kojiku->data.data_d[13] + kojiku->line.line,
			p3 < kojiku->data.pspr.real + kojiku->line.line;
		psi_s++,
			p2++,
			p3++
			){
				/*				*psi_s = kojiku->p_max.mmAq /( kojiku->p_max.p_ave - kojiku->init.pspr ) * ( *p2 - kojiku->init.pspr ); //mmAqで出力
				*psi_s = 0.00980665 * (*psi_s);		//kPaに単位変換
				*psi_s = ( *psi_s ) / ( kojiku->atm.dens * kojiku->atm.Uc * kojiku->atm.Uc / 2000.0);	//無次元化*/
				*psi_s = *p3 / (kojiku->atm.dens * kojiku->atm.Uc * kojiku->atm.Uc / 2000.0);
		}
		//フィルター用作業------------------------------------------------------------------
		for( psi_s = kojiku->data.psi_s.real + kojiku->line.line;
			psi_s < kojiku->data.psi_s.real + kojiku->line.newline;
			psi_s++ ){
				*psi_s = kojiku->data.psi_s.real[kojiku->line.line-1];
		}
	}
}

//------------------------------------------------------------------------------------------------------------
//流量係数計算関数
//------------------------------------------------------------------------------------------------------------
void Cal_Phi( st_kojiku *kojiku ){

	//変数宣言---------------------------------------------------------------------------------------
	double	*phi;
	double  *phi2;
	double  *phi3;
	double	*p1;
	double	*p2;
	double  *p3;


	//計算------------------------------------------------------------------------------
	if(kojiku->check.check_rawdata15_phi==1 || kojiku->check.check_filter15_phi==1 || kojiku->check.check_rawdata20_phi_psi==1 || kojiku->check.check_filter20_phi_psi==1 || kojiku->check.check_rawdata16_phi_spsi==1 || kojiku->check.check_filter16_phi_spsi==1 || kojiku->check.check_rawdata_dpdt_dqdt==1){
		for(	phi = kojiku->data.phi.real,
			p1 = kojiku->data.averv.real;
			phi < kojiku->data.phi.real + kojiku->line.line,
			p1 < kojiku->data.averv.real + kojiku->line.line;
		phi++,
			p1++){
				//				*phi	= ( kojiku->p_max.mmAq_v / kojiku->p_max.v_ave)* ( *p2 );	//PetitTestφ
				*phi	=( *p1) / kojiku->atm.Uc;//無次元化


		}
		for( phi = kojiku->data.phi.real + kojiku->line.line;
			phi < kojiku->data.phi.real + kojiku->line.newline;
			phi++){
				*phi = kojiku->data.phi.real[kojiku->line.line-1];
				//printf("へっ%d\n",i);i++;
		}
	}

	if(kojiku->check.check_rawdata18_hwi2==1 || kojiku->check.check_filter18_hwi2==1 || kojiku->check.check_FFTampspec18_hwi2==1){
		for(	phi2= kojiku->data.phi2.real,
			p2 = kojiku->data.hwi2.real;
			phi2< kojiku->data.phi2.real+ kojiku->line.line,
			p2 < kojiku->data.hwi2.real + kojiku->line.line;
		phi2++,
			p2++){
				*phi2	= ( *p2) / kojiku->atm.Uc;
		}
		for( phi2= kojiku->data.phi2.real+ kojiku->line.line;
			phi2< kojiku->data.phi2.real+ kojiku->line.newline;
			phi2++){
				*phi2= kojiku->data.phi2.real[kojiku->line.line-1];
		}
	}

	if (kojiku->check.check_rawdata25_hwi3 == 1 || kojiku->check.check_filter25_hwi3 == 1 || kojiku->check.check_FFTampspec25_hwi3 == 1){
		for (phi3 = kojiku->data.phi3.real,
			p3 = kojiku->data.hwi3.real;
			phi3< kojiku->data.phi3.real + kojiku->line.line,
			p3 < kojiku->data.hwi3.real + kojiku->line.line;
		phi3++,
			p3++){
				*phi3 = (*p3) / kojiku->atm.Uc;
		}
		for (phi3 = kojiku->data.phi3.real + kojiku->line.line;
			phi3< kojiku->data.phi3.real + kojiku->line.newline;
			phi3++){
				*phi3 = kojiku->data.phi3.real[kojiku->line.line - 1];
		}
	}

}

//------------------------------------------------------------------------------------------------------------
//スプリット型熱線流速計計算関数(55R55)
//------------------------------------------------------------------------------------------------------------
void Cal_Fwsp1( st_kojiku *kojiku ){

	//変数宣言---------------------------------------------------------------------------------------
	double	*hwi,*alpha, *vaxis, *vcir, *nd_ax, *nd_cir, *averv, *phi;
	double	*p1;
	double	*p2;

	if(kojiku->check.check_filter31_hwsp1_v	==1 || kojiku->check.check_filter32_hwsp1_alpha==1 || kojiku->check.check_filter33_hwsp1_vaxis==1 || kojiku->check.check_filter34_hwsp1_vcir==1 || kojiku->check.check_filter35_ndvaxis1==1 || kojiku->check.check_filter36_ndvcir1==1 || kojiku->check.check_filter37_2daverv1==1 || kojiku->check.check_filter38_2dphi1 ==1 || kojiku->check.check_filter39_2dphi_psi1 ==1
		||kojiku->check.check_rawdata31_hwsp1_v	==1 || kojiku->check.check_rawdata32_hwsp1_alpha==1 || kojiku->check.check_rawdata33_hwsp1_vaxis==1 || kojiku->check.check_rawdata34_hwsp1_vcir==1 || kojiku->check.check_rawdata35_ndvaxis1==1 || kojiku->check.check_rawdata36_ndvcir1==1 || kojiku->check.check_rawdata37_2daverv1==1 || kojiku->check.check_rawdata38_2dphi1 ==1 || kojiku->check.check_rawdata39_2dphi_psi1 ==1
		|| kojiku->check.check_FFTampspec33_hwsp1_vaxis==1 || kojiku->check.check_FFTampspec34_hwsp1_vcir==1){
		//V計算------------------------------------------------------------------------------
		for(	hwi = kojiku->data.hwsp1_v.real,
			p1 = kojiku->data.data_d[10],
			p2 = kojiku->data.data_d[11];
		hwi < kojiku->data.hwsp1_v.real + kojiku->line.line,
			p1 < kojiku->data.data_d[10] + kojiku->line.line,
			p2 < kojiku->data.data_d[11] + kojiku->line.line;
		hwi++,
			p1++,
			p2++){
				*hwi	= pow(  ( ( (*p1) * (*p1) + (*p2) * (*p2) - kojiku->sens.hwsp1.A ) / kojiku->sens.hwsp1.B ),
					(1.0 / kojiku->sens.hwsp1.n)  );
		}//フィルター用作業------------------------------------------------------------------
		for( hwi = kojiku->data.hwsp1_v.real + kojiku->line.line;
			hwi < kojiku->data.hwsp1_v.real + kojiku->line.newline;
			hwi++ ){
				*hwi = kojiku->data.hwsp1_v.real[kojiku->line.line-1];
		}

		//alpha計算------------------------------------------------------------------------------
		for(	
			hwi = kojiku->data.hwsp1_v.real,
			alpha = kojiku->data.hwsp1_alpha.real,
			p1 = kojiku->data.data_d[10],
			p2 = kojiku->data.data_d[11];
		hwi < kojiku->data.hwsp1_v.real + kojiku->line.line,
			alpha < kojiku->data.hwsp1_alpha.real + kojiku->line.line,
			p1 < kojiku->data.data_d[10] + kojiku->line.line,
			p2 < kojiku->data.data_d[11] + kojiku->line.line;
		hwi++,
			alpha++,
			p1++,
			p2++){
				*alpha	= ((*p1) * (*p1) + (*p2) * (*p2) - kojiku->sens.hwsp1.V1 - kojiku->sens.hwsp1.V2 * sqrt( *hwi ))
					/ (kojiku->sens.hwsp1.K1 + kojiku->sens.hwsp1.K2 * sqrt( *hwi));
		}//フィルター用作業------------------------------------------------------------------
		for( alpha = kojiku->data.hwsp1_alpha.real + kojiku->line.line;
			alpha < kojiku->data.hwsp1_alpha.real + kojiku->line.newline;
			alpha++ ){
				*alpha = kojiku->data.hwsp1_alpha.real[kojiku->line.line-1];
		}

		//vaxis計算------------------------------------------------------------------------------
		for(	
			hwi = kojiku->data.hwsp1_v.real,
			alpha = kojiku->data.hwsp1_alpha.real,
			vaxis = kojiku->data.hwsp1_vaxis.real;
		hwi < kojiku->data.hwsp1_v.real + kojiku->line.line,
			alpha < kojiku->data.hwsp1_alpha.real + kojiku->line.line,
			vaxis < kojiku->data.hwsp1_vaxis.real + kojiku->line.line;
		hwi++,
			alpha++,
			vaxis++){
				*vaxis	= (*hwi)*cos((*alpha)*PI/180.0);
		}//フィルター用作業------------------------------------------------------------------
		for(vaxis = kojiku->data.hwsp1_vaxis.real + kojiku->line.line;
			vaxis < kojiku->data.hwsp1_vaxis.real + kojiku->line.newline;
			vaxis++ ){
				*vaxis = kojiku->data.hwsp1_vaxis.real[kojiku->line.line-1];
		}

		//vcir計算------------------------------------------------------------------------------
		for(	
			hwi = kojiku->data.hwsp1_v.real,
			alpha = kojiku->data.hwsp1_alpha.real,
			vcir = kojiku->data.hwsp1_vcir.real;
		hwi < kojiku->data.hwsp1_v.real + kojiku->line.line,
			alpha < kojiku->data.hwsp1_alpha.real + kojiku->line.line,
			vcir < kojiku->data.hwsp1_vcir.real + kojiku->line.line;
		hwi++,
			alpha++,
			vcir++){
				*vcir	= (*hwi)*sin((*alpha)*PI/180.0);
		}//フィルター用作業------------------------------------------------------------------
		for(vcir = kojiku->data.hwsp1_vcir.real + kojiku->line.line;
			vcir < kojiku->data.hwsp1_vcir.real + kojiku->line.newline;
			vcir++ ){
				*vcir = kojiku->data.hwsp1_vcir.real[kojiku->line.line-1];
		}

		//ndiv_vaxis計算------------------------------------------------------------------------------
		//ndiv_vcir計算------------------------------------------------------------------------------
		for(	
			vaxis = kojiku->data.hwsp1_vaxis.real,
			vcir = kojiku->data.hwsp1_vcir.real,
			nd_ax = kojiku->data.hwsp1_ndvaxis.real,
			nd_cir = kojiku->data.hwsp1_ndvcir.real;
		vaxis < kojiku->data.hwsp1_vaxis.real + kojiku->line.line,
			vcir < kojiku->data.hwsp1_vcir.real + kojiku->line.line,
			nd_ax < kojiku->data.hwsp1_ndvaxis.real + kojiku->line.line,
			nd_cir < kojiku->data.hwsp1_ndvcir.real + kojiku->line.line;
		vaxis++,
			alpha++,
			nd_ax++,
			nd_cir++){
				*nd_ax = (*vaxis)/kojiku->atm.Uc;
				*nd_cir = (*vcir)/kojiku->atm.Uc;
		}//フィルター用作業------------------------------------------------------------------
		for(nd_ax = kojiku->data.hwsp1_ndvaxis.real + kojiku->line.line;
			nd_ax < kojiku->data.hwsp1_ndvaxis.real + kojiku->line.newline;
			nd_ax++ ){
				*nd_ax = kojiku->data.hwsp1_ndvaxis.real[kojiku->line.line-1];
		}
		for(nd_cir = kojiku->data.hwsp1_ndvcir.real + kojiku->line.line;
			nd_cir < kojiku->data.hwsp1_ndvcir.real + kojiku->line.newline;
			nd_cir++ ){
				*nd_cir = kojiku->data.hwsp1_ndvcir.real[kojiku->line.line-1];
		}

		//2d_averv計算------------------------------------------------------------------------------
		for(
			averv = kojiku->data.hwsp1_twod_averv.real,
			vaxis = kojiku->data.hwsp1_vaxis.real;
		averv < kojiku->data.hwsp1_twod_averv.real + kojiku->line.line,
			vaxis < kojiku->data.hwsp1_vaxis.real + kojiku->line.line;
		averv++,
			vaxis++){
				if(kojiku->check.check_position_sp == 0){
					*averv = (*vaxis)*(kojiku->sens.kousei.__0);
				}if(kojiku->check.check_position_sp == 2){
					*averv = (*vaxis)*(kojiku->sens.kousei.__2);
				}
		}//フィルター用作業------------------------------------------------------------------
		for(averv = kojiku->data.hwsp1_twod_averv.real + kojiku->line.line;
			averv < kojiku->data.hwsp1_twod_averv.real + kojiku->line.newline;
			averv++){
				*averv = kojiku->data.hwsp1_twod_averv.real[kojiku->line.line-1];
		}

		//2d_phi計算------------------------------------------------------------------------------
		for(
			averv = kojiku->data.hwsp1_twod_averv.real,
			phi = kojiku->data.hwsp1_twod_phi.real;
		averv < kojiku->data.hwsp1_twod_averv.real + kojiku->line.line,
			phi < kojiku->data.hwsp1_twod_phi.real + kojiku->line.line;
		averv++,
			phi++){
				*phi = (*averv)/kojiku->atm.Uc;
		}//フィルター用作業------------------------------------------------------------------
		for(phi = kojiku->data.hwsp1_twod_phi.real + kojiku->line.line;
			phi < kojiku->data.hwsp1_twod_phi.real + kojiku->line.newline;
			phi++){
				*phi = kojiku->data.hwsp1_twod_phi.real[kojiku->line.line-1];
		}

	}
}

//------------------------------------------------------------------------------------------------------------
//スプリット型熱線流速計計算関数(55R57)
//------------------------------------------------------------------------------------------------------------
void Cal_Fwsp2( st_kojiku *kojiku ){

	//変数宣言---------------------------------------------------------------------------------------
	double	*hwi,*alpha, *vaxis, *vcir, *nd_ax, *nd_cir, *averv, *phi;
	double	*p1;
	double	*p2;

	if(kojiku->check.check_filter41_hwsp2_v	==1 || kojiku->check.check_filter42_hwsp2_alpha==1 || kojiku->check.check_filter43_hwsp2_vaxis==1 || kojiku->check.check_filter44_hwsp2_vcir==1 || kojiku->check.check_filter45_ndvaxis2==1 || kojiku->check.check_filter46_ndvcir2==1 || kojiku->check.check_filter47_2daverv2==1 || kojiku->check.check_filter48_2dphi2 ==1 || kojiku->check.check_filter49_2dphi_psi2 ==1
		||kojiku->check.check_rawdata41_hwsp2_v	==1 || kojiku->check.check_rawdata42_hwsp2_alpha==1 || kojiku->check.check_rawdata43_hwsp2_vaxis==1 || kojiku->check.check_rawdata44_hwsp2_vcir==1 || kojiku->check.check_rawdata45_ndvaxis2==1 || kojiku->check.check_rawdata46_ndvcir2==1 || kojiku->check.check_rawdata47_2daverv2==1 || kojiku->check.check_rawdata48_2dphi2 ==1 || kojiku->check.check_rawdata49_2dphi_psi2 ==1
		|| kojiku->check.check_FFTampspec43_hwsp2_vaxis==1 || kojiku->check.check_FFTampspec44_hwsp2_vcir==1){
		////V計算------------------------------------------------------------------------------
		//for(	hwi = kojiku->data.hwsp2_v.real,
		//	p1 = kojiku->data.data_d[1],
		//	p2 = kojiku->data.data_d[6];
		//hwi < kojiku->data.hwsp2_v.real + kojiku->line.line,
		//	p1 < kojiku->data.data_d[1] + kojiku->line.line,
		//	p2 < kojiku->data.data_d[6] + kojiku->line.line;
		//hwi++,
		//	p1++,
		//	p2++){
		//		*hwi	= pow(  ( ( (*p1) * (*p1) + (*p2) * (*p2) - kojiku->sens.hwsp2.A ) / kojiku->sens.hwsp2.B ),
		//			(1.0 / kojiku->sens.hwsp2.n)  );
		//}//フィルター用作業------------------------------------------------------------------
		//for( hwi = kojiku->data.hwsp2_v.real + kojiku->line.line;
		//	hwi < kojiku->data.hwsp2_v.real + kojiku->line.newline;
		//	hwi++ ){
		//		*hwi = kojiku->data.hwsp2_v.real[kojiku->line.line-1];
		//}
		for (
			hwi = kojiku->data.hwsp2_v.real,
			alpha = kojiku->data.hwsp2_alpha.real,
			p1 = kojiku->data.data_d[1],
			p2 = kojiku->data.data_d[6];
			hwi < kojiku->data.hwsp2_v.real + kojiku->line.line,
			alpha < kojiku->data.hwsp2_alpha.real + kojiku->line.line,
			p1 < kojiku->data.data_d[1] + kojiku->line.line,
			p2 < kojiku->data.data_d[6] + kojiku->line.line;
			hwi++,
			alpha++,
			p1++,
			p2++) {
			*hwi = pow((((*p1) * (*p1) + (*p2) * (*p2) - 5.165184527) / 4.29196636), (1.0 / 0.466619429));
			//*alpha	= ((*p1) * (*p1) - (*p2) * (*p2) - kojiku->sens.hwsp2.V1 - kojiku->sens.hwsp2.V2 * sqrt( *hwi )) / (kojiku->sens.hwsp2.K1 + kojiku->sens.hwsp2.K2 * sqrt( *hwi));
			*alpha = ((*p1) * (*p1) - (*p2) * (*p2) - 4.790761534- 0.445032648* sqrt(*hwi)) / (0.002437449+ 0.030530712* sqrt(*hwi));
		}//フィルター用作業------------------------------------------------------------------
		for (hwi = kojiku->data.hwsp2_v.real + kojiku->line.line;
		hwi < kojiku->data.hwsp2_v.real + kojiku->line.newline;
			hwi++) {
			*hwi = kojiku->data.hwsp2_v.real[kojiku->line.line - 1];
		}
		for (alpha = kojiku->data.hwsp2_alpha.real + kojiku->line.line;
		alpha < kojiku->data.hwsp2_alpha.real + kojiku->line.newline;
			alpha++) {
			*alpha = kojiku->data.hwsp2_alpha.real[kojiku->line.line - 1];
		}

		//vaxis計算------------------------------------------------------------------------------
		for(	
			hwi = kojiku->data.hwsp2_v.real,
			alpha = kojiku->data.hwsp2_alpha.real,
			vaxis = kojiku->data.hwsp2_vaxis.real;
		hwi < kojiku->data.hwsp2_v.real + kojiku->line.line,
			alpha < kojiku->data.hwsp2_alpha.real + kojiku->line.line,
			vaxis < kojiku->data.hwsp2_vaxis.real + kojiku->line.line;
		hwi++,
			alpha++,
			vaxis++){
				*vaxis	= (*hwi)*cos((*alpha)*PI/180.0);
		}//フィルター用作業------------------------------------------------------------------
		for(vaxis = kojiku->data.hwsp2_vaxis.real + kojiku->line.line;
			vaxis < kojiku->data.hwsp2_vaxis.real + kojiku->line.newline;
			vaxis++ ){
				*vaxis = kojiku->data.hwsp2_vaxis.real[kojiku->line.line-1];
		}

		//vcir計算------------------------------------------------------------------------------
		for(	
			hwi = kojiku->data.hwsp2_v.real,
			alpha = kojiku->data.hwsp2_alpha.real,
			vcir = kojiku->data.hwsp2_vcir.real;
		hwi < kojiku->data.hwsp2_v.real + kojiku->line.line,
			alpha < kojiku->data.hwsp2_alpha.real + kojiku->line.line,
			vcir < kojiku->data.hwsp2_vcir.real + kojiku->line.line;
		hwi++,
			alpha++,
			vcir++){
				*vcir	= (*hwi)*sin((*alpha)*PI/180.0);
		}//フィルター用作業------------------------------------------------------------------
		for(vcir = kojiku->data.hwsp2_vcir.real + kojiku->line.line;
			vcir < kojiku->data.hwsp2_vcir.real + kojiku->line.newline;
			vcir++ ){
				*vcir = kojiku->data.hwsp2_vcir.real[kojiku->line.line-1];
		}

		//ndiv_vaxis計算------------------------------------------------------------------------------
		//ndiv_vcir計算------------------------------------------------------------------------------
		for(	
			vaxis = kojiku->data.hwsp2_vaxis.real,
			vcir = kojiku->data.hwsp2_vcir.real,
			nd_ax = kojiku->data.hwsp2_ndvaxis.real,
			nd_cir = kojiku->data.hwsp2_ndvcir.real;
		vaxis < kojiku->data.hwsp2_vaxis.real + kojiku->line.line,
			vcir < kojiku->data.hwsp2_vcir.real + kojiku->line.line,
			nd_ax < kojiku->data.hwsp2_ndvaxis.real + kojiku->line.line,
			nd_cir < kojiku->data.hwsp2_ndvcir.real + kojiku->line.line;
		vaxis++,
			alpha++,
			nd_ax++,
			nd_cir++){
				*nd_ax = (*vaxis)/kojiku->atm.Uc;
				*nd_cir = (*vcir)/kojiku->atm.Uc;
		}//フィルター用作業------------------------------------------------------------------
		for(nd_ax = kojiku->data.hwsp2_ndvaxis.real + kojiku->line.line;
			nd_ax < kojiku->data.hwsp2_ndvaxis.real + kojiku->line.newline;
			nd_ax++ ){
				*nd_ax = kojiku->data.hwsp2_ndvaxis.real[kojiku->line.line-1];
		}
		for(nd_cir = kojiku->data.hwsp2_ndvcir.real + kojiku->line.line;
			nd_cir < kojiku->data.hwsp2_ndvcir.real + kojiku->line.newline;
			nd_cir++ ){
				*nd_cir = kojiku->data.hwsp2_ndvcir.real[kojiku->line.line-1];
		}

		//2d_averv計算------------------------------------------------------------------------------
		for(
			averv = kojiku->data.hwsp2_twod_averv.real,
			vaxis = kojiku->data.hwsp2_vaxis.real;
		averv < kojiku->data.hwsp2_twod_averv.real + kojiku->line.line,
			vaxis < kojiku->data.hwsp2_vaxis.real + kojiku->line.line;
		averv++,
			vaxis++){
				if(kojiku->check.check_position_sp == 0){
					*averv = (*vaxis)*(kojiku->sens.kousei.__0);
				}if(kojiku->check.check_position_sp == 2){
					*averv = (*vaxis)*(kojiku->sens.kousei.__2);
				}
		}//フィルター用作業------------------------------------------------------------------
		for(averv = kojiku->data.hwsp2_twod_averv.real + kojiku->line.line;
			averv < kojiku->data.hwsp2_twod_averv.real + kojiku->line.newline;
			averv++){
				*averv = kojiku->data.hwsp2_twod_averv.real[kojiku->line.line-1];
		}

		//2d_phi計算------------------------------------------------------------------------------
		for(
			averv = kojiku->data.hwsp2_twod_averv.real,
			phi = kojiku->data.hwsp2_twod_phi.real;
		averv < kojiku->data.hwsp2_twod_averv.real + kojiku->line.line,
			phi < kojiku->data.hwsp2_twod_phi.real + kojiku->line.line;
		averv++,
			phi++){
				*phi = (*averv)/kojiku->atm.Uc;
		}//フィルター用作業------------------------------------------------------------------
		for(phi = kojiku->data.hwsp2_twod_phi.real + kojiku->line.line;
			phi < kojiku->data.hwsp2_twod_phi.real + kojiku->line.newline;
			phi++){
				*phi = kojiku->data.hwsp2_twod_phi.real[kojiku->line.line-1];
		}

	}
}

//------------------------------------------------------------------------------------------------------------
//タンク静圧上昇計算関数
//------------------------------------------------------------------------------------------------------------
void Cal_Ptank( st_kojiku *kojiku ){

	//変数宣言---------------------------------------------------------------------------------------
	double	*ptank;
	double	*p2;
	double  kosei0 = ( (100.0 - kojiku->sens.kousei.P_0) / kojiku->sens.kousei.P_1) - (kojiku->p_max.p_ave - kojiku->init.pspr);  //100[mmAq]のときのp-maxと校正曲線のx方向のズレ
	double  kosei1 = kosei0 * kojiku->sens.kousei.P_1; //この値だけ縦軸をずらして出力させる.

	//printf("突然ですが%lf\n",kojiku->sens.kousei.P_1);

	if(kojiku->check.check_rawdata51_ptank==1 || kojiku->check.check_filter51_ptank==1){
		//計算------------------------------------------------------------------------------
		for(	ptank = kojiku->data.ptank.real,
			p2 = kojiku->data.data_d[12];
			ptank < kojiku->data.ptank.real + kojiku->line.line,
			p2 < kojiku->data.data_d[12] + kojiku->line.line;
		ptank++,
			p2++ ){
				*ptank = ( *p2 - kojiku->init.wp3E ) * kojiku->sens.wp3E;
				//*pspr = ( kojiku->sens.kousei.P_1 * (*p2 - kojiku->init.pspr) + kojiku->sens.kousei.P_0 + kosei1 )* 9.80665 / 1000.0;//kPa
		}
		//フィルター用作業------------------------------------------------------------------
		for(	ptank = kojiku->data.ptank.real + kojiku->line.line;
			ptank < kojiku->data.ptank.real + kojiku->line.newline;
			ptank++ ){
				*ptank = kojiku->data.ptank.real[kojiku->line.line-1];
		}
	}
}

//------------------------------------------------------------------------------------------------------------
//タンク入り口静圧上昇係数計算関数
//------------------------------------------------------------------------------------------------------------
void Cal_Ptank_psi( st_kojiku *kojiku ){

	//変数宣言---------------------------------------------------------------------------------------
	double	*ptank_psi;
	double	*p2;
	double  *p3;

	if(kojiku->check.check_rawdata52_ptank_psi==1 || kojiku->check.check_filter52_ptank_psi==1){

		//計算------------------------------------------------------------------------------
		for(	ptank_psi = kojiku->data.ptank_psi.real,
			p2 = kojiku->data.data_d[12],
			p3 = kojiku->data.pspr.real;
		ptank_psi < kojiku->data.ptank_psi.real + kojiku->line.line,
			p2 < kojiku->data.data_d[12] + kojiku->line.line,
			p3 < kojiku->data.pspr.real + kojiku->line.line;
		ptank_psi++,
			p2++,
			p3++
			){
				/*				*ptank_psi = kojiku->p_max.mmAq /( kojiku->p_max.p_ave - kojiku->init.pspr ) * ( *p2 - kojiku->init.pspr ); //mmAqで出力
				*ptank_psi = 0.00980665 * (*ptank_psi);		//kPaに単位変換
				*ptank_psi = ( *ptank_psi ) / ( kojiku->atm.dens * kojiku->atm.Uc * kojiku->atm.Uc / 2000.0);	//無次元化*/
				*ptank_psi = *p3 / (kojiku->atm.dens * kojiku->atm.Uc * kojiku->atm.Uc / 2000.0);
		}
		//フィルター用作業------------------------------------------------------------------
		for( ptank_psi = kojiku->data.ptank_psi.real + kojiku->line.line;
			ptank_psi < kojiku->data.ptank_psi.real + kojiku->line.newline;
			ptank_psi++ ){
				*ptank_psi = kojiku->data.ptank_psi.real[kojiku->line.line-1];
		}
	}
}
#include <stdio.h>
#include "イニシャル_定数・構造体定義.h"

//*************************************************************************************************************
//イニシャルプログラムのイニシャル計算関数
//*************************************************************************************************************

//-------------------------------------------------------------------------------------------------------------
//イニシャル計算関数その0
//-------------------------------------------------------------------------------------------------------------

void Calculation_Initial_Step_0(double **data_d,		//計算用データ配列
								double init[10],
								unsigned int ii){		//イニシャル値

	//変数宣言---------------------------------------------------------------------------------------
	int		i;		//行カウンタ
	int		j;		//列カウンタ
	int		a;		//イニシャルデータ配列用カウンタ
	double	sum;	//合計

	//変数宣言---------------------------------------------------------------------------------------
	for( j=4, a=0; j<14, a<10; j++, a++ ){

		sum	= 0.0;

		for( i=0; i<(int)ii; i++ ){
			sum += data_d[j][i];
		}

		init[a] = sum / (double)ii;
	}
}


//-------------------------------------------------------------------------------------------------------------
//イニシャル計算関数その1
//-------------------------------------------------------------------------------------------------------------
void Calculation_Initial_Step_1(double init_0[10],			//イニシャル0
								double init_1[10],			//イニシャル1
								double aver_init[10]){		//2つのイニシャルの平均

	//変数宣言---------------------------------------------------------------------------------------
	int		a;		//イニシャルデータ配列用カウンタ
	double	sum;	//合計


	//変数宣言---------------------------------------------------------------------------------------
	for( a=0; a<10; a++ ){
		sum				= init_0[a] + init_1[a];
		aver_init[a]	= sum / 2.0;
	}

}

//------------------------------------------------------------------------------------------------------------
//軸流速計算関数
//------------------------------------------------------------------------------------------------------------
void Cal_Fwi( st_init *init ){

	//変数宣言---------------------------------------------------------------------------------------
	int i;
	double sum_p = 0.;
	double sum_u = 0.;
	double sum_1 = 0.;
	double sum_2 = 0.;
	double sum_3 = 0.;

	//計算------------------------------------------------------------------------------
	for( i=0; i<(int)init->line.init3; i++ ){
        init->data.data_d3[14][i]  = init->file.sens.hwi_6 * (init->data.data_d3[14][i]) * (init->data.data_d3[14][i]) * (init->data.data_d3[14][i]) * (init->data.data_d3[14][i]) * (init->data.data_d3[14][i]) * (init->data.data_d3[14][i])
			+ init->file.sens.hwi_5 * (init->data.data_d3[14][i]) * (init->data.data_d3[14][i]) * (init->data.data_d3[14][i]) * (init->data.data_d3[14][i]) * (init->data.data_d3[14][i])
			+ init->file.sens.hwi_4 * (init->data.data_d3[14][i]) * (init->data.data_d3[14][i]) * (init->data.data_d3[14][i]) * (init->data.data_d3[14][i])
			+ init->file.sens.hwi_3 * (init->data.data_d3[14][i]) * (init->data.data_d3[14][i]) * (init->data.data_d3[14][i])
			+ init->file.sens.hwi_2 * (init->data.data_d3[14][i]) * (init->data.data_d3[14][i])
			+ init->file.sens.hwi_1 * (init->data.data_d3[14][i])
			+ init->file.sens.hwi_0;
	}
	
	for( i=0; i<(int)init->line.init3; i++ ){
			sum_1 += init->data.data_d3[6][i];
			sum_2 += init->data.data_d3[9][i];
			sum_3 += init->data.data_d3[12][i];
			sum_p += init->data.data_d3[13][i];
			sum_u += init->data.data_d3[14][i];
	}

	init->data.aver_v[0] = sum_p / init->line.init3;
	init->data.aver_v[1] = sum_u / init->line.init3;
	init->data.aver_v[2] = sum_1 / init->line.init3;
	init->data.aver_v[3] = sum_2 / init->line.init3;
	init->data.aver_v[4] = sum_3 / init->line.init3;
}

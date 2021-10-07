//*************************************************************************************************************
//バイナリデータを電圧値に変換する関数
//*************************************************************************************************************

//ライブラリ、自作ヘッダのインクルード
#include	<stdio.h>
#include	 "定数・構造体定義.h"

//-------------------------------------------------------------------------------------------------------------
//「unsigned int型」のバイナリデータから「double型」の電圧値[V]に変換する関数（ポインタ版）
//-------------------------------------------------------------------------------------------------------------
void Int_to_Double( st_kojiku *kojiku ){   //////////////////210611 takahashi修正(各チャンネルのレンジをデータレコーダに合わせた)

	//変数宣言---------------------------------------------------------------------------------------
	unsigned int	**pu1;
	unsigned int	*pu2;
	double			**pd1;
	double			*pd2;

	//変換処理---------------------------------------------------------------------------------------
	for(	pu1 = kojiku->data.data_u,
			pd1 = kojiku->data.data_d;
			pu1 < kojiku->data.data_u + J,
			pd1 < kojiku->data.data_d + J;
			pu1++,
			pd1++
		){

		if ((pu1 == kojiku->data.data_u + 8) && (pd1 == kojiku->data.data_d + 8)) {  //9chのレンジは1V
			for (pu2 = *pu1,
				pd2 = *pd1;
				pu2 < *pu1 + kojiku->line.line,
				pd2 < *pd1 + kojiku->line.line;
				pu2++,
				pd2++
				) {
				if (*pu2 < 0x8000) {
					*pd2 = 1.0 * (double)(*pu2) / (double)0x6000;	//バイナリデータの最大値は0x6000，電圧値の最大値は1.0V
				}
				else {
					*pu2 = (~(*pu2 - 1)) & 0x0000FFFF;	//2の補数
					*pd2 = -1.0 * (double)(*pu2) / (double)0x6000;	//－（マイナス）の場合
				}
			}
		}

		if ((pu1 == kojiku->data.data_u + 12) && (pd1 == kojiku->data.data_d + 12)) {  //13chのレンジは20V
			for (pu2 = *pu1,
				pd2 = *pd1;
				pu2 < *pu1 + kojiku->line.line,
				pd2 < *pd1 + kojiku->line.line;
				pu2++,
				pd2++
				) {
				if (*pu2 < 0x8000) {
					*pd2 = 20.0 * (double)(*pu2) / (double)0x6000;	//バイナリデータの最大値は0x6000，電圧値の最大値は20.0V
				}
				else {
					*pu2 = (~(*pu2 - 1)) & 0x0000FFFF;	//2の補数
					*pd2 = -20.0 * (double)(*pu2) / (double)0x6000;	//－（マイナス）の場合
				}
			}
		}

		if ((pu1 == kojiku->data.data_u + 13) && (pd1 == kojiku->data.data_d + 13)) {  //14chのレンジは20V
			for (pu2 = *pu1,
				pd2 = *pd1;
				pu2 < *pu1 + kojiku->line.line,
				pd2 < *pd1 + kojiku->line.line;
				pu2++,
				pd2++
				) {
				if (*pu2 < 0x8000) {
					*pd2 = 20.0 * (double)(*pu2) / (double)0x6000;	//バイナリデータの最大値は0x6000，電圧値の最大値は20.0V
				}
				else {
					*pu2 = (~(*pu2 - 1)) & 0x0000FFFF;	//2の補数
					*pd2 = -20.0 * (double)(*pu2) / (double)0x6000;	//－（マイナス）の場合
				}
			}
		}

		else {
			for (pu2 = *pu1,
				pd2 = *pd1;
				pu2 < *pu1 + kojiku->line.line,
				pd2 < *pd1 + kojiku->line.line;
				pu2++,
				pd2++
				) {
				if (*pu2 < 0x8000) {
					*pd2 = 5.0 * (double)(*pu2) / (double)0x6000;	//バイナリデータの最大値は0x6000，電圧値の最大値は5.0V
				}
				else {
					*pu2 = (~(*pu2 - 1)) & 0x0000FFFF;	//2の補数
					*pd2 = -5.0 * (double)(*pu2) / (double)0x6000;	//－（マイナス）の場合
				}
			}
		}
	}
}

//-------------------------------------------------------------------------------------------------------------
//「unsigned int型」のバイナリデータから「double型」の電圧値[V]に変換する関数
//-------------------------------------------------------------------------------------------------------------
/*void Int_to_Double( st_kojiku *kojiku ){

	//変数宣言---------------------------------------------------------------------------------------
	unsigned int	i;
	unsigned int	j;


	//変換処理---------------------------------------------------------------------------------------
	for( j=0; j<J; j++ ){
		for( i=0; i<kojiku->line.line; i++ ){

			if( kojiku->data.data_u[j][i] >= 0x8000 ){
				kojiku->data.data_u[j][i]	= ( ~(kojiku->data.data_u[j][i]-1) ) & 0x0000FFFF;
				kojiku->data.data_d[j][i]	= -5.0 * (double)(kojiku->data.data_u[j][i]) / (double)0x6000;
			}else{
				kojiku->data.data_d[j][i]	= 5.0 * (double)(kojiku->data.data_u[j][i]) / (double)0x6000;
			}
		}
	}
}*/
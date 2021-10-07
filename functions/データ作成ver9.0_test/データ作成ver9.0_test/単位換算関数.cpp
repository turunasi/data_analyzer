//*************************************************************************************************************
//「電圧→各値変換」プログラムに於いて、大気状態値を単位換算する関数
//*************************************************************************************************************

//標準ライブラリのインクルード
#include	<stdio.h>
#include	<stdio.h>
#include	<math.h>
#include	"定数・構造体定義.h"

//-------------------------------------------------------------------------------------------------------------
//大気状態値を単位換算する関数
//-------------------------------------------------------------------------------------------------------------
void Unit_Conversion( st_kojiku *kojiku ){
	kojiku->atm.P       = ( kojiku->atm.P_init + kojiku->atm.P_end )/2.0;
	kojiku->atm.P		= kojiku->atm.P * 0.133322;				//実験時大気圧[mmHg]→[kPa]
	kojiku->atm.T		= ( kojiku->atm.T_init + kojiku->atm.T_end )/2.0; 
	kojiku->atm.T		= kojiku->atm.T + 273.15;				//実験時大気温度[℃]→[K]
	kojiku->atm.dens	= kojiku->atm.P / R / kojiku->atm.T;	//実験時空気密度(状態方程式ρ=P/RT)
	kojiku->atm.Uc		= 0.13 * PI * kojiku->atm.Nrev ;//* sqrt( (20.0+273.15) / kojiku->atm.T ); //動翼先端周速度
    	printf("周速度=%lf\n",kojiku->atm.Uc);
	//	printf("P %lf	T %lf	dens %lf \n",kojiku->atm.P,kojiku->atm.T,kojiku->atm.dens);
	//printf("tanikansan%lf\n",kojiku->sens.kousei.P_1);
}
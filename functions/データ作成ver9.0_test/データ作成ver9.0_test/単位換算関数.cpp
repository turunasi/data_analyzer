//*************************************************************************************************************
//�u�d�����e�l�ϊ��v�v���O�����ɉ����āA��C��Ԓl��P�ʊ��Z����֐�
//*************************************************************************************************************

//�W�����C�u�����̃C���N���[�h
#include	<stdio.h>
#include	<stdio.h>
#include	<math.h>
#include	"�萔�E�\���̒�`.h"

//-------------------------------------------------------------------------------------------------------------
//��C��Ԓl��P�ʊ��Z����֐�
//-------------------------------------------------------------------------------------------------------------
void Unit_Conversion( st_kojiku *kojiku ){
	kojiku->atm.P       = ( kojiku->atm.P_init + kojiku->atm.P_end )/2.0;
	kojiku->atm.P		= kojiku->atm.P * 0.133322;				//��������C��[mmHg]��[kPa]
	kojiku->atm.T		= ( kojiku->atm.T_init + kojiku->atm.T_end )/2.0; 
	kojiku->atm.T		= kojiku->atm.T + 273.15;				//��������C���x[��]��[K]
	kojiku->atm.dens	= kojiku->atm.P / R / kojiku->atm.T;	//��������C���x(��ԕ�������=P/RT)
	kojiku->atm.Uc		= 0.13 * PI * kojiku->atm.Nrev ;//* sqrt( (20.0+273.15) / kojiku->atm.T ); //������[�����x
    	printf("�����x=%lf\n",kojiku->atm.Uc);
	//	printf("P %lf	T %lf	dens %lf \n",kojiku->atm.P,kojiku->atm.T,kojiku->atm.dens);
	//printf("tanikansan%lf\n",kojiku->sens.kousei.P_1);
}
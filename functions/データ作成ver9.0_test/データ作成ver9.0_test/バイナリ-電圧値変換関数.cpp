//*************************************************************************************************************
//�o�C�i���f�[�^��d���l�ɕϊ�����֐�
//*************************************************************************************************************

//���C�u�����A����w�b�_�̃C���N���[�h
#include	<stdio.h>
#include	 "�萔�E�\���̒�`.h"

//-------------------------------------------------------------------------------------------------------------
//�uunsigned int�^�v�̃o�C�i���f�[�^����udouble�^�v�̓d���l[V]�ɕϊ�����֐��i�|�C���^�Łj
//-------------------------------------------------------------------------------------------------------------
void Int_to_Double( st_kojiku *kojiku ){   //////////////////210611 takahashi�C��(�e�`�����l���̃����W���f�[�^���R�[�_�ɍ��킹��)

	//�ϐ��錾---------------------------------------------------------------------------------------
	unsigned int	**pu1;
	unsigned int	*pu2;
	double			**pd1;
	double			*pd2;

	//�ϊ�����---------------------------------------------------------------------------------------
	for(	pu1 = kojiku->data.data_u,
			pd1 = kojiku->data.data_d;
			pu1 < kojiku->data.data_u + J,
			pd1 < kojiku->data.data_d + J;
			pu1++,
			pd1++
		){

		if ((pu1 == kojiku->data.data_u + 8) && (pd1 == kojiku->data.data_d + 8)) {  //9ch�̃����W��1V
			for (pu2 = *pu1,
				pd2 = *pd1;
				pu2 < *pu1 + kojiku->line.line,
				pd2 < *pd1 + kojiku->line.line;
				pu2++,
				pd2++
				) {
				if (*pu2 < 0x8000) {
					*pd2 = 1.0 * (double)(*pu2) / (double)0x6000;	//�o�C�i���f�[�^�̍ő�l��0x6000�C�d���l�̍ő�l��1.0V
				}
				else {
					*pu2 = (~(*pu2 - 1)) & 0x0000FFFF;	//2�̕␔
					*pd2 = -1.0 * (double)(*pu2) / (double)0x6000;	//�|�i�}�C�i�X�j�̏ꍇ
				}
			}
		}

		if ((pu1 == kojiku->data.data_u + 12) && (pd1 == kojiku->data.data_d + 12)) {  //13ch�̃����W��20V
			for (pu2 = *pu1,
				pd2 = *pd1;
				pu2 < *pu1 + kojiku->line.line,
				pd2 < *pd1 + kojiku->line.line;
				pu2++,
				pd2++
				) {
				if (*pu2 < 0x8000) {
					*pd2 = 20.0 * (double)(*pu2) / (double)0x6000;	//�o�C�i���f�[�^�̍ő�l��0x6000�C�d���l�̍ő�l��20.0V
				}
				else {
					*pu2 = (~(*pu2 - 1)) & 0x0000FFFF;	//2�̕␔
					*pd2 = -20.0 * (double)(*pu2) / (double)0x6000;	//�|�i�}�C�i�X�j�̏ꍇ
				}
			}
		}

		if ((pu1 == kojiku->data.data_u + 13) && (pd1 == kojiku->data.data_d + 13)) {  //14ch�̃����W��20V
			for (pu2 = *pu1,
				pd2 = *pd1;
				pu2 < *pu1 + kojiku->line.line,
				pd2 < *pd1 + kojiku->line.line;
				pu2++,
				pd2++
				) {
				if (*pu2 < 0x8000) {
					*pd2 = 20.0 * (double)(*pu2) / (double)0x6000;	//�o�C�i���f�[�^�̍ő�l��0x6000�C�d���l�̍ő�l��20.0V
				}
				else {
					*pu2 = (~(*pu2 - 1)) & 0x0000FFFF;	//2�̕␔
					*pd2 = -20.0 * (double)(*pu2) / (double)0x6000;	//�|�i�}�C�i�X�j�̏ꍇ
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
					*pd2 = 5.0 * (double)(*pu2) / (double)0x6000;	//�o�C�i���f�[�^�̍ő�l��0x6000�C�d���l�̍ő�l��5.0V
				}
				else {
					*pu2 = (~(*pu2 - 1)) & 0x0000FFFF;	//2�̕␔
					*pd2 = -5.0 * (double)(*pu2) / (double)0x6000;	//�|�i�}�C�i�X�j�̏ꍇ
				}
			}
		}
	}
}

//-------------------------------------------------------------------------------------------------------------
//�uunsigned int�^�v�̃o�C�i���f�[�^����udouble�^�v�̓d���l[V]�ɕϊ�����֐�
//-------------------------------------------------------------------------------------------------------------
/*void Int_to_Double( st_kojiku *kojiku ){

	//�ϐ��錾---------------------------------------------------------------------------------------
	unsigned int	i;
	unsigned int	j;


	//�ϊ�����---------------------------------------------------------------------------------------
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
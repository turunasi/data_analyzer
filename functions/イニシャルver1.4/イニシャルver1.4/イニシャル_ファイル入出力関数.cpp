//*************************************************************************************************************
//�C�j�V�����v���O�����̃t�@�C���ւ̓��o�͂Ɋւ���֐�
//*************************************************************************************************************

//�W�����C�u�����̃C���N���[�h
#include<stdio.h>
#include"���茋��.h"

//-------------------------------------------------------------------------------------------------------------
//�C�j�V������ǂݍ��ފ֐�
//-------------------------------------------------------------------------------------------------------------
void Read_File(	FILE			*fp_in,			//&fp_in_0  || &fp_in_1
				unsigned int	**data_i,		//&data_i_0 || &data_i_1
				unsigned int	*line){			//&line_0   || &line_1							

	//�ϐ��錾---------------------------------------------------------------------------------------
	int	i;			//�s�J�E���^
	int	j;			//��J�E���^

	//�ǂݍ���----------------------------------------------------------------------------------------
	*line = 0;

	for( i=0; ; i++ ){

		for( j=0; j<16; j++ ){
			fread( &(data_i[j][i]), 2, 1, fp_in );
		}

		//printf("i = %d\n",i);

		if( feof(fp_in) != 0 ){
			break;
		}else{
			(*line)++;
		}
	}

//	printf("%d \n",*line);
}


//-------------------------------------------------------------------------------------------------------------
//�t�@�C���ɏ������ފ֐�
//-------------------------------------------------------------------------------------------------------------
void Write_File1(FILE	**fp_out,			//&fp_out
	double	aver_init[10]) {		//aver_init

//�ϐ��錾---------------------------------------------------------------------------------------
	fprintf(*fp_out, "%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f",
		aver_init[0],
		aver_init[1],
		aver_init[2],
		aver_init[3],
		aver_init[4],
		aver_init[5],
		aver_init[6],
		aver_init[7],
		aver_init[8],
		aver_init[9]);
		//iINITIAL_1A + (aver_init[0] - CORRECT_1A),
		//iINITIAL_1C + (aver_init[1] - CORRECT_1C),
		//iINITIAL_1E + (aver_init[2] - CORRECT_1E),
		//iINITIAL_2A + (aver_init[3] - CORRECT_2A),
		//iINITIAL_2C + (aver_init[4] - CORRECT_2C),
		//iINITIAL_2E + (aver_init[5] - CORRECT_2E),
		//iINITIAL_3A + (aver_init[6] - CORRECT_3A),
		//iINITIAL_3C + (aver_init[7] - CORRECT_3C),
		//iINITIAL_3E + (aver_init[8] - CORRECT_3E),
		//iINITIAL_PP + (aver_init[9] - CORRECT_PP));
}

void Write_File2(FILE	**fp_out,
				 double	aver_init[5]){
	fprintf(*fp_out, "%f\t%f\t%f\t%f\t%f",
		iINITIAL_PP + (aver_init[9] - CORRECT_PP),
						aver_init[1],
						aver_init[2],
						aver_init[3],
						aver_init[4]);
}
				
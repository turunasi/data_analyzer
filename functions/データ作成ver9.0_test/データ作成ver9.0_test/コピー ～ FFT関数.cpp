//���C�u�����A����w�b�_�̃C���N���[�h
#include	<stdlib.h>
#include	<math.h>
#include	"�萔�E�\���̒�`.h"	//����w�b�_
#include	"����֐���`.h"		//����w�b�_



//------------------------------------------------------------------------------------------------------------------------------------------
//FFT���|����֐�
//------------------------------------------------------------------------------------------------------------------------------------------
void FFT( st_kojiku *kojiku ){

	printf("\t\t�����O���ǈ��@1A");
	FFT_IFFT(	kojiku->data.wp1A.real,
				kojiku->data.wp1A.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				1
	);
	printf("�A1C");
	FFT_IFFT(	kojiku->data.wp1C.real,
				kojiku->data.wp1C.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				1
	);
	printf("�A1E");
	FFT_IFFT(	kojiku->data.wp1E.real,
				kojiku->data.wp1E.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				1
	);
	printf("�A2A");
	FFT_IFFT(	kojiku->data.wp2A.real,
				kojiku->data.wp2A.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				1
	);
	printf("�A2C");
	FFT_IFFT(	kojiku->data.wp2C.real,
				kojiku->data.wp2C.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				1
	);
	printf("�A2E");
	FFT_IFFT(	kojiku->data.wp2E.real,
				kojiku->data.wp2E.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				1
	);
	printf("�A3A");
	FFT_IFFT(	kojiku->data.wp3A.real,
				kojiku->data.wp3A.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				1
	);
	printf("�A3C");
	FFT_IFFT(	kojiku->data.wp3C.real,
				kojiku->data.wp3C.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				1
	);
	printf("�A3E\n");
	FFT_IFFT(	kojiku->data.wp3E.real,
				kojiku->data.wp3E.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				1
	);
	printf("\t\t���\�È��㏸\n");
	FFT_IFFT(	kojiku->data.pspr.real,
				kojiku->data.pspr.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				1
	);
	printf("\t\t�����iI�^�M���j\n");
	FFT_IFFT(	kojiku->data.hwi.real,
				kojiku->data.hwi.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				1
	);
	printf("\t\t���\�S���㏸\n");
	FFT_IFFT(	kojiku->data.ptpr.real,
				kojiku->data.ptpr.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				1
	);
	printf("\t\t���k�@�����ώ�����\n");
	FFT_IFFT(	kojiku->data.averv.real,
				kojiku->data.averv.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				1
	);
	printf("\t\t�S���㏸�W��\n");
	FFT_IFFT(	kojiku->data.phi.real,
				kojiku->data.phi.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				1
	);
	printf("\t\t���ʌW��\n");
	FFT_IFFT(	kojiku->data.psi.real,
				kojiku->data.psi.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				1
	);
	//printf("\t\t��Η����iSprit�^�M���j\n");
	//FFT_IFFT(	kojiku->data.hwsp_v.real,
	//			kojiku->data.hwsp_v.imag,
	//			kojiku->line.newline,
	//			kojiku->line.log2,
	//			1
	//);
	//printf("\t\t����p�iSprit�^�M���j\n");
	//FFT_IFFT(	kojiku->data.hwsp_alpha.real,
	//			kojiku->data.hwsp_alpha.imag,
	//			kojiku->line.newline,
	//			kojiku->line.log2,
	//			1
	//);
	//printf("\t\t�����������iSprit�^�M���j\n");
	//FFT_IFFT(	kojiku->data.hwsp_vaxis.real,
	//			kojiku->data.hwsp_vaxis.imag,
	//			kojiku->line.newline,
	//			kojiku->line.log2,
	//			1
	//);
	//printf("\t\t�����������iSprit�^�M���j\n");
	//FFT_IFFT(	kojiku->data.hwsp_vcir.real,
	//			kojiku->data.hwsp_vcir.imag,
	//			kojiku->line.newline,
	//			kojiku->line.log2,
	//			1
	//);

/*	printf("\t\t�����������������iSprit�^�M���j\n");
	FFT_IFFT(	kojiku->data.hwsp_ndvaxis.real,
				kojiku->data.hwsp_ndvaxis.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				1
	);
	printf("\t\t�����������iSprit�^�M���j\n");
	FFT_IFFT(	kojiku->data.hwsp_ndvcir.real,
				kojiku->data.hwsp_ndvcir.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				1
	);*/
}



//------------------------------------------------------------------------------------------------------------------------------------------
//IFFT���|����֐�
//------------------------------------------------------------------------------------------------------------------------------------------
void IFFT( st_kojiku *kojiku ){

	printf("\t\t�����O���ǈ��@1A");
	FFT_IFFT(	kojiku->data.wp1A.real,
				kojiku->data.wp1A.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				0
	);
	printf("�A1C");
	FFT_IFFT(	kojiku->data.wp1C.real,
				kojiku->data.wp1C.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				0
	);
	printf("�A1E");
	FFT_IFFT(	kojiku->data.wp1E.real,
				kojiku->data.wp1E.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				0
	);
	printf("�A2A");
	FFT_IFFT(	kojiku->data.wp2A.real,
				kojiku->data.wp2A.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				0
	);
	printf("�A2C");
	FFT_IFFT(	kojiku->data.wp2C.real,
				kojiku->data.wp2C.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				0
	);
	printf("�A2E");
	FFT_IFFT(	kojiku->data.wp2E.real,
				kojiku->data.wp2E.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				0
	);
	printf("�A3A");
	FFT_IFFT(	kojiku->data.wp3A.real,
				kojiku->data.wp3A.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				0
	);
	printf("�A3C");
	FFT_IFFT(	kojiku->data.wp3C.real,
				kojiku->data.wp3C.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				0
	);
	printf("�A3E\n");
	FFT_IFFT(	kojiku->data.wp3E.real,
				kojiku->data.wp3E.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				0
	);
	printf("\t\t���\�È��㏸\n");
	FFT_IFFT(	kojiku->data.pspr.real,
				kojiku->data.pspr.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				0
	);
	printf("\t\t�����iI�^�M���j\n");
	FFT_IFFT(	kojiku->data.hwi.real,
				kojiku->data.hwi.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				0
	);
	printf("\t\t���\�S���㏸\n");
	FFT_IFFT(	kojiku->data.ptpr.real,
				kojiku->data.ptpr.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				0
	);
	printf("\t\t���k�@�����ώ�����\n");
	FFT_IFFT(	kojiku->data.averv.real,
				kojiku->data.averv.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				0
	);
	printf("\t\t�S���㏸�W��\n");
	FFT_IFFT(	kojiku->data.phi.real,
				kojiku->data.phi.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				0
	);
	printf("\t\t���ʌW��\n");
	FFT_IFFT(	kojiku->data.psi.real,
				kojiku->data.psi.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				0
	);
	/*printf("\t\t��Η����iSprit�^�M���j\n");
	FFT_IFFT(	kojiku->data.hwsp_v.real,
				kojiku->data.hwsp_v.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				0
	);
	printf("\t\t����p�iSprit�^�M���j\n");
	FFT_IFFT(	kojiku->data.hwsp_alpha.real,
				kojiku->data.hwsp_alpha.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				0
	);
	printf("\t\t�����������iSprit�^�M���j\n");
	FFT_IFFT(	kojiku->data.hwsp_vaxis.real,
				kojiku->data.hwsp_vaxis.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				0
	);
	printf("\t\t�����������iSprit�^�M���j\n");
	FFT_IFFT(	kojiku->data.hwsp_vcir.real,
				kojiku->data.hwsp_vcir.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				0
	);*/
/*	printf("\t\t�����������������iSprit�^�M���j\n");
	FFT_IFFT(	kojiku->data.hwsp_ndvaxis.real,
				kojiku->data.hwsp_ndvaxis.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				0
	);
	printf("\t\t�����������������iSprit�^�M���j\n");
	FFT_IFFT(	kojiku->data.hwsp_ndvcir.real,
				kojiku->data.hwsp_ndvcir.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				0
	);*/
}



//------------------------------------------------------------------------------------------------------------------------------------------
//�w����g������������֐�
//------------------------------------------------------------------------------------------------------------------------------------------
void Cut_Freq_All( st_kojiku *kojiku ){

	Cut_Freq(	kojiku->data.wp1A.real,
				kojiku->data.wp1A.imag,
				kojiku->freq.cut1,
				kojiku->line.newline
	);
	Cut_Freq(	kojiku->data.wp1C.real,
				kojiku->data.wp1C.imag,
				kojiku->freq.cut1,				
				kojiku->line.newline
	);
	Cut_Freq(	kojiku->data.wp1E.real,
				kojiku->data.wp1E.imag,
				kojiku->freq.cut1,
				kojiku->line.newline
	);
	Cut_Freq(	kojiku->data.wp2A.real,
				kojiku->data.wp2A.imag,
				kojiku->freq.cut1,
				kojiku->line.newline
	);
	Cut_Freq(	kojiku->data.wp2C.real,
				kojiku->data.wp2C.imag,
				kojiku->freq.cut1,
				kojiku->line.newline
	);
	Cut_Freq(	kojiku->data.wp2E.real,
				kojiku->data.wp2E.imag,
				kojiku->freq.cut1,
				kojiku->line.newline
	);
	Cut_Freq(	kojiku->data.wp3A.real,
				kojiku->data.wp3A.imag,
				kojiku->freq.cut1,
				kojiku->line.newline
	);
	Cut_Freq(	kojiku->data.wp3C.real,
				kojiku->data.wp3C.imag,
				kojiku->freq.cut1,
				kojiku->line.newline
	);
	Cut_Freq(	kojiku->data.wp3E.real,
				kojiku->data.wp3E.imag,
				kojiku->freq.cut1,
				kojiku->line.newline
	);
	Cut_Freq(	kojiku->data.pspr.real,
				kojiku->data.pspr.imag,
				kojiku->freq.cut2,
				kojiku->line.newline
	);
	Cut_Freq(	kojiku->data.hwi.real,
				kojiku->data.hwi.imag,
				kojiku->freq.cut1,
				kojiku->line.newline
	);
	Cut_Freq(	kojiku->data.ptpr.real,
				kojiku->data.ptpr.imag,
				kojiku->freq.cut2,
				kojiku->line.newline
	);
	Cut_Freq(	kojiku->data.averv.real,
				kojiku->data.averv.imag,
				kojiku->freq.cut2,
				kojiku->line.newline
	);
	Cut_Freq(	kojiku->data.psi.real,
				kojiku->data.psi.imag,
				kojiku->freq.cut2,
				kojiku->line.newline
	);
	Cut_Freq(	kojiku->data.phi.real,
				kojiku->data.phi.imag,
				kojiku->freq.cut2,
				kojiku->line.newline
	);
	//Cut_Freq(	kojiku->data.hwsp_v.real,
	//			kojiku->data.hwsp_v.imag,
	//			kojiku->freq.cut1,
	//			kojiku->line.newline
	//);
	//Cut_Freq(	kojiku->data.hwsp_alpha.real,
	//			kojiku->data.hwsp_alpha.imag,
	//			kojiku->freq.cut1,
	//			kojiku->line.newline
	//);
	//Cut_Freq(	kojiku->data.hwsp_vaxis.real,
	//			kojiku->data.hwsp_vaxis.imag,
	//			kojiku->freq.cut1,
	//			kojiku->line.newline
	//);
	//Cut_Freq(	kojiku->data.hwsp_vcir.real,
	//			kojiku->data.hwsp_vcir.imag,
	//			kojiku->freq.cut1,
	//			kojiku->line.newline
	//);

/*	Cut_Freq(	kojiku->data.hwsp_ndvaxis.real,
				kojiku->data.hwsp_ndvaxis.imag,
				kojiku->freq.cut1,
				kojiku->line.newline
	);

	Cut_Freq(	kojiku->data.hwsp_ndvcir.real,
				kojiku->data.hwsp_ndvcir.imag,
				kojiku->freq.cut1,
				kojiku->line.newline
	);*/
}



//------------------------------------------------------------------------------------------------------------------------------------------
//�����̐�Βl�����߂�֐�
//------------------------------------------------------------------------------------------------------------------------------------------
double Abs_Imag(double x, double y){

	return( sqrt( x * x + y * y ) );
}


//------------------------------------------------------------------------------------------------------------------------------------------
//FFT�֐�
//------------------------------------------------------------------------------------------------------------------------------------------
void FFT_IFFT(double x_real[], double x_imag[], unsigned int N, unsigned int log_N, unsigned int sw){

	unsigned int		number_stage, stage;
	unsigned int		i, j, k, n, m, r, *index;
	double			a_real, a_imag, b_real, b_imag, c_real, c_imag, real, imag;

	number_stage = log_N;	//�o�^�t���C���Z�̒i����log2(�f�[�^��)

	//printf("%f %f %f %f\n\n", x_real[32766], x_imag[0], x_real[32767], x_imag[1]);

	//�o�^�t���C���Z
	for(stage=1 ; stage<=number_stage ; stage++){	//�o�^�t���C���Z�̒i��

		for(i=0 ; i<Pow2(stage-1) ; i++){	//�e�i�ɂ�����f�[�^�̃O���[�v��

			for(j=0 ; j<Pow2(number_stage-stage) ; j++){	//�e�i�̃O���[�v���ɂ�����f�[�^�̑g�ݍ��킹��

				n = Pow2(number_stage - stage + 1) * i + j;	//�f�[�^�ԍ�[n]��[m]��g�Ƃ��Čv�Z
				m = n + Pow2(number_stage - stage);			//�f�[�^�ԍ�[n]��[m]��g�Ƃ��Čv�Z

				r = Pow2(stage - 1) * j;	//��]�q�̎���

				a_real = x_real[n];
				a_imag = x_imag[n];
				b_real = x_real[m];
				b_imag = x_imag[m];
				c_real = cos((2.0*PI*r)/N);
				if( sw ){
					c_imag = -sin((2.0*PI*r)/N);
				}else{
					c_imag = +sin((2.0*PI*r)/N);
				}

				if(stage < number_stage){	//�ŏI�i�ȊO
					x_real[n] = a_real + b_real;
					x_imag[n] = a_imag + b_imag;
					x_real[m] = (a_real-b_real)*c_real - (a_imag-b_imag)*c_imag;
					x_imag[m] = (a_imag-b_imag)*c_real + (a_real-b_real)*c_imag;
				}
				else{	//�ŏI�i
					x_real[n] = a_real + b_real;
					x_imag[n] = a_imag + b_imag;
					x_real[m] = a_real - b_real;
					x_imag[m] = a_imag - b_imag;
				}
			}
		}
	}

	//�C���f�b�N�X�̕��ёւ��̂��߂̃e�[�u���쐬
	index = (unsigned int *)calloc(N, sizeof(unsigned int));
	for(stage=1; stage<=number_stage; stage++){
		for(i=0; i<Pow2(stage-1); i++){
			index[Pow2(stage - 1) + i] = index[i] + Pow2(number_stage - stage);
		}
	}

	//�C���f�b�N�X�̕��בւ�
	for(k=0 ; k<N ; k++){
		if(index[k]>k){
			real = x_real[index[k]];
			imag = x_imag[index[k]];
			x_real[index[k]] = x_real[k];
			x_imag[index[k]] = x_imag[k];
			x_real[k] = real;
			x_imag[k] = imag;
		}
	}

	free(index);


	if( !sw ){
		for(double *p=x_real; p<x_real+N; p++ ){
			*p /= (double)N;
		}
	}
}



//------------------------------------------------------------------------------------------------------------------------------------------
//�w����g������������֐�
//------------------------------------------------------------------------------------------------------------------------------------------
void Cut_Freq( double *x_real, double *x_imag, double cutfreq, unsigned int n_newline ){


	//�ϐ��錾------------------------------------------------------------------------------------
	unsigned int	n_array	= (unsigned int)( (double)n_newline * (double)cutfreq / SampFreq );
	double			*p1;
	double			*p2;
		

	//�G���[�΍�----------------------------------------------------------------------------------
	if( cutfreq >= SampFreq/2 ){
		printf("�J�b�g�I�t���g�����T���v�����O���g����1/2��菬�����Ȃ�悤�ɂ��Ă��������B\n");
		printf("�����I�����ĉ������B\n");
		while(1);
	}

	//�w�肳�ꂽ���g���ȏ���J�b�g-----------------------------------------------------------------
	for(	p1 = x_real + n_array,
			p2 = x_imag + n_array;
			p1 <= x_real + n_newline - n_array,
			p2 <= x_imag + n_newline - n_array;
			p1++,
			p2++){
		*p1	= 0.0;
		*p2	= 0.0;
	}
}


//------------------------------------------------------------------------------------------------------------------------------------------
//�U���X�y�N�g�����v�Z����֐�
//------------------------------------------------------------------------------------------------------------------------------------------
void FFT_AmpSpec( st_kojiku *kojiku ){

	//�ϐ��錾---------------------------------------------------------------------------------------
	double	*p1;
	double	*p2;
	double	*p3;
	

	//�ϐ��錾---------------------------------------------------------------------------------------
	for(	p1 = kojiku->data.wp1A.abs,
			p2 = kojiku->data.wp1A.real,
			p3 = kojiku->data.wp1A.imag;
			p1 < kojiku->data.wp1A.abs  + kojiku->line.ampspec,
			p2 < kojiku->data.wp1A.real + kojiku->line.ampspec,
			p3 < kojiku->data.wp1A.imag + kojiku->line.ampspec;
			p1++,
			p2++,
			p3++ ){
		*p1 = Abs_Imag(	*p2, *p3 );
	}
	for(	p1 = kojiku->data.wp2A.abs,
			p2 = kojiku->data.wp2A.real,
			p3 = kojiku->data.wp2A.imag;
			p1 < kojiku->data.wp2A.abs  + kojiku->line.ampspec,
			p2 < kojiku->data.wp2A.real + kojiku->line.ampspec,
			p3 < kojiku->data.wp2A.imag + kojiku->line.ampspec;
			p1++,
			p2++,
			p3++ ){
		*p1 = Abs_Imag(	*p2, *p3 );
	}
	for(	p1 = kojiku->data.wp3A.abs,
			p2 = kojiku->data.wp3A.real,
			p3 = kojiku->data.wp3A.imag;
			p1 < kojiku->data.wp3A.abs  + kojiku->line.ampspec,
			p2 < kojiku->data.wp3A.real + kojiku->line.ampspec,
			p3 < kojiku->data.wp3A.imag + kojiku->line.ampspec;
			p1++,
			p2++,
			p3++ ){
		*p1 = Abs_Imag(	*p2, *p3 );
	}
	for(	p1 = kojiku->data.ptpr.abs,
			p2 = kojiku->data.ptpr.real,
			p3 = kojiku->data.ptpr.imag;
			p1 < kojiku->data.ptpr.abs  + kojiku->line.ampspec,
			p2 < kojiku->data.ptpr.real + kojiku->line.ampspec,
			p3 < kojiku->data.ptpr.imag + kojiku->line.ampspec;
			p1++,
			p2++,
			p3++ ){
		*p1 = Abs_Imag(	*p2, *p3 );
	}
	for(	p1 = kojiku->data.hwi.abs,
			p2 = kojiku->data.hwi.real,
			p3 = kojiku->data.hwi.imag;
			p1 < kojiku->data.hwi.abs  + kojiku->line.ampspec,
			p2 < kojiku->data.hwi.real + kojiku->line.ampspec,
			p3 < kojiku->data.hwi.imag + kojiku->line.ampspec;
			p1++,
			p2++,
			p3++ ){
		*p1 = Abs_Imag(	*p2, *p3 );
	}
	/*for(	p1 = kojiku->data.hwsp_vaxis.abs,
			p2 = kojiku->data.hwsp_vaxis.real,
			p3 = kojiku->data.hwsp_vaxis.imag;
			p1 < kojiku->data.hwsp_vaxis.abs  + kojiku->line.ampspec,
			p2 < kojiku->data.hwsp_vaxis.real + kojiku->line.ampspec,
			p3 < kojiku->data.hwsp_vaxis.imag + kojiku->line.ampspec;
			p1++,
			p2++,
			p3++ ){
		*p1 = Abs_Imag(	*p2, *p3 );
	}
	for(	p1 = kojiku->data.hwsp_vcir.abs,
			p2 = kojiku->data.hwsp_vcir.real,
			p3 = kojiku->data.hwsp_vcir.imag;
			p1 < kojiku->data.hwsp_vcir.abs  + kojiku->line.ampspec,
			p2 < kojiku->data.hwsp_vcir.real + kojiku->line.ampspec,
			p3 < kojiku->data.hwsp_vcir.imag + kojiku->line.ampspec;
			p1++,
			p2++,
			p3++ ){
		*p1 = Abs_Imag(	*p2, *p3 );
	}*/
}



//------------------------------------------------------------------------------------------------------------------------------------------
//�U���X�y�N�g���̎��g�������v�Z����֐�
//------------------------------------------------------------------------------------------------------------------------------------------
void Axis_AmpSpec( st_kojiku *kojiku ){

	//�ϐ��錾---------------------------------------------------------------------------------------
	unsigned int	i;
	double			*p;

	//���g�����̌v�Z---------------------------------------------------------------------------------
	for(	i = 0,
			p = kojiku->freq.axis_ampspec;
			i < kojiku->line.ampspec,
			p < kojiku->freq.axis_ampspec + kojiku->line.ampspec;
			i++,
			p++ ){
		*p = (double)i * SampFreq / (double)kojiku->line.newline;
	}
}
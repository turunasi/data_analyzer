//*************************************************************************************************************
//�萔�y�э\���̒�`
//*************************************************************************************************************

#include	<stdio.h>

//-------------------------------------------------------------------------------------------------------------
//�萔��`
//-------------------------------------------------------------------------------------------------------------
#define		I			( 1<<23 )					//�z��̍s���i2�O21�s�A�܂��22�b���ɏ���Ɍ��߂��j	//210831 1<<23�ɂ���������������
#define		J			( 16 )						//�z��̗񐔁i�f�[�^���R�[�_�[�̎d�l��A16��j
#define		PI			( 3.1415926535 )			//�~����
#define		P0			( 101.325 )					//�W����C��
#define		T0			( 273.15+20.0 )				//�W����C���x�i20[��]�j
#define		R			( 0.287 )					//��C�̋C�̒萔
#define		SampFreq	( 96000.0 )					//�f�[�^���R�[�_�̃T���v�����O���g��
//#define		Nrev		( 200.0 )					//��]��
//#define		U			( 0.13 * PI * Nrev )		//�������[���x

//-------------------------------------------------------------------------------------------------------------
//�\����
//-------------------------------------------------------------------------------------------------------------
struct st_kojiku{

	//�t�@�C���Ɋւ���\����------------------------------------------------------------------------------
	struct{

		struct{

			FILE		*init;			//�C�j�V����
			FILE		*in;			//����
			FILE		*p_max;	//�v�`�e�X�g

			struct{
				FILE	*rawdata;		//�ǈ�1A���f�[�^
				FILE	*filter;		//�ǈ�1A�t�B���^
				FILE	*ampspec;		//�ǈ�1A�U���X�y�N�g��
			}wp1A;

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}wp1C;

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}wp1E;

			struct{
				FILE	*rawdata;
				FILE	*filter;
				FILE	*ampspec;
			}wp2A;

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}wp2C;

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}wp2E;

			struct{
				FILE	*rawdata;
				FILE	*filter;
				FILE	*ampspec;
			}wp3A;

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}wp3C;

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}wp3E;

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}pspr;					//���\�ǈ��㏸

			struct{
				FILE	*rawdata;
				FILE	*filter;
				FILE	*ampspec;
			}hwi;					//�������i�M��I�^�j

			struct{
				FILE	*rawdata;
				FILE	*filter;
				FILE	*ampspec;
			}ptpr;					//���\�S���㏸

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}averv;					//���k�@�����ώ�����

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}psi;					//�S���㏸�W����

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}phi;					//���ʌW����

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}phi2;					//����������ph2

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}phi3;					//����������phi3

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}psi_s;					//�È��㏸�W����s

			struct{
				FILE	*rawdata;
				FILE	*filter;
				FILE	*ampspec;
			}hwi2;				//��������iI�^�M���j

			struct{
				FILE	*rawdata;
				FILE	*filter;
				FILE	*ampspec;
			}hwi3;				//��������iI�^�M���j

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}phi_psi;				//��-��

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}phi_psi_s;				//��-�Ձi�È��㏸�W���j

			struct{
				FILE	*rawdata;
			}valve;

			struct{
				FILE	*rawdata;
			}dpdt;

			struct{
				FILE	*rawdata;
			}dqdt;

			struct {
				FILE	*rawdata;
			}plunge;

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}hwsp1_v;				//��Η����i�X�v���b�g�^�M���j

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}hwsp1_alpha;			//����p�i�X�v���b�g�^�M���j

			struct{
				FILE	*rawdata;
				FILE	*filter;
				FILE	*ampspec;
			}hwsp1_vaxis;			//�����������i�X�v���b�g�^�M���j

			struct{
				FILE	*rawdata;
				FILE	*filter;
				FILE	*ampspec;
			}hwsp1_vcir;				//�����������i�X�v���b�g�^�M���j

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}hwsp1_ndvaxis;			//�����������������i�X�v���b�g�^�M���j

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}hwsp1_ndvcir;			//�����������������i�X�v���b�g�^�M���j

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}hwsp1_twod_averv;				//2d���ώ�����

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}hwsp1_twod_phi;				//2d��

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}hwsp1_twod_phi_psi;				//2d��-��

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}hwsp2_v;				//��Η����i�X�v���b�g�^�M���j

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}hwsp2_alpha;			//����p�i�X�v���b�g�^�M���j

			struct{
				FILE	*rawdata;
				FILE	*filter;
				FILE	*ampspec;
			}hwsp2_vaxis;			//�����������i�X�v���b�g�^�M���j

			struct{
				FILE	*rawdata;
				FILE	*filter;
				FILE	*ampspec;
			}hwsp2_vcir;				//�����������i�X�v���b�g�^�M���j

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}hwsp2_ndvaxis;			//�����������������i�X�v���b�g�^�M���j

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}hwsp2_ndvcir;			//�����������������i�X�v���b�g�^�M���j

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}hwsp2_twod_averv;				//2d���ώ�����

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}hwsp2_twod_phi;				//2d��

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}hwsp2_twod_phi_psi;				//2d��-��

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}ptank;				//Ptank

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}ptank_psi;				//Ptank_psi

		}fp;

		struct{
			unsigned int	init1;		//�C�j�V�����ԍ�1
			unsigned int	init2;		//�C�j�V�����ԍ�2
			unsigned int	data;		//���̓t�@�C���ԍ�
			unsigned int	p_max;	//�v�`�e�X�g�ԍ�
		}num;

		struct{
			char			*init;			//�C�j�V�����t�@�C���̏ꏊ
			char			*in;			//���̓t�@�C���̏ꏊ
			char			*out;			//�o�̓t�@�C���̏ꏊ
			char			*p_max;	//�v�`�e�X�g�t�@�C���̏ꏊ
		}posit;

		char posit_num_dir[256];
	}file;


	//�f�[�^�Ɋւ���\����------------------------------------------------------------------------------
	struct{

		unsigned int	**data_u;		//�o�C�i���f�[�^�i�[�p�z��
		double			**data_d;		//�d���l�ϊ��f�[�^�i�[�p�z��

		struct{							//�ǈ�1A
			double	*real;				//�i�����j
			double	*imag;				//�i�����j
			double	*abs;				//�i��Βl�j
		}wp1A;
		struct{							//�ȉ��ǈ�
			double	*real;
			double	*imag;
		}wp1C;
		struct{
			double	*real;
			double	*imag;
		}wp1E;
		struct{
			double	*real;
			double	*imag;
			double	*abs;
		}wp2A;
		struct{
			double	*real;
			double	*imag;
		}wp2C;
		struct{
			double	*real;
			double	*imag;
		}wp2E;
		struct{
			double	*real;
			double	*imag;
			double	*abs;
		}wp3A;
		struct{
			double	*real;
			double	*imag;
		}wp3C;
		struct{
			double	*real;
			double	*imag;
		}wp3E;

		struct{							//���\�È��㏸
			double	*real;
			double	*imag;
		}pspr;

		struct{							//�������i�M��I�^�j
			double	*real;
			double	*imag;
			double	*abs;
		}hwi;

		struct{							//��������iI�^�M���j
			double *real;
			double *imag;
			double *abs;
		}hwi2;

		struct{							//��������iI�^�M���j
			double *real;
			double *imag;
			double *abs;
		}hwi3;

		struct{							//���\�S���㏸
			double	*real;
			double	*imag;
			double	*abs;
		}ptpr;

		struct{							//���k�@�����ώ�����
			double	*real;
			double	*imag;
		}averv;

		struct{							//�S���㏸�W����
			double	*real;
			double	*imag;
		}psi;

		struct{							//���ʌW����
			double	*real;
			double	*imag;
		}phi;

		struct{
			double  *real;
			double	*imag;
		}phi2;

		struct{
			double  *real;
			double	*imag;
		}phi3;

		struct{							//�È��㏸�W����s
			double	*real;
			double	*imag;
		}psi_s;							

		struct{							//�o���u�J��
			double *real;
		}valve;

		struct {							//���j�g�`
			double *real;
		}plunge;

		struct{							//dp/dt�v�Z�֐��p
			double *real;
		}dpdt;

		struct{							//dq/dt�v�Z�֐��p
			double *real;
		}dqdt;

		struct{							//��Η����i�X�v���b�g�^�M���j
			double	*real;
			double	*imag;
		}hwsp1_v;

		struct{							//����p�i�X�v���b�g�^�M���j
			double	*real;
			double	*imag;
		}hwsp1_alpha;

		struct{							//�����������i�X�v���b�g�^�M���j
			double	*real;
			double	*imag;
			double	*abs;
		}hwsp1_vaxis;

		struct{							//�����������i�X�v���b�g�^�M���j
			double	*real;
			double	*imag;
			double	*abs;
		}hwsp1_vcir;

		struct{							//�����������������i�X�v���b�g�^�M���j
			double *real;
			double *imag;
		}hwsp1_ndvaxis;

		struct{							//�����������������i�X�v���b�g�^�M���j
			double *real;
			double *imag;
		}hwsp1_ndvcir;

		struct{							//2d���ώ�����
			double	*real;
			double	*imag;
		}hwsp1_twod_averv;

		struct{							//2d��
			double	*real;
			double	*imag;
		}hwsp1_twod_phi;							

		struct{							//��Η����i�X�v���b�g�^�M���j
			double	*real;
			double	*imag;
		}hwsp2_v;

		struct{							//����p�i�X�v���b�g�^�M���j
			double	*real;
			double	*imag;
		}hwsp2_alpha;

		struct{							//�����������i�X�v���b�g�^�M���j
			double	*real;
			double	*imag;
			double	*abs;
		}hwsp2_vaxis;

		struct{							//�����������i�X�v���b�g�^�M���j
			double	*real;
			double	*imag;
			double	*abs;
		}hwsp2_vcir;

		struct{							//�����������������i�X�v���b�g�^�M���j
			double *real;
			double *imag;
		}hwsp2_ndvaxis;

		struct{							//�����������������i�X�v���b�g�^�M���j
			double *real;
			double *imag;
		}hwsp2_ndvcir;

		struct{							//2d���ώ�����
			double	*real;
			double	*imag;
		}hwsp2_twod_averv;

		struct{							//2d��
			double	*real;
			double	*imag;
		}hwsp2_twod_phi;				

		struct{
			double	*real;
			double	*imag;
		}ptank;				//Ptank

		struct{
			double	*real;
			double	*imag;
		}ptank_psi;		//Ptank_psi

	}data;

	//�C�j�V�����̍\����-------------------------------------------------------------------------------
	struct{
		double	wp1A;
		double	wp1C;
		double	wp1E;
		double	wp2A;
		double	wp2C;
		double	wp2E;
		double	wp3A;
		double	wp3C;
		double	wp3E;
		double	pspr;
	}init;

	//�v�`�e�X�g�t�@�C���̍\����------------------------------------------------------------------------
	struct{
		double p_ave;
		double v_ave;
		double mmAq;
		double mmAq_v;
		double offset;
		double  DA1;
		double  DA2;
		double	DA3;
	}p_max;

	//�Z���T���x�̍\����--------------------------------------------------------------------------------
	struct{
		double	wp1A;
		double	wp1C;
		double	wp1E;
		double	wp2A;
		double	wp2C;
		double	wp2E;
		double	wp3A;
		double	wp3C;
		double	wp3E;
		double	pspr;

		struct{
			double  __6;
			double	__5;
			double	__4;
			double	__3;
			double	__2;
			double	__1;
			double	__0;
		}hwi;

		struct{
			double  __6;
			double	__5;
			double	__4;
			double	__3;
			double	__2;
			double	__1;
			double	__0;
		}hwi2;

		struct{
			double  __6;
			double	__5;
			double	__4;
			double	__3;
			double	__2;
			double	__1;
			double	__0;
		}hwi3;

		struct{
			double	__2;
			double	__1;
			double	__0;
			double	P_1;
			double	P_0;
		}kousei;					//���ϗ��������߂闬�ʍZ�����i1�����̂��ߌW��2��

		struct{
			double	A;
			double	B;
			double	n;
			double	V1;
			double	V2;
			double	K1;
			double	K2;
		}hwsp1;

		struct{
			double	A;
			double	B;
			double	n;
			double	V1;
			double	V2;
			double	K1;
			double	K2;
		}hwsp2;

	}sens;

	//�s���\����----------------------------------------------------------------------------------------
	struct{
		unsigned int	line;		//�f�[�^�s��
		unsigned int	log2;		//log2( �f�[�^�s�� )�A�J�グ����
		unsigned int	newline;	//2^x�ɏC�������V�����f�[�^�s��
		unsigned int	ampspec;	//�U���X�y�N�g��
	}line;

	//��C����------------------------------------------------------------------------------------------
	struct{
		double	P;		//��������C���i[mmHg]�j
		double  P_init;
		double  P_end;
		double	T;		//��������C���x�i[��]�j
		double	T_init;
		double  T_end;
		double	dens;	//��������C���x
		double	Nrev;	    //������]��
		double	Uc;		 //�����x
	}atm;

	//���g��--------------------------------------------------------------------------------------------
	struct{
		double	*axis_ampspec;
		double	cut1;
		double	cut2;
		double	cut3;
		double	cut4;
	}freq;

	//�o�̓`�F�b�N----------------------------------------------------------------------------------------
	struct{
		int	check_FFTampspec01_1A;
		int	check_FFTampspec04_2A;
		int	check_FFTampspec07_3A;
		int	check_FFTampspec11_hwi;
		int	check_FFTampspec12_ptpr;
		int	check_FFTampspec18_hwi2;
		int	check_FFTampspec25_hwi3;

		int	check_FFTampspec33_hwsp1_vaxis;
		int	check_FFTampspec34_hwsp1_vcir;
		int	check_FFTampspec43_hwsp2_vaxis;
		int	check_FFTampspec44_hwsp2_vcir;

		int	check_filter01_1A;
		int	check_filter02_1C;
		int	check_filter03_1E;
		int	check_filter04_2A;
		int	check_filter05_2C;
		int	check_filter06_2E;
		int	check_filter07_3A;
		int	check_filter08_3C;
		int	check_filter09_3E;
		int	check_filter10_pspr;
		int	check_filter11_hwi;
		int	check_filter12_ptpr;
		int	check_filter13_averv;
		int	check_filter14_psi;
		int	check_filter15_phi;
		int	check_filter18_hwi2;
		int	check_filter20_phi_psi;
		int	check_filter25_hwi3;
		int check_filter13_spsi;	
		int check_filter16_phi_spsi;

		int check_filter31_hwsp1_v	;
		int check_filter32_hwsp1_alpha;
		int check_filter33_hwsp1_vaxis;
		int check_filter34_hwsp1_vcir;
		int check_filter35_ndvaxis1;
		int check_filter36_ndvcir1;
		int check_filter37_2daverv1;
		int check_filter38_2dphi1;
		int check_filter39_2dphi_psi1;

		int check_filter41_hwsp2_v	;
		int check_filter42_hwsp2_alpha;
		int check_filter43_hwsp2_vaxis;
		int check_filter44_hwsp2_vcir;
		int check_filter45_ndvaxis2;
		int check_filter46_ndvcir2;
		int check_filter47_2daverv2;
		int check_filter48_2dphi2;
		int check_filter49_2dphi_psi2;

		int	check_rawdata01_1A;
		int	check_rawdata02_1C;
		int	check_rawdata03_1E;
		int	check_rawdata04_2A;
		int	check_rawdata05_2C;
		int	check_rawdata06_2E;
		int	check_rawdata07_3A;
		int	check_rawdata08_3C;
		int	check_rawdata09_3E;
		int	check_rawdata10_pspr;
		int	check_rawdata11_hwi;
		int	check_rawdata12_ptpr;
		int	check_rawdata13_averv;
		int	check_rawdata14_psi;
		int	check_rawdata15_phi;
		int	check_rawdata18_hwi2;
		int	check_rawdata20_phi_psi;
		int check_rawdata22_valve;
		int check_rawdata_dpdt_dqdt;
		int check_rawdata13_spsi;
		int check_rawdata16_phi_spsi;
		int check_rawdata25_hwi3;
		int	 check_rawdata27_plunge;

		int check_rawdata31_hwsp1_v	;
		int check_rawdata32_hwsp1_alpha;
		int check_rawdata33_hwsp1_vaxis;
		int check_rawdata34_hwsp1_vcir;
		int check_rawdata35_ndvaxis1;
		int check_rawdata36_ndvcir1;
		int check_rawdata37_2daverv1;
		int check_rawdata38_2dphi1;
		int check_rawdata39_2dphi_psi1;

		int check_rawdata41_hwsp2_v	;
		int check_rawdata42_hwsp2_alpha;
		int check_rawdata43_hwsp2_vaxis;
		int check_rawdata44_hwsp2_vcir;
		int check_rawdata45_ndvaxis2;
		int check_rawdata46_ndvcir2;
		int check_rawdata47_2daverv2;
		int check_rawdata48_2dphi2;
		int check_rawdata49_2dphi_psi2;

		int log2check;
		int check_position;
		int check_position_sp;

		int check_rawdata51_ptank;
		int check_rawdata52_ptank_psi;
		int check_filter51_ptank;
		int check_filter52_ptank_psi;

	}check;
};

int Random(void);
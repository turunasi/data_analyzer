#define	I	( 1<<18 )//�z��̍s���i2�O18�s�A�܂��2.7�b���j	
#define	J	( 16 )//�z��̗񐔁i�f�[�^���R�[�_�[�̎d�l��A16��j

struct st_init{
	struct{
		struct{
			unsigned int	__1;		//�C�j�V�����t�@�C���ԍ�0
			unsigned int	__2;		//�C�j�V�����t�@�C���ԍ�1
			unsigned int	__3;		//���͏C���C�j�V����
		}num;

		struct{
			char	*in;				//���̓t�@�C���̃p�X
			char	*out;				//�o�̓t�@�C���̃p�X
		}posit;
	
		struct{
			FILE	*in1;				//���̓t�@�C���|�C���^0
			FILE	*in2;				//���̓t�@�C���|�C���^1
			FILE	*in3;
			FILE	*out1;
			FILE	*out2;				//�o�̓t�@�C���|�C���^
		}fp;
		struct{
			double  hwi_6;
			double	hwi_5;
			double	hwi_4;
			double	hwi_3;
			double	hwi_2;
			double	hwi_1;
			double  hwi_0;
		}sens;							//�M�������v���x
	}file;

	//�f�[�^------------------------------------
	struct{		
		unsigned int	**data_u1;			//�o�C�i���f�[�^�i�[�p�z��0
		unsigned int	**data_u2;			//�o�C�i���f�[�^�i�[�p�z��1
		unsigned int	**data_u3;
		double			**data_d1;			//�v�Z�p�z��0
		double			**data_d2;			//�v�Z�p�z��1
		double			**data_d3;			//�v�Z�p�z��2
		double			init1[10];			//�C�j�V����0�i1A�`3E�A���\�È���10�v�f�j
		double			init2[10];			//�C�j�V����1�i1A�`3E�A���\�È���10�v�f�j
		double			init3[2];			//���\�È��C�����̂Q�v�f 
		double			aver_init12[10];	//�C�j�V�����̕��ϒl�i1A�`3E�A���\�È���10�v�f�j
		double			aver_v[5];			//���ϓd��+ ���ȑ��֌W��
	}data;

	//�s----------------------------------------
	struct{
		unsigned int	init1;		//�C�j�V�����̍s��0
		unsigned int	init2;		//�C�j�V�����̍s��1
		unsigned int	init3;		//�C�j�V�����̍s��2
	}line;
};
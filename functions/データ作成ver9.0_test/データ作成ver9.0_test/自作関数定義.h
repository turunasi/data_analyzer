//*************************************************************************************************************
//����֐��̒�`
//*************************************************************************************************************

//�R�}���h���C��������ϐ��ɑ�����邽�߂̊֐�
void Substitution_CL( char *[], st_kojiku *);

//���܂��Ȃ��֐�
void Omajinai( st_kojiku * );

//�P�ʊ��Z�֐�
void Unit_Conversion( st_kojiku * );

//�t�@�C���֘A�֐�
void Create_Directory( st_kojiku * );
void Open_File( st_kojiku * );
void Open_File_Init( st_kojiku * );
void Open_File_In( st_kojiku * );
void Open_File_P_Max( st_kojiku * );
void Open_File_Out( FILE **, char *, char [256] ,unsigned int data);
void Close_File( st_kojiku * );
void FUJITAvoid( st_kojiku *kojiku );

//���������蓖�Ċ֐�
void Reserve_Memory_UInt_2D( unsigned int ***, unsigned int ,unsigned int );
void Reserve_Memory_Double_1D( double **, unsigned int );
void Reserve_Memory_INT_1D( int **, unsigned int );
void Reserve_Memory_Double_2D( double ***, unsigned int ,unsigned int );
void Reserve_Memory( st_kojiku * );
void Free_Memory_UInt_2D( unsigned int ***, unsigned int );
void Free_Memory_Double_2D( double ***, unsigned int );
void Free_Memory( st_kojiku * );

//�t�@�C�����o�͊֐�
void Read_File_Init( st_kojiku * );
void Read_P_Max_File( st_kojiku *);
void Read_File_Data( st_kojiku * );
void Write_RawData( st_kojiku * );
void Write_AmpSpec( st_kojiku * );
void Write_Filter( st_kojiku * );
void Write_1( FILE *, double *, unsigned int );
void Write_2( FILE *, double *, double *, unsigned int, unsigned int );

//�����^�o�C�i���l�𕂓������^�d���l�ɕϊ�����֐�
void Int_to_Double( st_kojiku * );

//log2(x)���v�Z����֐�
unsigned int Log2( unsigned int );

//pow(x)���v�Z����֐�
unsigned int Pow2( unsigned int );

//�e�l�v�Z�֐�
void Calculation( st_kojiku * );
void Cal_Wp( st_kojiku * );
void Cal_Pspr( st_kojiku * );
void Cal_Fwi( st_kojiku * );
void Cal_Averv( st_kojiku * );
void Cal_Ptpr( st_kojiku * );
void Cal_Phi( st_kojiku * );
void Cal_Psi( st_kojiku * );
void Cal_Psi_s( st_kojiku *);
void Cal_Fwi2( st_kojiku * );
void Cal_Fwi3(st_kojiku *);
void Cal_Valve( st_kojiku * );
void Cal_dpdt(st_kojiku * );
void Cal_dqdt(st_kojiku * );
void Cal_Plunge(st_kojiku *);
void Cal_Fwsp1(st_kojiku *);
void Cal_Fwsp2(st_kojiku *);
void Cal_Ptank(st_kojiku *);
void Cal_Ptank_psi(st_kojiku *);

//FFT�֘A�֐�
void FFT( st_kojiku * );
void IFFT( st_kojiku * );
void FFT_IFFT(double [], double [], unsigned int, unsigned int, unsigned int );
void FFT_AmpSpec( st_kojiku * );
void Axis_AmpSpec( st_kojiku * );
void Cut_Freq_All( st_kojiku * );
void Cut_Freq( double *, double *, double, double, unsigned int );

//�����̐�Βl�����߂�֐�
double Abs_Imag(double , double );

void Line( st_kojiku * );

void Kakunin( st_kojiku * );
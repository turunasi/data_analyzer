	//__���܂��Ȃ��֐�-------------------------------------------------------
	void Omajinai( st_init * );

	//__�t�@�C���֘A�֐�-----------------------------------------------------
	//____�ǂݍ���
	void Open_File_In(	FILE **,			//&fp_in_0   | &fp_in_1
						char *,				//posit_in_0 | posit_in_1
						unsigned int);		//num_init_0 | num_init_1

	//____��������
	void Open_File_Out(	FILE **,			//*fp_out		
						char *,				//*posit_out
						unsigned int,		//num_init_0
						unsigned int);		//num_init_1

	void Open_File_Out2(FILE **,
						char *,
						unsigned int);	//���͏C���p�C�j�V����

	//__�������֘A�֐�---------------------------------------------------------
	//____�m��
	//______unsigned int �^
	void Reserve_Memory_Int(unsigned int ***,	//&data_i_0 || &data_i_1
							unsigned int,				//ii
							unsigned int);				//jj
	
	//______double �^
	void Reserve_Memory_Double(	double ***,		//&data_d_0 || &data_d_1
								unsigned int,			//ii
								unsigned int);			//jj

	//____�J��
	//______unsigned int �^
	void Free_Memory_Int(	unsigned int ***,	//&data_i_0 || &data_i_1
							unsigned int);				//jj

	//______double �^
	void Free_Memory_Double(double ***,		//&data_d_0 || &data_d_1
							unsigned int);			//jj

	//__�t�@�C������ǂݍ��ފ֐��@���łɍs��������------------------------------
	void Read_File(	FILE *,					//&fp_in_0  ||�@&fp_in_1
					unsigned int **,		//&data_i_0 || &data_i_1
					unsigned int *);		//&lines_0  || &lines_1							

	//__�����^�o�C�i���l�𕂓������^�d���l�ɕϊ�����֐�--------------------------
	void Int_to_Double(	unsigned int **,		//&data_i_0 || &data_i_1
						double **,
						unsigned int);			//&data_d_0 || &data_d_1

	//__�C�j�V�����l���v�Z����֐�----------------------------------------------
	//____����1
	void Calculation_Initial_Step_0(double **,		//data_d_0 || data_d_1
									double [10],
									unsigned int);	//init_0 || init_1

	//__�C�j�V�����l���v�Z����֐�
	//____����1
	void Calculation_Initial_Step_1(double [10],	//init_0
									double [10],	//init_1
									double [10]);	//aver_init

	//__�t�@�C���ɏ������ފ֐�-------------------------------------------------
	void Write_File1(FILE **,			//&fp_out
					double [10]);		//aver_init
	void Write_File2(FILE **,			//&fp_out
					double [1]);		//aver_init

	//I�^�����v�Z�֐�----------------------------------------------------------
	void Cal_Fwi( st_init * );

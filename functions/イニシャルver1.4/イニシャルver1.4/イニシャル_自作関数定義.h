	//__おまじない関数-------------------------------------------------------
	void Omajinai( st_init * );

	//__ファイル関連関数-----------------------------------------------------
	//____読み込み
	void Open_File_In(	FILE **,			//&fp_in_0   | &fp_in_1
						char *,				//posit_in_0 | posit_in_1
						unsigned int);		//num_init_0 | num_init_1

	//____書き込み
	void Open_File_Out(	FILE **,			//*fp_out		
						char *,				//*posit_out
						unsigned int,		//num_init_0
						unsigned int);		//num_init_1

	void Open_File_Out2(FILE **,
						char *,
						unsigned int);	//圧力修正用イニシャル

	//__メモリ関連関数---------------------------------------------------------
	//____確保
	//______unsigned int 型
	void Reserve_Memory_Int(unsigned int ***,	//&data_i_0 || &data_i_1
							unsigned int,				//ii
							unsigned int);				//jj
	
	//______double 型
	void Reserve_Memory_Double(	double ***,		//&data_d_0 || &data_d_1
								unsigned int,			//ii
								unsigned int);			//jj

	//____開放
	//______unsigned int 型
	void Free_Memory_Int(	unsigned int ***,	//&data_i_0 || &data_i_1
							unsigned int);				//jj

	//______double 型
	void Free_Memory_Double(double ***,		//&data_d_0 || &data_d_1
							unsigned int);			//jj

	//__ファイルから読み込む関数　ついでに行数も勘定------------------------------
	void Read_File(	FILE *,					//&fp_in_0  ||　&fp_in_1
					unsigned int **,		//&data_i_0 || &data_i_1
					unsigned int *);		//&lines_0  || &lines_1							

	//__整数型バイナリ値を浮動小数型電圧値に変換する関数--------------------------
	void Int_to_Double(	unsigned int **,		//&data_i_0 || &data_i_1
						double **,
						unsigned int);			//&data_d_0 || &data_d_1

	//__イニシャル値を計算する関数----------------------------------------------
	//____その1
	void Calculation_Initial_Step_0(double **,		//data_d_0 || data_d_1
									double [10],
									unsigned int);	//init_0 || init_1

	//__イニシャル値を計算する関数
	//____その1
	void Calculation_Initial_Step_1(double [10],	//init_0
									double [10],	//init_1
									double [10]);	//aver_init

	//__ファイルに書き込む関数-------------------------------------------------
	void Write_File1(FILE **,			//&fp_out
					double [10]);		//aver_init
	void Write_File2(FILE **,			//&fp_out
					double [1]);		//aver_init

	//I型流速計算関数----------------------------------------------------------
	void Cal_Fwi( st_init * );

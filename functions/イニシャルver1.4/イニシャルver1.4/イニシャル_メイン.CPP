//************************************************************************************************************
//イニシャル値（実験時大気圧での圧力センサ出力電圧値）を算出するC言語プログラムです。
//メイン関数の引数は以下の通りです。バッチファイルには、実行プログラム名に続いてこの順に数値を入力してください。
//
//1:イニシャル番号1
//2:イニシャル番号2
//3:入力ファイルのパス
//4:出力ファイルのパス
//
//（注意）ファイルのパスを入力する際はプログラムの仕様上、フォルダの区切りは「\」ではなく「/」を用いてください。			
//************************************************************************************************************　

//標準ライブラリのインクルード
#include <stdio.h>
#include <stdlib.h>
#include"イニシャル_定数・構造体定義.h"
#include"イニシャル_自作関数定義.h"

//------------------------------------------------------------------------------------------------------------
//メイン関数
//------------------------------------------------------------------------------------------------------------
int main(int argc, char *argv[]){	

	//変数宣言（構造体）-----------------------------------------------------------------------------------
	st_init	init;

//	if(argc != 13){printf("%d...error\n",argc);}
	//コマンドラインからの引数を各変数に代入--------------------------------------------------------
	init.file.num.__1	 = atoi(argv[1]);	//文字列をint型に型変換
	init.file.num.__2	 = atoi(argv[2]);
	init.file.posit.in	 = argv[3];
	init.file.posit.out	 = argv[4];
	init.file.sens.hwi_5 = atof(argv[5]);
	init.file.sens.hwi_4 = atof(argv[6]);
	init.file.sens.hwi_3 = atof(argv[7]);
	init.file.sens.hwi_2 = atof(argv[8]);
	init.file.sens.hwi_1 = atof(argv[9]);
	init.file.sens.hwi_0 = atof(argv[10]);
	init.file.num.__3	 = atoi(argv[11]);
	init.file.sens.hwi_6 = atoi(argv[12]);
	//圧力修正イニシャル

	//おまじない----------------------------------------------------------------------------------
	Omajinai( &init );
	
	//ファイルオープン-----------------------------------------------------------------------------
	printf("＜実行状況＞\n");
	printf("\t入出力ファイルオープン・・・\n");

	Open_File_In( &init.file.fp.in1, init.file.posit.in, init.file.num.__1 );
	Open_File_In( &init.file.fp.in2, init.file.posit.in, init.file.num.__2 );
	Open_File_In( &init.file.fp.in3, init.file.posit.in, init.file.num.__3 );
	Open_File_Out( &init.file.fp.out1, init.file.posit.out, init.file.num.__1, init.file.num.__2 );
	Open_File_Out2( &init.file.fp.out2, init.file.posit.out, init.file.num.__3 );

	//メモリ確保-----------------------------------------------------------------------------------
	printf("\tメモリ確保中・・・\n");

	Reserve_Memory_Int( &init.data.data_u1, I,	J );
	Reserve_Memory_Int( &init.data.data_u2, I,	J );
	Reserve_Memory_Int( &init.data.data_u3, I,  J );
	Reserve_Memory_Double( &init.data.data_d1, I, J );
	Reserve_Memory_Double( &init.data.data_d2, I, J );
	Reserve_Memory_Double( &init.data.data_d3, I, J );

	//ファイルより読み込み-------------------------------------------------------------------------
	printf("\tデータ読み込み中・・・\n");

	Read_File( init.file.fp.in1, init.data.data_u1, &init.line.init1 );
	Read_File( init.file.fp.in2, init.data.data_u2, &init.line.init2 );
	Read_File( init.file.fp.in3, init.data.data_u3, &init.line.init3 );

/*	printf("%d \n",init.line.init1);
	printf("%d \n",init.line.init2);
	printf("%d \n",init.line.init3);
	printf("%f \n",init.data.data_d1[15][0]);
	printf("%f \n",init.data.data_d2[15][0]);
	printf("%f \n",init.data.data_d3[15][0]);*/
	
	//データをバイナリから電圧値に変換--------------------------------------------------------------
	printf("\tバイナリデータから電圧値に変換中・・・\n");
	Int_to_Double( init.data.data_u1, init.data.data_d1, init.line.init1 );
	Int_to_Double( init.data.data_u2, init.data.data_d2, init.line.init2 );
	Int_to_Double( init.data.data_u3, init.data.data_d3, init.line.init3 );

	//バイナリデータ用メモリ開放
	Free_Memory_Int( &init.data.data_u1, J);
	Free_Memory_Int( &init.data.data_u2, J);
	Free_Memory_Int( &init.data.data_u3, J);

	//イニシャルを計算-----------------------------------------------------------------------------
	printf("\tイニシャル計算中・・・\n");
	Calculation_Initial_Step_0( init.data.data_d1, init.data.init1, init.line.init1 );
	Calculation_Initial_Step_0( init.data.data_d2, init.data.init2, init.line.init2 );
	Calculation_Initial_Step_1( init.data.init1, init.data.init2, init.data.aver_init12 );
	Cal_Fwi( &init );

	//ファイルへ出力------------------------------------------------------------------------------
	printf("\tファイルへ出力中・・・\n");
	Write_File1( &init.file.fp.out1, init.data.aver_init12 );
	Write_File2( &init.file.fp.out2, init.data.aver_v );
	//メモリー開放---------------------------------------------------------------------------------
	Free_Memory_Double( &init.data.data_d1, J );
	Free_Memory_Double( &init.data.data_d2, J );
	Free_Memory_Double( &init.data.data_d3, J );

	//ファイルを閉じる-----------------------------------------------------------------------------
	fclose( init.file.fp.in1 );
	fclose( init.file.fp.in1 );
	fclose( init.file.fp.in3 );
	fclose( init.file.fp.out1 );
	fclose( init.file.fp.out2 );

	//終了-----------------------------------------------------------------------------------------
	printf("終了\n");

	return(0);
}
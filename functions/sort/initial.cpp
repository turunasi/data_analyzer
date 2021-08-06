//*******************************************************************************************************

// do not warning info about scan functions.
#pragma warning( disable: 4996 )

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<direct.h>

#define POSIT_IN  "C:/Users/small/Desktop/data_analyzer/data/210701"  // input
#define POSIT_OUT "C:/Users/small/Desktop/data_analyzer/data/210701" // output

#define T_STANDBY 0.0 // 立ち上がりまでの秒数
#define FS 96000
#define DEVIDE 105000 // 分割データ数

// 基本的に単数だが,複数ある場合もある. その場合は連続でない.
#define START 1 // ファイル開始No
#define END 1   // ファイル終了No

//*******************************************************************************************************

unsigned int data_u[16][1 << 21]; //バイナリデータ用配列
unsigned int data_count[16][1 << 21];
unsigned int data_temp[1 << 21]; //CH入れ替え用配列

unsigned int damy[16][1];

int main(void) {

	// --------------------------------------------------------------------------------
	// declare variables
	int fn, i, j, limit1 = 0;
	int count = 0;

	static int count_data = 0;

	char *posit_in = POSIT_IN;
	char *posit_out = POSIT_OUT;

	char posit_name_in[100];
	char posit_name_out[100];
	char posit_name_out2[100];
	char posit_name_folda1[150];

	FILE *fp_in, *fp_out, *fp_out2;

	//--------------------------------------------------------------------------------
	// データのオープンと立ち上がり時間分排除
	for (fn = START; fn <= END; fn++) {

		sprintf(posit_name_in, "%s/%08di.DAT", posit_in, fn); // make path
		if ((fp_in = fopen(posit_name_in, "rb")) == NULL) {   // open file
			printf("%s/%08di.DAT is not found.\n", posit_in, fn);
			continue;
		} else {
			printf("%03di.DAT is processing\n", fn);
		}

		//--------------------------------------------------------------------------------
		// count data
		count_data = 0;
		for (i = 0; ; i++) {
			for (j = 0; j < 16; j++) {
				fread(&damy[j][0], 2, 1, fp_in);
			}
			if (i % 96000 == 0) {
				count_data = count_data + 1;
				printf("\t data will be cut into %d num files..\n", count_data);
			}
			//printf("i = %d\n",i);
			if (feof(fp_in) != 0) {
				break; // skip a file which contains nothing.
			}
		}
		fclose(fp_in);

		printf("devined into %d files.\n", count_data);

		//--------------------------------------------------------------------------------
		// make directory
		/*printf("make directory %di\n", count_data);
		sprintf(posit_name_folda1, "%s/%03d", posit_out, fn);
		_mkdir(posit_name_folda1);*/

		sprintf(posit_name_in, "%s/%08di.DAT", posit_in, fn); // make binary path
		if ((fp_in = fopen(posit_name_in, "rb")) == NULL) {   // open path
			printf("%s/%08di.DAT is not found\n", posit_in, fn);
			continue;
		} else {
			printf("%03di.DAT is processing.\n", fn);
		}

		//--------------------------------------------------------------------------------
		// cut in 1sec
		//for (i = 0; i < T_STANDBY * FS; i++) {
		//	for (j = 0; j < 16; j++) {
		//		fread(&data_u[j][i], 2, 1, fp_in);
		//	}
		//}
		//fseek(fp_in, 0L, SEEK_CUR);

		//--------------------------------------------------------------------------------
		// begin to devide
		//for (count = 0; count < count_data; count++) {
		for (count = 0; count < 1; count++) {

			//------------------------------------------------------------------------------
			for (i = 0; i < DEVIDE; i++) {
				for (j = 0; j < 16; j++) {
					fread(&data_u[j][i], 2, 1, fp_in);
				}
			}

			// exchange 2ch to 15ch
			//for (i = 0; i < DEVIDE; i++) {
			//	data_temp[i] = data_u[1][i];
			//	data_u[1][i] = data_u[14][i];
			//	data_u[14][i] = data_temp[i];
			//}

			//fseek(fp_in, 0L, SEEK_CUR);

			//--------------------------------------------------------------------------------
			// write devided data
			sprintf(posit_name_out, "%s/%08di.DAT", posit_out,  fn);  // output
			sprintf(posit_name_out2, "%s/%08di.LOG", posit_out,  fn); // output log
			if ((fp_out = fopen(posit_name_out, "wb")) == NULL) {     // open file
				printf("dat file is not found.\n");
				continue;
			}
			if ((fp_out2 = fopen(posit_name_out2, "w")) == NULL) {    // output log
				printf("log file is not found.\n");
				continue;
			}
			printf("%03d_%03d\n", fn, count + 1);
			printf("\t output %03d_%d.dat\n", fn, count + 1);

			for (i = 0; i < DEVIDE; i++) {
				for (j = 0; j < 16; j++) {
					fwrite(&data_u[j][i], 2, 1, fp_out);
				}
			}
			fclose(fp_out);

			printf("\t output %03d_%d.log\n", fn, count + 1);

			fprintf(fp_out2, "// Sony SIR-1000 data Log file\n");
			fprintf(fp_out2, "// Warning:  Do not modify the contents of this file\n");
			fprintf(fp_out2, "//\n");
			fprintf(fp_out2, "VERSION       	3.2	\n");
			fprintf(fp_out2, "DATA_FILE     	%03di.BIN	\n", count + 1);
			fprintf(fp_out2, "BIT_FILE      	NONE	\n");
			fprintf(fp_out2, "AUX1_FILE     	NONE	\n");
			fprintf(fp_out2, "AUX2_FILE     	NONE	\n");
			fprintf(fp_out2, "FORMAT        	0 INTEL-86	\n");
			fprintf(fp_out2, "VOLUME_CH     	96000	\n");
			fprintf(fp_out2, "FILE_INTVL_CH 	1.041667E-005 s	\n");
			fprintf(fp_out2, "REMARKS       	Remarks.....	\n");
			fprintf(fp_out2, "CHANNEL       	001, \"Ch_001\", Volt, *(2.034505e-004)+(0.000000e+000)	\n");
			fprintf(fp_out2, "CHANNEL       	002, \"Ch_002\", Volt, *(2.034505e-004)+(0.000000e+000)	\n");
			fprintf(fp_out2, "CHANNEL       	003, \"Ch_003\", Volt, *(2.034505e-004)+(0.000000e+000)	\n");
			fprintf(fp_out2, "CHANNEL       	004, \"Ch_004\", Volt, *(2.034505e-004)+(0.000000e+000)	\n");
			fprintf(fp_out2, "CHANNEL       	005, \"Ch_005\", Volt, *(2.034505e-004)+(0.000000e+000)	\n");
			fprintf(fp_out2, "CHANNEL       	006, \"Ch_006\", Volt, *(2.034505e-004)+(0.000000e+000)	\n");
			fprintf(fp_out2, "CHANNEL       	007, \"Ch_007\", Volt, *(2.034505e-004)+(0.000000e+000)	\n");
			fprintf(fp_out2, "CHANNEL       	008, \"Ch_008\", Volt, *(2.034505e-004)+(0.000000e+000)	\n");
			fprintf(fp_out2, "CHANNEL       	009, \"Ch_009\", Volt, *(2.034505e-004)+(0.000000e+000)	\n");
			fprintf(fp_out2, "CHANNEL       	010, \"Ch_010\", Volt, *(2.034505e-004)+(0.000000e+000)	\n");
			fprintf(fp_out2, "CHANNEL       	011, \"Ch_011\", Volt, *(2.034505e-004)+(0.000000e+000)	\n");
			fprintf(fp_out2, "CHANNEL       	012, \"Ch_012\", Volt, *(2.034505e-004)+(0.000000e+000)	\n");
			fprintf(fp_out2, "CHANNEL       	013, \"Ch_013\", Volt, *(2.034505e-004)+(0.000000e+000)	\n");
			fprintf(fp_out2, "CHANNEL       	014, \"Ch_014\", Volt, *(2.034505e-004)+(0.000000e+000)	\n");
			fprintf(fp_out2, "CHANNEL       	015, \"Ch_015\", Volt, *(2.034505e-004)+(0.000000e+000)	\n");
			fprintf(fp_out2, "CHANNEL       	016, \"Ch_016\", Volt, *(2.034505e-004)+(0.000000e+000)	\n");
			fprintf(fp_out2, "//\n");
			fprintf(fp_out2, "// Info. at Data Copy\n");
			fprintf(fp_out2, "//\n");
			fprintf(fp_out2, "TAPE_BC_MODE  	16	\n");
			fprintf(fp_out2, "TAPE_SRATE_CH 	96000 original-samples/s/channel	\n");
			fprintf(fp_out2, "DECIMATION    	0	\n");
			fprintf(fp_out2, "TAPE_SPEED    	1	\n");
			fprintf(fp_out2, "ID            %03di	\n", count + 1);
			fprintf(fp_out2, "DATE_TIME     	20170803 163211	\n");
			fprintf(fp_out2, "CNT_ADDRESS   	0	\n");
			fprintf(fp_out2, "MEMO          	SIR-1000W RECORDER                                                                              	\n");
			fprintf(fp_out2, "TRIG_MODE     	1 ID	\n");
			fprintf(fp_out2, "INPUT_RANGE   	CH_001, 5.00V	\n");
			fprintf(fp_out2, "INPUT_RANGE   	CH_002, 5.00V	\n");
			fprintf(fp_out2, "INPUT_RANGE   	CH_003, 10.00V	\n");
			fprintf(fp_out2, "INPUT_RANGE   	CH_004, 5.00V	\n");
			fprintf(fp_out2, "INPUT_RANGE   	CH_005, 5.00V	\n");
			fprintf(fp_out2, "INPUT_RANGE   	CH_006, 5.00V	\n");
			fprintf(fp_out2, "INPUT_RANGE   	CH_007, 5.00V	\n");
			fprintf(fp_out2, "INPUT_RANGE   	CH_008, 5.00V	\n");
			fprintf(fp_out2, "INPUT_RANGE   	CH_009, 5.00V	\n");
			fprintf(fp_out2, "INPUT_RANGE   	CH_010, 5.00V	\n");
			fprintf(fp_out2, "INPUT_RANGE   	CH_011, 5.00V	\n");
			fprintf(fp_out2, "INPUT_RANGE   	CH_012, 5.00V	\n");
			fprintf(fp_out2, "INPUT_RANGE   	CH_013, 5.00V	\n");
			fprintf(fp_out2, "INPUT_RANGE   	CH_014, 5.00V	\n");
			fprintf(fp_out2, "INPUT_RANGE   	CH_015, 5.00V	\n");
			fprintf(fp_out2, "INPUT_RANGE   	CH_016, 5.00V	\n");

			fclose(fp_out2);

			//fseek(fp_in, 0L, SEEK_CUR);
		}

		fclose(fp_in);

	}

	return 0;
}



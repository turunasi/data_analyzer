//*******************************************************************************************************

// do not warning info about scan functions.
#pragma warning( disable: 4996 )

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<direct.h>

#define POSIT_IN  "F:/Axial21/21data/DAT/210701"  // input
#define POSIT_OUT "F:/Axial21/21data/DAT2/210701" // output

#define T_STANDBY 0.0 // 立ち上がりまでの秒数
#define FS 96000
#define DEVIDE 1050000 // 分割データ数

#define START 2 // ファイル開始No
#define END 22  // ファイル終了No

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

		sprintf(posit_name_in, "%s/%08d.DAT", posit_in, fn); // make path
		if ((fp_in = fopen(posit_name_in, "rb")) == NULL) {   // open file
			printf("%s/%08d.DAT is not found.\n", posit_in, fn);
			continue;
		} else {
			printf("%03d.DAT is processing\n", fn);
		}

		//--------------------------------------------------------------------------------
		// count data
		count_data = 0;
		for (i = 0; ; i++) {
			for (j = 0; j < 16; j++) {
				fread(&damy[j][0], 2, 1, fp_in);
			}
			if ((i % 1050000 == 0) && (i != 0)) {
				count_data = count_data + 1;
				printf("\t data will be cut into %d num files..\n", count_data);
			}
			if (feof(fp_in) != 0) {
				break; // skip a file which contains nothing.
			}
		}
		fclose(fp_in);

		printf("devined into %d files.\n", count_data);

		//--------------------------------------------------------------------------------
		// make directory
		printf("make directory %di\n", count_data);
		sprintf(posit_name_folda1, "%s/%03d", posit_out, fn);
		_mkdir(posit_name_folda1);

		sprintf(posit_name_in, "%s/%08d.DAT", posit_in, fn); // make binary path
		if ((fp_in = fopen(posit_name_in, "rb")) == NULL) {  // open path
			printf("%s/%08di.DAT is not found\n", fn);
			continue;
		} else {
			printf("%03di.DAT is processing.\n", fn);
		}

		//--------------------------------------------------------------------------------
		// cut in 1sec
		for (i = 0; i < T_STANDBY * FS; i++) {
			for (j = 0; j < 16; j++) {
				fread(&data_u[j][i], 2, 1, fp_in);
			}
		}
		fseek(fp_in, 0L, SEEK_CUR);

		//--------------------------------------------------------------------------------
		// begin to devide
		for (count = 0; count <= count_data - 1; count++) {

			//------------------------------------------------------------------------------
			for (i = 0; i < DEVIDE; i++) {
				for (j = 0; j < 16; j++) {
					fread(&data_u[j][i], 2, 1, fp_in);
				}
			}

			// exchange 2ch to 15ch
			//for (i = 0; i < DEVIDE; i++) {

			//	data_temp[i] = data_u[10][i];

			//	data_u[10][i] = data_u[6][i];

			//	data_u[6][i] = data_temp[i];
			//}

			//fseek(fp_in, 0L, SEEK_CUR);

			//--------------------------------------------------------------------------------
			// write devided data
			sprintf(posit_name_out, "%s/%03d/%08d.DAT", posit_out, fn, count + 1);  // output
			sprintf(posit_name_out2, "%s/%03d/%08d.HDR", posit_out, fn, count + 1); // output log
			if ((fp_out = fopen(posit_name_out, "wb")) == NULL) {                   // open file
				printf("dat file is not found.\n");
				continue;
			}
			if ((fp_out2 = fopen(posit_name_out2, "w")) == NULL) {		//���̃t�@�C�����J��.
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

			fprintf(fp_out2, "DATASET %08d\n", count + 1);
			fprintf(fp_out2, "VERSION 1\n");
			fprintf(fp_out2, "SERIES CH1_WX7K_PAAMP,CH2_WX7K_PAAMP,CH3_WX7K_PAAMP,CH4_WX7K_PAAMP,CH5_WX7K_PAAMP,CH6_WX7K_PAAMP,CH7_WX7K_PAAMP,CH8_WX7K_PAAMP,CH9_WX7K_PAAMP,CH10_WX7K_PAAMP,CH11_WX7K_PAAMP,CH12_WX7K_PAAMP,CH13_WX7K_PAAMP,CH14_WX7K_PAAMP,CH15_WX7K_PAAMP,CH16_WX7K_PAAMP\n");
			fprintf(fp_out2, "DATE 10-09-2018\n");
			fprintf(fp_out2, "RATE 96000\n");
			fprintf(fp_out2, "VERT_UNITS V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V\n");
			fprintf(fp_out2, "HORZ_UNITS Sec\n");
			fprintf(fp_out2, "COMMENT WX-7000\n");
			fprintf(fp_out2, "NUM_SERIES 16\n");
			fprintf(fp_out2, "STORAGE_MODE INTERLACED\n");
			fprintf(fp_out2, "FILE_TYPE INTEGER\n");
			fprintf(fp_out2, "SLOPE 2.000000e-04,2.000000e-04,2.000000e-04,2.000000e-04,2.000000e-04,2.000000e-04,2.000000e-04,2.000000e-04,2.000000e-04,2.000000e-04,2.000000e-04,2.000000e-04,8.000000e-04,8.000000e-04,2.000000e-04,2.000000e-04\n");
			fprintf(fp_out2, "X_OFFSET 0.0\n");
			fprintf(fp_out2, "Y_OFFSET 0.000000e+000,0.000000e+000,0.000000e+000,0.000000e+000,0.000000e+000,0.000000e+000,0.000000e+000,0.000000e+000,0.000000e+000,0.000000e+000,0.000000e+000,0.000000e+000,0.000000e+000,0.000000e+000,0.000000e+000,0.000000e+000\n");
			fprintf(fp_out2, "NUM_SAMPS %d\n", DEVIDE);
			fprintf(fp_out2, "DATA\n");
			fprintf(fp_out2, "DEVICE WX-7000\n");
			fprintf(fp_out2, "CH1_1 WX7K_PAAMP,RANGE=5V,DC,OFF,FLAT,OFF\n");
			fprintf(fp_out2, "CH2_2 WX7K_PAAMP,RANGE=5V,DC,OFF,FLAT,OFF\n");
			fprintf(fp_out2, "CH3_3 WX7K_PAAMP,RANGE=5V,DC,OFF,FLAT,OFF\n");
			fprintf(fp_out2, "CH4_4 WX7K_PAAMP,RANGE=5V,DC,OFF,FLAT,OFF\n");
			fprintf(fp_out2, "CH5_5 WX7K_PAAMP,RANGE=5V,DC,OFF,FLAT,OFF\n");
			fprintf(fp_out2, "CH6_6 WX7K_PAAMP,RANGE=5V,DC,OFF,FLAT,OFF\n");
			fprintf(fp_out2, "CH7_7 WX7K_PAAMP,RANGE=5V,DC,OFF,FLAT,OFF\n");
			fprintf(fp_out2, "CH8_8 WX7K_PAAMP,RANGE=5V,DC,OFF,FLAT,OFF\n");
			fprintf(fp_out2, "CH10_10 WX7K_PAAMP,RANGE=5V,DC,OFF,FLAT,OFF\n");
			fprintf(fp_out2, "CH9_9 WX7K_PAAMP,RANGE=5V,DC,OFF,FLAT,OFF\n");
			fprintf(fp_out2, "CH11_11 WX7K_PAAMP,RANGE=5V,DC,OFF,FLAT,OFF\n");
			fprintf(fp_out2, "CH12_12 WX7K_PAAMP,RANGE=5V,DC,OFF,FLAT,OFF\n");
			fprintf(fp_out2, "CH13_13 WX7K_PAAMP,RANGE=20V,DC,OFF,FLAT,OFF\n");
			fprintf(fp_out2, "CH14_14 WX7K_PAAMP,RANGE=20V,DC,OFF,FLAT,OFF\n");
			fprintf(fp_out2, "CH15_15 WX7K_PAAMP,RANGE=5V,DC,OFF,FLAT,OFF\n");
			fprintf(fp_out2, "CH16_16 WX7K_PAAMP,RANGE=5V,DC,OFF,FLAT,OFF\n");
			fprintf(fp_out2, "REC_MODE RDX\n");
			fprintf(fp_out2, "END_TIME 10-09-2018 14:48:04\n");
			fprintf(fp_out2, "START_TRIGGER COMMAND\n");
			fprintf(fp_out2, "STOP_CONDITION COMMAND\n");
			fprintf(fp_out2, "WX-7000_VERSION MAIN_FW:V1.33   , MAIN_FPGA:V1.16, SUB_FW:V1.04   , LCD_FW:V1.14   , AMP_DSP0:V 1.12, AMP_FPGA0:V 1.12, 00022EE091D5,PC\n");

			fclose(fp_out2);

			//fseek(fp_in, 0L, SEEK_CUR);
		}

		fclose(fp_in);

	}

	return 0;
}



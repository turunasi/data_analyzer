//-------------------------------------------------------------------------------------------------------------
//?uint?^?v??o?C?i???f?[?^????udouble?^?v??d???l[V]??????????
//-------------------------------------------------------------------------------------------------------------

//?W?????C?u??????C???N???[?h
#include<stdio.h>

void Int_to_Double(	unsigned int	**data_i,		//?o?C?i???f?[?^?p?z???A?h???X
					double			**data_d,
					unsigned int	ii){		//?v?Z?p?z???A?h???X

	//?????---------------------------------------------------------------------------------------
	unsigned int	i;	//?s?J?E???^
	unsigned int	j;	//??J?E???^

//printf("data_d[7][0]=%f \n",data_d[7][0]);
//printf("data_d[8][0]=%f \n",data_d[8][0]);
//printf("data_d[9][0]=%f \n",data_d[9][0]);

	//?????---------------------------------------------------------------------------------------
	for( j=0; j<16; j++ ){            ////?`?????l???????????W?????????????????D210614
		if (j == 8) {
			for (i = 0; i < ii; i++) {
				if (data_i[j][i] >= 0x8000) {
					data_i[j][i] = (~(data_i[j][i] - 1)) & 0x0000FFFF;
					data_d[j][i] = 1.0 * (double)data_i[j][i] / (double)0x6000;
					data_d[j][i] = -data_d[j][i];
				}
				else {
					data_d[j][i] = 1.0 * (double)data_i[j][i] / (double)0x6000;
					//printf("data_d[%d][%d]=%f \n",j,i,data_d[j][i]);
				}
			}
		}

		if (j == 12) {
			for (i = 0; i < ii; i++) {
				if (data_i[j][i] >= 0x8000) {
					data_i[j][i] = (~(data_i[j][i] - 1)) & 0x0000FFFF;
					data_d[j][i] = 20.0 * (double)data_i[j][i] / (double)0x6000;
					data_d[j][i] = -data_d[j][i];
				}
				else {
					data_d[j][i] = 20.0 * (double)data_i[j][i] / (double)0x6000;
					//printf("data_d[%d][%d]=%f \n",j,i,data_d[j][i]);
				}
			}
		}

		if (j == 13) {
			for (i = 0; i < ii; i++) {
				if (data_i[j][i] >= 0x8000) {
					data_i[j][i] = (~(data_i[j][i] - 1)) & 0x0000FFFF;
					data_d[j][i] = 20.0 * (double)data_i[j][i] / (double)0x6000;
					data_d[j][i] = -data_d[j][i];
				}
				else {
					data_d[j][i] = 20.0 * (double)data_i[j][i] / (double)0x6000;
					//printf("data_d[%d][%d]=%f \n",j,i,data_d[j][i]);
				}
			}
		}

		else {
			for (i = 0; i < ii; i++) {
				if (data_i[j][i] >= 0x8000) {
					data_i[j][i] = (~(data_i[j][i] - 1)) & 0x0000FFFF;
					data_d[j][i] = 5.0 * (double)data_i[j][i] / (double)0x6000;
					data_d[j][i] = -data_d[j][i];
				}
				else {
					data_d[j][i] = 5.0 * (double)data_i[j][i] / (double)0x6000;
					//printf("data_d[%d][%d]=%f \n",j,i,data_d[j][i]);
				}
			}
		}
	}
}
//ライブラリ、自作ヘッダのインクルード
#include	<stdlib.h>
#include	<math.h>
#include	"定数・構造体定義.h"	//自作ヘッダ
#include	"自作関数定義.h"		//自作ヘッダ



//------------------------------------------------------------------------------------------------------------------------------------------
//FFTを掛ける関数
//------------------------------------------------------------------------------------------------------------------------------------------
void FFT( st_kojiku *kojiku ){

	printf("\t\t動翼前縁壁圧　1A");
	FFT_IFFT(	kojiku->data.wp1A.real,
				kojiku->data.wp1A.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				1
	);
	printf("、1C");
	FFT_IFFT(	kojiku->data.wp1C.real,
				kojiku->data.wp1C.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				1
	);
	printf("、1E");
	FFT_IFFT(	kojiku->data.wp1E.real,
				kojiku->data.wp1E.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				1
	);
	printf("、2A");
	FFT_IFFT(	kojiku->data.wp2A.real,
				kojiku->data.wp2A.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				1
	);
	printf("、2C");
	FFT_IFFT(	kojiku->data.wp2C.real,
				kojiku->data.wp2C.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				1
	);
	printf("、2E");
	FFT_IFFT(	kojiku->data.wp2E.real,
				kojiku->data.wp2E.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				1
	);
	printf("、3A");
	FFT_IFFT(	kojiku->data.wp3A.real,
				kojiku->data.wp3A.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				1
	);
	printf("、3C");
	FFT_IFFT(	kojiku->data.wp3C.real,
				kojiku->data.wp3C.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				1
	);
	printf("、3E\n");
	FFT_IFFT(	kojiku->data.wp3E.real,
				kojiku->data.wp3E.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				1
	);
	printf("\t\t性能静圧上昇\n");
	FFT_IFFT(	kojiku->data.pspr.real,
				kojiku->data.pspr.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				1
	);
	printf("\t\t流速（I型熱線）\n");
	FFT_IFFT(	kojiku->data.hwi.real,
				kojiku->data.hwi.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				1
	);
	printf("\t\t性能全圧上昇\n");
	FFT_IFFT(	kojiku->data.ptpr.real,
				kojiku->data.ptpr.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				1
	);
	printf("\t\t圧縮機内平均軸流速\n");
	FFT_IFFT(	kojiku->data.averv.real,
				kojiku->data.averv.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				1
	);
	printf("\t\t全圧上昇係数\n");
	FFT_IFFT(	kojiku->data.phi.real,
				kojiku->data.phi.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				1
	);
	printf("\t\t流量係数\n");
	FFT_IFFT(	kojiku->data.psi.real,
				kojiku->data.psi.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				1
	);
	//printf("\t\t絶対流速（Sprit型熱線）\n");
	//FFT_IFFT(	kojiku->data.hwsp_v.real,
	//			kojiku->data.hwsp_v.imag,
	//			kojiku->line.newline,
	//			kojiku->line.log2,
	//			1
	//);
	//printf("\t\t流れ角（Sprit型熱線）\n");
	//FFT_IFFT(	kojiku->data.hwsp_alpha.real,
	//			kojiku->data.hwsp_alpha.imag,
	//			kojiku->line.newline,
	//			kojiku->line.log2,
	//			1
	//);
	//printf("\t\t軸方向流速（Sprit型熱線）\n");
	//FFT_IFFT(	kojiku->data.hwsp_vaxis.real,
	//			kojiku->data.hwsp_vaxis.imag,
	//			kojiku->line.newline,
	//			kojiku->line.log2,
	//			1
	//);
	//printf("\t\t周方向流速（Sprit型熱線）\n");
	//FFT_IFFT(	kojiku->data.hwsp_vcir.real,
	//			kojiku->data.hwsp_vcir.imag,
	//			kojiku->line.newline,
	//			kojiku->line.log2,
	//			1
	//);

/*	printf("\t\t無次元軸方向流速（Sprit型熱線）\n");
	FFT_IFFT(	kojiku->data.hwsp_ndvaxis.real,
				kojiku->data.hwsp_ndvaxis.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				1
	);
	printf("\t\t周方向流速（Sprit型熱線）\n");
	FFT_IFFT(	kojiku->data.hwsp_ndvcir.real,
				kojiku->data.hwsp_ndvcir.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				1
	);*/
}



//------------------------------------------------------------------------------------------------------------------------------------------
//IFFTを掛ける関数
//------------------------------------------------------------------------------------------------------------------------------------------
void IFFT( st_kojiku *kojiku ){

	printf("\t\t動翼前縁壁圧　1A");
	FFT_IFFT(	kojiku->data.wp1A.real,
				kojiku->data.wp1A.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				0
	);
	printf("、1C");
	FFT_IFFT(	kojiku->data.wp1C.real,
				kojiku->data.wp1C.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				0
	);
	printf("、1E");
	FFT_IFFT(	kojiku->data.wp1E.real,
				kojiku->data.wp1E.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				0
	);
	printf("、2A");
	FFT_IFFT(	kojiku->data.wp2A.real,
				kojiku->data.wp2A.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				0
	);
	printf("、2C");
	FFT_IFFT(	kojiku->data.wp2C.real,
				kojiku->data.wp2C.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				0
	);
	printf("、2E");
	FFT_IFFT(	kojiku->data.wp2E.real,
				kojiku->data.wp2E.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				0
	);
	printf("、3A");
	FFT_IFFT(	kojiku->data.wp3A.real,
				kojiku->data.wp3A.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				0
	);
	printf("、3C");
	FFT_IFFT(	kojiku->data.wp3C.real,
				kojiku->data.wp3C.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				0
	);
	printf("、3E\n");
	FFT_IFFT(	kojiku->data.wp3E.real,
				kojiku->data.wp3E.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				0
	);
	printf("\t\t性能静圧上昇\n");
	FFT_IFFT(	kojiku->data.pspr.real,
				kojiku->data.pspr.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				0
	);
	printf("\t\t流速（I型熱線）\n");
	FFT_IFFT(	kojiku->data.hwi.real,
				kojiku->data.hwi.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				0
	);
	printf("\t\t性能全圧上昇\n");
	FFT_IFFT(	kojiku->data.ptpr.real,
				kojiku->data.ptpr.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				0
	);
	printf("\t\t圧縮機内平均軸流速\n");
	FFT_IFFT(	kojiku->data.averv.real,
				kojiku->data.averv.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				0
	);
	printf("\t\t全圧上昇係数\n");
	FFT_IFFT(	kojiku->data.phi.real,
				kojiku->data.phi.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				0
	);
	printf("\t\t流量係数\n");
	FFT_IFFT(	kojiku->data.psi.real,
				kojiku->data.psi.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				0
	);
	/*printf("\t\t絶対流速（Sprit型熱線）\n");
	FFT_IFFT(	kojiku->data.hwsp_v.real,
				kojiku->data.hwsp_v.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				0
	);
	printf("\t\t流れ角（Sprit型熱線）\n");
	FFT_IFFT(	kojiku->data.hwsp_alpha.real,
				kojiku->data.hwsp_alpha.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				0
	);
	printf("\t\t軸方向流速（Sprit型熱線）\n");
	FFT_IFFT(	kojiku->data.hwsp_vaxis.real,
				kojiku->data.hwsp_vaxis.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				0
	);
	printf("\t\t周方向流速（Sprit型熱線）\n");
	FFT_IFFT(	kojiku->data.hwsp_vcir.real,
				kojiku->data.hwsp_vcir.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				0
	);*/
/*	printf("\t\t無次元軸方向流速（Sprit型熱線）\n");
	FFT_IFFT(	kojiku->data.hwsp_ndvaxis.real,
				kojiku->data.hwsp_ndvaxis.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				0
	);
	printf("\t\t無次元周方向流速（Sprit型熱線）\n");
	FFT_IFFT(	kojiku->data.hwsp_ndvcir.real,
				kojiku->data.hwsp_ndvcir.imag,
				kojiku->line.newline,
				kojiku->line.log2,
				0
	);*/
}



//------------------------------------------------------------------------------------------------------------------------------------------
//指定周波数を除去する関数
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
//虚数の絶対値を求める関数
//------------------------------------------------------------------------------------------------------------------------------------------
double Abs_Imag(double x, double y){

	return( sqrt( x * x + y * y ) );
}


//------------------------------------------------------------------------------------------------------------------------------------------
//FFT関数
//------------------------------------------------------------------------------------------------------------------------------------------
void FFT_IFFT(double x_real[], double x_imag[], unsigned int N, unsigned int log_N, unsigned int sw){

	unsigned int		number_stage, stage;
	unsigned int		i, j, k, n, m, r, *index;
	double			a_real, a_imag, b_real, b_imag, c_real, c_imag, real, imag;

	number_stage = log_N;	//バタフライ演算の段数はlog2(データ数)

	//printf("%f %f %f %f\n\n", x_real[32766], x_imag[0], x_real[32767], x_imag[1]);

	//バタフライ演算
	for(stage=1 ; stage<=number_stage ; stage++){	//バタフライ演算の段数

		for(i=0 ; i<Pow2(stage-1) ; i++){	//各段におけるデータのグループ数

			for(j=0 ; j<Pow2(number_stage-stage) ; j++){	//各段のグループ内におけるデータの組み合わせ数

				n = Pow2(number_stage - stage + 1) * i + j;	//データ番号[n]と[m]を組として計算
				m = n + Pow2(number_stage - stage);			//データ番号[n]と[m]を組として計算

				r = Pow2(stage - 1) * j;	//回転子の次数

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

				if(stage < number_stage){	//最終段以外
					x_real[n] = a_real + b_real;
					x_imag[n] = a_imag + b_imag;
					x_real[m] = (a_real-b_real)*c_real - (a_imag-b_imag)*c_imag;
					x_imag[m] = (a_imag-b_imag)*c_real + (a_real-b_real)*c_imag;
				}
				else{	//最終段
					x_real[n] = a_real + b_real;
					x_imag[n] = a_imag + b_imag;
					x_real[m] = a_real - b_real;
					x_imag[m] = a_imag - b_imag;
				}
			}
		}
	}

	//インデックスの並び替えのためのテーブル作成
	index = (unsigned int *)calloc(N, sizeof(unsigned int));
	for(stage=1; stage<=number_stage; stage++){
		for(i=0; i<Pow2(stage-1); i++){
			index[Pow2(stage - 1) + i] = index[i] + Pow2(number_stage - stage);
		}
	}

	//インデックスの並べ替え
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
//指定周波数を除去する関数
//------------------------------------------------------------------------------------------------------------------------------------------
void Cut_Freq( double *x_real, double *x_imag, double cutfreq, unsigned int n_newline ){


	//変数宣言------------------------------------------------------------------------------------
	unsigned int	n_array	= (unsigned int)( (double)n_newline * (double)cutfreq / SampFreq );
	double			*p1;
	double			*p2;
		

	//エラー対策----------------------------------------------------------------------------------
	if( cutfreq >= SampFreq/2 ){
		printf("カットオフ周波数がサンプリング周波数の1/2より小さくなるようにしてください。\n");
		printf("強制終了して下さい。\n");
		while(1);
	}

	//指定された周波数以上をカット-----------------------------------------------------------------
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
//振幅スペクトルを計算する関数
//------------------------------------------------------------------------------------------------------------------------------------------
void FFT_AmpSpec( st_kojiku *kojiku ){

	//変数宣言---------------------------------------------------------------------------------------
	double	*p1;
	double	*p2;
	double	*p3;
	

	//変数宣言---------------------------------------------------------------------------------------
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
//振幅スペクトルの周波数軸を計算する関数
//------------------------------------------------------------------------------------------------------------------------------------------
void Axis_AmpSpec( st_kojiku *kojiku ){

	//変数宣言---------------------------------------------------------------------------------------
	unsigned int	i;
	double			*p;

	//周波数軸の計算---------------------------------------------------------------------------------
	for(	i = 0,
			p = kojiku->freq.axis_ampspec;
			i < kojiku->line.ampspec,
			p < kojiku->freq.axis_ampspec + kojiku->line.ampspec;
			i++,
			p++ ){
		*p = (double)i * SampFreq / (double)kojiku->line.newline;
	}
}
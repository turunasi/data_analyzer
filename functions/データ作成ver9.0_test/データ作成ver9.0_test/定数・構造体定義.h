//*************************************************************************************************************
//定数及び構造体定義
//*************************************************************************************************************

#include	<stdio.h>

//-------------------------------------------------------------------------------------------------------------
//定数定義
//-------------------------------------------------------------------------------------------------------------
#define		I			( 1<<23 )					//配列の行数（2＾21行、つまり約22秒分に勝手に決めた）	//210831 1<<23にした方がいいかな
#define		J			( 16 )						//配列の列数（データレコーダーの仕様上、16列）
#define		PI			( 3.1415926535 )			//円周率
#define		P0			( 101.325 )					//標準大気圧
#define		T0			( 273.15+20.0 )				//標準大気温度（20[℃]）
#define		R			( 0.287 )					//空気の気体定数
#define		SampFreq	( 96000.0 )					//データレコーダのサンプリング周波数
//#define		Nrev		( 200.0 )					//回転数
//#define		U			( 0.13 * PI * Nrev )		//動翼翼端速度

//-------------------------------------------------------------------------------------------------------------
//構造体
//-------------------------------------------------------------------------------------------------------------
struct st_kojiku{

	//ファイルに関する構造体------------------------------------------------------------------------------
	struct{

		struct{

			FILE		*init;			//イニシャル
			FILE		*in;			//入力
			FILE		*p_max;	//プチテスト

			struct{
				FILE	*rawdata;		//壁圧1A生データ
				FILE	*filter;		//壁圧1Aフィルタ
				FILE	*ampspec;		//壁圧1A振幅スペクトル
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
			}pspr;					//性能壁圧上昇

			struct{
				FILE	*rawdata;
				FILE	*filter;
				FILE	*ampspec;
			}hwi;					//軸流速（熱線I型）

			struct{
				FILE	*rawdata;
				FILE	*filter;
				FILE	*ampspec;
			}ptpr;					//性能全圧上昇

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}averv;					//圧縮機内平均軸流速

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}psi;					//全圧上昇係数ψ

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}phi;					//流量係数φ

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}phi2;					//無次元流速ph2

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}phi3;					//無次元流速phi3

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}psi_s;					//静圧上昇係数ψs

			struct{
				FILE	*rawdata;
				FILE	*filter;
				FILE	*ampspec;
			}hwi2;				//内部流れ（I型熱線）

			struct{
				FILE	*rawdata;
				FILE	*filter;
				FILE	*ampspec;
			}hwi3;				//内部流れ（I型熱線）

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}phi_psi;				//φ-ψ

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}phi_psi_s;				//φ-ψ（静圧上昇係数）

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
			}hwsp1_v;				//絶対流速（スプリット型熱線）

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}hwsp1_alpha;			//流れ角（スプリット型熱線）

			struct{
				FILE	*rawdata;
				FILE	*filter;
				FILE	*ampspec;
			}hwsp1_vaxis;			//軸方向流速（スプリット型熱線）

			struct{
				FILE	*rawdata;
				FILE	*filter;
				FILE	*ampspec;
			}hwsp1_vcir;				//周方向流速（スプリット型熱線）

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}hwsp1_ndvaxis;			//無次元軸方向流速（スプリット型熱線）

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}hwsp1_ndvcir;			//無次元周方向流速（スプリット型熱線）

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}hwsp1_twod_averv;				//2d平均軸流速

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}hwsp1_twod_phi;				//2dφ

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}hwsp1_twod_phi_psi;				//2dφ-ψ

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}hwsp2_v;				//絶対流速（スプリット型熱線）

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}hwsp2_alpha;			//流れ角（スプリット型熱線）

			struct{
				FILE	*rawdata;
				FILE	*filter;
				FILE	*ampspec;
			}hwsp2_vaxis;			//軸方向流速（スプリット型熱線）

			struct{
				FILE	*rawdata;
				FILE	*filter;
				FILE	*ampspec;
			}hwsp2_vcir;				//周方向流速（スプリット型熱線）

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}hwsp2_ndvaxis;			//無次元軸方向流速（スプリット型熱線）

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}hwsp2_ndvcir;			//無次元周方向流速（スプリット型熱線）

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}hwsp2_twod_averv;				//2d平均軸流速

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}hwsp2_twod_phi;				//2dφ

			struct{
				FILE	*rawdata;
				FILE	*filter;
			}hwsp2_twod_phi_psi;				//2dφ-ψ

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
			unsigned int	init1;		//イニシャル番号1
			unsigned int	init2;		//イニシャル番号2
			unsigned int	data;		//入力ファイル番号
			unsigned int	p_max;	//プチテスト番号
		}num;

		struct{
			char			*init;			//イニシャルファイルの場所
			char			*in;			//入力ファイルの場所
			char			*out;			//出力ファイルの場所
			char			*p_max;	//プチテストファイルの場所
		}posit;

		char posit_num_dir[256];
	}file;


	//データに関する構造体------------------------------------------------------------------------------
	struct{

		unsigned int	**data_u;		//バイナリデータ格納用配列
		double			**data_d;		//電圧値変換データ格納用配列

		struct{							//壁圧1A
			double	*real;				//（実部）
			double	*imag;				//（虚部）
			double	*abs;				//（絶対値）
		}wp1A;
		struct{							//以下壁圧
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

		struct{							//性能静圧上昇
			double	*real;
			double	*imag;
		}pspr;

		struct{							//軸流速（熱線I型）
			double	*real;
			double	*imag;
			double	*abs;
		}hwi;

		struct{							//内部流れ（I型熱線）
			double *real;
			double *imag;
			double *abs;
		}hwi2;

		struct{							//内部流れ（I型熱線）
			double *real;
			double *imag;
			double *abs;
		}hwi3;

		struct{							//性能全圧上昇
			double	*real;
			double	*imag;
			double	*abs;
		}ptpr;

		struct{							//圧縮機内平均軸流速
			double	*real;
			double	*imag;
		}averv;

		struct{							//全圧上昇係数ψ
			double	*real;
			double	*imag;
		}psi;

		struct{							//流量係数φ
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

		struct{							//静圧上昇係数ψs
			double	*real;
			double	*imag;
		}psi_s;							

		struct{							//バルブ開閉
			double *real;
		}valve;

		struct {							//撃針波形
			double *real;
		}plunge;

		struct{							//dp/dt計算関数用
			double *real;
		}dpdt;

		struct{							//dq/dt計算関数用
			double *real;
		}dqdt;

		struct{							//絶対流速（スプリット型熱線）
			double	*real;
			double	*imag;
		}hwsp1_v;

		struct{							//流れ角（スプリット型熱線）
			double	*real;
			double	*imag;
		}hwsp1_alpha;

		struct{							//軸方向流速（スプリット型熱線）
			double	*real;
			double	*imag;
			double	*abs;
		}hwsp1_vaxis;

		struct{							//周方向流速（スプリット型熱線）
			double	*real;
			double	*imag;
			double	*abs;
		}hwsp1_vcir;

		struct{							//無次元軸方向流速（スプリット型熱線）
			double *real;
			double *imag;
		}hwsp1_ndvaxis;

		struct{							//無次元周方向流速（スプリット型熱線）
			double *real;
			double *imag;
		}hwsp1_ndvcir;

		struct{							//2d平均軸流速
			double	*real;
			double	*imag;
		}hwsp1_twod_averv;

		struct{							//2dφ
			double	*real;
			double	*imag;
		}hwsp1_twod_phi;							

		struct{							//絶対流速（スプリット型熱線）
			double	*real;
			double	*imag;
		}hwsp2_v;

		struct{							//流れ角（スプリット型熱線）
			double	*real;
			double	*imag;
		}hwsp2_alpha;

		struct{							//軸方向流速（スプリット型熱線）
			double	*real;
			double	*imag;
			double	*abs;
		}hwsp2_vaxis;

		struct{							//周方向流速（スプリット型熱線）
			double	*real;
			double	*imag;
			double	*abs;
		}hwsp2_vcir;

		struct{							//無次元軸方向流速（スプリット型熱線）
			double *real;
			double *imag;
		}hwsp2_ndvaxis;

		struct{							//無次元周方向流速（スプリット型熱線）
			double *real;
			double *imag;
		}hwsp2_ndvcir;

		struct{							//2d平均軸流速
			double	*real;
			double	*imag;
		}hwsp2_twod_averv;

		struct{							//2dφ
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

	//イニシャルの構造体-------------------------------------------------------------------------------
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

	//プチテストファイルの構造体------------------------------------------------------------------------
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

	//センサ感度の構造体--------------------------------------------------------------------------------
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
		}kousei;					//平均流速を求める流量校正式（1次式のため係数2個

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

	//行数構造体----------------------------------------------------------------------------------------
	struct{
		unsigned int	line;		//データ行数
		unsigned int	log2;		//log2( データ行数 )、繰上げ整数
		unsigned int	newline;	//2^xに修正した新しいデータ行数
		unsigned int	ampspec;	//振幅スペクトル
	}line;

	//大気条件------------------------------------------------------------------------------------------
	struct{
		double	P;		//実験時大気圧（[mmHg]）
		double  P_init;
		double  P_end;
		double	T;		//実験時大気温度（[℃]）
		double	T_init;
		double  T_end;
		double	dens;	//実験時空気密度
		double	Nrev;	    //実験回転数
		double	Uc;		 //周速度
	}atm;

	//周波数--------------------------------------------------------------------------------------------
	struct{
		double	*axis_ampspec;
		double	cut1;
		double	cut2;
		double	cut3;
		double	cut4;
	}freq;

	//出力チェック----------------------------------------------------------------------------------------
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
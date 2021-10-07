#define	I	( 1<<18 )//配列の行数（2＾18行、つまり約2.7秒分）	
#define	J	( 16 )//配列の列数（データレコーダーの仕様上、16列）

struct st_init{
	struct{
		struct{
			unsigned int	__1;		//イニシャルファイル番号0
			unsigned int	__2;		//イニシャルファイル番号1
			unsigned int	__3;		//圧力修正イニシャル
		}num;

		struct{
			char	*in;				//入力ファイルのパス
			char	*out;				//出力ファイルのパス
		}posit;
	
		struct{
			FILE	*in1;				//入力ファイルポインタ0
			FILE	*in2;				//入力ファイルポインタ1
			FILE	*in3;
			FILE	*out1;
			FILE	*out2;				//出力ファイルポインタ
		}fp;
		struct{
			double  hwi_6;
			double	hwi_5;
			double	hwi_4;
			double	hwi_3;
			double	hwi_2;
			double	hwi_1;
			double  hwi_0;
		}sens;							//熱線流速計感度
	}file;

	//データ------------------------------------
	struct{		
		unsigned int	**data_u1;			//バイナリデータ格納用配列0
		unsigned int	**data_u2;			//バイナリデータ格納用配列1
		unsigned int	**data_u3;
		double			**data_d1;			//計算用配列0
		double			**data_d2;			//計算用配列1
		double			**data_d3;			//計算用配列2
		double			init1[10];			//イニシャル0（1A～3E、性能静圧の10要素）
		double			init2[10];			//イニシャル1（1A～3E、性能静圧の10要素）
		double			init3[2];			//性能静圧，流速の２要素 
		double			aver_init12[10];	//イニシャルの平均値（1A～3E、性能静圧の10要素）
		double			aver_v[5];			//平均電圧+ 自己相関係数
	}data;

	//行----------------------------------------
	struct{
		unsigned int	init1;		//イニシャルの行数0
		unsigned int	init2;		//イニシャルの行数1
		unsigned int	init3;		//イニシャルの行数2
	}line;
};
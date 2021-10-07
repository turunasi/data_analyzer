// ライブラリ、自作ヘッダのインクルード //
#include	"定数・構造体定義.h"	//自作ヘッダ
#include	"自作関数定義.h"		//自作ヘッダ

void Line( st_kojiku *kojiku ){
	if(kojiku->check.log2check == 0){
		kojiku->line.log2	= Log2( kojiku->line.line );
		kojiku->line.newline	= Pow2( kojiku->line.log2 );
		kojiku->line.ampspec	= (unsigned int)( 3000.0 * (double)kojiku->line.newline / SampFreq ) + 1;

	printf( "\t\tデータ行数：%d(<2^%d=%d)[行]\n",
			kojiku->line.line,
			kojiku->line.log2,
			kojiku->line.newline
	);
	}else{
		kojiku->line.log2	= Log2( kojiku->line.line ) - 1;
		kojiku->line.newline	= Pow2( kojiku->line.log2 );
		kojiku->line.ampspec	= (unsigned int)( 3000.0 * (double)kojiku->line.newline / SampFreq ) + 1;

	printf( "\t\tデータ行数：%d(<2^%d=%d)[行]\n",
			kojiku->line.line,
			kojiku->line.log2,
			kojiku->line.newline
	);
	kojiku->line.line = kojiku->line.newline;
	
	}
	//printf("Line%lf\n",kojiku->sens.kousei.P_1);
}
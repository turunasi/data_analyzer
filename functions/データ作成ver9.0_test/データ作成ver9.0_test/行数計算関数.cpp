// ���C�u�����A����w�b�_�̃C���N���[�h //
#include	"�萔�E�\���̒�`.h"	//����w�b�_
#include	"����֐���`.h"		//����w�b�_

void Line( st_kojiku *kojiku ){
	if(kojiku->check.log2check == 0){
		kojiku->line.log2	= Log2( kojiku->line.line );
		kojiku->line.newline	= Pow2( kojiku->line.log2 );
		kojiku->line.ampspec	= (unsigned int)( 3000.0 * (double)kojiku->line.newline / SampFreq ) + 1;

	printf( "\t\t�f�[�^�s���F%d(<2^%d=%d)[�s]\n",
			kojiku->line.line,
			kojiku->line.log2,
			kojiku->line.newline
	);
	}else{
		kojiku->line.log2	= Log2( kojiku->line.line ) - 1;
		kojiku->line.newline	= Pow2( kojiku->line.log2 );
		kojiku->line.ampspec	= (unsigned int)( 3000.0 * (double)kojiku->line.newline / SampFreq ) + 1;

	printf( "\t\t�f�[�^�s���F%d(<2^%d=%d)[�s]\n",
			kojiku->line.line,
			kojiku->line.log2,
			kojiku->line.newline
	);
	kojiku->line.line = kojiku->line.newline;
	
	}
	//printf("Line%lf\n",kojiku->sens.kousei.P_1);
}
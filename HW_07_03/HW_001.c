#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	// 痕呪 識情馬奄.
	int min = 0, max = 0, squareCnt = 0;
	// 薦咽 いい呪研 眼澗 壕伸.
	int squareNumAry[10000] = { 0, };
	int i, j, isSquare = 0;

	// 莫縦 窒径馬奄.
	printf("min : ");
	scanf("%d", &min);
	printf("max : ");
	scanf("%d", &max);

	// 薦咽 いい呪 姥馬奄
	/*
	* 蓄舛馬澗 因縦 : (嬢恐 呪 X) % (薦咽 呪) != 0->薦咽 いい呪.
	* 嬢恐 呪 X : min戚雌 ~ max 戚馬税 乞窮 呪.
	* 薦咽 呪 : 4, 9, 16 ~~~.
	*/ 

	for (i = min; i <= max; i++) {
		// 績税税 薦咽 呪 識情
		int tempSquareNum = 0;
		for (j = 2; j < 10000; j++) {
			tempSquareNum = j * j;
			// 薦咽 いい呪亜 焼艦虞檎
			if (i % tempSquareNum == 0) {
				isSquare = 0;
				break;
			}else{
				isSquare = 1;
			}
			// 薦咽 呪 装亜 因縦
		}
		if (isSquare == 1) {
			squareNumAry[squareCnt] = i;
			// 薦咽 いい呪亜 壕伸拭 匂敗鞠檎 背雁 壕伸税 index 葵 装亜獣徹奄.
			squareCnt++;
		}
		isSquare = 0;
	}



	printf("薦咽 いい呪 : %d鯵\n", squareCnt);


	// 薦咽 いい呪亜 眼延 壕伸聖 窒径馬奄
	for (i = 0; i < 10000; i++) {
		if (squareNumAry[i] == 0) {
			break;
		}else{
			printf("%d ", squareNumAry[i]);
		}
	}

	return 0;
}
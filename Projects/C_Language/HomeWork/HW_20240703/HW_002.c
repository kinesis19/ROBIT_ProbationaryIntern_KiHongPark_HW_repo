#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>

int main() {

	// 痕呪 識情馬奄
	int inputNum = 0, numAry[20] = { 0, }; // numAry : 推社研 煽舌馬澗 増杯(壕伸)
	char operator[10] = { 0, }; // add, remove 去税 舘嬢 煽舌 壕伸
	int i, j, aryIndex = 0;
	int isOkayAdd = 1, isOkayRemove = 0, isOkayCheck = 0, isOkayToggle = 0; // boolean 尻至切澗 照 壕錘 鎧遂戚糠稽 int稽 boolean 蝕拝聖 企端敗.

	// 莫縦 窒径馬奄
	printf("尻至聖 識澱馬室推. (1 <= x <= 20");
	printf("\nadd X\nremove X\ncheck X\ntoggle X\nall 0\nempty 0\n\n");

	while (1) {
		
		printf("input : ");
		scanf("%s %d", &operator, &inputNum);

		/* (森須坦軒)
		* 引薦拭澗 情薦猿走 鋼差馬澗走, 情薦 纏窒馬澗走拭 企廃 竺誤戚 照 鞠嬢 赤製.
		* 巷廃 欠覗研 号走馬奄 是背 鋼差庚 纏窒拭 企廃 森須坦軒澗 績税稽 姥薄敗.
		* 舘, 引薦拭 薦獣吉 窒径 莫縦聖 層呪馬奄 是背 莫縦 窒径拭辞澗 stop 淫恵 庚姥研 蓄亜馬走 省製.
		* 弘経, Ctrl + C 舘逐徹研 搭背 巷廃 欠覗研 纏窒拝 呪 赤製.
		*/ 

		if (!strcmp(operator, "stop") && inputNum == 0) {
			printf("Stopped!");
			break;
		}

		// 域至 尻至切 搾嘘馬奄
		if (!strcmp(operator, "add")) {
			for (i = 0; i < 20; i++) {
				if (numAry[i] == inputNum) {
					isOkayAdd = 0;
					break;
				}
			}
			if (isOkayAdd == 1) {
				numAry[aryIndex] = inputNum;
				printf("増杯 : { ");
				for (j = 0; j <= aryIndex; j++) {
					printf("%d, ", numAry[j]);
				}
				printf(" }\n\n");
				aryIndex++;
			}
			isOkayAdd = 1;
		}else if (!strcmp(operator, "remove")) {
			int removeIdx = 0; // 肢薦拝 推社税 index 葵

			// 肢薦拝 呪 赤澗 収切昔走 伊塘馬奄. (背雁 収切亜 増杯税 推社稽 匂敗鞠嬢 赤澗走 伊塘)
			for (i = 0; i < 20; i++) {
				// 収切焼 増杯 鎧拭 赤澗 推社析 凶税 坦軒.
				if (numAry[i] == inputNum) {
					removeIdx = i;
					aryIndex--; // 推社研 蓄亜拝 凶, 痕井吉 index 穣汽戚闘馬奄
					/* ex) remove亜 砧 腰 鞠醸生檎,
					*  蓄亜拝 凶税 index 是帖亀 蓄亜拝 凶税 index拭辞 砧 腰 及拭辞 蓄亜背醤 敗.
					*/
					isOkayRemove = 1;
					break;
				}
			}
			if (isOkayRemove == 1) {
				// 推社 薦暗馬奄.
				numAry[removeIdx] = 0;
				// 薦暗吉 推社 及拭 赤澗 推社級亀 蒋生稽 戚疑 獣徹奄.
				for (j = removeIdx; j < 20; j++) {
					numAry[j] = numAry[j + 1];
				}
			}
			// 巨獄焔 (推社 窒径馬奄 - 舛軒 板)
			printf("増杯 : { ");
			for (j = 0; j < aryIndex; j++) {
				printf("%d, ", numAry[j]);
			}
			printf(" }\n\n");
			isOkayRemove = 0;
			
		}else if (!strcmp(operator, "check")) {
			// 脊径吉 収切亜 増杯拭 匂敗鞠嬢 赤澗走 伊塘馬奄
			for (i = 0; i < 20; i++) {
				if (numAry[i] == inputNum) {
					isOkayCheck = 1;
					break;
				}else{
					isOkayCheck = 0;
				}
			}
			// 幻鉦, 増杯 鎧拭 背雁 収切亜 蒸生檎 0聖 窒径馬奄.
			// 壕錘 鯵割 掻 馬蟹昔 *3牌 尻至切* 紫遂背 左奄.
			printf("%d ", isOkayCheck == 1 ? 1 : 0);

			printf("増杯 : { ");
			for (j = 0; j < aryIndex; j++) {
				printf("%d, ", numAry[j]);
			}
			printf(" }\n\n");

		}else if (!strcmp(operator, "toggle")) {
			int removeIdx = 0;
			// 脊径吉 収切亜 増杯拭 匂敗鞠嬢 赤澗走 伊塘馬奄
			for (i = 0; i < 20; i++) {
				if (numAry[i] == inputNum) {
					removeIdx = i;
					isOkayToggle = 1;
					break;
				}else {
					isOkayToggle = 0;
				}
			}
			// 幻鉦 増杯拭 背雁 収切亜 赤聖 凶,
			if (isOkayToggle == 1) {
				// 推社 薦暗馬奄.
				numAry[removeIdx] = 0;
				aryIndex--;
				// 薦暗吉 推社 及拭 赤澗 推社級亀 蒋生稽 戚疑 獣徹奄.
				for (j = removeIdx; j < 20; j++) {
					numAry[j] = numAry[j + 1];
				}
			}else{ // 幻鉦 増杯拭 背雁 収切亜 蒸聖 凶,
				numAry[aryIndex] = inputNum;
				aryIndex++;
			}

			printf("増杯 : { ");
			for (j = 0; j < aryIndex; j++) {
				printf("%d, ", numAry[j]);
			}
			printf(" }\n\n");

		}else if (!strcmp(operator, "all") && inputNum == 0) {
			// 引薦拭 薦獣吉 脊径 莫縦 "all 0"戚 鞠嬢醤幻 薦獣吉 増杯生稽 痕井鞠亀系 姥薄敗.

			for (j = 0; j < 20; j++) {
				numAry[j] = j + 1;
			}

			printf("増杯 : { ");
			for (j = 0; j < 20; j++) {
				printf("%d, ", numAry[j]);
			}
			printf(" }\n\n");
			aryIndex = 19;

		}else if (!strcmp(operator, "empty") && inputNum == 0) {
			// 引薦拭 薦獣吉 脊径 莫縦 "empty 0"戚 鞠嬢醤幻 薦獣吉 増杯生稽 痕井鞠亀系 姥薄敗.
			
			/*
			* 推社澗 0稽 走舛馬食 因増杯 坦軒研 敗.
			* 0生稽 走舛廃 戚政 : 脊径吉 収切税 骨是澗 1戚雌 ~ 20戚馬績.
			* 増杯 伊至 縦拭辞 0昔 推社亜 赤生檎 因増杯績聖 昔縦馬惟 馬食, 
			* 因増杯 窒径聖 馬亀系 姥薄敗.
			*/

			for (j = 0; j < 20; j++) {
				numAry[j] = 0;
			}

			printf("増杯 : { ");
			for (j = 0; j < aryIndex; j++) {
				// 因増杯戚虞檎
				if (numAry[j] == 0) {
					break;
				}
			}
			printf(" }\n\n");
			aryIndex = 0;
		}
	}


	return 0;
}


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	// 痕呪 識情馬奄.
	int min = 0, max = 0, squareCnt = 0;
	// 薦咽 いい呪研 眼澗 壕伸.
	int squareNumAry[10000] = { 0, };
	int i, j, isSquare = 0;

	// 莫縦 窒径馬奄.
	printf("%min : ");
	scanf("%d", &min);
	printf("%max : ");
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
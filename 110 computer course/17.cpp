#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main() {
	int N;

	while (scanf("%d", &N)) {
		if (N <= 0) {
			break;
		}
		int count[200] = { 0 };
		char String1[99][99];
		int ascii_count[52] = { 0 };//A~Z and a~z saved 
		int max = 0;
		for (int x = 0; x < N; x++) {
			scanf("%s",String1[x]);
		}
		for (int z = 0; z < N; z++) {//第N筆資料
			for (int y = 0; y < strlen(String1[z]); y++) {//第N筆資料長度
				if (String1[z][y] >= 65 &&  String1[z][y] <= 90) {
					++ascii_count[((String1[z][y]) - 65)];
				}
				if (String1[z][y] >= 97 && String1[z][y] <= 122) {
					++ascii_count[((String1[z][y]) - 71)];
				}
				
			}
		}
		for (int run = 0; run < 52; run++) {
			if (ascii_count[run] > max) {
				max = ascii_count[run];
			}
		}

		int save_runtime = max;
		while (save_runtime > 0) {
			for (int v = 0; v < 26; v++) {
				if (ascii_count[v] == save_runtime) {
					printf("%c(%d) ", v + 65, save_runtime);
				}
			}
			for (int v = 26; v < 52; v++) {
				if (ascii_count[v] == save_runtime) {
					printf("%c(%d) ", v + 71, save_runtime);
				}
			}
			--save_runtime;
		}
		printf("\n");
	}
	return 0;
}

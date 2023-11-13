#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

int* pa;
int n;

void load() {
	FILE* fin = fopen("C:\\Users\\vkobi\\OneDrive\\Desktop\\lab_19\\in4.txt", "rt");
	if (fin == NULL) {
		printf("входной файл не найден\n");
		return;
	}

	fscanf(fin, "%d", &n);

	pa = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) { fscanf(fin, "%d", &pa[i]); }

	fclose(fin);
}


void SaveResult() {
	float mx = 0;
	float s = 0;

	for (int i = 0; i < n; i++) {
		if (pa[i] > mx) {
			mx = pa[i];
		}
	}

	s = (0.6666 * mx);


	int m = 0;
	for (int i = 0; i < n; i++) {
		if (pa[i] >= s) {
			m++;
		}
	}


	FILE* fout = fopen("C:\\Users\\vkobi\\OneDrive\\Desktop\\lab_19\\out4.txt", "wt");
	if (fout == NULL) {
		printf("выходной файл не найден\n");
		return;
	}

	fprintf(fout, "%d\n", m);
	for (int i = 0; i < n; i++) {
		if (pa[i] >= s) {
			fprintf(fout, "%d ", pa[i]);
		}
	}
	fclose(fout);
}


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("Hello, it is task4!\n");


	load();
	SaveResult();

	free(pa);
}
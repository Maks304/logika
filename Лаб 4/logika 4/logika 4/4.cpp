#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>
#include <windows.h>


int i = 0;
int j = 0;
int size = 0;
int** g = 0;

void z1() {


	srand(time(NULL));

	g = (int**)malloc(size * sizeof(int*));
	for (i = 0; i < size; i++)
	{
		g[i] = (int*)malloc(size * sizeof(int));
	}

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			g[i][j] = rand() % 2;

		}
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (i == j)
				g[i][j] = 0;
			else
				g[i][j] = g[j][i];
		}
	}
	printf("Матрица: \n");
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%2d", g[i][j]);
		}
		printf("\n");
	}
}

void DFS(int** g, int* NUM, int v)
{
	NUM[v] = 1;
	printf(" %d ", v);
	for (int i = 0; i < size; i++)
	{
		if ((g[v][i] == 1) && (NUM[i] == 0))
			DFS(g, NUM, i);
	}
}
void z2(int** g)
{
	int* NUM = (int*)malloc(size * sizeof(int));
	int v;
	printf("Точка входа: ");
	scanf("%d", &v);
	for (int i = 0; i < size; i++)
	{
		NUM[i] = 0;
	}
	printf("\n");
	DFS(g, NUM, v);
}
int main(void)
{
	setlocale(LC_ALL, "RUS");
	int* NUM = (int*)malloc(size * sizeof(int));
	printf("Введите размер матрицы: ");
	scanf("%d", &size);
	z1();
	printf("\n");
	z2(g);
	printf("\n");
	system("pause");
}

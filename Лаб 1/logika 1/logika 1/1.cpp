#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>
#include <locale.h>
#include <time.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

void task1()
{
	int min = 100;
	int max = 0;
	int mas[10] = { 10, 20, 25, 23, 12, 11, 25, 14, 9, 6 };

	printf("������� 1:\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", mas[i]);
		if (mas[i] > max)
			max = mas[i];
		if (mas[i] < min)
			min = mas[i];
	}
	printf("\n������� ����� max � min = %d\n", max - min);
}

void task2()
{
	srand(time(NULL));
	printf("������� 2:\n");
	int mas[10] = { 0 };
	for (int i = 0; i < 10; i++)
	{
		mas[i] = rand() % 100;
		printf("%d ", mas[i]);
	}
	printf("\n");
}

void task3()
{
	srand(time(NULL));
	printf("������� 3:\n");
	int* mas2;

	int n = 0;
	printf("������� ���-�� ���������: ");
	scanf("%d", &n);
	mas2 = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		mas2[i] = rand() % 100;
		printf("%d ", mas2[i]);
	}
	free(mas2);
	printf("\n");
}

void task4()
{
	srand(time(NULL));
	printf("������� 4:\n");
	printf("�����. �������\n");
	int** mas;
	int strok, stolb, i, j;
	printf("������� ���-�� �����: ");
	scanf("%d", &strok);
	printf("������� ���-�� ��������: ");
	scanf("%d", &stolb);
	mas = (int**)malloc(strok * sizeof(int*));

	for (i = 0; i < strok; i++)
	{
		mas[i] = (int*)malloc(stolb * sizeof(int));
	}
	for (i = 0; i < strok; i++)
	{
		for (j = 0; j < stolb; j++)
		{
			mas[i][j] = rand() % 99;
		}
	}


	for (i = 0; i < strok; i++)
	{
		for (j = 0; j < stolb; j++)
		{
			printf("%3d", mas[i][j]);
		}
		printf("\n");
	}
}

void task5()
{
	printf("������� 5:\n");
	int i;
	struct student
	{
		char famil[40];
		char name[40];
		char facult[40];
		int Nomzach;
	} stud[3];
	int kolv = 0;
	printf("������� ���������� ���������, ������� ������ ��������\n");
	scanf("%d", &kolv);
	for (i = 0; i < kolv; i++)
	{
		printf("������� ������� ��������\n");
		scanf("%20s", &stud[i].famil);
		OemToCharA(stud[i].famil, stud[i].famil);

		printf("������� ��� ��������\n");
		scanf("%20s", &stud[i].name);
		OemToCharA(stud[i].name, stud[i].name);

		printf("������� �������� ���������� ��������\n");
		scanf("%20s", &stud[i].facult);
		OemToCharA(stud[i].facult, stud[i].facult);

		printf("������� ����� �������� ������ ��������\n");
		scanf("%20d", &stud[i].Nomzach);
	}

	for (i = 0; i < kolv; i++)
	{
		printf("������� %s %s ��������� �� ���������� %s, ����� �������� ������ %d\n", stud[i].famil, stud[i].name, stud[i].facult, stud[i].Nomzach);
	}

	char sl[20];
	printf("����� \n");
	printf(">\a");
	scanf("%s", sl);
	OemToCharA(sl, sl);
	printf("\n");
	short chet = 0;
	for (int i = 0; i < kolv; i++)
	{
		if (strcmp(sl, stud[i].famil) == 0 || strcmp(sl, stud[i].name) == 0 || strcmp(sl, stud[i].facult) == 0)
		{
			printf("������� %s %s ��������� �� ���������� %s, ����� �������� ������ %d\n", stud[i].famil, stud[i].name, stud[i].facult, stud[i].Nomzach);
			chet++;
		}
	}
	if (chet == 0)
		printf("|_______������ �� �������_______|\n");
	system("pause");
}


int main(void)
{
	setlocale(LC_ALL, "Russian");
	task1();
	printf("\n");
	task2();
	printf("\n");
	task3();
	printf("\n");
	task4();
	printf("\n");
	task5();
	printf("\n");
	system("pause");
}

#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>
#include <windows.h>

void multiply(int size)
{
	setlocale(LC_ALL, "RUS");

	int i = 0, j = 0, r = 0;
	int elem_c;

	//clock_t start, end;

	srand(time(NULL));// �������������� ��������� ���������� ��������� �����
	int** a = 0;
	int** b = 0;
	int** c = 0;
	//int size;
	//printf("������� ������ ������: ");
	//scanf("%d", &size);


	a = (int**)malloc(size * sizeof(int*));
	for (i = 0; i < size; i++)
	{
		a[i] = (int*)malloc(size * sizeof(int));
	}

	b = (int**)malloc(size * sizeof(int*));
	for (i = 0; i < size; i++)
	{
		b[i] = (int*)malloc(size * sizeof(int));
	}

	c = (int**)malloc(size * sizeof(int*));
	for (i = 0; i < size; i++)
	{
		c[i] = (int*)malloc(size * sizeof(int));
	}

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			a[i][j] = rand() % 99;
		}
	}

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			b[i][j] = rand() % 99;
		}
	}

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			elem_c = 0;
			for (r = 0; r < size; r++)
			{
				elem_c = elem_c + a[i][r] * b[r][j];
				c[i][j] = elem_c;
			}
		}
	}
}

void shell(int* items, int count)
{

	int i, j, gap, k;
	int x, a[5];

	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

	for (k = 0; k < 5; k++) {
		gap = a[k];
		for (i = gap; i < count; ++i) {
			x = items[i];
			for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
				items[j + gap] = items[j];
			items[j + gap] = x;
		}
	}
}

void qs(int* items, int left, int right) //����� �������: qs(items, 0, count-1);
{
	int i = 0, j;
	int x, y;

	i = left; j = right;

	//����� ����������
	x = items[(left + right) / 2];

	do {
		while ((items[i] < x) && (i < right)) i++;
		while ((x < items[j]) && (j > left)) j--;

		if (i <= j) {
			y = items[i];
			items[i] = items[j];
			items[j] = y;
			i++; j--;
		}
	} while (i <= j);

	if (left < j) qs(items, left, j);
	if (i < right) qs(items, i, right);
}

int comp(const int* a, const int* b)
{
	return *a - *b;
}


int main(void)
{

	int count = 0, size = 0;
	clock_t start, end;
	setlocale(LC_ALL, "RUS");

	FILE* file;
	char inputname[16], filename[16];
	setlocale(LC_ALL, "Russian");
	printf("������� �������� ������ �����:\n>");		// �������� �����
	scanf("%s", inputname);
	strcpy(filename, inputname);
	file = fopen(filename, "w+");
	printf("���� ������.");
	Sleep(999);
	system("cls");

	/*��������� ������*/
	printf("��������� ������:\n");
	printf("������� ������ ������: ");
	scanf("%d", &size);
	start = clock();
	multiply(size);
	end = clock();
	float time = end - start;
	fprintf(file, "��������� ������: ����� ���������� ������ ���������=%.4f �\n\n", time / CLOCKS_PER_SEC);
	printf("����� ���������� =%.4f �, ��������� ������� � ����.\n\n", time / CLOCKS_PER_SEC);
	end = 0;
	start = 0;

	/*���������� �����=================================================================*/
	printf("���������� �����:\n\n");
	printf("������� ������ ��c����:\n");

	scanf("%d", &count);
	int* items = (int*)malloc(count * sizeof(items));

	for (int i = 0; i < count; i++)
	{
		items[i] = rand() % 100;
	}
	printf("1. ��������� ����� ������:\n");
	start = clock();
	shell(items, count);
	end = clock();
	time = end - start;
	fprintf(file, "������ ������� %d\n\n", count);
	fprintf(file, "����, ��������� ����� ������: ����� ���������� =%.4f �\n", time / CLOCKS_PER_SEC);
	printf("����� ���������� =%.4f �, ��������� ������� � ����.\n\n", time / CLOCKS_PER_SEC);


	for (int i = 0; i < count; i++)
	{
		items[i] = i;
	}
	printf("2. �������� ������ �� �����������:\n");
	start = clock();
	shell(items, count);
	end = clock();
	time = end - start;
	fprintf(file, "����, ���. ������ �� ����.: ����� ���������� =%.4f �\n", time / CLOCKS_PER_SEC);
	printf("����� ���������� =%.4f �, ��������� ������� � ����.\n\n", time / CLOCKS_PER_SEC);


	for (int i = 0; i < count; i++)
	{
		items[i] = count - i;
	}
	printf("3. �������� ������ �� ��������:\n");
	start = clock();
	shell(items, count);
	end = clock();
	time = end - start;
	fprintf(file, "����, ���. ������ �� ��������: ����� ���������� =%.4f �\n", time / CLOCKS_PER_SEC);
	printf("����� ���������� =%.4f �, ��������� ������� � ����.\n\n", time / CLOCKS_PER_SEC);

	for (int i = 0; i < count; i++)
	{
		if (i < count / 2) {
			items[i] = i;
		}
		else {
			items[i] = count - i;
		}
	}
	printf("4. �������� ������ �� ����. �� �������� �������, ������ - �� ��������\n");
	start = clock();
	shell(items, count);
	end = clock();
	time = end - start;
	fprintf(file, "����, ���. ������ �����������-���������.: ����� ���������� =%.4f �\n\n", time / CLOCKS_PER_SEC);
	printf("����� ���������� =%.4f �, ��������� ������� � ����.\n\n", time / CLOCKS_PER_SEC);


	/*������� ����������=================================================================*/
	printf("������� ����������\n");
	printf("������ ������� %d\n\n", count);
	for (int i = 0; i < count; i++)
	{
		items[i] = rand() % 100;
	}
	printf("1. ��������� ����� ������\n");
	start = clock();
	qs(items, count / 2, count - 1);
	end = clock();
	time = end - start;
	fprintf(file, "������� ����������, ���. ������ �� ��������: ����� ���������� =%.4f �\n", time / CLOCKS_PER_SEC);
	printf("����� ���������� =%.4f �, ��������� ������� � ����.\n\n", time / CLOCKS_PER_SEC);

	for (int i = 0; i < count; i++)
	{
		items[i] = i;
	}
	printf("2. �������� ������ �� �����������:\n");
	start = clock();
	qs(items, count / 2, count - 1);
	end = clock();
	time = end - start;
	fprintf(file, "������� ����������, ���. ������ �� �����������: ����� ���������� =%.4f �\n", time / CLOCKS_PER_SEC);
	printf("����� ���������� =%.4f �, ��������� ������� � ����.\n\n", time / CLOCKS_PER_SEC);

	for (int i = 0; i < count; i++)
	{
		items[i] = count - i;
	}
	printf("3. �������� ������ �� ��������:\n");
	start = clock();
	qs(items, count / 2, count - 1);
	end = clock();
	time = end - start;
	fprintf(file, "������� ����������, ���. ������ �� ��������: ����� ���������� =%.4f �\n", time / CLOCKS_PER_SEC);
	printf("����� ���������� =%.4f �, ��������� ������� � ����.\n\n", time / CLOCKS_PER_SEC);

	for (int i = 0; i < count; i++)
	{
		if (i < count / 2) {
			items[i] = i;
		}
		else {
			items[i] = count - i;
		}
	}
	printf("4. �������� ������ �� ����. �� �������� �������, ������ - �� ��������\n");
	start = clock();
	shell(items, count);
	end = clock();
	time = end - start;
	fprintf(file, "������� �., ���. ������ �����������-���������.: ����� ���������� =%.4f �\n\n", time / CLOCKS_PER_SEC);
	printf("����� ���������� =%.4f �, ��������� ������� � ����.\n\n", time / CLOCKS_PER_SEC);

	/*quicksort=================================================================*/

	printf("Quicksort\n");
	printf("������ ������� %d\n\n", count);
	for (int i = 0; i < count; i++)
	{
		items[i] = rand() % 100;
	}
	printf("1. ��������� ����� ������\n");
	start = clock();
	qsort(items, count, sizeof(int), (int(*) (const void*, const void*))comp);
	end = clock();
	time = end - start;
	fprintf(file, "Qsort, ��������� ����� ������: ����� ���������� =%.4f �\n", time / CLOCKS_PER_SEC);
	printf("����� ���������� =%.4f �, ��������� ������� � ����.\n\n", time / CLOCKS_PER_SEC);

	for (int i = 0; i < count; i++)
	{
		items[i] = i;
	}
	printf("2. �������� ������ �� �����������:\n");
	start = clock();
	qsort(items, count, sizeof(int), (int(*) (const void*, const void*))comp);
	end = clock();
	time = end - start;
	fprintf(file, "Qsort, ���. ������ �� �����������: ����� ���������� =%.4f �\n", time / CLOCKS_PER_SEC);
	printf("����� ���������� =%.4f �, ��������� ������� � ����.\n\n", time / CLOCKS_PER_SEC);

	for (int i = 0; i < count; i++)
	{
		items[i] = count - i;
	}
	printf("3. �������� ������ �� ��������:\n");
	start = clock();
	qsort(items, count, sizeof(int), (int(*) (const void*, const void*))comp);
	end = clock();
	time = end - start;
	fprintf(file, "Qsort, ���. ������ �� ��������: ����� ���������� =%.4f �\n", time / CLOCKS_PER_SEC);
	printf("����� ���������� =%.4f �, ��������� ������� � ����.\n\n", time / CLOCKS_PER_SEC);

	for (int i = 0; i < count; i++)
	{
		if (i < count / 2) {
			items[i] = i;
		}
		else {
			items[i] = count - i;
		}
	}
	printf("4. �������� ������ �� ����. �� �������� �������, ������ - �� ��������\n");
	start = clock();
	qsort(items, count, sizeof(int), (int(*) (const void*, const void*))comp);
	end = clock();
	time = end - start;
	fprintf(file, "Qsort, ���. ������ �����������-���������.: ����� ���������� =%.4f �\n", time / CLOCKS_PER_SEC);
	printf("����� ���������� =%.4f �, ��������� ������� � ����.\n\n", time / CLOCKS_PER_SEC);
	fclose(file);
}

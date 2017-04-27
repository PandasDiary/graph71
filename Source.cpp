#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<locale.h>


int main()
{
	setlocale(LC_ALL, "rus");
	char symb;
	int **A;
	int count_space = 0, edgecount, minedgecount=1000000, stroka;
	FILE *txt = fopen("file.txt", "r");
	if ((txt = fopen("file.txt", "r")) == NULL)
	{
		printf("Error");
		exit(-1);
	}
	do
	{
		fscanf(txt, "%c", &symb);
		if (symb == ' ') count_space++;
		if (symb == '\n') break;
	} while (symb != EOF);
	int n = count_space + 1; // Число строк и столбцов
	A = (int**)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		A[i] = (int*)malloc(n * sizeof(int));
	}
	fseek(txt, 0, SEEK_SET); // Сдвинуть каретку потока в начало файла
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			fscanf(txt, "%i", &A[i][j]);
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			printf("%i ", A[i][j]);
			if (j%n == (n - 1))	printf("\n");
		}
	////
	for (int i = 0; i < n; i++)
	{
		edgecount = 0;
		for (int j = 0; j < n; j++)
		{
			if ((A[i][j] != 0)&&(i!=j)) edgecount++;
		}
		if (edgecount < minedgecount)
		{
			minedgecount = edgecount;
			stroka = i;
		}
	}
	//Проверка на окончание слова
	int number;
	number = minedgecount % 100;
	if ((number>10)&&(number<15))
		printf("Надо удалить как минимум %i ребер\n", minedgecount);
	else
	{
		number = number % 10;
		if (number == 0) printf("Надо удалить как минимум %i ребер\n", minedgecount);
		if (number == 1) printf("Надо удалить как минимум %i ребро\n", minedgecount);
		if ((number > 1)&&(number<5)) printf("Надо удалить как минимум %i ребра\n", minedgecount);
		if (number > 4) printf("Надо удалить как минимум %i ребер\n", minedgecount);
	}
	///
	printf("Ребра:\n");
	for (int j = 0; j < n; j++)
		if ((A[stroka][j] != 0) && (stroka != j))
		{
			stroka++; //Для вывода номера ребра не с 0, а с 1
			j++;
			printf("Из точки %i в точку %i\n", stroka, j);
			stroka--;
			j--;
		}
	system("pause");
	free(A);
	fclose(txt);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

void Enter(char** A, int n, int m) {
	int i; // счетчик циклов

	rewind(stdin);

	for (i = 0; i < n; i++)
	{
		printf("A[%d] : ", i);
		fgets(A[i], m + 1, stdin);
		rewind(stdin);
	}

	printf("Строки матрицы:\n");
	for (i = 0; i < n; i++)
	{
		printf("A[%d] : ", i);
		puts(A[i]);
	}
	// вывод текста
}

int WordFind(char** A, int n, int m) {
	int i; // переменная для цикла
	int j = 0; // индекс по строке

	int flag = 0;
	//int temp = 0; // для преобразования строки в число


	int temp = 0; // для подсчета числа
	int num = 0; // число

	for (i = 0; i < n; i++)
	{
		while (A[i][j] && A[i][j] != '.' && flag != 1)
		{
			/*
			if (((int)(A[i][j]) > 32 && (int)(A[i][j]) < 48 || (int)(A[i][j]) > 57))
			{
				temp = 0;
				num = 0;
				printf("В строке есть буква. Строка с индексом %d пропущена. ", i);
				break;
			}
			// если есть символ-не-цифра, то прекращаем цикл
			*/


			if (A[i][j] == ' ')
			{
				num += temp;
				flag = 1;
				temp = 0;
			}
			// зануляем число при знаке пробела

			if ((int)(A[i][j]) >= 48 && (int)(A[i][j]) <= 57)
			{
				temp = temp * 10 + (A[i][j] - '0');
			}
			j++;
		}

		if (A[i][j] == '\0' || A[i][j] == '.')
		{
			num += temp;
			flag = 1;
			temp = 0;
		}

		if (num == 0)
		{
			printf("Число %d строки не обнаружено.\n", i);
		}
		else
		{
			printf("Число %d строки равно : %d\n", i, num);
			return (num);
		}
		
		

		flag = 0;
		num = 0;
		temp = 0;
		j = 0;
		// зануляем найденное число, индекс начала строки j, temp и индикатор flag
	}


}

int main() {
	setlocale(LC_ALL, "");

	int number; // кол-во матриц для ввода
	int n; // кол-во строк
	int m; // кол-во символов в строке

	int a; // счетчик основного цикла
	int i, j; // счетчики внутренних циклов

	printf("Введите кол-во матриц: ");
	scanf_s("%d", &number);

	printf("Введите кол-во строк в матрице:");
	scanf_s("%d", &n);
	// ввод кол-ва строк

	printf("Введите размерность строки:");
	scanf_s("%d", &m);
	// ввод кол-ва символов

	char** A = (char**)malloc(n * sizeof(char*));
	for (i = 0; i < n; i++)
	{
		A[i] = (char*)malloc((m + 1) * sizeof(char));
	}
	// создание дин. массива строк

	int* B = (int*)malloc(n * sizeof(int));
	// создание дин. массива для преобразованных чисел

	for (a = 0; a < number; a++) // цикл по всем матрицам
	{
		printf("\nМатрица %d:\n", a);
		Enter(A, n, m); // вызов функции ввода и вывода матрицы

		B[a] = WordFind(A, n, m); // вызов функции поиска слов
		printf("\nB[%d] = %d", a, B[a]);
		
	}

	for (i = 0; i < n; i++)
	{
		free(A[i]);
	}
	free(A);

	free(B);

	return 0;
}
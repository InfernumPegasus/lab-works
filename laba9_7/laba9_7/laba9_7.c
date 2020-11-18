#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <malloc.h>

/*int clearStdin() {

}*/

int main() {
	setlocale(LC_ALL, "");

	int n; // кол-во строк
	int m; // размер строки

	printf_s("Введите кол-во строк: ");
	scanf_s("%d", &n);

	rewind(stdin); // очистка поля ввода

	printf_s("Введите кол-во символов: ");
	scanf_s("%d", &m);

	rewind(stdin); // очистка поля ввода

	int i, j;

	char** A = (char*)malloc(n * sizeof(char*)); // создание строки на n символов
	for (i = 0; i < n + 1; i++)
	{
		A[i] = (char*)malloc((m + 1) * sizeof(char));
	}

	for (i = 0; i < n; i++)
	{
		printf_s("A[%d] : ", i);
		fgets(A[i], m + 1, stdin); // ввод строки
	}

	
	int sum = 0;

	printf_s("\nsum = %d\n", sum);

	rewind(stdin);
	/*for (i = 0; i < n; i++)
	{
		if (A[i] == '\n')
		{
			break;
		}
		printf_s("\nкод %d элемента строки: %d\n", i + 1, (int)(A[i]));
	}
	*/
	return 0;
}
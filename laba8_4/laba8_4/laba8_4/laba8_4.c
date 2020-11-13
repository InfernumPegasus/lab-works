#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>

int clearStdin() // функция для проверки
{
	int rv = 1, ch;
	while (1) {
		ch = getchar();
		if (ch == '\n' || ch == EOF) {
			break;
		}
		rv = 0;
	}
	return rv;
}

int main() {
	setlocale(LC_ALL, "Rus");

	int isEmpty, readCount; // переменные для проверки

	int lenS; // длина строки s

	printf_s("Введите длину первой строки: ");
	while (1)
	{
		readCount = scanf_s("%d", &lenS);
		isEmpty = clearStdin();
		if (readCount == 1 && isEmpty != 0 && lenS > 0)
		{
			break;
		}
		printf_s("Неправильный формат числа. Попробуйте снова: ");
	}
	// проверка на ввод длины строки

	char* s = (char*)malloc((lenS + 1) * sizeof(char));
	// создание дин. с кол-вом символов lenS

	printf("Введите строку s: ");
	fgets(s, lenS + 1, stdin);	// ввод строки s

	printf_s("Строка s: ");
	puts(s);
	// вывод строки s
	rewind(stdin);

	int lenA; // длина строки a

	printf_s("Введите длину строки a: ");
	while (1)
	{
		readCount = scanf_s("%d", &lenA);
		isEmpty = clearStdin();
		if (readCount == 1 && isEmpty != 0 && lenA > 0)
		{
			break;
		}
		printf_s("Неправильный формат числа. Попробуйте снова: ");
	}
	// проверка на ввод длины строки

	rewind(stdin);
	// очистка поля ввода

	char* a = (char*)malloc((lenA + 1) * sizeof(char));
	// создание дин. строки с кол-вом символов lenA

	printf("Введите строку a: ");
	fgets(a, lenA + 1, stdin);
	// ввод строки a
	printf_s("Строка a: ");
	puts(a);
	
	int k;		// индекс для преобразования строки s
	int i, j;	// счетчики для циклов
	int match;	// переменная для поиска совпадения
	
	for (i = k = 0; s[i] != '\0'; i++)
	{
		match = 0;
		for (j = 0; a[j] != '\0'; j++)
		{
			if (s[i] == a[j])
			{
				match = 1;
			}
		}
		if (!match) //если совпадений не было, преобразовываем k-й элемент к виду i-го элемента
		{
			s[k] = s[i];
			k++;
		}
	}
	s[k] = '\0'; // "удаляем" "лишние" символы строк

	printf_s("Итоговая строка: ");
	fputs(s, stdout);
	// вывод преобразованной строки s

	return 0;
}

/*-------------------------------------------------------------------------------------------*/
// пример со статическими строками через функцию squeeze()

/*#include <stdio.h>

void squeeze(char s1[], char s2[])
{
	int i, j, k, match;

	for (i = k = 0; s1[i] != '\0'; i++)
	{
		match = 0;
		for (j = 0; s2[j] != '\0'; j++)
		{
			if (s1[i] == s2[j])
			{
				match = 1;
			}
		}
		if (!match) //если совпадений не было
		{
			s1[k] = s1[i];
			k++;
		}
	}
	s1[k] = '\0';
}
//функция удаляет из строки 1 все символы, которые есть в строке 2

int main()
{
	char line1[] = "12345ggggg6789", line2[] = "g25g4";

	squeeze(line1, line2);

	printf("%s", line1);
	return 0;
}
*/
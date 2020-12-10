#include <stdio.h>
#include <stdlib.h>
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

void wordAmount(char** text, int n, int size) { // функция для подсчета слов в тексте
    int i; // счетчик для цикла
    int j; // счетчик для цикла
    int temp = 0;
    int amount = 0; // кол-во слов в тексте

    for (i = 0; i < n; i++)
    {
        for (j = 0; text[i][j]; j++)
        {
            if (text[i][j] == ' ' || text[i][j] == '.' || text[i][j] == ',' || text[i][j] == '!' || text[i][j] == '\n')
            {
                temp = 0;
            }
            else if (temp == 0)
            {
                temp = 1;
                amount++; // общее число слов
            }
        }
        // поиск и подсчет слов

    }
    printf("Кол-во слов в тексте: %d\n", amount);
}

void wordEquality(char** text, int n, int size)
{
    int i; // счетчик для строк
    int j = 0; // счетчик по символам каждой строки
    int first, second; // индексы первого и последнего символа в слове
    int amount = 0; // кол-во подходящих слов
    int flag = 0;

    for (int i = 0; i < n; i++)
    {
        while (text[i][j] == ' ' && text[i][j] != '\0')
        {
            j++;
        }
        // скипаем пробелы

        while (text[i][j] != '\0')
        {
            if (!isspace(text[i][j]))
            {
                if (flag == 0)
                {
                    first = j;
                    flag = 1;
                }
            }
            if (!isspace(text[i][j]) && !ispunct(text[i][j]))
            {
                second = j;
            }
            // идем по символам, пока он не станет равным пробелу или знаку

            if (text[i][j] == ' ' || ispunct(text[i][j]) || text[i][j] == '\n')
            {
                if (flag == 1 && second != 0)
                {
                    if (text[i][first] == text[i][second])
                    {
                        amount++;
                        flag = 0;
                        second = 0;
                        first = 0;
                    }
                }
            }
            j++;
        }
        j = 0;
    }
    printf("Количество слов, где первый и последний символ совпадает: %d", amount);

}

int main() {
    setlocale(LC_ALL, "");

    int isEmpty, readCount; // переменные для проверки ввода

    int n; // кол-во строк
    int size; // кол-во символов в строке
    int i; // счетчик цикла

    printf("Введите кол-во строк:\n");
    while (1)
    {
        readCount = scanf_s("%d", &n);
        isEmpty = clearStdin();
        if (readCount == 1 && isEmpty != 0 && n > 0)
        {
            break;
        }
        printf_s("Wrong number. Try again:\n");
    }
    // проверка на вводимое число строк

    printf("Введите кол-во символов в строке:\n");
    while (1)
    {
        readCount = scanf_s("%d", &size);
        isEmpty = clearStdin();
        if (readCount == 1 && isEmpty != 0 && size > 0)
        {
            break;
        }
        printf_s("Wrong number. Try again:\n");
    }
    // проверка на вводимое число длины строки

    char** text = (char**)malloc(n * sizeof(char*));
    for (i = 0; i < n; i++)
    {
        text[i] = (char*)malloc((size + 1) * sizeof(char));
    }
    // создание массива строк

    rewind(stdin);

    printf("Строки:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d: ", i);
        fgets(text[i], size, stdin);
        rewind(stdin);
    }
    // ввод строк с клавиатуры

    wordAmount(text, n, size); // вызов функции

    wordEquality(text, n, size); // вызов функции

    for (i = 0; i < n; i++)
    {
        free(text[i]);
    }
    free(text);

    return 0;
}

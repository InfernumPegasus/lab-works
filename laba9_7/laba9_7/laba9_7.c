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

int main() {
    setlocale(LC_ALL, "");

    int isEmpty, readCount; // переменные для проверки ввода

    int string_num; // кол-во строк
    int char_num; // кол-во символов в строке

    printf("Введите количество строк в тексте: ");
    while (1)
    {
        readCount = scanf_s("%d", &string_num);
        isEmpty = clearStdin();
        if (readCount == 1 && isEmpty != 0 && string_num > 0)
        {
            break;
        }
        printf_s("Wrong number. Try again:\n");
    }
    // проверка на вводимое число

    printf("Введите количество символов в строке: ");
    while (1)
    {
        readCount = scanf_s("%d", &char_num);
        isEmpty = clearStdin();
        if (readCount == 1 && isEmpty != 0 && char_num > 0)
        {
            break;
        }
        printf_s("Wrong number. Try again:\n");
    }
    // проверка на вводимое число

    int i; // счетчик

    char** A = (char**)malloc(string_num * sizeof(char*));
    for (i = 0; i < string_num; i++)
    {
        A[i] = (char*)malloc((char_num + 1) * sizeof(char));
    }
    // создание дин. массива символов

    printf("Введите текст\n");
    rewind(stdin); // сбрасывает индикатор ошибок потока данных и устанавливает указатель на начало 

    for (i = 0; i < string_num; i++)
    {
        fgets(A[i], char_num, stdin);
    }
    // ввод строки

    int j = 0; // счетчик по символам
    int temp = 0; // для подсчета числа
    int sum = 0; // сумма чисел

    for (i = 0; i < string_num; i++)
    {
        while (A[i][j] && A[i][j] != '.')
        {
            if (((int)(A[i][j]) > 32 && (int)(A[i][j]) < 48 || (int)(A[i][j]) > 57))
            {
                temp = 0;
                sum = 0;
                printf("В строке есть буква. Строка с индексом %d пропущена. ", i);
                break;
            }
            // если есть символ-не-цифра, то прекращаем цикл

            if (A[i][j] == ' ')
            {
                sum += temp;
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
            sum += temp;
            temp = 0;
        }

        printf("Сумма %d строки равна : %d\n", i, sum);

        sum = 0;
        temp = 0;
        j = 0;
        // зануляем сумму, индекс начала строки j и temp
    }

    for (i = 0; i < string_num; i++) {
        free(A[i]);
    }
    free(A);
    // очистка памяти от массива A

    return 0;
}
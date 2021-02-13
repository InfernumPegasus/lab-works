#include <ctype.h>
#include <stdio.h>
#include <locale.h>

void TextEnter(char** A, int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        printf("A[%d] : ", i);
        //rewind(stdin);
        fgets(A[i], m, stdin);
        rewind(stdin);
    }
}

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


int atoi(char *str)
{
  /*
  *  Проверка str на NULL.
  */
  if (str == NULL)
    return 0;

  int n = 0;

  /*
  *  isspace использовал только для обобщения задачи. Вместо (и далее в коде)
  *  этого спокойно можно использовать *str == ' ' (*str != ' ').
  */
  while (*str != '\0' && !isspace(*str))
    n = 10 * n + *str++ - '0';

  return n;
}

/*
*  Возвращает указатель на первое числовое слово. Если его нет, то NULL.
*/
char *strfnd(char *str)
{
  char *tmp[2];

  tmp[1] = str;

  /*
  *  isnum показывает, является ли текущее слово числовым.
  */
  int isnum = 1;

  while (*tmp[1] != '\0') {
    /*
    *  Пропускаем пробелы.
    */
    while (isspace(*tmp[1]))
      ++tmp[1];

    /*
    *  Запоминаем начало слова.
    */
    tmp[0] = tmp[1];

    /*
    *  Проверяем все символы слова до пробела (либо конца строки).
    */
    while (!isspace(*tmp[1]) && *tmp[1] != '\0')
      /*
      *  Если найдётся не цифра, то isnum никогда (в этом слове) не станет 1.
      *
      *  isnum &= ... - то же, что и isnum = isnum && ...
      */
      isnum &= isdigit(*tmp[1]++);

    /*
    *  Возвращает указатель на это слово, если оно числовое.
    *
    *  Если бы не было второго условия, то функция всегда возращала бы конец
    *  строки, если бы ничего не нашла.
    */
    if (isnum && *tmp[1] != '\0')
      return tmp[0];

    /*
    *  Сбрасываем isnum для следующего слова.
    */
    isnum = 1;
  }

  /*
  *  Возвращает NULL, если ничего не нашли.
  */
  return NULL;
}

int main()
{
  setlocale(LC_ALL, "");
  int isEmpty, readCount; // переменные для проверки ввода

  printf("Введите кол-во матриц для обработки: ");
  int a; // кол-во матриц
   while (1)
    {
        readCount = scanf_s("%d", &a);
        isEmpty = clearStdin();
        if (readCount == 1 && isEmpty != 0 && a > 0)
        {
            break;
        }
        printf_s("Wrong number. Try again\na = ");
    }
    // проверка на вводимое число

  printf("Введите кол-во строк в тексте: ");
  int n; // кол-во строк текста
  while (1)
    {
        readCount = scanf_s("%d", &n);
        isEmpty = clearStdin();
        if (readCount == 1 && isEmpty != 0 && n > 0)
        {
            break;
        }
        printf_s("Wrong number. Try again\nn = ");
    }
    // проверка на вводимое число

  printf("Введите кол-во символов в строке: ");
  int m; // кол-во символов в строке
  while (1)
    {
        readCount = scanf_s("%d", &m);
        isEmpty = clearStdin();
        if (readCount == 1 && isEmpty != 0 && m > 0)
        {
            break;
        }
        printf_s("Wrong number. Try again\nm = ");
    }
    // проверка на вводимое число

  rewind(stdin);
  system("CLS");

  int i;

  char** A = (char**)malloc(n * sizeof(char*));
  for(i = 0; i < n; i++)
  {
      A[i] = (char*)malloc((m + 1) * sizeof(char));
  }
    //    создание дин. массива строк

  int k = 0; // индекс для массива вывода
  int* mas = (int*)calloc(n, sizeof(int));
   // создание дин. массива для хранения чисел

  int j;

  for(j = 0; j < a; j++)
  {
      printf("Матрица %d:\n", j + 1);

  TextEnter(A, n, m);  // ввод текста по строкам

  printf("\nВведенный текст:\n");

  for(i = 0; i < n; i++)
  {
      printf("Строка %d : ", i + 1);
      puts(A[i]);
  }
    // вывод текста
      k = 0;
for(i = 0; i < n; i++)
{
    char *tmp = strfnd(A[i]);
    mas[k] = atoi(tmp);
    printf("Число %d строки: %d\n", k + 1, mas[k]);
    k++;
}
    //  вывод числа на экран
    getchar();
    rewind(stdin);
    system("CLS");
  }
    // обработка матриц

  for(i = 0; i < n; i++)
  {
      free(A[i]);
  }
  free(A);
  free(mas);
  // очистка памяти от массивов

  system("pause");
  return 0;
}

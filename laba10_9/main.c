#include <ctype.h>
#include <stdio.h>
#include <locale.h>

int clearStdin() // ������� ��� ��������
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
  *  �������� str �� NULL.
  */
  if (str == NULL)
    return 0;

  int n = 0;

  /*
  *  isspace ����������� ������ ��� ��������� ������. ������ (� ����� � ����)
  *  ����� �������� ����� ������������ *str == ' ' (*str != ' ').
  */
  while (*str != '\0' && !isspace(*str))
    n = 10 * n + *str++ - '0';

  return n;
}

/*
*  ���������� ��������� �� ������ �������� �����. ���� ��� ���, �� NULL.
*/
char *strfnd(char *str)
{
  char *tmp[2];

  tmp[1] = str;

  /*
  *  isnum ����������, �������� �� ������� ����� ��������.
  */
  int isnum = 1;

  while (*tmp[1] != '\0') {
    /*
    *  ���������� �������.
    */
    while (isspace(*tmp[1]))
      ++tmp[1];

    /*
    *  ���������� ������ �����.
    */
    tmp[0] = tmp[1];

    /*
    *  ��������� ��� ������� ����� �� ������� (���� ����� ������).
    */
    while (!isspace(*tmp[1]) && *tmp[1] != '\0')
      /*
      *  ���� ������� �� �����, �� isnum ������� (� ���� �����) �� ������ 1.
      *
      *  isnum &= ... - �� ��, ��� � isnum = isnum && ...
      */
      isnum &= isdigit(*tmp[1]++);

    /*
    *  ���������� ��������� �� ��� �����, ���� ��� ��������.
    *
    *  ���� �� �� ���� ������� �������, �� ������� ������ ��������� �� �����
    *  ������, ���� �� ������ �� �����.
    */
    if (isnum && *tmp[1] != '\0')
      return tmp[0];

    /*
    *  ���������� isnum ��� ���������� �����.
    */
    isnum = 1;
  }

  /*
  *  ���������� NULL, ���� ������ �� �����.
  */
  return NULL;
}

int main()
{
  setlocale(LC_ALL, "");
  int isEmpty, readCount; // ���������� ��� �������� �����

  printf("������� ���-�� ������ ��� ���������: ");
  int a; // ���-�� ������
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
    // �������� �� �������� �����

  printf("������� ���-�� ����� � ������: ");
  int n; // ���-�� ����� ������
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
    // �������� �� �������� �����

  printf("������� ���-�� �������� � ������: ");
  int m; // ���-�� �������� � ������
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
    // �������� �� �������� �����

  rewind(stdin);
  //system("CLS");

  int i;

  char** A = (char**)malloc(n * sizeof(char*));
  for(i = 0; i < n; i++)
  {
      A[i] = (char*)malloc((m + 1) * sizeof(char));
  }
    //    �������� ���. ������� �����

  int k = 0; // ������ ��� ������� ������
  int* mas = (int*)calloc(n, sizeof(int));
   // �������� ���. ������� ��� �������� �����

  for(a = 0; a < n; a++)
  {
      printf("������� %d:\n", a);
      k = 0;
      for(i = 0; i < n; i++)
  {
      printf("������ %d : ", i);
      fgets(A[i], m + 1, stdin);
      rewind(stdin);
  }
    //    ���� ������ �� �������


  printf("\n��������� �����:\n");

  for(i = 0; i < n; i++)
  {
      printf("������ %d : ", i);
      puts(A[i]);
  }
    // ����� ������

for(i = 0; i < n; i++)
{
    char *tmp = strfnd(A[i]);
    mas[k] = atoi(tmp);
    printf("����� %d ������: %d\n", k, mas[k]);
    k++;
    //printf("����� ������: %d\n", atoi(tmp));
}
    //  ����� ����� �� �����

  }
  // ��������� ������

  for(i = 0; i < n; i++)
  {
      free(A[i]);
  }
  free(A);
  free(mas);
  // ������� ������ �� ��������

  system("pause");
  return 0;
}

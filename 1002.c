#include <stdio.h>
#include <string.h>
#define TODIGIT(X) ((X)-'0')

const char* pinyin[] =
{
  "ling", "yi", "er", "san", "si",
  "wu", "liu", "qi", "ba", "jiu"
};

void pinyin_print(const char *_str);

int main()
{
  char strbuf[101];
  int sum = 0;

  scanf("%s", strbuf);
  for (int i = 0; i < strlen(strbuf); i++)
    {
      sum += TODIGIT(strbuf[i]);
    }

  sprintf(strbuf, "%d", sum);
  pinyin_print(strbuf);
  return 0;
}

void pinyin_print(const char *_str)
{
  int i;
  for (i = 0; i < strlen(_str) - 1; i++)
    {
      printf("%s", pinyin[_str[i] - '0']);
      putchar(' ');
    }
  printf("%s", pinyin[_str[i] - '0']);
  putchar('\n');
}


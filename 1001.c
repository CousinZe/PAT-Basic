#include <stdio.h>

int fold(int _number);

int main()
{
  int number;
  while (~scanf("%d", &number))
    {
      int steps = 0;

      while (number != 1)
        {
          number = fold(number);
          steps++;
        }
      printf("%d\n", steps);
    }
  return 0;
}

int fold(int _number)
{
  if (_number%2 != 0)
    {
      return (_number*3+1)/2;
    }
  else
    {
      return _number/2;
    }
}

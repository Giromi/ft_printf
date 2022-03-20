#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "printf.h"
#include <string.h>

int	main(void)
{
	char 	*input;
	char 	*long_str;
	char 	c[10] = {'a', '\0', '1'};
	char 	*str[10] = {"Mong", "areyousmile", "minsu bab"};
	int		n[10] = {123, -123, INT_MAX, INT_MIN, 0};
	int		nx;
	int		len;
	int		idx;

	idx = 0;
	len = 2147483646;
	long_str = (char *)calloc(len + 1, 1);
	memset(long_str, 'a', len);
	// printf("\n=> cnt : %d\t[CASE s-9]\n\n", printf("%s", long_str));
	// printf("\n=> cnt : %d\t[CASE s-10]\n\n", printf("%s %s", "Hello", long_str));
	// printf("\n=> cnt : %d\t[CASE s-10]\n\n", printf("%.2147483647s", long_str));
	// printf("\n=> cnt : %d\t[CASE s-10]\n\n", printf("%.2147483647d", 123));
	// printf("\n=> cnt : %d\t[CASE s-10]\n\n", printf("%.2147483648s", long_str));
	// printf("\n=> cnt : %d\t[CASE s-10]\n\n", printf("%.2147483648d", 123));
	// printf("\n=> cnt : %d\t[CASE s-10]\n\n", printf("Abc%1000000000dabc %1000000000ddabc %1000000000d%.", 123, 456, 789)); printf("|ABC%1000000000dabc %1000000000ddabc %1000000000d%.", 123, 456, 789); // printf("\n=> cnt : %d\t[CASE s-10]\n\n", printf("%2147483646d %s", 123, long_str));
	// printf("abc\n%1000000000d\nabc\n %1000000000dd\nabc\n %1000000000d\n", 123, 456, 789);
    //
    //
	// for (int i = 0; i < 3; i++)
	// {
	//     printf("\t=> cnt : %d\t[CASE  c-01] <- %c\n\n", printf("|%c|", c[i]) - 2, c[i]);
	//     printf("\t=> cnt : %d\t[CASE  c-02] <- %c\n\n", printf("|%10c|", c[i]) - 2, c[i]);
	//     printf("\t=> cnt : %d\t[CASE  c-03] <- %c\n\n", printf("|%010c|", c[i]) - 2, c[i]);
	//     printf("\t=> cnt : %d\t[CASE  c-04] <- %c\n\n", printf("|%-10c|", c[i]) - 2, c[i]);
	//     printf("\t=> cnt : %d\t[CASE  c-05] <- %c\n\n", printf("|%-010c|", c[i]) - 2, c[i]);
	//     printf("\t=> cnt : %d\t[CASE  c-06] <- %c\n\n", printf("|%+010c|", c[i]) - 2, c[i]);
	//     printf("\t=> cnt : %d\t[CASE  c-07] <- %c\n\n", printf("|%5.3c|", c[i]) - 2, c[i]);
	//     printf("\t");
	// }
    //
    //
	// for (int i = 0; i < 3; i++)
	// {
	//     printf("\t=> cnt : %d\t[CASE  s-01]\n\n", printf("|%s|", str[i]) - 2, str[i]);
	//     printf("\t=> cnt : %d\t[CASE  s-02]\n\n", printf("|%10s|", str[i]) - 2, str[i]);
	//     printf("\t=> cnt : %d\t[CASE  s-03]\n\n", printf("|%-10s|", str[i]) - 2, str[i]);
	//     printf("\t=> cnt : %d\t[CASE  s-04]\n\n", printf("|%010s|", str[i]) - 2, str[i]);
	//     printf("\t=> cnt : %d\t[CASE  s-05]\n\n", printf("|%-010s|", str[i]) - 2, str[i]);
	//     printf("\t=> cnt : %d\t[CASE  s-06]\n\n", printf("|%-010.3s|", str[i]) - 2, str[i]);
	//     printf("\t=> cnt : %d\t[CASE  s-07]\n\n", printf("|% 010.3s|", str[i]) - 2, str[i]);
	//     printf("\t=> cnt : %d\t[CASE  s-08]\n\n", printf("|%020.3s|", str[i]) - 2, str[i]);
	//     printf("\t=> cnt : %d\t[CASE  s-09]\n\n", printf("|%020.3s|", str[i]) - 2, str[i]);
	//     printf("\t=> cnt : %d\t[CASE  s-09]\n\n", printf("|%+20.9s|", str[i]) - 2, str[i]);
	//     printf("\t=> cnt : %d\t[CASE  s-09]\n\n", printf("|%+20.s|", str[i]) - 2, str[i]);
	//     printf("\t=> cnt : %d\t[CASE  s-09]\n\n", printf("|% 20.0s|", str[i]) - 2, str[i]);
	// }
    //
    //
	// for (int i = 0; i < 5; i++)
	// {
	//     printf("\t=> cnt : %d\t[CASE  d-01] <- %d\n\n", printf("|%d|", n[i]) - 2, n[i]);
	//     printf("\t=> cnt : %d\t[CASE  d-02] <- %d\n\n", printf("|%20d|", n[i]) - 2, n[i]);
	//     printf("\t=> cnt : %d\t[CASE  d-03] <- %d\n\n", printf("|%020d|", n[i]) - 2, n[i]);
	//     printf("\t=> cnt : %d\t[CASE  d-08] <- %d\n\n", printf("|%-20d|", n[i]) - 2, n[i]);
	//     printf("\t=> cnt : %d\t[CASE  d-05] <- %d\n\n", printf("|%-020.14d|", n[i]) - 2, n[i]);
	//     printf("\t=> cnt : %d\t[CASE  d-06] <- %d\n\n", printf("|%-20.14d|", n[i]) - 2, n[i]);
	//     printf("\t=> cnt : %d\t[CASE  d-07] <- %d\n\n", printf("|%- 020d|", n[i]) - 2, n[i]);
	//     printf("\t=> cnt : %d\t[CASE  d-07] <- %d\n\n", printf("|%- 020.14d|", n[i]) - 2, n[i]);
	//     printf("\t=> cnt : %d\t[CASE  d-08] <- %d\n\n", printf("|%+020.14d|", n[i]) - 2, n[i]);
	//     printf("\t=> cnt : %d\t[CASE  d-09] <- %d\n\n", printf("|%+ 20.14d|", n[i]) - 2, n[i]);
	//     printf("\t=> cnt : %d\t[CASE  d-10] <- %d\n\n", printf("|%+ 20.14d|", n[i]) - 2, n[i]);
	//     printf("\t=> cnt : %d\t[CASE  d-09] <- %d\n\n", printf("|%+ 20.0d|", n[i]) - 2, n[i]);
	//     printf("\t");
	// }
    //
	// for (int i = 0; i < 5; i++)
	// {
	//     printf("\t=> cnt : %d\t[CASE  u-01] <- %d\n\n", printf("|%u|", n[i]) - 2, n[i]);
	//     printf("\t=> cnt : %d\t[CASE  u-02] <- %d\n\n", printf("|%18u|", n[i]) - 2, n[i]);
	//     printf("\t=> cnt : %d\t[CASE  u-03] <- %d\n\n", printf("|%018u|", n[i]) - 2, n[i]);
	//     printf("\t=> cnt : %d\t[CASE  u-04] <- %d\n\n", printf("|%-18u|", n[i]) - 2, n[i]);
	//     printf("\t=> cnt : %d\t[CASE  u-05] <- %d\n\n", printf("|%-18.6u|", n[i]) - 2, n[i]);
	//     printf("\t=> cnt : %d\t[CASE  u-06] <- %d\n\n", printf("|%-18.15u|", n[i]) - 2, n[i]);
	//     printf("\t=> cnt : %d\t[CASE  u-07] <- %d\n\n", printf("|%- 018u|", n[i]) - 2, n[i]);
	//     printf("\t=> cnt : %d\t[CASE  u-08] <- %d\n\n", printf("|%+018u|", n[i]) - 2, n[i]);
	//     printf("\t=> cnt : %d\t[CASE  u-09] <- %d\n\n", printf("|%+ 18u|", n[i]) - 2, n[i]);
	//     printf("\t=> cnt : %d\t[CASE  u-10] <- %d\n\n", printf("|%+18u|", n[i]) - 2, n[i]);
	// }
    //
	// for (int i = 0; i < 5; i++)
	// {
	//     printf("\t=> cnt : %d\t[CASE  x-01]\n", printf("|%01.x|", n[i]) - 2, n[i]);
	//     printf("\t=> cnt : %d\t[CASE  x-02]\n", printf("|%01.3x|", n[i]) - 2, n[i]);
	// }
    //
	// for (int i = 0; i < 5; i++)
	// {
	//     printf("\t=> cnt : %d\t[CASE  X-01]\n", printf("|%01.X|", n[i]) - 2, n[i]);
	//     printf("\t=> cnt : %d\t[CASE  X-02]\n", printf("|%01.3X|", n[i]) - 2, n[i]);
	// }
    //
	// printf("\t=> cnt : %d\t[CASE  %%-01]\n\n", printf("|%%|") - 2);
	// printf("\t=> cnt : %d\t[CASE  %%-02]\n\n", printf("|%10%|") - 2);
	// printf("\t=> cnt : %d\t[CASE  %%-03]\n\n", printf("|%10.%|") - 2);
	// printf("\t=> cnt : %d\t[CASE  %%-04]\n\n", printf("|%10.0%|") - 2);
	// printf("\t=> cnt : %d\t[CASE  %%-05]\n\n", printf("|%10.3%|") - 2);
	// // printf("\t=> cnt : %d\t[CASE  p-01]\n\n", printf("|%p|", &n) - 2);
	// // printf("\t=> cnt : %d\t[CASE  p-02]\n\n", printf("|%18p|", &n) - 2);
	// // printf("\t=> cnt : %d\t[CASE  p-03]\n\n", printf("|%018p|", &n) - 2);
	// // printf("\t=> cnt : %d\t[CASE  p-04]\n\n", printf("|%-18p|", &n) - 2);
	// // printf("\t=> cnt : %d\t[CASE  p-05]\n\n", printf("|%-18.6p|", &n) - 2);
	// // printf("\t=> cnt : %d\t[CASE  p-06]\n\n", printf("|%-18.15p|", &n) - 2);
	// // printf("\t=> cnt : %d\t[CASE  p-07]\n\n", printf("|%- 018p|", &n) - 2);
	// // printf("\t=> cnt : %d\t[CASE  p-08]\n\n", printf("|%+018p|", &n) - 2);
	// // printf("\t=> cnt : %d\t[CASE  p-09]\n\n", printf("|%+ 18p|", &n) - 2);
	// // printf("\t=> cnt : %d\t[CASE  p-10]\n\n", printf("|%+18p|", &n) - 2);
	// // printf("\t=> cnt : %d\t[CASE  p-11]\n\n", printf("|%+18p|", -1) - 2);
	// // system("leaks -q printf.out");
	return (0);
}

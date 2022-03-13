#include <stdio.h>
#include <limits.h>
#include "printf.h"
#include <string.h>

int	main(void)
{
	char 	*input;
	char 	*str;
	char 	*long_str;
	char 	c;
	int		n[10] = {123, -123, INT_MAX, INT_MIN, 0};
	int		len;
	int		idx;


	// c = 'a';
	// printf("\n=> cnt : %d\t[CASE  c-01]\n\n", printf("|%c|", c) - 2);
	// printf("\n=> cnt : %d\t[CASE  c-02]\n\n", printf("|%10c|", c) - 2);
	// printf("\n=> cnt : %d\t[CASE  c-03]\n\n", printf("|%010c|", c) - 2);
	// printf("\n=> cnt : %d\t[CASE  c-04]\n\n", printf("|%-10c|", c) - 2);
	// printf("\n=> cnt : %d\t[CASE  c-05]\n\n", printf("|%-010c|", c) - 2);
	// c = '\0';
	// printf("\n=> cnt : %d\t[CASE  c-06]\n\n", printf("|%c|", c) - 2);
	// printf("\n=> cnt : %d\t[CASE  c-07]\n\n", printf("|%10c|", c) - 2);
	// printf("\n=> cnt : %d\t[CASE  c-08]\n\n", printf("|%010c|", c) - 2);
	// printf("\n=> cnt : %d\t[CASE  c-09]\n\n", printf("|%-10c|", c) - 2);
	// printf("\n=> cnt : %d\t[CASE  c-10]\n\n", printf("|%-010c|", c) - 2);
    //
    //
	// str = "Hello";
	// printf("\n=> cnt : %d\t[CASE  s-01]\n\n", printf("|%s|", str) - 2);
	// printf("\n=> cnt : %d\t[CASE  s-02]\n\n", printf("|%10s|", str) - 2);
	// printf("\n=> cnt : %d\t[CASE  s-03]\n\n", printf("|%-10s|", str) - 2);
	// printf("\n=> cnt : %d\t[CASE  s-04]\n\n", printf("|%010s|", str) - 2);
	// printf("\n=> cnt : %d\t[CASE  s-05]\n\n", printf("|%-010s|", str) - 2);
	// printf("\n=> cnt : %d\t[CASE  s-06]\n\n", printf("|%-010.3s|", str) - 2);
	// printf("\n=> cnt : %d\t[CASE  s-07]\n\n", printf("|% 010.3s|", str) - 2);
	// printf("\n=> cnt : %d\t[CASE  s-08]\n\n", printf("|%.12s|", "hi there") - 2);

	for (int i = 0; i < 5; i++)
	{
		printf("\n=> cnt : %d\t[CASE  d-01] <- %d\n\n", printf("|%d|", n[i]) - 2, n[i]);
		printf("\n=> cnt : %d\t[CASE  d-02] <- %d\n\n", printf("|%20d|", n[i]) - 2, n[i]);
		printf("\n=> cnt : %d\t[CASE  d-03] <- %d\n\n", printf("|%020d|", n[i]) - 2, n[i]);
		printf("\n=> cnt : %d\t[CASE  d-08] <- %d\n\n", printf("|%-20d|", n[i]) - 2, n[i]);
		printf("\n=> cnt : %d\t[CASE  d-05] <- %d\n\n", printf("|%-020.14d|", n[i]) - 2, n[i]);
		printf("\n=> cnt : %d\t[CASE  d-06] <- %d\n\n", printf("|%-20.14d|", n[i]) - 2, n[i]);
		printf("\n=> cnt : %d\t[CASE  d-07] <- %d\n\n", printf("|%- 020d|", n[i]) - 2, n[i]);
		printf("\n=> cnt : %d\t[CASE  d-07] <- %d\n\n", printf("|%- 020.14d|", n[i]) - 2, n[i]);
		printf("\n=> cnt : %d\t[CASE  d-08] <- %d\n\n", printf("|%+020.14d|", n[i]) - 2, n[i]);
		printf("\n=> cnt : %d\t[CASE  d-09] <- %d\n\n", printf("|%+ 20.14d|", n[i]) - 2, n[i]);
		printf("\n=> cnt : %d\t[CASE  d-10] <- %d\n\n", printf("|%+ 20.14d|", n[i]) - 2, n[i]);
		printf("\n=> cnt : %d\t[CASE  d-09] <- %d\n\n", printf("|%+ 20.0d|", n[i]) - 2, n[i]);
		printf("\n");
	}
    //
    //
    //
	// n = 123;
	// printf("\n=> cnt : %d\t[CASE  u-01]\n\n", printf("|%u|", n) - 2);
	// printf("\n=> cnt : %d\t[CASE  u-02]\n\n", printf("|%18u|", n) - 2);
	// printf("\n=> cnt : %d\t[CASE  u-03]\n\n", printf("|%018u|", n) - 2);
	// printf("\n=> cnt : %d\t[CASE  u-04]\n\n", printf("|%-18u|", n) - 2);
	// printf("\n=> cnt : %d\t[CASE  u-05]\n\n", printf("|%-18.6u|", n) - 2);
	// printf("\n=> cnt : %d\t[CASE  u-06]\n\n", printf("|%-18.15u|", n) - 2);
	// printf("\n=> cnt : %d\t[CASE  u-07]\n\n", printf("|%- 018u|", n) - 2);
	// printf("\n=> cnt : %d\t[CASE  u-08]\n\n", printf("|%+018u|", n) - 2);
	// printf("\n=> cnt : %d\t[CASE  u-09]\n\n", printf("|%+ 18u|", n) - 2);
	// printf("\n=> cnt : %d\t[CASE  u-10]\n\n", printf("|%+18u|", n) - 2);
	// n = -123;
	// printf("\n=> cnt : %d\t[CASE  u-01]\n\n", printf("|%u|", n) - 2);
	// printf("\n=> cnt : %d\t[CASE  u-02]\n\n", printf("|%18u|", n) - 2);
	// printf("\n=> cnt : %d\t[CASE  u-03]\n\n", printf("|%018u|", n) - 2);
	// printf("\n=> cnt : %d\t[CASE  u-04]\n\n", printf("|%-18u|", n) - 2);
	// printf("\n=> cnt : %d\t[CASE  u-05]\n\n", printf("|%-18.6u|", n) - 2);
	// printf("\n=> cnt : %d\t[CASE  u-06]\n\n", printf("|%-18.15u|", n) - 2);
	// printf("\n=> cnt : %d\t[CASE  u-07]\n\n", printf("|%- 018u|", n) - 2);
	// printf("\n=> cnt : %d\t[CASE  u-08]\n\n", printf("|%+018u|", n) - 2);
	// printf("\n=> cnt : %d\t[CASE  u-09]\n\n", printf("|%+ 18u|", n) - 2);
	// printf("\n=> cnt : %d\t[CASE  u-10]\n\n", printf("|%+18u|", n) - 2);
    //
    //
	// n = 0x123;
	// printf("\n=> cnt : %d\t[CASE  x-01]\n", printf("|%01.x|", n) - 2);
	// printf("\n=> cnt : %d\t[CASE  x-02]\n", printf("|%01.3x|", n) - 2);
    //
	// printf("\n=> cnt : %d\t[CASE  X-01]\n", printf("|%01.X|", n) - 2);
	// printf("\n=> cnt : %d\t[CASE  X-02]\n", printf("|%01.3X|", n) - 2);
    //
	// printf("\n=> cnt : %d\t[CASE  %%-01]\n\n", printf("|%%|") - 2);
	// printf("\n=> cnt : %d\t[CASE  %%-02]\n\n", printf("|%10%|") - 2);
	// printf("\n=> cnt : %d\t[CASE  %%-03]\n\n", printf("|%10.%|") - 2);
	// printf("\n=> cnt : %d\t[CASE  %%-04]\n\n", printf("|%10.0%|") - 2);
	// printf("\n=> cnt : %d\t[CASE  %%-05]\n\n", printf("|%10.3%|") - 2);
    //
	// printf("\n=> cnt : %d\t[CASE  p-01]\n\n", printf("|%p|", &n) - 2);
	// printf("\n=> cnt : %d\t[CASE  p-02]\n\n", printf("|%18p|", &n) - 2);
	// printf("\n=> cnt : %d\t[CASE  p-03]\n\n", printf("|%018p|", &n) - 2);
	// printf("\n=> cnt : %d\t[CASE  p-04]\n\n", printf("|%-18p|", &n) - 2);
	// printf("\n=> cnt : %d\t[CASE  p-05]\n\n", printf("|%-18.6p|", &n) - 2);
	// printf("\n=> cnt : %d\t[CASE  p-06]\n\n", printf("|%-18.15p|", &n) - 2);
	// printf("\n=> cnt : %d\t[CASE  p-07]\n\n", printf("|%- 018p|", &n) - 2);
	// printf("\n=> cnt : %d\t[CASE  p-08]\n\n", printf("|%+018p|", &n) - 2);
	// printf("\n=> cnt : %d\t[CASE  p-09]\n\n", printf("|%+ 18p|", &n) - 2);
	// printf("\n=> cnt : %d\t[CASE  p-10]\n\n", printf("|%+18p|", &n) - 2);
	// printf("\n=> cnt : %d\t[CASE  p-11]\n\n", printf("|%+18p|", -1) - 2);

	// idx = 0;
	// len = 2147483646;
	// long_str = (char *)calloc(len + 1, 1);
	// memset(long_str, 'a', len);
	// printf("\n=> cnt : %d\t[CASE s-9]\n\n", printf("%s", long_str));
	// printf("\n=> cnt : %d\t[CASE s-10]\n\n", printf("%s %s", "Hello", long_str));
	// printf("\n=> cnt : %d\t[CASE s-10]\n\n", printf("%2147483646d", 123));
	// printf("\n=> cnt : %d\t[CASE s-10]\n\n", printf("%2147483646d %s", 123, long_str));
	// printf("\n=> cnt : %d\t[CASE s-10]\n\n", printf("%1001000000d %1001000000d %500d", 123, 123, 123));


	// system("leaks -q printf.out");
	return (0);
}

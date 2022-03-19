#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"
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

	// for (int i = 0; i < 3; i++)
	// {
	//     ft_printf("\t=> cnt : %d\t[CASE  c-01] <- %c\n\n", ft_printf("|%c|", c[i]) - 2, c[i]);
	//     ft_printf("\t=> cnt : %d\t[CASE  c-02] <- %c\n\n", ft_printf("|%10c|", c[i]) - 2, c[i]);
	//     ft_printf("\t=> cnt : %d\t[CASE  c-03] <- %c\n\n", ft_printf("|%010c|", c[i]) - 2, c[i]);
	//     ft_printf("\t=> cnt : %d\t[CASE  c-04] <- %c\n\n", ft_printf("|%-10c|", c[i]) - 2, c[i]);
	//     ft_printf("\t=> cnt : %d\t[CASE  c-05] <- %c\n\n", ft_printf("|%-010c|", c[i]) - 2, c[i]);
	//     ft_printf("\t=> cnt : %d\t[CASE  c-06] <- %c\n\n", ft_printf("|%+010c|", c[i]) - 2, c[i]);
	//     ft_printf("\t=> cnt : %d\t[CASE  c-07] <- %c\n\n", ft_printf("|%5.3c|", c[i]) - 2, c[i]);
	//     ft_printf("\t");
	// }
    //
    //
	// for (int i = 0; i < 3; i++)
	// {
	//     ft_printf("\t=> cnt : %d\t[CASE  s-01]\n\n", ft_printf("|%s|", str[i]) - 2, str[i]);
	//     ft_printf("\t=> cnt : %d\t[CASE  s-02]\n\n", ft_printf("|%10s|", str[i]) - 2, str[i]);
	//     ft_printf("\t=> cnt : %d\t[CASE  s-03]\n\n", ft_printf("|%-10s|", str[i]) - 2, str[i]);
	//     ft_printf("\t=> cnt : %d\t[CASE  s-04]\n\n", ft_printf("|%010s|", str[i]) - 2, str[i]);
	//     ft_printf("\t=> cnt : %d\t[CASE  s-05]\n\n", ft_printf("|%-010s|", str[i]) - 2, str[i]);
	//     ft_printf("\t=> cnt : %d\t[CASE  s-06]\n\n", ft_printf("|%-010.3s|", str[i]) - 2, str[i]);
	//     ft_printf("\t=> cnt : %d\t[CASE  s-07]\n\n", ft_printf("|% 010.3s|", str[i]) - 2, str[i]);
	//     ft_printf("\t=> cnt : %d\t[CASE  s-08]\n\n", ft_printf("|%020.3s|", str[i]) - 2, str[i]);
	//     ft_printf("\t=> cnt : %d\t[CASE  s-09]\n\n", ft_printf("|%020.3s|", str[i]) - 2, str[i]);
	//     ft_printf("\t=> cnt : %d\t[CASE  s-09]\n\n", ft_printf("|%+20.9s|", str[i]) - 2, str[i]);
	//     ft_printf("\t=> cnt : %d\t[CASE  s-09]\n\n", ft_printf("|%+20.s|", str[i]) - 2, str[i]);
	//     ft_printf("\t=> cnt : %d\t[CASE  s-09]\n\n", ft_printf("|% 20.0s|", str[i]) - 2, str[i]);
	// }
    //
    //
	// for (int i = 0; i < 5; i++)
	// {
	//     ft_printf("\t=> cnt : %d\t[CASE  d-01] <- %d\n\n", ft_printf("|%d|", n[i]) - 2, n[i]);
	//     ft_printf("\t=> cnt : %d\t[CASE  d-02] <- %d\n\n", ft_printf("|%20d|", n[i]) - 2, n[i]);
	//     ft_printf("\t=> cnt : %d\t[CASE  d-03] <- %d\n\n", ft_printf("|%020d|", n[i]) - 2, n[i]);
	//     ft_printf("\t=> cnt : %d\t[CASE  d-08] <- %d\n\n", ft_printf("|%-20d|", n[i]) - 2, n[i]);
	//     ft_printf("\t=> cnt : %d\t[CASE  d-05] <- %d\n\n", ft_printf("|%-020.14d|", n[i]) - 2, n[i]);
	//     ft_printf("\t=> cnt : %d\t[CASE  d-06] <- %d\n\n", ft_printf("|%-20.14d|", n[i]) - 2, n[i]);
	//     ft_printf("\t=> cnt : %d\t[CASE  d-07] <- %d\n\n", ft_printf("|%- 020d|", n[i]) - 2, n[i]);
	//     ft_printf("\t=> cnt : %d\t[CASE  d-07] <- %d\n\n", ft_printf("|%- 020.14d|", n[i]) - 2, n[i]);
	//     ft_printf("\t=> cnt : %d\t[CASE  d-08] <- %d\n\n", ft_printf("|%+020.14d|", n[i]) - 2, n[i]);
	//     ft_printf("\t=> cnt : %d\t[CASE  d-09] <- %d\n\n", ft_printf("|%+ 20.14d|", n[i]) - 2, n[i]);
	//     ft_printf("\t=> cnt : %d\t[CASE  d-10] <- %d\n\n", ft_printf("|%+ 20.14d|", n[i]) - 2, n[i]);
	//     ft_printf("\t=> cnt : %d\t[CASE  d-09] <- %d\n\n", ft_printf("|%+ 20.0d|", n[i]) - 2, n[i]);
	//     ft_printf("\t");
	// }
    //
	// for (int i = 0; i < 5; i++)
	// {
	//     ft_printf("\t=> cnt : %d\t[CASE  u-01] <- %d\n\n", ft_printf("|%u|", n[i]) - 2, n[i]);
	//     ft_printf("\t=> cnt : %d\t[CASE  u-02] <- %d\n\n", ft_printf("|%18u|", n[i]) - 2, n[i]);
	//     ft_printf("\t=> cnt : %d\t[CASE  u-03] <- %d\n\n", ft_printf("|%018u|", n[i]) - 2, n[i]);
	//     ft_printf("\t=> cnt : %d\t[CASE  u-04] <- %d\n\n", ft_printf("|%-18u|", n[i]) - 2, n[i]);
	//     ft_printf("\t=> cnt : %d\t[CASE  u-05] <- %d\n\n", ft_printf("|%-18.6u|", n[i]) - 2, n[i]);
	//     ft_printf("\t=> cnt : %d\t[CASE  u-06] <- %d\n\n", ft_printf("|%-18.15u|", n[i]) - 2, n[i]);
	//     ft_printf("\t=> cnt : %d\t[CASE  u-07] <- %d\n\n", ft_printf("|%- 018u|", n[i]) - 2, n[i]);
	//     ft_printf("\t=> cnt : %d\t[CASE  u-08] <- %d\n\n", ft_printf("|%+018u|", n[i]) - 2, n[i]);
	//     ft_printf("\t=> cnt : %d\t[CASE  u-09] <- %d\n\n", ft_printf("|%+ 18u|", n[i]) - 2, n[i]);
	//     ft_printf("\t=> cnt : %d\t[CASE  u-10] <- %d\n\n", ft_printf("|%+18u|", n[i]) - 2, n[i]);
	// }
    //
	// for (int i = 0; i < 5; i++)
	// {
	//     ft_printf("\t=> cnt : %d\t[CASE  x-01]\n", ft_printf("|%01.x|", n[i]) - 2, n[i]);
	//     ft_printf("\t=> cnt : %d\t[CASE  x-02]\n", ft_printf("|%01.3x|", n[i]) - 2, n[i]);
	// }
    //
	// for (int i = 0; i < 5; i++)
	// {
	//     ft_printf("\t=> cnt : %d\t[CASE  X-01]\n", ft_printf("|%01.X|", n[i]) - 2, n[i]);
	//     ft_printf("\t=> cnt : %d\t[CASE  X-02]\n", ft_printf("|%01.3X|", n[i]) - 2, n[i]);
	// }
    //
	// ft_printf("\t=> cnt : %d\t[CASE  %%-01]\n\n", ft_printf("|%%|") - 2);
	// ft_printf("\t=> cnt : %d\t[CASE  %%-02]\n\n", ft_printf("|%10%|") - 2);
	// ft_printf("\t=> cnt : %d\t[CASE  %%-03]\n\n", ft_printf("|%10.%|") - 2);
	// ft_printf("\t=> cnt : %d\t[CASE  %%-04]\n\n", ft_printf("|%10.0%|") - 2);
	// ft_printf("\t=> cnt : %d\t[CASE  %%-05]\n\n", ft_printf("|%10.3%|") - 2);
	// ft_printf("\t=> cnt : %d\t[CASE  p-01]\n\n", ft_printf("|%p|", &n) - 2);
	// ft_printf("\t=> cnt : %d\t[CASE  p-02]\n\n", ft_printf("|%18p|", &n) - 2);
	// ft_printf("\t=> cnt : %d\t[CASE  p-03]\n\n", ft_printf("|%018p|", &n) - 2);
	// ft_printf("\t=> cnt : %d\t[CASE  p-04]\n\n", ft_printf("|%-18p|", &n) - 2);
	// ft_printf("\t=> cnt : %d\t[CASE  p-05]\n\n", ft_printf("|%-18.6p|", &n) - 2);
	// ft_printf("\t=> cnt : %d\t[CASE  p-06]\n\n", ft_printf("|%-18.15p|", &n) - 2);
	// ft_printf("\t=> cnt : %d\t[CASE  p-07]\n\n", ft_printf("|%- 018p|", &n) - 2);
	// ft_printf("\t=> cnt : %d\t[CASE  p-08]\n\n", ft_printf("|%+018p|", &n) - 2);
	// ft_printf("\t=> cnt : %d\t[CASE  p-09]\n\n", ft_printf("|%+ 18p|", &n) - 2);
	// ft_printf("\t=> cnt : %d\t[CASE  p-10]\n\n", ft_printf("|%+18p|", &n) - 2);
	// ft_printf("\t=> cnt : %d\t[CASE  p-11]\n\n", ft_printf("|%+18p|", -1) - 2);

	// idx = 0;
	// len = 2147483646;
	// long_str = (char *)calloc(len + 1, 1);
	// memset(long_str, 'a', len);
	// ft_printf("\n=> cnt : %d\t[CASE s-9]\n\n", ft_printf("%s", long_str));
	// ft_printf("\n=> cnt : %d\t[CASE s-10]\n\n", ft_printf("%s %s", "Hello", long_str));
	ft_printf("\n=> cnt : %d\t[CASE d-long]\n\n", ft_printf("%.2147483646d", 123));
	ft_printf("\n=> cnt : %d\t[CASE d-long]\n\n", ft_printf("%.2147483647d", 123));
	// ft_printf("\n=> cnt : %d\t[CASE s-10]\n\n", ft_printf("%2147483646d %s", 123, long_str));
	// ft_printf("\n=> cnt : %d\t[CASE s-10]\n\n", ft_printf("Hello %1001000000d world %1001000000x nice%1001000000u tomato", 123, -123, -123));

	// system("leaks -q ft_printf.out");
	return (0);
}

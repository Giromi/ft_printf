#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	char 	*input;
	char 	c;
	int		n;
	int		cnt2;
    //
	// c = 'a';
	// ft_printf("\t=> cnt : %d\t[CASE 1]\n", ft_printf("|%c|", c) - 2);
	// ft_printf("\t=> cnt : %d\t[CASE 2]\n", ft_printf("|%10c|", c) - 2);
	// ft_printf("\t=> cnt : %d\t[CASE 3]\n", ft_printf("|%010c|", c) - 2);
	// ft_printf("\t=> cnt : %d\t[CASE 4]\n", ft_printf("|%-10c|", c) - 2);
	// ft_printf("\t=> cnt : %d\t[CASE 5]\n", ft_printf("|%-010c|", c) - 2);
    //
	// c = '\0';
	// ft_printf("\t=> cnt : %d\t[CASE 6]\n", ft_printf("|%c|", c) - 2);
	// ft_printf("\t=> cnt : %d\t[CASE 7]\n", ft_printf("|%10c|", c) - 2);
	// ft_printf("\t=> cnt : %d\t[CASE 8]\n", ft_printf("|%010c|", c) - 2);
	// ft_printf("\t=> cnt : %d\t[CASE 9]\n", ft_printf("|%-10c|", c) - 2);
	// ft_printf("\t=> cnt : %d\t[CASE 10]\n", ft_printf("|%-010c|", c) - 2);

	// n = 123;
	// ft_printf("\t=> cnt : %d\t[CASE 11]\n", ft_printf("|%d|", n) - 2);
	// ft_printf("\t=> cnt : %d\t[CASE 12]\n", ft_printf("|%10d|", n) - 2);
	// ft_printf("\t=> cnt : %d\t[CASE 13]\n", ft_printf("|%010d|", n) - 2);
	// ft_printf("\t=> cnt : %d\t[CASE 18]\n", ft_printf("|%-10d|", n) - 2);
	// ft_printf("\t=> cnt : %d\t[CASE 15]\n", ft_printf("|%-010.6d|", n) - 2);
	// ft_printf("\t=> cnt : %d\t[CASE 16]\n", ft_printf("|%-10.5d|", n) - 2);
	// ft_printf("\t=> cnt : %d\t[CASE 17]\n", ft_printf("|%- 010d|", n) - 2);
	// ft_printf("\t=> cnt : %d\t[CASE 18]\n", ft_printf("|%+010d|", n) - 2);
	// ft_printf("\t=> cnt : %d\t[CASE 19]\n", ft_printf("|%+ 10d|", n) - 2);


	// ft_printf("\t=> cnt : %d\t[CASE P-1]\n", ft_printf("|%p|", &n) - 2);
	// ft_printf("\t=> cnt : %d\t[CASE P-2]\n", ft_printf("|%18p|", &n) - 2);
	// ft_printf("\t=> cnt : %d\t[CASE P-3]\n", ft_printf("|%018p|", &n) - 2);
	// ft_printf("\t=> cnt : %d\t[CASE P-4]\n", ft_printf("|%-18p|", &n) - 2);
	// ft_printf("\t=> cnt : %d\t[CASE P-5]\n", ft_printf("|%-18.6p|", &n) - 2);
	// ft_printf("\t=> cnt : %d\t[CASE P-6]\n", ft_printf("|%-18.15p|", &n) - 2);
	// ft_printf("\t=> cnt : %d\t[CASE P-7]\n", ft_printf("|%- 018p|", &n) - 2);
	// ft_printf("\t=> cnt : %d\t[CASE P-8]\n", ft_printf("|%+018p|", &n) - 2);
	// ft_printf("\t=> cnt : %d\t[CASE P-9]\n", ft_printf("|%+ 18p|", &n) - 2);
	// ft_printf("\t=> cnt : %d\t[CASE P-10]\n", ft_printf("|%+18p|", &n) - 2);
	ft_printf("\t=> cnt : %d\t[CASE P-11]\n", ft_printf("|%+18p|", -1) - 2);
	return (0);
}

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	char 	*input;
	char 	c;
	int		cnt1;
	int		cnt2;
    //
	// c = 'a';
	// ft_putstr_fd("\n>>>>>>>>> [CASE 1] <<<<<<<<<\n", 1);
	// ft_printf("\t=> cnt : %d\n", ft_printf("|%c|", c) - 2);
    //
	// ft_putstr_fd("\n>>>>>>>>> [CASE 2] <<<<<<<<<\n", 1);
	// ft_printf("\t=> cnt : %d\n", ft_printf("|%10c|", c) - 2);
    // //
	// ft_putstr_fd("\n>>>>>>>>> [CASE 3] <<<<<<<<<\n", 1);
	// ft_printf("\t=> cnt : %d\n", ft_printf("|%010c|", c) - 2);
    //
	// ft_putstr_fd("\n>>>>>>>>> [CASE 4] <<<<<<<<<\n", 1);
	// ft_printf("\t=> cnt : %d\n", ft_printf("|%-10c|", c) - 2);
    //
	// ft_putstr_fd("\n>>>>>>>>> [CASE 5] <<<<<<<<<\n", 1);
	// ft_printf("\t=> cnt : %d\n", ft_printf("|%-010c|", c) - 2);
    //
	c = '\0';
	ft_printf("\t=> cnt : %d\t[CASE 6]\n", ft_printf("|%c|", c) - 2);

	// ft_printf("\t=> cnt : %d\t[CASE 7]\n", ft_printf("|%10c|", c) - 2);
    // //
	// ft_putstr_fd("\n>>>>>>>>> [CASE 8] <<<<<<<<<\n", 1);
	// ft_printf("\t=> cnt : %d\n", ft_printf("|%010c|", c) - 2);
    //
	// ft_putstr_fd("\n>>>>>>>>> [CASE 9] <<<<<<<<<\n", 1);
	// ft_printf("\t=> cnt : %d\n", ft_printf("|%-10c|", c) - 2);
    //
	// ft_putstr_fd("\n>>>>>>>>> [CASE 10] <<<<<<<<<\n", 1);
	// ft_printf("\t=> cnt : %d\n", ft_printf("|%-010c|", c) - 2);
	return (0);
}

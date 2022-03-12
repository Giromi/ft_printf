#include <stdio.h>
#include "ft_printf.h"

//test...

int	main(void)
{
	int		bits = CV_D;
	int		cnt;
	int		len;
	char	*input;
	size_t	n;
	char	dst[30];

	cnt = ft_printf("|%d|", 10) - 2;
	printf("\t=> cnt : %d (ft_printf)\n", cnt);
	cnt = printf("|%d|", 10) - 2;
	printf("\t=> cnt : %d (printf)\n", cnt);

}

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int		bits = CV_D;
	int		cnt;
	int		len;
	char	*input;
	size_t	n;
	char	dst[30];

	input = "|%d|";
	cnt = ft_printf(input, 10) - 2;
	printf("=> cnt : %d (ft_printf)", cnt);

	cnt = ft_printf(input, 10) - 2;
	cnt = printf(input, 10) - 2;
	printf("=> cnt : %d (printf)", cnt);
}

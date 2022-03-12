#include <stdio.h>

void	printf_cmp(char *input)
{
	int cnt;

	ft_putstr("|");
	full_len = printf(input, arg);
	printf("\t = full_len : %d (my_printf)\n", full_len);
	printf("|\t => full_len : %d (real_printf)\n", full_len);
}

int	main(void)
{
	int		bits = 0;
	int		cnt;
	char	*input;

	input = "|%d|";
	cnt = ft_printf(input, 10) - 2;
	printf("=> cnt : %d (ft_printf)", cnt);

	cnt = ft_printf(input, 10) - 2;
	cnt = printf(input, 10) - 2;
	printf("=> cnt : %d (printf)", cnt);


}

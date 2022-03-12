#include <stdio.h>
#include "ft_printf.h"

static int	check_len_num_mem(size_t arg, int bits)
{
	int				len;
	int				base_num;
	unsigned int	num;

	len = 0;
	base_num = DEC;
	num = arg;
	if (bits & (CV_SX | CV_LX | CV_D))
		arg = num;
	if (bits & (CV_SX | CV_LX | CV_P))
		base_num = HEX;
	if (bits & PC_EXIST && arg == 0)
		return (0);
	if (arg == 0)
		return (1);
	if (bits & CV_D && (int)arg < 0)
		arg = -(unsigned int)arg ;
	while (arg && (len++ < FINAL_LEN))
		arg /= base_num;
	return (len);
}


// void	printf_cmp(char *input)
// {
//     int cnt;
//
//     ft_putstr("|");
//     full_len = printf(input, arg);
//     printf("\t = full_len : %d (my_printf)\n", full_len);
//     printf("|\t => full_len : %d (real_printf)\n", full_len);
// }

int	main(void)
{
	int		bits = CV_SX;
	int		cnt;
	int		len;
	char	*input;
	size_t	n;
	char	dst[30];

	// input = "|%d|";
	// cnt = ft_printf(input, 10) - 2;
	// printf("=> cnt : %d (ft_printf)", cnt);
    //
	// cnt = ft_printf(input, 10) - 2;
	// cnt = printf(input, 10) - 2;
	// printf("=> cnt : %d (printf)", cnt);
	n = -123;
	len = check_len_num_mem(n, bits); dst[len] = '\0';
	convert_num_mem_base(dst, n, len, bits);
	printf("|%s| => %d\n", dst, len);
	printf("|%x|\n", (int)n);

	n = 0x12323;
	len = check_len_num_mem(n, bits); dst[len] = '\0';
	convert_num_mem_base(dst, n, len, bits);
	printf("|%s| => %d\n", dst, len);
	printf("|%x|\n", (int)n);
}

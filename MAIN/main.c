#include <stdio.h>
#include "ft_printf.h"



static int	make_len_num_mem(size_t arg, int bits)
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
	if (bits & (CV_SX | CV_LX) && (int)arg < 0)
		return (8);
	if (bits & CV_D && (int)arg < 0)
		arg = -(unsigned int)arg ;
	while (arg && (len++ != INT_MAX))
		arg /= base_num;
	return (len);
}


int	main(void)
{
	int	bits = 0;

	bits = CV_D;
	printf("%d\n", make_len_num_mem(123, bits));

	bits = CV_D;
	printf("%d\n", make_len_num_mem(-123, bits));

	bits = CV_D;
	printf("%d\n", make_len_num_mem(0, bits));

	bits = CV_SX;
	printf("%d\n", make_len_num_mem(-123, bits));

	bits = CV_LX;
	printf("%d\n", make_len_num_mem(0x123, bits));

	bits = CV_P;
	printf("%d\n", make_len_num_mem(&bits, bits));
}

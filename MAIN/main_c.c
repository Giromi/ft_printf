#include <stdio.h>
// #include "ft_printf.h"

int	ft_strchr_idx(const char *s, int c)
{
	int	idx;

	idx = 0;
	while (s[idx] && s[idx] != (char)c)
		idx++;
	return (idx);
}

int	main(void)
{
	// printf("|%010c|\n", 'A');
	// printf("|%010s|\n", "Hello");
	printf("%d\n", ft_strchr_idx("0123B", '4'));
	printf("%d\n", ft_strchr_idx("0123B", '4'));
	return (0);
}

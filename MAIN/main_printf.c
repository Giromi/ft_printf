#include <stdio.h>
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (fd < 0 || !s)
		return ;
	while (*s)
		ft_putchar_fd(*s++, fd);
}


int	main(void)
{
	char 	*input;
	char 	c;

	// printf("\n>>>>>>>>> [CASE 1] <<<<<<<<<\n");
	// printf("\t=> cnt : %d\n", printf("|%c|", 'a') - 2);
    //
	// printf("\n>>>>>>>>> [CASE 2] <<<<<<<<<\n");
	// printf("\t=> cnt : %d\n", printf("|%10c|", 'a') - 2);
    //
	// printf("\n>>>>>>>>> [CASE 2] <<<<<<<<<\n");
	// printf("\t=> cnt : %d\n", printf("|%10c|", c) - 2);
    // //
	// printf("\n>>>>>>>>> [CASE 3] <<<<<<<<<\n");
	// printf("\t=> cnt : %d\n", printf("|%010c|", c) - 2);
    //
	// printf("\n>>>>>>>>> [CASE 4] <<<<<<<<<\n");
	// printf("\t=> cnt : %d\n", printf("|%-10c|", c) - 2);
    //
	// printf("\n>>>>>>>>> [CASE 5] <<<<<<<<<\n");
	// printf("\t=> cnt : %d\n", printf("|%-010c|", c) - 2);

	c = '\0';
	printf("\t=> cnt : %d\t[CASE 6]\n", printf("|%c|", c) - 2);
	// printf("\t=> cnt : %d\t[CASE 7]\n", printf("|%10c|", c) - 2);
    // //
	// printf("\n>>>>>>>>> [CASE 8] <<<<<<<<<\n");
	// printf("\t=> cnt : %d\n", printf("|%010c|", c) - 2);
    //
	// printf("\n>>>>>>>>> [CASE 9] <<<<<<<<<\n");
	// printf("\t=> cnt : %d\n", printf("|%-10c|", c) - 2);
    //
	// printf("\n>>>>>>>>> [CASE 10] <<<<<<<<<\n");
	// printf("\t=> cnt : %d\n", printf("|%-010c|", c) - 2);
	// input = "|%c|"; c = 'a';
	// printf(">>>>>>>>> [CASE %s, %c]<<<<<<<<<\n", input, c);
	// cnt = printf(input, c) - 2;
	// printf("\t=> cnt : %d (printf)\n", cnt);
	// cnt = printf(input, c) - 2;
	// printf("\t=> cnt : %d (printf)\n\n", cnt);
    //
	// input = "|%10c|"; c = 'a';
	// printf(">>>>>>>>> [CASE %s, %c]<<<<<<<<<\n", input, c);
	// cnt = printf(input, c) - 2;
	// printf("\t=> cnt : %d (printf)\n", cnt);
	// cnt = printf(input, c) - 2;
	// printf("\t=> cnt : %d (printf)\n\n", cnt);
    //
	// input = "|%-10c|"; c = 'a';
	// printf(">>>>>>>>> [CASE %s, %c]<<<<<<<<<\n", input, c);
	// cnt = printf(input, c) - 2;
	// printf("\t=> cnt : %d (printf)\n", cnt);
	// cnt = printf(input, c) - 2;
	// printf("\t=> cnt : %d (printf)\n\n", cnt);
    //
	// input = "|%-010c|"; c = 'a';
	// printf(">>>>>>>>> [CASE %s, %c]<<<<<<<<<\n", input, c);
	// cnt = printf(input, c) - 2;
	// printf("\t=> cnt : %d (printf)\n", cnt);
	// cnt = printf(input, c) - 2;
	// printf("\t=> cnt : %d (printf)\n\n", cnt);
    //
	// input = "|% -010c|"; c = 'a';
	// printf(">>>>>>>>> [CASE %s, %c]<<<<<<<<<\n", input, c);
	// cnt = printf(input, c) - 2;
	// printf("\t=> cnt : %d (printf)\n", cnt);
	// cnt = printf(input, c) - 2;
	// printf("\t=> cnt : %d (printf)\n\n", cnt);
	//
	return (0);
}

#include <stdio.h>

int	main(void)
{
	char 	*input;
	char 	c;
	int		n;
    //
	// c = 'a';
	// printf("\t=> cnt : %d\t[CASE 1]\n", printf("|%c|", c) - 2);
	// printf("\t=> cnt : %d\t[CASE 2]\n", printf("|%10c|", c) - 2);
	// printf("\t=> cnt : %d\t[CASE 3]\n", printf("|%010c|", c) - 2);
	// printf("\t=> cnt : %d\t[CASE 4]\n", printf("|%-10c|", c) - 2);
	// printf("\t=> cnt : %d\t[CASE 5]\n", printf("|%-010c|", c) - 2);
    //
	// c = '\0';
	// printf("\t=> cnt : %d\t[CASE 6]\n", printf("|%c|", c) - 2);
	// printf("\t=> cnt : %d\t[CASE 7]\n", printf("|%10c|", c) - 2);
	// printf("\t=> cnt : %d\t[CASE 8]\n", printf("|%010c|", c) - 2);
	// printf("\t=> cnt : %d\t[CASE 9]\n", printf("|%-10c|", c) - 2);
	// printf("\t=> cnt : %d\t[CASE 10]\n", printf("|%-010c|", c) - 2);

	// n = 123;
	// printf("\t=> cnt : %d\t[CASE 11]\n", printf("|%d|", n) - 2);
	// printf("\t=> cnt : %d\t[CASE 12]\n", printf("|%10d|", n) - 2);
	// printf("\t=> cnt : %d\t[CASE 13]\n", printf("|%010d|", n) - 2);
	// printf("\t=> cnt : %d\t[CASE 18]\n", printf("|%-10d|", n) - 2);
	// printf("\t=> cnt : %d\t[CASE 15]\n", printf("|%-010.6d|", n) - 2);
	// printf("\t=> cnt : %d\t[CASE 16]\n", printf("|%-10.5d|", n) - 2);
	// printf("\t=> cnt : %d\t[CASE 17]\n", printf("|%- 010d|", n) - 2);
	// printf("\t=> cnt : %d\t[CASE 18]\n", printf("|%+010d|", n) - 2);
	// printf("\t=> cnt : %d\t[CASE 19]\n", printf("|%+ 10d|", n) - 2);
	printf("\t=> cnt : %d\t[CASE d-20]\n", printf("|%01.d|", 0) - 2);
	printf("\t=> cnt : %d\t[CASE d-21]\n", printf("%042.2d", 42000) - 2);

	// >>>>>>>>>>>>>>>>>>>>>>>>>>>> x test <<<<<<<<<<<<<<<<<<<<<<<<<<<< //
	printf("\t=> cnt : %d\t[CASE x-1]\n", printf("|%01.x|", 0) - 2);


	// printf("\t=> cnt : %d\t[CASE P-1]\n", printf("|%p|", &n) - 2);
	// printf("\t=> cnt : %d\t[CASE P-2]\n", printf("|%18p|", &n) - 2);
	// printf("\t=> cnt : %d\t[CASE P-3]\n", printf("|%018p|", &n) - 2);
	// printf("\t=> cnt : %d\t[CASE P-4]\n", printf("|%-18p|", &n) - 2);
	// printf("\t=> cnt : %d\t[CASE P-5]\n", printf("|%-18p|", &n) - 2);
	// printf("\t=> cnt : %d\t[CASE P-6]\n", printf("|%-18.5p|", &n) - 2);
	// printf("\t=> cnt : %d\t[CASE P-7]\n", printf("|%- 018p|", &n) - 2);
	// printf("\t=> cnt : %d\t[CASE P-8]\n", printf("|%+010p|", &n) - 2);
	// printf("\t=> cnt : %d\t[CASE P-9]\n", printf("|%+ 10p|", &n) - 2);
	// printf("\t=> cnt : %d\t[CASE P-10]\n", printf("|%+18p|", &n) - 2);
	// printf("\t=> cnt : %d\t[CASE P-11]\n", printf("|%+18p|", -1) - 2);

	// >>>>>>>>>>>>>>>>>>>>>>>>>>>> u test <<<<<<<<<<<<<<<<<<<<<<<<<<<< //
	// n = -123;
	// printf("\t=> cnt : %d\t[CASE U-1]\n", printf("|%u|", n) - 2);
	// printf("\t=> cnt : %d\t[CASE U-2]\n", printf("|%18u|", n) - 2);
	// printf("\t=> cnt : %d\t[CASE U-3]\n", printf("|%018u|", n) - 2);
	// printf("\t=> cnt : %d\t[CASE U-4]\n", printf("|%-18u|", n) - 2);
	// printf("\t=> cnt : %d\t[CASE U-5]\n", printf("|%-18.6u|", n) - 2);
	// printf("\t=> cnt : %d\t[CASE U-6]\n", printf("|%-18.15u|", n) - 2);
	// printf("\t=> cnt : %d\t[CASE U-7]\n", printf("|%- 018u|", n) - 2);
	// printf("\t=> cnt : %d\t[CASE U-8]\n", printf("|%+018u|", n) - 2);
	// printf("\t=> cnt : %d\t[CASE U-9]\n", printf("|%+ 18u|", n) - 2);
	// printf("\t=> cnt : %d\t[CASE U-10]\n", printf("|%+18u|", n) - 2);

	// >>>>>>>>>>>>>>>>>>>>>>>>>>>> %% test <<<<<<<<<<<<<<<<<<<<<<<<<<<< //
	// printf("\t=> cnt : %d\t[CASE %%-1]\n", printf("|%%|") - 2);

	// >>>>>>>>>>>>>>>>>>>>>>>>>>>> s test <<<<<<<<<<<<<<<<<<<<<<<<<<<< //
	printf("\t=> cnt : %d\t[CASE s-1]\n", printf("|%s|", "Hello") - 2);
	printf("\t=> cnt : %d\t[CASE s-2]\n", printf("|%10s|", "Hello") - 2);
	printf("\t=> cnt : %d\t[CASE s-3]\n", printf("|%-10s|", "Hello") - 2);
	printf("\t=> cnt : %d\t[CASE s-4]\n", printf("|%010s|", "Hello") - 2);
	printf("\t=> cnt : %d\t[CASE s-5]\n", printf("|%-010s|", "Hello") - 2);
	printf("\t=> cnt : %d\t[CASE s-6]\n", printf("|%-010.3s|", "Hello") - 2);
	printf("\t=> cnt : %d\t[CASE s-7]\n", printf("|% 010.3s|", "Hello") - 2);
	printf("\t=> cnt : %d\t[CASE s-8]\n", printf("|%.12s|", "hi there") - 2);
	return (0);
}
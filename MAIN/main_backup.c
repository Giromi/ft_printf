#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "ft_printf.h"
#include <stdlib.h>
#include <string.h>

int		print_memory(size_t nbr);
int		print_p(size_t mem);
void	hex_memory(size_t mem);
void	make_memory(size_t nbr, size_t cnt);

void ft_putchar(const char c)
{
	write(1, &c, 1);
}

void ft_putstr(const char *s)
{
	while (*s)
	{
		ft_putchar(*s);
		s++;
	}
}
// int	ft_putchar_rtn(const char c)
// {
//     return (write(1, &c, 1));
// }
// int	ft_putstr_rtn(const char *s)
// {
//     int	i;
//
//     i = 0;
//     while (s[i])
//         ft_putchar(s[i++]);
//     return (i);
// }
//
//
// int	ft_putnbr_rtn(int n)
// {
//     int	cnt;
//     if (n == INT_MIN)
//         return (ft_putstr_rtn(INT_MIN_STR));
//     cnt = 0;
//     if (n < 0)
//     {
//         cnt += ft_putchar_rtn('-');
//         n *= -1;
//     }
//     cnt += change_base_int(n, DEC_BASE, DEC);
//     return (cnt);
// }


static void	test_va(int	cnt, ...)
{
	va_list	ap;
	size_t	mem;

	va_start(ap, cnt);
	for (int i = 0; i < cnt; i++)
	{
		mem = va_arg(ap, size_t);
		printf("real : 0x%zx\n", mem);
		ft_putstr("my   : ");
		printf("my : "); print_p(mem); printf("\n");
	}
}

void	change_base_int(unsigned int nbr, char *base, unsigned int n, int cnt)
{
	if (cnt)
	{
		change_base_int(nbr / n, base, n, cnt - 1);
		ft_putchar(base[nbr % n]);
	}
}

void	input_dec_base(char *dst, unsigned int nbr, int len)
{
	if (len)
	{
		input_dec_base(dst, nbr / DEC, len - 1);
		if (!nbr)
			dst[len - 1] = '0';
		else
			dst[len - 1] = DEC_BASE[nbr % DEC];
	}
}

void	ft_inputnbr(char *str, t_gather *fwp, int n, int len)
{
	if ((fwp->bits & CV_U) || n >= 0)
		input_dec_base(str, n, len);
	else
		input_dec_base(str, -n, len);
}

int check_make_u_len(unsigned int arg, int *len)
{
	*len = 0;
	while (arg)
	{
		(*len)++;
		arg /= 10;
	}
	return (*len);
}

int check_make_di_len(int arg, int *len)
{
	*len = 0;
	while (arg)
	{
		(*len)++;
		arg /= 10;
	}
	return (*len);

}

int salloc_int(char **new, int len, char fill)
{
	*new = (char *)malloc((len + 1) * sizeof(char));
	if (!*new)
		return (ERROR);
	(*new)[len] = '\0';
	ft_memset(*new, fill, len); // + + 'len'
	return (SUCCESS);
}

void front_input(char *dst, char pl_sp)
{
	int	i;

	i = 0;
	while (dst[i++] && !ft_isdigit(dst[i]) && dst[i] == ' ')
		;
	dst[i - 1] = pl_sp;
}

int	isfg_plsp(t_gather *fwp)
{
	return ((fwp->bits & (FG_PLUS | FG_SPACE)) != 0);
}

char 	*setting_len(t_gather *fwp, int n, int *len, int *full_len)
{
	char	*dst;

	if (fwp->precision > *len)
		*len = fwp->precision;
	*full_len = *len;
	if ((fwp->bits & WD_EXIST) && (fwp->width > *len))
		*full_len = fwp->width;
	if ((isfg_plsp(fwp) && (*full_len == *len)))
		(*full_len)++;
	if (!(fwp->bits & FG_MINUS) && (fwp->bits & FG_ZERO)
			&& (salloc_int(&dst, *full_len, '0') == ERROR))
		return (NULL);
	else
		if (salloc_int(&dst, *full_len, ' ') == ERROR)
			return (NULL);
	return (dst);
}

char	*make_diu(t_gather *fwp, int n, int len)
{
	char	*dst;
	int	full_len;

	if (!(fwp->bits & CV_U) && n < 0)
		fwp->bits |= FG_PLUS;
	dst = setting_len(fwp, n, &len, &full_len);
	if (!dst)
		return (NULL);
	if (fwp->bits & FG_MINUS)
		ft_inputnbr(dst + isfg_plsp(fwp), fwp, n, len);
	else
		ft_inputnbr(dst + full_len - len, fwp, n, len);
	printf(", n = %d, width = %d, prec = %d\n\tlen = %d @ %p\n", n, fwp->width, fwp->precision, len ,dst);
	if (fwp->bits & CV_U)
		return (dst);
	if (n >= 0)
	{
		if (fwp->bits & FG_PLUS)
			front_input(dst, '+');
		else if (fwp->bits & FG_SPACE)
			front_input(dst, ' ');
	}
	else
		front_input(dst, '-');
	return (dst);
}

//test

//test
int	my_printf(const char *str, t_gather *fwp, int n, int len)
{
	char	*result;
	int		cnt;
	char	c;

	result = make_diu(fwp, n, len);
	cnt = (int)ft_strlen(result);
	printf("|%s|", result);
	free(result);
	return (cnt);
}

void	printf_cmp(char *input, int arg, int width, int precision, int *len, t_gather *fwp)
{
	char	*with_cv;
	int	full_len;

	if ((fwp->bits & CV_D) && check_make_di_len(arg, len))
		with_cv = ft_strjoin(input, "d");
	else if ((fwp->bits & CV_U) && check_make_u_len(arg, len))
		with_cv = ft_strjoin(input, "u");
	ft_putstr("\n   (0-+ #WPcspdiuxX%)\n");
	ft_putstr("> 0B");
	change_base_int(fwp->bits, "01", 2, 16);
	fwp->width = width;
	fwp->precision = precision;

	printf("\n> \"%s\"", with_cv);
	full_len = my_printf(with_cv, fwp, arg, *len);
}
int	main(void)
{
	int	n;
	char		*str;
	char		*input;
	char		*long_str;
	int			prec;	//precision
	int			len;
	t_gather	fwp;

	// len = len < prec ? prec : len; //%s
	// width = width > len ? width : len; //%s
	//--------------------------------------------------
	// [TEST] "input_dec_base"


	// printf("\n<<<<<<<<<<<<<\t[CASE 1] %%d\t>>>>>>>>>>>>>\n");
	// n = 123;
	// len = check_make_di_len(n);
	// fwp.bits = CV_D;
	// fwp.width = 0;
	// fwp.precision= 0;
    //
	// str = make_diu(&fwp, n, len);
	// printf("\t => cnt : %d (real_printf)\n", printf("|%d|", 123) - 2);
	// printf("|%s|\t => cnt : %d <- my_prinf\n", str, (int)strlen(str));
	// printf("\t => cnt : %d (real_printf)\n", printf("|%d|", 123) - 2);
    //
    //
	// printf("\n<<<<<<<<<<<<<\t[CASE 2] %%010d\t>>>>>>>>>>>>>\n");
	// n = 123;
	// len = check_make_di_len(n);
    //
	// str = make_diu(&fwp, n, len);
	// printf("\t => cnt : %d (real_printf)\n", printf("|%010d|", 123) - 2);
	// printf("|%s|\t => cnt : %d\n", str, (int)strlen(str));
    //
	// printf("\n<<<<<<<<<<<<<[CASE 3] %%+10d>>>>>>>>>>>>>\n");
	// n = 123;
	// len = check_make_di_len(n);
	// fwp.bits = CV_D | WD_EXIST | FG_PLUS;
	// fwp.width = 10;
	// fwp.precision= 0;
    //
	// str = make_diu(&fwp, n, len);
	// printf("\t => cnt : %d (real_printf)\n", printf("|%+10d|", 123) - 2);
	// printf("|%s|\t => cnt : %d\n", str, (int)strlen(str));
    //
	// printf("\n<<<<<<<<<<<<<[CASE 4] %% 10d>>>>>>>>>>>>>\n");
	// n = 123;
	// len = check_make_di_len(n);
	// fwp.bits = CV_D | WD_EXIST | FG_SPACE;
	// fwp.width = 10;
	// fwp.precision= 0;
    //
	// str = make_diu(&fwp, n, len);
	// printf("\t => cnt : %d (real_printf)\n", printf("|% 10d|", 123) - 2);
	// printf("|%s|\t => cnt : %d\n", str, (int)strlen(str));
    //
	// printf("\n<<<<<<<<<<<<<[CASE 5] %%-10d>>>>>>>>>>>>>\n");
	// n = 123;
	// fwp.bits = CV_D | WD_EXIST | FG_MINUS;
	// fwp.width = 10;
	// fwp.precision= 0;
    //
	// str = make_diu(&fwp, n, len);
	// printf("\t => cnt : %d (real_printf)\n", printf("|%-10d|", 123) - 2);
	// printf("|%s|\t => cnt : %d\n", str, (int)strlen(str));
    //
	// printf("\n<<<<<<<<<<<<<[CASE 6] %%10.d>>>>>>>>>>>>>\n");
	// n = 0;
	// len = check_make_di_len(n);
	// fwp.bits = CV_D | WD_EXIST;
	// fwp.width = 10;
	// fwp.precision= 0;
    //
	// str = make_diu(&fwp, n, len);
	// printf("\t => cnt : %d (real_printf)\n", printf("|%10.d|", 0) - 2);
	// printf("|%s|\t => cnt : %d\n", str, (int)strlen(str));
    //
	// printf("\n<<<<<<<<<<<<<<<<<<[CASE 7] %%+010.5d>>>>>>>>>>>>>>>>>>\n");
	// n = 123;
	// len = check_make_di_len(n);
	// fwp.bits = CV_D | WD_EXIST | FG_PLUS | PC_EXIST;
	// fwp.width = 10;
	// fwp.precision= 5;
    //
	// str = make_diu(&fwp, n, len);
	// printf("\t => cnt : %d (real_printf)\n", printf("|%+010.5d|", 123) - 2);
	// printf("|%s|\t => cnt : %d\n", str, (int)strlen(str));
    //
	// printf("\n<<<<<<<<<<<<<<<<<<[CASE 8] %%-+010.0diu>>>>>>>>>>>>>>>>>>\n");
	// //test_make_conversion(size_t arg, *len, bits, width, precision, t_gather *fwp);
    //
	// input = "%-+10.0";
    //
	// fwp.bits = FG_MINUS | FG_ZERO | FG_PLUS | WD_EXIST | PC_EXIST | CV_D;
    //
	// n = 123;
	// test_make_conversion(n, &len, &fwp, 10, 0);
	// printf("\t => full_len : %d (my_printf)\n", my_printf(input, &fwp, n, len));
	// printf("\t => full_len : %d (real_printf)\n", printf("|%-+10.0d|", n) - 2);
	// n = -123;
	// test_make_conversion(n, &len, &fwp, 10, 0);
	// printf("\t => full_len : %d (my_printf)\n", my_printf(input, &fwp, n, len));
	// printf("\t => full_len : %d (real_printf)\n", printf("|%-+10.0d|", n) - 2);
    //
	// fwp.bits = FG_MINUS | FG_ZERO | FG_PLUS | WD_EXIST | PC_EXIST | CV_U;
	// fwp.bits &= ~FG_PLUS; // notes : ignored '+'
    //
	// n = 123;
	// test_make_conversion(n, &len, &fwp, 10, 0);
	// printf("\t => full_len : %d (my_printf)\n", my_printf(input, &fwp, n, len));
	// printf("\t => full_len : %d (real_printf)\n", printf("|%-+10.0u|", n) - 2);
	// n = -123;
	// test_make_conversion(n, &len, &fwp, 10, 0);
	// printf("\t => full_len : %d (my_printf)\n", my_printf(input, &fwp, n, len));
	// printf("\t => full_len : %d (real_printf)\n", printf("|%-+10.0u|", n) - 2);
    //
	// input = "%-+15.13d";
	// printf("\n<<<<<<<<<<<<<<<<<<<<<<[CASE 9] %s>>>>>>>>>>>>>>>>>>>>>>\n", input);
    //
	// fwp.bits = FG_MINUS | FG_ZERO | FG_SPACE | WD_EXIST | PC_EXIST | CV_D;
    //
	// n = INT_MAX;
	// test_make_conversion(n, &len, &fwp, 15, 13);
	// printf("\t => full_len : %d (my_printf)\n", my_printf(input, &fwp, n, len));
	// printf("\t => full_len : %d (real_printf)\n", printf("|%- 15.13d|", n) - 2);
	// n = INT_MIN;
	// test_make_conversion(n, &len, &fwp, 15, 13);
	// printf("\t => full_len : %d (my_printf)\n", my_printf(input, &fwp, n, len));
	// printf("\t => full_len : %d (real_printf)\n", printf("|%- 15.13d|", n) - 2);
    //
    //
	// fwp.bits = FG_MINUS | FG_ZERO | FG_SPACE | WD_EXIST | PC_EXIST | CV_U;
	// fwp.bits &= ~FG_SPACE; // notes : ignored ' ' (undefine behavior)
    //
	// n = INT_MAX;
	// test_make_conversion(n, &len, &fwp, 15, 13);
	// printf("\t => full_len : %d (my_printf)\n", my_printf(input, &fwp, n, len));
	// printf("\t => full_len : %d (real_printf)\n", printf("|%- 15.13u|", n) - 2);
	// n = INT_MIN;
	// test_make_conversion(n, &len, &fwp, 15, 13);
	// printf("\t => full_len : %d (my_printf)\n", my_printf(input, &fwp, n, len));
	// printf("\t => full_len : %d (real_printf)\n", printf("|%- 15.13u|", n) - 2);
    //
	printf("\n<<<<<<<<<<<<<<<<<<<<<<[CASE 10] %%  -+03.13>>>>>>>>>>>>>>>>>>>>>>\n");
	input = "% -+017.13";
	fwp.bits = FG_SPACE | FG_MINUS | FG_ZERO | FG_PLUS | WD_EXIST | PC_EXIST | CV_D;
	fwp.bits &= ~(FG_ZERO | FG_SPACE);
	// printf("% -+03.13d", 1);			// notes : ignored	 '0'
	//
	//
	printf_cmp(input, 2413, 17, 13, &len, &fwp);
	//              (*input, arg, width, precision, *len, *fwp)
	//
	//
	//
	//
	//
	printf_cmp(input, 0, 17, 13, &len, &fwp);
	//              (*input, arg, width, precision, *len, *fwp)
	printf_cmp("% -+017.13d", -2413, 17, 13, &len, &fwp);
	//              (*input, arg, width, precision, *len, *fwp)


	fwp.bits = FG_SPACE | FG_MINUS | FG_ZERO | WD_EXIST | PC_EXIST | CV_U;
	fwp.bits &= ~(FG_SPACE | FG_PLUS |FG_ZERO);	// notes : undefined ' '
	// printf("% -+03.13u", 1);			// notes : ignored	 '0'
	printf_cmp("% -+017.13u", 2413, 17, 13, &len, &fwp);
	//              (*input, arg, width, precision, *len, *fwp)
	printf_cmp("% -+017.13u", 0, 17, 13, &len, &fwp);
	//              (*input, arg, width, precision, *len, *fwp)
	printf_cmp("% -+017.13u", -2413, 17, 13, &len, &fwp);
	//              (*input, arg, width, precision, *len, *fwp)
	//
	printf("\n<<<<<<<<<<<<<<<<<<<<<<[CASE 11] %%010>>>>>>>>>>>>>>>>>>>>>>\n");

	fwp.bits = FG_SPACE | FG_MINUS | FG_ZERO | FG_PLUS | WD_EXIST | PC_EXIST | CV_D;
	fwp.bits &= ~(FG_ZERO | FG_SPACE); // notes : ignored	 '0'
	printf_cmp("% -+017.13d", 2413, 17, 13, &len, &fwp);
	//              (*input, arg, width, precision, *len, *fwp)
	printf_cmp("% -+017.13d", -2413, 17, 13, &len, &fwp);
	//              (*input, arg, width, precision, *len, *fwp)


	fwp.bits = FG_SPACE | FG_MINUS | FG_ZERO | WD_EXIST | PC_EXIST | CV_U;
	fwp.bits &= ~(FG_SPACE | FG_PLUS |FG_ZERO);	// notes : undefined ' '
	// printf("% -+03.13u", 1);			// notes : ignored	 '0'
	printf_cmp("% -+017.13u", 2413, 17, 13, &len, &fwp);
	//              (*input, arg, width, precision, *len, *fwp)
	printf_cmp("% -+017.13u", -2413, 17, 13, &len, &fwp);
	//              (*input, arg, width, precision, *len, *fwp)
    //
    //
	// n = 2413;
	// test_make_conversion(n, &len, &fwp, 3, 13);
	// printf("\t => full_len : %d (my_printf)\n", my_printf(input, &fwp, n, len));
	// printf("\t => full_len : %d (real_printf)\n", printf("|%- 03.13u|", n) - 2);
	// n = -2413;
	// test_make_conversion(n, &len, &fwp, 3, 13);
	// printf("\t => full_len : %d (my_printf)\n", my_printf(input, &fwp, n, len));
	// printf("\t => full_len : %d (real_printf)\n", printf("|%- 03.13u|", n) - 2);
	// // n = -123;
	// // len = check_make_di_len(n);
	// // fwp.bits = CV_D | WD_EXIST | FG_ZERO;
	// // fwp.width = 10;
	// // fwp.precision= 0;
    // //
	// // str = make_diu(&fwp, n, len);
	// // printf("\t => cnt : %d\n", printf("|%010d|", -123) - 2);
	// printf("|%s|\t => cnt : %d\n", str, (int)strlen(str));
    //
	// printf("\n<<<<<<<<<<<<<[CASE 12] %% 10d>>>>>>>>>>>>>\n");
	// n = -123;
	// len = check_make_di_len(n);
	// fwp.bits = CV_D | WD_EXIST | FG_SPACE;
	// fwp.width = 10;
	// fwp.precision= 0;
    //
	// str = make_diu(&fwp, n, len);
	// printf("\t => cnt : %d\n", printf("|% 10d|", -123) - 2);
	// printf("|%s|\t => cnt : %d\n", str, (int)strlen(str));
    //
	// printf("\n<<<<<<<<<<<<<[CASE 13] %%+10d>>>>>>>>>>>>>\n");
	// n = -123;
	// len = check_make_di_len(n);
	// fwp.bits = CV_D | WD_EXIST | FG_PLUS;
	// fwp.width = 10;
	// fwp.precision= 0;
    //
	// str = make_diu(&fwp, n, len);
	// printf("\t => cnt : %d\n", printf("|%+10d|", n) - 2);
	// printf("|%s|\t => cnt : %d\n", str, (int)strlen(str));
    //
	// printf("\n<<<<<<<<<<<<<[CASE 14] %%+015d>>>>>>>>>>>>>\n");
	// n = INT_MIN;
	// len = check_make_di_len(n);
	// fwp.bits = CV_D | WD_EXIST | FG_PLUS | FG_ZERO;
	// fwp.width = 15;
	// fwp.precision= 0;
    //
	// str = make_diu(&fwp, n, len);
	// printf("\t => cnt : %d\n", printf("|%+015d|", n) - 2);
	// printf("|%s|\t => cnt : %d\n", str, (int)strlen(str));
    //
	// printf("\n<<<<<<<<<<<<<[CASE 15] %%+017.15d>>>>>>>>>>>>>\n");
	// n = INT_MIN;
	// len = check_make_di_len(n);
	// fwp.bits = CV_D | WD_EXIST | PC_EXIST | FG_PLUS;
	// fwp.width = 17;
	// fwp.precision= 15;
    //
	// str = make_diu(&fwp, n, len);
	// printf("\t => cnt : %d\n", printf("|%+017.15d|", n) - 2);
	// printf("|%s|\t => cnt : %d\n", str, (int)strlen(str));
    //
	// printf("\n<<<<<<<<<<<<<[CASE 16] %%+d>>>>>>>>>>>>>\n");
	// n = 123;
	// len = check_make_di_len(n);
	// fwp.bits = CV_D | FG_PLUS;
	// fwp.width = 0;
	// fwp.precision= 0;
    //
	// str = make_diu(&fwp, n, len);
	// printf("\t => cnt : %d\n", printf("|%+d|", n) - 2);
	// printf("|%s|\t => cnt : %d\n", str, (int)strlen(str));
    //
    //
    //
    //
	// printf("\n<<<<<<<<<<<<<[CASE 17] %%+u>>>>>>>>>>>>>\n");
	// n = -123;
	// len = check_make_di_len(n);
	// fwp.bits = CV_U | FG_PLUS;
	// fwp.width = 0;
	// fwp.precision= 0;
    //
	// if (fwp.bits | CV_D)
	//     str = make_diu(&fwp, (int)n, len);
	// if (fwp.bits | CV_U)
	//     str = make_diu(&fwp, (unsigned int)n, len);
	// printf("\t => cnt : %d\n", printf("|%+d|", n) - 2);
	// printf("|%s|\t => cnt : %d\n", str, (int)strlen(str));
	// // printf("\t => cnt : %d <- (real)\n", printf("|%- 10d|", 123) - 2);
	// // ft_inputnbr(str + 1, 123, len, ' ');
	// // ft_handle_pos(str, ' ');
	// // ft_memset(str + len, ' ',  width - len);
	// // printf("|%s|\t => cnt : %d <- (my)\n", str, (int)strlen(str));
	// // printf("\t\t => len : %d\n", len);
    // //
	// // printf("\n[CASE 8] %%- 10.3d\n"); //-상태에서 sp or + 이면 문자열 +1 시작
	// // len = 5;
	// // printf("\t => cnt : %d <- (real)\n", printf("|%- 10.5d|", 123) - 2);
	// // ft_inputnbr(str + 1, 123, len, '0');
	// // ft_handle_pos(str, ' ');
	// // printf("|%s|\t => cnt : %d <- (my)\n", str, (int)strlen(str));
	// // printf("\t\t => len : %d\n", len);
    // //
	// // printf("\n[CASE 9] %%-10.3d\n");
	// // len = 3; prec = 3; width = 10;
	// // str[width] = '\0';
	// // printf("\t => cnt : %d <- (real)\n", printf("|%-10.3d|", 123) - 2);
	// // ft_inputnbr(str, 123, len, '0');
	// // // ft_handle_pos(str, '+');
	// // ft_memset(str + len, ' ',  width - len); // + + 'len'
	// // printf("|%s|\t => cnt : %d <- (my)\n", str, (int)strlen(str));
	// // printf("\t\t => len : %d\n", len);
    // //
	// // printf("\n----------[CASE 10] \"%%+10d\"----------\n");
	// // // precision이없을 때 켜진 것 처럼 행동
	// // len = 3; prec = 0; width = 10;
	// // len = len > prec ? len : prec; //%d
	// // if (!(fg_mi = 0) && width > len)
	// //     len = width;
	// // str[len] = '\0';
	// // str[width] = '\0';
	// // if ((fg_plsp = 1))
	// //     len++;
	// // printf("\t => cnt : %d <- (real)\n", printf("|%+10d|", 123) - 2);
	// // ft_inputnbr(str, 123, len, '0');
	// // ft_handle_pos(str, '+');
	// // if (width > len)
	// //     ft_memset(str + len, ' ',  width - len); // + + 'len'
	// // printf("|%s|\t => cnt : %d <- (my)\n", str, (int)strlen(str));
	// // printf("\t\t => width : %d, prec : %d, len : %d\n", width, prec, len);
    // //
	// // printf("\n----------[CASE 11] \"%%-+10d\"----------\n");
	// // // precision이없을 때 켜진 것 처럼 행동
	// // width = 10; prec = 0; n = 0; len = 1;
	// // len = len > prec ? len : prec; //%d
	// // if (!(fg_mi = 1) && width > len)
	// // {
	// //     len = width;
	// //     str[len] = '\0';
	// // }
	// // else
	// //     str[width] = '\0';
	// // if ((fg_plsp = 1))
	// //     len++;
	// // printf("\t => cnt : %d <- (real)\n", printf("|%-+10d|", n) - 2);
	// // ft_inputnbr(str, n, len, '0');
	// // ft_handle_pos(str, '+');
	// // if (width > len)
	// //     ft_memset(str + len, ' ',  width - len); // + + 'len'
	// // printf("|%s|\t => cnt : %d <- (my)\n", str, (int)strlen(str));
	// // printf("\t\t => width : %d, prec : %d, len : %d\n", width, prec, len);
    // //
	// // printf("\n----------[CASE 12] \"%% 3.4d\"----------\n");
	// // len = 3;
	// // prec = 4;
	// // width = 3;
	// // len = len > prec ? len : prec; //%d
	// // // len = len < prec ? prec : len; //%s
	// // // width = width > len ? width : len; //%s
	// // if ((fg_mi = 0) && len > width)
	// //     len = len > width ? len : width; //%d
	// // if ((fg_plsp = 1))
	// //     len++;
	// // str[len] = '\0';
	// // ft_bzero(str, width);
	// // printf("\t => cnt : %d <- (real)\n", printf("|% 3.4d|", 123) - 2);
	// // ft_inputnbr(str, 123, len, '0');
	// // ft_handle_pos(str, ' ');
	// // // ft_memset(str + len, ' ',  width - len); // + + 'len'
	// // printf("|%s|\t => cnt : %d <- (my)\n", str, (int)strlen(str));
	// // printf("\t => width : %d, prec : %d, len : %d\n", width, prec, len);
    // //
	// // printf("\n[CASE 13] %% 3.4d\n");
	// // free(str);
	// // //--------------------------------------------------
    // //
	// // // long_str = (char *)calloc(2147483647LL, 1);
	// // // while (idx <= 2147483645LL)
	// // //     long_str[idx++] = '1';
	// // // printf("\nreturn = %d\n", printf("Hello%dab\n%s", 13, long_str));
	// // // printf("return = %zd\n", write(1, long_str, 2147483648LL)); //?????? why? printed behind?
	// // // printf("[test type]--------------------------------------\n");
	// // // printf("void \t\t\t: %zu\n", sizeof(void));
	// // // printf("char \t\t\t: %zu\n", sizeof(char));
	// // printf("int  \t\t\t: %zu\n", sizeof(int));
	// // printf("unsinged int \t\t: %zu\n", sizeof(unsigned int));
	// // printf("unsinged long \t\t: %zu\n", sizeof(unsigned long));
	// // printf("unsinged long long \t: %zu\n", sizeof(unsigned long long));
	// // printf("size_t  \t\t: %zu\n", sizeof(size_t));
	// // printf("void * : %zu\n", sizeof(void *));
	// // printf("char * : %zu\n", sizeof(char *));
	// // printf("int  * : %zu\n", sizeof(int *));
	// // printf("void ** : %zu\n", sizeof(void **));
	// // printf("--------------------------------------------------\n");
    //

	// printf("%zd\n", write(1, "", 1));
	// printf("%d\n", printf("%s", "")); // 0
    //
	// printf("[test ft_put*]--------------------------------------\n");
	// printf("\t => result : %d\n", change_base_int(123, DEC_BASE, DEC));
	// printf("\t => result : %d\n", change_base_int(-123, DEC_BASE, DEC));
	// printf("\t => result : %d\n", change_base_int(INT_MAX+1, HEX_BASE_LOWER, HEX));
	// printf("\t => result : %d\n", change_base_int(-123, HEX_BASE_LOWER, HEX));
	// printf("\t => result : %d\n", ft_putnbr_rtn(123));
	// printf("\t => result : %d\n", ft_putnbr_rtn(-123));
	// printf("\t => result : %d\n", printf("%u", -123));
	// printf("\t => result : %d\n", printf("%u", -123));
	// printf("--------------------------------------------------\n");
    //
	// printf("\n\n");
	// printf("[test ft_printf %%p]-vs -print_p----------------------\n");
	// printf("\t => result : %d\n", printf("%p", str));
	// printf("\t => result : %d\n", print_p(str));
	// printf("\t => result : %d\n", printf("%lx", str));
	// printf("\t => result : %d\n", print_memory(str));
	// test_va(2, &n, &str);

	// printf("----------------[test %%di]-----------------\n");
	// printf("\t => result : %d\n", printf("|%04d|", 123) - 2);
	// printf("\t => result : %d\n", printf("|%04i|", 123) - 2);
    //
	// printf("\t => result : %d\n", printf("|%+5d|", 123) - 2);
	// printf("\t => result : %d\n", printf("|%+5i|", 123) - 2);
    //
	// printf("\t => result : %d\n", printf("|%-5d|", 123) - 2);
	// printf("\t => result : %d\n", printf("|%-5i|", 123) - 2);
    //
	// printf("\t => result : %d\n", printf("|% 4d|", -123) - 2);
	// printf("\t => result : %d\n", printf("|% 4i|", -123) - 2);
    //
	// // printf("\t => result : %d\n", printf("|%#5d|", -123) - 2);
	// // printf("\t => result : %d\n", printf("|%#5i|", -123) - 2);
    //
	// printf("\t => result : %d\n", printf("|%0d|", -123) - 2);
	// printf("\t => result : %d\n", printf("|%0d|", -123) - 2);
    //
	// printf("\t => result : %d\n", printf("|%0.d|", 123) - 2);
	// printf("\t => result : %d\n", printf("|%0.i|", 123) - 2);
    //
	// printf("\t => result : %d\n", printf("|%-4i|", 123) - 2);

	//
	// printf("----------------[test %%xX]-----------------\n");
	// printf("\t => result : %d\n", printf("|%04x|", 123) - 2);
	// printf("\t => result : %d\n", printf("|%04X|", 123) - 2);
    //
	// printf("\t => result : %d\n", printf("|%+5x|", 123) - 2);
	// printf("\t => result : %d\n", printf("|%+5X|", 123) - 2);
    //
	// printf("\t => result : %d\n", printf("|%-11x|", 123) - 2);
	// printf("\t => result : %d\n", printf("|%-11X|", 123) - 2);
    //
	// printf("\t(sp) => result : %d\n", printf("|% 9x|", -123) - 2);
	// printf("\t(sp) => result : %d\n", printf("|% 9X|", -123) - 2);
    //
	// printf("\t => result : %d\n", printf("|%#5x|", -123) - 2);
	// printf("\t => result : %d\n", printf("|%#5X|", -123) - 2);
    //
	// printf("\t => result : %d\n", printf("|%0x|", -123) - 2);
	// printf("\t => result : %d\n", printf("|%0X|", -123) - 2);
    //
	// printf("\t => result : %d\n", printf("|%.6x|", 123) - 2);
	// printf("\t => result : %d\n", printf("|%.6X|", 123) - 2);
    //
	// printf("\t => result : %d\n", printf("|%-4x|", 123) - 2);
	// printf("\t => result : %d\n", printf("|%-4X|", 123) - 2);
    //
	// // while (1)
	// // {
	// //     printf("\ninput : ");
	// //     scanf("%d", &n);
	// //     printf("%d vs %u\n", n, n);
	// //     ft_putstr("int : ");
	// //     ft_putstr("\ndec : ");
	// //     ft_putnbr_rtn(n);
	// //     ft_putstr("\nu  : ");
	// //     change_base_int(n, DEC_BASE, DEC);
	// //     // printf("\nmy : ");
	// //     ft_putstr("\nu  : ");
	// //     change_base_int(n, HEX_BASE_LOWER, HEX);
	// //     ft_putstr("\nmy : ");
	// //     // printf("\nmy : ");
	// //     change_base_int(n, "01234567", 8);
	// //     ft_putstr("\nmy : ");
	// //     // printf("\nmy : ");
	// //     change_base_int(n, "01", 2);
	// //     printf("\n");
	//     if (!n)
	//         break ;
	//     printf("\n");
	// }
	// printf("|%3.5d|\n", 1234);
	// printf("|%+3.5d|\n", 1234);
	// printf("|%+03d|\n", 1234);
	// printf("|%04%|\n");
	// printf("|%04c|\n", '%');
	// printf("|%05.3s|\n", NULL); // (nu
	// printf("%d", printf("%d %d22342%30000000000d32423", 3, 3, 3));
	// change_base_cnt(10, 7, DEC);
	// printf("\n");
	// printf("\t => result : %d\n", change_base_sp(10, 7, DEC, ));
	// printf("%d %w", 10);
	return (0);
}

	// printf("|%+10c|", '3');		// |         3|%
	// printf("|%10.4c|", '3');		// |         3|%
	// printf("|%-10.4d|", 10);		// |         3|%
	// printf("|%+010.7d|", -10);		// |         3|%
    //
	// printf("%%1.3d = |%1.3d|\n", 3);		// |         3|%
	// printf("%%2.3d = |%2.3d|\n", 3);		// |         3|%
	// printf("%%3.3d = |%3.3d|\n", 3);		// |         3|%
	// printf("%%4.3d = |%4.3d|\n", 3);		// |         3|%
	// printf("%%+4.3d = |%+4.3d|\n", 3);		// |         3|%
	// printf("%%3.3d = |%3.3d|\n", -3);		// |         3|%
	// printf("%%-4.3d = |%-4.3d|\n", 3);		// |         3|%
    //
	// //varient space
	// printf("%% 4.3d = |% 4.3d|\n", 3);		// |         3|%
	// printf("%%  4.3d = |%  4.3d|\n", 3);		// |         3|%
	// printf("%%     4.3d = |%      4.3d|\n", 3);		// |         3|%
    //
	// printf("%% 4.3d = |% 4.3d|\n", -3);		// |         3|%
	// printf("%%  4.3d = |%  4.3d|\n", -3);		// |         3|%
	// printf("%%  -  7.3d = |%  -   7.3d|\n", -3);		// |         3|%
    //
    //
	// printf("\n-------[CASE flags #]------\n");
	// printf("|%#7c|\n", 'a'); 		// |    003| (u.b.)
	// printf("|%#7s|\n", "Hello"); 		// |    003| (u.b.)
	// printf("|%#7p|\n", "abc"); 		// |    003| (u.b.)
	// printf("|%#7d|\n", 3); 		// |    003| (u.b.)
	// printf("|%#7i|\n", 3); 		// |    003| (u.b.)
	// printf("|%#7u\n", 3); 		// |    003| (u.b.)
	// printf("|%#7x\n", 3); 		// |    003| (u.b.)
	// printf("|%#7X\n", 3); 		// |    003| (u.b.)
	// printf("|%%7\n"); 		// |    003| (u.b.)
	// //flags 0
	// printf("\n-------[CASE flags 0]------\n");
	// printf("|%0     7.3d|\n", 3); 		// |    003|
	// printf("|%07.3d|\n", 3);		 	// |    003|
	// printf("|%07d|\n", 3);		 		// |0000003|
	// printf("|%07s|\n", "a");			// |000000a| (u.b.)
	// printf("|%0 7d|\n", 3);			  	// | 000003|
	// printf("|%0 7s|\n", "a");			// |000000a| (u.b.)
	// printf("|%0   7d|\n", 3);		 	// | 000003|
	// printf("|%0   7s|\n", "Hellojglkdfjglkdfjglkjsdlfkgjldfj");		// |00Hello| (u.b.)
    //
	// printf("%d\n", printf("|%3000000000s|\n", "a"));		 	// | 000003|
    //
	// printf("\"\" : %d\n", printf(""));		 	// | 000003|
   //
	// printf("\t=> \"%d\"\n", printf("\n|%4s| |%dioiu| |%10s|", "a", 3, "abc"));
	// // |   a| |3       => "-1"
    //
	// // printf("%d\n", printf("|%3s| |%d|\n", "abc", 3));		 	// | 000003|
	// char str = '0';
	// printf("%lx\n", &str);
	// printf("%ld\n", &str);
	// printf("%p\n", &str);
	// printf("%d\n", write(1, &str, INT_MAX + 1));
    //
	// printf("%x\n", -123);
	// printf("%x\n", INT_MIN);
	// printf("%d\n", -123 % 16);
	//

// int	print_memory(size_t nbr)
// {
//     int	cnt;
//
//     if (!nbr)
//         return (0);
//     cnt = 0;
//     cnt += print_memory(nbr / HEX) + ft_putchar_rtn(HEX_BASE_LOWER[nbr % HEX]);
//     return (cnt);
// }
//
// int	print_p(size_t mem)
// {
//     return (ft_putstr_rtn("0x") + print_memory(mem));
// }
//
//
//
// void	make_memory(size_t nbr, size_t cnt)
// {
//     if (cnt)
//     {
//         make_memory(nbr / HEX, cnt - 1);
//         ft_putchar(HEX_BASE_LOWER[nbr % HEX]);
//     }
// }
//
//
//
//
// void	hex_memory(size_t mem)
// {
//     ft_putstr("0x");
//     make_memory(mem, HEX);
// }

// int	change_base_int(unsigned int nbr, char *base, unsigned int n)
// {
//     int	cnt;
//
//     cnt = 0;
//     if (!nbr)
//         return (0);
//     cnt += change_base_int(nbr / n, base, n) + ft_putchar_rtn(base[nbr % n]);
//     return (cnt);
// }

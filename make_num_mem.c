/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_num_mem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:48:14 by minsuki2          #+#    #+#             */
/*   Updated: 2022/03/12 22:51:03 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int isfg_incr(t_gather *fwp)
{
	if (fwp->bits & FG_POUND)
		return (2);
	return ((fwp->bits & (FG_PLUS | FG_SPACE)) != 0);
}

static void	ft_handle_incr(char *dst, int bits, int sign)
{
	int		i;
	char	incr;

	if (sign == -1)
		incr = '-';
	else if (bits & FG_PLUS)
		incr = '+';
	else if (bits & FG_SPACE)
		incr = ' ';
	else if (bits & CV_SX)
		incr = 'x';
	else if (bits & CV_LX)
		incr = 'X';
	i = 1;
	if (bits & FG_POUND)
		i = 2;
	while (!(bits & FG_MINUS) && dst[i] == ' ' && !ft_isalnum(dst[i]))
		i++;
	dst[i - 1] = incr;
	if (bits & FG_POUND)
		dst[i - 2] =  '0';
}

static void	convert_num_mem_base(char *dst, int bits, size_t arg, int len)
{
	unsigned int nbr;

	if (arg && len)
	{
		nbr = arg;
		if (bits & (CV_SX | CV_LX))
			convert_num_mem_base(dst, nbr / HEX, len - 1, bits);
		else if (bits & (CV_P))
			convert_num_mem_base(dst, arg / HEX, len - 1, bits);
		else
			convert_num_mem_base(dst, nbr / DEC, len - 1, bits);
		if (bits & CV_SX)
			dst[len - 1] = HEX_BASE_LOWER[nbr % HEX];
		else if (bits & CV_LX)
			dst[len - 1] = HEX_BASE_UPPER[nbr % HEX];
		else if (bits & CV_P)
			dst[len - 1] = HEX_BASE_LOWER[arg % HEX];
		else
			dst[len - 1] = DEC_BASE[nbr % DEC];
	}
}

static char	*make_dst(size_t arg, int sign, t_gather *fwp, int len)
{
	char	*dst;

	if ((fwp->bits & FG_ZERO)
		&& (salloc_int(&dst, fwp->full_len, '0') == ERROR))
		return (NULL);
	else if (!(fwp->bits & FG_ZERO)
		&& (salloc_int(&dst, fwp->full_len, ' ') == ERROR))
		return (NULL);
	if (fwp->bits & FG_MINUS)
		convert_num_mem_base(dst + isfg_incr(fwp), fwp->bits, arg, len);
	else
		convert_num_mem_base(dst + fwp->full_len - len, fwp->bits, arg, len);
	if (fwp->bits & (FG_PLUS | FG_SPACE))
		ft_handle_incr(dst, fwp->bits, sign);
	return (dst);
}

char	*make_num_mem(t_gather *fwp, size_t arg, int *cnt, int len)
{
	int sign;

	sign = 1;
	if (fwp->bits & (CV_SX | CV_LX) && arg == 0)
		fwp->bits &= ~(FG_POUND);
	if (fwp->bits & CV_D && (int)arg < 0)
	{
		sign = -1;
		fwp->bits |= FG_PLUS;
	}
	if (full_len_check(fwp, &len) == ERROR
			|| check_len_max(cnt, fwp->full_len) == ERROR)
		return (NULL);
	return (make_dst(arg * sign, sign, fwp, len));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_num_mem_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:48:14 by minsuki2          #+#    #+#             */
/*   Updated: 2022/03/19 16:31:27 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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
	else if (bits & (CV_SX | CV_P))
		incr = 'x';
	else
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

static void	convert_num_mem_base(char *dst, size_t arg, int len, int bits)
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
	int		offset;

	if ((fwp->bits & FG_ZERO)
		&& (salloc_int(&dst, fwp->full_len, '0') == ERROR))
		return (NULL);
	else if (!(fwp->bits & FG_ZERO)
		&& (salloc_int(&dst, fwp->full_len, ' ') == ERROR))
		return (NULL);
	if (fwp->bits & FG_MINUS)
		offset = isfg_incr(fwp);
	else
		offset = fwp->full_len - len;
	ft_memset(dst + offset, '0', len);
	convert_num_mem_base(dst + offset, arg, len, fwp->bits);
	if (isfg_incr(fwp))
		ft_handle_incr(dst, fwp->bits, sign);
	return (dst);
}

char	*make_num_mem(t_gather *fwp, size_t arg, int *cnt, int len)
{
	int sign;

	sign = 1;
	if (arg == 0 && fwp->bits & (CV_SX | CV_LX))
			fwp->bits &= ~(FG_POUND);
	if ((int)arg < 0 && fwp->bits & CV_D)
	{
		sign = -1;
		fwp->bits |= FG_PLUS;
	}
	if (full_len_check(fwp, &len) == ERROR
			|| check_len_max(cnt, fwp->full_len) == ERROR)
		return (NULL);
	return (make_dst(arg * sign, sign, fwp, len));
}

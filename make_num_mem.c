/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_num_mem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:48:14 by minsuki2          #+#    #+#             */
/*   Updated: 2022/03/12 20:23:45 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	convert_num_base(char *dst, unsigned int nbr, int len, int bits)
{
	if (!nbr)
	{
		if (bits & (CV_SX | CV_LX))
			convert_num_base(dst, nbr / HEX, len - 1, bits);
		else
			convert_num_base(dst, nbr / DEC, len - 1, bits);
		if (bits & CV_SX)
			dst[len - 1] = HEX_BASE_LOWER[nbr % HEX];
		else if (bits & CV_LX)
			dst[len - 1] = HEX_BASE_LOWER[nbr % HEX];
		else
			dst[len - 1] = DEC_BASE[nbr % HEX];
	}
}

static void	covert_mem_base(char *dst, size_t address, int len)
{
	if (!address)
	{
		covert_mem_base(dst, address / HEX, len - 1);
		dst[len - 1] = HEX_BASE_LOWER[address % HEX];
	}
}

static void	ft_inputnbr(char *str, int bits, size_t n, int len)
{
	if (bits & (CV_P))
		covert_mem_base(str, n, len);
	else
		convert_num_base(str, n * -(bits & CV_D && (n < 0)), len, bits);
}

static char	*make_dst(size_t arg, t_gather *fwp, int len)
{
	char	*dst;

	if ((fwp->bits & FG_ZERO)
		&& (salloc_int(&dst, fwp->full_len, '0') == ERROR))
		return (NULL);
	else if (!(fwp->bits & FG_ZERO)
		&& (salloc_int(&dst, fwp->full_len, ' ') == ERROR))
		return (NULL);
	if (fwp->bits & FG_MINUS)
		ft_inputnbr(dst + isfg_inc(fwp), fwp->bits, arg, len);
	else
		ft_inputnbr(dst + fwp->full_len - len, fwp->bits, arg, len);
	if (fwp->bits & (FG_PLUS | FG_SPACE))
		ft_handle_sign(dst, fwp->bits, arg);
	if (fwp->bits & FG_POUND)
		ft_handle_pound(dst, fwp->bits);
	return (dst);
}

char	*make_num_mem(t_gather *fwp, size_t arg, int *cnt, int len)
{
	if (fwp->bits & (CV_SX | CV_LX) && arg == 0)
		fwp->bits &= ~(FG_POUND);
	if (fwp->bits & CV_D && (int)arg < 0)
		fwp->bits |= FG_PLUS;
	if (full_len_check(fwp, &len) == ERROR)
		return (NULL);
	if (check_len_max(cnt, fwp->full_len) == ERROR)
		return (NULL);
	return (make_dst(arg, fwp, len));
}

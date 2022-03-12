/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   measure_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:51:12 by minsuki2          #+#    #+#             */
/*   Updated: 2022/03/12 20:47:07 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	full_len_check(t_gather *fwp, int *len)
{
	int	full_len;

	if (fwp->bits & PC_EXIST && fwp->precision > *len)
		*len = fwp->precision;
	full_len = fwp->width;
	if (*len > fwp->width)
		full_len = *len;
	if (isfg_inc(fwp) && (full_len == *len || full_len == *len + 1))
		full_len += isfg_inc(fwp) - (full_len - *len);
	if (full_len < 0 || full_len == INT_MAX)
		return (ERROR);
	fwp->full_len = full_len;
	return (SUCCESS);
}

void	ft_handle_pound(char *dst, t_gather *fwp)
{
	int	i;

	i = 2;
	while (dst[i] && !ft_strchr(HEX_BASE_ALL, dst[i]))
		i++;
	if ((fwp->bits & CV_SX) || (fwp->bits & CV_P))
		dst[i - 1] = 'x';
	else
		dst[i - 1] = 'X';
	dst[i - 2] = '0';
}


static void	ft_handle_sign(int n, int bits, char *dst)
{
	int		i;
	char	sign;

	if (n < 0)
		sign = '-';
	else
	{
		sign = ' ';
		if (bits & FG_PLUS)
			sign = '+';
	}
	i = 1;
	if (bits & FG_MINUS)
	{
		dst[0] = sign;
		return ;
	}
	while (dst[i] && !ft_strchr(DEC_BASE, dst[i]))
		i++;
	dst[i - 1] = sign;
}

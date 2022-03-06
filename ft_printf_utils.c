/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojinjang <hojinjang@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 23:32:07 by minsuki2          #+#    #+#             */
/*   Updated: 2022/03/07 04:47:21 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	salloc_int(char **new, int len, char fill)
{
	*new = (char *)malloc((len + 1) * sizeof(char));
	if (!*new)
		return (ERROR);
	(*new)[len] = '\0';
	ft_memset(*new, fill, len);
	return (SUCCESS);
}

int	isfg_inc(t_gather *fwp)
{
	if (fwp->bits & FG_POUND)
		return (2);
	return ((fwp->bits & (FG_PLUS | FG_SPACE)) != 0);
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

int	measure_len_diuxp(t_gather *fwp, int *len)
{
	int	full_len;

	if (fwp->precision > *len)
		*len = fwp->precision;
	full_len = fwp->width;
	if (*len > fwp->width)
		full_len = *len;
	if (isfg_inc(fwp) && (full_len == *len || full_len == *len + 1))
		full_len += isfg_inc(fwp) - (full_len - *len);
	if (full_len < 0 || full_len == INT_MAX)
		return (ERROR);
	return (full_len);
}

int	check_max(int *cnt, int full_len)
{
	int	idx;

	idx = 0;
	while (idx++ < full_len)
	{
		if (++(*cnt) == 2147483647)
			return (ERROR);
	}
	return (SUCCESS);
}

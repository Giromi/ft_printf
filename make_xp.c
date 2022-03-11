/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_xp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojinjang <hojinjang@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:10:22 by hchang            #+#    #+#             */
/*   Updated: 2022/03/07 04:40:02 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	input_hex_base_p(char *dst, size_t nbr, int len, t_gather *fwp)
{
	if (len)
	{
		input_hex_base_p(dst, nbr / HEX, len - 1, fwp);
		dst[len - 1] = HEX_BASE_LOWER[nbr % HEX];
	}
}

static void	input_hex_base(char *dst, unsigned int nbr, int len, t_gather *fwp)
{
	if (len)
	{
		input_hex_base(dst, nbr / HEX, len - 1, fwp);
		if (!nbr)
			dst[len - 1] = '0';
		else
		{
			if ((fwp->bits & CV_SX))
				dst[len - 1] = HEX_BASE_LOWER[nbr % HEX];
			else
				dst[len - 1] = HEX_BASE_UPPER[nbr % HEX];
		}
	}
}

static char	*make_str_x(size_t arg, t_gather *fwp, int len, int f_len)
{
	char	*result;

	if ((fwp->bits & FG_ZERO) && (salloc_int(&result, f_len, '0') == ERROR))
		return (NULL);
	else if (!(fwp->bits & FG_ZERO) && \
		(salloc_int(&result, f_len, ' ') == ERROR))
		return (NULL);
	if (fwp->bits & FG_MINUS)
		input_hex_base(result + isfg_inc(fwp), arg, len, fwp);
	else
		input_hex_base(result + f_len - len, arg, len, fwp);
	if ((fwp->bits & FG_POUND))
		ft_handle_pound(result, fwp);
	return (result);
}

char	*make_p(t_gather *fwp, size_t address, int *cnt, int len)
{
	int		idx;
	int		full_len;
	char	*dst;

	idx = 0;
	full_len = measure_len_diuxp(fwp, &len);
	if (full_len == ERROR)
		return (NULL);
	while (idx++ < full_len)
	{
		if (++(*cnt) == INT_MAX)
			return (NULL);
	}
	if (salloc_int(&dst, full_len, ' ') == ERROR)
		return (NULL);
	if (fwp->bits & FG_MINUS)
		input_hex_base_p(dst + 2, address, len, fwp);
	else
		input_hex_base_p(dst + full_len - len, address, len, fwp);
	ft_handle_pound(dst, fwp);
	return (dst);
}

char	*make_x(t_gather *fwp, size_t arg, int *cnt, int len)
{
	int		full_len;
	int		idx;

	idx = 0;
	if (arg == 0)
		fwp->bits &= ~(FG_POUND);
	full_len = measure_len_diuxp(fwp, &len);
	if (full_len == ERROR)
		return (NULL);
	if (check_max(cnt, full_len) == ERROR)
		return (NULL);
	return (make_str_x(arg, fwp, len, full_len));
}

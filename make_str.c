/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojinjang <hojinjang@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 20:49:37 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/03/12 19:55:58 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static char	*make_dst(char *str_arg, int bits, int len, int full_len)
{
	char	*str;
	int		i;

	if ((bits & FG_ZERO)
		&& (salloc_int(&str, full_len, '0') == ERROR))
		return (NULL);
	else if (!(bits & FG_ZERO)
		&& (salloc_int(&str, full_len, ' ') == ERROR))
		return (NULL);
	if (bits & FG_MINUS)
		i = 0;
	else
		i = full_len - len;
	while (len-- > 0)
	{
		if (bits & (CV_C | CV_PCT))
			str[i++] = (size_t)str_arg;
		else
			str[i++] = *(str_arg)++;
	}
	return (str);
}

char	*make_cspct(t_gather *fwp, char *arg, int *cnt, int len)
{
	if (measure_full_len(fwp, &len) == ERROR)
		return (NULL);
	if (check_len_max(cnt, fwp->full_len) == ERROR)
		return (NULL);
	if ((fwp->bits & CV_S) && arg == NULL)
		return (make_dst("(null)", fwp->bits, len, fwp->full_len));
	return (make_dst(arg, fwp->bits, len, fwp->full_len));
}

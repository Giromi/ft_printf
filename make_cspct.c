/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cspct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojinjang <hojinjang@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 20:49:37 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/03/07 01:05:11 by hojinjang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*make_str(char *str_arg, t_gather *fwp, int len, int full_len)
{
	char	*str;
	int		idx;

	str = (char *)malloc(full_len + 1);
	if (str == NULL)
		return (NULL);
	if (fwp->bits & CV_C)
		fwp->full_len = full_len;
	str[full_len] = '\0';
	idx = 0;
	if (fwp->bits & FG_MINUS)
	{
		while (len-- > 0)
			str[idx++] = *str_arg++;
		while (idx < full_len)
			str[idx++] = ' ';
	}
	else
	{
		while ((full_len--) - len > 0)
			str[idx++] = ' ';
		while (len-- > 0)
			str[idx++] = *str_arg++;
	}
	return (str);
}

char	*make_cspct(t_gather *fwp, char *arg, int *cnt, int len)
{
	char	*str_arg;
	int		idx;
	int		full_len;
	char	char_arg[2];

	if ((fwp->bits & PC_EXIST) && (fwp->precision < len))
		len = fwp->precision;
	full_len = len;
	if (fwp->width > len)
		full_len = fwp->width;
	if ((fwp->bits & CV_S) && arg == NULL)
		str_arg = "(null)";
	else if (fwp->bits & (CV_C | CV_PCT))
	{
		char_arg[0] = (size_t)arg;
		char_arg[1] = '\0';
		str_arg = &char_arg[0];
	}
	else
		str_arg = arg;
	idx = 0;
	if (check_max(cnt, full_len) == ERROR)
		return (NULL);
	return (make_str(str_arg, fwp, len, full_len));
}

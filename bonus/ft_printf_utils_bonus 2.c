/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 01:39:46 by minsuki2          #+#    #+#             */
/*   Updated: 2022/03/12 22:20:39 by minsuki2         ###   ########.fr       */
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

int	ft_strchr_idx(const char *s, int c)
{
	int	idx;

	idx = 0;
	while (s[idx] && s[idx] != (char)c)
		idx++;
	if (!s[idx] && c != '%')
		return (ERROR);
	return (idx);
}


int	check_len_max(int *cnt, int check)
{
	if (FINAL_LEN - *cnt < check)
		return (ERROR);
	*cnt += check;
	return (SUCCESS);
}

int	full_len_check(t_gather *fwp, int *len)
{
	int	full_len;

	if (fwp->bits & PC_EXIST && fwp->precision > *len)
		*len = fwp->precision;
	full_len = fwp->width;
	if (*len > fwp->width)
		full_len = *len;
	if (isfg_incr(fwp) && (full_len == *len || full_len == *len + 1))
		full_len += isfg_incr(fwp) - (full_len - *len);
	if (full_len < 0 || full_len == INT_MAX)
		return (ERROR);
	fwp->full_len = full_len;
	return (SUCCESS);
}

size_t	bring_arg(va_list *ap, int bits)
{
	if (bits & (CV_S | CV_P))
		return (va_arg(*ap, size_t));
	else if (bits & CV_PCT)
		return ('%');
	else
		return (va_arg(*ap, int));
	return (ERROR);
}
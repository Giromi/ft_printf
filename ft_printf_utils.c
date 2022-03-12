/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 01:39:46 by minsuki2          #+#    #+#             */
/*   Updated: 2022/03/12 20:32:39 by minsuki2         ###   ########.fr       */
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
	if (c == '%')
		return (idx);
	return (ERROR);
}

int	isfg_inc(t_gather *fwp)
{
	if (fwp->bits & FG_POUND)
		return (2);
	return ((fwp->bits & (FG_PLUS | FG_SPACE)) != 0);
}

int	check_len_max(int *cnt, int check)
{
	if (FINAL_LEN - *cnt < check)
		return (ERROR);
	*cnt += check;
	return (SUCCESS);
}

size_t	bring_arg(va_list *ap, int bits)
{
}

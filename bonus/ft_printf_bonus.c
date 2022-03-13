/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:26:39 by minsuki2          #+#    #+#             */
/*   Updated: 2022/03/13 16:12:59 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static size_t	bring_arg(va_list *ap, int bits)
{
	if (bits & (CV_S | CV_P))
		return (va_arg(*ap, size_t));
	else if (bits & CV_PCT)
		return ('%');
	else
		return (va_arg(*ap, int));
	return (ERROR);
}

static char	*find_pct(const char **cur, int *cnt)
{
	int		len;
	char	*before_str;
	int		i;

	len = ft_strchr_idx(*cur, '%', RTN_IDX);
	if (check_len_max(cnt, len) == ERROR)
		return (NULL);
	if (salloc_int(&before_str, len + 1, '\0') == ERROR)
		return (NULL);
	i = 0;
	while (i < len)
		before_str[i++] = *(*cur)++;
	return (before_str);
}

static void	print_lst(t_pctlst *lst, int full_len)
{
	if (lst->after_pct)
	{
		ft_putstr_fd(lst->before_pct, 1);
		write(1, lst->after_pct, full_len);
		free(lst->after_pct);
	}
	free(lst->before_pct);
}

static int	loop_printf(const char **cur, va_list *ap, int *cnt, t_pctlst *lst)
{
	t_gather	fwp;

	ft_bzero(&fwp, sizeof(t_gather));
	lst->before_pct = find_pct(cur, cnt);
	// printf("----------------------\n");
	// printf("before_pct : %s\n", lst->before_pct);
	if (!lst->before_pct)
		return (ERROR);
	if (**cur)
		analysis_pct(cur, &fwp);
	lst->after_pct = make_pct(*cur, &fwp, bring_arg(ap, fwp.bits), cnt);
	// printf("after_pct : %s\n", lst->after_pct);
	// printf("----------------------\n");
	return (fwp.full_len);
}

int	ft_printf(const char *s, ...)
{
	va_list		ap;
	int			cnt;
	int			full_len;
	t_pctlst	lst;

	cnt = 0;
	va_start(ap, s);
	ft_bzero(&lst, sizeof(t_pctlst));
	while (*s && cnt != ERROR)
	{
		full_len = loop_printf(&s, &ap, &cnt, &lst);
		if (full_len == ERROR)
			cnt = ERROR;
		print_lst(&lst, full_len);
	}
	va_end(ap);
	return (cnt);
}

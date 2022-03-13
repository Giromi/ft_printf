/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:26:39 by minsuki2          #+#    #+#             */
/*   Updated: 2022/03/13 02:41:35 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*find_pct(const char **cur, int *cnt)
{
	int		len;
	char	*before_str;
	int		i;

	len = ft_strchr_idx(*cur, '%');
	if (check_len_max(cnt, len) == ERROR)
		return (NULL);
	if (salloc_int(&before_str, len + 1, '\0') == ERROR)
		return (NULL);
	i = 0;
	while (i < len)
		before_str[i++] = *(*cur)++;
	return (before_str);
}

static int	loop_printf(const char **cur, va_list *ap, int *cnt, t_pctlst *lst)
{
	t_gather	fwp;
	size_t		arg;

	ft_bzero(&fwp, sizeof(t_gather));
	lst->before_pct = find_pct(cur, cnt);
	printf("----------------------\n");
	printf("before_pct : %s\n", lst->before_pct);
	if (!lst->before_pct)
		return (ERROR);
	arg = analysis_pct(cur, ap, &fwp);
	lst->after_pct = make_pct(*cur, &fwp, arg, cnt);
	printf("after_pct : %s\n", lst->after_pct);
	printf("----------------------\n");
	return (fwp.full_len);
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

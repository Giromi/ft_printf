/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 03:09:34 by minsuki2          #+#    #+#             */
/*   Updated: 2022/03/07 02:26:06 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	bring_arg(va_list *ap, int bits)
{
	size_t	arg;

	if (bits & (CV_S | CV_P))
		arg = va_arg(*ap, size_t);
	else if (bits & CV_PCT)
		arg = (size_t) '%';
	else
		arg = (size_t) va_arg(*ap, int);
	return (arg);
}

static char	*make_pct(const char *cur, t_gather *fwp, size_t arg, int *cnt)
{
	int		len;

	if (fwp->bits & FAIL_INT)
		return (NULL);
	if (!fwp->bits)
		return (ft_strdup(""));
	if (fwp->bits & FAIL_CONV)
		return (ft_substr(cur, 0, 1));
	len = make_cv_len(arg, fwp->bits);
	if (fwp->bits & (CV_D | CV_I | CV_U))
		return (make_diu(fwp, (int)arg, cnt, len));
	if (fwp->bits & (CV_C | CV_S | CV_PCT))
		return (make_cspct(fwp, (char *)arg, cnt, len));
	if (fwp->bits & (CV_SX | CV_LX))
		return (make_x(fwp, arg, cnt, len));
	if (fwp->bits & CV_P)
		return (make_p(fwp, arg, cnt, len));
	return (NULL);
}

static char	*find_pct(const char **cur, int *cnt)
{
	int		len;
	char	*before_str;
	int		i;

	len = ft_nstrchr_cnt(*cur, '%', cnt);
	if (*cnt & FAIL_INT)
		return (NULL);
	if (salloc_int(&before_str, len + 1, '\0') == ERROR)
		return (NULL);
	i = 0;
	while (i < len)
	{
		before_str[i++] = **cur;
		(*cur)++;
	}
	return (before_str);
}

static int	recursive_printf(const char *cur, va_list *ap, int *cnt,
		t_pctlst **start)
{
	int			check;
	char		*before_str;
	t_pctlst	*last;
	t_gather	fwp;

	ft_bzero(&fwp, sizeof(t_gather));
	if (!(*cur))
		return (SUCCESS);
	before_str = find_pct(&cur, cnt);
	last = ft_lstadd_back_last(start, ft_lstnew_before_str(before_str));
	if (!last)
		return (ERROR);
	analysis_pct(&cur, &fwp, cnt);
	last->after_pct = make_pct(cur, &fwp, bring_arg(ap, fwp.bits), cnt);
	if (fwp.full_len != 0)
		last->full_len = fwp.full_len;
	if (!last->after_pct)
		return (ERROR);
	if (*cur)
		cur++;
	check = recursive_printf(cur, ap, cnt, &last);
	if (check == -1)
		return (ERROR);
	return (*cnt);
}

int	ft_printf(const char *s, ...)
{
	va_list		ap;
	int			cnt;
	t_pctlst	*lst;

	cnt = 0;
	va_start(ap, s);
	lst = NULL;
	cnt = recursive_printf(s, &ap, &cnt, &lst);
	print_lst(lst);
	va_end(ap);
	return (cnt);
}

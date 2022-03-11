/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 01:39:46 by minsuki2          #+#    #+#             */
/*   Updated: 2022/03/07 03:23:58 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nstrchr_cnt(const char *s, int c, int *cnt)
{
	int	idx;

	idx = 0;
	while (s[idx])
	{
		if (cnt && *cnt == INT_MAX)
			return (ERROR);
		if (s[idx] == (char)c)
			return (idx);
		idx++;
		if (cnt)
			(*cnt)++;
	}
	if (!cnt)
		return (ERROR);
	return (idx);
}

static void	*ft_lstfclean(t_pctlst **lst)
{
	t_pctlst	*tmp;

	if (!lst)
		return (NULL);
	while (*lst)
	{
		if ((*lst)->before_pct)
			free((*lst)->before_pct);
		if ((*lst)->after_pct)
			free((*lst)->after_pct);
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
	return (NULL);
}

t_pctlst	*ft_lstadd_back_last(t_pctlst **lst, t_pctlst *new)
{
	t_pctlst	*tmp;

	if (!lst || !new)
		return (NULL);
	if (!*lst)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next)
			 tmp = tmp->next;
		tmp->next = new;
	}
	return (new);
}

t_pctlst	*ft_lstnew_before_str(char *before)
{
	t_pctlst	*new;

	new = malloc(sizeof(t_pctlst));
	if (!new)
		return (NULL);
	new->before_pct = before;
	new->after_pct = NULL;
	new->full_len = 0;
	new->next = NULL;
	return (new);
}

void	print_lst(t_pctlst *lst)
{
	t_pctlst	*first;

	first = lst;
	while (lst)
	{
		if (lst->before_pct)
			ft_putstr_fd(lst->before_pct, 1);
		if (lst->after_pct)
		{
			if (lst->full_len != 0)
				write(1, lst->after_pct, lst->full_len);
			else
				ft_putstr_fd(lst->after_pct, 1);
		}
		lst = lst->next;
	}
	ft_lstfclean(&first);
}

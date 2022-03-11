/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:12:31 by minsuki2          #+#    #+#             */
/*   Updated: 2022/01/24 15:16:36 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_size(char const *s, char const *set, size_t *idx,
					size_t set_len);
static size_t	cmp_set(char const *str, char const *set, size_t set_size);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dst;
	size_t	len;
	size_t	set_len;
	size_t	idx;

	if (!s1 || !set)
		return (NULL);
	idx = 0;
	set_len = ft_strlen(set);
	len = check_size(s1, set, &idx, set_len);
	dst = ft_substr(s1, idx, len);
	return (dst);
}

static size_t	check_size(char const *s, char const *set, size_t *idx,
					size_t set_len)
{
	size_t	e_idx;

	e_idx = ft_strlen(s) - 1;
	while (*idx <= e_idx && cmp_set(&s[*idx], set, set_len) < set_len)
		(*idx)++;
	while (e_idx >= *idx && cmp_set(&s[e_idx], set, set_len) < set_len)
		e_idx--;
	return (e_idx - *idx + 1);
}

static size_t	cmp_set(char const *str, char const *set, size_t set_len)
{
	size_t	i;

	i = 0;
	while (*str != set[i] && set_len--)
		i++;
	return (i);
}

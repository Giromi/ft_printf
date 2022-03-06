/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:11:55 by minsuki2          #+#    #+#             */
/*   Updated: 2022/01/26 17:30:21 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *str, char c);
static char		*make_ptr(char const *str, size_t *j, char c);
static char		**ft_error_malloc(char **str, size_t D2_size);

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	ea;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	ea = count_words(s, c);
	ptr = (char **)malloc(sizeof(char *) * (ea + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	j = 0;
	while (i < ea)
	{
		ptr[i++] = make_ptr((char *)s, &j, c);
		if (!ptr[i - 1])
			return (ft_error_malloc(ptr, ea + 1));
	}
	ptr[ea] = NULL;
	return (ptr);
}

static size_t	count_words(char const *str, char c)
{
	char	*pos;
	size_t	i;
	size_t	cnt;

	cnt = 0;
	i = 0;
	if (*str && *str != c)
		cnt++;
	while (str[i++] && c)
	{
		pos = ft_strchr(&str[i - 1], c);
		if (pos)
		{
			i = pos - str + 1;
			if (str[i] && str[i] != c)
				cnt++;
		}
	}
	return (cnt);
}

static char	*make_ptr(char const *str, size_t *j, char c)
{
	size_t	idx_n_len;
	size_t	str_len;
	char	*dst;
	char	*pos;

	str_len = ft_strlen(str);
	while (str[*j] == c)
		(*j)++;
	pos = ft_strchr(str + *j, c);
	idx_n_len = pos - str;
	if (idx_n_len > str_len)
		idx_n_len = str_len;
	dst = ft_substr(str, (unsigned int)*j, idx_n_len - *j);
	*j = idx_n_len;
	return (dst);
}

static char	**ft_error_malloc(char **str, size_t D2_size)
{
	while (D2_size--)
		if (str[D2_size])
			free(str[D2_size]);
	free(str);
	return (NULL);
}

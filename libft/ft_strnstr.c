/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 23:31:24 by minsuki2          #+#    #+#             */
/*   Updated: 2022/01/24 18:01:23 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		flag;
	size_t	needle_len;
	size_t	haystack_len;
	size_t	i;

	needle_len = ft_strlen(needle);
	haystack_len = ft_strlen(haystack);
	if (haystack_len < len)
		len = haystack_len;
	i = 0;
	flag = 1;
	while (flag && needle_len)
	{
		i = ft_strchr(haystack + i, *needle) - haystack;
		if (i + needle_len > len)
			return (NULL);
		flag = ft_strncmp(haystack + i, needle, needle_len);
		if (flag)
			i++;
	}
	return ((char *)haystack + i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:49:01 by minsuki2          #+#    #+#             */
/*   Updated: 2022/01/28 11:30:51 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_strlen(s) + 1;
	while (i++ < size)
		if (s[i - 1] == (char)c)
			return ((char *)s + i - 1);
	return (NULL);
}

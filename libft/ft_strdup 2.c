/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:18:13 by minsuki2          #+#    #+#             */
/*   Updated: 2022/01/24 14:41:13 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	size;

	size = ft_strlen(s1) + 1;
	dup = (char *)malloc(sizeof(char) * size);
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s1, size);
	return (dup);
}

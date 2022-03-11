/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 04:24:36 by minsuki2          #+#    #+#             */
/*   Updated: 2022/01/24 16:19:41 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	itoa_nbr(int n, char *dst, size_t len);

char	*ft_itoa(int n)
{
	char	*ptr;
	size_t	cnt;
	int		tmp;

	cnt = 1;
	tmp = n;
	while (tmp && cnt++)
		tmp /= 10;
	if (n > 0)
		cnt--;
	ptr = (char *)malloc(sizeof(char) * (cnt + 1));
	if (!ptr)
		return (NULL);
	ptr[cnt] = '\0';
	itoa_nbr(n, ptr, cnt);
	return (ptr);
}

void	itoa_nbr(int n, char *dst, size_t len)
{
	if (n > -10 && n < 10)
	{
		if (n < 0)
		{
			dst[0] = '-';
			n *= -1;
		}
		dst[len - 1] = n % 10 + '0';
		return ;
	}
	itoa_nbr(n / 10, dst, len - 1);
	if (n >= 0)
		dst[len - 1] = n % 10 + '0';
	else
		dst[len - 1] = -(n % 10) + '0';
}

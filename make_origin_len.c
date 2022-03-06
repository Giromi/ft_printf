/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_origin_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojinjang <hojinjang@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:40:18 by hchang            #+#    #+#             */
/*   Updated: 2022/03/07 04:23:22 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	make_len_di_u(unsigned int arg, int bits)
{
	int	len;

	len = 0;
	if (bits & CV_D && (int)arg < 0)
		arg *= -1;
	if ((bits & PC_EXIST) && arg == 0)
		return (len);
	if (arg == 0)
		return (1);
	while (arg && (len++ != INT_MAX))
		arg /= 10;
	return (len);
}

static int	make_len_s(char *arg)
{
	int		len;
	char	*tmp;

	len = 0;
	tmp = arg;
	if (arg == NULL)
		return (6);
	while (*tmp++ && (len != INT_MAX))
		len++;
	return (len);
}

static int	make_len_x(int arg, int bits)
{
	int	len;

	len = 0;
	if (arg < 0)
		return (8);
	if (arg == 0 && (bits & PC_EXIST))
		return (len);
	if (arg == 0)
		return (1);
	while (arg && (len++ != INT_MAX))
		arg /= 16;
	return (len);
}

static int	make_len_p(void *arg)
{
	int		len;
	size_t	address;

	len = 0;
	address = (size_t)arg;
	if (address == 0)
		return (1);
	while (address && (len++ != INT_MAX))
		address /= 16;
	return (len);
}

int	make_cv_len(size_t arg, int bits)
{
	int	result;

	if (bits & CV_D || bits & CV_I || bits & CV_U)
		result = make_len_di_u(arg, bits);
	else if (bits & CV_S)
		result = make_len_s((char *)arg);
	else if (bits & CV_LX || bits & CV_SX)
		result = make_len_x(arg, bits);
	else if (bits & CV_P)
		result = make_len_p((void *)arg);
	else
		result = 1;
	return (result);
}

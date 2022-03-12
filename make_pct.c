/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:56:43 by minsuki2          #+#    #+#             */
/*   Updated: 2022/03/12 23:22:38 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	check_len_num_mem(size_t arg, int bits)
{
	int				len;
	int				base_num;
	unsigned int	num;

	len = 0;
	base_num = DEC;
	num = arg;
	if (bits & (CV_SX | CV_LX | CV_D))
		arg = num;
	if (bits & (CV_SX | CV_LX | CV_P))
		base_num = HEX;
	if (bits & PC_EXIST && arg == 0)
		return (0);
	if (arg == 0)
		return (1);
	if (bits & CV_D && (int)arg < 0)
		arg = -(unsigned int)arg ;
	while (arg && (len++ < FINAL_LEN))
		arg /= base_num;
	return (len);
}

static int	check_len_str_char(const char *arg, int bits)
{
	int		len;

	if (arg == NULL)
		return (6);
	len = 0;
	while (*arg++ && (len < FINAL_LEN))
		len++;
	return (len);
}

static char	*make_dst(char *str_arg, int bits, int len, int full_len)
{
	char	*str;
	int		i;

	if ((bits & FG_ZERO)
		&& (salloc_int(&str, full_len, '0') == ERROR))
		return (NULL);
	else if (!(bits & FG_ZERO)
		&& (salloc_int(&str, full_len, ' ') == ERROR))
		return (NULL);
	if (bits & FG_MINUS)
		i = 0;
	else
		i = full_len - len;
	while (len-- > 0)
	{
		if (bits & (CV_C | CV_PCT))
			str[i++] = (size_t)str_arg;
		else
			str[i++] = *(str_arg)++;
	}
	return (str);
}

static char	*make_str_char(t_gather *fwp, char *arg, int *cnt, int len)
{
	if (full_len_check(fwp, &len) == ERROR
			|| check_len_max(cnt, fwp->full_len) == ERROR)
		return (NULL);
	if ((fwp->bits & CV_S) && arg == NULL)
		return (make_dst("(null)", fwp->bits, len, fwp->full_len));
	return (make_dst(arg, fwp->bits, len, fwp->full_len));
}

char	*make_pct(const char *cur, t_gather *fwp, size_t arg, int *cnt)
{
	int		len;

	if (fwp->bits & FAIL_INT)
		return (NULL);
	if (!fwp->bits)
		return (ft_strdup(""));
	if (fwp->bits & FAIL_CONV)
		return (ft_substr(cur, 0, 1));
	if (fwp->bits & CV_S)
		len = check_len_str_char((char *)arg, fwp->bits);
	else if (CV_C | CV_PCT)
		len = 1;
	else
		len = check_len_num_mem(arg, fwp->bits);
	if (fwp->bits & (CV_D | CV_U | CV_SX | CV_LX | CV_P))
		return (make_num_mem(fwp, arg, cnt, len));
	if (fwp->bits & (CV_C | CV_S | CV_PCT))
		return (make_str_char(fwp, (char *)arg, cnt, len));
	return (NULL);
}


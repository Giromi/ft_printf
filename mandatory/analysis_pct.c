/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis_pct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:04:04 by minsuki2          #+#    #+#             */
/*   Updated: 2022/03/19 16:04:06 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	solve_conflict(int *bits)
{
	if ((*bits & FG_ZERO) && (*bits & FG_MINUS))
		*bits &= ~FG_ZERO;
	if ((*bits & FG_PLUS) && (*bits & FG_SPACE))
		*bits &= ~FG_SPACE;
	if ((!(*bits & CV_S) && ((*bits & FG_ZERO) && (*bits & PC_EXIST))))
		*bits &= ~FG_ZERO;
	if (*bits & CV_I)
		*bits |= CV_D;
	else if (*bits & CV_S)
		*bits &= ~(FG_PLUS | FG_SPACE | FG_POUND);
	else if (*bits & (CV_P | CV_SX | CV_LX))
	{
		*bits &= ~(FG_PLUS | FG_SPACE);
		if (*bits & CV_P)
			*bits |= FG_POUND;
	}
	else if (*bits & CV_D)
		*bits &= ~(FG_POUND);
	else if (*bits & CV_U)
		*bits &= ~(FG_PLUS | FG_SPACE | FG_POUND);
	else if (*bits & (CV_C | CV_PCT))
		*bits &= ~(FG_PLUS | FG_SPACE | FG_POUND | PC_EXIST);
}


static void	find_width_precision(const char **cur, t_gather *fwp)
{
	if (ft_isdigit(**cur))
		fwp->bits |= WD_EXIST;
	while (**cur && ft_isdigit(**cur))
	{
		if ((fwp->width > INT_MAX / 10) || ((fwp->width == INT_MAX / 10)
				&& ((**cur - '0') >= INT_MAX % 10)))
		{
			fwp->bits |= FAIL_INT;
			return ;
		}
		fwp->width = fwp->width * 10 + (**cur - '0');
		(*cur)++;
	}
	if (**cur == '.' && (*cur)++)
		fwp->bits |= PC_EXIST;
	while (**cur && ft_isdigit(**cur))
	{
		fwp->precision = fwp->precision * 10 + (**cur - '0');
		(*cur)++;
	}
}


static void	find_conversion(const char **cur, int *bits)
{
	int	idx;

	idx = ft_strchr_idx(CV_SET, **cur, RTN_ERROR);
	if (**cur && idx != ERROR)
	{
		*bits |= 1 << (CV_BIT_BEGIN  - idx);
		(*cur)++;
	}
	else
		*bits |= FAIL_CONV;
}

static void	find_flags(const char **cur, int *bits)
{
	int	idx;

	while (**cur)
	{
		idx = ft_strchr_idx(FG_SET, **cur, RTN_ERROR);
		if (idx == ERROR)
			break ;
		*bits |= 1 << (FG_BIT_BEGIN - idx);
		(*cur)++;
	}
}

void	analysis_pct(const char **cur, t_gather *fwp)
{
	(*cur)++;
	find_flags(cur, &fwp->bits);
	find_width_precision(cur, fwp);
	find_conversion(cur, &fwp->bits);
	if (!(fwp->bits & (FAIL_INT| FAIL_CONV)))
		solve_conflict(&fwp->bits);
}

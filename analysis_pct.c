/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis_pct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:51:32 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/03/12 23:12:52 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	solve_conflict(t_gather *fwp)
{
	if ((fwp->bits & FG_ZERO) && (fwp->bits & FG_MINUS))
		fwp->bits &= ~FG_ZERO;
	if ((fwp->bits & FG_PLUS) && (fwp->bits & FG_SPACE))
		fwp->bits &= ~FG_SPACE;
	if ((fwp->bits & FG_ZERO) && (fwp->bits & PC_EXIST))
		fwp->bits &= ~FG_ZERO;
	if (fwp->bits & CV_I)
		fwp->bits |= CV_D;
	if (fwp->bits & (CV_C | CV_PCT))
		fwp->bits &= ~(FG_PLUS | FG_SPACE | FG_POUND | PC_EXIST);
	else if (fwp->bits & CV_S)
		fwp->bits &= ~(FG_ZERO | FG_PLUS | FG_SPACE | FG_POUND);
	else if (fwp->bits & CV_P)
	{
		fwp->bits &= ~(FG_ZERO | FG_PLUS | FG_SPACE | PC_EXIST);
		fwp->bits |= FG_POUND;
	}
	else if (fwp->bits & CV_D)
		fwp->bits &= ~(FG_POUND);
	else if (fwp->bits & CV_U)
		fwp->bits &= ~(FG_PLUS | FG_SPACE | FG_POUND);
	else if (fwp->bits & (CV_SX | CV_LX))
		fwp->bits &= ~(FG_PLUS | FG_SPACE);
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

	idx = ft_strchr_idx(CV_SET, **cur);
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
		idx = ft_strchr_idx(FG_SET, **cur);
		if (idx == ERROR)
			break ;
		*bits |= 1 << (FG_BIT_BEGIN - idx);
		(*cur)++;
	}
}

size_t	analysis_pct(const char **cur, va_list *ap, t_gather *fwp)
{
	if (!**cur)
		return (SUCCESS);
	(*cur)++;
	find_flags(cur, &fwp->bits);
	find_width_precision(cur, fwp);
	find_conversion(cur, &fwp->bits);
	if (!(fwp->bits & (FAIL_INT| FAIL_CONV)))
		solve_conflict(fwp);
	return (bring_arg(ap, fwp->bits));
}

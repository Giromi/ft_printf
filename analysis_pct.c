/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis_pct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:51:32 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/03/07 03:53:35 by minsuki2         ###   ########.fr       */
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
		fwp->bits &= ~(FG_ZERO | FG_PLUS | FG_SPACE | FG_POUND | PC_EXIST);
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

static void	find_conversion(const char **cur, t_gather *fwp)
{
	if ((ft_nstrchr_cnt(CV_SET, **cur, NULL) != ERROR) && **cur != '\0')
		fwp->bits |= 1 << (CV_BIT_BEGIN - ft_nstrchr_cnt(CV_SET, **cur, NULL));
	else
		fwp->bits |= FAIL_CONV;
}

static void	find_width_precision(const char **cur, t_gather *fwp)
{
	if (ft_isdigit(**cur))
		fwp->bits |= WD_EXIST;
	while (ft_isdigit(**cur) && (**cur != '\0'))
	{
		if ((fwp->width > 214748364) || ((fwp->width == 214748364)
				&& ((**cur - '0') >= 7)))
		{
			fwp->bits |= FAIL_INT;
			return ;
		}
		fwp->width = fwp->width * 10 + (**cur - '0');
		(*cur)++;
	}
	if (**cur == '.' && (*cur)++)
		fwp->bits |= PC_EXIST;
	while (ft_isdigit(**cur) && (**cur != '\0'))
	{
		fwp->precision = fwp->precision * 10 + (**cur - '0');
		(*cur)++;
	}
}

static void	find_flags(const char **cur, t_gather *fwp)
{
	while ((ft_nstrchr_cnt(FG_SET, **cur, NULL) != ERROR) && **cur != '\0')
	{
		fwp->bits |= 1 << (FG_BIT_BEGIN - ft_nstrchr_cnt(FG_SET, **cur, NULL));
		(*cur)++;
	}
}

void	analysis_pct(const char **cur, t_gather *fwp, int *cnt)
{
	if (**cur == '\0' && *cnt > 0)
		return ;
	(*cur)++;
	find_flags(cur, fwp);
	find_width_precision(cur, fwp);
	find_conversion(cur, fwp);
	if ((fwp->bits & FAIL_INT) || (fwp->bits & FAIL_CONV))
		return ;
	solve_conflict(fwp);
}

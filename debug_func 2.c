#include "ft_printf.h"
#include <stdio.h>

void    info_fwp(t_gather *fwp)
{
    printf("---------------------------\n");
    printf("FLAGS_STATUS : ");
    if (fwp->bits & FAIL_INT)
        printf("/ERROR_INT/ ");
    if (fwp->bits & FAIL_CONV)
        printf("/ERROR_CONV/ ");
    if (fwp->bits & FG_ZERO)
        printf("/ZERO/ ");
    if (fwp->bits & FG_MINUS)
        printf("/MINUS/ ");
    if (fwp->bits & FG_PLUS)
        printf("/PLUS/ ");
    if (fwp->bits & FG_SPACE)
        printf("/SPACE/ ");
    if (fwp->bits & FG_POUND)
        printf("/POUND/\n");

    printf("\nWIDTH_STATUS : ");
    if (fwp->bits & WD_EXIST)
        printf("TRUE(%d)\n", fwp->width);
    else
        printf("FALSE\n");

    printf("PRECISION_STATUS : ");
    if (fwp->bits & PC_EXIST)
        printf("TRUE(%d)\n", fwp->precision);
    else
        printf("FALSE\n");
    printf("---------------------------\n");
}

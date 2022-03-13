#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# define FAIL_INT 0B10000000000000000000000000000000
# define FAIL_CONV 0B100000000000000000000000
# define FG_ZERO 0B1000000000000000
# define FG_MINUS 0B100000000000000
# define FG_PLUS 0B10000000000000
# define FG_SPACE 0B1000000000000
# define FG_POUND 0B100000000000
# define WD_EXIST 0B10000000000
# define PC_EXIST 0B1000000000
# define CV_EXIST 0B111111111
# define CV_C 0B100000000
# define CV_S 0B10000000
# define CV_P 0B1000000
# define CV_D 0B100000
# define CV_I 0B10000
# define CV_U 0B1000
# define CV_SX 0B100
# define CV_LX 0B10
# define CV_PCT 0B1
# define ERROR -1
# define SUCCESS 0
# define CV_C_LEN 1
# define HEX 16
# define HEX_BASE_LOWER "0123456789abcdef"
# define HEX_BASE_UPPER "0123456789ABCDEF"
# define HEX_BASE_ALL "0123456789abcdefABCDEF"
# define DEC 10
# define DEC_BASE "0123456789"
# define FG_SET "0-+ #"
# define FG_BIT_BEGIN 15
# define CV_SET "cspdiuxX%"
# define CV_BIT_BEGIN 8
# define FINAL_LEN 2147483646
# define RTN_ERROR 0
# define RTN_IDX 1

typedef struct s_gather
{
	int		bits;
	int		width;
	int		precision;
	int		full_len;
}	t_gather;

typedef struct s_pctlst
{
	char			*before_pct;
	char			*after_pct;
}	t_pctlst;

int			ft_printf(const char *s, ...);
int			ft_strchr_idx(const char *s, int c, int switcher);
void		analysis_pct(const char **cur, t_gather *fwp);
char		*make_pct(const char *cur, t_gather *fwp, size_t arg, int *cnt);
char		*make_num_mem(t_gather *fwp, size_t arg, int *cnt, int len);
int			salloc_int(char **new, int len, char fill);
void		ft_pctlstadd_back(t_pctlst **lst, t_pctlst *new);
t_pctlst	*ft_pctlstnew(char *before);
int			full_len_check(t_gather *fwp, int *len);
void		info_fwp(t_gather *fwp);
int			check_len_max(int *cnt, int check);
int			isfg_incr(t_gather *fwp);
#endif

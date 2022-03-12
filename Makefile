# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 19:22:21 by minsuki2          #+#    #+#              #
#    Updated: 2022/03/12 22:33:49 by minsuki2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I$(HEADERDIR)

NAME = libftprintf.a
LIBFT = libft.a
LIBFTDIR = ./libft
MAINDIR = MAIN/
MAIN = $(MAINDIR)main_diu.c
TARGET = a.out

AR = ar
ARFLAGS = -rcus

PRINTFCDIR = .
PRINTFODIR = .
PRINTFCDIR_BONUS = .
PRINTFODIR_BONUS = .

HEADERDIR = .

PRINTFC = ft_printf.c		\
		  ft_printf_utils.c	\
		  analysis_pct.c	\
		  make_pct.c		\
		  make_num_mem.c

PRINTFC_BONUS = ft_printf.c		\
		  		ft_printf_utils.c	\
		  ft_printf_utils2.c\
		  analysis_pct.c	\
		  make_origin_len.c	\
		  make_cspct.c		\
		  make_diu.c		\
		  make_xp.c

_PRINTFOBJS = $(PRINTFC:.c=.o)
_PRINTFOBJS_BONUS = $(PRINTFC_BONUS:.c=.o)
PRINTFOBJS = $(addprefix $(PRINTFODIR)/, $(_PRINTFOBJS))
PRINTFOBJS_BONUS = $(addprefix $(PRINTFODIR_BONUS)/, $(_PRINTFOBJS_BONUS))

PRINTFHEADER = $(HEADERDIR)/ft_printf.h
PRINTFHEADER_BONUS = $(HEADERDIR)/ft_printf_bonus.h

ifdef WITH_BONUS
	PRINTFCDIR = $(PRINTFCDIR_BONUS)
	PRINTFODIR = $(PRINTFODIR_BONUS)
	PRINTFOBJS = $(PRINTFOBJS_BONUS)
	PRINTFHEADER = $(PRINTFHEADER_BONUS)
endif

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(PRINTFOBJS)
	make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFT) $@
	$(AR) $(ARFLAGS) $@ $^

exe: $(TARGET)

$(TARGET): $(NAME) $(MAIN) $(INCLUDES)
	@echo --------------------------------
	@echo $@ Making...
	$(CC) -g $(MAIN) $(PRINTFC) -I./ -L./ -lftprintf

diu: $(DIU_TARGET)

$(DIU_TARGET): $(NAME) $(MAIN) $(INCLUDES)
	@echo --------------------------------
	@echo $@ Making...
	$(CC) -g $(MAIN_DIU) $(PRINTFC) -I./ -L./ -lftprintf

# %.out: %.c bonus $(NAME) $(MAIN) $(INCLUDES)
#     $(CC) -g $(addprefix $(MAIN:%.c=%)_, $(<:ft_%=%)) -I./ $< -L./ -lft


$(PRINTFODIR)/%.o: $(PRINTFCDIR)/%.c $(PRINTFHEADER)

clean:
	make clean -C $(LIBFTDIR)
	$(RM) $(PRINTFOBJS) $(PRINTFOBJS_BONUS)

fclean:
	make fclean -C $(LIBFTDIR)
	$(RM) $(PRINTFOBJS) $(PRINTFOBJS_BONUS)
	$(RM) $(LIBFT)
	$(RM) $(NAME)

re: fclean all

bonus:
	@make WITH_BONUS=1 all

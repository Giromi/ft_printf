# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 19:22:21 by minsuki2          #+#    #+#              #
#    Updated: 2022/03/13 01:19:37 by minsuki2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I$(HEADERDIR)

NAME = libftprintf.a
LIBFT = libft.a
LIBFTDIR = ./libft
MAINDIR = MAIN/
MAIN_PRINTF = $(MAINDIR)main_printf.c
MAIN_FT_PRINTF = $(MAINDIR)main_ft_printf.c
TARGET_PRINTF = printf.out
RESULT_PRINTF = printf.txt
TARGET_FT_PRINTF = ft_printf.out
RESULT_FT_PRINTF = ft_printf.txt

AR = ar
ARFLAGS = -rcus

PRINTFCDIR = .
PRINTFODIR = .
PRINTFCDIR_BONUS = .
PRINTFODIR_BONUS = .

HEADERDIR = .

FT_PRINTF_SRC_FILES = ft_printf.c		\
		  			  ft_printf_utils.c	\
		  			  analysis_pct.c	\
		  			  make_pct.c		\
		  			  make_num_mem.c


PRINTFC_BONUS_SRC_FILES = ft_printf.c		\
		  			  ft_printf_utils.c	\
		  			  analysis_pct.c	\
		  			  make_pct.c		\
		  			  make_num_mem.c

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

ans: $(RESULT_PRINTF)

# cat -e $<

$(RESULT_PRINTF): $(TARGET_PRINTF)
	./$< > $@

$(TARGET_PRINTF): $(MAIN_PRINTF)
	$(CC) $< -I./libft/ -o $@


exe: $(RESULT_FT_PRINTF) all

# cat -e $<

$(RESULT_FT_PRINTF): $(TARGET_FT_PRINTF)
	./$< > $@

$(TARGET_FT_PRINTF): $(MAIN_FT_PRINTF) $(FT_PRINTF_SRC_FILES)
	$(CC) $< -I./ -L./ -lftprintf -o $@

cmp: ans exe
	@echo
	@echo "@@@@@@@@@@ cmp result @@@@@@@@@@"
	diff -a $(RESULT_PRINTF) $(RESULT_FT_PRINTF)| cat -e

$(TARGET): $(NAME) $(MAIN) $(INCLUDES)
	@echo --------------------------------
	@echo $@ Making...
	$(CC) -g $(MAIN_FT_PRINTF) $(PRINTFC) -I./ -L./ -lftprintf -o ft_printf.out


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

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 19:22:21 by minsuki2          #+#    #+#              #
#    Updated: 2022/03/13 02:33:40 by minsuki2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
RM = rm -v
CFLAGS = -Wall -Wextra -Werror -I$(HEADERDIR)

MAKE_LIBFT = make -C $(LIBFTDIR)
NAME = libftprintf.a
LIBFT = libft.a

LIBFTDIR = ./libft

MANDATORY_DIR = mandatory/
BONUS_DIR = bonus/

MAIN_DIR = MAIN/
MAIN_PRINTF = $(MAIN_DIR)main_printf.c
MAIN_FT_PRINTF = $(MAIN_DIR)main_ft_printf.c

TARGET_PRINTF = $(MAIN_DIR)printf.out
TARGET_FT_PRINTF = $(MAIN_DIR)ft_printf.out
RESULT_FT_PRINTF = $(MAIN_DIR)ft_printf.txt
RESULT_PRINTF = $(MAIN_DIR)printf.txt

AR = ar
ARFLAGS = -rcus

FT_PRINTF_SRC_FILES = ft_printf.c		\
		  			  ft_printf_utils.c	\
		  			  analysis_pct.c	\
		  			  make_pct.c		\
		  			  make_num_mem.c


FT_PRINTF_BONUS_SRC_FILES = ft_printf_bonus.c		\
		  			  	    ft_printf_utils_bonus.c	\
		  			  	    analysis_pct_bonus.c	\
		  			  	    make_pct_bonus.c		\
		  			  	    make_num_mem_bonus.c

FT_PRINTF_INC_FILES = ft_printf.h
FT_PRINTF_BONUS_INC_FILES = ft_printf_bonus.h

FT_PRINTF_SRCS = $(addprefix $(MANDATORY_DIR), $(FT_PRINTF_SRC_FILES))
FT_PRINTF_OBJS = $(FT_PRINTF_SRCS:.c=.o)
FT_PRINTF_INCS = $(addprefix $(MANDATORY_DIR), $(FT_PRINTF_INC_FILES))

PRINTFOBJS = $(addprefix $(PRINTFODIR)/, $(_PRINTFOBJS))
# PRINTFOBJS_BONUS = $(addprefix $(PRINTFODIR_BONUS)/, $(_PRINTFOBJS_BONUS))




all: $(NAME)

$(NAME): $(FT_PRINTF_OBJS)
	make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFT) $@
	$(AR) $(ARFLAGS) $@ $^

ans: $(RESULT_PRINTF)

$(RESULT_PRINTF): $(TARGET_PRINTF)
	./$< > $@

$(TARGET_PRINTF): $(MAIN_PRINTF)
	$(CC) $< -I./libft/ -o $@

exe: $(RESULT_FT_PRINTF) all

$(RESULT_FT_PRINTF): $(TARGET_FT_PRINTF)
	./$< > $@

$(TARGET_FT_PRINTF): $(MAIN_FT_PRINTF) $(FT_PRINTF_INC_FILES)
	$(CC) $< -I./ -L./ -lftprintf -o $@

cmp: ans exe
	@echo
	@echo "@@@@@@@@@@ cmp result @@@@@@@@@@"
	diff -a $(RESULT_PRINTF) $(RESULT_FT_PRINTF)| cat -e

# $(TARGET): $(NAME) $(MAIN) $(FT_PRINTF_INCS)
#     @echo --------------------------------
#     @echo $@ Making...
#     $(CC) -g $(MAIN_FT_PRINTF) $(PRINTFC) -I./ -L./ -lftprintf -o ft_printf.out

$(PRINTFODIR)/%.o: $(PRINTFCDIR)/%.c $(PRINTFHEADER)

clean:
	@echo ">>>>>>>>>>>>>>>> Delete List <<<<<<<<<<<<<<<<<<<<"
	@$(MAKE_LIBFT) clean
	@$(RM) $(FT_PRINTF_SRC_FILES:.c=.o) #$(FT_PRINTF_BONUS_SRC_FILES:.c=.o)
	@echo "-------------------------------------------------"

fclean: clean
	@echo >>>>Delete<<<<
	@$(RM) $(LIBFTDIR)$(LIBFT)
	@$(RM)$(NAME)

re: fclean all

bonus:
	@make "FT_PRINTF_SRCS = $(addprefix $(BONUS_DIR), $(FT_PRINTF_BONUS_SRC_FILES))
		   FT_PRINTF_INCS = $(addprefix $(BONUS_DIR), $(FT_PRINTF_BONUS_INC_FILES))" all

.PHONY: all clean fclean re bonus

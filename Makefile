# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 19:22:21 by minsuki2          #+#    #+#              #
#    Updated: 2022/03/20 15:00:08 by minsuki2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 				= gcc
CFLAGS 			= -Wall -Wextra -Werror -c
INC 			= -I
RM 				= rm -vf
AR 				= ar
ARFLAGS 		= -rcus
MAKE_C 			= make -C
MANDATORY_DIR 	= mandatory/
BONUS_DIR 		= bonus/
LIBFT_DIR 		= libft/
TARGET_DIR 		= $(MANDATORY_DIR)

LIBFT 			= libft.a
NAME	 		= libftprintf.a

SRC_FILES 		= ft_printf.c		\
		  		  ft_printf_utils.c	\
		  		  analysis_pct.c	\
		  		  make_pct.c		\
		  		  make_num_mem.c

BONUS_SRC_FILES = ft_printf_bonus.c			\
		  	      ft_printf_utils_bonus.c	\
		  	   	  analysis_pct_bonus.c		\
		  		  make_pct_bonus.c			\
				  make_num_mem_bonus.c

HAD_FILES 		= ft_printf.h
BONUS_HAD_FILES = ft_printf_bonus.h
LIBFT_H 		= libft.h

FT_PRINTF_OBJS = $(addprefix $(MANDATORY_DIR), $(SRC_FILES:.c=.o))
FT_PRINTF_HADS = $(addprefix $(MANDATORY_DIR), $(HAD_FILES))

FT_PRINTF_OBJS_BONUS = $(addprefix $(BONUS_DIR), $(BONUS_SRC_FILES:.c=.o))
FT_PRINTF_HADS_BONUS = $(addprefix $(BONUS_DIR), $(BONUS_HAD_FILES))

OBJS = $(FT_PRINTF_OBJS)
HADS = $(FT_PRINTF_HADS)

all: $(LIBFT_DIR)$(LIBFT) $(NAME)

$(LIBFT_DIR)$(LIBFT):
	$(MAKE_C) $(LIBFT_DIR)

$(NAME): $(OBJS)
	cp $(LIBFT_DIR)$(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c $(HADS)
	@echo $@ Making...
	$(CC) $(CFLAGS) $< $(INC)$(LIBFT_DIR) $(INC)$(TARGET_DIR) -o $@

clean:
	$(MAKE_C) $(LIBFT_DIR) clean
	@echo
	@echo ">>>>>>>>>>>>>>>> Delete List <<<<<<<<<<<<<<<<<<<<"
	@$(RM) $(FT_PRINTF_OBJS)
	@$(RM) $(FT_PRINTF_OBJS_BONUS)
	@echo ">>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<"
	@echo

fclean: clean
	@echo ">>>>>>>>>>>>>>>> Delete List <<<<<<<<<<<<<<<<<<<<"
	@$(RM) $(LIBFT_DIR)$(LIBFT)
	@$(RM) $(NAME)
	@echo ">>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<"
	@echo

re: fclean all

bonus: $(LIBFT_DIR)$(LIBFT)
	@$(MAKE) \
	"OBJS		= $(FT_PRINTF_OBJS_BONUS)"	\
	"HADS		= $(FT_PRINTF_HADS_BONUS)" 	\
	"TARGET_DIR	= $(BONUS_DIR)"				\
	all

.PHONY: all clean fclean re bonus

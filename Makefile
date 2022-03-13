# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 19:22:21 by minsuki2          #+#    #+#              #
#    Updated: 2022/03/13 22:29:29 by minsuki2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 				= gcc
CFLAGS 			= -Wall -Wextra -Werror -c
INC 			= -I
CUR_DIR			= ./
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

OBJ_FILES 		= $(SRC_FILES:.c=.o)
BONUS_OBJ_FILES = $(BONUS_SRC_FILES:.c=.o)

HAD_FILES 		= ft_printf.h
BONUS_HAD_FILES = ft_printf_bonus.h
LIBFT_H 		= libft.h


# HADS = $(addprefix $(TARGET_DIR), $(HAD_FILES))
# $(addprefix $(TARGET_DIR), $(BONUS_SRC_FILES))
#
FT_PRINTF_OBJS = $(addprefix $(MANDATORY_DIR), $(OBJ_FILES))
FT_PRINTF_HADS = $(addprefix $(MANDATORY_DIR), $(HAD_FILES))

FT_PRINTF_OBJS_BONUS = $(addprefix $(BONUS_DIR), $(BONUS_OBJ_FILES))
FT_PRINTF_HADS_BONUS = $(addprefix $(BONUS_DIR), $(BONUS_HAD_FILES))

OBJS = $(FT_PRINTF_OBJS)
HADS = $(FT_PRINTF_HADS)

#-----
MAIN_DIR = main/
MAIN_PRINTF = $(MAIN_DIR)main_printf.c
MAIN_FT_PRINTF = $(MAIN_DIR)main_ft_printf.c

TARGET_PRINTF = $(MAIN_DIR)printf.out
TARGET_FT_PRINTF = $(MAIN_DIR)ft_printf.out
RESULT_FT_PRINTF = $(MAIN_DIR)ft_printf.txt
RESULT_PRINTF = $(MAIN_DIR)printf.txt
#-----




all: $(LIBFT_DIR)$(LIBFT) $(NAME)

$(LIBFT_DIR)$(LIBFT):
	$(MAKE_C) $(LIBFT_DIR)

$(NAME): $(OBJS)
	cp $(LIBFT_DIR)$(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $@ $^


$(TARGET_DIR)%.o: $(TARGET_DIR)%.c $(HADS)
	$(CC) $(CFLAGS) $< $(INC)$(LIBFT_DIR) $(INC)$(TARGET_DIR) -o $@

%.o: %.c $(HADS)
	$(CC) $(CFLAGS) $< $(INC)$(LIBFT_DIR) $(INC)$(TARGET_DIR) -o $@

# ---------------------------
#

ans:
	@echo @@@@@@@@@@ printf @@@@@@@@@@
	cp $(MAIN_FT_PRINTF) $(MAIN_PRINTF)
	sed -i "" 's/ft_printf/printf/g' $(MAIN_PRINTF)
	@echo
	$(CC) -g $(MAIN_PRINTF) -I./libft/ -o $(TARGET_PRINTF)
	$(TARGET_PRINTF) > $(RESULT_PRINTF)
	@echo
	head -c 20 $(RESULT_PRINTF) | cat -e
	@echo
	grep -aw "cnt" $(RESULT_PRINTF)
# cat -e $(RESULT_PRINTF)



exe: all
	@echo @@@@@@@@@@ ft_printf @@@@@@@@@@
	@echo
	$(CC) -g $(MAIN_FT_PRINTF) $(FT_PRINTF_OBJS:.o=.c) $(INC)$(LIBFT_DIR) $(INC)$(TARGET_DIR) -L./ -lftprintf -o $(TARGET_FT_PRINTF)
	$(TARGET_FT_PRINTF) > $(RESULT_FT_PRINTF)
	@echo
	head -c 20 $(RESULT_FT_PRINTF) | cat -e
	@echo
	grep -aw "cnt" $(RESULT_FT_PRINTF)
# cat -e $(RESULT_FT_PRINTF)
#@echo

fsan: all
	$(CC) -fsanitize=address $(MAIN_FT_PRINTF) $(FT_PRINTF_OBJS:.o=.c) $(INC)$(LIBFT_DIR) $(INC)$(TARGET_DIR) -L./ -lftprintf -o $(TARGET_FT_PRINTF)
	$(TARGET_FT_PRINTF)

cmp: ans exe
	@echo
	@echo "@@@@@@@@@@ cmp result @@@@@@@@@@"
	diff -a $(RESULT_PRINTF) $(RESULT_FT_PRINTF) | cat -e

# $(TARGET): $(NAME) $(MAIN) $(FT_PRINTF_INCS)
#     @echo --------------------------------
#     @echo $@ Making...
#     $(CC) -g $(MAIN_FT_PRINTF) $(PRINTFC) -I./ -L./ -lftprintf -o ft_printf.out

clean:
	@echo ">>>>>>>>>>>>>>>> Delete List <<<<<<<<<<<<<<<<<<<<"
	$(MAKE_C) $(LIBFT_DIR) clean
	@echo
	$(RM) $(FT_PRINTF_OBJS)
	$(RM) $(FT_PRINTF_OBJS_BONUS)
	@echo "-------------------------------------------------"

fclean: clean
	@echo ">>>>>>>>>>>>>>>> Delete List <<<<<<<<<<<<<<<<<<<<"
	$(RM) $(LIBFT_DIR)$(LIBFT)
	$(RM) $(NAME)

re: fclean all

bonus: $(LIBFT_DIR)$(LIBFT)
	@$(MAKE) \
	"TARGET_DIR	= $(BONUS_DIR)"				\
	"OBJS		= $(FT_PRINTF_OBJS_BONUS)"	\
	"HADS		= $(FT_PRINTF_HADS_BONUS)" 	\
	all


.PHONY: all clean fclean re bonus ans exe

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 19:22:21 by minsuki2          #+#    #+#              #
#    Updated: 2022/03/13 06:16:45 by minsuki2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 				= gcc
CFLAGS 			= -Wall -Wextra -Werror -c
INC 			= -I
CUR_DIR			= ./
RM 				= rm -vf
AR 				= ar
ARFLAGS 		= -rcus
MAKE 			= make
MAKE_C 			= make -C


LIBFT_DIR 		= libft/
LIBFT 			= libft.a
LIBFT_H 		= libft.h
FT_PRINTF 		= libftprintf.a

MANDATORY_DIR 	= mandatory/
BONUS_DIR 		= bonus/
TARGET_DIR 		= $(MANDATORY_DIR)



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

FT_PRINTF_BONUS_SRCS = $(addprefix $(BONUS_DIR), $(BONUS_SRC_FILES))


FT_PRINTF_HADS = $(addprefix $(MANDATORY_DIR), $(HAD_FILES))
FT_PRINTF_BONUS_HADS = $(addprefix $(BONUS_DIR), $(BONUS_HAD_FILES))

FT_PRINTF_SRCS = $(SRC_FILES)
SRCS = $(addprefix $(TARGET_DIR), $(FT_PRINTF_SRCS))
HADS = $(addprefix $(TARGET_DIR), $(FT_PRINTF_HADS))
HADS = $(FT_PRINTF_HADS)
OBJS = $(SRCS:.c=.o)

#-----
MAIN_DIR = main/
MAIN_PRINTF = $(MAIN_DIR)main_printf.c
MAIN_FT_PRINTF = $(MAIN_DIR)main_ft_printf.c

TARGET_PRINTF = $(MAIN_DIR)printf.out
TARGET_FT_PRINTF = $(MAIN_DIR)ft_printf.out
RESULT_FT_PRINTF = $(MAIN_DIR)ft_printf.txt
RESULT_PRINTF = $(MAIN_DIR)printf.txt
#-----




all: $(FT_PRINTF)

#libft는 수정 안할거라는 전제
$(FT_PRINTF): $(LIBFT_DIR)$(LIBFT) $(OBJS)
	cp $< $@
	$(AR) $(ARFLAGS) $@ $(OBJS)

$(LIBFT_DIR)$(LIBFT):
	$(MAKE_C) $(LIBFT_DIR)

$(TARGET_DIR)%.o: $(TARGET_DIR)%.c $(HADS) $(LIBFT_DIR)$(LIBFT_H)
	@echo $@
	$(CC) $(CFLAGS) $< $(INC)$(LIBFT_DIR) $(INC)$(TARGET_DIR) -o $@



ans: $(RESULT_PRINTF)

$(RESULT_PRINTF): $(TARGET_PRINTF)
	$< > $@

$(TARGET_PRINTF): $(MAIN_PRINTF)
	$(CC) -g $< -I./libft/ -o $@



exe: all
	$(CC) -g $(MAIN_FT_PRINTF) $(SRCS) $(INC)$(LIBFT_DIR) $(INC)$(TARGET_DIR) -L./ -lftprintf -o $(TARGET_FT_PRINTF)
	$(TARGET_FT_PRINTF) > $(RESULT_FT_PRINTF)

cmp: ans exe
	@echo
	@echo "@@@@@@@@@@ cmp result @@@@@@@@@@"
	diff -a $(RESULT_FT_PRINTF) $(RESULT_PRINTF)| cat -e

# $(TARGET): $(NAME) $(MAIN) $(FT_PRINTF_INCS)
#     @echo --------------------------------
#     @echo $@ Making...
#     $(CC) -g $(MAIN_FT_PRINTF) $(PRINTFC) -I./ -L./ -lftprintf -o ft_printf.out

$(PRINTFODIR)/%.o: $(PRINTFCDIR)/%.c $(PRINTFHEADER)

clean:
	@echo ">>>>>>>>>>>>>>>> Delete List <<<<<<<<<<<<<<<<<<<<"
	$(MAKE_C) $(LIBFT_DIR) clean
	@echo
	$(RM) $(FT_PRINTF_SRCS:.c=.o)
	$(RM) $(FT_PRINTF_BONUS_SRCS:.c=.o)
	@echo "-------------------------------------------------"

fclean: clean
	@echo ">>>>>>>>>>>>>>>> Delete List <<<<<<<<<<<<<<<<<<<<"
	$(RM) $(LIBFT_DIR)$(LIBFT)
	$(RM) $(FT_PRINTF)

re: fclean all

bonus:
	@$(MAKE) "TARGET_DIR		= $(BONUS_DIR)
			  FT_PRINTF_SRCS 	= $(BONUS_SRC_FILES)
			  HADS				= $(HADS_FILES)
		   	 "all

.PHONY: all clean fclean re bonus

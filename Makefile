# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: haachtch <haachtch@student.codam.n>          +#+                      #
#                                                    +#+                       #
#    Created: 2020/08/31 19:48:29 by haachtch      #+#    #+#                  #
#    Updated: 2020/10/11 21:44:01 by haachtch      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRC_D  = src
INC_D = inc
OBJ_D = obj

SRC = $(SRC_D)/ft_atoi.c\
	  $(SRC_D)/ft_detect.c\
	  $(SRC_D)/ft_init_struct.c\
	  $(SRC_D)/ft_isdigit.c\
	  $(SRC_D)/ft_isdigit2.c\
	  $(SRC_D)/ft_itoa.c\
	  $(SRC_D)/ft_itoa2.c\
	  $(SRC_D)/ft_print_char.c\
	  $(SRC_D)/ft_print_int2.c\
	  $(SRC_D)/ft_print_int_width_and_dot.c\
	  $(SRC_D)/ft_print_int_zero_and_dot.c\
	  $(SRC_D)/ft_print_percent.c\
	  $(SRC_D)/ft_print_pointer.c\
	  $(SRC_D)/ft_putchar.c\
	  $(SRC_D)/ft_print_space_zero_function.c\
	  $(SRC_D)/ft_print_x.c\
	  $(SRC_D)/ft_strdup.c\
	  $(SRC_D)/ft_print_string.c\
	  $(SRC_D)/ft_print_u.c\
	  $(SRC_D)/ft_print_u2.c\
	  $(SRC_D)/ft_print_u3.c\
	  $(SRC_D)/ft_print_x2.c\
	  $(SRC_D)/ft_print_x3.c\
	  $(SRC_D)/ft_printf.c\
	  $(SRC_D)/ft_printf_utils.c\
	  $(SRC_D)/ft_putnbr.c\
	  $(SRC_D)/ft_putnbr_hex.c\
	  $(SRC_D)/ft_putstr.c\
	  $(SRC_D)/ft_putstrn.c\
	  $(SRC_D)/ft_star.c\
	  $(SRC_D)/ft_strlcpy.c\
	  $(SRC_D)/ft_strlen.c\
	  $(SRC_D)/ft_substr.c

INC =		$(INC_D)/libftprintf.h

OBJ := $(SRC:$(SRC_D)/%.c=$(OBJ_D)/%.o)

CC = clang
CC_FLAGS	=	-Wall -Wextra -Werror
AR_COMMAND	=	ar rsv

all: $(NAME)

$(NAME): $(OBJ_D) $(OBJ) $(INC_D) $(INC)
			$(AR_COMMAND) $(NAME) $(OBJ)

$(OBJ_D):
		mkdir -p $(OBJ_D)

$(OBJ): $(OBJ_D)/%.o: $(SRC_D)/%.c
		@$(CC) $(CC_FLAGS) -I$(INC_D) -c $< -o $@

clean:
		rm -rf $(OBJ_D)
/		rm	-rf *.dSYM

fclean: clean
	rm -f $(NAME)

re: fclean all

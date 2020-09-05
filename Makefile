# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybakker <ybakker@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/01 10:51:58 by ybakker           #+#    #+#              #
#    Updated: 2020/01/09 21:09:19 by haachtch      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRC		= ft_atoi.c ft_detect.c ft_init_struct.c ft_isdigit.c ft_isdigit2.c\
		 ft_itoa.c ft_itoa2.c ft_print_char.c ft_print_int2.c\
			ft_print_int_width_and_dot.c ft_print_int_zero_and_dot.c\
			ft_print_percent.c ft_print_pointer.c ft_putchar.c\
			ft_print_space_zero_function.c ft_print_x.c ft_strdup.c\
			ft_print_string.c ft_print_u.c ft_print_u2.c ft_print_u3.c\
			ft_print_x2.c ft_print_x3.c ft_printf.c ft_printf_utils.c\
			ft_putnbr.c ft_putnbr_hex.c ft_putstr.c ft_putstrn.c ft_star.c\
			ft_strlcpy.c ft_strlen.c ft_substr.c

OBJ		= $(SRC:.c=.o)
CFLAG	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(CFLAG) -c -I ./libft $(SRC)
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

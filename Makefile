# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/12/18 12:21:51 by kbedene      #+#   ##    ##    #+#        #
#    Updated: 2017/12/18 17:02:08 by kbedene     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = ft_printf.a

SRC_FILES =\
			ft_printf.c\
			ft_conversion.c ft_convert_spec.c\
			ft_apply_flags.c ft_apply_prec.c ft_apply_width.c\
			ft_check_flags.c ft_check_width.c ft_check_precision.c\
			ft_check_size.c\
			ft_get_type.c ft_init_spec.c ft_isflag.c ft_isize.c\
			ft_wint_to_str.c\
			ft_proc_s.c ft_proc_s_maj.c\
			ft_proc_d.c ft_proc_x.c ft_proc_p.c\
			ft_proc_c.c\
			ft_ctoa.c ft_putcstr.c ft_strncpy.c\

LIBFT_FILES =\
			ft_atoi.c ft_bzero.c ft_islower.c\
			ft_putchar.c ft_putchar_fd.c\
			ft_atoi_binary.c\
			ft_itoa.c ft_itoa_base.c\
			ft_isdigit.c ft_putnbr.c ft_putnbr_fd.c\
			ft_memalloc.c ft_strcdup.c ft_strjoin.c ft_strdup.c\
			ft_strcpy.c ft_strrev.c ft_strclen.c\
			ft_putstr.c ft_putstr_fd.c\
			ft_pow.c ft_strcat.c ft_strchr.c ft_strlen.c ft_strtoupper.c\
			ft_swap.c ft_toupper.c\

SRCS = $(addprefix srcs/, $(SRC_FILES))

SRCS_LIB = $(addprefix srcs/, $(LIBFT_FILES))

OBJ = $(SRCS:.c=.o) $(SRCS_LIB:.c=.o)

CC = gcc

FLAGS = -Wall -Werror -Wextra

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

./srcs/%.o: ./srcs/%.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

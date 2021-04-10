# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chan <chan@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/10 14:41:35 by chan              #+#    #+#              #
#    Updated: 2021/04/10 16:27:05 by chan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= printf.a

SRC 		= ft_printf.c \
		  ft_libft.c \
		  ft_c_printf.c \
		  ft_d_printf.c \
		  ft_p_printf.c \
		  ft_s_printf.c \
		  ft_u_printf.c \
		  ft_lx_printf.c \
		  ft_sx_printf.c \
		  ft_printf_utils.c

OBJS					= $(SRCS:%.c=%.o)

BNS_OBJS				= $(BNS_SRCS:%.c=%.o)

FLAGS					= -Wall -Wextra -Werror

$(NAME)		: $(OBJS)
			gcc $(FLAGS) -c $(SRCS) -I/
			ar rc $(NAME) $(OBJS)

all	:	$(NAME)

bonus	:	$(NAME)
		gcc $(FLAGS) -c $(BNS_SRCS) -I/
		ar rc $(NAME) $(BNS_OBJS)

clean	:
		rm -f $(OBJS) $(BNS_OBJS)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re

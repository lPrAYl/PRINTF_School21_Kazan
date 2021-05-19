NAME = libftprintf.a

SRCS =	ft_printf.c			ft_parsing.c	ft_printing_chars.c\
		ft_printf_utils.c

OBJS = $(patsubst %.c, %.o, $(SRCS))

FLAGS = -Wall -Werror -Wextra

HEADER = ft_printf.h libft/libft.h

all : $(NAME)

$(NAME) : $(OBJS) $(HEADER)
	ar rcs $@ $?

%.o : %.c
	gcc $(FLAGS) -c $< -o $@

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
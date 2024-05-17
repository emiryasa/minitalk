SRCS = ft_printf.c ft_putnbrs.c ft_putstrs.c ft_strlen.c ft_atoi.c \

OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a
CC = gcc
ARFLAGS = -rc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar $(ARFLAGS) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME) 

re: fclean all

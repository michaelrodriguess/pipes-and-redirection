SRCS	=
OBJS	=	$(SRCS:.c=.o) 
CC		=	cc 
RM		=	rm -f
CFLAGS	=	-Wall -Werror -Wextra
NAME	=	
LIBC	=	ar -rcs


.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I .

$(NAME):	$(OBJS)
		$(LIBC) $(NAME) $(OBJS)

all:	$(NAME)
	
clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re

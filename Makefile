SRCS		=	pipex.c \
				pipex_utils.c \

OBJS		=	$(SRCS:.c=.o) 
CC			=	cc 
RM			=	rm -f
CFLAGS		=	-Wall -Werror -Wextra
NAME		=	pipex
LIBFT_PATH	=	./libft	
LIBFT		=	$(LIBFT_PATH)/libft.a

$(NAME):
		make -C $(LIBFT_PATH)
		$(CC) $(CFLAGS) $(SRCS) -o $(NAME) -L./libft -lft  

all:	$(NAME)
	
clean:
		make clean -C $(LIBFT_PATH)
		$(RM) $(OBJS)

fclean:	clean
		make fclean -C $(LIBFT_PATH)
		$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re

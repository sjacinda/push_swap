NAME	=	push_swap

SRCS	=	commands.c main.c parser.c utils.c

HEADER	=	push_swap.h
OBJ		=	$(patsubst %.c, %.o, $(SRCS))

FT_LIB	=	./libft/libft.a

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I. -I./libft -g

.PHONY	:	libft all clean fclean re

libft:
	$(MAKE) -C ./libft

$(FT_LIB): libft

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(FT_LIB)
	$(CC) $(CFLAGS) $^ -o $@

%.o		:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	@rm -f $(OBJ)
	@$(MAKE) clean -C ./libft

fclean	:	clean
	@ $(RM) $(NAME)
	@$(MAKE) fclean -C ./libft

re		:	fclean all
NAME	=	push_swap
NAME_B	=	checker

HEADER	=	push_swap.h
FT_LIB	=	./libft/libft.a

SRCS	=	commands.c parser.c utils.c sorting.c main.c
SRCS_B	=	commands.c parser.c utils.c sorting.c bonus.c

OBJ		=	$(SRCS:.c=.o)
OBJ_B	=	$(SRCS_B:.c=.o)

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I. -I./libft -g
RM		=	rm -rf

.PHONY:	all clean fclean re libft bonus

all:	$(NAME)

$(NAME):	$(OBJ) $(FT_LIB)
	ar -rcs $(NAME) $?

$(NAME_B):	$(OBJ_B) $(FT_LIB)
	ar -rcs $(NAME) $?

libft:
	@$(MAKE) -C ./libft

$(FT_LIB):	libft

%.o:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

bonus:	$(NAME_B)

clean:
	@$(RM) $(OBJ)
	@$(RM) $(OBJ_B)
	@$(MAKE) clean -C ./libft

fclean:	clean
	@$(RM) $(NAME)
	@$(RM) $(NAME_B)
	@$(MAKE) fclean -C ./libft

re:	fclean all

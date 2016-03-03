NAME=test_gnl
FLAGS=-Wall -Wextra -Werror
SRCS=get_next_line.c main.c
OBJS=$(SRCS:.c=.o)
LIB=libft

all: gnl

help:
	@echo "Ce Makefile compile votre GNL selon les consignes du sujet"
	@echo "cibles: all, gnl, %.o, clean, fclean, re"

gnl: $(OBJS)
	@echo "\033[32mWaiting for compilation...\033[0m\n"
	@make -C $(LIB)
	@gcc -o $(NAME) $(OBJS) -L $(LIB) -lft
	@echo "\033[32mGNL ready to be tested\033[0m\n"
	@echo "\033[34m\033[1musage: ./test_gnl \"filename\" or ./test_gnl with no args to read stdin\033[0m"

%.o: %.c
	@gcc $(FLAGS) -I libft/includes/ -c $(SRCS)

clean: 
	@rm -f $(OBJS)
	@echo "\033[31mDeleted: GNL objects\033[0m"

fclean: clean
	@make -C $(LIB) fclean
	@rm -f $(NAME)
	@echo "\033[31mlibft directory cleaned\033[0m"
	@echo "\033[31mDeleted: GNL test executable\033[0m\n"

re: clean fclean all

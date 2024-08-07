NAME = atoi.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = -rm -rf
AR = ar rcs

SRC = ft_atoi.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

CC	= cc
CCFLAGS	= -Wall -Wextra -Werror

SERVER	= server
CLIENT	= client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus
FT_PRINTF = ft_printf/ft_printf.a
FT_ATOI = utils/ft_atoi.a
#FT_PRINTF = ft_printf
#ATOI	= atoi
SRCS_SERVER	= server.c
SRCS_CLIENT	= client.c
SRCS_SERVER_BONUS = server_bonus.c
SRCS_CLIENT_BONUS = client_bonus.c
#SRCS_PRINTF	= ft_printchar.c ft_printdec.c ft_printf.c ft_printhex.c ft_printptr ft_printstr\
	  ft_printun.c
#SRCS_ATOI	= ft_atoi.c

#OBJS_PRINTF	= $(SRCS_PRINTF:.c=.o)
#OBJS_ATOI	= $(SRCS_ATOI:.c=.o)
OBJS_SERVER	= $(SRCS_SERVER:.c=.o)
OBJS_CLIENT	= $(SRCS_CLIENT:.c=.o)
OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)
OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)

all: $(FT_PRINTF) $(FT_ATOI) $(SERVER) $(CLIENT)
#$(FT_PRINTF) $(ATOI)

#$(FT_PRINTF): $(OBJS_PRINTF)
#		$(CC) $(CCFLAGS) $(OBJS_PRINTF) -o $(FT_PRINTF)

#$(ATOI): $(OBJS_ATOI)
#		$(CC) $(CCFLAGS) $(OBJS_ATOI) -o $(ATOI)
$(FT_PRINTF):
			$(MAKE) -C ./ft_printf
$(FT_ATOI):
			$(MAKE) -C ./utils

$(SERVER): $(OBJS_SERVER)
		$(CC) $(CCFLAGS) $(OBJS_SERVER) ft_printf/libftprintf.a utils/atoi.a -o $(SERVER)

$(CLIENT): $(OBJS_CLIENT)
		$(CC) $(CCFLAGS) $(OBJS_CLIENT) ft_printf/libftprintf.a utils/atoi.a -o $(CLIENT)

bonus: $(FT_PRINTF) $(FT_ATOI) $(SERVER_BONUS) $(CLIENT_BONUS)

$(FT_PRINTF):
			$(MAKE) -C ./ft_printf
$(FT_ATOI):
			$(MAKE) -C ./utils

$(SERVER_BONUS): $(OBJS_SERVER_BONUS)
			$(CC) $(CCFLAGS) $(OBJS_SERVER_BONUS) ft_printf/libftprintf.a utils/atoi.a -o $(SERVER_BONUS)

$(CLIENT_BONUS): $(OBJS_CLIENT_BONUS)
			$(CC) $(CCFLAGS) $(OBJS_CLIENT_BONUS) ft_printf/libftprintf.a utils/atoi.a -o $(CLIENT_BONUS)

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_PRINTF) $(OBJS_ATOI) $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_CLIENT_BONUS) $(OBJS_SERVER_BONUS)
	#rm -rf $(SERVER) $(CLIENT) $(FT_PRINTF) $(ATOI) $(SERVER_BONUS) $(CLIENT_BONUS)

	$(MAKE) fclean -C ./ft_printf
	$(MAKE) fclean -C ./utils

fclean: clean
		$(MAKE) fclean -C ./ft_printf
		$(MAKE) fclean -C ./utils
		rm -rf $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS) $(NAME)

re: fclean all fclean bonus

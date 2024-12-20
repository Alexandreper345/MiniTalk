NAMEC = client
NAMES =  server
PRINTF = libftprintf.a
LIBFT = libft.a
SRCC_FILES = client.c
SRCS_FILES = server.c
SRC_DIR = src/
SRCC = $(addprefix $(SRC_DIR), $(SRCC_FILES))
SRCS = $(addprefix $(SRC_DIR), $(SRCS_FILES))
OBJC = ${SRCC:.c=.o}
OBJS = ${SRCS:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I include
RM = rm -rf

all:	$(NAMEC) $(NAMES)

$(NAMEC): $(OBJC)
	@make -C Printf
	@make -C Libft
	$(CC) $(CFLAGS) $(OBJC) $(INCLUDE) Printf/$(PRINTF) Libft/$(LIBFT) -o $(NAMEC)


$(NAMES): $(OBJS)
	@make -C Printf
	@make -C Libft
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) Printf/$(PRINTF) Libft/$(LIBFT) -o $(NAMES)

clean:
	@make clean -C Printf
	@make clean -C Libft
	${RM} ${OBJC}
	${RM} ${OBJS}


fclean: clean
	@make clean -C Printf
	@make clean -C Libft
	${RM} ${NAMEC}
	${RM} ${NAMES}
	${RM} ${PRINTF}
	${RM} ${LIBFT}

re: fclean all

.PHONEY: all clean fclean re	

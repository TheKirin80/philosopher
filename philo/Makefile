SRC_DIR	= src

SRC_FILES	= forks.c get.c set.c routine.c free.c tool.c gest_param.c main.c philosopher.c

SRCS = $(SRC_FILES)

INC		= -I includes

OBJS	= ${SRCS:.c=.o}

OBJSBON	= ${SRCSBON:.c=.o}

NAME 	= philosopher

CC 		= clang

RM 		= rm -f

CFLAGS	= -Wall -Wextra -Werror -fsanitize=thread #-g3

all:		${NAME}

.c.o :
			$(CC) $(CFLAGS) $(INC) -c $< -o $@

${NAME}:	${OBJS}
			$(CC) $(CFLAGS) $(OBJS) -lpthread -o $(NAME) 
clean:		
			${RM} ${OBJS} ${OBJSBON}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus
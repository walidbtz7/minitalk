CLIENT    		=   client

SERVER    		=   server

C_SRCS    		=   client.c helper.c

S_SRCS    		=   server.c helper.c

FLAGS 			=	-Wall -Wextra -Werror

C_OBJS			=    $(C_SRCS:.c=.o)

S_OBJS			=    $(S_SRCS:.c=.o)

RM        		=    rm -f

all:    $(SERVER) $(CLIENT)

$(CLIENT):
	cc $(FLAGS) $(C_SRCS) -o $(CLIENT)

$(SERVER):
	cc $(FLAGS) $(S_SRCS) -o $(SERVER)

clean:
	${RM} ${C_OBJS} ${S_OBJS}

fclean:    clean
	${RM} ${CLIENT} ${SERVER}

re:        fclean all

.PHONY:		all clean fclean re bonus
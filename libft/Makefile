NAME = libft.a

INC				= inc/
SRC_DIR			= src/

SRCS = \
	$(SRC_DIR)ft_putstr_fd.c \
	$(SRC_DIR)ft_putendl_fd.c\
	$(SRC_DIR)ft_putchar_fd.c \
	$(SRC_DIR)ft_bzero.c \
	$(SRC_DIR)ft_calloc.c \
	$(SRC_DIR)ft_strjoin.c \
	$(SRC_DIR)ft_substr.c \
	$(SRC_DIR)ft_strlcpy.c \
	$(SRC_DIR)ft_strlen.c\
	$(SRC_DIR)ft_split.c \
	$(SRC_DIR)ft_strcmp.c \

OBJS = ${SRCS:.c=.o}

OBJSBONUS = ${BONUS:.c=.o}

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS} ${OBJSBONUS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all
NAME = libft.a

SRCS = \
	file/ft_putstr_fd.c \
	file/ft_putendl_fd.c\
	file/ft_putchar_fd.c \
	\
	mem/ft_bzero.c \
	mem/ft_calloc.c \
	\
	str/ft_strjoin.c \
	str/ft_substr.c \
	str/ft_strlcpy.c \
	str/ft_strlen.c\
	str/ft_split.c \
	str/ft_strcmp.c \

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
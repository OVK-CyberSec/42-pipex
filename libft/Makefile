NAME = libft.a

SRCS = \
	src/ft_putstr_fd.c \
	src/ft_putendl_fd.c\
	src/ft_putchar_fd.c \
	src/ft_bzero.c \
	src/ft_calloc.c \
	src/ft_strjoin.c \
	src/ft_substr.c \
	src/ft_strlcpy.c \
	src/ft_strlen.c\
	src/ft_split.c \
	src/ft_strcmp.c \

OBJS = ${SRCS:.c=.o}

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all
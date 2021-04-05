# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aberry <aberry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/05 20:48:28 by aberry            #+#    #+#              #
#    Updated: 2021/04/05 22:15:05 by aberry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:		all re clean fclean

NAME		=	philo_one

CC			=	gcc

TOOLS		=	$(addprefix  ../tools/, input)

INC			=	$(addprefix -I, $(addsuffix /includes/, . $(TOOLS)))

CFLAGS		=	-O3 -MMD $(INC) #-Wall -Wextra -Werror 

FILES		=	$(addprefix $(addsuffix /src/, $(TOOLS)), \
					$(addprefix utils/,\
						get_number.c\
						isdigit.c\
						ismoreint.c\
						isnumber.c\
						isspace.c\
						strlen.c\
					)\
					$(addprefix validation_input/,\
						$(addprefix check/,\
							argument_size.c\
							argument_value.c\
						)\
						initialization_simulation.c\
						validation_value.c\
					)\
				)\
				$(addprefix src/,\
					main.c\
				)

OBJS		=	$(FILES:.c=.o)
DEPENDS		=	$(OBJS:.o=.d)

all:		$(NAME)

debug:		CFLAGS	+= -fsanitize=address -g
debug:		all;

$(NAME):	$(OBJS)
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	rm -rf ${OBJS} ${DEPENDS}

fclean:		clean
	rm -rf ${NAME}

re:			fclean all

-include ${DEPENDS}
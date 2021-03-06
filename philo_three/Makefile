# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aberry <aberry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/05 20:48:28 by aberry            #+#    #+#              #
#    Updated: 2021/04/13 14:18:53 by aberry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:		all re clean fclean debug

NAME		=	philo_three

CC			=	gcc

TOOLS		=	$(addprefix  ../tools/, input time)

INC			=	$(addprefix -I, $(addsuffix /includes/, . $(TOOLS)))

CFLAGS		=	-O3 -MMD $(INC) -Wall -Wextra -Werror 

FILES		=	$(addprefix ../tools/input/src/, \
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
				$(addprefix ../tools/time/src/, \
						msleep.c\
						gettimeofday.c\
						get_time_now.c\
					)\
				$(addprefix src/,\
					$(addprefix initialization/,\
						init_philosophers.c\
						init_simulation.c\
					)\
					$(addprefix utils/,\
						destroy_simulation.c\
						print_message.c\
					)\
					$(addprefix process/,\
						$(addprefix philosopher/,\
							live_philo.c\
						)\
						$(addprefix supervisor/,\
							create_detach.c\
							create_join.c\
							$(addprefix child/,\
								check_count_eat.c\
								check_death.c\
								observation_of_philo.c\
							)\
							$(addprefix parent/,\
								dead.c\
								eat.c\
							)\
						)\
						$(addprefix initialization_process/,\
							creat_fork.c\
						)\
						start_simulation.c\
					)\
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

norm:
	norminette -R CheckForbiddenSourceHeader
	norminette -R CheckForbiddenSourceHeader ../tools

-include ${DEPENDS}
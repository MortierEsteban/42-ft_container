BLU							=	\033[0;34m
GRN							=	\033[0;32m
RED							=	\033[0;31m
RST							=	\033[0m
END							=	\e[0m

CC							=	g++
CC_FLAGS					=	-Wall -Werror -Wextra -std=c++98
NAME						=	Map
NAME_STD					=	Map_std	
OBJS_DIR					=	objs
OBJECTS_PREFIXED			=	$(addprefix	$(OBJS_DIR)/,	$(OBJS))
OBJECTS_PREFIXED_STD		=	$(addprefix	$(OBJECTS_PREFIXED), "-std.o")
OBJS						=	$(SRCS:.cpp=.o)
DEPENDENCIES				=	$(OBJECTS_PREFIXED:.o=.d)
SRCS						=	main_map.cpp	\



all:	$(NAME)

$(OBJS_DIR):
		@mkdir	-p	$(OBJS_DIR)

$(OBJS_DIR)/%.o	:	%.cpp Makefile | $(OBJS_DIR)
		@$(CC)	$(CC_FLAGS)	-MMD	-c	$<	-o	$@-std.o
		@$(CC)	$(CC_FLAGS)	-MMD	-DNAMESPACE=ft -c	$<	-o	$@
		@printf				"\033[2K\r${BLU}[BUILD]${RST}	'$<'	$(END)"

$(NAME):	$(OBJECTS_PREFIXED)
		@$(CC)	-o	$(NAME)	$(OBJECTS_PREFIXED)	$(CC_FLAGS)
		@$(CC) $(CC_FLAGS)	-o	$(NAME_STD) $(OBJECTS_PREFIXED_STD)
		@printf	"\033[2K\r\033[0;32m[END]\033[0m	$(NAME)$(END)\n"
		@./$(NAME)
		@./$(NAME_STD)

clean:
		@rm	-rf	$(OBJS_DIR)
		@printf	"\033[2K\r${GRN}[CLEAN]${RST}	done$(END)"

fclean:	clean
		@rm $(NAME) $(NAME_STD)
		@printf	"\033[2K\r${GRN}[FCLEAN]${RST}	done$(END)"

re:	fclean	all

.PHONY:	all	clean	fclean	re

-include	$(DEPENDENCIES)%
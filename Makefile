BLU							=	\033[0;34m
GRN							=	\033[0;32m
RED							=	\033[0;31m
RST							=	\033[0m
END							=	\e[0m

CC							=	g++
CC_FLAGS					=	-Wall -Werror -Wextra -std=c++98

NAME						=	Container
NAME_STD					=	Container-STD

OBJS_DIR					=	objs
OBJS						=	$(SRCS:.cpp=.o)
OBJECTS_PREFIXED			=	$(addprefix	$(OBJS_DIR)/,	$(OBJS))
DEPENDENCIES				=	$(OBJECTS_PREFIXED:.o=.d)
OBJECTS_PREFIXED_STD		=	$(OBJS_DIR)/main.o-std.o \
								$(OBJS_DIR)/$(MAP_DIR)/tester/map_test.o-std.o \
								$(OBJS_DIR)/$(VECTOR_DIR)/tester/vector_test.o-std.o \
								$(OBJS_DIR)/$(STACK_DIR)/tester/stack_test.o-std.o

TRACE_DIR					= trace
MAP_DIR						= map
VECTOR_DIR					= vector
STACK_DIR					= stack

SRCS		=	main.cpp \
				$(MAP_DIR)/tester/map_test.cpp \
				$(VECTOR_DIR)/tester/vector_test.cpp \
				$(STACK_DIR)/tester/stack_test.cpp


all:	$(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/$(MAP_DIR)
	@mkdir -p $(OBJS_DIR)/$(MAP_DIR)/tester
	@mkdir -p $(OBJS_DIR)/$(VECTOR_DIR)
	@mkdir -p $(OBJS_DIR)/$(VECTOR_DIR)/tester
	@mkdir -p $(OBJS_DIR)/$(STACK_DIR)
	@mkdir -p $(OBJS_DIR)/$(STACK_DIR)/tester

$(TRACE_DIR):
	@mkdir -p $(TRACE_DIR)
	@mkdir -p $(TRACE_DIR)/$(MAP_DIR)
	@mkdir -p $(TRACE_DIR)/$(MAP_DIR)/ft
	@mkdir -p $(TRACE_DIR)/$(MAP_DIR)/std
	@mkdir -p $(TRACE_DIR)/$(VECTOR_DIR)
	@mkdir -p $(TRACE_DIR)/$(VECTOR_DIR)/ft
	@mkdir -p $(TRACE_DIR)/$(VECTOR_DIR)/std
	@mkdir -p $(TRACE_DIR)/$(STACK_DIR)
	@mkdir -p $(TRACE_DIR)/$(STACK_DIR)/ft
	@mkdir -p $(TRACE_DIR)/$(STACK_DIR)/std

$(OBJS_DIR)/%.o	:	%.cpp Makefile  common.hpp | $(OBJS_DIR)
		@$(CC)	$(CC_FLAGS)	-MMD -c	$<	-o	$@-std.o
		@$(CC)	$(CC_FLAGS)	-MMD -DNAMESPACE=ft -c	$<	-o	$@
		@printf				"\033[2K\r${BLU}[BUILD]${RST}	'$<'	$(END)"
		
$(NAME): $(OBJECTS_PREFIXED) | $(TRACE_DIR)
		@$(CC) $(CC_FLAGS) -o	$(NAME)	$(OBJECTS_PREFIXED)	
		@$(CC) $(CC_FLAGS) -o	$(NAME_STD) $(OBJECTS_PREFIXED_STD)
		@printf	"\033[2K\r\033[0;32m[END]\033[0m	$(NAME)$(END)\n"

diff:
	@sh map/tester/map_diff.sh
	@sh vector/tester/vector_diff.sh
	@sh stack/tester/stack_diff.sh

clean:
		@rm -rf $(TRACE_DIR) $(OBJS_DIR)
		@printf	"\033[2K\r${GRN}[CLEAN]${RST}	done $(END)"

fclean:	clean
		@rm -rf $(NAME) $(NAME_STD)
		@printf	"\033[2K\r${GRN}[FCLEAN]${RST}	done$(END)"

re:	fclean	all

.PHONY:	all	clean	fclean	re diff 

-include	$(DEPENDENCIES)%
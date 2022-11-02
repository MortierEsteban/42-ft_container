BLU			= \033[0;34m
GRN			= \033[0;32m
RED			= \033[0;31m
RST			= \033[0m
END			= \e[0m

CC					=	g++
CC_FLAGS			=	-Wall -Werror -Wextra -std=c++98 #-g3 -fsanitize=address 
NAME				=	Container
OBJS_DIR			=	objs

VECTOR_DIR				=	vector/
NAME_VECTOR				= 	vector-test
OBJECTS_PREFIXED_VECTOR	=	$(addprefix $(OBJS_DIR)/, $(OBJS_VECTOR))
OBJS_VECTOR				=	$(SRCS_VECTOR:.cpp=.o)
DEPENDENCIES_VECTOR		=	$(OBJECTS_PREFIXED_VECTOR:.o=.d)
SRCS_VECTOR				=	$(VECTOR_DIR)main_vector.cpp \

STACK_DIR				=	stack/
NAME_STACK				= 	stack-test
OBJECTS_PREFIXED_STACK	=	$(addprefix $(OBJS_DIR)/, $(OBJS_STACK))
OBJS_STACK				=	$(SRCS_STACK:.cpp=.o)
DEPENDENCIES_STACK		=	$(OBJECTS_PREFIXED_STACK:.o=.d)
SRCS_STACK				=	$(STACK_DIR)main_stack.cpp \

MAP_DIR					=	map/
NAME_MAP				= 	map-test
OBJECTS_PREFIXED_MAP	=	$(addprefix $(OBJS_DIR)/, $(OBJS_MAP))
OBJS_MAP				=	$(SRCS_MAP:.cpp=.o)
DEPENDENCIES_MAP		=	$(OBJECTS_PREFIXED_MAP:.o=.d)
SRCS_MAP				=	$(MAP_DIR)main_map.cpp \
				

all: $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/$(MAP_DIR)
	@mkdir -p $(OBJS_DIR)/$(VECTOR_DIR)
	@mkdir -p $(OBJS_DIR)/$(STACK_DIR)

$(OBJS_DIR)/%.o : %.cpp Makefile | $(OBJS_DIR)
	@$(CC) $(CC_FLAGS) -MMD -c $< -o $@
	@printf    "\033[2K\r${BLU}[BUILD]${RST} '$<' $(END)"

$(NAME) : map vector stack
	@printf "\033[2K\r\033[0;32m[END]\033[0m "ALL Containers" $(END)\n"

tester:
	gcl https://github.com/mli42/containers_test.git

map: $(OBJECTS_PREFIXED_MAP)
	@$(CC) -o $(NAME_MAP) $(OBJECTS_PREFIXED_MAP) $(CC_FLAGS)
	@printf "\033[2K\r\033[0;32m[END]\033[0m "MAP" $(END)\n"
	
vector: $(OBJECTS_PREFIXED_VECTOR)
	@$(CC) -o $(NAME_VECTOR) $(OBJECTS_PREFIXED_VECTOR) $(CC_FLAGS)
	@printf "\033[2K\r\033[0;32m[END]\033[0m "VECTOR" $(END)\n"

stack: $(OBJECTS_PREFIXED_STACK)
	@$(CC) -o $(NAME_STACK) $(OBJECTS_PREFIXED_STACK) $(CC_FLAGS)
	@printf "\033[2K\r\033[0;32m[END]\033[0m "MAP" $(END)\n"

clean:
	@rm -rf $(OBJS_DIR)
	@printf "\033[2K\r${GRN}[CLEAN]${RST} done$(END)"

fclean: clean
	@rm -f $(NAME)
	@printf "\033[2K\r${GRN}[FCLEAN]${RST} done$(END)"

re: fclean all

.PHONY:	all clean fclean re

-include $(DEPENDENCIES)%
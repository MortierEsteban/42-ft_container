BLU			= \033[0;34m
GRN			= \033[0;32m
RED			= \033[0;31m
RST			= \033[0m
END			= \e[0m

CC					=	g++
CC_FLAGS			=	-Wall -Werror -Wextra -std=c++98 -g3 -fsanitize=address 
NAME				=	Container
OBJS_DIR			=	objs
VECTOR_DIR			=	vector/
MAP_DIR				=	map/
OBJECTS_PREFIXED	=	$(addprefix $(OBJS_DIR)/, $(OBJS))
OBJS				=	$(SRCS:.cpp=.o)
DEPENDENCIES		=	$(OBJECTS_PREFIXED:.o=.d)
SRCS				=	$(MAP_DIR)main.cpp \
				
all: $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/$(VECTOR_DIR)
	@mkdir -p $(OBJS_DIR)/$(MAP_DIR)

$(OBJS_DIR)/%.o : %.cpp Makefile | $(OBJS_DIR)
	@$(CC) $(CC_FLAGS) -MMD -c $< -o $@
	@printf    "\033[2K\r${BLU}[BUILD]${RST} '$<' $(END)"

$(NAME): $(OBJECTS_PREFIXED)
	@$(CC) -o $(NAME) $(OBJECTS_PREFIXED) $(CC_FLAGS)
	@printf "\033[2K\r\033[0;32m[END]\033[0m $(NAME)$(END)\n"

clean:
	@rm -rf $(OBJS_DIR)
	@printf "\033[2K\r${GRN}[CLEAN]${RST} done$(END)"

fclean: clean
	@rm -f $(NAME)
	@printf "\033[2K\r${GRN}[FCLEAN]${RST} done$(END)"

re: fclean all

test: re 
	./$(NAME) > log.txt 

.PHONY:	all clean fclean re

-include $(DEPENDENCIES)%
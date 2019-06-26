SRC=$(shell find src -type f)
INCLUDE=include
GCC=clang++
FLAGS=-Wextra -Wall -Werror -std=c++11
NAME=avn
OBJ_PATH=objs
INCLUDE=include
OBJ:=$(patsubst src%.cpp,$(OBJ_PATH)%.o, $(SRC))

.PHONY: re

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Linking..."
	@$(GCC) $(OBJ) -o $(NAME) $(FLAGS)
	
$(OBJ_PATH)/%.o : src/%.cpp $(OBJ_PATH)
	@echo $@ '>>' $<
	@$(GCC) $< -o $@ $(FLAGS) -I $(INCLUDE) -c
	
	
$(OBJ_PATH):
	mkdir $(OBJ_PATH)

re: fclean $(NAME)

clean:
	@echo clearing objects
	@rm -rf $(OBJ_PATH)

fclean: clean
	@echo clearing excicutable
	@rm $(NAME)
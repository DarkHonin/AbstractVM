SRC=$(shell find src -type f)
INCLUDE=include
GCC=clang++
FLAGS=-Wextra -Wall -Werror -std=c++11
NAME=avn
OBJ_PATH=objs
INCLUDE=include
OBJ:=$(patsubst src%.cpp,$(OBJ_PATH)%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(GCC) $(OBJ) -o $(NAME) $(FLAGS)
	
$(OBJ_PATH)/%.o : src/%.cpp $(OBJ_PATH)
	@echo $@ $<
	@$(GCC) $< -o $@ $(FLAGS) -I $(INCLUDE) -c
	
$(OBJ_PATH):
	mkdir $(OBJ_PATH)

re:

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm $(NAME)

info:
	@echo $(SRC)
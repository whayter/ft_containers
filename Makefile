ifdef STD
NAME = std_containers
else
NAME = ft_containers
endif

INC_DIR = ./includes
SRC_DIR = ./sources
OBJ_DIR = ./obj

SRC = vector.cpp stack.cpp map.cpp main.cpp
vpath %.cpp $(SRC_DIR)

INC = vector.hpp stack.hpp map.hpp
INC += binary_search_tree.hpp
INC += algorithm.hpp
INC += iterator.hpp
INC += type_traits.hpp
INC += utility.hpp
vpath %.hpp $(INC_DIR)

OBJ = $(addprefix  $(OBJ_DIR)/,$(SRC:%.cpp=%.o))
vpath %.cpp $(SRC_DIR)

CXX = clang++
IFLAGS = $(foreach inc, $(INC_DIR),-I$(inc))
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address -fstandalone-debug
ifdef STD
CXXFLAGS += -D STD=1
endif

STRT_STYLE = \033[0;32m
END_STYLE = \033[0m

all: $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(IFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@echo "$(STRT_STYLE)Compiling $@...$(END_STYLE)"
	$(CXX) $(CXXFLAGS) $(IFLAGS) $(OBJ) -o $@
	@echo "$(STRT_STYLE)Done.$(END_STYLE)"

test:
	@(sh test.sh)

clean:
	@echo "$(STRT_STYLE)Cleaning...$(END_STYLE)"
	@rm -rf $(OBJ_DIR)
	@(echo "$(STRT_STYLE)Done.$(END_STYLE)")

fclean: clean
	@echo "$(STRT_STYLE)Fcleaning...$(END_STYLE)"
	@rm -rf $(NAME)
	@rm -rf std_containers
	@rm -rf out
	@(echo "$(STRT_STYLE)Done.$(END_STYLE)")

re: fclean all

.PHONY: all clean fclean re test
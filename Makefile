NAME = ft_containers

SRC_DIR = ./src
INC_DIR = ./inc
OBJ_DIR = ./obj

SRC = main.cpp
vpath %.cpp $(SRC_DIR)
INC = list.hpp vector.hpp map.hpp stack.hpp queue.hpp
vpath %.hpp $(INC_DIR)
OBJ = $(addprefix  $(OBJ_DIR)/,$(SRC:%.cpp=%.o))
vpath %.cpp $(SRC_DIR)

IFLAGS = $(foreach inc, $(INC_DIR),-I$(inc))
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

CXX = clang++
RM = rm -rf
MV = mv
MKD = mkdir -p
STRT_STYLE = \033[1;32m
END_STYLE = \033[0m

all: $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@($(MKD) $(OBJ_DIR))
	@($(CXX) $(CXXFLAGS) -c $(IFLAGS) $< -o $@)

$(NAME): $(OBJ)
	@(echo "$(STRT_STYLE)Compiling...$(END_STYLE)")
	@$(CXX) $(CXXFLAGS) $(IFLAGS)  -o $@ $(OBJ)
	@(echo "$(STRT_STYLE)Done.$(END_STYLE)")

clean:
	@(echo "$(STRT_STYLE)Cleaning...$(END_STYLE)")
	@($(RM) $(OBJ_DIR))
	@(echo "$(STRT_STYLE)Done.$(END_STYLE)")

fclean: clean
	@(echo "$(STRT_STYLE)Fcleaning...$(END_STYLE)")
	@($(RM) $(NAME))
	@(echo "$(STRT_STYLE)Done.$(END_STYLE)")

re: fclean all

.PHONY: all clean fclean re
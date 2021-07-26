NAME = stack

SRC_DIR = ./src
INC_DIR = ./inc
OBJ_DIR = ./obj

SRC = stack.cpp
vpath %.cpp $(SRC_DIR)
INC = stack.hpp
INC += ../utility/algorithm.hpp
INC += ../utility/iterator.hpp
INC += ../utility/type_traits.hpp
INC += ../utility/utility.hpp
vpath %.hpp $(INC_DIR)
OBJ = $(addprefix  $(OBJ_DIR)/,$(SRC:%.cpp=%.o))
vpath %.cpp $(SRC_DIR)

IFLAGS = $(foreach inc, $(INC_DIR),-I$(inc))
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 #-Wno-c++11-extensions

CXX = clang++
RM = rm -rf
MV = mv
MKD = mkdir -p
STRT_STYLE = \033[0;32m
END_STYLE = \033[0m

all: $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@($(MKD) $(OBJ_DIR))
	@($(MKD) $(OBJ_DIR)/ft)
	@($(CXX) $(CXXFLAGS) -c $(IFLAGS) $< -o obj/ft/stack.o)
	@($(MKD) $(OBJ_DIR)/std)
	@($(CXX) $(CXXFLAGS) -c $(IFLAGS) $< -D STD=1 -o obj/std/stack.o)

$(NAME): $(OBJ)
	@(echo "$(STRT_STYLE)Compiling ft_stack...$(END_STYLE)")
	@$(CXX) $(CXXFLAGS) $(IFLAGS)  -o ft_$@ obj/ft/stack.o
	@(echo "$(STRT_STYLE)Done.$(END_STYLE)")
	@(echo "$(STRT_STYLE)Compiling std_stack...$(END_STYLE)")
	@$(CXX) $(CXXFLAGS) $(IFLAGS)  -o std_$@ obj/std/stack.o
	@(echo "$(STRT_STYLE)Done.$(END_STYLE)")

test:
	@(sh test.sh)

clean:
	@(echo "$(STRT_STYLE)Cleaning stack...$(END_STYLE)")
	@($(RM) $(OBJ_DIR))
	@($(RM) out)
	@(echo "$(STRT_STYLE)Done.$(END_STYLE)")

fclean: clean
	@(echo "$(STRT_STYLE)Fcleaning stack...$(END_STYLE)")
	@($(RM) ft_$(NAME))
	@($(RM) std_$(NAME))
	@($(RM) ft_stack.txt)
	@($(RM) std_stack.txt)
	@(echo "$(STRT_STYLE)Done.$(END_STYLE)")

re: fclean all

.PHONY: all clean fclean re test
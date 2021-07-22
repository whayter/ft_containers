NAME = vector

SRC_DIR = ./src
INC_DIR = ./inc
OBJ_DIR = ./obj

SRC = vector.cpp
vpath %.cpp $(SRC_DIR)
INC = vector.hpp
INC += ../utility/algorithm.hpp
INC += ../utility/iterator.hpp
INC += ../utility/type_traits.hpp
INC += ../utility/utility.hpp
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
	@($(MKD) $(OBJ_DIR)/ft)
	@($(CXX) $(CXXFLAGS) -c $(IFLAGS) $< -o obj/ft/vector.o)
	@($(MKD) $(OBJ_DIR)/std)
	@($(CXX) $(CXXFLAGS) -c $(IFLAGS) $< -D STD=1 -o obj/std/vector.o)

$(NAME): $(OBJ)
	@(echo "$(STRT_STYLE)Compiling ft_vector...$(END_STYLE)")
	@$(CXX) $(CXXFLAGS) $(IFLAGS)  -o ft_$@ obj/ft/vector.o
	@(echo "$(STRT_STYLE)Done.$(END_STYLE)")
	@(echo "$(STRT_STYLE)Compiling std_vector...$(END_STYLE)")
	@$(CXX) $(CXXFLAGS) $(IFLAGS)  -o std_$@ obj/std/vector.o
	@(echo "$(STRT_STYLE)Done.$(END_STYLE)")

clean:
	@(echo "$(STRT_STYLE)Cleaning...$(END_STYLE)")
	@($(RM) $(OBJ_DIR))
	@($(RM) out)
	@(echo "$(STRT_STYLE)Done.$(END_STYLE)")

fclean: clean
	@(echo "$(STRT_STYLE)Fcleaning...$(END_STYLE)")
	@($(RM) ft_$(NAME))
	@($(RM) std_$(NAME))
	@($(RM) ft_vector.txt)
	@($(RM) std_vector.txt)
	@(echo "$(STRT_STYLE)Done.$(END_STYLE)")

re: fclean all

.PHONY: all clean fclean re
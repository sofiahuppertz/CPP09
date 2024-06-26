NAME = PmergeMe

CXX = c++
INCLUDE = include
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I$(INCLUDE)


SRCS_PATH = src
OBJS_PATH = obj
		
SRCS = $(wildcard $(SRCS_PATH)/*.cpp)
OBJS = $(SRCS:$(SRCS_PATH)/%.cpp=$(OBJS_PATH)/%.o)

# ANSI escape codes for colors
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
NC = \033[0m # No Color

.SECONDARY : $(OBJS)

all : $(NAME)

$(NAME): $(OBJS)
	@echo "${YELLOW}Compiling...${NC}"
	@$(CXX) -I./dec $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "${GREEN}Done${NC}"


$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.cpp 
	@echo "${BLUE}Compiling $<...${NC}"
	@mkdir -p $(OBJS_PATH)
	@$(CXX) $(CXXFLAGS) -I./dec -c $< -o $@
	

clean:
	@echo "${RED}Deleting object files...${NC}"
	@rm -f $(OBJS)
	@rm -rf $(OBJS_PATH)

fclean: clean
	@echo "${RED}Deleting executable...${NC}"
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
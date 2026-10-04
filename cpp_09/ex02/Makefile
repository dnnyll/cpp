# definitions
INC_DIR			=		inc
SRC_DIR			=		src
NAME			=		PmergeMe
CXX				=		c++
CXXFLAGS		=		-Wall -Wextra -Werror -std=c++98 -I$(INC_DIR)

# debug flag: DEBUG=1 also switches to a separate object/binary tree, so objects
# compiled with -DDEBUG can never be reused by a release build and vice versa.
ifdef DEBUG
CXXFLAGS		+=		-DDEBUG -DPMERGEME_DEBUG_BUILD
BUILD			=		debug
else
BUILD			=		release
endif

OBJ_DIR			=		obj/$(BUILD)
BIN_DIR			=		bin/$(BUILD)

# sources and objects
SRCS			=		main.cpp	\
						PmergeMe.cpp

OBJS			=		$(SRCS:%.cpp=$(OBJ_DIR)/%.o)

# compilation rule
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
						mkdir -p $(OBJ_DIR)
						$(CXX) $(CXXFLAGS) -c $< -o $@

# default target
all: $(NAME)

# named target: refresh the symlink so that it always points at the binary of the
# build you just asked for. Phony on purpose, otherwise ./$(NAME) would keep its
# own (newer) timestamp and `make all` after `make debug` would silently serve
# the debug binary.
.PHONY: $(NAME)
$(NAME): $(BIN_DIR)/$(NAME)
						ln -sf $(BIN_DIR)/$(NAME) ./$(NAME)

# builds with -DDEBUG into obj/debug and bin/debug
.PHONY: debug
debug:
						$(MAKE) DEBUG=1 all

# builds the traced implementation instead of the release one
.PHONY: trace
trace:
						$(MAKE) DEBUG=1 SRCS="main.cpp PmergeMeDebug.cpp" all


# linking binary
$(BIN_DIR)/$(NAME): $(OBJS)
						mkdir -p $(BIN_DIR)
						$(CXX) $(CXXFLAGS) $(OBJS) -o $@

# just make sure the binary and the symlink exist
link:					$(NAME)

# cleaning
#removes content of /bin and /obj directories
clean:
						rm -rf obj/*
						rm -rf bin/*

#removes content and directories /bin and /obj
fclean: clean
						rm -rf obj
						rm -rf bin
						rm -rf $(NAME)

re: fclean all

# phony targets
.PHONY: all clean fclean re link trace

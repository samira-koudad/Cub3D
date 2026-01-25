# ============================================================================
# CUB3D MAKEFILE
# ============================================================================

NAME			= cub3D
CC				= gcc
CFLAGS			= -Wall -Wextra -g
INCLUDES		= -I./includes -I./libft -I./gnl
RM				= rm -f

# ============================================================================
# DIRECTORIES
# ============================================================================

SOURCES_DIR		= sources
BUILD_DIR		= build
LIBFT_DIR		= libft
GNL_DIR			= gnl

# ============================================================================
# SOURCE FILES
# ============================================================================

SOURCES			= $(SOURCES_DIR)/main.c \
				  $(SOURCES_DIR)/parsing.c \
				   $(SOURCES_DIR)/pars.c \
				   $(SOURCES_DIR)/maps.c

OBJECTS			= $(SOURCES:%.c=$(BUILD_DIR)/%.o)

# LIBFT
LIBFT_NAME		= $(LIBFT_DIR)/libft.a

# GET_NEXT_LINE
GNL_FILES		= get_next_line.c get_next_line_utils.c
GNL_OBJECTS		= $(GNL_FILES:%.c=$(BUILD_DIR)/gnl/%.o)

# ============================================================================
# RULES
# ============================================================================

all: $(NAME)

$(NAME): $(LIBFT_NAME) $(OBJECTS) $(GNL_OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(GNL_OBJECTS) -L$(LIBFT_DIR) -lft $(INCLUDES) -o $(NAME)
	@echo "✓ $(NAME) built successfully!"

# LIBFT Rules (uses libft's own makefile)
$(LIBFT_NAME):
	@make -C $(LIBFT_DIR)
	@echo "✓ libft compiled!"

# GET_NEXT_LINE Rules
$(BUILD_DIR)/gnl/%.o: $(GNL_DIR)/%.c
	@mkdir -p $(BUILD_DIR)/gnl
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# CUB3D Rules
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(BUILD_DIR)/sources
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) -r $(BUILD_DIR)
	@make -C $(LIBFT_DIR) clean
	@echo "✓ Build files cleaned!"

fclean: clean
	$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "✓ Everything cleaned!"

re: fclean all

.PHONY: all clean fclean re

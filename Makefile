NAME = fdf

SRCS = draw.c \
	draw_line.c \
	draw_map.c \
	draw_point_with_height_color.c \
	ft_split_numbers.c \
	hooks.c \
	main.c \
	parsing.c \
	projection_isometric.c \
	projection_parallel.c \
	rotate.c \
	runtime.c
SRCS_DIR = srcs/
SRCS := $(addprefix $(SRCS_DIR), $(SRCS))
OBJS_DIRS = objs/
OBJS = $(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIRS)%.o)
DEPS = $(OBJS:%.o=%.d)
INCLUDE_DIRS = include/ libft/ mlx42/include/MLX42/
BIN_DIR = bin/

CC = gcc
IQUOTES = $(addprefix -iquote, $(INCLUDE_DIRS))
CFLAGS = -Wall -Werror -Wextra -MMD $(IQUOTES) -O3
# -g -fsanitize=address
# -O3

DOT_A = libft/libft.a \
	mlx42/build/libmlx42.a
GLFW_DIR = ${HOME}/homebrew/opt/glfw/lib
LDFLAGS = $(addprefix -L, $(dir $(DOT_A)) $(GLFW_DIR))
DOT_A_BASENAMES = $(notdir $(DOT_A))
LDLIBS = $(DOT_A_BASENAMES:lib%.a=-l%) -lglfw -framework Cocoa -framework OpenGL -framework IOKit

all: $(NAME)

$(NAME): $(OBJS) $(DOT_A)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -o $@ $(OBJS)

$(OBJS_DIRS)%.o:$(SRCS_DIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

libft/libft.a:
	@$(MAKE) -C $(dir $@)

mlx42/build/libmlx42.a:
	cd mlx42; \
	cmake -B build
	@$(MAKE) -C $(dir $@) -j4

bonus: all

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	@$(MAKE) -C libft/ $@
	@rm -rf mlx42/build/
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re

-include $(DEPS)
NAME = libft.a
INCLUDE_DIR = .

AR = ar -rc
CC = gcc
CFLAGS = -Wall -Wextra -Werror -MMD -O2 -I$(INCLUDE_DIR)
LDFLAGS = -L.
LDLIBS = -lft

SRCS = ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c
BONUS_SRCS = ft_lstadd_back_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstmap_bonus.c \
	ft_lstnew_bonus.c \
	ft_lstsize_bonus.c
FT_PRINTF_DIR = ft_printf/
FT_PRINTF_SRCS = aconsumer.c \
	display_char.c \
	display_numbers.c \
	display_str.c \
	ft_math.c \
	ft_printf.c \
	ft_str.c \
	ids.c \
	numbers_util.c \
	puts.c
FT_PRINTF_SRCS := $(addprefix $(FT_PRINTF_DIR),$(FT_PRINTF_SRCS))
GNL_DIR = get_next_line/
GNL_SRCS = get_next_line.c \
	get_next_line_utils.c
GNL_SRCS := $(addprefix $(GNL_DIR),$(GNL_SRCS))
SRCS := $(SRCS) $(BONUS_SRCS) $(FT_PRINTF_SRCS) $(GNL_SRCS)
OBJS_DIR = objs/
OBJS = $(addprefix $(OBJS_DIR),$(SRCS:.c=.o))
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $^

main: main.c $(NAME)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $< $(LDLIBS)

$(OBJS_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re

-include $(DEPS) $(BONUS_DEPS)
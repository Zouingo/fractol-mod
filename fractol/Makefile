NAME    := fractol
CFLAGS  := -Wextra -Wall -Werror
LIBMLX  := include/MLX42
LIBFT   := include/libft

HEADERS := -I ./include -I $(LIBMLX)/include/MLX42/ -I $(LIBFT)/include
LIBS    := $(LIBMLX)/build/libmlx42.a -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -lm -framework Cocoa -framework OpenGL -framework IOKit
SRCS    := $(shell find ./src -iname "*.c")
OBJS    := ${SRCS:.c=.o}

all: $(LIBMLX) $(OBJS) $(NAME)

$(LIBMLX):
	@if [ ! -d /Users/$(USER)/.brew ]; then \
		echo "\033[1;32mInstalling brew:\033[0m"; \
		-fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh; \
		echo "\033[1;32mBrew installed\033[0m"; \
	fi
	@if [ ! -d /Users/$(USER)/.brew/opt/glfw ]; then \
		echo "\033[1;32mInstalling glfw:\033[0m"; \
		brew install glfw; \
		echo "\033[1;32mglfw installed\033[0m"; \
	fi
	@if [ ! -d $(LIBMLX) ]; then \
		echo "\033[1;32mMaking libmlx:\033[0m"; \
		git clone https://github.com/Tanker50207/MLX42.git $(LIBMLX); \
		cmake -S $(LIBMLX) -B $(LIBMLX)/build -DCMAKE_INSTALL_PREFIX=$(LIBMLX)/include && \
		make -C $(LIBMLX)/build -j4 install; \
	fi

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re libmlx libft

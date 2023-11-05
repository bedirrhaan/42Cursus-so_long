SRC = src/main.c src/map_controls.c src/utils.c src/utils2.c src/path_finder.c src/utils3.c src/hook.c

INC = inc
NAME = so_long
BNAME = so_long_bonus
CFLAGS = -Wall -Werror -Wextra
MLX = mlx/libmlx.a

ifeq ($(shell uname), Linux)
	FRAMEWORKS = -L/mlx -lmlx -lX11 -lXext -lm
else
	FRAMEWORKS = -framework OpenGL -framework AppKit
endif

all: $(NAME)

$(NAME): $(SRC)
	@make -C mlx
	@gcc -g -o $@ $^ $(CFLAGS) $(FRAMEWORKS) $(MLX) -I $(INC)

bonus: $(BNAME)

$(BNAME): $(BSRC)
	@make -C mlx
	@gcc -o $@ $^ $(CFLAGS) $(FRAMEWORKS) $(MLX) -I $(INC)

clean:
	@rm -rf $(NAME)
	@rm -rf $(BNAME)

fclean: clean
	@make -C mlx clean

re: fclean all

.PHONY: clean fclean re all

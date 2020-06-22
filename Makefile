NAME =				RTv1

CFLAGS =			-Wall -Wextra -Werror
MLXFLAGS =			-framework OpenGL -framework AppKit

VECTORS =			vec_normalize.c			\
					vec_mult_num.c			\
					vec_sub_num.c			\
					vec_div_num.c			\
					vec_length.c			\
					vec_rotate.c			\
					vec_mult.c				\
					vec_sub.c				\
					vec_sum.c				\
					vec_dot.c				\
					vec_dir.c				\

READER = 			write_light_data.c		\
					write_obj_data.c		\
					write_cam_data.c		\
					scene_reader.c			\
					read_color.c			\
					get_type.c				\
					color.c					\

RENDER =			find_intersection.c		\
					calculate_normal.c		\
					ray_trace.c				\
					renderer.c				\
					shadow.c				\
					light.c					\

SRC =				$(VECTORS)				\
					$(READER)				\
					$(RENDER)				\
					hooks.c			 		\
					init.c					\
					main.c					\



SRC_PATH =			source/

INCL_PATH =			-I include
LIBFT_INCL_PATH =	-I libft/includes
MLX_INCL_PATH =		-I minilibx/

MLX_PATH =			minilibx/
LIBFT_PATH =		libft/

LIBS =				$(INCL_PATH) $(LIBFT_INCL_PATH) $(MLX_INCL_PATH)

OBJ =				$(SRC:.c=.o)

vpath %.c $(SRC_PATH)
vpath %.c $(SRC_PATH)render
vpath %.c $(SRC_PATH)vectors
vpath %.c $(SRC_PATH)args_check
vpath %.c $(SRC_PATH)scene_reader

.PHONY: all lib mlx re clean fclean

all: lib mlx $(NAME)
	@printf "\033[32mRTv1 ready!\033[0m\n"

$(NAME): $(OBJ)
	@gcc $(CFLAGS) $^ $(LIBS) $(MLX_LIB) $(LIBFT_PATH)libft.a $(MLX_PATH)libmlx.a $(MLXFLAGS) -o $(NAME)

$(OBJ): $(SRC)
	@gcc $(CFLAGS) -c $^ $(LIBS)

lib:
	@make -C $(LIBFT_PATH) re
	@make -C $(LIBFT_PATH) clean
	@printf "\033[32mLibFT ready!\033[0m\n"

mlx:
	@make -C $(MLX_PATH) 

clean:
	@rm -f $(OBJ)
	@printf "\033[33mObj files removed!\033[0m\n"

fclean:
	@make -C $(LIBFT_PATH) fclean
	@make -C $(MLX_PATH) clean
	@rm -f $(NAME)
	@rm -f $(OBJ)
	@printf "\033[31mRTv1 removed!\033[0m\n"

re: fclean all

clterm:
	@clear && printf '\033[3J'
# GENERAL ####################################################################
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror -g

# MINILIBX ###################################################################
MILX_NAME	:= minilibx
MILX_SRC	:= main_minilibx.c
MILX_DIR	:= mlx_linux
MILX_FLAGS	:= -I$(MILX_DIR) -L$(MILX_DIR) -lmlx -lXext -lX11 -lm -lz

# MACROLIBX ##################################################################
MALX_NAME	:= macrolibx
MALX_SRC	:= main_macrolibx.c
MALX_DIR	:= Macrolibx
MALX_FLAGS	:= -I$(MALX_DIR)/includes $(MALX_DIR)/libmlx.so -lSDL2

# MLX42 ######################################################################
MLX42_NAME	:= mlx42
MLX42_SRC	:= main_mlx42.c
MLX42_DIR	:= codam-mlx42
MLX42_FLAGS	:= -I$(MLX42_DIR)/include $(MLX42_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm

# RULES ######################################################################

all: setuplibs $(MILX_NAME) $(MALX_NAME) $(MLX42_NAME)

$(MILX_NAME): $(MILX_SRC)
	make -C $(MILX_DIR)
	$(CC) $(CFLAGS) -o $@ $^ $(MILX_FLAGS)


$(MALX_NAME): $(MALX_SRC)
	make -C $(MALX_DIR)
	$(CC) $(CFLAGS) -o $@ $^ $(MALX_FLAGS)


$(MLX42_NAME): $(MLX42_SRC)
	make -C $(MLX42_DIR)/build
	$(CC) $(CFLAGS) -o $@ $^ $(MLX42_FLAGS)


clean:
	rm -f $(MILX_NAME) $(MALX_NAME) $(MLX42_NAME)
	make -C $(MILX_DIR) clean
	make -C $(MALX_DIR) clean
	make -C $(MLX42_DIR)/build clean


re: clean all


setuplibs: $(MILX_DIR) $(MALX_DIR) $(MLX42_DIR)


$(MILX_DIR):
	wget https://cdn.intra.42.fr/document/document/26767/minilibx-linux.tgz
	tar -xpf minilibx-linux.tgz
	rm minilibx-linux.tgz
	mv minilibx-linux $(MILX_DIR)


$(MALX_DIR):
	git clone https://github.com/seekrs/MacroLibX.git $(MALX_DIR)


$(MLX42_DIR):
	git clone https://github.com/codam-coding-college/MLX42.git $(MLX42_DIR)
	cd $(MLX42_DIR) && mkdir build && cd build && cmake ..


clearlibs:
	rm -rf $(MILX_DIR)
	rm -rf $(MALX_DIR)
	rm -rf $(MLX42_DIR)

fclean: clean clearlibs

.PHONY: all clean re setuplibs clearlibs fclean

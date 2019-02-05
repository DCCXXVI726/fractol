# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thorker <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/15 17:25:57 by thorker           #+#    #+#              #
#    Updated: 2019/02/05 15:48:26 by thorker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
FLAG = 
SRC = set_start_arg.c put_interface.c main.c create_struct.c put_img.c put_smth_n_exit.c init_opencl.c move.c hook.c 
INC = -I /usr/local/include -I libft/
LIB = -L /usr/local/lib -lmlx -L libft/ -lft
FRWR = -framework OpenGL -framework OpenCL -framework AppKit

all: $(NAME)

$(NAME):
	make -C libft
	gcc $(FLAG) $(INC) $(LIB) $(SRC) $(FRWR) -o $(NAME)

clean:
	make -C libft/ clean
	rm -rf *.o

fclean: clean
	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean all

git: clean
	make -C libft/ git
	git add --all
	git status
	git commit -m "auto git"
	git push

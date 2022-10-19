GCC = gcc
FLAGS = -Wall -Wextra -Werror -g
NAME = miniRT.a

DIR_SRCS = ./srcs/
DIR_HEADER = ./includes/
SRCS = main.c \
	light.c\
	mlx_hook.c\
	parsing.c \
	parsing_viewer.c\
	three_value_2.c\
	viewer.c\
	main.c\
	mlx_img.c\
	parsing_object.c\
	ray.c\
	three_value_vector.c\
	matrix.c\
	object.c\
	parsing_utils.c\
	three_value_1.c\
	utils.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)
$(NAME) : $(addprefix $(DIR_SRCS), $(OBJS))
	ar rcs $@ $^
%.o : %.c
	$(GCC) $(FLAGS) -c -o $@ $^ -I $(DIR_HEADER) -g

fclean : clean
	@rm -rf $(NAME);

clean : 
	@rm -rf $(addprefix $(DIR_SRCS), $(OBJS));

re : clean fclean all
PHONY : all fclean clean re
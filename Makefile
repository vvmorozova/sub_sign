NAME		=	sub_sign

SRCS		=	$(wildcard $(SRCS_DIR)/*.c)
SRCS_DIR	=	src

HEADER		=	$(wildcard $(HEADER_DIR)/*.h)

HEADER_DIR	=	inc

CC			=	clang

FLAGS		=	-lm -I ${HEADER_DIR}

RM			=	rm -f

OBJ 		=	$(SRCS:$(SRCS_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_DIR		=	bin

all : $(NAME) 

run : $(NAME)
	./$(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ): $(OBJ_DIR)/%.o : $(SRCS_DIR)/%.c  $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re

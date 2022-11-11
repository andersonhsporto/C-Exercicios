EXEC1 = exercicio1
EXEC2 = exercicio2
EXEC3 = exercicio3
EXEC4 = exercicio4
EXEC5 = exercicio5

FLAGS = -Wall -Wextra -Werror
CC = gcc

all: $(EXEC1) $(EXEC2) $(EXEC3) $(EXEC4) $(EXEC5)

SRC1 = ./q_01/ex01.c
SRC2 = ./q_02/ex02.c
SRC3 = ./q_03/ex03.c
SRC4 = ./q_04/ex04.c
SRC5 = ./q_05/questao_05.c

OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)
OBJ3 = $(SRC3:.c=.o)
OBJ4 = $(SRC4:.c=.o)
OBJ5 = $(SRC5:.c=.o)

$(EXEC1): $(OBJ1)
	gcc $(FLAGS) $(OBJ1) -o $(EXEC1)

$(EXEC2): $(OBJ2)
	gcc $(FLAGS) $(OBJ2) -o $(EXEC2)

$(EXEC3): $(OBJ3)
	gcc $(FLAGS) $(OBJ3) -o $(EXEC3)

$(EXEC4): $(OBJ4)
	gcc $(FLAGS) $(OBJ4) -o $(EXEC4)

$(EXEC5): $(OBJ5)
	gcc $(FLAGS) $(OBJ5) -o $(EXEC5)

clean:
	rm -f $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5)

fclean: clean
	rm -f $(EXEC1) $(EXEC2) $(EXEC3) $(EXEC4) $(EXEC5)

re: fclean all




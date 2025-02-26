C_SRCS = Coordinator.c Checker.c
C_OBJS = Coordinator.o Checker.o

OBJS = ${C_OBJS}
EXE1 = coordinator 
# EXE2 needs to match the string passed to execlp in Coordinator.c
EXE2 = checker 

GCC = gcc
FLAGS = -Wextra

all: coordinator checker

coordinator: Coordinator.o 
	$(GCC) $(FLAGS) Coordinator.o -o $(EXE1)

checker: Checker.o 
	$(GCC) $(FLAGS) Checker.o -o $(EXE2)

clean:
	rm -f *.o *- $(EXE1) $(EXE2)

package:
	zip -r HW3.zip Coordinator.c Checker.c Makefile README.txt
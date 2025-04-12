CC=g++
FILES=Scheduler.cpp FCFS.cpp SJF.cpp PS.cpp
OUT_EXE=Scheduler
ARGS=
all: $(FILES)
	$(CC) -o $(OUT_EXE) $(FILES)
run: all
	./$(OUT_EXE) $(ARGS)
clean:
	rm -f *.o $(OUT_EXE)
	
package:
	zip Seefeldt-Tyler-HW5.zip README.txt Makefile Scheduler.cc
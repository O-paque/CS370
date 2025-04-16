CC=g++
FILES=Scheduler.cpp FCFS.cpp SJF.cpp PS.cpp FCFS.h SJF.h PS.h Process.h
OUT_EXE=Scheduler
ARGS=
all: $(FILES)
	$(CXX) -o $(OUT_EXE) $(FILES)
clean:
	rm -f *.o *.zip $(OUT_EXE)
	
package:
	zip Seefeldt-Tyler-HW5.zip README.txt Makefile Scheduler.cpp FCFS.cpp FCFS.h SJF.cpp SJF.h PS.cpp PS.h Process.h
CC=gcc
CFLAGS=-Wextra
OBJFILES=Driver.o MemoryManager.o
OUT_EXE=main
all: $(OUT_EXE)

$(OUT_EXE): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(OUT_EXE) $(OBJFILES)

clean:
	rm -f *.o $(OUT_EXE)


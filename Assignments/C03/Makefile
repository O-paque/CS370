CC=gcc
FILES=main.c
OUT_EXE=main
ARGS=
build: $(FILES)
	$(CC) -o $(OUT_EXE) $(FILES)
run: build
	./$(OUT_EXE) $(ARGS)
clean:
	rm -f *.o $(OUT_EXE)
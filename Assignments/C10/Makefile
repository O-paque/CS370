CC=gcc
FILES=main.c
OUT_EXE=main
ARGS=
build: $(FILES)
	$(CC) -o $(OUT_EXE) $(FILES)
run: build
	./main < infile
clean:
	rm -f *.o $(OUT_EXE)
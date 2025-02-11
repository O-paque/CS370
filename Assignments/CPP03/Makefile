CC=g++
FILES=main.cpp bank_account.cpp
OUT_EXE=main
ARGS=
build: $(FILES)
	$(CC) -o $(OUT_EXE) $(FILES)
run: build
	./$(OUT_EXE) $(ARGS)
clean:
	rm -f *.o $(OUT_EXE)
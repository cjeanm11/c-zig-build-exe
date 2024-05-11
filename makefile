run: build
	@./a.out

build: clean
	@clang -c *.c
	@clang -c src/*.c
	@clang ./*.o

clean:
	@rm -rf *.o > /dev/null 2>&1
	@rm -f a.out > /dev/null 2>&1
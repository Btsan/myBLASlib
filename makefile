test:
	g++ test.cpp -O2 -std=c++11 -pedantic-errors -mavx -m64 -o test

run:
	./test

clean:
	rm test
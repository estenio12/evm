Compiling:	./sources/*.cpp
	clang++ ./sources/*.cpp -std=c++17 -o ./bin/evm
	./bin/evm ./bin/app.bin
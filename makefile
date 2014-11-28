all: run_test

clean:
	rm -rf build

make_dir: clean
	mkdir build

compile_src: make_dir
	gcc src/main/SimpleCUnit.h -o build/SimpleCUnit.o

ar_compiled_src: compile_src
	ar -crsv build/libSimpleCUnit.a build/SimpleCUnit.o

compile_test: make_dir
	gcc src/test/SimpleCUnitTest.c -o build/SimpleCUnitTest -Isrc/main
	
run_test: compile_test
	./build/SimpleCUnitTest

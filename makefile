# Simple makefile for the project

source_files = main.c dynamic_array.c
runner_name = runner

all: $(source_files)
	cc -o $(runner_name) $(source_files)

analyze: $(source_files)
	cc --analyze $(source_files)

run: all
	./$(runner_name)

clean:
	rm -f *.plist $(runner_name)
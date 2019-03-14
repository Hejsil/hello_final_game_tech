
all: build/hello-world

build/hello-world: build src/main.c src/final_dynamic_opengl.h src/final_platform_layer.h
	cc src/main.c -ldl -o build/hello-world
	
build:
	mkdir build

clean:
	rm -r build
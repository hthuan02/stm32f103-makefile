PROJ_NAME := stack
OBJ_FILES = out/main.o
OBJ_FILES += out/$(PROJ_NAME).o


out/main.o: src/main.c
	@gcc -c -I./inc src/main.c -o out/main.o

out/$(PROJ_NAME).o: src/$(PROJ_NAME).c
	@gcc -c -I./inc src/$(PROJ_NAME).c -o out/$(PROJ_NAME).o

.PHONY: build
build: $(OBJ_FILES)
	@gcc $(OBJ_FILES) -o out/app.exe
	@echo "Build Done!"

.PHONY: run
run:
	./out/app.exe
	@echo "Running..."
clean:
	rm ./out/*.o
	@echo "Clear all output file.o of makefile!"

print-%:
	@echo $($(subst print-,,$@))
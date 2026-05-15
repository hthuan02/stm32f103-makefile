PROJ_NAME := circular
OBJ_FILES = out/main.o
OBJ_FILES += out/$(PROJ_NAME).o

# Build process: preprocessor, compilation, assemble to build object file (file.o)
out/main.o: src/main.c
	@gcc -c -I./inc src/main.c -o out/main.o

out/$(PROJ_NAME).o: src/$(PROJ_NAME).c
	@gcc -c -I./inc src/$(PROJ_NAME).c -o out/$(PROJ_NAME).o

.PHONY: build
build: $(OBJ_FILES)
	@gcc out/main.o out/$(PROJ_NAME).o -o out/application.exe
	@echo "Build Done!"

.PHONY: run
run:
	@./out/application.exe
	@echo "Running..."

clean:
	@rm ./out/*.o
	@echo "Clear All object file!"

print-%:
	@echo $($(subst print-,,$@))
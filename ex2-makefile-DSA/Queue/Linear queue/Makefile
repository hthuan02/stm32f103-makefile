PROJ_NAME := linear
OBJ_FILES = out/main.o
OBJ_FILES += out/$(PROJ_NAME).o
out/main.o: src/main.c
	@gcc -c -I./inc src/main.c -o out/main.o

out/$(PROJ_NAME).o: src/$(PROJ_NAME).c
	@gcc -c -I./inc src/$(PROJ_NAME).c -o out/$(PROJ_NAME).o

build: $(OBJ_FILES)
	@gcc out/main.o out/$(PROJ_NAME).o -o out/app.exe
	@echo "Build Done!"

run:
	./out/app.exe

clean:
	@rm ./out/*.o
	@echo "Remove output file.o!"

print-%:
	@echo $($(subst print-,,$@))

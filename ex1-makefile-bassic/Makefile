PROJ_NAME := sum
OBJ_FILES = out/main.o
OBJ_FILES += out/$(PROJ_NAME).o

out/main.o: src/main.c
	@gcc -c -I./inc src/main.c -o out/main.o

out/$(PROJ_NAME).o: src/$(PROJ_NAME).c
	@gcc -c -I./inc src/$(PROJ_NAME).c -o out/$(PROJ_NAME).o 
	
.PHONY: build
build: $(OBJ_FILES)
	@gcc out/main.o out/$(PROJ_NAME).o -o out/main.exe
	@echo "Build Done!"
	@echo $(OBJ_FILES)

.PHONY: run
run:
	./out/main.exe
	
clean:
	@rm ./out/*.o
	@echo "Clear ALL Output files!"
	
print-%:
	@echo $($(subst print-,,$@))
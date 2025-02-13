all: lib exercice00

lib:
	make -C matrix_lib/

exercice00:
	make -C Exercice00/

.PHONY: clean
clean:
	make clean -C Exercice00/
	make clean -C matrix_lib/

fclean:
	make fclean -C Exercice00/
	make fclean -C matrix_lib/
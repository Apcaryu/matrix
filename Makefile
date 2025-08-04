all: lib exercice00

lib:
	make -C matrix_lib/

all_exercice: exercice00 exercice01 exercice02 exercice03 exercice04 exercice05 exercice06 exercice07 exercice08 \
				exercice09 exercice10 exercice11 exercice12 exercice13

exercice00:
	make -C Exercice00/
exercice01:
	make -C Exercice01/
exercice02:
	make -C Exercice02/
exercice03:
	make -C Exercice03/
exercice04:
	make -C Exercice04/
exercice05:
	make -C Exercice05/
exercice06:
	make -C Exercice06/
exercice07:
	make -C Exercice07/
exercice08:
	make -C Exercice08/
exercice09:
	make -C Exercice09/
exercice10:
	make -C Exercice10/
exercice11:
	make -C Exercice11/
exercice12:
	make -C Exercice12/
exercice13:
	make -C Exercice13/
.PHONY: clean
clean:
	make clean -C Exercice00/
	make clean -C Exercice01/
	make clean -C Exercice02/
	make clean -C Exercice03/
	make clean -C Exercice04/
	make clean -C Exercice05/
	make clean -C Exercice06/
	make clean -C Exercice07/
	make clean -C Exercice08/
	make clean -C Exercice09/
	make clean -C Exercice10/
	make clean -C Exercice11/
	make clean -C Exercice12/
	make clean -C Exercice13/
	make clean -C matrix_lib/

fclean:
	make fclean -C Exercice00/
	make fclean -C Exercice01/
	make fclean -C Exercice02/
	make fclean -C Exercice03/
	make fclean -C Exercice04/
	make fclean -C Exercice05/
	make fclean -C Exercice06/
	make fclean -C Exercice07/
	make fclean -C Exercice08/
	make fclean -C Exercice09/
	make fclean -C Exercice10/
	make fclean -C Exercice11/
	make fclean -C Exercice12/
	make fclean -C Exercice13/
	make fclean -C matrix_lib/

re: fclean all
all: ordenacao

ordenacao: ordenacao.cpp
	@echo "Compilando arquivo objeto: ordenacao"
	@g++ -o ordenacao ordenacao.cpp

install: ordenacao
	@echo "Instalando no Sistema."
	@sudo cp ordenacao /usr/local/bin/ordenacao

clean:
	@echo "Limpando arquivos"
	-@rm -f ordenacao

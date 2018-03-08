/*
UFPB - CENTRO DE INFORMATICA
DISCIPLINA: ANÁLISE E PROJETO DE ALGORITMOS
AUTOR: BRUNO CORREIA
DATA: 07/03/2018
VERSÃO: 0.001
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

// CLASSE MENSAGEM
class mensagem
{
public:

	void versao(){
		cout<<"Versão 0.001"<<endl<<endl;
	}

	void ajuda(){
		cout<<"\nUso: ./ordenacao [OPÇÕES]\n\nOPÇÕES:\n\n -t [is|ss]     Tipo da Ordenação. P/ InsertionSort -> IS , SelectionSort -> SS.\n\n                        Ex.: -t is | -t ss\n\n -i [Arquivo]   Defini o arquivo deentrada, com os valores a seremordenados.\n\n                        Ex.: -i ./couting.txt | -i ~/ordenar.txt\n\n\n -h      Mostra esta tela de ajuda e sai\n -v      Mostra a versão do programa e sai\n\n\nExemplo completo de uso:\n\n./ordenacao -t ss -i entrada.txt\n\n";
	}

	void erro(){
		cout<<"Opção inválida, tente novamente. Use -h para ajuda."<<endl<<endl;
    }


};

void InsertionSort(int a[], int n){
    int i,j,elemento;

    for(i=1;i<n;i++){
        elemento = a[i];
        j = i;
        while(j>0 && a[j-1] > elemento) {
            a[j] = a[j-1];
            j = j - 1;
        }
        a[j] = elemento;
    }
}

void SelectionSort(int a[],int n) {
    int min, i, j;

    for(i = 0; i < (n-1) ; i++)
    {
        min = i;
        for( j = (i+1) ; j < n ; j++)
        {
            if(a[j]<a[min])
                min = j;
        }
        if(min!=i)
        {
            swap(a[min],a[i]);
        }
    }
}

int main(int argc, char *argv[]){

	mensagem exibir;

	int i, numParametros = argc;

	string	nomePrograma=argv[0], tipo, arquivoEntrada, arquivoSaida;


	if ( numParametros == 2 ){

		if (argv[1][0] == '-' ){

			switch(argv[1][1]){

				case 'v':
				case 'V':
					exibir.versao();
					return 0;
					break;

				case 'h':
				case 'H':
					exibir.ajuda();
					return 0;
					break;

				default:
					exibir.erro();
					return 1;
			}

		}

	} else if ( numParametros == 5 ){

			while ((++argv)[0]){

				if (argv[0][0] == '-' ){

					switch(argv[0][1]){

						case 't':
							tipo = argv[1];
							break;

						case 'i':
							arquivoEntrada = argv[1];
							break;

						default:
							exibir.erro();
							return 1;
					}

				}

			}

		// EXECUTION PROGRAM
		ifstream contar(arquivoEntrada.c_str());

		int N_LINHAS = 0;

		if(!contar.is_open()){
			cout << "Arquivo não pode ser aberto, verifique se o mesmo existe." << "\n\n";
			return 1;
		} else {
			string linha;

			while(getline(contar,linha)){
				++N_LINHAS;
			}

			contar.close();
		}

		int array[N_LINHAS];

		ifstream arquivo(arquivoEntrada.c_str());

		if(!arquivo.is_open()){
			cout << "Arquivo não pode ser aberto, verifique se o mesmo existe." << "\n\n";
			return 1;
		}

		for( i=0 ; i < N_LINHAS ; i++ ){
			arquivo >> array[i];
		}

		arquivo.close();

		if ( tipo == "IS" || tipo == "is" ) {
			
		    cout << endl << "Insertion Sort" << endl << endl;
		    cout << "Antes de ordenar:" << endl;

		    for (int i = 0;i < N_LINHAS; i++)
		        cout << array[i] << " ";

		    InsertionSort(array,N_LINHAS);

		    cout << endl << endl << "Depois de ordenar:" << endl;
		    for (int i = 0;i < N_LINHAS; i++)
		        cout << array[i] << " ";
		    cout << endl << endl;

		} else if ( tipo == "SS" || tipo == "ss" ){
			
		    cout << endl << "Selection Sort" << endl << endl;
		    cout << "Antes de ordenar:" << endl;

		    for (int i = 0;i < N_LINHAS; i++)
		        cout << array[i] << " ";

		    SelectionSort(array,N_LINHAS);

		    cout << endl << endl << "Depois de ordenar:" << endl;
		    for (int i = 0;i < N_LINHAS; i++)
		        cout << array[i] << " ";
		    cout << endl << endl;

		} else {

			cout << "Tipo inválido, use" << nomePrograma << " -h para ajuda." << "\n\n";
			return 1;

		}

	} else {

		exibir.erro();
		return 1;
	
	}

	return 0;

}
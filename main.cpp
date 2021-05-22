#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

void Funcao(int* ponteiro, int quantidadeElementos, int* valorMaximo, int* valorMinimo){
    int maior=*(ponteiro), menor=*(ponteiro), pos1=0, pos2=0;

    for (int i=0; i<quantidadeElementos; i++){
        if (maior < *(ponteiro+i)){
            maior = *(ponteiro+i);
            pos1 = i+1;
        }
        if (menor > *(ponteiro+i)){
            menor = *(ponteiro+i);
            pos2 = i+1;
        }
    }
    cout << "O vetor [ ";
    for (int i=0; i<quantidadeElementos; i++){
        cout << *(ponteiro+i) << " ";
    }
    cout << "] tem " << quantidadeElementos << " elementos e esta no endereco " << ponteiro << endl;
    cout << "O maior valor valor foi " << maior << " e estava na " << pos1 << "ª posicao no endereco " << valorMaximo << endl;
    cout << "O menor valor valor foi " << menor << " e estava na " << pos2 << "ª posicao no endereco " << valorMinimo << endl;
}

int main(){

    string a;
    cout << "Digite os numeros separados por espaco: ";
    getline(cin, a);

    int tamanho = 1;
    for (int i=0; i<a.length(); i++){
        if (a[i] == 32){
            if (i!=0){
                tamanho++;
            }
        }
    }

    int vetor[tamanho];
    string novaPalavra="";
    int cont=0;

    for (int i=0; i<a.length(); i++){
        novaPalavra += a[i];

        if (a[i] == 32){
            if (i!=0){
                vetor[cont] = stoi(novaPalavra);
                novaPalavra = "";
                cont++;
            }
        }
    }

    vetor[cont] = stoi(novaPalavra);

    int valorMaximo=0, valorMinimo=0;
    int* ponteiro;
    ponteiro = vetor;

    Funcao(ponteiro, tamanho, &valorMaximo, &valorMinimo);

}



#include <iostream>
#include "ArvBinBusca.h"

using namespace std;

int main()
{
    ArvBinBusca arv;

    cout << "Criando Arvore Binaria de Busca (ABB)" << endl;
    arv.insere(15);
    arv.insere(9);
    arv.insere(20);
    arv.insere(7);
    arv.insere(11);
    arv.insere(18);
    arv.insere(24);
    arv.insere(6);
    arv.insere(8);
    arv.insere(10);
    arv.insere(12);
    arv.insere(17);
    arv.insere(19);
    arv.insere(19);
    arv.insere(6);

    arv.imprime();
    cout << " mº pares ate o caminho"<<arv.contaParesCaminho(24)<<endl;
    cout << endl;
    arv.remove(7);
    arv.imprime();
    cout << endl;
    cout<< "maior = "<<arv.maior()<<"menor ="<<arv.menor();
    cout << endl;
    arv.removeMaior();
    arv.removeMenor();
    cout <<"Removido maior e menor"<<endl;

    arv.imprime();
    cout << endl;
    cout<< "maior = "<<arv.maior()<<"menor ="<<arv.menor();
    cout << endl;

    cout << "Media do caminho ate o no com valor 18: " << arv.mediaCaminho(18) << endl;

    cout << "Busca o valor 20: " << arv.busca(20) << endl;
    cout << "Busca o valor  5: " << arv.busca(5) << endl;
    cout << endl;

    cout << "Removendo os valores 24, 6, 7, 12, 18, 5." << endl;
    arv.remove(24);
    arv.remove(6);
    arv.remove(7);
    arv.remove(12);
    arv.remove(18);
    arv.remove(5);
    cout << endl;
    cout <<"ciando arvore vazia"<<endl;
    ArvBinBusca a;
    a.preencheABB(&a, 10,20);
    int impar, filho;
    impar =filho =0;
    a.contaImparesFilhos1(&impar, &filho);
    cout << "Arvore Binaria de Busca final: conta impares filho" <<impar<<" "<<filho<< endl;
    a.imprime();

    return 0;
}


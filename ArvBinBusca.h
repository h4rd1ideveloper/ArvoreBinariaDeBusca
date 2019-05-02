#ifndef ARVBINBUSCA_H_INCLUDED
#define ARVBINBUSCA_H_INCLUDED
#include "NoArv.h"

class ArvBinBusca
{
public:
    ArvBinBusca();
    ~ArvBinBusca();
    bool vazia(); // verifica se a �rvore est� vazia
    bool busca(int val);
    void insere(int val);
    void remove(int val);
    void imprime();
    float mediaCaminho(int ch);
    int maior();
    int menor();
    void removeMaior();
    void removeMenor();
    int contaParesCaminho(int x);
    void preencheABB(ArvBinBusca *a, int p, int q);
    int somaDoNivel(int x);
    void contaImparesFilhos1(int *nI, int *nF);

private:
NoArv* balanceia(NoArv *p);
    NoArv* rotacaoEsquerda(NoArv *arv);
    NoArv* rotacaoDireita(NoArv *arv);
    int fat_bal(NoArv* arv);
    int height(NoArv *h);
    void auxContaImparesFilhos1(NoArv *p, int *nI, int *nF);
    int auxSomaDoNivel(NoArv *p, int x);
    NoArv* maiorSubArvEsq(NoArv *p);
    int auxContaParesCaminhos(NoArv *p, int x);
    void auxRemoveMaior(NoArv *p);
    void auxRemoveMenor(NoArv *p);
    int auxMaior(NoArv *p);
    int auxMenor(NoArv *p);
    NoArv* raiz; // ponteiro para o No raiz da �rvore
    bool auxBusca(NoArv *p, int val);
    NoArv* auxInsere(NoArv *p, int val);
    NoArv* auxRemove(NoArv *p, int val);
    NoArv* menorSubArvDireita(NoArv *p);
    NoArv* removeFolha(NoArv *p);
    NoArv* remove1Filho(NoArv *p);
    void imprimePorNivel(NoArv* p, int nivel);
    NoArv* libera(NoArv *p);
};

#endif // ARVBINBUSCA_H_INCLUDED

#include <iostream>
#include "ArvBinBusca.h"

using namespace std;

ArvBinBusca::ArvBinBusca()
{
    raiz = NULL;
}

bool ArvBinBusca::vazia()
{
    return raiz == NULL;
}

void ArvBinBusca::insere(int val)
{
    raiz = auxInsere(raiz, val);
}

NoArv* ArvBinBusca::auxInsere(NoArv *p, int val)
{
    if(p == NULL)
    {
        p = new NoArv();
        p->setInfo(val);
        p->setEsq(NULL);
        p->setDir(NULL);
    }
    else if(val < p->getInfo())
        p->setEsq(auxInsere(p->getEsq(), val));
    else
        p->setDir(auxInsere(p->getDir(), val));
    return p;
}

bool ArvBinBusca::busca(int val)
{
    return auxBusca(raiz, val);
}

bool ArvBinBusca::auxBusca(NoArv *p, int val)
{
    if(p == NULL)
        return false;
    else if(p->getInfo() == val)
        return true;
    else if(val < p->getInfo())
        return auxBusca(p->getEsq(), val);
    else
        return auxBusca(p->getDir(), val);
}

void ArvBinBusca::remove(int val)
{
    raiz = auxRemove(raiz, val);
}

NoArv* ArvBinBusca::auxRemove(NoArv *p, int val)
{
    if(p == NULL)
        return NULL;
    else if(val < p->getInfo())
        p->setEsq(auxRemove(p->getEsq(), val));
    else if(val > p->getInfo())
        p->setDir(auxRemove(p->getDir(), val));
    else
    {
        if(p->getEsq() == NULL && p->getDir() == NULL)
            p = removeFolha(p);
        else if((p->getEsq() == NULL) || (p->getDir() == NULL))
            p = remove1Filho(p);
        else
        {
            NoArv *aux = menorSubArvDireita(p);
            int tmp = aux->getInfo();
            p->setInfo(tmp);
            aux->setInfo(val);
            p->setDir(auxRemove(p->getDir(), val));
        }
    }
    return p;
}

NoArv* ArvBinBusca::removeFolha(NoArv *p)
{
    delete p;
    return NULL;
}

NoArv* ArvBinBusca::remove1Filho(NoArv *p)
{
    NoArv *aux;
    if(p->getEsq() == NULL)
        aux = p->getDir();
    else
        aux = p->getEsq();
    delete p;
    return aux;
}

NoArv* ArvBinBusca::menorSubArvDireita(NoArv *p)
{
    NoArv *aux = p->getDir();
    while(aux->getEsq() != NULL)
        aux = aux->getEsq();
    return aux;
}

void ArvBinBusca::imprime()
{
    imprimePorNivel(raiz, 0);
}

void ArvBinBusca::imprimePorNivel(NoArv *p, int nivel)
{
    if(p != NULL)
    {
        cout << "(" << nivel << ")";
        for(int i = 1; i <= nivel; i++)
            cout << "--";
        cout << p->getInfo() << endl;
        imprimePorNivel(p->getEsq(), nivel+1);
        imprimePorNivel(p->getDir(), nivel+1);
    }
}

ArvBinBusca::~ArvBinBusca()
{
    raiz = libera(raiz);
}

NoArv* ArvBinBusca::libera(NoArv *p)
{
    if(p != NULL)
    {
        p->setEsq(libera(p->getEsq()));
        p->setDir(libera(p->getDir()));
        delete p;
        p = NULL;
    }
    return p;
}

float ArvBinBusca::mediaCaminho(int ch)
{
    int soma = 0, cont = 0;
    NoArv *p = raiz;
    while(p != NULL)
    {
        cont++;
        soma += p->getInfo();
        if(ch == p->getInfo())
            break;
        else if(ch > p->getInfo())
            p = p->getDir();
        else
            p = p->getEsq();
    }
    return (float)soma/cont;
}
//Maior
int ArvBinBusca :: maior()
{
    return auxMaior(raiz);
}
int ArvBinBusca::auxMaior(NoArv *p)
{
    return ((p!=NULL)&&(p->getDir()==NULL))?p->getInfo():auxMaior(p->getDir());
}
//Menor
int ArvBinBusca :: menor()
{
    return auxMenor(raiz);
}
int ArvBinBusca::auxMenor(NoArv *p)
{
    return ((p!=NULL)&&(p->getEsq()==NULL))?p->getInfo():auxMenor(p->getEsq());
}
//Remove Maior
void ArvBinBusca::removeMaior()
{
    return auxRemoveMaior(raiz);
}
void ArvBinBusca::auxRemoveMaior(NoArv *p)
{

    if(p!=NULL)
    {
        if(p->getDir()==NULL)
        {
            raiz = auxRemove(raiz, p->getInfo());

        }
        else
        {
            auxRemoveMaior(p->getDir());
        }
    }

}
//Remove Menor
void ArvBinBusca::removeMenor()
{
    return auxRemoveMenor(raiz);
}
void ArvBinBusca::auxRemoveMenor(NoArv *p)
{

    raiz = auxRemove(raiz, menor());

}
int ArvBinBusca::contaParesCaminho(int x)
{
    return auxContaParesCaminhos(raiz, x);
}
int ArvBinBusca::auxContaParesCaminhos(NoArv *p, int x)
{

    if(p&&p->getInfo()!=x)
    {

        if(p->getInfo()%2==0)
        {

            return (p->getInfo()<x)?1+auxContaParesCaminhos(p->getDir(), x):1+auxContaParesCaminhos(p->getEsq(), x);

        }
        else
        {
            return (p->getInfo()>x)?auxContaParesCaminhos(p->getEsq(), x):auxContaParesCaminhos(p->getDir(), x);
        }

    }
    else if (p->getInfo()==x)
    {
        return 0;
    }
    return 0;
}
NoArv* ArvBinBusca::maiorSubArvEsq(NoArv *p)
{
    NoArv *aux = p->getEsq();
    while(aux->getDir() != NULL)
        aux = aux->getDir();
    return aux;
}

void ArvBinBusca::preencheABB(ArvBinBusca *a, int p, int q)
{
    if (a->vazia())
    {
        int m = (p+q)/2;
        int maxPQ = (p>q)?p:q;
        int minPQ = (p<q)?p:q;
        insere(m);
        preencheABB(a, minPQ, maxPQ);
    }
    else if (p<=q)
    {
        if (p!=raiz->getInfo())
        {
            insere(p);
        }
        preencheABB(a, p+1, q);
    }
}

void ArvBinBusca::contaImparesFilhos1(int *nI, int *nF)
{

    cout<<*nI<<"< test >"<<*nF<<endl;
    return auxContaImparesFilhos1(raiz,nI,nF);

}
void ArvBinBusca::auxContaImparesFilhos1(NoArv *p, int *nI, int *nF)
{
    if (p)
    {
        if(p->getInfo()%2)
        {
            *nI+=1;
        }
        if(p->getEsq()==NULL||p->getDir()==NULL)
        {
            *nF+=1;
        }
        auxContaImparesFilhos1(p->getEsq(), nI, nF);
        auxContaImparesFilhos1(p->getDir(), nI, nF);
    }
}

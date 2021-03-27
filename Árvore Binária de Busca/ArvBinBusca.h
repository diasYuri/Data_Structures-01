#ifndef ARVBINBUSCA_H_INCLUDED
#define ARVBINBUSCA_H_INCLUDED
#include "NoArv.h"

class ArvBinBusca
{
public:
    ArvBinBusca();
    ~ArvBinBusca();
    bool vazia(); // verifica se a árvore está vazia
    bool busca(int val);
    void insere(int val);
    void remove(int val);
    void imprime();
    float mediaCaminho(int ch);
    void nivel(int val);
    void altura();
    void impValMaiores(int val){auxImpValMaiores(raiz, val);};
    bool EhABB();
    int maior ();
    int menor ();
    int* vetIntervalo(int a, int b, int k);
    void removeMaior ();
    void removeMenor ();
    void mediaNivel(int nivel);
    void insNaoRec (int val);

    int contaParesCaminho(int x);
    void vetor(int k, int *vet, int tam);

    void insereFilhoDireita(int val);


private:
    NoArv* raiz; // ponteiro para o No raiz da árvore
    bool auxBusca(NoArv *p, int val);
    NoArv* auxInsere(NoArv *p, int val);
    NoArv* auxRemove(NoArv *p, int val);
    NoArv* menorSubArvDireita(NoArv *p);
    NoArv* maiorSubArvEsquerda(NoArv *p);
    NoArv* removeFolha(NoArv *p);
    NoArv* remove1Filho(NoArv *p);
    NoArv* libera(NoArv *p);
    NoArv* auxRemoveMenor (NoArv*p);

    void auxContaParesCaminho(NoArv *p, int x, int *cont);
    void imprimePorNivel(NoArv* p, int nivel);
    void auxImpValMaiores(NoArv *p, int val);
    void auxMediaNivel(NoArv *p, int nivel, int *soma, int *n);
    void auxVetIntervalo (NoArv* p, int a, int b, int k, int* vet, int* idx);
    void auxVetor(NoArv *p, int *vet, int k, int* cont1, int* cont2);

    int BuscaPorNivel(NoArv *p, int nivel, int val);
    int buscaMenor(NoArv *p);
    int auxAltura(NoArv *p, int nivel);

    bool auxEhABB(NoArv *p, int *ultimo);//ultimo: valor do último nó visitado
};

#endif // ARVBINBUSCA_H_INCLUDED

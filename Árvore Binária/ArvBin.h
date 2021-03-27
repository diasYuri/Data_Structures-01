#ifndef ARVBIN_H_INCLUDED
#define ARVBIN_H_INCLUDED
#include "NoArv.h"

class ArvBin
{
  public:
    ArvBin();
    ~ArvBin();

    int getRaiz();
    void cria(int x, ArvBin *sae, ArvBin *sad);
    void anulaRaiz();
    bool vazia(); // verifica se a árvore está vazia
    bool busca(int x);
    void preOrdem();
    void montaArvore();
    void insere(int x);
    int nNos();
    int nFolhas();
    int altura();
    void imprimeNivel(int k);
    bool verificaCheia();
    void deletaFolhas();
    int contaNos ();
    int contaImpar();
    void contaElegante();

  private:
    NoArv *raiz; // ponteiro para o No raiz da árvore

    NoArv* libera(NoArv *p);
    bool auxBusca(NoArv *p, int x);
    void auxPreOrdem(NoArv *p);
    NoArv* auxMontaArvore();
    void auxImpNivel(NoArv *p, int atual, int k);
    void auxInverte(NoArv * p);
    int auxnNos(NoArv *p);
    int auxnFolhas(NoArv *p);
    NoArv* auxInsere(NoArv *p, int x);
    bool ehFolha(NoArv *p);
    int auxAltura(NoArv *p);
    void auxImprimeNivel(NoArv *p, int atual, int k);
    void auxDeletaFolhas(NoArv *p);
    void auxNumNos (NoArv *p, int *cont);
    int auxVerificaCheia(NoArv *p, int *n);
    int auxContaImpar(NoArv *p);
    void auxContaElegante(NoArv *p, int *n2, int *m5);
};

#endif // ARVBIN_H_INCLUDED

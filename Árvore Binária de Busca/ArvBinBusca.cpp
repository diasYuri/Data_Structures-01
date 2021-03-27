#include <iostream>
#include "ArvBinBusca.h"
#include <math.h>

using namespace std;

ArvBinBusca::ArvBinBusca()
{
    raiz = NULL;
}

ArvBinBusca::~ArvBinBusca()
{
    raiz = libera(raiz);
}


bool ArvBinBusca::EhABB()
//ESTA OPERAÇÃO NÃO FOI TESTADA, FOI FEITA RAPIDAMENTE (CUIDADO)
{
    NoArv *p = raiz;
    while(p->getEsq() != NULL)
        p = p->getEsq();
    int menorValor = p->getInfo();

    return auxEhABB(raiz, &menorValor);
}

//verifica se uma AB é ABB
bool ArvBinBusca::auxEhABB(NoArv *p, int *ultimo)
//ESTA OPERAÇÃO NÃO FOI TESTADA, FOI FEITA RAPIDAMENTE (CUIDADO)
{
    //faz um percurso em ordem na ABB.

    if(p == NULL)
        return true;
    else
        {
            bool abb_sae = auxEhABB(p->getEsq(), ultimo);

            if(!abb_sae)
                return false;

            if(*ultimo > p->getInfo())
                return false;

            *ultimo = p->getInfo();

            return auxEhABB(p->getDir(), ultimo);
        }
}

void ArvBinBusca::auxImpValMaiores(NoArv *p, int val)
//imprime todos os nós com valores >= val. Visita o mínimo de nós
{
    if(p != NULL)
        {
            if(p->getInfo()>=val)
                {
                    cout<<p->getInfo()<<"   ";
                    auxImpValMaiores(p->getEsq(), val);
                    auxImpValMaiores(p->getDir(), val);
                }
            else
                {
                    auxImpValMaiores(p->getDir(), val);
                }

        }
}

int ArvBinBusca::buscaMenor(NoArv *p)
{
    int menor;
    for(p; p!=NULL; p = p->getEsq())
        menor = p->getInfo();
    return menor;
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
                    //objetivo tranformar o nó com dois filhos em uma raiz ou em um nó com um filho
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



// retorna substituto para raiz em que ele foi chamado
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


void ArvBinBusca::nivel(int val)
{
    int n = BuscaPorNivel(raiz, 0, val);
    cout<<"Nivel de "<<val<<": "<<n<<endl;
}

int ArvBinBusca::BuscaPorNivel(NoArv *p, int nivel, int val)
{
    int n;
    if(p == NULL)
        return -1;
    else
        {
            if(p->getInfo() == val)
                return nivel;
            else if(p->getInfo() > val)
                n = BuscaPorNivel(p->getEsq(), nivel+1, val);
            else if(p->getInfo() < val)
                n = BuscaPorNivel(p->getDir(), nivel+1, val);
        }

    return n;
}

void ArvBinBusca::altura()
{
    int altura = auxAltura(raiz, 0);
    cout<<"Altura: "<<altura<<endl;
}

int ArvBinBusca::auxAltura(NoArv *p, int nivel)
{
    if(p == NULL)
        return nivel-1;
    else
        {
            int ne = auxAltura(p->getEsq(), nivel+1);
            int nd = auxAltura(p->getDir(), nivel+1);

            if(ne>nd)
                return ne;
            else
                return nd;
        }


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


NoArv* ArvBinBusca::maiorSubArvEsquerda(NoArv *p)
{
    NoArv *aux = p->getEsq();
    while(aux->getDir() != NULL)
        aux = aux->getDir();
    return aux;
}


int ArvBinBusca::maior ()
{
    if (raiz == NULL)
        {
            cout << "Arvore vazia" << endl;
            return -1;
        }

    NoArv *p = raiz;
    while (p->getDir () != NULL)
        p = p->getDir ();
    return p->getInfo ();
}

int ArvBinBusca::menor ()
{
    if (raiz != NULL)
        {
            NoArv *p;
            for (p = raiz; p->getEsq () != NULL; p = p->getEsq ());
            return p->getInfo();
        }
    else
        {
            cout << "Arvore vazia" << endl;
            return -1;
        }
}

void ArvBinBusca::removeMaior ()
{
    remove (maior ());
}

void ArvBinBusca::removeMenor ()
{
    raiz = auxRemoveMenor (raiz);
}

NoArv* ArvBinBusca::auxRemoveMenor (NoArv*p)
{
    if (p == NULL)
        return NULL;

    else if (p->getEsq () != NULL)
        {
            NoArv *filho = auxRemoveMenor (p->getEsq());
            p->setEsq (filho);
        }

    else // Encontrei o menor elemento!
        {
            // Tem filho pra direita?
            if (p->getDir () != NULL)
                p = remove1Filho (p);
            else
                p = removeFolha (p);
        }
    return p;
}


int ArvBinBusca::contaParesCaminho(int x)
{
    int contador = 0;
    auxContaParesCaminho (raiz, x, &contador);
    return contador;
}

void ArvBinBusca::auxContaParesCaminho(NoArv *p, int x, int *cont)
{
    if (p == NULL)
        return;
    else
        {
            if (p->getInfo () % 2 == 0)
                *cont = *cont + 1;

            if (p->getInfo () == x)
                return;
            else if (x < p->getInfo ())
                auxContaParesCaminho (p->getEsq (), x, cont);
            else
                auxContaParesCaminho (p->getDir (), x, cont);
        }
}


void ArvBinBusca::mediaNivel(int nivel)
{
    int soma = 0;
    int n = 0;

    auxMediaNivel(raiz, nivel, &soma, &n);


    cout<<"Media do nivel "<<nivel<<": "<<float(soma/n)<<endl;

}


void ArvBinBusca::auxMediaNivel(NoArv *p, int nivel, int *soma, int *n)
{
    if( p != NULL && nivel >= 0)
        {

            if(nivel == 0)
                {
                    *soma = *soma + p->getInfo();
                    *n = *n + 1;
                }

            auxMediaNivel(p->getEsq(), nivel-1, soma, n);
            auxMediaNivel(p->getDir(), nivel-1, soma, n);
        }
}


int* ArvBinBusca::vetIntervalo (int a, int b, int k)
{
    // Criar vetor
    int tam = pow(2,k) + 1;
    int *vetOrdenado = new int [tam];
    int idx = 0;

    auxVetIntervalo (raiz, a, b, k, vetOrdenado, &idx);

    for (int i = idx; i < tam; i++)
        vetOrdenado[i] = -1;

    return vetOrdenado;
}

void ArvBinBusca::auxVetIntervalo (NoArv* p, int a, int b, int k, int* vet, int* idx)
{
    if (p != NULL && k >= 0)
        {
            // Esquerda
            if (a < p->getInfo ())
                auxVetIntervalo (p->getEsq (), a, b, k-1, vet, idx);



            // Elemento p
            int info = p->getInfo ();
            if (k == 0 && info >= a && info <= b)
                {
                    // Inserir o numero no vetor
                    vet[*idx] = info;
                    *idx = *idx + 1;
                }

            // Direita
            if (b >= p->getInfo ())
                auxVetIntervalo (p->getDir (), a, b, k-1, vet, idx);
        }
}


void ArvBinBusca::insNaoRec (int val)
{
    // Criando o novo nó
    NoArv *novo = new NoArv ();
    novo->setEsq (NULL);
    novo->setDir (NULL);
    novo->setInfo (val);

    if (raiz == NULL)
        raiz = novo;
    else
        {
            NoArv *p = raiz;
            NoArv *pai = NULL;

            while (p != NULL)
                {
                    if (p->getInfo () == val)
                        {
                            delete novo;
                            cout << "este valor já existe na arvore" << endl;
                            return;
                        }

                    pai = p;
                    if (val < p->getInfo ())
                        p = p->getEsq ();
                    else
                        p = p->getDir ();
                }

            // Achei o lugar da inserção
            if (val < pai->getInfo ())
                // Insere esquerda
                pai->setEsq (novo);
            else
                // Insere direita
                pai->setDir (novo);
        }
}






void ArvBinBusca::vetor(int k, int *vet, int tam)
{
    int cont1 = 0;
    int cont2 = tam-1;

    for(int i=0; i<tam; i++)
        vet[i] = -1;


    auxVetor(raiz, vet, k, &cont1, &cont2);

}

void ArvBinBusca::auxVetor(NoArv *p, int *vet, int k, int* cont1, int* cont2)
{
    if(p != NULL && k >= 0)
        {

            auxVetor(p->getDir(), vet, k-1, cont1, cont2);


            if(k == 0)
                {
                    vet[*cont1] = p->getInfo();
                    *cont1 = *cont1 + 1;
                }
            else
                {
                    vet[*cont2] = p->getInfo();
                    *cont2 = *cont2 - 1;
                }


            auxVetor(p->getEsq(), vet, k-1, cont1, cont2);

        }


}





void ArvBinBusca::insereFilhoDireita(int val)
{
    int i = 0;
    NoArv *novo = new NoArv ();
    novo->setEsq (NULL);
    novo->setDir (NULL);
    novo->setInfo (val);

    NoArv *p = raiz;

    while (p != NULL)
    {
        if (p->getInfo () == val)
        {
            if(p->getDir() == NULL)
            {
                p->setDir(novo);
                return;
            }
            else
                i++;
        }


        if (val < p->getInfo ())
            p = p->getEsq ();
        else
            p = p->getDir ();
    }

    delete novo;
    if(i==0)
        cout<<"ERROR: Nao existe no com val="<<val<<endl;
    else
        cout<<"ERROR: Todos os nos com val="<<val<<" ja possuem filho(s) a direita"<<endl;

}


void ArvBinBusca::removeDireita(int val)
{
    NoArv *pai = NULL;
    NoArv *p = raiz;

    while (p != NULL)
    {
        if (p->getInfo () == val)
        {
            if(p->getEsq() == NULL)
            {
                if(p->getDir() != NULL)
                {
                    pai->setDir(p->getDir())
                    delete p;
                    return;
                }
                else
                {
                    delete p;
                    return;
                }
            }
            else
            {
                cout<<"Error: no possui filho a esquerda"<<endl;
                return;
            }

        }

        pai = p;
        if (val < p->getInfo ())
            p = p->getEsq ();
        else
            p = p->getDir ();
    }

    cout<<"Error: nao possui no com esse val"<<endl;
}


void ArvBinBusca::removeFilhoEsquerda(int val)
{
    NoArv *menor = NULL;
    NoArv *p = raiz;
    int m = raiz->getInfo();

    while (p != NULL)
    {
        if (p->getInfo() < m)
        {
            m = p->getInfo();
            menor = p;
        }

        if (val < p->getInfo ())
            p = p->getEsq ();
        else
            p = p->getDir ();
    }

    if(menor->getEsq() != NULL && menor->getEsq()->getDir == NULL)
    {
        p = menor->getEsq();
        delete p;
    }
}














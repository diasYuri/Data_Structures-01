#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <math.h>
#include "ArvBin.h"

using namespace std;

ArvBin::ArvBin()
{
    raiz = NULL;
}

int ArvBin::getRaiz()
{
    if (raiz != NULL)
        return raiz->getInfo();
    else
        {
            cout << "Árvore vazia!" << endl;
            exit(1);
        }
}

void ArvBin::cria(int x, ArvBin *sae, ArvBin *sad)
{
    NoArv *p = new NoArv();
    p->setInfo(x);
    p->setEsq(sae->raiz);
    p->setDir(sad->raiz);
    raiz = p;
}

void ArvBin::anulaRaiz()
{
    raiz = NULL;
}

bool ArvBin::vazia()
{
    return (raiz == NULL);
}


////////////////// MONTA ARVORE //////////////////////
void ArvBin::montaArvore()
{
    if(!vazia())
        cout << "Arvore ja montada. So e possivel a insercao de nos." << endl;
    else
        {
            cout << "Montagem da arvore em pre-ordem:" << endl;
            raiz = auxMontaArvore();
        }
}

NoArv* ArvBin::auxMontaArvore()
{
    string linha;
    cout << "Valor: ";
    cin >> linha;
    if(linha != "NULL" && linha != "null")
        {
            istringstream ent(linha);
            int valor;
            ent >> valor;
            NoArv *p = new NoArv();
            p->setInfo(valor);
            cout << "Esquerda" << endl;
            p->setEsq(auxMontaArvore());
            cout << "Volta no noh " << p->getInfo() << endl;
            cout << "Direita" << endl;
            p->setDir(auxMontaArvore());
            cout << "Volta no noh " << p->getInfo() << endl;
            return p;
        }
    else
        return NULL;
}
/////////////////////////////////////////////////////


////////////////// INSERE //////////////////////
void ArvBin::insere(int x)
{
    raiz = auxInsere(raiz, x);
}

NoArv* ArvBin::auxInsere(NoArv *p, int x)
{
    if(p == NULL)
        {
            p = new NoArv();
            p->setInfo(x);
            p->setEsq(NULL);
            p->setDir(NULL);
        }
    else
        {
            char direcao;
            cout << x << " a esquerda (e) ou direita (d) de " << p->getInfo() << ": ";
            cin >> direcao;
            if(direcao == 'e' || direcao == 'E')
                p->setEsq(auxInsere(p->getEsq(), x));
            else
                p->setDir(auxInsere(p->getDir(), x));
        }
    return p;
}
//////////////////////////////////////////////


//////////////// BUSCA ///////////////////////
bool ArvBin::busca(int x)
{
    return auxBusca(raiz, x);
}

bool ArvBin::auxBusca(NoArv *p, int x)
{
    if (p == NULL)
        return false;
    else if (p->getInfo() == x)
        return true;
    else if (auxBusca(p->getEsq(), x))
        return true;
    else
        return auxBusca(p->getDir(), x);
}
///////////////////////////////////////////////


////////////////// DESTRUTOR //////////////////////
ArvBin::~ArvBin()
{
    raiz = libera(raiz);
}

NoArv* ArvBin::libera(NoArv *p)
{
    if (p != NULL)
        {
            p->setEsq(libera(p->getEsq()));
            p->setDir(libera(p->getDir()));
            delete p;
            p = NULL;
        }
    return NULL;
}
//////////////////////////////////////////////////


////////// IMPRIME PRE-ORDEM //////////////
void ArvBin::preOrdem()
{
    cout << "Arvore Binaria em Pre-Ordem: ";
    auxPreOrdem(raiz);
    cout<<endl;
}

void ArvBin::auxPreOrdem(NoArv *p)
{
    if (p != NULL)
        {
            cout << p->getInfo() << " ";
            auxPreOrdem(p->getEsq());
            auxPreOrdem(p->getDir());

        }
}
////////////////////////////////////////////


int ArvBin::nNos()
{
    return auxnNos(raiz);
}

int ArvBin::auxnNos(NoArv *p)
{
    if(p == NULL)
        return 0;
    else
        {
            int ne = auxnNos(p->getEsq());
            int nd = auxnNos(p->getDir());
            return 1 + ne + nd;
        }
}


////////////////////////// FOLHAS ////////////////////////////////
/*bool ArvBin::ehFolha(NoArv *p)
{
    if(p != NULL)
        {
            if(p->getDir() == NULL && p->getEsq() == NULL)
                return true;
            else
                return false;
        }
}*/

int ArvBin::nFolhas()
{
    return auxnFolhas(raiz);
}

int ArvBin::auxnFolhas(NoArv *p)
{
    if(p == NULL)
        return 0;
    else if(ehFolha(p))
        return 1;
    else
        return auxnFolhas(p->getEsq()) + auxnFolhas(p->getEsq());
}
//////////////////////////////////////////////////////////////////


//////////////////////// ALTURA //////////////////////////////////
int ArvBin::altura()
{
    return auxAltura(raiz);
}

int ArvBin::auxAltura(NoArv *p)
{
    if(p == NULL)
        return -1;
    else
        {
            int he = auxAltura(p->getEsq());

            int hd = auxAltura(p->getDir());

            if(he>hd)
                return he+1;
            else
                return hd+1;
        }
}
/////////////////////////////////////////////////////////////////


///////////////////// NIVEL /////////////////////////////////
void ArvBin::imprimeNivel(int k)
{
    auxImprimeNivel(raiz, 0, k);
    cout << endl;
}

void ArvBin::auxImprimeNivel(NoArv *p, int atual, int k)
{
    if(p != NULL)
        {
            if(atual == k)
                cout << p->getInfo() << " ";
            else
                {
                    auxImprimeNivel(p->getEsq(), atual+1, k);
                    auxImprimeNivel(p->getDir(), atual+1, k);
                }
        }
}
/////////////////////////////////////////////////////////


//////////////////// CHEIA ///////////////////////
bool ArvBin::verificaCheia()
{
    int h;
    int nos = 0;

    h = auxVerificaCheia(raiz, &nos);

    if(nos == (pow(2, h+1))-1)
        return true;
    else
        return false;
}

int ArvBin::auxVerificaCheia(NoArv *p, int *n)
{
    if(p == NULL)
        return -1;
    else
    {
        *n = *n + 1;

        int he = auxVerificaCheia(p->getEsq (), n);
        int hd = auxVerificaCheia(p->getDir (), n);

        if(he>hd)
            return he+1;
        else
            return hd+1;
    }
}
/////////////////////////////////////////////////


void ArvBin::deletaFolhas()
{
    return auxDeletaFolhas(raiz);
}

void ArvBin::auxDeletaFolhas(NoArv *p)
{
    if(p != NULL)
        {
            if(ehFolha(p->getEsq()))
                {
                    NoArv *aux = p->getEsq();
                    p->setEsq(NULL);
                    delete aux;
                }
            if(ehFolha(p->getDir()))
                {
                    NoArv *aux = p->getDir();
                    p->setDir(NULL);
                    delete aux;
                }

            auxDeletaFolhas(p->getEsq());
            auxDeletaFolhas(p->getDir());
        }
}



/////////////////// OPÇÃO CONTA NÓS ////////////////////
int ArvBin::contaNos ()
{
    int contador = 0;
    auxNumNos (raiz, &contador);
    return contador;
}

void ArvBin::auxNumNos (NoArv *p, int *cont)
{
    if(p != NULL)
    {
        *cont = *cont + 1;
        auxNumNos(p->getEsq (), cont);
        auxNumNos(p->getDir (), cont);



    }
}
////////////////////////////////////////////////////



int ArvBin::contaImpar()
{
    auxContaImpar(raiz);
}

int ArvBin::auxContaImpar(NoArv *p)
{
    if(p == NULL)
        return 0;
    else
    {
        int aux;

        if(p->getInfo() % 2 != 0)
                aux=1;
        else
                aux=0;

        int impar = aux + auxContaImpar(p->getEsq()) + auxContaImpar(p->getDir());

        return impar;
    }

}

///////////////////////////////////////////////////////////////////


bool ArvBin::ehFolha(NoArv *p)
{
    if(p != NULL)
        {
            if(p->getDir() == NULL && p->getEsq() == NULL)
                return true;
            else
                return false;
        }
}

/*void ArvBin::contaElegante()
{
    int n2f = 0;
    int m5 = 0;

    auxContaElegante(raiz, &n2f, &m5);


    cout<<"Resultado: "<<endl;
    cout<<"Nos que possuem 2 filhos: "<<n2f<<endl;
    cout<<"Folhas com valor multiplo de 5: "<<m5<<endl;

}

void ArvBin::auxContaElegante(NoArv *p, int *n2, int *m5)
{
    if(p != NULL)
    {
        if(ehFolha(p) && p->getInfo() % 5 == 0)
            *m5 = *m5 + 1;

        if(p->getEsq() != NULL && p->getDir() != NULL)
            *n2 = *n2 + 1;


        auxContaElegante(p->getEsq(), n2, m5);
        auxContaElegante(p->getDir(), n2, m5);
    }
}*/



void ArvBin::contaElegante()
{
    int cont = 0;
    int soma = 0;
    auxContaElegante(raiz, &cont, &soma);
    cout << cont << endl;
    cout << soma << endl;
}

void ArvBin::auxContaElegante(NoArv *p, int *cont, int *soma)
{
    if(p != NULL)
    {
        if((p->getEsq() == NULL && p->getDir() == NULL) && p->getInfo() % 2 == 0)
            *cont = *cont +1;

        if(!(p->getEsq() == NULL && p->getDir() == NULL))
            *soma = *soma + p->getInfo();

        auxContaElegante(p->getEsq (), cont, soma);
        auxContaElegante(p->getDir (), cont, soma);

    }
}



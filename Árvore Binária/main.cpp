#include <iostream>
#include "ArvBin.h"
using namespace std;

int main()
{
    ArvBin vazia, arv;
    ArvBin a1, a2, a3;

    a1.cria(20, &vazia, &vazia);
    a2.cria(2, &vazia, &vazia);
    a3.cria(8, &a2, &a1);
    a1.cria(9, &vazia, &vazia);
    a2.cria(6, &vazia, &vazia);
    a1.cria(7, &a2, &a1);
    arv.cria(15, &a1, &a3);
    a1.anulaRaiz();
    a2.anulaRaiz();
    a3.anulaRaiz();

    /*arv.insere(25);
    arv.insere(20);
    arv.insere(10);
*/
    arv.preOrdem();
    arv.contaElegante();

    //cout<<"impar: "<<arv.contaImpar()<<endl;

    /*arv.imprimeNivel(2);
    arv.deletaFolhas();
    arv.preOrdem();
    arv.nNos();*/



    /*ArvBin arv;
    arv.montaArvore();
    arv.insere(15);
    arv.insere(25);
    arv.insere(10);
    arv.preOrdem();*/

    return 0;
}

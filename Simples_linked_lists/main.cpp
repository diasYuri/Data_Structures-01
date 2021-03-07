#include <iostream>
#include "ListaEncad.h"

using namespace std;

int main()
{
    ListaEncad l;
    l.insereFinal(12);
    l.insereInicio(13);
    l.insereFinal(5);
    l.insereInicio(-6);
    l.imprime();
    cout << "Nos: " << l.contaNos2() << endl;

    l.insereK(10, 5);
    l.imprime();


    l.removeK(2);
    l.imprime();
    cout << "Nos: " << l.contaNos2() << endl;
    l.removeInicio();
    l.imprime();
    cout << "Nos: " << l.contaNos2() << endl;
    l.removeFinal();
    l.imprime();
    cout << "Nos: " << l.contaNos2() << endl;
    l.removeInicio();
    l.imprime();
    cout << "Nos: " << l.contaNos2() << endl;
    l.removeFinal();
    return 0;
}

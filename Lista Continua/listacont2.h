#ifndef LISTACONT2_H
#define LISTACONT2_H


class ListaCont2
{
    private:
        int max;
        int n;
        int inicio;
        int *vet;

    public:
        ListaCont2(int tam, int init);
        ~ListaCont2();

        int get(int k);
        void set(int k, int val);
        void insereFinal(int val);
        void insereK(int k, int val);
        void insereInicio(int val);
        void removeFinal();
        void removeK(int k);
        void removeInicio();
        void imprime();
        void insereAntesInicio(int val);
};

#endif // LISTACONT2_H

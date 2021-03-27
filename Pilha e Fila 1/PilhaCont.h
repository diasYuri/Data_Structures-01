#ifndef PILHACONT_H_INCLUDED
#define PILHACONT_H_INCLUDED

class PilhaCont
{
private:
    int max; // capacidade maxima
    int topo; // posicao do topo da pilha
    int *vet; // vetor que armazena os dados da pilha
public:
    PilhaCont(int tam);
    ~PilhaCont();
    int getTopo(); // valor do No no Topo
    void empilha(int val);// insere No no Topo
    int desempilha(); // elimina No do Topo
    bool vazia();
    void imprime();
};

#endif // PILHACONT_H_INCLUDED

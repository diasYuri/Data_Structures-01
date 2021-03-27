#ifndef MATRIXANTISIMETRICA_H
#define MATRIXANTISIMETRICA_H


class MatrixAntiSimetrica
{
    public:
        MatrixAntiSimetrica(int ordem);
        ~MatrixAntiSimetrica();

    void set(int l, int j, float value);
        float get(int l, int j);

    private:
        int n;
        int i;

        float *mat;

        int DefineIndex(int l, int j);
        bool verifyIndex(int l, int j);
};

#endif // MATRIXANTISIMETRICA_H

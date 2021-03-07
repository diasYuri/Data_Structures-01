#ifndef MATRIXSIMETRICA_H
#define MATRIXSIMETRICA_H


class MatrixSimetrica
{
    public:
        MatrixSimetrica(int ordem);
        ~MatrixSimetrica();

        void set(int l, int j, float value);
        float get(int l, int j);

    private:
        int n;
        int i;

        float *mat;

        int DefineIndex(int l, int j);
        bool verifyIndex(int l, int j);
};

#endif // MATRIXSIMETRICA_H

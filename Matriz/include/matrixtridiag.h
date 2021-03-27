#ifndef MATRIXTRIDIAG_H
#define MATRIXTRIDIAG_H


class MatrixTriDiag
{
    public:
        MatrixTriDiag(int ordem);
        ~MatrixTriDiag();

        void set(int l, int j, float value);
        float get(int l, int j);

    private:
        int n;
        int i;

        float *mat;

        int DefineIndex(int l, int j);
        bool verifyIndex(int l, int j);
        bool verifyDiag(int l, int j);
};

#endif // MATRIXTRIDIAG_H

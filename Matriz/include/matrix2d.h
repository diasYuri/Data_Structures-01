#ifndef MATRIX2D_H
#define MATRIX2D_H


class Matrix2D
{
    public:
        Matrix2D(int l, int j);
        ~Matrix2D();

        float get(int l, int j);
        void set(int l, int j, float valor);

    private:
        float **matrix;
        int nl, nc;


        bool verifyIndex(int l, int j);
};

#endif // MATRIX2D_H

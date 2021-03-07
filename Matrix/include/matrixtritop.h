#ifndef MATRIXTRITOP_H
#define MATRIXTRITOP_H


class MatrixTriTop
{
    public:
        MatrixTriTop(int ordem);
        ~MatrixTriTop();

        void set(int l, int j, float value);
        float get(int l, int j);

    private:
        int n;
        int i;

        float *mat;

        int DefineIndex(int l, int j);
        bool verifyIndex(int l, int j);
};

#endif // MATRIXTRITOP_H

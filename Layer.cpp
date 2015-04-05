#include "Layer.h"

Layer::Layer(int in_size, int out_size)
{
    insize = in_size;
    outsize = out_size;
    w = MatrixXd::Random(outsize, insize);
    b = VectorXd::Random(outsize);
}

VectorXd Layer::calculate(VectorXd in)
{
    assert(in.rows() == insize);
    VectorXd out = w * in;
    out = out + b;
    return out;
}

MatrixXd Layer::getMatrix()
{
    return w;
}

void Layer::setMatrix(MatrixXd m)
{
    assert(w.rows() == m.rows());
    assert(w.cols() == m.cols());
    w = m;
}

VectorXd Layer::getOffset()
{
    return b;
}

void Layer::setOffset(VectorXd v)
{
    assert(b.rows() == v.rows());
    b = v;
}

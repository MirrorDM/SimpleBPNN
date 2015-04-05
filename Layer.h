#include <Eigen/Dense>
#include "misc.h"

using namespace Eigen;

class Layer
{
    int insize, outsize;
    MatrixXd w;
    VectorXd b;
public:
    Layer(int in_size, int out_size);
    VectorXd calculate(VectorXd in);
    MatrixXd getMatrix();
    void setMatrix(MatrixXd m);
    VectorXd getOffset();
    void setOffset(VectorXd v);
};

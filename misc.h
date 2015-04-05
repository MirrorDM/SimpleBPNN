#include <cmath>
#include <Eigen/Dense>

using namespace Eigen;

double sigmoid(double z);
VectorXd sigmoid(VectorXd v);

double d_sigmoid(double z);
VectorXd d_sigmoid(VectorXd v);
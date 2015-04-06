#include <Eigen/Dense>
#include <cmath>

using namespace Eigen;

class Trainset
{
    int inputsize, outputsize, n;
    VectorXd *vi, *vo, *myans;
    VectorXd calculateOutput(VectorXd input);
public:
    Trainset(int in_size, int out_size, int num);
    VectorXd getInput(int i);
    VectorXd getOutput(int i);
    void setMyAns(VectorXd v, int i);
    VectorXd getMyAns(int i);
    double calculatePrecision();
    int getSize();
};

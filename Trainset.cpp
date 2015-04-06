#include "Trainset.h"

VectorXd Trainset::calculateOutput(VectorXd input)
{
    VectorXd output(outputsize);
    double ans = 0;
    if ((input[0] * input[0]) + (input[1] * input[1]) > 0.64)
    //if ( (fabs(input[0]) + fabs(input[1])) > 1)
    {
        ans = 1;
    }
    output[0] = ans;
    return output;
}

Trainset::Trainset(int in_size, int out_size, int num)
{
    inputsize = in_size;
    outputsize = out_size;
    n = num;
    vi = new VectorXd[n];
    vo = new VectorXd[n];
    myans = new VectorXd[n];
    for (int i = 0; i < n; i++)
    {
        vi[i] = VectorXd::Random(inputsize);
        vo[i] = calculateOutput(vi[i]);
    }
}

VectorXd Trainset::getInput(int i)
{
    assert(i < n);
    return vi[i];
}

VectorXd Trainset::getOutput(int i)
{
    assert(i < n);
    return vo[i];
}

void Trainset::setMyAns(VectorXd v, int i)
{
    assert(v.rows() == outputsize);
    assert(i < n);
    myans[i] = v;
}

VectorXd Trainset::getMyAns(int i)
{
    assert(i < n);
    return myans[i];
}
double Trainset::calculatePrecision()
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int myans_i = 0;
        if (myans[i][0] >= 0.5)
            myans_i = 1;
        if (myans_i == vo[i][0])
            count += 1;
    }
    return (double)count / n;
}

int Trainset::getSize()
{
    return n;
}
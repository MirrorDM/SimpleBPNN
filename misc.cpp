#include "misc.h"

double sigmoid(double z)
{
    return 1.0 / (1.0 + exp(-z));
}

double d_sigmoid(double z)
{
	double sig_z = sigmoid(z);
	return (1 - sig_z) * sig_z;
}

VectorXd sigmoid(VectorXd v)
{
	VectorXd out = v;
	for (int i = 0; i < out.rows(); i++)
	{
		out[i] = sigmoid(out[i]);
	}
	return out;
}

VectorXd d_sigmoid(VectorXd v)
{
	VectorXd out = v;
	for (int i = 0; i < out.rows(); i++)
	{
		out[i] = d_sigmoid(out[i]);
	}
	return out;
}
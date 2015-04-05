#include <iostream>
#include <Eigen/Dense>
#include <cstdlib>
#include "Layer.h"
#include "Trainset.h"
#include "misc.h"

#define PRINT(x) (cout<< #x << " = " << endl << x << endl)

using namespace Eigen;
using namespace std;

const int inputs = 2;
const int hidden = 10;
const int outputs = 1;

int main()
{

    Layer w1(inputs,hidden);
    Layer w2(hidden, outputs);

    VectorXd x(inputs);
    VectorXd y(hidden), dy(hidden), theta1(hidden);
    VectorXd z(outputs), dz(outputs), theta2(outputs), ans(outputs);

    Trainset train(2, 1, 200000);
    Trainset testcase(2,1,1000);
    
    for(int i = 0; i < train.getSize(); i++) {

        if (i % (train.getSize() / 100) == 0)
        {
            cout << "Training Process: " << (double) i / train.getSize() * 100 << '%' << '\r';
            cout.flush();
        }

        x = train.getInput(i);

        theta1 = w1.calculate(x);
        y = sigmoid(theta1);

        theta2 = w2.calculate(y);
        z = sigmoid(theta2);

        ans = train.getOutput(i);
        
        dz = ans - z;
        
        MatrixXd dw1, dw2, diag_dtheta1, diag_dtheta2;
        VectorXd db1, db2, dtheta1, dtheta2;

        diag_dtheta1 = d_sigmoid(theta1).asDiagonal();
        diag_dtheta2 = d_sigmoid(theta2).asDiagonal();

        db2 = diag_dtheta2 * dz;
        dw2 = db2 * y.transpose();

        dy = w2.getMatrix().transpose() * diag_dtheta2 * dz;

        db1 = diag_dtheta1 * dy;
        dw1 = db1 * x.transpose();

        // PRINT(x);
        // PRINT(z);
        // PRINT(dz);
        double step = 0.1;

        w1.setMatrix(w1.getMatrix() + dw1 * step);
        w1.setOffset(w1.getOffset() + db1 * step);
        w2.setMatrix(w2.getMatrix() + dw2 * step);
        w2.setOffset(w2.getOffset() + db2 * step);

        y = sigmoid(w1.calculate(x));
        z = sigmoid(w2.calculate(y));

        // PRINT(z);
    }
    
    for (int i = 0; i < testcase.getSize(); i++)
    {
        x = testcase.getInput(i);
        y = sigmoid(w1.calculate(x));
        z = sigmoid(w2.calculate(y));
        testcase.setMyAns(z, i);
    }
    double accurate = testcase.calculatePrecision();
    cout << endl << "----------" << endl;
    cout << "accurate: " << accurate * 100 << '%' << endl;
    cout << "----------" << endl << endl;

    PRINT(w1.getMatrix());
    PRINT(w1.getOffset());
    PRINT(w2.getMatrix());
    PRINT(w2.getOffset());
    // cout << "input 10 = " << endl << train.getInput(121) << endl;
    // cout << "output 10 = " << endl << train.getOutput(121) << endl;

}




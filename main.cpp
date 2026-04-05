#include <iostream>
#include "loss.h"
#include "Linear_model.h"
#include "optimizer.h"

using namespace std;


int EPOCH = 5;
float lr = 0.01;


int main(){
    LinearModel model = LinearModel(3);
    Optimizer optim = Optimizer(lr, model.get_weights());

    vector<float> data = {2.0, 3.0, 4.0};
    for (int i = 0; i < EPOCH; i++) {
        float predict = model.predict(data);
        cout<<predict;
        float loss = MSE(predict, 9.00);
        optim.step(loss, model.backprop());
    }
    cout<<"Param:";
    for (int i=0; i< model.get_weights().size(); i++) {
        cout<<model.get_weights()[i];
    }
    return 0;
}

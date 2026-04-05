#include <iostream>
#include <optimizer.h>

using namespace std;


Optimizer::Optimizer(float lr, std::vector<float>& w) : lr(lr), weights(w) {
}

void Optimizer::step(float loss, vector<float> grad) {
    for (int i = 0; i<weights.size(); i++) {
        weights[i] = weights[i] - loss*grad[i];
    }
}
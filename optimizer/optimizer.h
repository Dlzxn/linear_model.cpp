#ifndef OPTIMIZER_H 
#define OPTIMIZER_H

#include <vector>

using namespace std;

class Optimizer {
    public:
    float lr;
    vector<float>& weights;
    Optimizer(float lr, vector<float>& weights);
    void step(float loss, vector<float> grad);
};

#endif

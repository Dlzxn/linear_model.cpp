#ifndef LINEAR_H
#define LINEAR_H

#include <vector>

using namespace std;


class LinearModel {
public:
    vector<float> weights;
    float predict(const vector<float>& values);
    LinearModel(const int num_features);
};

#endif
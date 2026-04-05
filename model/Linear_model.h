#ifndef LINEAR_H
#define LINEAR_H

#include <vector>

using namespace std;


class LinearModel {
public:
    vector<float> weights;
    vector<float> last_input;
    float predict(const vector<float>& values);
    LinearModel(const int num_features);
    vector<float> backprop(float diff);
    vector<float>& get_weights();
};

#endif
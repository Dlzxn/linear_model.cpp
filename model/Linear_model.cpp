#include <iostream>
#include <vector>
#include "Linear_model.h"

using namespace std;


LinearModel::LinearModel(int num_features) {
    this->weights.assign(num_features, 0.0f);
}

float LinearModel::predict(const vector<float>& values) {
    float sum = 0.0f;
    for (size_t i = 0; i < values.size(); i++) {
        sum += (values[i] * weights[i]);
    }
    return sum + weights.back();
}

vector<float> LinearModel::backprop() {
    return this->weights;
}

vector<float>& LinearModel::get_weights() {
    return this->weights;
}
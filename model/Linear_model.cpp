#include <iostream>
#include <vector>
#include <random>
#include "Linear_model.h"

using namespace std;


LinearModel::LinearModel(int num_features) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dis(-0.5f, 0.5f);
    this->weights.assign(num_features, dis(gen));
}

float LinearModel::predict(const vector<float>& values) {
    this->last_input = values;
    float sum = 0.0f;
    for (size_t i = 0; i < values.size(); i++) {
        sum += (values[i] * weights[i]);
    }
    return sum + weights.back();
}

vector<float> LinearModel::backprop(float diff) {
    vector<float> grad_vector(this->weights.size());
    for (int i = 0; i<grad_vector.size(); i++) {
        grad_vector[i] = 2*diff*this->last_input[i];
    }
    return grad_vector;
}

vector<float>& LinearModel::get_weights() {
    return this->weights;
}
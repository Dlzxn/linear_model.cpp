#include <iostream>
#include <random>
#include "loss.h"
#include "Linear_model.h"
#include "optimizer.h"

using namespace std;


int EPOCH = 100;
float lr = 0.0001;

vector<vector<float>> data_generator(const vector<float>& true_weights, int num_examples) {
    vector<vector<float>> dataset;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dist_x(-10.0f, 10.0f);
    normal_distribution<float> noise(0.0f, 0.01f);

    int num_features = true_weights.size() - 1;

    for (int i = 0; i < num_examples; i++) {
        vector<float> row;
        float y = 0.0f;
        
        for (int j = 0; j < num_features; j++) {
            float x = dist_x(gen);
            row.push_back(x);
            y += x * true_weights[j];
        }
        
        y += true_weights.back() + noise(gen);
        
        row.push_back(y);
        dataset.push_back(row);
    }
    return dataset;
}


int main(){
    vector<float> goal_weights = {0.5, -2.0, 10.0, 4.0, 9.0};
    vector<vector<float>> data = data_generator(goal_weights, 2000);
    LinearModel model = LinearModel(goal_weights.size() - 1);
    Optimizer optim = Optimizer(lr, model.get_weights());

    for (int i = 0; i < EPOCH; i++) {
        float loss_epoch = 0;
        for (int j = 0; j < data.size(); j++) {
            vector<float> x_values(data[j].begin(), data[j].end() - 1);
            float y_true = data[j].back();
            float predict = model.predict(x_values);
            float loss = MSE(predict, y_true);
            loss_epoch = loss_epoch + loss;
            optim.step(model.backprop(predict-y_true));
        }
        cout<<"Loss epoch "<<i<<": "<<loss_epoch<<"\n";
    }
    cout<<"Param:"<<"\n";
    for (int i=0; i< model.get_weights().size(); i++) {
        cout<<model.get_weights()[i]<<"\n";
    }
    return 0;
}

#include <iostream>
#include <math>

using namespace std;


class MSE {
public:
    float get(float predict, float true_value){
        return (predict-true_value) * (predict-true_value)
    }
}
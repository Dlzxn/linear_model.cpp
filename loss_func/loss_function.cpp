#include "loss.h"


float MSE(float predict, float true_value){
        return (predict-true_value) * (predict-true_value);
    }

float MAE(float predict, float true_value){
        if ((predict-true_value) > 0) {
            return (predict-true_value);
        }
        else {
            return -(predict-true_value);
        }
    }
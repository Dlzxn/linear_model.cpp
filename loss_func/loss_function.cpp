#include "loss.h"


float MSE(float predict, float true_value){
        return (predict-true_value) * (predict-true_value);
    }
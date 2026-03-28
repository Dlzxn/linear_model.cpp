#include <iostream>
#include "loss.h"
#include "Linear_model.h"

using namespace std;


int main(){
    cout<<MSE(4, 2);
    LinearModel model = LinearModel(15);
    return 0;
}

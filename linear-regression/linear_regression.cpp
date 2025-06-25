#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

float mean(const vector<float>& v) {
    float sum = 0.0;
    for(auto i:v) {
        sum += i;
    }

    return sum/v.size();
}

int main() {

    // Y = 2X+1
    vector<float> x = {1.0, 2.0, 3.0, 4.0};
    vector<float> y = {3.0, 5.0, 7.0, 9.0};


    float w=0.0, b=0.0;
    float lr=0.01;
    int epoch=1000;

    for(int i=0; i<epoch; i++) {
        vector<float> y_pred;
        for (int i = 0; i < x.size(); i++) {
            y_pred.push_back(w * x[i] + b);
        }

        float loss=0.0;
        for (int i = 0; i < x.size(); i++) {
            loss += pow(y[i] - y_pred[i], 2);
        }
        loss /= x.size();

        float dw = 0.0;
        float db = 0.0;
        for (int i = 0; i < x.size(); i++) {
            dw += 2 * (y_pred[i] - y[i]) * x[i];
            db += 2 * (y_pred[i] - y[i]);
        }
        dw /= x.size();
        db /= x.size();

        w -= lr * dw;
        b -= lr * db;

        if (i % 100 == 0) {
            cout << "Epoch " << epoch << ": "
                 << "w = " << w << ", b = " << b
                 << ", loss = " << loss << endl;
        }
        
    }

    float test_input = 10.0;
    float result = w * test_input + b;
    cout << "x = " << test_input << "일 때 예측값: " << result << endl;

    return 0;
    
}
#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

double equation1(double value) {
    return value * sin(value) + cos(value);
}

double equation2(double value) {
    return value * cos(value);
}

double equation3(double value) {
    return value * exp(value) - 1;
}

double equation4(double value) {
    return value * exp(value) + exp(value);
}

void newtonRaphsonMethod(double initialValue, int maxIterations) {
    int iteration = 0;
    double currentValue, previousValue = initialValue;
    while (iteration <= maxIterations) {
        currentValue = previousValue - (equation3(previousValue) / equation4(previousValue));
        if (previousValue == currentValue) break;
        previousValue = currentValue;
        iteration++;
    }
    cout << fixed << setprecision(4) << "Root: " << currentValue << endl;
}

int main() {
    double startValue, iterations;
    cout << "Enter the initial value and number of iterations: ";
    cin >> startValue >> iterations;
    newtonRaphsonMethod(startValue, iterations);
    return 0;
}

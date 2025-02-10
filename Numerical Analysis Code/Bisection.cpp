#include<bits/stdc++.h>
using namespace std;
#define EPSILON 0.01

double f(double x) {
    return x*x*x - x*x + 2;
}

void bisectionMethod(double low, double high) {
    if (f(low) * f(high) >= 0) {
        cout << "Invalid initial guesses\n";
        return;
    }

    double mid = low;
    while ((high - low) >= EPSILON) {
        mid = (low + high) / 2;

        if (f(mid) == 0.0)
            break;

        else if (f(mid) * f(low) < 0)
            high = mid;
        else
            low = mid;
    }
    cout << "The root is: " << mid;
}

int main() {
    double low, high;
    cout << "Enter the initial guesses (low and high): ";
    cin >> low >> high;
    bisectionMethod(low, high);
    return 0;
}


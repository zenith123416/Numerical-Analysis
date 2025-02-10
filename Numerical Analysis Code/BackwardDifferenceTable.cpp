
#include<iostream>
using namespace std;

int main() {
    float data[20], diffTable[20][20];
    int i, j, dataCount;

    cout << "Enter number of data points: " << endl;
    cin >> dataCount;

    cout << "Enter data points: " << endl;
    for(i = 0; i < dataCount; i++) {
        cout << "data[" << i << "] = ";
        cin >> data[i];
        cout << "diffTable[" << i << "][0] = ";
        cin >> diffTable[i][0];
    }

    for(i = 1; i < dataCount; i++) {
        for(j = dataCount - 1; j > i - 1; j--) {
            diffTable[j][i] = diffTable[j][i - 1] - diffTable[j - 1][i - 1];
        }
    }

    cout << endl << "BACKWARD DIFFERENCE TABLE" << endl;
    for(i = 0; i < dataCount; i++) {
        cout << data[i];
        for(j = 0; j <= i; j++) {
            cout << "\t" << diffTable[i][j];
        }
        cout << endl;
    }

    return 0;
}

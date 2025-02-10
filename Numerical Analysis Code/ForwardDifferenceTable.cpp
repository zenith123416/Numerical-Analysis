
#include<iostream>
using namespace std;

int main() {
    float dataPoints[20], diffTable[20][20];
    int i, j, dataCount;

    cout << "Enter number of data points: " << endl;
    cin >> dataCount;

    cout << "Enter data points: " << endl;
    for(i = 0; i < dataCount; i++) {
        cout << "dataPoints[" << i << "] = ";
        cin >> dataPoints[i];
        cout << "diffTable[" << i << "][0] = ";
        cin >> diffTable[i][0];
    }

    for(i = 1; i < dataCount; i++) {
        for(j = 0; j < dataCount-i; j++) {
            diffTable[j][i] = diffTable[j+1][i-1] - diffTable[j][i-1];
        }
    }

    cout << endl << "FORWARD DIFFERENCE TABLE" << endl;
    for(i = 0; i < dataCount; i++) {
        cout << dataPoints[i];
        for(j = 0; j < dataCount-i; j++) {
            cout << "\t" << diffTable[i][j];
        }
        cout << endl;
    }

    return 0;
}

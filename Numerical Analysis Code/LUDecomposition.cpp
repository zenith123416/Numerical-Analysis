#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void LUDecompose(vector<vector<float>>& inputMatrix, int matrixSize) {
    vector<vector<float>> lower(matrixSize, vector<float>(matrixSize, 0));
    vector<vector<float>> upper(matrixSize, vector<float>(matrixSize, 0));

    for (int row = 0; row < matrixSize; row++) {
        for (int col = row; col < matrixSize; col++) {
            upper[row][col] = inputMatrix[row][col];
            for (int k = 0; k < row; k++) {
                upper[row][col] -= lower[row][k] * upper[k][col];
            }
        }
        for (int col = row; col < matrixSize; col++) {
            if (row == col)
                lower[row][row] = 1;
            else {
                lower[col][row] = inputMatrix[col][row];
                for (int k = 0; k < row; k++) {
                    lower[col][row] -= lower[col][k] * upper[k][row];
                }
                lower[col][row] /= upper[row][row];
            }
        }
    }

    cout << "\nLower Matrix (L):\n";
    for (int row = 0; row < matrixSize; row++) {
        for (int col = 0; col < matrixSize; col++) {
            cout << setw(4) << lower[row][col] << " ";
        }
        cout << endl;
    }

    cout << "\nUpper Matrix (U):\n";
    for (int row = 0; row < matrixSize; row++) {
        for (int col = 0; col < matrixSize; col++) {
            cout << setw(4) << upper[row][col] << " ";
        }
        cout << endl;
    }
}

int main() {
    int matrixSize;
    cout << "Enter the size of the matrix: ";
    cin >> matrixSize;

    vector<vector<float>> inputMatrix(matrixSize, vector<float>(matrixSize));

    cout << "Enter the matrix values:\n";
    for (int row = 0; row < matrixSize; row++) {
        for (int col = 0; col < matrixSize; col++) {
            cout << "matrix[" << row << "][" << col << "] = ";
            cin >> inputMatrix[row][col];
        }
    }

    LUDecompose(inputMatrix, matrixSize);

    return 0;
}


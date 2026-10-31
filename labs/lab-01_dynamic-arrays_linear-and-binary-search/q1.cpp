/*
 Write a C++ program to copy data of a 2D array in a 1D array using Column Major Order.
*/
#include <iostream>
using namespace std;

int main(){
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    int arr2D[rows][cols];
    cout << "Enter the elements of the 2D array:" << endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cin >> arr2D[i][j];
        }
    }

    int arr1D[rows * cols];
    int index = 0;

    for(int j = 0; j < cols; j++){
        for(int i = 0; i < rows; i++){
            arr1D[index++] = arr2D[i][j];
        }
    }

    cout << "Elements of the 1D array (in column-major order):" << endl;
    for (int i = 0; i < rows * cols; i++){
        cout << arr1D[i] << " ";
    }
    cout << endl;

    return 0;
}

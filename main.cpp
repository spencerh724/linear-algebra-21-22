#include <iostream>

using namespace std;

class Matrix3x4{
    public:
        int rows;
        int columns;
        double **table;

        Matrix3x4(){
            rows = 3;
            columns = 4;
            table = new double*[rows];
            for(int i = 0; i < rows; i++){
                table[i] = new double[columns];
            }

            for(int i = 0; i < rows; i++){
                for(int j = 0; j < columns; j++){
                    cout << "A[" << i+1 << "][" << j+1 << "]: ";
                    cin >> table[i][j];
                }
            }
            cout << endl;
        }

        string toString(){
            string ret = "";
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < columns; j++){
                    ret.append(to_string(table[i][j]) + " ");
                }
                ret.append("\n");
            }
            return ret;
        }
    
        void scaleRow(int r, double k){
            for(int i = 0; i < columns; i++){
                table[r][i] *= k;
            }
        }

        void addRow(int k, int rA, int rB){
            for(int i = 0; i < columns; i++){

            }
        }
};


int main(){
    Matrix3x4 A;
    A.scaleRow(0, 0.5);
    cout << A.toString();

}

//    int rows;
//    int columns;
//
//    cout << "rows, cols: ";
//    cin >> rows >> cols;
//
//    int** table = new int*[rows];
//    for(int i = 0; i < rows; i++){
//        table[i] = new int[columns];
//    }
//
//    //de-allocation
//
//    for(int i = 0; i < rows; i++){
//        delete[]table[i];
//        table[i] = NULL;
//    }
//    delete[] table;
//    table = NULL;

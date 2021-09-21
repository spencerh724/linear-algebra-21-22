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

        Matrix3x4(string s){
            rows = 3;
            columns = 4;
            table = new double*[rows];
            for(int i = 0; i < rows; i++){
                table[i] = new double[columns];
            }
            table[0][0] = 2;
            table[0][1] = 6;
            table[0][2] = 1;
            table[0][3] = 7;
            table[1][0] = 1;
            table[1][1] = 2;
            table[1][2] = -1;
            table[1][3] = -1;
            table[2][0] = 5;
            table[2][1] = 7;
            table[2][2] = -4;
            table[2][3] = 9;

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
                table[rB][i] += k * table[rA][i];
            }
        }

        void RREF(){
            /*
            for(int i = 0; i < columns; i++){
                scaleRow(i, 1.0/table[i][i]);
                for(int j = 0; j < rows; j++){
                    if(j != i){
                        addRow(-(table[j][i]), i, j);
                    }
                }
            }
            */
        }
};


int main(){
    Matrix3x4 A("akdslfjfhfj");
    cout << A.toString() << endl;

    A.scaleRow(0, 1.0/A.table[0][0]);
    cout << "cout << A.toString() << endl;" << endl;
    cout << A.toString() << endl;

    A.addRow(-(A.table[1][0]), 0, 1);
    cout << "A.addRow(-(A.table[1][0]), 0, 1);" << endl;
    cout << A.toString() << endl;

    A.addRow(-(A.table[2][0]), 0, 2);
    cout << "A.addRow(-(A.table[2][0]), 0, 2);" << endl;
    cout << A.toString() << endl;
    //////////////////////////////////////////////
    A.scaleRow(1, 1.0/A.table[1][1]);
    cout << "A.scaleRow(1, 1.0/A.table[1][1]);" << endl;
    cout << A.toString() << endl;

    A.addRow(-(A.table[0][1]), 1, 0);
    cout << "A.addRow(-(A.table[0][1]), 0, 1);" << endl;
    cout << A.toString() << endl;

    A.addRow(-(A.table[2][1]), 1, 2);
    cout << "A.addRow(-(A.table[2][1]), 0, 2);" << endl;
    cout << A.toString() << endl;
    //////////////////////////////////////////////
    A.scaleRow(2, 1.0/A.table[2][2]);
    cout << "A.scaleRow(2, 1.0/A.table[2][2]);" << endl;
    cout << A.toString() << endl;

    A.addRow(-(A.table[0][2]), 2, 0);
    cout << "A.addRow(-(A.table[0][3]), 2, 0);" << endl;
    cout << A.toString() << endl;

    A.addRow(-(A.table[1][2]), 2, 1);
    cout << "A.addRow(-(A.table[1][3]), 2, 1);" << endl;
    cout << A.toString() << endl;


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

#include <iostream>

using namespace std;

class Matrix{
    public:
        int rows;
        int columns;
        double **table;

        Matrix(int r, int c){
            rows = r;
            columns = c;
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

        Matrix(string s){
            //this constructor is for a specific test matrix
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
            int m = (rows==columns) ? rows-1:rows;
            for(int i = 0; i < m ; i++){
                scaleRow(i, 1.0/table[i][i]);

                for(int j = 0; j < rows; j++){
                    if(j != i){
                        addRow(-(table[j][i]), i, j);
                    }
                }
            }
            return;
        }
};


int main(){
    Matrix A("akdslfjfhfj"); //test matrix with values inputted in code
    cout << A.toString() << endl;
    A.RREF();
    cout << A.toString() << endl;

    Matrix B(3, 3);
    cout << B.toString() << endl;
    B.RREF();
    cout << B.toString() << endl;
    
    /*
        Tested B with:
           1    1   1
           4   -1  -6
           2   -3   8
    */

}

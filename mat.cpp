#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

const int MIN_CHAR_PRINTABLE_VAL = 33;
const int MAX_CHAR_PRINTABLE_VAL = 126;
 
using namespace std;

namespace ariel{

    string mat(int colls, int rows, char c1, char c2){

        if(colls % 2 == 0 || rows % 2 == 0){
            throw invalid_argument("Mat size is always odd");
        }
        if(c1 < MIN_CHAR_PRINTABLE_VAL || c1 > MAX_CHAR_PRINTABLE_VAL || c2 < MIN_CHAR_PRINTABLE_VAL || c2 > MAX_CHAR_PRINTABLE_VAL){
            throw invalid_argument("char must be ascii");
        }
        if(colls < 0 || rows < 0){
            throw invalid_argument("matrix rows and colloms must be positive");
        }
        
        char c = 0;
        int min_v = min(colls, rows);
        int total_rings = min_v/2 + 1;

        vector<vector<char>> matrix (rows, vector<char>(colls));
        // if(matrix == NULL){
        //     return NULL;
        // }
        // for (int i = 0; i < rows; i++){
        //     matrix[i] = new char[colls];
        //     if(matrix[i] == NULL){
        //         return NULL;
        //     }
        // }

        for(int i = 0; i < total_rings; i++){
            c = c1;
            if(i % 2 != 0){
                c = c2;
            }
            for(int start = i; start < colls-i; start++){  
                matrix[i][start] = c;  // put up line values 
                matrix[rows-i-1][start] = c;  // put down line values
            }
            for(int start = i; start < rows-i; start++){
                matrix[start][i] = c;  // left collum
                matrix[start][colls-i-1] = c;  // right collum
            }
        }
        string s;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < colls; j++){
                s += matrix[i][j];
            }
            s += "\n";
            // delete [] matrix[i];
        }
        // delete [] matrix;

        return s;
    }
}
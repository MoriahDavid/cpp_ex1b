#include <iostream>
#include "mat.hpp"

using namespace std;
using namespace ariel;

int main(){

    int colls = 0;
    int rows = 0; 
    string c1; 
    string c2; 
    char ans = 0;
    bool is_running = true;

    while(is_running){

        cout << "Type columns number: "; // Type and press enter
        cin >> colls; // Get user input for columns

        cout << "Type rows number: ";
        cin >> rows; // Get user input for rows

        cout << "Type spirals design of the rug: ";
        cin >> c1; // Get user input for the rug spiral
        if(c1.length() != 1){
            cout << "invalid input: Insert only one charecter" << endl;
            continue;
        }

        cout << "Type background of the rug: ";
        cin >> c2; // Get user input for background
        if(c2.length() != 1){
            cout << "invalid input: Insert only one charecter" << endl;
            continue;
        }

        try {
            string rug = mat(colls, rows, c1[0], c2[0]);
            cout << "Your rug design: " << endl << rug;
        } 
        catch (exception & ex) {
            cout << "invalid input: " << ex.what() << endl;
        }
        cout << "Do you want to create another rug? (y/n) ";
        cin >> ans; // Get user answer
        if(ans == 'n'){
            is_running = false;
        }
    }
}
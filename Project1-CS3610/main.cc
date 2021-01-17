/*
 * Date: 09/08/20
 * Gerald McGee
 * CS 3610 - Data Structures
 * Project #1 
 *
 * 
*/

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <string>
#include <cctype>
using namespace std;



bool valid_int(string y);
/*
Precondition: Takes a string object
Postcondition: If the string passed is a valid integer it will return true, if otherwise false.
*/


struct listNum{
    int value;
    bool prime;
    bool marked;
};

int main(int argc, char** argv){
    string input;

    if (argc < 2){
        cout << "Missing Argument" << endl;
        return 0;
    }

    input = argv[1]; 
    if(!valid_int(input)){
        return 0;
    }

    input = argv[1];
    int n = stoi(input);  int asize = n  + 1;

    listNum *list = new listNum[n + 1]; 
    for(size_t i = 0; i < asize;  ++i){ // set values of the struct
        list[i].value  = i;
        list[i].prime = false;
        list[i].marked = false;
    }

    for(size_t i = 2; i <= n; i++){ //sieve 
        if(!list[i].marked){
            list[i].prime = true;

            for(int j = i * 2; j <= n; j += i){
                list[j].marked = true; 
            }
        }
    }

    for(size_t i = 2; i <  asize; ++i){ // prime print
        if(list[i].prime){
            cout << list[i].value << " ";
        }
    }
    cout << endl;
    for(size_t i = 2; i <  asize; ++i){ // comp print
        if(!list[i].prime){
            cout << list[i].value << " ";
        }
    }
    cout << endl;

    delete [] list;
    return 0;
}
bool valid_int(string y){
    for (size_t i =  0; i < y.length(); ++i){
        if(!isdigit(y[i])){
            cout << "Nan" << endl; 
            return false;
        }
    }

    int x = stoi(y);
    if(x >= 2 &&  x <= 3000)
        return true; 

    cout << "Out of range" << endl;
    return false;
}
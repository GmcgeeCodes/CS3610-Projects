/*
 * File: Main.cc 
 * Gerald McGee 
 * Project 5, Ohio University CS3610
 * 11/25/20
 * 
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>

using namespace std;

// function prototype
void dijAlgo(int sizeN, vector <vector<int> > dMatrix, string* cityNames);
/*
This function will check all possible that could be taken and returns the
smallest route.
*/

int min_length(int sizeN, int distance[],bool v[]);
/*
This function will return the minimum distance
*/
void print(string* cityNames, int index, int p[]);
/*
The print function will putput the cityNames from the array.
*/


int  main(){
    int k, n; // k for tests, n for cities
    cin >> k;
    
    while (k > 0){
        cin >> n;    
        string cityNames[n]; // this array will contain the cities

        for(size_t i = 0; i < n; i++){
            cin >> cityNames[i];
        }

        vector <vector<int> > dMatrix;
        dMatrix.resize(n);

        for(size_t i = 0; i < n; i++){
            dMatrix[i].resize(n);
            for(size_t j = 0; j < n; j++){
                cin >> dMatrix[i][j];
            }
        }

        dijAlgo(n, dMatrix, cityNames);
        k--;
    }
    return 0;
} // end of main

void dijAlgo(int sizeN, vector <vector<int> > dMatrix, string* cityNames){
    
    bool v [sizeN]; int distance[sizeN]; int before[sizeN];

    int i = 0;
    while(i < sizeN){
        distance[i] = INT32_MAX; v[i] = false;
        i++;
    }

    before[0] = -1; 
    distance[0] = 0; 
    for(size_t i = 0; i < sizeN; i++){  
        int x = min_length(sizeN, distance, v);
        v[x] = 1; 
        for(int j = 0; j < sizeN; j++){
            if(!v[j] && dMatrix[x][j] && distance[x] != INT32_MAX && distance[j] > distance[x] + dMatrix[x][j]){
                before[j] = x;
                distance[j] = distance[x] + dMatrix[x][j];

            }
        }

    }
    print(cityNames ,sizeN - 1,before);
    cout << distance[sizeN - 1] << endl;
}
int min_length(int sizeN, int distance[], bool v[]){
    int minimum = INT32_MAX;
    int x;
    for(size_t i = 0; i < sizeN; i++){
        if(!v[i] && distance[i] <= minimum){
            minimum = distance[i];
            x = i;
        }
    }
    return x;
}
void print(string* cityNames, int index, int p[]){
    if(p[index] == -1){
        cout << cityNames[0] << " "; return;
    }
    print(cityNames, p[index], p);
    cout << cityNames[index] << " ";

}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: k
 *
 * Created on 13 September 2016, 5:07 AM
 */

#include <cstdlib>
#include <vector> 
#include <iostream>
#include <algorithm>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    const int lowest = 10;
    const int highest = 99;
    vector<int> scramble;
    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        scramble.push_back(lowest + rand() % (highest - lowest + 1));
    }
    cout << "original: ";
    for (int i = 0; i < scramble.size(); i++) {
        cout << scramble[i] << " ";
    }
    cout << endl << endl;
    //q1.1
    cout << "max value: " << *max_element(scramble.begin(), scramble.end()) << endl;

    //q1.2
    cout << "times 13 appears: " << count(scramble.begin(), scramble.end(), 13) << endl;

    //q1.3
    vector<int>::iterator pbegin = scramble.begin();
    vector<int>::iterator pend = scramble.end();
    pend = remove(pbegin, pend, 13);
    scramble.resize(pend - pbegin);
    cout << "size of new vector after removing 13s: " << scramble.size();
    cout << endl;
    cout << endl;

    //q2.1
    int tempMax = scramble[0];
    for (int i = 1; i < scramble.size(); i++) {
        if (scramble[i] > tempMax) tempMax = scramble[i];
    }
    cout << "max value: " << tempMax << endl;

    //q2.2
    int counter = 0;
    for (int i = 0; i < scramble.size(); i++) {
        if (scramble[i] == 14) counter++;
    }
    cout << "times 14 appears: " << counter << endl;

    //q2.3
    for (int i = 0; i < scramble.size(); i++) {
        if (scramble[i] == 14) scramble.erase(scramble.begin() + i);
    }
    cout << "size of new vector after removing 14s: " << scramble.size();
    
    return 0;
}


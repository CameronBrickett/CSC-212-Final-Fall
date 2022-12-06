#ifndef KNUTT_H
#define KNUTT_H
#include <iostream>
#include <vector>
#include <fstream>    // all the libraries knutt class will need
#include <sstream>
#include <algorithm>
#include <chrono>
#include <thread>

class Knutt{        //knutt class

    private:

        std::string filename;
        std::string originaltext;       // variabels the constructor will set from input
        std::string pattern;
        int length;

    public:

    //constructor
    Knutt(std::string fname,std::string pat,int len);

    //method for knutt
    void readfile();             //to open and read the file
    void solvelps();           // time and solve the lps array seacch will need
    void search(int lps[],float ms1);            // the actual search with both times time


};
#endif
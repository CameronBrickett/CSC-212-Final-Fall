#ifndef Boyer_H
#define Boyer_H
# define NO_OF_CHARS 256
#include <iostream>
#include <vector>
#include <fstream>       /// all the libraries boyer class will need
#include <sstream>
#include <algorithm>
#include <string>
#include <chrono>
#include <thread>

class Boyer{         //boyer class

    private:

        std::string fileName;
        std::string originaltxt;          //  variabels the constructor will set with input
        std::string Pattern;
        int Length;
        float ms1;      //  first elapsed time for badCharHeuristic function

    public:

    //constructor
    Boyer(std::string fname,std::string pat,int len);

    // methods for boyer
    void readfileBoyer();
    void badCharHeuristic(std::string str, int size,int badchar[NO_OF_CHARS]);
    void searchBoyer();

};
#endif
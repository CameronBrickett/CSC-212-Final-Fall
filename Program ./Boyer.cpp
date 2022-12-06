#include "Boyer.h"
#include <bits/stdc++.h>
using namespace std;



//Constructor Function
Boyer::Boyer(std::string fname,std::string pat, int len){
    fileName = fname;
    Pattern = pat;
    Length =len;
}
//read file Function
void Boyer::readfileBoyer(){
    std::string line;
    std::string temp;
    std::ifstream input_file(fileName);
    while(std::getline(input_file,line)){
        std::stringstream stream(line);
        while(stream >> temp){
          originaltxt += temp;
        }

    }
}




//this function will set the items in badchar all equal to -1 and when the pattern has been checked in that area it will set it equal to the corisponding point in the pattern
void Boyer::badCharHeuristic( string Pattern, int patlen,int badchar[NO_OF_CHARS]){
    int i;
    for (i = 0; i < NO_OF_CHARS; i++){
        badchar[i] = -1;
    }
    for (i = 0; i < patlen; i++){
        badchar[(int) Pattern[i]] = i;
    }
}




//This function will find the pattern within the text
void Boyer::searchBoyer()
{
    //this will set patlen equal to the length of patter
    int patLen = Pattern.length();
    //this will set txtlen equal to the length of the text document
    int txtlen = originaltxt.length();
    //This is setting the ammount of possible characters there will be in a string
    int badchar[NO_OF_CHARS];
    //This calls the function above to check the bad characteristic rule
    badCharHeuristic(Pattern, patLen, badchar);
    int s = 0;
    //This will be counting how many comparisons will be made in the program
    int count=0;
    //This is creating a timer that we will use to see how long the program runs for
    using namespace std::literals::chrono_literals;
    //This starts the timer
    auto start = std::chrono::high_resolution_clock::now();
    //This while loop will run until the text file.length - the pattern.length();
    while(s <= (txtlen - patLen)){
        int small = patLen - 1;
    //This while loop will make the index size of small shrink by one each loop there by making the pattern shift the appropriet ammount of times.
        while(small >= 0 && Pattern[small] == originaltxt[s + small]){

            small--;
            //Number of comparisons will go up by one each time this loops through
            count++;
        }
        //this if statement will kill the while loops because the pattern has been found
        if (small < 0){

            s += (s + patLen < txtlen)? patLen-badchar[originaltxt[s + patLen]] : 1;
            count++;

        }
        //the else statement will shift the bad character to make a match within the string you are looking in

        else{
            s += max(1, small - badchar[originaltxt[s + small]]);
            count++;
        }

    }
    //This will print out the number of times the string was compared inside the Boyer Moore Algorithm
    std::cout<<"number of comparisons for Boyer Moore Algorithm = "<<count<<"\n";
    //This stops the clock
    auto end =std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = end - start;
    //This will tell us how long the program took to exicute
    std::cout<<duration.count()<<" seconds" <<std::endl;

}

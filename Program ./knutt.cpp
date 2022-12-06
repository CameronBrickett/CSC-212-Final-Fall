#include "knutt.h"

//constructor
Knutt::Knutt(std::string fname,std::string pat, int len){
    filename = fname;    // saving input fname to "filename" so it
    pattern = pat;       // saving the input to "pattern" so it can be refrenced later
    length =len;
}

// readfile
void Knutt::readfile(){
    std::string line;
    std::string temp;

    //std::string original;
    std::ifstream input_file(filename);
    while(std::getline(input_file,line)){            // readfile line by line and save it to "line"
     // std::cout<<line;
        //std::stringstream stream(line);           // stringstream on line to account for whitespace and save the words to stream
        //while(stream >> temp){                    //                    while there is a word on the line
          //originaltext += temp;                     //                   add the word to originaltext the
        //}
       originaltext += line + "\n";

    }
}

void Knutt::solvelps(){

    int templps[length];
    int len = 0;               //pointing  the longets prefix
    int i = 1;                //travesing the pattern starting at the second position

    templps[0] =0;          //the first positon is set to 0
                              using namespace std::literals::chrono_literals;         //  using the namespace so we can use auto
                              auto start =std::chrono::high_resolution_clock::now();   // starting the high::resolutions clock here

    while( i < length){                                         //while loop will run the length of the pattern
      if( pattern[len] == pattern[i]){             //if the next positions maches the previous
          templps[i]= len+1;                         //lps array at i will equal len+1
          i++;                                                //advance the search
          len++;                                          //advance the search

      }else if( len != 0 ){                   //in the case where len has advanced and a mismatch is made
              len = templps[len-1];             // we are setting len = to len templps[len-1] to refrence our array and find
                                                    // what previous comparisons were already made so if another mismatch is made array at lps will acount for that
      }
      else {                                  // in the case that there is a mismatch and len is equal to 0
        templps[i] =0;
        i++;
      }
    }

                    auto end =std::chrono::high_resolution_clock::now();     // end the clock here
                    std::chrono::duration<float> duration1= end - start;    //  calculate the total elapsed time "duration" with the end-start
                    float ms1 = duration1.count() * 1000.0f;                 // change duration from seconds to milliseconds


     search(templps,ms1);                 //call to search with parameters the lps array and the elapsed time

}

void Knutt::search(int lps[], float ms1){

  int i =0;                                       // pointers to our orginal text and pattern
  int j =0;
  int orglength = originaltext.length();
  double textlength = originaltext.length();
  double patlength = length;
  int count =0; ;
  double percentage=0;
  bool match = false;
  int count2 =0;

                      //time timer;
                      using namespace std::literals::chrono_literals;             //using namespace for auto
                      auto start =std::chrono::high_resolution_clock::now();            /// starting the high::resolutions clock here

   while(i < orglength-length+1){                                    // the loop will run for the size of original length
  


    if ( pattern[j]== originaltext[i]){                //    if pattern is made advance both pointers
        i++;
        j++;
        count++;

    }else {                                                 // if a mismach is made and j has been advanced we will refrence our previous
      if (j != 0){                                               // longest prefix that is also a suffix to advance and make less comparisons
        j = lps[j-1];                                           // while also not ignoring any overlaping matches
        count++;
      }else {
        i++;
        count++;
      }
    }

    if(j == length){                                                      // if j=length than we have matched till the end of pattern and a match is made
        //std::cout<<i-j<<"\n";
        count++;
        match = true;
        j= lps[j-1];
        break;                                                         // we will break from the loop when the match is made

      }
    }

                    auto end =std::chrono::high_resolution_clock::now();          //end the clock here
                    std::chrono::duration<float> duration2 = end - start;           /// calculate the total elapsed time "duration" with the end-start
                    float ms2 = duration2.count() * 1000.0f;                      // change duration from seconds to milliseconds
                    ms2 += ms1;                                                     // the lsp time + the search time
                    std::cout<<"_______________________________________\n";
                    std::cout<<"Knutt-Morris-Pratt"<<std::endl;
                    std::cout<<"Number of comparisons for Knutt Moris Pratt Algorithm = "<<count<<"\n";

                 if (match){                                                    // if the match was made we then output the time it required
                   std::cout<<ms2<<" Milliseconds" <<std::endl;
                   percentage = (patlength/textlength)*100;
                  // std::cout<<"Percentage of match= "<<percentage<<"\n";
                 }else {                                                                         // if no match was made we will ouput this
                  std::cout<<ms2<<" Milliseconds\n"<<"NO MATCH WAS MADE" <<std::endl;
                 }

}

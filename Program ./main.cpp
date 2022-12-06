
// include our header files
#include "knutt.h"
#include "Boyer.h"

int main(int argc, char** argv){



    std::string fname = argv[1];    // file name from command line
    std::string pat =argv[2];      // pattern to search for from command line
    int len = pat.length();        //length of the pattern

    Knutt knutt(fname,pat,len);         /// object constructors for the respective classes
    Boyer Boyer(fname,pat,len);            // that takes in the filename, that pattern, and the length

    knutt.readfile();                       // read the file for the knutt classs
    knutt.solvelps();                         // calling the solvelps function of knutt class

    Boyer.readfileBoyer();            ///readfile for the boyer class             kind of redundent might need fixing
    Boyer.searchBoyer();                  //calling the search function for boyer class

}




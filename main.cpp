#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>
#include "similarityDetector.hpp"
#include "LCS.hpp"
using namespace std;





//load two strings from txt file then send them as parameters for LCS class
int main() {
    ifstream file("twoStrings.txt");
    if(!file.is_open()) {
        cerr<<"error opening file"<<endl;
        return 1;
    }
    string string1;
    string string2;

    getline(file,string1);
    getline(file,string2);
    file.close();


     LCS lcs(string1,string2);
     lcs.computeLCS();
     string lcsresult=lcs.getLCS();


    cout<<"welcome to DSA2P5, this program will use dyanmic programming to solve longest common sub sequence prob"<<endl;
    cout<<"This will utilze c array but no 'b' array "<<endl;
    cout<<"Longest subsequence is " <<lcsresult<<endl;
    //print results from LCS
    //pass text file name into similarity detector, class opens the file by itself
    similarityDetector detector("multiStrings.txt");
    detector.printSimilarityMatrix();
    //print similarity matrix
    return 0;
}
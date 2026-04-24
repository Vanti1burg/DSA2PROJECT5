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

    similarityDetector detector("multiStrings.txt");
    detector.printSimilarityMatrix();
    return 0;
}
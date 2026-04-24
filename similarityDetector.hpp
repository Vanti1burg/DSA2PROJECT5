#ifndef SIMILARITYDETECTOR_HPP
#define SIMILARITYDETECTOR_HPP
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>



using namespace std;

class similarityDetector{
    private:
        vector<string> strings;
        string x;
        string y;
        int n, m;
        int numStrings;
        vector<vector<int>> c;
        ifstream file;
        vector<vector<char>> similarityMatrix;
        string fileName;
        int i1;
        int i2;
    public:
        similarityDetector(string fileName);
      
        void computeSimilarity(string string1, string string2, int index1,int index2);
        
          void computeLCS();
         void printSimilarityMatrix();
          string readLine(string fileName, int lineNumber);
          
       
};

#endif
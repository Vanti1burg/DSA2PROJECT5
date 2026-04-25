#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "similarityDetector.hpp"
using namespace std;

//similariyDetector constructor, takes the file name and opens file to find string number, which then creates the similarity matrix
//initializs default values in similarity matrix to dash to show uncomputed value.

similarityDetector::similarityDetector(string fileName) {

    this->fileName=fileName;

    file.open(fileName);

    if(!file.is_open()) {

        cerr<<"Error opening"<<endl;
        exit(1);

    }

    string line;

    getline(file,line);

    numStrings=stoi(line);

    file.close();

    similarityMatrix.resize(numStrings,vector<char>(numStrings,'-'));
//compute similarity for each pair of strings, only compute upper triangle since it is all that is needed for this symetric matrix

    for (int i=0; i<numStrings; i++) {
        //find string based on line number, then compute similarity and fill in matrix based on result
        for(int j=i+1; j<numStrings; j++){

           x= readLine(fileName,i+2);

           y= readLine(fileName,j+2);

           computeSimilarity(x,y,i,j);

        }

    }


}



void similarityDetector::computeSimilarity(string string1, string string2, int index1, int index2)  {

   
    x=string1;
    y=string2;
    i1=index1;
    i2=index2;

    n=x.length();
    m=y.length();
    c.assign(n+1, vector<int>(m+1,0));
    computeLCS();
//basically just takes parameters and sets up the compute lcs function, kind of a buffer that isnt really needed
// but I created it in the process of completing this project and saw no reason to change it since it works    

}

  void similarityDetector::computeLCS() {
    //similar to regular LCS function but does not need to reconstruct
    //creates a c array and fills it normally, then uses final values to compute similarity and fill 
    //matrix based on thresholds stated in project document
         int lcsLength=0;
        
            for (int i=0 ; i<=n; i++) {

                 for (int j=0; j<=m;j++){

                    if (i==0 || j==0) {

                        c[i][j]=0;


                    }

                    else if(x[i-1]==y[j-1]) {

                        c[i][j]=c[i-1][j-1]+1;

                       

                    }

                    else {
                        c[i][j]=max(c[i-1][j],c[i][j-1]);


                    }

                 }
            }
            //lcsLength in bottom right 
                lcsLength=c[n][m];

            //compute similarity, basically if length of lcs is close to length of shorter string and longer string is not much longer 
            //then high sim, this follows for other thresholds, most notably even if the lcs is 100 percent of shorter string,
            //if longer string is much longer than shorter than it gets a lower similarity rating.

            double similarity= (double)lcsLength/min(n,m);

            double lengthDiff =abs(n-m);



            if (similarity>=0.9 && lengthDiff<=0.1*min(n,m)) {
                similarityMatrix[i1][i2]='h'; 
            }
            else if (similarity>=0.8 && lengthDiff<=0.2*min(n,m)) {
                similarityMatrix[i1][i2]='m'; 
            }
            else if (similarity>=0.5 && lengthDiff<=0.4*min(n,m)){
                similarityMatrix[i1][i2]='l';
            }
            else {
                similarityMatrix[i1][i2]='d'; 
            }

        

        }
 
//prints similarity matrix for upper triangle

void similarityDetector::printSimilarityMatrix() {

    cout<<"Similarity Matrix: " <<endl;

    for (int i=0;i<numStrings;i++) {

        for (int j=0;j<numStrings;j++) {

            cout<<similarityMatrix[i][j]<<" ";


        }

        cout<<endl;
    }

}
//this is used to grab strings from file without having to load entire file into memory or array
//this isn't the most efficient way since it has to iterate through file till it reaches line number
//but it does achieve the goal of not loading whole file into array

string similarityDetector::readLine(string fileName, int lineNumber) {

    ifstream file(fileName);

    if(!file.is_open()){

        return "error opening file";

        
    }
    string line;

    for(int i=0;i<lineNumber;i++){

        if(!getline(file,line)){

            return "error reading line";

            
        }

        else if(i==lineNumber-1){

            return line;

        }
    }

    file.close();
    
    return "line not found";


}
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

    for (int i=0; i<numStrings; i++) {

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
    

}

  void similarityDetector::computeLCS() {

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
                lcsLength=c[n][m];

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
 

void similarityDetector::printSimilarityMatrix() {

    cout<<"Similarity Matrix: " <<endl;

    for (int i=0;i<numStrings;i++) {

        for (int j=0;j<numStrings;j++) {

            cout<<similarityMatrix[i][j]<<" ";


        }

        cout<<endl;
    }

}

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
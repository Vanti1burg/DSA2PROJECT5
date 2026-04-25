#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include "LCS.hpp"
using namespace std;


//lcs constructor, creates the 2d c vector and initializes everything, creates internal strings to pass through algorithm
LCS::LCS(string string1, string string2) {

             x=string1;
             y=string2;

             n=x.length();
             m=y.length();

             c.resize(n+1, vector<int>(m+1,0));


        }


//computeLCS function, fills the c array with lengths of longest common subsequence 
//at that particular point, uses 'c' array but no 'b' array


void LCS:: computeLCS() {

        //assign values to c array based on character matches or surrounding values
            for (int i=0 ; i<=n; i++) {

                 for (int j=0; j<m;j++){

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

        }
//reconstructs lcs from c matrix from bottom right to top left
//if characters match, add to lcs and move diagonally, if not move to the larger of two surrounding values
//reverse at the end since it builds backawrds.

string LCS::getLCS() {

        string lcs="";
        int i=n, j=m;

        while(i>0&&j>0) {

            if (x[i-1]==y[j-1]) {

                lcs+=x[i-1];
                i--;

            }

            else if (c[i-1][j]>c[i][j-1]){

                i--;
            }

            else {
                j--;
            }
        }
        
        reverse(lcs.begin(),lcs.end());
        return lcs;
     }

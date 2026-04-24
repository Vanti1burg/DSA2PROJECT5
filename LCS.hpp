#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;


class LCS {
private:
        string x, y;
        int n,m;
        vector<vector<int>> c;
      
    public:
        LCS(string string1, string string2);
        void computeLCS();
        string getLCS() ;
       
};



# DSA2PROJECT5
Final Project for DSA2
 
This project is a program that find the LCS or longest common subsequence in two different strings as well as creating a similarity matrix of many strings through the use of dynamic programming applications to store and retrieve already solved problems
The program consists of a main driver file, an lcs header and cpp file that runs the simple LCS algorithm that can work with any two strings. There
is also a SimilarityDetector hpp and cpp (sorry for the long drawn out names its easier for me) which run the similarity detection class that can compare many strings, and without loading all of them into memory, to create a matrix that shows the similarities between different strings

Program Instructions 
1) Drop this folder into a valid linux environmnet and open the terminal
2) While in the directory type make clean into the terminal to verify no objects have been made yet
3) Type make into the terminal to assemble the program into exectuables
4) type ./main to run the program, the results will show a very long first part that shows the lcs of two very...very long strings
    afterward below you will see a matrix with only the upper triangle filled in which shows the similarities of strings within the multiStrings.txt file
    
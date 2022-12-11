// XMLConversion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include<string>
#include <algorithm>
#include <cctype>
#include <vector>

using namespace std;


int main()
{
    string x;

    ifstream f("XML.txt");            
    ofstream fileCreated("Testf.txt"); 


    while (getline(f,x)) {

        x.erase(remove_if(x.begin(), x.end(), ::isspace), x.end());  
        fileCreated << x << "\n";
    }
    
   
    f.close();
    fileCreated.close();
}


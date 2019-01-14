#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int main()
{

string fName = "save.dat";
string lin;
ifstream introFile;

introFile.open(fName.c_str());

if (introFile.fail())
{
    cout <<"The file was not opened"
         <<endl;
}

while (getline(introFile,lin))
       cout<<lin<<endl;

     









}

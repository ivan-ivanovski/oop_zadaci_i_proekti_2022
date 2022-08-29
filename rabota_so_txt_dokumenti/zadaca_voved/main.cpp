#include <iostream>
#include<fstream>
#include<cstring>
using namespace std;

int main()
{
    ifstream vlezDat("vlez.txt");
    string line;
    if(vlezDat.is_open())
    {
        while ( getline (vlezDat,line) )
        {
          cout << line << endl;
        }
        vlezDat.close();
    }
    else
        cout<<"Ne mozam da ja otvoram datotekata ili dadotekata ne postoi"<<endl;
    return 0;
}

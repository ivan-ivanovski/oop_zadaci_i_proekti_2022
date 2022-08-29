#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

int main()
{
    ofstream izlDat("izlez.txt");
    char lin[60];
    while(izlDat.is_open()){
        cin.getline(lin,60);
        izlDat<<lin<<endl;
    }

    system("pause");
}

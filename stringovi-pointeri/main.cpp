/*Dolzina na string*/
#include <iostream>
using namespace std;
int Dolzina(char *ch){
    int i;
    while(*ch !='\0'){
        i++;
        ch++;
    }
    return i;
}
int main(){
    char zbor[100];
    int l;
    cout<<"Dolzina na string so pomos na niza od znaci i koristenje na pointeri \n";
    cout<<"Vnesi go zborot\n";
    cin.getline(zbor,100);//za vnesuvanje na zborovi vo niza
    l=Dolzina(zbor);
    cout<<"Dolzina na strigot e "<<l<<"\n";
    return 0;
}

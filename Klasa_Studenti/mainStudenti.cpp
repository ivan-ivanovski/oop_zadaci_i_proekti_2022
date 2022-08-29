#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;

class Student{
    private:
        string index;
        string ime; 
        string prezime;
        int poeni;
    public:
        Student(string index, string ime, string prezime, int poeni){
            this->index = index;
            this->ime = ime;
            this->prezime = prezime;
            this->poeni = poeni;
        }
        string setIme(string ime){
            this->ime = ime;
            return ime;
        }
        void getIme(string ime){
            cout<<"Ime : "<<ime<<endl;
        }

        void pecati(){
            cout<<"Index "<<index<<endl;
            cout<<"Ime "<<ime<<endl;
            cout<<"Prezime: "<<prezime<<endl;
        }
};

int main(){
    Student st1("202193", "Ivan", "Ivanovski", 30);
    string imeStd2 = "Boris", imeStd3;
    Student st2("20032", imeStd2, "IIII", 40);
    st1.pecati();
    st2.pecati();
    st2.getIme(imeStd2);
    cin>>imeStd3;
    Student st3("222", imeStd3, "mmms", 30);
    st3.getIme(imeStd3);
    cin.get();

}
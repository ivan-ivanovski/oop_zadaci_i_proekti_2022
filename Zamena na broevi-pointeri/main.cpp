#include <iostream>

using namespace std;
void Smeni(int *a,int *b){
    long t;
    t=*a;
    *a=*b;
    *b=t;
    cout<<"Ovaa se vrednosti od potprogramata "<<*a<<" "<<*b;

}

int main()
{
    int b1, b2;
    int *pb1=&b1,*pb2=&b2;
    cin>>b1>>b2;
    Smeni(pb1,pb2);
    cout<<"\nOvaa se vrednosti od main "<<b1<<" "<<b2;
}

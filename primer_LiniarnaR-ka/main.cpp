#include <iostream>
using namespace std;
int main(){
        float a,b,x;
        cin>>a>>b;
        if( (a!=0) && (b!=0)){
            x=(-b)/a;
            cout<<"Resenie na ravenkata e "<<x<<endl;
        }
        else if(a==0 && b!=0){
            cout<<"Ravenkata nema resenie"<<endl;
        }
        else{
            cout<<"Ravenkata ima beskonecno mnogu resenija ";
        }
        cin.get();

}

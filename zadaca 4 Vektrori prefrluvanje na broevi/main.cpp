#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main()
{
    vector <int> vek;
    deque <int> d;
    int i,broj,n;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>broj;
        vek.push_back(broj);
    }
    d.push_back(vek.back());
    vek.pop_back();
    while(vek.size()>0){
            if(vek.back()>d.back()){
                d.push_back(vek.back());
                vek.pop_back();
            }
            else
                vek.pop_back();

    }
    for(i=0;i<d.size();i++){
        cout<<d[i]<<" ";
    }

}

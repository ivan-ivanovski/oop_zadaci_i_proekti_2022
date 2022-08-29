#include <iostream>
#include<vector>
using namespace std;
int main()
{
    int i,n,broj,x;
    vector <int> v;
    cout<<"Kolku broja kje vnesete?"<<endl;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>broj;
        v.push_back(broj);
    }
    cout<<"Za kolku mesta da se napravi Shift Right?"<<endl;
    cin>>x;
	for(i=1;i<=x;i++){
	    int pom=v[n-1];
	    v.pop_back();
	    v.insert(v.begin(),pom);
	}


     for(i=0;i<n;i++)
    {
        cout<<v[i]<<endl;
    }


    return 0;
}


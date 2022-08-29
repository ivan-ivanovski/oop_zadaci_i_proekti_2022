#include <iostream>
#include <list>
using namespace std;

int main()
{
    list <int> l;
    list <int>::iterator it = l.begin(),  temp=l.begin();
    int i, n, broj;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>broj;
        l.push_back(broj);
    }

    for(i=0;i<n;i++){
        if(*it<=0){
            temp = it;
            it++;
            l.erase(temp);
        }
        else
            it++;

    }

    for(it=l.begin();it!=l.end();it++){
        cout<<*it<<"\t";
    }

    return 0;
}

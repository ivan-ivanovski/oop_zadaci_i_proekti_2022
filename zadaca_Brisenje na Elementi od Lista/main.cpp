#include <iostream>
#include <list>
using namespace std;

int main()
{
    list <int> l;
    list <int>::iterator it = l.begin();
    int i, n, poz, broj;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>broj;
        l.push_back(broj);
    }

    cin>>poz;
    for(i=0;i<=poz;i++){
        it++;
    }
    l.erase(it);

    for(it=l.begin();it!=l.end();it++){
        cout<<*it<<"\t";
    }

    return 0;
}

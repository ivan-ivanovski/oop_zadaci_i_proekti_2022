#include <iostream>
#include <list>
using namespace std;
int main()
{
    list <int> pozicija_na_eden;
    list <int> pozicii_na_duplikati;
    list <int>::iterator it_poz_eden=pozicija_na_eden.begin();
    list <int>::iterator it_poz_dup=pozicii_na_duplikati.begin();
    int broj, baran, n;
    cout<<"Vnesi go n: ";
    cin>>n;
    cout<<"Vnesi go brojot na koj sto sakate da ja doznaete pozicijata: ";
    cin>>baran;
    for(int i=0;i<n;i++){
        cout<<"Vnesi broj od poz {"<<i<<"} --> ";
        cin>>broj;
        pozicija_na_eden.push_back(broj);
        if(broj==baran){
            pozicii_na_duplikati.push_back(i);
        }
        it_poz_eden++;
        it_poz_dup++;
    }
    cout<<"Pozicija/i na brojot/evite e/se: "<<endl;
	for(int j=0;j<pozicii_na_duplikati.size();j++)
	{
		cout<<*it_poz_dup<<endl;
		it_poz_dup++;
	}

	return 0;

}

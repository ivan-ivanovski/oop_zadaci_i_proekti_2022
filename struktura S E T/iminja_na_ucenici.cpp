#include<iostream>
#include<set>
using namespace std;	
int main(){
	multiset<string> iminja;
	multiset<string>::iterator it = iminja.begin();
	int n, i, br=0;
	string ime,moe;
	cin>>n;
	for(i=0;i<n;i++,it++){
		cout<<"Vnesi go imeto na ucenikot:  ";
		cin>>ime;
		iminja.insert(ime);
	}
	
	for(it=iminja.begin();it!=iminja.end();it++){
		cout<<*it<<endl;
	}
	
	cout<<"Vase ime"<<endl;
	cin>>moe;
	it=iminja.find(moe);
    for(i=0;i<n;i++){
        if(it!=iminja.end()){
            it.count(moe);
        }
    }
	
	cout<<"Ima vkupno "<<it<<" iminja kako vasite"<<endl;

	return 0;
}
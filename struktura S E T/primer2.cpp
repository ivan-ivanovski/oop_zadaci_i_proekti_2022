#include<iostream>
#include<set>
using namespace std;
int main(){
	multiset <int> m;
	multiset <int>::iterator it=m.begin();
	
	cout<<"Primer za mnozestvo so duplikati - multiset "<<endl;
	cout<<"Vnesi gi 10te broevi na mnozestvoto"<<endl;
	for(int i=0;i<10;i++){
		int broj;
		cin>>broj;
		m.insert(broj);
	}
	cout<<"Mnozestvoto se sostoi od slednive broevi"<<endl;
	for(it=m.begin();it!=m.end();it++){
		cout<<*it<<"\t";
	}
	
	return 0;
}
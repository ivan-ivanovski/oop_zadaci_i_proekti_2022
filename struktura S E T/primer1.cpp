#include<iostream>
#include<set>
using namespace std;
int main(){
	set <int> s;
	set<int>::iterator it=s.begin();
	
	cout<<"Primer za mnozestvo - set"<<endl;
	cout<<"Vnesi gi 10te broevi na mnozestvoto"<<endl;
	for(int i=0;i<10;i++){
		int broj;
		cin>>broj;
		s.insert(broj);
	}
	cout<<"Mnozestvoto se sostoi od slednive broevi"<<endl;
	for(it=s.begin();it!=s.end();it++){
		cout<<*it<<"\t";
	}
	int broj;
	cout<<"\n Koj broj go baras "<<endl;
	cin>>broj;
	
	it=s.find(broj);
	if(it!=s.end()){
		cout<<"Go ima";
	}
	else{
		cout<<"Go nema"<<broj<<endl;
	}
	return 0;
}
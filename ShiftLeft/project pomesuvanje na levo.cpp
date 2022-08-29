///Shift Left-> nacin na koj  broevite se pomestuvaat na levo za edno mesto
#include<iostream>
#include<vector>

using namespace std;
int main(){
	cout<<"Popolni eden vektor so 10 broja."<<endl;
	vector<int> v;
	
	for(int i=0;i<10;i++){
		int broj;
		cin>>broj;
		v.push_back(broj);
	}
	int pom=v[0];
	v.erase(v.begin());
	v.push_back(pom);
	for(int i=0;i<10;i++){
		cout<<v[i]<<endl;
	}
	
	
	cin.get();
	cin.get();	
}

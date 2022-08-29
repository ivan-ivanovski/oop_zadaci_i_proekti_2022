/*
 	N planinari trgnale na pat. Sekoj so sebe ponel sise so 
	voda so razlicen volumen (prmer 0.5l, 1l, 2l). 
	Koga se kacile na vrvot imale ispieno voda i koga reseli da \
	se spustat resile ostanata voda da ja sobrat vo nekolku sisinja.
	Kolku najmalko sisinja kje im treba da ponesat odnosno da napolnat.
*/
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	cout<<"Kolku iznesuva brojot planinari (N), volumen na sekoe sise V[i], ispiena voda A[i]"<<endl;
	cout<<"Presmetaj kolku voda ostanalo i kolku najmalko sisinja se potrebni za nazad da se vrata"<<endl;
	int n,i,br=0;
	cin>>n;
	float V[n], A[n], razlika=0, zbir=0, zbir1=0, min=9999;
	for(i=0;i<n;i++){
		cin>>V[i]>>A[i];
	}
	cout<<"Ostanata voda"<<endl;
	for(i=0;i<n;i++){
		razlika=V[i]-A[i];
		zbir+=razlika;
	}
	sort(V,V+n);
	for(i=n-1;i>=0;i--){
		zbir1+=V[i];
		br++;
		if(zbir1 >= zbir)
		 break;
		else
		 continue;
	}
	
	cout<<endl<<zbir<<"l voda moze da se sobere vo"<<br<<endl;
	
	cin.get();
	cin.get();
	
}

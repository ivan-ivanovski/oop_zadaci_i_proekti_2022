#include <iostream>
#include <cstring>
using namespace std;
class Kukja{
	private:
		int masaDolzina;
		int masaShirina;
		int sobaDolzina, sobaShirina;
		string adresaKukja;
	public:
		Kukja(){};
		Kukja(int masaShirina, int masaDolzina, string adresaKukja,int sobaDolzina, int sobaShirina){
			this->masaShirina=masaShirina;
			this->masaDolzina=masaDolzina;
			this->sobaShirina = sobaShirina;
			this->sobaDolzina = sobaDolzina;
			this->adresaKukja = adresaKukja;			
		};
		
		void setAdr(string adresaKukja){
			this->adresaKukja = adresaKukja;
		}
		string getAdr(){
			return adresaKukja;
		}
		void setMasaDolzina(int masaDolzina){
			this->masaDolzina = masaDolzina;
		}
		int getMasaDolzina(){
			return masaDolzina;
		}
		
		void setMasaShirina(int masaShirina){
			this->masaShirina = masaShirina;
		}
		int getMasaShirina(){
			return masaShirina;
		}
		
		void setSobaShirina(int sobaShirina){
			this->sobaShirina = sobaShirina;
		}
		int getSobaShirina(){
			return sobaShirina;
		}
		void setSobaDolz(int sobaDolzina){
			this->sobaDolzina = sobaDolzina;
		}
		int getSobaDolzina(){
			return sobaDolzina;
		}
		void pecati(){
			cout<<"Adresa: "<<adresaKukja<<" Soba: "<<sobaShirina<<" "<<sobaDolzina<<" Masa: "<<masaShirina<<" "<<masaDolzina<<endl;
		}
		~Kukja(){};
		
};

void vnesiPodatoci(Kukja k[], int n){
	for(int i=0;i<n;i++){
		int dolz, shir;
		int sobaDolz;
		int sobaShir;
		string adresa;
		cin>>shir;
		k[i].setMasaShirina(shir);
		cin>>dolz;
		k[i].setMasaDolzina(dolz);
		cin>>sobaShir;
		k[i].setSobaShirina(sobaShir);
		cin>>sobaDolz;	
		k[i].setSobaDolz(sobaDolz);
		cin>>adresa;
		k[i].setAdr(adresa);
	}
}
int main() {
	Kukja k[100];
	int n;
	cout<<"Kolku podatoci kje vnesuvas: "<<endl;
	cin>>n;
	k[n];
	cout<<"Vnesi gi podatocite: "<<endl;
	vnesiPodatoci(k,n);
	
	for(int i=0;i<n;i++){
		k[i].pecati();
	}
	
	return 0;
}

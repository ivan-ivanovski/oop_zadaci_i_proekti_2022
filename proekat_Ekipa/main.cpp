#include <iostream>
#include <cstring>

class Ekipa{
private:
    ///Dinamicki alocirani nizi od tip char
    char *imeEkipa;
    char *imeStadion;
    char *grad;
    //metod za kopiranje, poednostavno i kodot e po pregleden
    void metodCopy(const Ekipa&ekipa){
        this->imeEkipa = new char [strlen(ekipa.imeEkipa)+1];
        strcpy(this->imeEkipa, ekipa.imeEkipa);
        this->imeStadion = new char [strlen(ekipa.imeStadion)+1];
        strcpy(this->imeStadion, ekipa.imeStadion);
        this->grad = new char [strlen(ekipa.grad)+1];
        strcpy(this->grad, ekipa.grad);
    }
    //metod za osloboduvnje na memorija
    void icistiMemorija(){
        delete [] imeEkipa;
        delete [] imeStadion;
        delete [] grad;
    }
public:
    Ekipa(char *imeEkipa = "", char *imeStadion="", char *grad=""){
        this->imeEkipa = new char [strlen(imeEkipa)+1];
        strcpy(this->imeEkipa, imeEkipa);
        this->imeStadion = new char [strlen(imeStadion)+1];
        strcpy(this->imeStadion, imeStadion);
        this->grad = new char [strlen(grad)+1];
        strcpy(this->grad, grad);
    }
    Ekipa(const Ekipa &ekipa){
        metodCopy(ekipa);
    }
    Ekipa &operator = (const Ekipa &ekipa){
        if(this!=&ekipa){
            icistiMemorija();
            metodCopy(ekipa);
        }
        return *this;
    }


    void pecatiEkipa(){
        std::cout<<"Ekipa ima: "<<imeEkipa<<" igra na stadion: "<<imeStadion<<" vo gradot: "<<grad<<std::endl;
    }

    ~Ekipa(){
        icistiMemorija();
    }
};

int main()
{
    int n;
    char ekipaIme[100];
    char ekipaStadion[100];
    char ekipaGrad[100];

    std::cout<<"Procitaj n: "<<std::endl;
    std::cin>>n;
    Ekipa *ekipi = new Ekipa[n];
    for(int i;i<n;i++){
        std::cin>>ekipaIme>>ekipaStadion>>ekipaGrad;
        ekipi[i] = Ekipa(ekipaIme, ekipaStadion, ekipaGrad);
    }
    for(int i;i<n;i++){
        ekipi[i].pecatiEkipa();
    }
    return 0;
}

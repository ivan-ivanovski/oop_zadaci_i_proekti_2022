#include <iostream>
#include <cstring>

using namespace std;

class Pica{

    char *nazivPica;
    char *picaSostojki;
    int cenaPica;
    int procent;


    void copyPica(const Pica &pica){
        this->nazivPica = new char[strlen(pica.nazivPica)+1];
        strcpy(this->nazivPica, pica.nazivPica);
        this->cenaPica = pica.cenaPica;
        this->picaSostojki = new char[strlen(pica.picaSostojki)+1];
        strcpy(this->picaSostojki, pica.picaSostojki);
        this->procent = pica.procent;
    }

public:

    Pica(char *nazivPica="", int cenaPica = 0, char *picaSostojki="", int procent=0){
        this->nazivPica = new char[strlen(nazivPica)+1];
        strcpy(this->nazivPica, nazivPica);
        this->cenaPica = cenaPica;
        this->picaSostojki = new char[strlen(picaSostojki)+1];
        strcpy(this->picaSostojki, picaSostojki);
        this->procent = procent;
    }

    Pica(const Pica &cpica){
        copyPica(cpica);
    }

    Pica &operator=(const Pica &pica){
        if(this!=&pica){
            delete[] picaSostojki;
            copyPica(pica);
        }
        return *this;
    }

    int getProcent(){
        return procent;
    }
    void setProcent(int procent){
        this->procent = procent;
    }
    bool istiSe(const Pica &pOther){
        return strcmp(this->picaSostojki, pOther.picaSostojki) == 0;
    }
    int promocialnaCena(){
        int promoCena = (cenaPica*procent)/100;
        return promoCena;
    }
    int poCena(){
        int poCena = cenaPica - promocialnaCena();
        return poCena;
    }
    void pecati(){
        if(procent > 0){
            cout<<nazivPica<<"-"<<picaSostojki<<", "<<cenaPica<<" "<<poCena()<<endl;
        }
        else{
            cout<<nazivPica<<"-"<<picaSostojki<<", "<<cenaPica<<"den"<<endl;
        }
    }
    ~Pica(){
        delete[] picaSostojki;
    }
};

class Picerija{
    char *picerijaIme;
    int nPici;
    Pica *pici;

    void copyPicerija(const Picerija &p){
        this->picerijaIme = new char[strlen(p.picerijaIme)+1];
        strcpy(this->picerijaIme, p.picerijaIme);
        this->nPici = p.nPici;
        pici = new Pica[this->nPici];
        for(int i=0;i<nPici;i++){
            pici[i] = p.pici[i];
        }
    }
    void freeMem(){
        delete[] pici;
        delete[] picerijaIme;

    }


public:
    Picerija(char *picerijaIme=""){
        this->picerijaIme = new char[strlen(picerijaIme)+1];
        strcpy(this->picerijaIme, picerijaIme);
        nPici = 0;
        pici = new Pica[nPici];
    }

    Picerija(const Picerija &pCopy){
        copyPicerija(pCopy);
    }

    Picerija &operator=(const Picerija &picerija){
        if(this!=&picerija){
            freeMem();
            copyPicerija(picerija);
        }
        return *this;
    }

    bool postoiPica(const Pica& pica){
        bool postoiPica = false;
        for(int i=0;i<nPici;i++){
            if(pici[i].istiSe(pica)){
                postoiPica = true;
                break;
            }
        }
        return postoiPica;
    }

    void dodadi(const Pica& pica){
        if(postoiPica(pica)){
            return;
        }
        Pica *tmp = new Pica[nPici+1];
        for(int i=0;i<nPici;i++){
            tmp[i] = pici[i];
        }
        tmp[nPici++] = pica;
        delete[] pici;
        pici = tmp;

    }

    void piciNaPromocija(){
        //cout<<"Picerija: "<<picerijaIme<<endl;
        for(int i=0;i<nPici;i++){
            if((pici[i].getProcent()) > 0){
                pici[i].pecati();
            }
        }
    }

    void setIme(char *picerijaIme){
        if(this->picerijaIme)
            delete [] this->picerijaIme;

        this->picerijaIme = new char[strlen(picerijaIme)+1];
        strcpy(this->picerijaIme, picerijaIme);
    }

    const char* getIme() const{
        return picerijaIme;
    }

    ~Picerija(){
        freeMem();
    }
};
//Vasiot kod tuka

int main () {
    int n;
    char ime[15];
    cin>>ime;
    cin >> n;

    Picerija p1(ime);
    for(int i = 0; i < n; i++){
        char imp[100];
        cin.get();
        cin.getline(imp,100);
        int cena;
        cin >> cena;
        char sostojki[100];
        cin.get();
        cin.getline(sostojki,100);
        int popust;
        cin >> popust;
        Pica p(imp,cena,sostojki,popust);
        p1.dodadi(p);
    }

    Picerija p2 = p1;
    cin >> ime;
    p2.setIme(ime);
    char imp[100];
    cin.get();
    cin.getline(imp,100);
    int cena;
    cin >> cena;
    char sostojki[100];
    cin.get();
    cin.getline(sostojki,100);
    int popust;
    cin >> popust;
    Pica p(imp,cena,sostojki,popust);
    p2.dodadi(p);

    cout<<p1.getIme()<<endl;
    cout<<"Pici na promocija:"<<endl;
    p1.piciNaPromocija();

    cout<<p2.getIme()<<endl;
    cout<<"Pici na promocija:"<<endl;
    p2.piciNaPromocija();


	return 0;
}
/**
    Pica pica1("Kapricioza", 210, "domat, kaskaval, pecurki, kulen", 30);
    pica1.pecati();
    Pica pica2("Kapricioza", 250, "domat, kaskaval, pecurki, kulen, macarela", 0);
    pica2.pecati();
    if(!pica1.istiSe(pica2)){
        cout<<"Ne se isti"<<endl;
    }
    else{
        cout<<"Isti se"<<endl;
    }
    Picerija picerija1("Deflagiono");
    picerija1.dodadiPica(pica1);
    picerija1.dodadiPica(pica2);
    picerija1.pecatiPicerija();
    */
/*

           bool seNaPromocija(const Pica &promocialnaPica){
            bool promocija = false;
            for(int i=0;i<nPici;i++){
                if(promocialnaPica)
            }

        }

*/

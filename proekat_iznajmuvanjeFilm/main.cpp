#include <iostream>
#include <cstring>
#include <vector>
class DatumIznajmuvanje{
    int mesec;
    int den;
    const int godina = 2022;


    void copyDate(const DatumIznajmuvanje &date){
        this->den = date.den;
        this->mesec =date.mesec;
    }

    bool proveriDatum(const DatumIznajmuvanje &date){
        bool tocen = true;
        if(date.den<0 || date.den > 31){
            std::cout<<"Datum na iznajmuvanje ne e tocno vnesen"<<std::endl;
            tocen = false;
        }
        else if(date.mesec<=0 || date.mesec >12){
            std::cout<<"Datum na iznajmuvanje ne e tocno vnesen"<<std::endl;
            tocen = false;
        }
        else return tocen=1;
    }

    void PrintDatum(){
        std::cout<<"Godina na iznajmuvanje: "<<den<<"."<<mesec<<"."<<godina<<std::endl;
    }
public:
     DatumIznajmuvanje(int den = 1, int mesec = 1, const int godina = 2022){
        this->den = den;
        this->mesec = mesec;
    }

    DatumIznajmuvanje(const DatumIznajmuvanje &dt){
        copyDate(dt);
    }

    DatumIznajmuvanje &operator = (const DatumIznajmuvanje &dt){
        if(this!=&dt){
            copyDate(dt);
        }
        return *this;
    }

    void postoiDatum(const DatumIznajmuvanje &dt){
        if(!proveriDatum(dt)){
            return;
        }
        else{
            PrintDatum();
        }
    }

    ~DatumIznajmuvanje(){}
};

class FilmInfo{
    char* str_nazivFilm;
    char* str_imeAvtor;
    char* str_contentFilm;
    int godinaP;

    void oslobodiMemorija(){
        delete[] str_nazivFilm;
        delete[] str_imeAvtor;
        delete[] str_contentFilm;
    }

    void copy_FilmInfo(const FilmInfo& film_info){
        this->str_nazivFilm = new char[strlen(film_info.str_nazivFilm)+1];
        strcpy(this->str_nazivFilm, film_info.str_nazivFilm);
        this->str_imeAvtor = new char[strlen(film_info.str_imeAvtor)+1];
        strcpy(this->str_imeAvtor, film_info.str_imeAvtor);
        this->str_contentFilm = new char[strlen(film_info.str_contentFilm)+1];
        strcpy(this->str_contentFilm, film_info.str_contentFilm);
        this->godinaP = film_info.godinaP;
    }



public:

    FilmInfo(char *str_nazivFilm = "nepoznat", char *str_imeAvtor ="nepoznato", char *str_contentFilm ="deskripcija", int godinaP = 1990){
        this->str_nazivFilm = new char[strlen(str_nazivFilm)+1];
        strcpy(this->str_nazivFilm, str_nazivFilm);
        this->str_imeAvtor = new char[strlen(str_imeAvtor)+1];
        strcpy(this->str_imeAvtor, str_imeAvtor);
        this->str_contentFilm = new char[strlen(str_contentFilm)+1];
        strcpy(this->str_contentFilm, str_contentFilm);
        this->godinaP = godinaP;
    }

    FilmInfo(const FilmInfo &film_info){
        copy_FilmInfo(film_info);
    }

    FilmInfo &operator =(const FilmInfo& fi){
        if(this!=&fi){
            oslobodiMemorija();
            copy_FilmInfo(fi);
        }
        return *this;
    }

    friend std::istream & operator>>(std::istream &inp, const FilmInfo &fi){
        inp>>fi.str_nazivFilm>>fi.str_imeAvtor>>fi.str_contentFilm;
        return inp;
    }

    bool istiSe(const FilmInfo &finf){
        return strcmp(this->str_nazivFilm, finf.str_nazivFilm)==0;
    }


    void setGodinaP(int godinaP){
        this->godinaP = godinaP;
    }

    int getGodinaP(){
        return godinaP;
    }

    void setNazivFilm(char *str_nazivFilm){
        this->str_nazivFilm = new char[strlen(str_nazivFilm)+1];
        strcpy(this->str_nazivFilm, str_nazivFilm);
    }
    char getNazivFilm(){
        return *str_nazivFilm;
    }
    void setAvtorFilm(char *str_imeAvtor){
        this->str_imeAvtor= new char[strlen(str_imeAvtor)+1];
        strcpy(this->str_imeAvtor, str_imeAvtor);
    }

    char getImeAvtor(){
        return *str_imeAvtor;
    }

    void setContentFilm(char *str_contentFilm){
        this->str_contentFilm= new char[strlen(str_contentFilm)+1];
        strcpy(this->str_contentFilm, str_contentFilm);
    }

    char getContentFilm(){
        return *str_contentFilm;
    }


    void pecatiInfoFilm(){
        std::cout<<"Naziv film: "<<str_nazivFilm<<std::endl;
        std::cout<<"Avtor film: "<<str_imeAvtor<<std::endl;
        std::cout<<"Deskripcija film: "<<str_contentFilm<<std::endl;
        std::cout<<"Godina: "<<godinaP<<std::endl;

    }
    ~FilmInfo(){
        oslobodiMemorija();
        ///std::cout<<"Memorija sega e oslobodena"<<std::endl;
    }

};

class FilmShop{
    char *str_imeShop;
    int n;
    FilmInfo *filmovi;

    void copyFilmShop(const FilmShop &fs){
        this->str_imeShop = new char[strlen(fs.str_imeShop)+1];
        strcpy(this->str_imeShop, fs.str_imeShop);
        this->n = fs.n;
        filmovi = new FilmInfo[this->n];
        for(int i=0;i<n;i++){
            filmovi[i] = fs.filmovi[i];
        }
    }

    void oslobodiMemorija(){
        delete[] filmovi;
        delete[] str_imeShop;
    }

public:

    FilmShop(char *str_imeShop = "shop_ime"){
        n=0;
        this->str_imeShop = new char[strlen(str_imeShop)+1];
        strcpy(this->str_imeShop, str_imeShop);
        filmovi = new FilmInfo[n];
    }

    FilmShop(const FilmShop &fs){
        copyFilmShop(fs);
    }

    FilmShop &operator =(const FilmShop &fs){
        if(this!=&fs){
            oslobodiMemorija();
            copyFilmShop(fs);
        }
        return *this;
    }


    void dodajFilmZaIznajmuvanje(const FilmInfo &film){
        if(postoiFilm(film)){
            return;
        }
        FilmInfo *tmpFilm = new FilmInfo[n+1];
        for(int i=0;i<n;i++){
            tmpFilm[i] = filmovi[i];
        }
        tmpFilm[n++] = film;
        delete[] filmovi;
        filmovi = tmpFilm;

    }

    bool postoiFilm(const FilmInfo &finf){
        bool postoi = false;
        for(int i=0;i<n;i++){
            if(filmovi[i].istiSe(finf)){
                postoi = true;
                break;
            }
        }
        return postoi;
    }

    void izbrisiFilm(const FilmInfo &finf){
        if(postoiFilm(finf)){
            FilmInfo *tmp = new FilmInfo[n-1];
            for(int i=0,j=0;i<n;i++){
                if(!filmovi[i].istiSe(finf)){
                    tmp[j++]=filmovi[i];
                }

            }
            n--;
            delete[] filmovi;
            filmovi = tmp;
        }

    }

    void pecatiFilmShop(){
        std::cout<<"Ime na kompanija: "<<str_imeShop<<std::endl;
        for(int i=0;i<n;i++){
            filmovi[i].pecatiInfoFilm();
        }
    }

    ~FilmShop(){
        oslobodiMemorija();
    }
};

struct Iznajmuvac{
    char *ime;
    char *brojNaLicnaKarta;
    char *grad;
    int vozrast;

    void freeMemory(){
        delete[] ime;
        delete[] brojNaLicnaKarta;
        delete[] grad;

    }


    void proveriVozrast(int vozrast){
        bool soodveten = false;
        if(vozrast >= 18){
            std::cout<<"Moze da go iznajmi ovoj zanr na film"<<std::endl;
            soodveten = true;
        }
        if(vozrast < 18){
            std::cout<<"Ne moze da se iznajmi ovoj zanr na film na lice pomalo od 18 godini"<<std::endl;
            soodveten = false;
        }
    };


    Iznajmuvac(char *ime="", char*brojNaLicnaKarta="", char *grad="", int vozrast = 0){
        this->ime = new char[strlen(ime)+1];
        strcpy(this->ime, ime);
        this->brojNaLicnaKarta = new char[strlen(brojNaLicnaKarta)+1];
        strcpy(this->brojNaLicnaKarta, brojNaLicnaKarta);
        this->grad = new char[strlen(grad)+1];
        strcpy(this->grad, grad);
        this->vozrast = vozrast;

    };

    void print(){
        std::cout<<"Ime : "<<ime<<std::endl;
        std::cout<<"Broj na licna karta: "<<brojNaLicnaKarta<<std::endl;
        std::cout<<"Grad: "<<grad<<std::endl;
        std::cout<<"Vozrast: "<<vozrast<<std::endl;
    }
};


int main()
{

    Iznajmuvac lice1;
    char kompanijaIme[50];
    int n;
    char imeF[50], contentF[50], avtorF[50]; int godF;
    std::cout<<"Iznajmuvanje na film"<<std::endl;
    std::cout<<"---------------------------------------"<<std::endl;
    std::cout<<"Vnesi ime na kompanija od koja se iznajmuva film: "<<std::endl;
    std::cin.getline(kompanijaIme,50);
    FilmShop kompanija1(kompanijaIme);
    kompanija1.pecatiFilmShop();
    std::cout<<"---------------------------------------"<<std::endl;
    std::cout<<"Vnesi detali za iznajmuvac na film: "<<std::endl;
    std::cout<<"---------------------------------------"<<std::endl;
    std::cout<<"Ime: ";std::cin>>lice1.ime;
    std::cout<<"Broj na licna karta: ";std::cin>>lice1.brojNaLicnaKarta;
    std::cout<<"Grad: ";std::cin>>lice1.grad;
    std::cout<<"Vozrast: ";std::cin>>lice1.vozrast;
    std::cout<<"---------------------------------------"<<std::endl;
    std::cout<<"Vneseni informacii za iznajmuvac"<<std::endl;
    lice1.print();
    std::cout<<"Kolku filma liceto kje iznajmi: ";std::cin>>n;
    FilmInfo filmovi1[n];
    std::cout<<"Vnesi podatoci za filmovi sto gi iznajmuva"<<std::endl;
    for(int i=0;i<n;i++){
        std::cout<<"Naziv: ";
        std::cin>>imeF;
        filmovi1[i].setNazivFilm(imeF);
        std::cout<<"Avtor: ";
        std::cin>>avtorF;
        filmovi1[i].setAvtorFilm(avtorF);
        std::cout<<"Content: ";
        std::cin>>contentF;
        filmovi1[i].setContentFilm(contentF);
        std::cout<<"Godina: ";
        std::cin>>godF;
        filmovi1[i].setGodinaP(godF);
    }
    for(int i=0;i<n;i++){
        filmovi1[i].pecatiInfoFilm();
    }
    /*
    DatumIznajmuvanje df1(24, 03, 2021);
    FilmInfo f1("Matrix", "Nemampojma", "Fantasticen film", 2002);
    //f1.pecatiInfoFilm();
    FilmInfo f2("MatrixII", "Nemampojma", "Fantasticen film", 2002);
   // f2.pecatiInfoFilm();
    FilmShop fshop1("Kompanija 1");
    std::cout<<"--------------------------"<<std::endl;
    fshop1.dodajFilmZaIznajmuvanje(f1);
    fshop1.dodajFilmZaIznajmuvanje(f2);
    fshop1.pecatiFilmShop();
    df1.postoiDatum(df1);

    std::cout<<"--------------------------"<<std::endl;
    std::cout<<"Brisenje na prv dodaden film"<<std::endl;
    std::cout<<"--------------------------"<<std::endl;
    fshop1.izbrisiFilm(f1);
    fshop1.pecatiFilmShop();
    df1.postoiDatum(df1);



    std::cout<<f1.istiSe(f2)<<std::endl;
    */

    return 0;
}

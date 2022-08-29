#include <iostream>
#include <cstring>
//Klasa webStrana
class WebStrana{
private:
    char urlStranica[100];// ovaa e url na edna strana niza od 100 znaci
    char *content;//dinamicka niza za content na stranica ( prototip char * ime);
    //void metoda vo privatna sekcija so koja povikuva pri kreiranje na copy constructor i preoptovaruvanje na operator =
    //slicna struktura so 2vo1 konstruktori
    void copyWebStranica(const WebStrana &wp){
        strcpy(this->urlStranica, wp.urlStranica);
        this->content = new char[strlen(wp.content)+1];
        strcpy(this->content, wp.content);
    }
public:
    //2vo1 konstruktor, t.e parametarski i default konstrukt
    WebStrana(char *urlStranica="https://www.finki.ukim.mk", char *content ="Web sajt na FINKI"){
        strcpy(this->urlStranica, urlStranica);//strcpy metoda so koja se prekopira sodrzina od eden string vo nov
        this->content = new char[strlen(content)+1];//nacin na koj se kreira dinamicka niza od znaci, zbor new kako nova niza od znaci,
         strcpy(this->content, content);//strlen dolzina na string  i potoa se korist strcpy metod
    }
    //copy-costruktor
    WebStrana(const WebStrana& wp){
        copyWebStranica(wp
    }
    //preoptovaruvanje na operatori ( za obicni operatori imeNaKlasa operator operatoStoSeOptovaruva(const imeNaKlasa &iK){...}
    WebStrana & operator=(const WebStrana& wpe){
        if(this!=&wpe){
            delete []content;
            copyWebStranica(wpe);
        }
        return *this;
    }
    //bool metoda so koja se proveruva dali vneseni stranici imaat ista url ako imaat se vrakja 1 ili true ili 0 ako nema
    bool istiSe(const WebStrana &wp){
        return strcmp(this->urlStranica, wp.urlStranica)==0;
    }
    //void funkcija za pecati
    void printStranica(){
        std::cout<<urlStranica<<" "<<content<<std::endl;
    }
    //de konstruktnor
    ~WebStrana(){
        delete []content;//brisenje i osloboduvanje objekti od memomorija samo ako imame dinamicki alocirana niza
    }
};
class WebServer{
    char ime[30];
    WebStrana *webStranici;//dinamicka niza od stranica
    int golemina;
    //metoda copy
    void copyWebServer(const WebServer &wserver){
        strcpy(this->ime, wserver.ime);
        this->golemina = wserver.golemina;
        webStranici = new WebStrana[this->golemina];
        for(int i=0;i<this->golemina;i++){
            this->webStranici[i] = wserver.webStranici[i];
        }
    }
public:
    //2vo1 konst, inicializiranje na promenlvi
    WebServer(char *ime = "server"){
        golemina = 0;
        strcpy(this->ime,ime);
        webStranici = new WebStrana[golemina];//kreiranje na dinamicna niza od objekti od tip na klasa WebStrana zavisno od golemina ili ti N,
    }
    //kopi konstruktor
    WebServer (const WebServer &ws){
        copyWebServer(ws);
    }
    //preoptovaruvanje na operator =
    WebServer &operator=(const WebServer &ws){
        if(this!=&ws){
            delete [] webStranici;
            copyWebServer(ws);
        }return *this;
    }
    //dodavanje na nova stranica, se proveruva dali postoi stranica so ist url, ako postoi ne se izvrusuvaa metoda za tekovna strana
    void dodajStranica(const WebStrana & wstrana){
        if(postoiStranica(wstrana)){
            return;
        }
        //Dodavanje na stranica dokolku ne postoi so toa kreirame temp niza;
        WebStrana *tmp = new WebStrana[golemina+1];
        for(int i=0;i<golemina;i++){
            tmp[i] = webStranici[i];///kje padne ako nema operator =, prebacuvanje na stranici i dodavanje na novi
        }
        tmp[golemina++] = wstrana;
        delete [] webStranici;//Mora da se izbirasat tekovna niza od strani
        webStranici = tmp;
    }
    //metod so koj se proveruva dali postoi stranica so koristenja na metoda istiSe od klasa WebStrana, prima argument od klasa WebStrana
    bool postoiStranica(const WebStrana &ws){
        bool postoi = false;
        for(int i=0;i<golemina;i++){
            if(webStranici[i].istiSe(ws)){
                postoi=true;
                break;//ako se naide na dve isti strani se prekenuva
            }
        }
        return postoi;
    }
    //brisenje metod, prima argument referenca od WebStrana, ako postoi stranica sto sakame da se izbrise, proveruvame,
    void izbrisiStranica(const WebStrana &ws){
        if(postoiStranica(ws)){
            WebStrana *tmp = new WebStrana[golemina-1];//tmp niza kade golemina e -1
            for(int i=0, j=0;i<golemina;i++){
                if(!webStranici[i].istiSe(ws)){
                    tmp[j++]= webStranici[i];
                }
            }
            golemina--;//namaluvanje na golemina za eden
            delete[] webStranici; //brisenje
            webStranici = tmp;//primanje
        }
    }
    ///pecatenje
    void printWebServer(){
        std::cout<<ime<<std::endl;
        for(int i=0;i<golemina;i++){
            webStranici[i].printStranica();
        }
    }

    ~WebServer(){
        delete[] webStranici;
    }
};
//main funkcija i nacin na implemtiranje
int main()
{
    WebStrana ws1;
    WebStrana wsc(ws1);

    ws1.printStranica();
    wsc.printStranica();

    std::cout<<ws1.istiSe(wsc)<<std::endl;

    WebStrana ws2("www.ivanovskiivan.finki.edu.mk","mySite");

    WebServer wserver1("FINKI");

    wserver1.dodajStranica(ws1);
    wserver1.dodajStranica(ws2);

    wserver1.printWebServer();

    wserver1.izbrisiStranica(wsc);
    wserver1.printWebServer();
    return 0;
}

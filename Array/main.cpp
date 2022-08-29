#include <iostream>

using namespace std;

class Array{
private:
    int *a;
    int n; //kolku elementi ima
    int c; //maksimalna dolzina
public:
    Array(int c=5){ //int a[5], prazna niza na elementi
        a = new int[c];
        this->c = c;
        n = 0;
    }
    //Copy Constructor
    Array (const Array &obj){
        a = new int[obj.c];
        c = obj.c;
        n = obj.n;
        for(int i=0;i<n;i++){
            a[i] = obj.a[i];
        }
    }

    Array &operator= (const Array &obj){
        if(this == &obj){ return *this; }//se sprecuva samododeluvanje, odnosno ako imame se pecati toa
        delete[] a; //brisenje na se vo a
        a = new int [obj.c];
        c = obj.c;
        n = obj.n;
        for(int i=0;i<n;i++){
            a[i] = obj.a[i];
        }
        return *this;
    }

    void add(int element){
        if(c == n){ // kje mora niza da se zgolemi, poslem da se dodade nov element
            cout<<"Se menuvaa kapacitet na tekovna niza \n";
            int *pom = new int[2*c];
            for(int i =0;i<n;i++){
                pom[i] = a[i];
            }
            delete [] a;
            a = pom;
            //promena na kapacitet
             c=2*c;

        }
        a[n] = element;
        n++;
    }

    void change(int A, int B){
        for(int i=0;i<n;i++){
            if(a[i] == A){
                a[i] =B;
            }
        }
    }
    void delAll(int elem){
        int new_n= 0;
        //pomestuvanje za edno mesto levo
        for(int i=0, k=0;i<n;i++){
            if(a[i] != elem){
                a[k] = a[i];
                k++;
                new_n ++;
            }
        }
        n = new_n;
    }
    void print(){
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }

    ~Array(){
        delete []a;

    }
};
int main()
{
    Array a;
    Array al(100);
    a.add(0);
    a.add(1);
    a.add(10);
    a.add(100);
    a.add(1000);
    a.print();
    Array a_copy(a);
    a_copy.print();
    al = a;
    al.print();
    a.add(10);
    a.print();
    a.change(10,5);
    a.print();
    a.delAll(5);
    a.print();
    return 0;
}

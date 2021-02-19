#include <iostream>

using namespace std;

class Kare{
public:
    Kare(string birim= "cm2"){
        cout << "Parametresiz Yapici Calisti" << endl;
    }
    virtual void mesaj() = 0;
    void alan(int _kenar){
        this -> kenar = _kenar;
        sonuc = (_kenar * _kenar);
    }
    void kenar_uzunluk(int _kenar1){
        this-> kenar = _kenar1;
        sonuc = 4 * _kenar1;
    }
    void print(){
        cout << sonuc << " " << birim << endl;
    }
    ~Kare(){
        cout << "Yikici Calisti" << endl;
    }
protected:
    int kenar;
    int sonuc;
    string birim;
};

class DikUcgen:public Kare{
public:
    DikUcgen(){
        cout << "Parametresiz Yapici Calisti" << endl;
        birim = "cm2";
    }
     void mesaj(){
        cout << "Nasilsin" << endl;
    }
    void alan(int _dikey,int _yatay){
        this -> dikey = _dikey;
        this -> yatay = _yatay;
        sonuc= (_dikey*_yatay)/2;
    }
    ~DikUcgen(){
        cout <<"Yikici Calisti" << endl;
    }
protected:
    int dikey;
    int yatay;
};

class Daire:public Kare{
public:
    Daire(){
        cout << "Parametresiz Yapici Calisti" << endl;
        birim = "cm2";
    }
    void mesaj(){
        cout << "Tamam" << endl;
    }
    void alan(int _r){
        this -> r = _r;
        sonuc= pi * r * r;
    }
    ~Daire(){
        cout <<"Yikici Calisti" << endl;
    }
protected:
    float pi = 3.14;
    int r;
};

int main()
{
   Kare *dizi[2];
   dizi[0] = new DikUcgen();
   dizi[1] = new Daire();
   for(int i=0;i<2;i++){
    dizi[i]->mesaj();
   }
}


#include <iostream>

using namespace std;

class Dikdortgen{
public:
    Dikdortgen(double uKenar = 5,double kKenar=10){
        this -> uzunkenar = uKenar;
        this -> kisakenar = kKenar;
        cout << "Yapici Calisti" << endl;
    }
    void setKisa(double kisa){
        kisakenar = kisa;
    }
    double getKisa(double kisa){
        return kisakenar;
    }
    void setUzun(double uzun){
        uzunkenar = uzun;
    }
    double getUzun(double uzun){
        return uzunkenar;
    }
    double Alan(double uKenar,double kKenar){
        this -> uzunkenar = uKenar;
        this -> kisakenar = kKenar;
        sonuc = uKenar * kKenar;
        return sonuc;
    }
    double Cevre(double uKenar,double kKenar){
        this -> uzunkenar = uKenar;
        this -> kisakenar = kKenar;
        sonuc = 2*kKenar + 2*uKenar;
        return sonuc;
    }
    void printf(){
        cout <<"Sonuc = " << sonuc << endl;
    }
    ~Dikdortgen(){
        cout << "Yikici Calisti"<< endl;
    }

protected:
    double sonuc;
    double uzunkenar;
    double kisakenar;
};

class Kare:public Dikdortgen{
public:
    Kare(double kKenar = 10){
        cout << "Yapici Calisti"<< endl;
    }

    double Alan(double kKenar){
        sonuc = kKenar * kKenar;
        return sonuc;
    }
    double Cevre(double kKenar){
        sonuc = 4*kKenar;
        return sonuc;
    }
    ~Kare(){
        cout << "Yikici Calisti"<< endl;
    }
};

class Daire:public Dikdortgen{
public:
    Daire(double Yaricap = 10){
        cout << "Yapici Calisti"<< endl;
    }
    double Alan(double Yaricap){
        sonuc = pi*Yaricap*Yaricap;
        return sonuc;
    }
    double Cevre(double Yaricap){
        sonuc = 2*pi*Yaricap;
        return sonuc;
    }
    ~Daire(){
        cout << "Yikici Calisti"<< endl;
    }

private:
    double pi = 3.14;
    double r;
};



int main()
{
    Dikdortgen dikdortgen;
    dikdortgen.setKisa(5);
    dikdortgen.setUzun(6);
    dikdortgen.Alan(7,8);
    dikdortgen.printf();
}

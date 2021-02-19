#include <iostream>
#include <stdlib.h>
#include <time.h>
#define row 10
#define column 10

using namespace std;

class Matris{
public:
    Matris(){
        this -> r = 10;
        this -> c = 10;
        this -> deger = 0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cout << deger;
            }cout << endl;
        }
    }
    Matris(int _r1,int _c1,int _deger){
        this -> r = _r1;
        this -> c = _c1;
        this -> deger = _deger;
        if(_deger == 1 || _deger == 9){
        for(int i=0;i<_r1;i++){
            for(int j=0;j<_c1;j++){
                cout << _deger;
            }cout << endl;
        }
        }
        else if(_deger == 'e'){
            for(int i=0;i<_r1;i++){
                for(int j=0;j<_c1;j++){
                    if(i == j){
                            cout << 1;
                    }
                    else {
                            cout << 0;
                    }
                }cout << endl;
            }
        }
        else if(_deger == 'r'){
            srand (time(NULL));
        for(int i=0;i<_r1;i++){
            for(int j=0;j<_c1;j++){
                cout << rand()% 255 << " " ;
            }cout << endl;
            }
        }
}


private:
    int deger;
 //   char birim;
  //  string random;
    int r;
    int c;
};
int main()
{
    Matris *m1,*m2,*m3,*m4;
    m1 = new Matris();
    m2 = new Matris(3,2,1);
    m2 = new Matris(3,4,9);
    m3 = new Matris(5,5,'e');
    m4 = new Matris(15,15,'r');
 //   m2 -> resize(5,5);
}
/*
    Matris(int _r2,int _c2,char _birim){
            this -> r = _r2;
            this -> c = _c2;
            this -> birim = _birim;
            for(int i=0;i<_r2;i++){
                for(int j=0;j<_c2;j++){
                    if(i == j){
                            cout << 1;
                    }
                    else {
                            cout << 0;
                    }
                }cout << endl;
            }
        }
    Matris(int _r3,int _c3,string _random){
        this -> r = _r3;
        this -> c = _c3;
        this -> random = _random;
        srand (time(NULL));
        for(int i=0;i<_r3;i++){
            for(int j=0;j<_c3;j++){
                cout << rand()% 255 << " " ;
            }cout << endl;
        }
     }
     void resize(int n_r,int n_c){
        this -> r = n_r;
        this -> c = n_c;
     }
     */

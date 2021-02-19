#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <iomanip>
#define satir 20
#define sutun 20

using namespace std;

template <class Tip>
class Matris{
public:
    Matris<Tip>(int _r1=10,int _c1=10,int _deger=0){ //Parametresiz Yapýcý icin Default degerler
        cout << "Parametreli Yapici Calisti" << endl;
        this -> r = _r1;
        this -> c = _c1;
        this -> deger = _deger;
        bellek_tamsayi();
        if(_deger >= 0 && _deger <= 99){ //Int degerler icin
            for(int i=0;i<_r1;i++){
                for(int j=0;j<_c1;j++){
                    matris[i][j] = _deger;
                }
            }
        }

           else if(_deger == 'e'){ //Birim matris icin
                for(int i=0;i<_r1;i++){
                    for(int j=0;j<_c1;j++){
                        if(i == j){
                              matris[i][j] = 1;
                        }
                        else {
                              matris[i][j] = 0;
                        }
                    }
                }
            }
            else if(_deger == 'r'){ //random degerli matris icin
                srand (time(NULL));
                for(int i=0;i<_r1;i++){
                    for(int j=0;j<_c1;j++){
                        matris[i][j] = rand() % 255;
                    }
                    }
            }
    }

    void setRowColumnDeger(int _r,int _c,int _deger){ //3 parametreli set edici fonksiyon
      r  = _r;
      c  = _c;
      deger = _deger;
    }

    void getRowColumnDeger(int &_r,int &_c,int &_deger){ //3 parametreli get edici fonksiyon
      _r = r;
      _c = c;
      _deger = deger;
    }

     Matris<Tip> operator +(const Matris &nesne)const  //2 Matrisi Vektorel Toplar.
{
    Matris t;
         for(int i=0;i<r;i++){
             for(int j=0;j<c;j++){
                 t.matris[i][j] = nesne.matris[i][j] + matris[i][j];
             }
         }
    return t;
}

    Matris<Tip> operator +(const int toplam)const  // Matris ve Int Degeri Skaler Toplar.
{
    Matris t;
         for(int i=0;i<r;i++){
             for(int j=0;j<c;j++){
                 t.matris[i][j] =matris[i][j] + toplam ;
             }
         }
    return t;
}

    Matris<Tip> operator -(const Matris &nesne)const //2 Matrisi Vektorel Cikarir.
{
    Matris t;
         for(int i=0;i<r;i++){
             for(int j=0;j<c;j++){
                 t.matris[i][j] = matris[i][j] - nesne.matris[i][j];
         }
        }
      return t;
}

    Matris<Tip> operator -(const int cikar)const // Matris ve Int Degeri Skaler Cikarir.
{
    Matris t;
         for(int i=0;i<r;i++){
             for(int j=0;j<c;j++){
                 t.matris[i][j] = matris[i][j] - cikar;
             }
         }
      return t;
}

    Matris<Tip> operator *(const Matris &nesne)const //2 Matrisi Vektorel Carpar.
{
    Matris t;
    int toplam;
    for(int a=0;a<r;a++)
    {
        for(int x=0;x<c;x++)
        {
            toplam=0;
            for(int b=0;b<c;b++)
            {
                toplam+=matris[a][b]*nesne.matris[b][x];
            }
                t.matris[a][x]=toplam;
        }
    }
    return t;
}

    Matris<Tip> operator *(const int carp)const //Matris ve Int Degeri Skaler Carpar.
{
    Matris t;
    for(int i=0;i<r;i++)
             for(int j=0;j<c;j++)
                 t.matris[i][j] = matris[i][j] * carp;
    return t;
}

    Matris<Tip> operator %(const int mod_al)const //Matrisin Elemanlarinin Modunu Alir.
{
    Matris t;
         for(int i=0;i<r;i++){
             for(int j=0;j<c;j++){
                 t.matris[i][j] = matris[i][j] % mod_al;
             }
         }
      return t;
}
 /*  Matris operator ^(const int us_al)const //Matrisin Elemanlarinin Ussunu Alir.
{
    Matris t;
         for(int i=0;i<r;i++){
             for(int j=0;j<c;j++){
                    for(int m=0;m<us_al;m++){
                        t.matris[i][j] *= matris[i][j] ;
                    }
         }
      return t;
    }
}*/

    void resize(int yeni_r,int yeni_c){ // Yeniden boyutlandýrma fonksiyonu
        this -> r = yeni_r;
        this -> c = yeni_c;
        for(int t=0;t<yeni_r;t++){
            for(int k=0;k<yeni_c;k++){
                matris[t][k];
            }
        }
    }
    void emul(Matris &nesne){
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                this->matris[i][j] = this->matris[i][j] * nesne.matris[i][j];
            }
        }
    }

    void T(){ //Matrisin Transpozunu alan fonksiyon
       Matris<Tip> t;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
               t.matris[j][i] = matris[i][j];
            }
        }
        cout << "Matrisin Transpozu" << endl;
        for(int i=0;i<c;i++){
            for(int j=0;j<r;j++){
               cout << t.matris[i][j] << " ";
            }cout << endl;
        }cout << endl;
    }
    void det() {
      int det=0,toplanan=0,cikarilan=0;
      if (r == c)
      {
          if(r == 2){
          det=matris[0][0]*matris[1][1]-matris[0][1]*matris[1][0];
          }
          else if (r == 1) {det=matris[0][0];}
          else if (r == 3)
            {
                toplanan=(matris[0][0]*matris[1][1]*matris[2][2])+(matris[0][1]*matris[1][2]*matris[2][0])+(matris[0][2]*matris[1][0]*matris[2][1]);
                cikarilan=(matris[0][2]*matris[1][1]*matris[2][0])+(matris[1][2]*matris[2][1]*matris[0][0])+(matris[1][0]*matris[0][1]*matris[2][2]);
                det=toplanan - cikarilan;
            }
      }

      cout << "Determinant = " ;
      cout << det << endl;
}
  /*  void inv(){
        det();
        if(r == c && det > 0){

        }
    }*/
    void print(){ //Matrisi basan fonksiyon
        cout << "Matris" << endl;
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    cout << matris[i][j] << " ";
                }cout << endl;
            }cout << endl;
        }

    void print(string oku){ //Matrisi dosyaya basan fonksiyon
        ofstream dosya;
        dosya.open("file.txt");
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    dosya << matris[i][j] << " ";
                }dosya << endl;
                }dosya << endl;
        dosya.close();
        cout << "Matrisi Dosyaya Yazdirma Islemi Basarili." << endl;
    }

    ~Matris(){  //Yikici Fonksiyon
        cout << "Yikici Fonksiyon Calisti" << endl;
    }

protected:
    void bellek_tamsayi(){ //Matris icin bellekte iki boyutlu yer acilmasi
        matris = (Tip **)malloc( satir * sizeof(Tip ) );
        if( matris == NULL )
            printf( "Yetersiz bellek!" ); // Daha sonra sutun sayisi icin yer olusturdum
        for(int i = 0; i < satir ; i++ ) {
            matris[i] = (Tip*)malloc( sutun * sizeof(Tip ) );
            if( matris[i] == NULL )
                printf( "Yetersiz bellek!" );
            }
        }

    Tip **matris;
    int deger;
    int r,c;
};



int main()
{
  //  Matris <int> *m1=new Matris<int>();
 //   Matris <int> *m2=new Matris<int>(3,2,1);
    Matris <int> *m2=new Matris<int>(3,4,9);
 //   Matris <int> *m3=new Matris<int>(5,5,'e');
 //   Matris <int> *m4=new Matris<int>(15,15,'r');
   //  m4 -> resize(5,5);
   //*m1 = (*m1) + (*m2);
   // *m1 = (*m1) - (*m2);
    *m2 = (*m2) * (*m2);
   // (*m1)= (*m1) + 12 ;
   // (*m1)= (*m1) - 20 ;
   // (*m1)= (*m1) * 10 ;
   // (*m1)= (*m1) % 10 ;
   // (*m1)= (*m2) ^ 2  ;
   //  m1 -> emul(*m2);
   //  m1 ->det();
   //  m1 -> inv();
    m2 -> print() ;
    m2 -> print("file.txt");

    m2 -> T();
    delete m2;
  //  delete m1,m2,m3,m4;
}

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <iomanip>

using namespace std;

template <class Tip>
class Matris{
public:
    Matris(int _r1=10,int _c1=10,int _deger=0){
        cout << "Parametreli Yapici Calisti" << endl;
        this -> r = _r1;
        this -> c = _c1;
        this -> deger = _deger;
        bellek_tamsayi();
        birim();
        random();
        if(_deger >= 0 && _deger <= 99){
            for(int i=0;i<_r1;i++){
                for(int j=0;j<_c1;j++){
                    matris[i][j] = _deger;
                }
            }
        }
           else if(_deger == 'e'){
                for(int i=0;i<_r1;i++){
                    for(int j=0;j<_c1;j++){
                        if(i == j){
                              birim_matris[i][j] = 1;
                        }
                        else {
                              birim_matris[i][j] = 0;
                        }
                    }
                }
            }
            else if(_deger == 'r'){
                srand (time(NULL));
                for(int i=0;i<_r1;i++){
                    for(int j=0;j<_c1;j++){
                        random_matris[i][j] = rand() % 255;
                    }
                    }
            }
    }
    void setRowColumnDeger(int _r,int _c,int _deger){
      r  = _r;
      c  = _c;
      deger = _deger;
    }
    void getRowColumnDeger(int &_r,int &_c,int &_deger){
      _r = r;
      _c = c;
      _deger = deger;
    }
     Matris operator +(const Matris &nesne)const  //2 Matrisi Vektorel Toplar.
{
    Matris t;
         for(int i=0;i<r;i++){
             for(int j=0;j<c;j++){
                 t.matris[i][j] = nesne.matris[i][j] + matris[i][j];
             }
         }
    return t;
}
    Matris operator +(const int toplam)const  // Matris ve Int Degeri Skaler Toplar.
{
    Matris t;
         for(int i=0;i<r;i++){
             for(int j=0;j<c;j++){
                 t.matris[i][j] =matris[i][j] + toplam ;
             }
         }
    return t;
}
    Matris operator -(const Matris &nesne)const //2 Matrisi Vektorel Cikarir.
{
    Matris t;
         for(int i=0;i<r;i++){
             for(int j=0;j<c;j++){
                 t.matris[i][j] = matris[i][j] - nesne.matris[i][j];
         }
        }
      return t;
}
    Matris operator -(const int cikar)const // Matris ve Int Degeri Skaler Cikarir.
{
    Matris t;
         for(int i=0;i<r;i++){
             for(int j=0;j<c;j++){
                 t.matris[i][j] = matris[i][j] - cikar;
             }
         }
      return t;
}
    Matris operator *(const Matris &nesne)const //2 Matrisi Vektorel Carpar.
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
    Matris operator *(const int carp)const //Matris ve Int Degeri Skaler Carpar.
{
    Matris t;
    for(int i=0;i<r;i++)
             for(int j=0;j<c;j++)
                 t.matris[i][j] = matris[i][j] * carp;
    return t;
}
    Matris operator %(const int mod_al)const //Matrisin Elemanlarinin Modunu Alir.
{
    Matris t;
         for(int i=0;i<r;i++){
             for(int j=0;j<c;j++){
                 t.matris[i][j] = matris[i][j] % mod_al;
             }
         }
      return t;
}
 /*   Matris operator ^(const int us_al)const //Matrisin Elemanlarinin Ussunu Alir.
{
    Matris t=1;
         for(int i=0;i<r;i++){
             for(int j=0;j<c;j++){
                    for(int m=0;m<us_al;m++){
                        t.matris[i][j] = t.matris[i][j] * matris[i][j] ;
                    }
             }
         }
      return t;
}*/

    void resize(int yeni_r,int yeni_c){
        this -> r = yeni_r;
        this -> c = yeni_c;
        for(int t=0;t<yeni_r;t++){
            for(int k=0;k<yeni_c;k++){
                matris[t][k];
                birim_matris[t][k];
                random_matris[t][k];
            }
        }
    }
    void T(){
        trans();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
               transpoz[j][i] = matris[i][j];
            }
        }/*
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
               transpoz[j][i] = birim_matris[i][j];
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
               transpoz[j][i] = random_matris[i][j];
            }
        }*/
        cout << "Matrisin Transpozu" << endl;
        for(int i=0;i<c;i++){
            for(int j=0;j<r;j++){
               cout << transpoz[i][j] << " ";
            }cout << endl;
        }cout << endl;
    }
    void print(){
        cout << "Matris" << endl;
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    cout << matris[i][j] << " ";
                }cout << endl;
            }cout << endl;
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    cout << birim_matris[i][j] << " ";
                }cout << endl;
            }cout << endl;
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    cout << random_matris[i][j] << " ";
                }cout << endl;
            }cout << endl;
        }
    void print(string oku){
        ofstream dosya;
        dosya.open("file.txt");
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    dosya << matris[i][j] << " ";
                }dosya << endl;
                }dosya << endl;
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    dosya << birim_matris[i][j] << " ";
                }dosya << endl;
                }dosya << endl;
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    dosya << random_matris[i][j] << " ";
                }dosya << endl;
                }dosya << endl;
        dosya.close();
        cout << "Matrisi Dosyaya Yazdirma Islemi Basarili." << endl;
    }
    ~Matris(){
        cout << "Yikici Fonksiyon Calisti" << endl;
    }
private:
    void bellek_tamsayi(){
        matris = (Tip **)malloc( 20 * sizeof(Tip) );
        if( matris == NULL )
            printf( "Yetersiz bellek!" ); // Daha sonra sutun sayisi icin yer olusturdum
        for(int i = 0; i < 20; i++ ) {
            matris[i] = (Tip*)malloc( 20 * sizeof(Tip) );
            if( matris[i] == NULL )
                printf( "Yetersiz bellek!" );
            }
            }
    void trans(){
        transpoz = (Tip **)malloc( 20 * sizeof(Tip) );
        if( transpoz == NULL )
            printf( "Yetersiz bellek!" );
        for(int i = 0; i < 20; i++ ) {
            transpoz[i] = (Tip*)malloc( 20 * sizeof(Tip) );
            if( transpoz[i] == NULL )
                printf( "Yetersiz bellek!" );
            }
            }
    void birim(){
        birim_matris = (Tip **)malloc( 20 * sizeof(Tip) );
        if( birim_matris == NULL )
            printf( "Yetersiz bellek!" );
        for(int i = 0; i < 20; i++ ) {
            birim_matris[i] = (Tip*)malloc( 20 * sizeof(Tip) );
            if( birim_matris[i] == NULL )
                printf( "Yetersiz bellek!" );
            }
            }
    void random(){
        random_matris = (Tip **)malloc( 20 * sizeof(Tip) );
        if( random_matris == NULL )
            printf( "Yetersiz bellek!" );
        for(int i = 0; i < 20; i++ ) {
            random_matris[i] = (Tip*)malloc( 20 * sizeof(Tip) );
            if( random_matris[i] == NULL )
                printf( "Yetersiz bellek!" );
            }
            }
    Tip **matris;
    Tip **transpoz;
    Tip **birim_matris;
    Tip **random_matris;
    int deger;
    char harf;
    int r,c;
    int det = 0,subi,subj;
};
int main()
{
    Matris <int> *m1=new Matris<int>();
    Matris <int> *m5=new Matris<int>(3,2,1);
    Matris <int> *m2=new Matris<int>(3,4,9);
    Matris <int> *m3=new Matris<int>(5,5,'e');
    Matris <int> *m4=new Matris<int>(15,15,'r');
  //  m2 -> resize(5,5);
  //  *m1 = (*m1) + (*m2);
   // *m1 = (*m1) - (*m2);
  //  *m1 = (*m2) * (*m2);
   // (*m1)= (*m1) + 12 ;
   // (*m1)= (*m1) - 20 ;
    //(*m1)= (*m1) * 10 ;
   // (*m1)= (*m1) % 10 ;
  //  (*m1)= (*m2) ^ 2  ;
    m2 -> print() ;
    m2 -> print("file.txt");

    m2 -> T();
    delete m1,m2,m3,m4;
}

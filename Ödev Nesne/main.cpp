#include <iostream>
#include <stdlib.h>
#include <time.h>                  //Resat Karakaya 348284
#include <fstream>                 //E-Mail : resatkrky_@hotmail.com
#include <iomanip>                 //Cep Tel:05342221650
#define satir 50
#define sutun 50

using namespace std;

template <class Tip>
class Matris{
public:
    Matris(int _r1=10,int _c1=10,int _deger=0){ //Parametresiz Yapici icin Default Degerler
        cout << "Int Parametreli Yapici Calisti" << endl;
        this -> r = _r1;
        this -> c = _c1;
        this -> deger = _deger;
       // bellek_tamsayi();
        satir_sutun();
        for(int i=0;i<_r1;i++){
            for(int j=0;j<_c1;j++){
                matris[i][j] = _deger; //Int degerler icin
            }
        }
    }
    Matris(int _r2,int _c2,char _ch){ //Birim Matris ve Random Matris icin
        cout << "Char Parametreli Yapici Calisti" << endl;
        this -> r = _r2;
        this -> c = _c2;
        this -> ch = _ch;
      //  bellek_tamsayi();
        satir_sutun();
        if(_ch == 'e'){ //Birim matris icin
            for(int i=0;i<_r2;i++){
                for(int j=0;j<_c2;j++){
                    if(i == j){
                            matris[i][j] = 1;
                    }
                    else {
                            matris[i][j] = 0;
                    }
                }
            }
        }
        else if(_ch == 'r'){ //random degerli matris icin
            srand (time(NULL));
            for(int i=0;i<_r2;i++){
                for(int j=0;j<_c2;j++){
                    matris[i][j] = rand() % 255;
                }
                }
        }
        else{
            cout << "Yanlis char girildi" << endl;
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

     Matris operator +(const Matris &nesne)const  //2 Matrisi Vektorel Toplar.
{
     Matris *t=new Matris(r,c,deger & ch);
         for(int i=0;i<r;i++){
             for(int j=0;j<c;j++){
                 t->matris[i][j] = nesne.matris[i][j] + matris[i][j];
             }
         }
    return *t;
}

    Matris operator +(const int toplam)const  // Matris ve Int Degeri Skaler Toplar.
{
     Matris *t=new Matris(r,c,deger & ch);
         for(int i=0;i<r;i++){
             for(int j=0;j<c;j++){
                 t->matris[i][j] =matris[i][j] + toplam ;
             }
         }
    return *t;
}

    Matris operator -(const Matris &nesne)const //2 Matrisi Vektorel Cikarir.
{
    Matris *t=new Matris(r,c,deger & ch);
         for(int i=0;i<r;i++){
             for(int j=0;j<c;j++){
                 t->matris[i][j] = matris[i][j] - nesne.matris[i][j];
         }
        }
      return *t;
}

    Matris operator -(const int cikar)const // Matris ve Int Degeri Skaler Cikarir.
{
    Matris *t=new Matris(r,c,deger & ch);
         for(int i=0;i<r;i++){
             for(int j=0;j<c;j++){
                 t->matris[i][j] = matris[i][j] - cikar;
             }
         }
      return *t;
}

    Matris operator *(const Matris &nesne)const //2 Matrisi Vektorel Carpar.
{
     Matris *t=new Matris(r,c,deger & ch);
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
                t->matris[a][x]=toplam;
        }
    }
    return *t;
}

    Matris operator *(const int carp)const //Matris ve Int Degeri Skaler Carpar.
{
    Matris *t=new Matris(r,c,deger & ch);
    for(int i=0;i<r;i++)
             for(int j=0;j<c;j++)
                 t->matris[i][j] = matris[i][j] * carp;
    return *t;
}

    Matris operator %(const int mod_al)const //Matrisin Elemanlarinin Modunu Alir.
{
     Matris *t=new Matris(r,c,deger & ch);
         for(int i=0;i<r;i++){
             for(int j=0;j<c;j++){
                 t->matris[i][j] = matris[i][j] % mod_al;
             }
         }
      return *t;
}

   Matris operator ^(const int us_al)const //Matrisin Elemanlarinin Ussunu Alir.
{
    Matris *t=new Matris(r,c,deger);
         for(int i=0;i<r;i++){
             for(int j=0;j<c;j++){
                    for(int m=1;m<us_al;m++){
                        t->matris[i][j] =t->matris[i][j] * matris[i][j] ;
                    }
         }
    }
    return *t;
}

    void resize(int yeni_r,int yeni_c){ // Yeniden boyutlandýrma fonksiyonu
        this -> r = yeni_r;
        this -> c = yeni_c;
        for(int t=0;t<yeni_r;t++){
            for(int k=0;k<yeni_c;k++){
                matris[t][k];
            }
        }
    }
    void emul(Matris &nesne){ //Iki Matrisi Eleman Duzeyinde Carpar.
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                this->matris[i][j] = this->matris[i][j] * nesne.matris[i][j];
            }
        }
    }

    void T(){ //Matrisin Transpozunu alan fonksiyon
       Matris t;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
               t.matris[j][i] = matris[i][j];
            }
        }
        cout << "Matrisin Transpozu" << endl;
        for(int i=0;i<c;i++){
            for(int j=0;j<r;j++){
               cout << setw(5) << t.matris[i][j] << " ";
            }cout << endl;
        }cout << endl;
    }

    int det() { //Istenen Matrisin Determinantini Alir.
      int deter=0,toplanan=0,cikarilan=0;
      if (r == c)
      {
          if(r == 2){deter=matris[0][0]*matris[1][1]-matris[0][1]*matris[1][0];}
          else if (r == 1) {deter=matris[0][0];}
          else if (r == 3)
            {
                toplanan=(matris[0][0]*matris[1][1]*matris[2][2])+(matris[0][1]*matris[1][2]*matris[2][0])+(matris[0][2]*matris[1][0]*matris[2][1]);
                cikarilan=(matris[0][2]*matris[1][1]*matris[2][0])+(matris[1][2]*matris[2][1]*matris[0][0])+(matris[1][0]*matris[0][1]*matris[2][2]);
                deter=toplanan - cikarilan;
            }
          }
     cout << "Determinant = " << deter << endl;
     return deter;
}

    void print(){ //Matrisi basan fonksiyon
        cout << "Matris" << endl;
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    cout << setw(5) << matris[i][j] << " ";
                }cout << endl;
            }cout << endl;
        }

    void print(string oku){ //Matrisi dosyaya basan fonksiyon
        ofstream dosya;
        dosya.open("file.txt");
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    dosya << setw(5) << matris[i][j] << " ";
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
        matris = (Tip **)malloc( satir * sizeof(Tip ) ); //Ilk Once Satir icin yer olusturdum.
        if( matris == NULL )
            cout << "Yetersiz bellek!" ; // Daha sonra sutun sayisi icin yer olusturdum
        for(int i = 0; i < satir ; i++ ) {
            matris[i] = (Tip*)malloc( sutun * sizeof(Tip ) );
            if( matris[i] == NULL )
                cout << "Yetersiz bellek!" ;
            }
        }
    void satir_sutun(){
		matris = new Tip* [satir];
		for (int i = 0; i < satir; i++){
            matris[i] = new Tip[sutun];
    }
}
    Tip **matris;
    int deger;
    char ch;
    int r;
    int c;
};

template <class Tip>
class Tablo:public Matris<Tip>{
public:
    Tablo(int _r1=10,int _c1=10,int _deger=0):Matris<Tip>(_r1,_c1,_deger){} //Parametresiz Yapici ve Int Deger icin Default Degerler

    Tablo(int _r2,int _c2,char _ch):Matris<Tip>(_r2,_c2,_ch){} //Birim Tablo ve Random Tablo icin

    void itemAt(int r,int c){ //Istenen Satir ve Sutundaki Int Tablo Degerinin Dondurur.
        cout << "Int Parametreli Istenilen Deger : ";
        cout << this->matris[c][r] << endl;
        }

    void itemAt(string s){  //Istenen Satir ve Sutundaki String Tablo Degerinin Dondurur.
		int satirTut=0,sutunTut=0;
		while(s[0] != cname[satirTut] ){ satirTut++; }
		while(s[1] != rname[sutunTut] ){ sutunTut++; }
		cout << "String Parametreli Istenilen Deger : ";
		cout << this->matris[satirTut][sutunTut] << endl;
	}

	void itemAt(char rs,char cs){ //Istenen Satir ve Sutundaki Char Tablo Degerinin Dondurur.
		int satirTut=0,sutunTut=0;
		while(rs != rname[satirTut] ){ satirTut++; }
		while(cs != cname[sutunTut] ){ sutunTut++; }
        cout << "Char Parametreli Istenilen Deger : ";
		cout<< this->matris[sutunTut][satirTut] << endl;
	}

    void setRowNames(char s[],int n){ rname[n] = s[n]; }//Tablonun Istenen Satir Adini Degistirir.

    void setColNames(char s[],int n){ cname[n] = s[n]; }//Tablonun Istenen Satir Adini Degistirir.

    void print(){ //Tabloyu Default Satir ve Sutun Isimleriyle Basar.
        for(int k=0;k<this->r;k++){
            cout << setw(8) << this->rname[k];
        }cout << endl;
        for(int m=0;m<this->c;m++){
            cout << this->cname[m] ;
            for(int t=0;t<this->c;t++){
                cout << setw(8) << this->matris[m][t] ;
            }cout << endl;
        }
    }
    ~Tablo(){
        cout << "Yikici Fonksiyon Calisti" << endl;
    }
protected:
    //------------------------------------------------------------DEFAULT TABLO ISIMLERI-------------------------------------------------------------------
    char rname[30] = {'0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29'};
    char cname[30] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','R','S','T','U','V','Y','Z','AA','AB','AC','AD','AE','AF','AG'};
};

int main(int argc,char *argv[])
{
    //--------MATRIS ISLEMLERI----------
    Matris <int> *m1=new Matris<int>();
 //   Matris <int> *m2=new Matris<int>(3,2,1);
    Matris <int> *m2=new Matris<int>(3,4,9);
    Matris <int> *m3=new Matris<int>(5,5,'e');
    Matris <int> *m4=new Matris<int>(15,15,'r');
    Matris <int> m5;
   // Matrix<double> a(2,3,1.);
   //   a.print();
   //  m2 -> resize(5,5);
   // (*m1) = (*m1) + (*m2);
   // (*m1) = (*m1) - (*m2);
   // (*m2) = (*m2) * (*m2);
   // (*m1)= (*m1) + 12 ;
   // (*m1)= (*m1) - 20 ;
   // (*m1)= (*m1) * 10 ;
   // (*m1)= (*m1) % 10 ;
   // (*m1)= (*m1) ^ 2  ;
   //  m1 -> emul(*m2);
   //  m4 -> det();
    m1 -> print();
    m1 -> print("file.txt");
    m1 -> T();
    //  m5.print();
    delete m1,m2,m3,m4;

    //----------TABLO ISLEMLERI---------------
//     Tablo <int> *m5=new Tablo<int>(3,3,'r');
  //   char yeni_r[2] = {'r','d'};
    // char yeni_c[2] = {'a','c'};
     //m5->  setRowNames(yeni_r,1);
     //m5->  setColNames(yeni_c,0);
   //  m5 -> itemAt(2,1);
   //  m5 -> itemAt('2','A');
   //  m5 -> itemAt("A0");
     //m5 -> print();
     //delete m5;
}


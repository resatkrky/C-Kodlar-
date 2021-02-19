#include <iostream>
#include <stdlib.h> //rand fonksiyonu için
#include <time.h> //srand fonksiyonu için

using namespace std;

void matris_olustur(int x[][10],int satir,int sutun){
    srand (time(NULL));
    int i=0,j=0;
    for(i=0;i<satir;i++){
        for(j=0;j<sutun;j++){
            x[i][j] = rand() % 2;
        }
    }
}
void matris_yazdir(int y[][10],int satir2,int sutun2){
    int i=0,j=0;
    for(i=0;i<satir2;i++){
        for(j=0;j<sutun2;j++){
           cout << y[i][j] ;
        }
        cout << endl;
    }

}

int main()
{
    int i=0,j=0,Satir=0,Sutun=0;
    int matris[10][10];
    bool kontrol = true;
    int puan=0,GSatir=0,GSutun=0;

    cout << "Satir sayisi" << endl;
    cin >> Satir;
    cout << "Sutun sayisi" << endl;
    cin >> Sutun;

    matris_olustur(matris,Satir,Sutun);

    while(kontrol){
        cout << "Puaniniz: " << puan << endl;
        cout << "Girilen Satir" << endl;
        cin >> GSatir;
        cout << "Girilen Sutun" << endl;
        cin >> GSutun;

        if(matris[GSatir][GSutun] == 1){
            kontrol = false;
        }
        else{
            puan += 10 ;
            cout << "Devam" << endl;
        }
    }


}

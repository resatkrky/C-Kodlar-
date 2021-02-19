#include <iostream>

using namespace std;
#define ROW 10
#define COLUMN 10

void vektormatris_bilgial(int vm1[ROW][COLUMN],int vm2[ROW][COLUMN],int r,int c){
    cout << "Ilk matris degerleri: ";
    for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
				cin >> vm1[i][j];
		}
    }
    cout << "Ikinci matris degerleri: ";
    for(int y=0; y<r; y++) {
		for(int z=0; z<c; z++) {
				cin >> vm2[y][z];
		}
    }
}
void skalermatris_bilgial(int sm[ROW][COLUMN],int r,int c){
    cout << "Matrisin degerleri:";
    for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
				cin >> sm[i][j];
		}
    }

}
void vektorel_toplam(int a1[ROW][COLUMN],int a2[ROW][COLUMN],int yaz[ROW][COLUMN],int r,int c){
    for(int k=0; k<r; k++) {
		for(int l=0; l<c; l++) {
            yaz[k][l] = a1[k][l] + a2[k][l];
		}
    }
}
void vektorel_cikarma(int b1[ROW][COLUMN],int b2[ROW][COLUMN],int yaz[ROW][COLUMN],int r,int c){
    for(int k=0; k<r; k++) {
		for(int l=0; l<c; l++) {
            yaz[k][l] = b1[k][l] - b2[k][l];
		}
    }
}
void vektorel_carpma(int c1[ROW][COLUMN],int c2[ROW][COLUMN],int yaz[ROW][COLUMN],int r,int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            for(int k=0;k<c;k++){
                yaz[i][j] = yaz[i][j] + (c1[i][k] * c2[k][j]);
            }
        }
    }
}
void skaler_toplam(int d[ROW][COLUMN],int r,int c){
    int topla;
    cout << "Toplanacak degeri giriniz: ";
    cin >> topla;
    for(int k=0; k<r; k++) {
		for(int l=0; l<c; l++) {
            d[k][l] += topla ;
		}
    }
}
void skaler_cikarma(int e[ROW][COLUMN],int r,int c){
    int cikar;
    cout << "Cikarilacak degeri giriniz: ";
    cin >> cikar;
    for(int k=0; k<r; k++) {
		for(int l=0; l<c; l++) {
            e[k][l] -= cikar ;
		}
    }
}
void skaler_carpma(int f[ROW][COLUMN],int r,int c){
    int carp;
    cout << "Carpilacak degeri giriniz: ";
    cin >> carp;
    for(int k=0; k<r; k++) {
		for(int l=0; l<c; l++) {
            f[k][l] *= carp ;
		}
    }
}
void skaler_usalma(int g[ROW][COLUMN],int r,int c){
    int us_al,sonuc=1;
    cout << "Us alinacak degeri giriniz: ";
    cin >> us_al;
    for(int k=0; k<r; k++) {
		for(int l=0; l<c; l++) {
            for(int m=0;m<us_al;m++){
                sonuc *=g[k][l]  ;
            }
            cout << sonuc << " ";
            sonuc=1;
		}   cout<< endl;
    }
}
void skaler_bolme(int h[ROW][COLUMN],int r,int c){
    float bol;
    cout << "Bolunecek degeri giriniz: ";
    cin >> bol;
    for(int k=0; k<r; k++) {
		for(int l=0; l<c; l++) {
            h[k][l] /= bol ;
		}
    }
}
void skaler_modalma(int j[ROW][COLUMN],int r,int c){
    int mod;
    cout << "Matrisin alinacak mod degerini giriniz: ";
    cin >> mod;
    for(int k=0; k<r; k++) {
		for(int l=0; l<c; l++) {
             j[k][l] %= mod ;
		}
    }
}
void transpoz(int n[ROW][COLUMN],int r,int c){
    int transpoz[r][c];
        for(int k=0; k<r; k++) {
		for(int l=0; l<c; l++) {
             transpoz[l][k] = n[k][l] ;
		}
    }
    cout << "Matrisin Transpozu" << endl;
    for(int m=0;m<r;m++){
        for(int n=0;n<c;n++){
            cout << transpoz[m][n] << " ";
        }cout<< endl;
    }
}
void matris_yazdir(int yaz[ROW][COLUMN],int r,int c){
    for(int t=0; t<r; t++) {
		for(int v=0; v<c; v++) {
            cout << yaz[t][v] << " ";
		}cout << endl;
    }
}
int main()
{
    int matris1[ROW][COLUMN];
	int matris2[ROW][COLUMN];
	int sonuc[ROW][COLUMN];
    int islem1,islem2,satir,sutun;
    string tur;
    cout << "Islem yapilacak matris turunu belirtiniz.(Vektorel mi Skaler mi?)" << endl;
    cout <<"Islem:";
    cin >> tur;
    if(tur == "Vektorel" || tur == "vektorel"){
        cout << "Lutfen matrisin satir ve sutun degerlerini giriniz." << endl;
        cout << "(NOT --> 0'dan buyuk deger girin yoksa program calismaz.)" << endl;
        cout << "Satir: ";
        cin >> satir;
        cout << "Sutun: ";
        cin >> sutun;
        cout << "1)Toplama 2)Cikarma 3)Carpma " << endl;
        cout << "Yapmak istediginiz islemi seciniz: ";
        cin >> islem1;
        switch(islem1){
        case 1:
            vektormatris_bilgial(matris1,matris2,satir,sutun);
            vektorel_toplam(matris1,matris2,sonuc,satir,sutun);
            matris_yazdir(sonuc,satir,sutun);
            break;
        case 2:
            vektormatris_bilgial(matris1,matris2,satir,sutun);
            vektorel_cikarma(matris1,matris2,sonuc,satir,sutun);
            matris_yazdir(sonuc,satir,sutun);
            break;
        case 3:
            vektormatris_bilgial(matris1,matris2,satir,sutun);
            vektorel_carpma(matris1,matris2,sonuc,satir,sutun);
            matris_yazdir(sonuc,satir,sutun);
            break;
        default:
            cout << "Yanlis deger girdiniz.";
        }
    }
    else if(tur == "Skaler" || tur == "skaler"){
        cout << "Lutfen matrisin satir ve sutun degerlerini giriniz." << endl;
        cout << "(NOT --> 0'dan buyuk deger girin yoksa program calismaz.)" << endl;
        cout << "Satir: ";
        cin >> satir;
        cout << "Sutun: ";
        cin >> sutun;
        cout << "1)Toplama 2)Cikarma 3)Carpma 4)Bolme 5)Us Alma 6)Mod Alma 7)Transpoz" << endl;;
        cout << "Yapmak istediginiz islemi seciniz: ";
        cin >> islem2;
        switch(islem2){
        case 1:
            skalermatris_bilgial(sonuc,satir,sutun);
            skaler_toplam(sonuc,satir,sutun);
            matris_yazdir(sonuc,satir,sutun);
            break;
        case 2:
            skalermatris_bilgial(sonuc,satir,sutun);
            skaler_cikarma(sonuc,satir,sutun);
            matris_yazdir(sonuc,satir,sutun);
            break;
        case 3:
            skalermatris_bilgial(sonuc,satir,sutun);
            skaler_carpma(sonuc,satir,sutun);
            matris_yazdir(sonuc,satir,sutun);
            break;
        case 4:
            skalermatris_bilgial(sonuc,satir,sutun);
            skaler_bolme(sonuc,satir,sutun);
            matris_yazdir(sonuc,satir,sutun);
            break;
        case 5:
            skalermatris_bilgial(sonuc,satir,sutun);
            skaler_usalma(sonuc,satir,sutun);
            break;
        case 6:
            skalermatris_bilgial(sonuc,satir,sutun);
            skaler_modalma(sonuc,satir,sutun);
            matris_yazdir(sonuc,satir,sutun);
            break;
        case 7:
            skalermatris_bilgial(sonuc,satir,sutun);
            transpoz(sonuc,satir,sutun);
            break;
        default:
            cout << "Yanlis deger girdiniz.";
    }
}
    else {
        cout << "Yanlis bilgi girdiniz.";
    }
}

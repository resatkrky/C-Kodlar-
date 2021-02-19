#include <iostream>

using namespace std;

//void f(int a[][10]){}
//void f(int *a){}
//void f(int a[10]){}

void transpoz(int d[][4],int r){
    int i,j,temp;
    for(i=0;i<r;i++){
        for(j=0;j<4;j++){
            temp=d[i][j];
            d[i][j]=d[j][i];
            d[j][i]=temp;
        }
    }
}
void print(int d[][4],int r){
    int i,j;
    for(i=0;i<r;i++){
        for(j=0;j<4;j++){
            cout <<d[j][i] <<" " ;
        }cout <<endl;
    }
}
void sutun(int e[][4],int r){
    int k,l,m,p,s,toplam=0,dizi[1];
    for(l=0;l<4;l++){
        for(k=0;k<r;k++){
            toplam+=e[k][l];
        }
        for(m=0;m<1;m++){
            dizi[m]=toplam;
            cout << dizi[m] << endl;
        }
        toplam=0;
    }
}


int main()
{
    int a[4][4]={{1,2,3,6},{4,5,6,4},{7,8,9,2},{3,5,9,7}};
    int b[4]={15,7,48,36};
    transpoz(a,4);
    print(a,4);
    sutun(a,4);
    return 0;
}



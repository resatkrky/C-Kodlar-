#include <iostream>

using namespace std;

int main()
{
    int i,j,vize,sayac=0,fn,max,min;
    cout<<"Girilecek sayiya kadar olan tum asal sayilari ekrana yazdiran program\n";
    cout<<"Bir vize notu giriniz : ";     cin>>vize;
    cout<<"Bir final notu giriniz : ";     cin>>fn;
    if(vize>fn){
		max=vize;
		min=fn;
		}
	else if(fn>vize){
		max=fn;
		min=vize;
		}
	else{
		cout <<"Girilen 2 sayi birbirine eþittir "<< endl;
    }


    for(i=min;i<=max;i++)
    {
                        for(j=1;j<=i;j++)
                        {
                           if(i%j==0)
                           {
                                     sayac=sayac+1;
                           }
                        }
                        if(sayac==2)
                        {
                                   cout<<i<<endl;
                        }
                        sayac=0;

    }
}

#include <iostream>

using namespace std;

string duzelt(string cumle,char harf[5],int r){
    int i,j;
    for(i=0;i<cumle.size();i++){
        for(j=0;j<r;j++){
            if(cumle[i] == harf[j]){
                cumle[i] = '-';
            }
        }
    }
    return cumle;
}

int main()
{
    string mesaj;
    char sesli[10]={'a','e','i','o','u','A','E','I','O','U'};
    cout << "Lutfen mesaji giriniz: ";
    getline(cin,mesaj);
    cout << duzelt(mesaj,sesli,10);

    return 0;
}

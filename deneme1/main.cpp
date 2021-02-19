#include <iostream>
#define N 100
using namespace std;

class HugeInt{
public:
    HugeInt(string _initValue="0"){
        size = _initValue.length();
        int i,j;
        for(i=0;i<_initValue.length();i++){
            digits[i] = _initValue[size-i-1] - '0'; //asciden kurtarmak icin 0 dan cikardi
        }
        for(j=i;j<N;j++){ //geriye kalan elemanlari sifirlar
            digits[j] = 0 ;
        }
    }
    HugeInt operator + (HugeInt _param){
        HugeInt temp;
        int maxLen = (size > _param.size)?size:_param.size;
        int carry = 0; //elde
        int t; //komsu
        for(int i=0;i<maxLen;i++){
            t = digits[i] + _param.digits[i] + carry;
            temp.digits[i] = t % 10;
            carry = t / 10;
        }
        temp.size = maxLen;
        return temp;
    }
    HugeInt operator * (HugeInt _param){
        HugeInt temp;
        int maxLen = size_param.size;
        int carry = 0; //elde
        int t; //komsu
        for(int i=0;i<maxLen;i++){
            t = digits[i] * _param.digits[i] + carry;
            temp.digits[i] = t % 10;
            carry = t / 10;
        }
        temp.size = maxLen;
        return temp;
    }
    void print(){
        for(int i=0;i<size;i++){
                cout << digits[i];
            }cout << endl;
    }
protected:
    int digits[N];
    int size;

};

int main()
{
    HugeInt h("34223");
    HugeInt h1("1");
    HugeInt h2;
    h = h1+ h ;
  //  h.print();
    h.print();
}

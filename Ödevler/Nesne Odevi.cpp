#include<iostream>
#include<stdlib.h>     /* srand, rand */
#include<time.h>       /* time */
#include<fstream>
#include <iomanip>

using namespace std;

class Matris
{

public:
	Matris()//Constructer
	{
		cout << "yapici 1 calisti." << endl;

		this->satir = 10;
		this->sutun = 10;
		this->MatrisDegeri = 0;
		//cout << "1"<<endl;
		//matrix=(int**)malloc(satir*sizeof(int));
		//cout<<"2"<<endl;
		satirOlustur();
		sutunOlustur();
		//cout << "aaa"<<endl;
		degerAta();
		//cout<< "4"<<endl;
	}
	Matris(const int _a, const int _b, const int _deger)//Constructer
	{
		cout << "yapici 2 calisti." << endl;
		satir = _a;
		sutun = _b;
		MatrisDegeri = _deger;
		//cout << "1"<<endl;
		//matrix=(int**)malloc(satir*sizeof(int));
		//cout<<"2"<<endl;
		satirOlustur();
		sutunOlustur();
		//cout << "3"<<endl;
		/*
		matrix[0][0]=1;
		matrix[0][1]=2;
		matrix[1][0]=3;
		matrix[1][1]=4;
		*/
		degerAta();
		//cout<< "4"<<endl;

	}
	Matris(const int _a, const int _b, const char _deger)//Constructer
	{
		if (_deger == 'e')//birim matris yap
		{
			cout << "yapici 3 calisti." << endl;
			satir = _a;
			sutun = _b;
			MatrisDegeri = 0;
			satirOlustur();
			sutunOlustur();
			degerAta();
			BirimMatrisYap();
		}
		else if (_deger == 'r')//random degerler ata
		{
			cout << "yapici 3 calisti." << endl;
			satir = _a;
			sutun = _b;
			MatrisDegeri = _deger;
			satirOlustur();
			sutunOlustur();

			randomDegerAta();

		}
		else
		{
			cout << "Gecersiz bir matris degeri girdiniz." << endl;
		}

	}
	void print()//Ekrana Bas.
	{
		for (int i = 0; i < satir; ++i)
		{
			for (int j = 0; j < sutun; j++)
			{
				cout << setw(4) << matrix[i][j] << '\t';
			}
			cout << endl;
		}
	}


	void print(string dosyaAdi)//Dosyaya Yaz.
	{
		ofstream dosya;//ofstream(dosyaya yazma) sýnýfýndan bir nesne oluþturduk.
		dosya.open("file.txt");//file.txt isimli bir dosya actýk.
		for (int i = 0; i < satir; i++)
		{
			for (int j = 0; j < sutun; j++)
			{
				dosya << matrix[i][j] << '\t';
			}
			dosya << endl;
		}


		dosya.close();

		cout << "Matris dosyaya yazildi." << endl;
	}

	void resize(int _satir, int _sutun)//Matrisi Tekrar Boyutlandýr.
	{
		satir = _satir;
		sutun = _sutun;

		cout << "Matrisin boyutu degistirildi." << endl;


	}

	//----------------------------------OPERATORLER  VEKTOREL--------------------------

	Matris operator+(const Matris &gelen)//+ operatörüne Operator Overloading yapma
	{
		Matris *temp =new Matris(this->satir,this->sutun,0);

		for (int i = 0; i < satir; i++)
		{
			for (int j = 0; j < sutun; j++)
			{
				temp->matrix[i][j] = this->matrix[i][j] + gelen.matrix[i][j];

				if(temp->matrix[i][j] > 10000 || temp->matrix[i][j] < -10000)
				{
					temp->matrix[i][j]=this->MatrisDegeri;
				}
			}
		}

		return *temp;
	}

	Matris operator-(const Matris &gelen)//+ operatörüne Operator Overloading yapma
	{
		Matris *temp =new Matris(this->satir,this->sutun,0);

		for (int i = 0; i < satir; i++)
		{
			for (int j = 0; j < sutun; j++)
			{
				temp->matrix[i][j] = this->matrix[i][j] - gelen.matrix[i][j];
				/*
				if(temp->matrix[0][0] > 10000 || temp->matrix[i][j] < -10000)
				{
					temp->matrix[i][j]=this->MatrisDegeri;
				}*/
			}
		}

		return *temp;
	}

	Matris operator*(const Matris &gelen)//+ operatörüne Operator Overloading yapma
	{
		Matris *temp =new Matris(this->satir,gelen.sutun,0);


		for (int j = 0; j < satir; j++)
		{
			for(int k=0;k<gelen.sutun;k++)
			{
				temp->matrix[j][k]=(this->matrix[j][0] * gelen.matrix[0][k]) + (this->matrix[j][1] * gelen.matrix[1][k]);
			}
		}

		return *temp;

	}

	//----------------------------------OPERATORLER  SKALER--------------------------

	Matris operator+(const int gelen)//+ operatörüne Operator Overloading yapma
	{
		Matris *temp =new Matris(this->satir,this->sutun,0);


		for (int i = 0; i < satir; i++)
		{
			for (int j = 0; j < sutun; j++)
			{
				temp->matrix[i][j] = this->matrix[i][j] + gelen;
			}
		}

		return *temp;

	}

	Matris operator-(const int gelen)//- operatörüne Operator Overloading yapma
	{

		Matris *temp=new Matris(satir,sutun,0);

		for (int i = 0; i < satir; i++)
		{
			for (int j = 0; j < sutun; j++)
			{
				temp->matrix[i][j]= this->matrix[i][j] - gelen;
			}
		}

		return *temp;

	}
	Matris operator*(const int gelen)//* operatörüne Operator Overloading yapma
	{

		Matris *temp=new Matris(satir,sutun,0);

		for (int i = 0; i < satir; i++)
		{
			for (int j = 0; j < sutun; j++)
			{
				temp->matrix[i][j]= this->matrix[i][j] * gelen;
			}
		}

		return *temp;

	}
	Matris operator/(const int gelen)// '/'  operatörüne Operator Overloading yapma
	{

		Matris *temp=new Matris(satir,sutun,0);

		for (int i = 0; i < satir; i++)
		{
			for (int j = 0; j < sutun; j++)
			{
				temp->matrix[i][j]= this->matrix[i][j] / gelen;
			}
		}

		return *temp;

	}
	Matris operator%(const int gelen)// % operatörüne Operator Overloading yapma
	{

		Matris *temp=new Matris(satir,sutun,0);

		for (int i = 0; i < satir; i++)
		{
			for (int j = 0; j < sutun; j++)
			{
				temp->matrix[i][j]= this->matrix[i][j] % gelen;
			}
		}

		return *temp;

	}
	Matris operator^(const int gelen)// ^ operatörüne Operator Overloading yapma
	{

		Matris *temp=new Matris(satir,sutun,MatrisDegeri);

		for (int i = 0; i < satir; i++)
		{
			for (int j = 0; j < sutun; j++)
			{
				for(int k=1;k<gelen;k++)
				{
					temp->matrix[i][j]= temp->matrix[i][j] * this->matrix[i][j];
				}
			}
		}

		return *temp;

	}

	//--------------------Matris Ýþlemleri------------------------

	void inv()//Matrisin Tersi
	{
		cout << endl;
		float a=det();

		if(satir==2 && sutun == 2)
		{
			float ters[2][2];
			float carp=1/a;
			float temp=0;
			temp=matrix[0][0];
			matrix[0][0]=matrix[1][1];
			matrix[1][1]=temp;
			matrix[0][1] *= -1;
			matrix[1][0] *= -1;
			cout << "Matrisin Tersi:" << endl;
			for(int i=0;i<2;i++)
			{
				for(int j=0;j<2;j++)
				{
					matrix[i][j] *= carp;
					cout << matrix[i][j]<<'\t';
				}
				cout << endl;
			}
		}
		else
		{
			float kof[3][3];
			float ters[3][3];
			if (a!=0)
			{
			//kofaktör matrisi oluþturulmasý
			kof[0][0]= (matrix[1][1]*matrix[2][2]-matrix[1][2]*matrix[2][1]);
			kof[0][1]= -(matrix[1][0]*matrix[2][2]-matrix[1][2]*matrix[2][0]);
			kof[0][2]= (matrix[1][0]*matrix[2][1]-matrix[1][1]*matrix[2][0]);
			kof[1][0]= -(matrix[0][1]*matrix[2][2]-matrix[0][2]*matrix[2][1]);
			kof[1][1]= (matrix[0][0]*matrix[2][2]-matrix[0][2]*matrix[2][0]);
			kof[1][2]= -(matrix[0][0]*matrix[2][1]-matrix[0][1]*matrix[2][0]);
			kof[2][0]= (matrix[0][1]*matrix[1][2]-matrix[1][1]*matrix[0][2]);
			kof[2][1]= -(matrix[0][0]*matrix[1][2]-matrix[1][0]*matrix[0][2]);
			kof[2][2]= (matrix[0][0]*matrix[1][1]-matrix[1][0]*matrix[0][1]);

			cout<<"girilen matrisin kofaktor matrisi :" <<endl<<endl;

			for(int i=0;i<=2;i++)
			{
				for(int j=0;j<=2;j++)
				{
					cout<<kof[i][j]<<"  ";
				}
				cout<<endl;
			}

			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					ters[i][j] = kof[i][j]/a;//tersinin alýnma iþlemi
				}
			}
			cout<<endl<<endl<<"matrisin tersi : "<<endl;

			for(int i=0;i<=2;i++)
			{
				for(int j=0;j<=2;j++)
				{
					cout<<ters[i][j]<<"  ";
				}
					cout<<endl;
				}
			}
			else
			{
				cout<<"matrisin tersi yoktur "<<endl;
			}
		}

	}

	int det()//Matrisin determinantý
	{
		int determinant=0;
		int topla=0;
		int cikar=0;
		if(satir==sutun)
		{
			if(satir==2)
			{
				determinant=(matrix[0][0]*matrix[1][1]-matrix[0][1]*matrix[1][0]);

			}
			else if(satir==1)
			{
				determinant=matrix[0][0];
			}
			else if(satir==3)
			{
				topla=(matrix[0][0]*matrix[1][1]*matrix[2][2]) + (matrix[0][1]*matrix[1][2]*matrix[2][0])+(matrix[0][2]*matrix[1][0]*matrix[2][1]);
				cikar=(matrix[0][2]*matrix[1][1]*matrix[2][0]) + (matrix[1][2]*matrix[2][1]*matrix[0][0])+(matrix[1][0]*matrix[0][1]*matrix[2][2]);
				determinant=topla-cikar;
			}
		}
		cout<<"Determinant : " << determinant <<endl;

		return determinant;
	}


	void emul(Matris& _matrix)//elementwise multiply, eleman düzeyinde çarpma
	{
		for(int i=0;i<_matrix.satir;i++)
		{
			for(int j=0;j<_matrix.sutun;j++)
			{
				this->matrix[i][j]=this->matrix[i][j] * _matrix.matrix[i][j];

			}
		}
	}

	void T()//Transpoze
	{
		cout << endl;
		int temp[sutun][satir];

		if(satir==sutun)//satir ve sutun esýt ýse
		{
			for (int i = 0; i < sutun; i++)
			{
				for (int j = 0; j < satir; j++)
				{
					temp[i][j] = this->matrix[j][i];
				}
			}
		}

		else
		{
			for (int i = 0; i < sutun; i++)
			{
				for (int j = 0; j < satir; j++)
				{
					temp[i][j] = this->matrix[j][i];
				}
			}
		}

			//-------------- MATRÝSÝ BASTIRMA------------


		for (int i = 0; i < sutun; i++)
		{
			for (int j = 0; j < satir; j++)
			{
				cout <<setw(4)<< temp[i][j]<< '\t';
			}
			cout << endl;
		}

		cout << "Transpoze alindi" << endl;

	}


	/*
	~Matris()//destructure
	{

		cout << "Yok Edildi." << endl;
		for (int i = 0; i < satir; ++i)
		{
			delete[] matrix[i];
		}

		delete[] matrix;
		cout <<this->matrix[0][0]<<endl;
	}*/

protected:
	void BirimMatrisYap()
	{
		for (int i = 0; i < satir; i++)
		{
			for (int j = 0; j < sutun; j++)
			{
				if (i == j)
				{
					matrix[i][j] = 1;
				}
			}
		}
	}

	void degerAta()//bizden istenilen matris degerini atadýk.
	{

		for (int i = 0; i < satir; i++)
		{
			for (int j = 0; j < sutun; j++)
			{

				matrix[i][j] = MatrisDegeri;

			}

		}

	}

	void randomDegerAta()
	{
		srand(time(NULL));

		for (int i = 0; i < satir; i++)
		{
			for (int j = 0; j < sutun; j++)
			{
				matrix[i][j] = rand() % 255 + 1;
			}

		}
	}
	void satirOlustur()
	{
		matrix = new int* [satir];
	}
	void sutunOlustur()
	{
		for (int i = 0; i < satir; i++)
		{
			matrix[i] = new int[sutun];
			//matrix[i]=(int*)malloc(sutun*sizeof(int));
		}
	}

	int MatrisDegeri;
	int satir;
	int sutun;
	int** matrix ;


};
/*
class Tablo:public Matris
{

public:
	Tablo()//Constructer
	{
		DegerleriAta();
	}



	~Tablo()//Destructer
	{
		delete []satirDizisi;
		delete []sutunDizisi;
	}
protected:
	void DegerleriAta()
	{

	}

	char *satirDizisi=new char[10];
	char *sutunDizisi=new char[10];

};
*/
int main()
{
	Matris *m1 = new Matris(2,2,'r');

	Matris *m2 = new Matris(3,3,3);
	//Matris *m3 = new Matris(5,4,'e');
	//Matris *m4 = new Matris(15,15,'r');
	//*m1=*m1^4;
	//m2->resize(5,5);
	//m1->T();
	//(*m2)= (*m2) / 12 ;
     m2->inv();
	 m2->print();
	//m3->print("file.txt");
	//Matris *m2 = new Matris(3,2,3);


	//m2->emul(*m1);
	//m1->emul(*m2);
	//*m1=(*m1)*(*m2);
	//*m1=(*m1) + 2;

	//m1->print();
	//cout << "1111"<<endl;
	 //m1->resize(5,5);

	//m1->print("file1.txt");


	/*  DESTRUCTER KENDILIGINDEN MI CAGIRIYOR
		Operator Overloadýng Olayý
		!!!!!!! 4 x 4 uzerý matrýslerde matrýs olusturamýyoruz.
		determýnant ve tersini 2*2 uzerý yapma
		*/

	return 0;
}

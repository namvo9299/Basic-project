#include<iostream>
#include<string>
using namespace std;
class Vemaybay{
    string tenchuyen,ngaybay;
    int giave;
    public:
    Vemaybay(){this->tenchuyen="";this->ngaybay="";this->giave=0;}
    Vemaybay(string a, string b, int c)
        :tenchuyen(a),ngaybay(b),giave(c){}
    ~Vemaybay(){}
    void nhap()
    {   
        cout<<"Nhap thong tin chuyen bay\n";
        cout<<"Nhap ten chuyen bay: ";fflush(stdin); getline(cin,tenchuyen);
        cout<<"Nhap ngay bay: "; fflush(stdin);getline(cin,ngaybay);
        cout<<"Nhap gia ve: "; cin>>this->giave;   cin.ignore();
        
    }
    void xuat()
    {   
        cout<<"\nTen chuyen bay: "; cout<<tenchuyen;
        cout<<"\nNgay bay: ";   cout<<ngaybay;
        cout<<"\nGia ve: "; cout<<giave;
    }
    int getgiave()
    {
        return giave;
    }
};
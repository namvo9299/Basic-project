#include<iostream>
using namespace std;
class Phanso
{
    int tu,mau;
    public:
    Phanso(){};
    ~Phanso(){};
    friend istream& operator >> (istream &is, Phanso &a)
    {
        cout<<"Nhap tu va mau: ";
        is>>a.tu>>a.mau;
        return is;
    }
    friend ostream& operator << (ostream &os, Phanso a)
    {
        os<<a.tu<<"/"<<a.mau;
        return os;
    }
    Phanso rutgon(Phanso a)
    {
        if(a.tu%a.mau==0){
            a.tu=a.tu/a.mau;
            a.mau=1;
        }else if(a.mau%a.tu==0){
            a.mau=a.mau/a.tu;
            a.tu=1;
        }
        return a;
    }
    
    Phanso operator+(Phanso b)
    {
        Phanso a;
        if(mau==b.mau){a.tu=tu+b.tu; a.mau=mau;}
        else {
            a.tu=(tu*b.mau)+(b.tu*mau);
            a.mau=mau*b.mau;
        }
        return rutgon(a);
    }
    Phanso operator-(Phanso b)
    {
        Phanso a;
        if(mau==b.mau){a.tu=tu-b.tu; a.mau=mau;}
        else {
            a.tu=(tu*b.mau)-(b.tu*mau);
            a.mau=mau*b.mau;
        }
        return rutgon(a);
    }
    Phanso operator*(Phanso b)
    {
        b.tu*=tu;
        b.mau*=mau;
        return rutgon(b);
    }
    Phanso operator/(Phanso b)
    {
        Phanso a;
        a.tu=tu*b.mau;
        a.mau=mau*b.tu;
        return rutgon(a);
    }
};
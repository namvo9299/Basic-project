#include "vemaybay.h"
class Nguoi
{   
    string hoten, gioitinh;
    int tuoi;
    public:
    Nguoi(){}
    Nguoi(string a, string b, int c)
        :hoten(a), gioitinh(b), tuoi(c){}
    ~Nguoi(){}
    friend istream& operator >> (istream &is, Nguoi &v)
    {   
        cout<<"Nhap ten nguoi: "; fflush(stdin);getline(is,v.hoten);
        cout<<"Nhap gioi tinh: "; fflush(stdin);getline(is,v.gioitinh);
        cout<<"Nhap tuoi: "; is>>v.tuoi;        cin.ignore();
        return is;
    }
    friend ostream& operator << (ostream &os, Nguoi v)
    {   
        cout<<"\nTen nguoi: "; os<<v.hoten;
        cout<<"\nGioi tinh: ";   os<<v.gioitinh;
        cout<<"\nTuoi: "; os<<v.tuoi;
        return os;
    }


};      
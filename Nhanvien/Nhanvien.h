#include<iostream>
#include<string>
using namespace std;
    static int c=0;
class Nhanvien
{
    string ten,gt,ns,dc,mst;
    int manv,hd;
    public:

    Nhanvien(){
        manv=c;
        ten=gt=ns=dc=mst="";
    }
    ~Nhanvien(){}
    friend istream& operator >> (istream &is,Nhanvien &a)
    {   
        ++c;
        a.manv=c;
        is.ignore();
        getline(is,a.ten);
        is>>a.gt>>a.ns;
        is.ignore();
        getline(is,a.dc);
        is>>a.mst>>a.hd;
        is.ignore();
        return is;
    }
    friend ostream& operator << (ostream &os,Nhanvien a)
    {

        os<<"0000"<<a.manv<<" "<<a.ten<<" "<<a.gt<<" "<<a.ns<<" "<<a.dc<<" "<<a.mst<<" "<<a.hd<<endl;
        return os;
    }
    bool operator > (Nhanvien a)
    {
        if(hd>a.hd)return true;
        return false;
    }
};
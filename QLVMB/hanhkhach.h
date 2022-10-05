#include "nguoi.h"
class Hanhkhach : public Nguoi
{
    Nguoi nguoi;
    Vemaybay *ve;
    int soluong,tong=0;
    public:
    Hanhkhach(){}
    Hanhkhach(int sl):soluong(sl)
    {
        ve = new Vemaybay[soluong];
    }
    ~Hanhkhach(){}
    void nhap()
    {   
        cout<<"\nNhap thong tin khach hang \n";
        cin>>nguoi;
        cout<<"Nhap so luong ve hanh khach da mua: "; cin>>soluong;cin.ignore();
        ve=new Vemaybay[soluong];
        for(int i=0; i<soluong; i++)
        {   
            cout<<"stt: "<<i<<endl;
            ve[i].nhap();
            tong =tong+ve[i].getgiave();
        }
    }
    bool operator < (const Hanhkhach &v )
    {
        if(tong<v.tong)return true;
        return false;
    }
    void xuat()
    {   
        cout<<"\nThong tin khach hang \n"; cout<<nguoi;
        for(int i=0; i<soluong; i++)
        {
            ve[i].xuat();
        }
        
        cout<<"\nTong tien la: "<<tong<<endl;
    }
};
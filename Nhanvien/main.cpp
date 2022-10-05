#include "Nhanvien.h"
int main(int argc, char const *argv[])
{
    Nhanvien *nv = new Nhanvien;
    Nhanvien *nv2 = new Nhanvien;
    cin>>*nv;
    cin>>*nv2;
    cout<<nv;
    cout<<nv2;
    if(*nv>*nv2)cout<<"\nn1 win win win";
    else cout<<"\nn2 win win win";
    return 0;
}

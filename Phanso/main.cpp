#include"Phanso.h"
#include<algorithm>

int gcd(int a, int b)
{
    int maxx=max(a,b);
    while(a!=b)
    {
        if(maxx==a)a-=b;
        else b-=a;
        maxx=max(a,b);
    }
    return a;
}
int main()
{
    // Phanso a,b;
    // cin>>a>>b;
    // cout<<"Phep cong: "<<a+b<<endl;
    // cout<<"Phep tru: "<<a-b<<endl;
    // cout<<"Phep nhan: "<<a*b<<endl;
    // cout<<"Phep chia: "<<a/b<<endl;
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b);
}
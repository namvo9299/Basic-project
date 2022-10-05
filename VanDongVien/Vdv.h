#include<iostream>
#include<string>
using namespace std;
class VDV
{
    string hoten,monthidau;
    int tuoi;
    double cannang,chieucao;
    public:
    VDV(){}
    VDV(string hoten, int tuoi, string monthidau, double cannang, double chieucao)
        :hoten(hoten),tuoi(tuoi),monthidau(monthidau),cannang(cannang),chieucao(chieucao){}
    ~VDV(){}
    friend istream& operator >> (istream &is, VDV &v)
    {
        cout<<"Ten: ";          getline(is,v.hoten);fflush(stdin);
        cout<<"Tuoi: ";         cin>>v.tuoi;cin.ignore();
        cout<<"Mon thi dau: ";  getline(is,v.monthidau);fflush(stdin);
        cout<<"Can nang: ";     cin>>v.cannang;
        cout<<"Chieu cao: ";    cin>>v.chieucao;cin.ignore();
        return is;
    }
    friend ostream& operator << (ostream &os, VDV v)
    {
        cout<<"\nTen: ";          os<<v.hoten;
        cout<<"\nTuoi: ";         os<<v.tuoi;
        cout<<"\nMon thi dau: ";  os<<v.monthidau;
        cout<<"\nCan nang: ";     os<<v.cannang;
        cout<<"\nChieu cao: ";    os<<v.chieucao;
    }  
    bool operator > (const VDV &v )
    {
        if(chieucao>v.chieucao)return true;
        else if(chieucao=v.chieucao){if(cannang>v.cannang)return true;}
        return false;
    }
    void BubbleSort(VDV a[], int n)
{
    VDV temp; // biến tạm temp
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
        	if (a[j] > a[j+1]){
                        temp = a[j];
                        a[j] = a[j+1];
                        a[j+1] = temp;
		    }
	    }
    }
}
};
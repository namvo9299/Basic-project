#include"HanhKhach.h"
void swap(Hanhkhach &a, Hanhkhach &b)
{
    Hanhkhach temp = a;
    a = b;
    b = temp;
}
 
void Bubblesort(Hanhkhach arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] < arr[j + 1])
                swap(arr[j], arr[j + 1]);
}
int main()
{
    int n;
    cout << "Nhap so luong hanh khach: ";
    cin >> n;cin.ignore();
    Hanhkhach *h = new Hanhkhach[n];
    for(int i=0;i<n;i++)
    {
        h[i].nhap();
        cout<< endl <<"------------------"<<endl<<endl;
    }
    for(int i=0;i<n;i++)
    {
        h[i].xuat();
        cout<< endl <<"------------------"<<endl<<endl;
    }
    cout<<"------SORTING-------\n";
    Bubblesort(h,n);
    for(int i=0;i<n;i++)
    {
        h[i].xuat();
        cout<< endl <<"------------------"<<endl<<endl;
    }
}
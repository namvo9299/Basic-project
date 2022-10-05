#include"Vdv.h"
void swap(VDV &a, VDV &b)
{
    VDV temp = a;
    a = b;
    b = temp;
}
 
void Bubblesort(VDV arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

int main()
{
    VDV *p =new VDV("Nam",23,"Da banh",60,1.78);
    cout<<*p<<endl;
    int n;
    cin>>n;cin.ignore();
    VDV *a = new VDV[n];
    for(int i=0; i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0; i<n;i++)
    {
        cout<<a[i];
    }
    cout<<"\nSORTTTTTTTT\n";
    Bubblesort(a,n);
    for(int i=0; i<n;i++)
    {
        cout<<a[i];
    }

}
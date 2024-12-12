#include<iostream>
using namespace std;

int sumArr(int a[] ,int n )
{
if(n==0)
return 0;

return a[n-1]+sumArr(a,n-1);
}
int main()
{
int n;
cout << "Enter the number of element" << endl;
cin>> n;
int a[n];
for(int i=0;i<n;i++) 
{
    cin>> a[i];
}
int sum =sumArr(a,n);
cout<<sum<<endl;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class printi
{
public:
    void operator()(const int &a)
    {
        cout<<a<<endl;
    }
};
void quicksort(vector<int> &v,int l,int r);
int partition(vector<int> &v,int l,int r);

int main(void)
{
    int arr[10]={9,3,1,3,5,3,2,8,0,3};
    vector<int> v(arr,arr+10);
    quicksort(v,0,9);
    for_each(v.begin(),v.end(),printi());
    return 0;
}

void quicksort(vector<int> &v,int l,int r)
{
    if(l<r)
    {
        int pos=partition(v, l, r);
        quicksort(v,l,pos-1);
        quicksort(v,pos+1,r);
    }
}
int partition(vector<int> &v,int l,int r)
{
    int k=l,x=0,tmp=rand()%(r-l+1)+l;
    swap(v[tmp],v[r]);
    x=v[r];
    for(int i=l;i<=r;i++)
        if(v[i]<x) swap(v[i],v[k++]);
    swap(v[k],v[r]);
    return k;
}

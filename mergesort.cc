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
void mergesort(vector<int> &v,int l,int r);
void merge(vector<int> &v,int l,int mid,int r);

int main(void)
{
    int arr[10]={9,3,1,3,5,3,2,8,0,3};
    vector<int> v(arr,arr+10);
    mergesort(v,0,9);
    for_each(v.begin(),v.end(),printi());
    return 0;
}
void mergesort(vector<int> &v,int l,int r)
{
    if(l<r)
    {
        int mid=(l+r)>>1;
        mergesort(v, l, mid);
        mergesort(v, mid+1, r);
        merge(v,l,mid,r);
    }
}
void merge(vector<int> &v,int l,int mid,int r)
{
    int i=l,j=mid+1;
    vector<int> tmpv;
    while(i<=mid && j<=r)
    {
        if(v[i]<v[j])
            tmpv.push_back(v[i++]);
        else
            tmpv.push_back(v[j++]);
    }
    while(i<=mid)
        tmpv.push_back(v[i++]);
    while(j<=r)
        tmpv.push_back(v[j++]);
    for(int k=l,h=0;k<=r;k++,h++)
    {
        v[k]=tmpv[h];
    }
}

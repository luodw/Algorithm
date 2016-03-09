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
class compare
{
public:
    bool operator()(const int &a,const int &b)
    {
        return a>b;
    }
};

template<class comp>
void choosesort(vector<int> &v,comp &com)
{
    int length=v.size();
    for(int i=0;i<length-1;i++)
    {
        int temp=v[i];
        for(int j=i+1;j<length;j++)
        {
            if(com(v[j],temp))
                swap(temp,v[j]);
        }
        swap(v[i],temp);
    }
}

int main(void)
{
    int arr[10]={8,4,6,2,9,7,1,5,0,3};
    vector<int> vec(arr,arr+10);
    compare comp;
    choosesort(vec,comp);
    for_each(vec.begin(),vec.end(),printi());
    return 0;
}

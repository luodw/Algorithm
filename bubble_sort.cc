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
void bubblesort(vector<int> &v);

int main(void)
{
    int arr[10]={8,4,6,2,9,7,1,5,0,3};
    vector<int> vec(arr,arr+10);
    bubblesort(vec);
    for_each(vec.begin(),vec.end(),printi());
    return 0;
}

void bubblesort(vector<int> &v)
{
    int len=v.size();
    for(int i=0;i<len;i++)
        for(int j=0;j<len-i;j++)
            if(v[j]>v[j+1])
                swap(v[j],v[j+1]);
}

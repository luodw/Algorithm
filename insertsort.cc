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
void insertsort(vector<int> &v);

int main(void)
{
    int arr[10]={8,4,6,2,9,7,1,5,0,3};
    vector<int> vec(arr,arr+10);
    insertsort(vec);
    for_each(vec.begin(),vec.end(),printi());
    return 0;
}

void insertsort(vector<int> &v)
{
    int length=v.size();
    int temp=0;
    for(int i=1;i<length;i++)
    {
        if(v[i-1]>v[i])
        {
            temp=v[i];
            int j=i-1;
            while(j>=0 && v[j]>temp)
            {
                v[j+1]=v[j];
                j--;
            }
            v[j+1]=temp;
        }
    }
}

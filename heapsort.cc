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

//调整堆元素,使之符合堆结构
void max_heapify(vector<int> &v,int i,int heapsize);
//建立大顶堆,即从第一个非叶子节点开始调整
void build_max_heap(vector<int> &v);
void heapsort(vector<int> &v);

int main(void)
{
    int arr[10]={8,4,6,2,9,7,1,5,0,3};
    vector<int> vec(arr,arr+10);
    heapsort(vec);
    for_each(vec.begin(),vec.end(),printi());
    return 0;
}

void max_heapify(vector<int> &v,int i,int heapsize)
{
    int l=2*i+1,r=2*i+2;
    int largest=i;
    if(l<heapsize && v[l]>v[i])//当前值和左儿子节点比较
        largest=l;
    if(r<heapsize && v[r]>v[largest])//右节点和(父节点和左节点的最大值)比较
        largest=r;
    //上述就是找出三个数的最大值,所以v[r]>v[largest]容易出错
    if(largest!=i)
    {
        swap(v[i],v[largest]);
        max_heapify(v, largest,heapsize);//如果是第三层以上的节点进行调整,
        //则需要递归调整最大子节点,因为最大子节点和父交换之后,不满足最大堆
    }
}
void build_max_heap(vector<int> &v)
{
    int len=v.size();
    for(int i=len/2-1;i>=0;i--)
        max_heapify(v, i, len);//从第一个非叶子节点开始调整,即可创建一个最大堆
}

void heapsort(vector<int> &v)
{
    int len=v.size();
    build_max_heap(v);//堆排先创建堆
    for(int i=len-1;i>0;i--)
    {
        /*
        ,第一个节点始终为最大值,将第一个节点和最后节点交换,这样最后一个值肯定是最大值
        ,然后再调整第一个节点.这时要注意传进调整函数的长度i是递减的.
        */
        swap(v[0],v[i]);
        max_heapify(v, 0 ,i);
    }
}

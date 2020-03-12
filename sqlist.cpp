#include<iostream>
 using namespace std;

 const int maxSize=100;
 template <class DataType >
 class Seqlist{
 public:
     Seqlist(){length=0;}
     Seqlist(DataType a[],int n);
     ~Seqlist(){}
     int Length(){return length;}
     DataType Get(int i);
     int Locate(DataType x);
     void Insert(int i,DataType x);
    DataType Delete(int i);
    void PrintList();
private:
    DataType data[maxSize];
    int length;
 };
template <class DataType>
Seqlist<DataType>::Seqlist(DataType a[],int n)
{
    if(n>maxSize)
    {
     //   throw "wrong parameter";
    }
    for(int i=0;i<n;i++)
    {
        data[i]=a[i];
    }
    length=n;
}
template <class DataType>
DataType Seqlist<DataType>::Get(int i)
{
if(i<1||i>length)
{
   // throw "wrong location";
}
return data[i-1];

}

template <class DataType>
int Seqlist<DataType>::Locate(DataType x)
{
    for(int i=0;i<length;i++)
    {
        if(data[i]==x)
            return i+1;
    
    }
    return 0;
}

template <class DataType>
void Seqlist<DataType>::Insert(int i,DataType x)

{
if(length>=maxSize){throw "overflow";}
if(i<0||i>length+1){throw "wrong location";}
for(int j=length;j>=i;j--)
{
    data[j]=data[j-1];
}
data[i-1]=x;
length++;
}


template <class DataType>
DataType Seqlist<DataType>::Delete(int i)
{
    if(i<0||i>length)
    {
     //   throw "wrong Locate";
    }
    DataType x=data[i-1];
    for(int j=i;j<length;j++)
    {
        data[j-1]=data[j];
    }
    length--;
    return x;
}

template <class DataType>
void Seqlist<DataType>::PrintList()
{
for(int i=0;i<length;i++)
{
    cout<<data[i];
}
}

int main()
{
Seqlist<int> p;
p.Insert(1,3);
p.PrintList();
return 0;
}

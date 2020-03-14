#include<iostream>
 using namespace std;

 template <class DataType>
 struct Node
{
    DataType data;
    Node<DataType> *next;
};

template <class DataType>
class LinkList
{
public :
    LinkList();
    LinkList(DataType a[],int n);
    ~LinkList();
    int Length();
    DataType Get(int i);
    int locate(DataType x);
    void Insert(DataType x,int i);
    DataType Delete(int i);
    void PrintList();
private:
    Node<DataType> *first;

};

template<class DataType>
LinkList<DataType>::LinkList()
{
    first=new Node<DataType>;
    first->next=nullptr;
}

template <class DataType>
LinkList<DataType>::LinkList(DataType a[],int n)
{
    first=new Node<DataType>;
    first->next=nullptr;
    for(int i=0;i<n;i++)
    {
        Node<DataType> *s=new Node<DataType>;
        s->data=a[i];
        s->next=first->next;
        first->next=s;
    }
}

template<class DataType>
LinkList<DataType>::~LinkList()
{
    while(first!=nullptr)
    {
        Node<DataType> *q=first;
        first=first->next;
        delete q;
    }
}


template<class DataType>
int LinkList<DataType>::Length()
{
    Node<DataType>* p = first->next;
	int count = 0;
	while (p != NULL)
	{
		p = p->next;
		count++;
	}
	return count;
}

template<class DataType>
DataType LinkList<DataType>::Get(int i)
{
	Node<DataType>* p = first->next;
	int count = 1;
	while (p != NULL && count<i)
	{
		p = p->next;
		count++;
	}
	if (p == NULL) throw "Location";
	else return p->data;
}

template<class DataType>
int LinkList<DataType>::locate(DataType x)
{
	Node<DataType> *p = first->next;
	int count = 1;
	while (p != NULL)
	{
		if (p->data == x) return count;
		p = p->next;
		count++;
	}
	return 0;
}

template<class DataType>
void LinkList<DataType>::Insert(DataType x,int i)
{
    Node<DataType> *p=first;
    int count=0;
    
        while(p!=NULL&&count<i-1)
        {
            p=p->next;
            count++;
        }
        Node<DataType> *s=new Node<DataType>;
        s->data=x;
        s->next=p->next;
        p->next=s;
        
    
}

template<class DataType>
DataType LinkList<DataType>::Delete(int i)
{
Node<DataType> *p=first;
int count=0;
while(p!=NULL&&count<i-1)
{
    p=p->next;
    count++;

}
	Node<DataType> *q = p->next;
    DataType x=q->data;
p->next=q->next;
return x;
}

template<class DataType>
void LinkList<DataType>::PrintList()
{
	Node<DataType> *p = first->next;
	while (p != NULL)
	{
		cout << p->data << endl;
		p = p->next;
	}
}

int main()
{
    LinkList<int> p;
    p.Insert(5,1);
    p.PrintList();
    return 0;
}

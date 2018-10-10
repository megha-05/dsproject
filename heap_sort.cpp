#include<iostream>
#include<conio.h>
using namespace std;

void maxheapify(int a[],int i,int n)
{
	int j,temp;
	temp=a[i];
	j=2*i;
	while(j<=n)
	{
		if((j<n)&&(a[j]<a[j+1]))
		j=j+1;
		if(temp>a[j])
		break;
		else if(temp<=a[j])
		{
			a[j/2]=a[j];
			j=2*j;
		}

	}
	a[j/2]=temp;
	return;
}
void buildMaxHeap(int a[],int n)
{
  int i;
  for(i=n/2;i>=1;i--)
   maxheapify(a,i,n);
}
void heapdsort(int a[],int n)
{
	int i,temp;
	for(i=n;i>=2;i--)
	{
		temp=a[i];
		a[i]=a[1];
		a[1]=temp;
		maxheapify(a,1,i-1);
	}
}
void display(int a[],int n)
{
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
}
int main()
{
	int a[100],i,n;
	cout<<"enter no of elments";
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	buildMaxHeap(a,n);
	heapdsort(a,n);
	display(a,n);
    getch();	
	
}

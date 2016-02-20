/*

Code Author : Shyam Singh
For any doubt, email me on shyam81295@gmail.com

Problem : Maximum Sum
Type : Segment tree

*/

#include<stdio.h>
#include<bits/stdc++.h>
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define MIN(a, b) ((a) >= (b) ? (b) : (a))
#define EPS -1
using namespace std;

struct node
{
	//	node structure
	long max1;
	long max2;
};

const int N = 100005;  // limit for array size
long n;  // array size
node t[2 * N];
long to_sort[10];

node combine(node l,node r)
{
	node res;
	to_sort[0] = l.max1;
	to_sort[1] = l.max2;
	to_sort[2] = r.max1;
	to_sort[3] = r.max2;

	sort(to_sort,to_sort+4);
	res.max1 = to_sort[3];
	res.max2 = to_sort[2];
	return res;
}

//	to assign values to nodes, it is imp
//	without it, it gives error
void assign_value(node* l,long val)
{
	l->max1 = val;
	l->max2 = 0;
}

void build()
{
	for(long i=n-1;i>0;i--)
	{
		t[i] = combine(t[i<<1],t[i<<1|1]);
	}
}

void update(long pos,long xval)
{
	long a,b;
	pos +=n;
	assign_value(&t[pos],xval);
	for( ;pos>1;pos>>=1)
	{
		//	if else is much needed because combine function for this case
		//	is sensitive for left and right function parameter,
		//	left parameter must be less than right parameter to work correctly.
		if(pos > (pos^1))
		{
			a = pos^1;
			b = pos;
		}
		else
		{
			a = pos;
			b = pos^1;
		}
		t[pos>>1] = combine(t[a],t[b]);
	}
}

node query(long l, long r)
{
	node resl,resr;
	//	always use assign func whenever
	//	we have to assign to some node a value
	//	we cant use '=' here because of structure.
	assign_value(&resl,EPS);
	assign_value(&resr,EPS);
	for(l += n, r += n; l<r; l>>=1 , r>>=1)
	{
		if(l&1)
		{
			resl = combine(resl,t[l++]);
		}
		if(r&1)
		{
			resr = combine(t[--r],resr);
		}
	}
	return combine(resl,resr);
}

int main()
{
	long Q,A,B,i,j,p,q;
	char ch;
	node xnode;
	scanf("%ld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%ld",&p);
		//	leaf nodes init
		t[i+n].max1 = p;
		t[i+n].max2 = 0;
	}
	build();
	scanf("%ld",&Q);
	for(i=0;i<Q;i++)
	{
		cin>>ch>>A>>B;
		if(ch=='Q')
		{
			 xnode = query(A-1,B);
			 printf("%ld\n",xnode.max1+xnode.max2);
		}
		else
		{
			update(A-1,B);
		}
	}
	return 0;
}

/*

Code Author : Shyam Singh
For any doubt, email me on shyam81295@gmail.com

Problem : Can you solve these query 1
Type : Segment Tree

*/

#include<bits/stdc++.h>
#define MAX(a,b) ((a>b)?(a):(b))
#define MAXN 50005

using namespace std;

struct node
{
	long left_max;
	long right_max;
	long sum;
	long best;
};

long arr[MAXN];
node seg_tree[4*MAXN];

void build_tree(long p,long a,long b)
{
	//	leaf node
	if(a==b)
	{
		seg_tree[p].sum = arr[a];
		seg_tree[p].best = arr[a];
		seg_tree[p].left_max = arr[a];
		seg_tree[p].right_max = arr[a];
		return;
	}
	//	internal node
	long mid = (a+b)/2;
	build_tree(p<<1,a,mid);
	build_tree((p<<1)+1,mid+1,b);
	seg_tree[p].sum = seg_tree[p<<1].sum + seg_tree[(p<<1)+1].sum;
	seg_tree[p].left_max = MAX(seg_tree[p<<1].left_max, seg_tree[p<<1].sum + seg_tree[(p<<1)+1].left_max);
	seg_tree[p].right_max = MAX(seg_tree[(p<<1)+1].right_max, seg_tree[(p<<1)+1].sum + seg_tree[p<<1].right_max);
	seg_tree[p].best = MAX( MAX(seg_tree[p<<1].best, seg_tree[(p<<1)+1].best) , seg_tree[p<<1].right_max + seg_tree[(p<<1)+1].left_max) ;
	return;
}

node query(long p,long nis,long nie,long qis,long qie)
{
	node res,q1,q2;
	//	node interval completely inside (qis,qie)
	if(nis>=qis && nie <= qie)
	{
		res = seg_tree[p];
		return res;
	}

	long mid = (nis+nie)/2;
	//	query is for left part
	if(qie<=mid)
	{
		return query(2*p,nis,mid,qis,qie);
	}
	//	query is for right part
	if(qis>mid)
	{
		return query((2*p)+1,mid+1,nie,qis,qie);
	}
	//	if query is for (left + right) part
	q1 = query(2*p,nis,mid,qis,mid);
	q2 = query((2*p)+1,mid+1,nie,mid+1,qie);
	res.sum = q1.sum + q2.sum;
	res.left_max = MAX(q1.left_max, q1.sum + q2.left_max);
	res.right_max = MAX(q2.right_max, q2.sum + q1.right_max);
	res.best = MAX( MAX(q1.best, q2.best) , q1.right_max + q2.left_max) ;
	return res;
}

int main()
{
	long i,j,a,b,B,N,M,l,r;
	node A;
	scanf("%ld",&N);
	for(i=0;i<N;i++)
	{
		scanf("%ld",&arr[i]);
	}
	build_tree(1,0,N-1);
	scanf("%ld",&M);
	for(i=0;i<M;i++)
	{
		scanf("%ld %ld",&l,&r);
		A = query(1,0,N-1,l-1,r-1);
		printf("%ld\n",A.best);
	}
	return 0;
}

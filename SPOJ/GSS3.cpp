/*

Code Author : Shyam Singh
For any doubt, email me on shyam81295@gmail.com

Problem : Can you solve these queries 3
Type : Segment Tree

*/

#include<bits/stdc++.h>
#define MAX(a,b) ((a>b)?(a):(b))
#define MAXN 50005
#define INF                         (int)1e9
#define EPS                         -100000
using namespace std;

struct node
{
	//	node structure
	long left_max;
	long right_max;
	long sum;
	long best;
};

const int N = 50005;  // limit for array size
long n;  // array size
node t[2 * N];

void assign_value(node* l,long val)
{
	l->sum = val;
	l->best = val;
	l->left_max = val;
	l->right_max = val;
}

node combine(node l, node r)
{
	node res;
	res.sum = l.sum + r.sum;
	res.left_max = MAX( l.left_max ,  l.sum + r.left_max );
	res.right_max = MAX( r.right_max , (r.sum + l.right_max ));
	res.best = MAX( MAX( l.best , r.best) , (l.right_max + r.left_max));
	return res;
}

void build() {  // build the tree
	for (long i = n - 1; i > 0; --i)
	{
		t[i] = combine(t[i<<1],t[i<<1|1]);
	}
}

void modify(long p, long val) {  // set value at position p
	assign_value(&t[p+n],val);
	long a,b;
	p += n;
	for ( ; p > 1; p >>= 1)
	{
		//	if else is much needed because combine function for this case
		//	is sensitive for left and right function parameter,
		//	left parameter must be less than right parameter to work correctly.
		if(p > (p^1))
		{
			a = p^1;
			b = p;
		}
		else
		{
			a = p;
			b = p^1;
		}
		t[p>>1] = combine(t[a],t[b]);
	}
}

node query(long l, long r)
{
	// sum on interval [l, r)
	node resl,resr ,res	;
	assign_value(&resl,EPS);
	assign_value(&resr,EPS);
	for (l += n, r += n; l < r; l >>= 1, r >>= 1)
	{
		if (l&1)
		{
			resl = combine(resl,t[l++]);
		}
		if (r&1)
		{
			resr = combine(t[--r],resr);
		}
	}
	res = combine(resl,resr);
	return res;
}

int main() {
	long a,l,r,choice,m;
	node A;
	scanf("%ld", &n);
	//	leaf node initialisation
	for (long i = 0; i < n; ++i)
	{
		scanf("%ld", &a);
		assign_value(&t[i+n],a);
	}
	build();
	scanf("%ld",&m);
	for(long i = 0;i<m;i++)
	{
		scanf("%ld %ld %ld",&choice,&l,&r);
		if(!choice)
			modify(l-1,r);
		else
		{
			A = query(l-1,r);
			printf("%ld\n",A.best);
		}
	}
	return 0;
}

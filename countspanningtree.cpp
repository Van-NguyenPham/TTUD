#include <bits/stdc++.h>
#define MAX 21
using namespace std;
int n,m;
vector <int> A[MAX];
int b[MAX], e[MAX], X[MAX];
int ans = 0;
int r[MAX];//rank
int p[MAX];//parent
long long rs = 0;
void link(int x, int y)
{
	if(r[x] > r[y])
	{
		p[y] = x;
	}
	else
	{
		p[x] = y;
		if(r[x] == r[y])
		{
			r[y]++;
		}
	}
}
void makeSet(int x)
{
	p[x] = x;
	r[x] = 0;
}
int findSet(int x)
{
	if(x != p[x])
	{
		p[x] = findSet(p[x]);
	}
	return p[x];
}
int check(int val, int k)
{
	for(int i = 1; i <= N; i++)
	{
		makeSet(i);
	}
	for(int j = 1; j < k; j++)
	{
		int u = b[X[j]];
		int v = e[X[j]];
		int ru = findSet(u);
		int rv = findSet(v);
		if(ru ==rv)
		{
			return 0;
		}
		link(ru,rv);
	}
	if(findSet(b[val]) == findSet(e[val]))
	{
		return 0;
	}
	return 1;
}
void solution()
{
	ans++;
}
void TRY(int k)
{
	for(int v = X[k-1] + 1; v <= M; v++)
	{
		int ok = check(v, k);
	}
}
void solve()
{
	ans = 0; 
	rs = 0;
	TRY(1);
}
int main()
{
	cin>>n>>m;
	for(int i = 1; i <= m; i++)
	{
		int u, v;
		cin>>u>>v;
		A[u].push_back(v);
		B[v].push_back(u);
		b[i] = u;
		e[i] = v;
	}
	solve();
	cout<<ans;
	return 0;
}

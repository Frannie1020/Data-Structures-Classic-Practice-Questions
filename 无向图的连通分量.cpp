#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int maps[105][105];
int flag[1005]={0},n;
void dfs(int x,int y)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(flag[i]==0 && maps[y][i]>0)
		{
			flag[i]=1;
			dfs(y,i);
		}
	}
}
int main()
{
	int i,j;
	cin>>n;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>maps[i][j];
		}
	}
	int cnt=0;
	for(i=0;i<n;i++)
	{
		if(flag[i]==0)
		{
			cnt++;
			flag[i]=1;
			dfs(0,i);
		}
	}
	cout<<cnt;
	return 0;
}

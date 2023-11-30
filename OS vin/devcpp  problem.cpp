#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> v(5);
	
	for(int i=0;i<5;i++)
	{
		cin>>v[i];
	}
	
	for(auto i:v)
	{
		cout<<i<<"\t";
	}
	
	return 0;
}

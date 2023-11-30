#include<bits/stdc++.h>
using namespace std;
int main()
{
	int process,res;
	cout<<"Enter number of process: ";
	cin>>process;
	cout<<"Enter number of resources: ";
	cin>>res;
	int allocation[100][100],maximum[100][100],need[100][100],available[100];
	cout<<"\nEnter allocation for each process: \n";
	for(int i=0;i<process;i++)
	{
		for(int j=0;j<res;j++)
		{
			cin>>allocation[i][j];
		}
	}
	cout<<"\nEnter maximum need for each process: \n";
	for(int i=0;i<process;i++)
	{
		for(int j=0;j<res;j++)
		{
			cin>>maximum[i][j];
		}
	}
	cout<<"\nEnter available resources: ";
	for(int i=0;i<res;i++)
	{
		cin>>available[i];
	}
	//calculate need matrix
	for(int i=0;i<process;i++)
	{
		for(int j=0;j<res;j++)
		{
			need[i][j]=maximum[i][j]-allocation[i][j];
		}
	}
	cout<<"\n\nNeed matrix is as follows: \n";
	for(int i=0;i<process;i++)
	{
		for(int j=0;j<res;j++)
		{
			cout<<need[i][j]<<" ";
		}
		cout<<"\n";
	}
	int cnt=0,i=0;
	bool *check=new bool[process]{0};
	vector<int> ans;
	while(true)
	{
		if(cnt==process)
		{
			break;
		}
		if(check[i%process]==false)
		{
			bool flag=1;
			for(int j=0;j<res;j++)
			{
				if(need[i%process][j]>available[j])
				{
					flag=0;
				}
			}
			if(flag==1)
			{
				for(int j=0;j<res;j++)
				{
					available[j]+=allocation[i%process][j];
				}
				
				check[i%process]=true;
				ans.push_back(i%process);
				cnt++;
			}
		}	
		i++;
	}
	cout<<"\n\nSafe sequence to avoid deadlock is as follows: \n";
	for(int i=0;i<ans.size();i++)
	{
		cout<<"p"<<ans[i]<<" ";
	}
	cout<<"\n";
	int p_no;
	cout<<"Enter the process no: ";
	cin>>p_no;
	
	int request[res];
	for(int i=0;i<n;i++)
	{
		cin>>request[i];
	}
	int num=0;
	for(int i=0;i<res;i++)
	{
		if(need[p_no][i]>=request[i])
		num++;
	}
	num=0;
	if(num==res)
	{
			for(int i=0;i<res;i++)
		{
			if(available[i]>=request[i])
			num++;
		}
		if(num==res)
		flag=0;
	}
	else
	{
		flag=1;
	}
	if(flag==1)
	cout<<"cannot fullfileed request"<<endl
	else
	{
		cout<<"request fullfilled"<<endl;
		for(int i=0;i<res;i++)
		{
			need[p_no][i]-=request[i];
			available[i]+=request[i];
		}
	}
	
	
	return 0;
}

/*

Enter number of process: 5
Enter number of resources: 3
Enter allocation for each process: 
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
Enter maximum need for each process: 
7 5 3
3 2 2
9 0 2
4 2 2
5 3 3
Enter available resources: 3 3 2
Need matrix is as follows: 
7 4 3 
1 2 2 
6 0 0 
2 1 1 
5 3 1 

Safe sequence to avoid deadlock is as follows: 
p1 p3 p4 p0 p2 

*/

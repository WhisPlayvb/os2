#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cout<<"Process: ";
	cin>>n;
	
	int index[n],bt[n],ct[n],pr[n],tat[n],wt[n];
	float avtat=0,avwt=0;

	//int at[n]={0,0,0,0};
	//jugad for with arrival time
	
	cout<<"Burst: \n";
	
	for(int i=0;i<n;i++)
	{
		cin>>bt[i];
		index[i]=i;
	}
	
	
	cout<<"\nPriority: \n";
	
	for(int i=0;i<n;i++)
	{
		cin>>pr[i];
	}
	
	
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(pr[i]>pr[j])//if lowest number=highest priority
			{
				swap(pr[i],pr[j]);
				swap(bt[i],bt[j]);
				swap(index[i],index[j]);
			}
		}
	}
	
	
	ct[0]=bt[0];
	
	for(int i=1;i<n;i++)
	{
		ct[i]=ct[i-1]+bt[i];
	}
	
	
	for(int i=0;i<n;i++)
	{
		tat[i]=ct[i];
		//with arrival ct[i]-at[i]
	}
	
	for(int i=0;i<n;i++)
	{
		wt[i]=tat[i]-bt[i];
	}
	
	for(int i=0;i<n;i++)
	{
		avtat+=tat[i];
		avwt+=wt[i];
	}
	
	cout<<"\n\n";
	
	cout<<"\n\n--------------------------------------------------------------------\n\n";
	
	cout<<"Process ID\tBurst Time\tWaiting time\tTurnaround time\n";
	for(int i=0;i<n;i++)
	{
		cout<<"p["<<index[i]+1<<"]"<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<"\n";
	}
	
	cout<<"\n\nAverarge waiting time: "<<float(avwt/n);
	cout<<"\nAverage turnaround time: "<<float(avtat/n);
	
	cout<<"\n\n--------------------------------------------------------------------\n\n";
	
	return 0;
}

/*

Process: 5
Burst: 
3 4 2 1 3
Priority: 
1 3 2 1 4
--------------------------------------------------------------------

Process ID	Burst Time	Waiting time	Turnaround time
p[1]		3		0		3
p[4]		1		3		4
p[3]		2		4		6
p[2]		4		6		10
p[5]		3		10		13


Averarge waiting time: 4.6
Average turnaround time: 7.2

--------------------------------------------------------------------



*/
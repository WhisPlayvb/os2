#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cout<<"\nEnter number of process: ";
	cin>>n;
	
	int at[n],bt[n],ct[n],wt[n],tat[n];
	float avwt=0,avtat=0;
	
	cout<<"\nEnter arrival time: \n";
	for(int i=0;i<n;i++)
	{
		cout<<"p["<<i+1<<"]: ";
		cin>>at[i];
	}
	
	cout<<"\n\nEnter burst time: \n";
	for(int i=0;i<n;i++)
	{
		cout<<"p["<<i+1<<"]: ";
		cin>>bt[i];
	}
	
	//completion time
	ct[0]=bt[0];
	for(int i=1;i<n;i++)
	{
		ct[i]=ct[i-1]+bt[i];
		if(at[i]>ct[i-1])//cpu becomes idle
		{
			ct[i]+=1;
		}
	}	
	
	//turnaround time
	for(int i=0;i<n;i++)
	{
		tat[i]=ct[i]-at[i];
	}
	
	//waiting time
	//wt[0]=0;
	for(int i=0;i<n;i++)
	{
		wt[i]=tat[i]-bt[i];
	}
	
	//average waiting time & turnaround time
	for(int i=0;i<n;i++)
	{
		avwt+=wt[i];
		avtat+=tat[i];
	}
	
	cout<<"\n\n------------------------------------------------------------------------------\n\n";
	
	cout<<"Process ID\tArrival time\tBurst Time\tWaiting time\tTurnaround time\n";
	for(int i=0;i<n;i++)
	{
		cout<<i+1<<"\t\t\t"<<at[i]<<"\t\t\t"<<bt[i]<<"\t\t\t"<<wt[i]<<"\t\t\t"<<tat[i]<<"\n";
	}
	
	cout<<"\n\nAverarge waiting time: "<<float(avwt/n);
	cout<<"\nAverage turnaround time: "<<float(avtat/n);
	
	cout<<"\n\n------------------------------------------------------------------------------\n\n";
	
	return 0;
}

/*


Enter number of process: 4
Enter arrival time: 
p[1]: 0
p[2]: 1
p[3]: 5
p[4]: 6
Enter burst time: 
p[1]: 2
p[2]: 2
p[3]: 3
p[4]: 4
------------------------------------------------------------------------------

Process ID	Arrival time	Burst Time	Waiting time	Turnaround time
1			0			2			0			2
2			1			2			1			3
3			5			3			0			3
4			6			4			2			6


Averarge waiting time: 0.75
Average turnaround time: 3.5

------------------------------------------------------------------------------



*/

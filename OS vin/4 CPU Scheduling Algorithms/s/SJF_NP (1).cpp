#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	
	cout<<"Enter number of process: ";
	cin>>n;
	
	int at[n],bt[n],ct[n],tat[n],wt[n];
	float avwt=0,avtat=0;
	
	cout<<"\n\nEnter arrival time: \n";
	
	for(int i=0;i<n;i++)
	{
		cout<<"p["<<i+1<<"]: ";
		cin>>at[i];
	}
	
	cout<<"\nEnter burst time: \n";
	for(int i=0;i<n;i++)
	{
		cout<<"p["<<i+1<<"]: ";
		cin>>bt[i];
	}
	
	int temp;
	
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(bt[i]>bt[j])
			{
				swap(bt[i],bt[j]);
				
				swap(at[i],at[j]);
			}
		}
	}
	
	
	int min,d;
	min=at[0];
	
	for(int i=0;i<n;i++)
	{
		if(min>at[i])
		{
			min=at[i];
			d=i;
		}
	}
	
	int tt;
	tt=min; //pointer
	ct[d]=tt+bt[d]; //completion time of first process
	tt=ct[d];
	
	for(int i=0;i<n;i++) //calculate completion time
	{
		if(at[i]!=min) //ct for min is calculates already
		{
			ct[i]=tt+bt[i];
			tt=ct[i];
		}
	}	
	
	for(int i=0;i<n;i++)  //calculate tat and wt
	{
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt[i];
		avtat+=tat[i];
		avwt+=wt[i];
	}
	
	cout<<"\n\n------------------------------------------------------------------------------\n\n";
	
	cout<<"Process ID\tArrival time\tBurst Time\tWaiting time\tTurnaround time\n";
	for(int i=0;i<n;i++)
	{
		cout<<i+1<<"\t\t"<<at[i]<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<"\n";
	}
	
	cout<<"\n\nAverarge waiting time: "<<float(avwt/n);
	cout<<"\nAverage turnaround time: "<<float(avtat/n);
	
	cout<<"\n\n------------------------------------------------------------------------------\n\n";
	
	
	return 0;
}



/*

/tmp/YercGtLfyS.o
Enter number of process: 5
Enter arrival time: 
p[1]: 1
p[2]: 2
p[3]: 3
p[4]: 4
p[5]: 5
Enter burst time: 
p[1]: 7
p[2]: 5
p[3]: 1
p[4]: 2
p[5]: 8
------------------------------------------------------------------------------

Process ID	Arrival time	Burst Time	Waiting time	Turnaround time
1		3		1		5		6
2		4		2		5		7
3		2		5		9		14
4		1		7		0		7
5		5		8		11		19


Averarge waiting time: 6
Average turnaround time: 10.6

------------------------------------------------------------------------------



*/
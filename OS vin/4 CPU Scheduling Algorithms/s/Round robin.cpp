#include<iostream>
using namespace std;

void find_tat(int burst_time[],int size,int wt[],int tat[])
{
	for(int i=0;i<size;i++)
	{
		tat[i] = burst_time[i] + wt[i];
	}
}

void find_wt(int burst_time[],int size,int wt[],int quantum_time)
{
	int copy_bt[size];
	
	for(int i=0;i<size;i++)
	{
		copy_bt[i] = burst_time[i];
		
	}
	
	int time=0;
	
	while(1)
	{
		bool done = true;
		
		for(int i=0;i<size;i++)
		{
			if(copy_bt[i]>0)
			{
				done = false;
				
				if(copy_bt[i]>quantum_time)
				{
					time+= quantum_time;
					
					copy_bt[i]-= quantum_time;
					
				}

				else
				{
					time+= copy_bt[i];
					
					wt[i] = time - burst_time[i];
					
					copy_bt[i] = 0;	
				}
			}
		}
		
		if(done==true)
		{
			break;
		}
	}
}

void findAvgTime_round_robin(int process[],int size,int burst_time[],int quantum_time)
{
	int wt[size],tat[size];
	int total_wt=0;
	int total_tat = 0;
	
	find_wt(burst_time,size,wt,quantum_time);
	
	find_tat(burst_time,size,wt,tat);
	
	cout<<"\n -------------- Round Robin ------------------ \n\n";
	
	cout<<"Process "<<"\t"<<" Burst Time "<<"\t"<<" WT "<<"\t"<<" TAT \n";
	
	for(int i=0;i<size;i++)
	{
		cout<<process[i]<<"\t"<<burst_time[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<"\n";
		
		total_wt+= wt[i];
		total_tat+= tat[i];
		
	}
	
	cout<<"\n\nAverage waiting time : "<<(float)total_wt/(float)size<<"\n";
	cout<<"\nAverage tat : "<<(float)total_tat/(float)size<<"\n";
		
}

int main()
{
	int process[] = {1,2,3};
	
	int burst_time[] = {10,5,8};
	
	int quantum_time = 2;
	
	int size = sizeof process / sizeof process[0];
	
	findAvgTime_round_robin(process,size,burst_time,quantum_time);
	
	return 0;
}

/*

-------------- Round Robin ------------------ 

Process 	 Burst Time 	 WT 	 TAT 
1	10	13	23
2	5	10	15
3	8	13	21
Average waiting time : 12

Average tat : 19.6667

*/

	#include<iostream>
	#include<algorithm>
	using namespace std;
	struct process
	{
	   int at;
	   int bt;
	   int wt;
	   int tat;
	   int st;
	   int ct;
	};
	bool comp(process a,process b)
	{
		if(a.at<=b.at)
		return true;
		return false;
	}
	int main()
	{
		int n=4;
	//	cout<<"Enter the no of process: ";
	//	cin>>n;
		process p[n];
	//	for(int i=0;i<n;i++)
	//	{
	//		cout<<"Enter the arrival time for process P"<<i<<" : ";
	//		cin>>p[i].at;
	//		cout<<"Enter the burst time for process P"<<i<<" : ";
	//		cin>>p[i].bt;
	//		cout<<endl;
	//	}
		int at[n]={0,1,5,6};
		int bt[n]={2,2,3,4};
		for(int i=0;i<n;i++)
		{	p[i].at=at[i];
			p[i].bt=bt[i];
		}	
		sort(p,p+n,comp);  
		//sorting the process according to their arrival time
		
	int currtime=0;
	int i=0;
	while(i!=n)
	{
		if(currtime<p[i].at)   //5
		currtime+=1;
		else
		{
			p[i].st=currtime;   
			currtime+=p[i].bt;
			p[i].ct=currtime;    //4
			p[i].tat=p[i].ct-p[i].at;    //tat=ct-at
			p[i].wt=p[i].tat-p[i].bt;     //wt=tat-bt
			i++;	
		}
	}
	
	//for(int i=0;i<n;i++)
	//{
	//	if(cu)
	//	p[i].st=currtime;
	//	currtime+=p[i].bt;
	//	p[i].ct=currtime;
	//	p[i].tat=p[i].ct-p[i].at;
	//	p[i].wt=p[i].tat-p[i].bt;
	//}
		
		cout<<"Process\tAT\tBT\tWT\tTAT"<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<"P"<<i<<"     \t"<<p[i].at<<" \t"<<p[i].bt<<" \t"<<p[i].wt<<" \t"<<p[i].tat<<endl;
		}
		
		float avgwt,avgtat;
		for(int i=0;i<n;i++)
		{
			avgwt+=p[i].wt;
			avgtat+=p[i].tat;
		}
		
		cout<<"Averge waiting time is: "<<avgwt/n<<endl;
		cout<<"Averge turnaround time is: "<<avgtat/n<<endl;
		
	}
	//Process AT      BT      WT      TAT
	//P0      0       2       0       2
	//P1      1       2       1       3
	//P2      5       3       0       3
	//P3      6       4       2       6
	//Averge waiting time is: 0.75
	//Averge turnaround time is: 3.5

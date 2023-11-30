#include <iostream>
using namespace std;
int main()
{
int nopages, nofaults, page[20], i, count = 0;
cout << "\n\t Enter no of pages for which you want to calculate page faults:>";
cin >> nopages; // it will store the number of Pages
cout << "\n\t Enter the Reference String:";
for (i = 0; i < nopages; i++)
{
cout << "\t";
cin >> page[i];
}
cout << "\n\t Enter the Number of frames:";
cin >> nofaults;
int frame[nofaults], fcount[nofaults];
for (i = 0; i < nofaults; i++)
{
frame[i] = -1;
fcount[i] = 0; 
// it will keep the track of when the page was last used
}
i = 0;
while (i < nopages)
{
int j = 0, flag = 0;
while (j < nofaults)
{
if (page[i] == frame[j])
{ // it will check whether the page already exist in frames or not
flag = 1;
fcount[j] = i + 1;
}
j++;
}
j = 0;
cout << "\n\t***\n";
cout << "\t" << page[i] << "-->";
if (flag == 0)
{
int min = 0, k = 0;
while (k < nofaults - 1)
{
if (fcount[min] > fcount[k + 1]) 
// It will calculate the page which is least recently used
min = k + 1;
k++;
}
frame[min] = page[i];
fcount[min] = i + 1; // Increasing the time
count++; // it will count the total Page Fault
while (j < nofaults)
{
cout << "\t|" << frame[j] << "|";
j++;
}
}
i++;
}
cout << "\n\t***\n";
cout << "\n\t Page Fault:" << count << endl;
return 0;
}

/*
/tmp/wBgKfKm90j.o
Enter no of pages for which you want to calculate page faults:>20
Enter the Reference String:	7 2 3 1 2 5 3 4 6 7 7 1 0 5 4 6 2 3 0 1
Enter the Number of frames:3
***
	7�>	|7|	|-1|	|-1|
	***
	2�>	|7|	|2|	|-1|
	***
	3�>	|7|	|2|	|3|
	***
	1�>	|1|	|2|	|3|
	***
	2�>
	***
	5�>	|1|	|2|	|5|
	***
	3�>	|3|	|2|	|5|
	***
	4�>	|3|	|4|	|5|
	***
	6�>	|3|	|4|	|6|
	***
	7�>	|7|	|4|	|6|
	***
	7�>
	***
	1�>	|7|	|1|	|6|
	***
	0�>	|7|	|1|	|0|
	***
	5�>	|5|	|1|	|0|
	***
	4�>	|5|	|4|	|0|
	***
	6�>	|5|	|4|	|6|
	***
	2�>	|2|	|4|	|6|
	***
	3�>	|2|	|3|	|6|
	***
	0�>	|2|	|3|	|0|
	***
	1�>	|1|	|3|	|0|
	***

	 Page Fault:18
*/


#include<bits/stdc++.h>
using namespace std;

struct job
{
	int dl;
	int profit;
	char id;
};

vector<int> parent;
vector<char> ans;

bool cmp(job a, job b)
{
    return (a.profit > b.profit);
}

void initialize( int n)
{
    for(int i = 0; i <= n; i++)
    {
       parent.push_back(i) ;
    }
}

int find (int i)
{
    while(i != parent[i])
    {
    	i = parent[i];	
    }
    return i;
}

void merge(int u, int v)
{
    parent[v] = u;
}

void show()
{
	cout<<"\n";
	for(int i = 0; i < parent.size(); i++)
	{
		cout<<parent[i]<<"\t";
	}
}

int main()
{
	int n, i, max_dl = 0;
	cout<<"enter the no of jobs : ";
	cin>>n; 
	job arr[n];

	cout<<"for each job give information : \n";
	for(i = 0; i < n; i++)
	{
		cin>>arr[i].dl;
		cin>>arr[i].profit;
		arr[i].id = (char)('a' + i);
		max_dl = max(max_dl, arr[i].dl);
	}

	initialize(max_dl+1);  //initializing to each element as its own root.
	sort(arr, arr + n, cmp);

	int max_profit  = 0;
	for(i = 0; i < n; i++)
	{
		int avl_slot = find(arr[i].dl);
		if(avl_slot > 0)
		{
			merge(find(avl_slot-1), avl_slot);
			ans.push_back(arr[i].id);
			cout<<arr[i].id<<"\t";
			max_profit += arr[i].profit;
		}
	}
	cout<<"\nmaximum profit is : "<<max_profit<<"\n";
	//show();
	return 0;
}
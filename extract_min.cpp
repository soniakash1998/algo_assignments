#include<bits/stdc++.h>
using namespace std;

deque<int>q;

void delete_min_from_queue(int min_val)
{
	size_t size = q.size();
	while(size -- > 0)
	{
		int front_value = q.front();
		q.pop_front();
		if(front_value == min_val)
		{
			break;
		}
		q.push_back(front_value);
	}
}

int extract_min()
{
	int front_value;
	int min_val = INT_MAX;
	size_t size = q.size();
	while(size-- > 0)
	{
		int front_value = q.front();
		q.pop_front();
		if(front_value < min_val)
		{
			min_val = front_value;
		}
		q.push_back(front_value);
	}
	delete_min_from_queue(min_val);
	return min_val;
}

int main()
{
	int n, i, temp;
	s.push(INT_MAX);

	cout<<"Enter the no of elements : ";
	cin>>n;
	cout<<"Enter the elements : ";
	for(i = 0; i < n; i++)
	{
		cin>>temp;
		q.push_back(temp);
	}
	cout<<"first minimum element in queue is : "<<extract_min()<<"\n";
	cout<<"second minimum element in queue is : "<<extract_min()<<"\n";
	return 0;
}
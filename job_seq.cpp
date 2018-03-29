#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool sortinrev(const pair<int,int> &a,const pair<int,int> &b){
       return (a.first > b.first);
}

int main(){

	int n;
	cout << "Enter Number of Jobs : " << endl;
	cin >>  n;

	int p[n],d[n]; //profits //deadlines
	vector< pair <int,int> > vec;

	cout << "Enter Profits: " << endl;
	for(int i=0;i<n;i++){
		cin >> p[i];
		vec.push_back(make_pair(p[i],i));
	}

	cout << "Enter Deadlines: " << endl;
	for(int i=0;i<n;i++){
		cin >> d[i];
	}

	int max = 0;
	for(int i=0;i<n;i++){
		if(d[i]>max)
			max = d[i];
	}

	//cout << "Max = " << max << endl;
	int arr[max];
	for(int i=0;i<max;i++){
		arr[i] = -1;
	}

	sort(vec.begin(), vec.end(),sortinrev);

	int profit;
	for(int i=0;i<n;i++){
		int k = vec[i].second;
		int delay = d[k];
		//cout << "Delay = " << delay << endl;
		for(int j=delay-1;j>=0;j--){
			if(arr[j] == -1){
				//cout << "JOB = " << k  << "Pos = " << j << endl;
				arr[j] = k;
				profit = profit + p[k];
				break;
			}
		}
	}

	cout << "Max Profit = " << profit << endl;

	return 0;
}
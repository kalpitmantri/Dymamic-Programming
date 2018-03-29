#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool sortinrev(const pair<double,double> &a,const pair<double,double> &b){
       return (a.first > b.first);
}

int main(){
	int n;
	cout << "Enter Number of objects: ";
	cin >> n;
	double p[n],w[n];

	double c; //capacity
	double profit; //profit
	cout << "Enter Capacity: ";
	cin >> c;

	cout << "Enter Profits: " << endl;
	for(int i=0;i<n;i++){
		cin >> p[i];
	}

	cout << "Enter Weights: " << endl;
	for(int i=0;i<n;i++){
		cin >> w[i];
	}

	vector< pair <double,double> > pw;
	
	for(int i=0;i<n;i++){
		double k = p[i]/w[i];
		pw.push_back( make_pair(k,i) );
	}

	sort(pw.begin(), pw.end(),sortinrev);

	int i,j;
	for(i=0;i<n;i++){
		j = pw[i].second;
		if(c>0 && w[j]<=c){
			c = c-w[j];
			profit = profit + p[j];
		}
		else{
			break;
		}
	}

	if(w>0){
		profit = profit + p[j]*(c/w[j]);
	}

	cout << "Maximum Profit is: " << profit << endl;
}
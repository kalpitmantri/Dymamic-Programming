//To-Do
//1. Print The Values That have been used to get Maximum Output!!

#include <iostream>
using namespace std;

int max(int,int);

int main(){

	int c;
	cout << "Enter Capacity: ";
	cin >> c;

	int n;
	cout << "Enter n : ";
	cin >> n;

	int p[n+1],w[n+1];
	p[0] = 0; w[0] = 0;
	cout << "Enter profits : ";
	for(int i=1;i<=n;i++)
		cin >> p[i];

	cout << "Enter Weights : ";
	for(int i=1;i<=n;i++)
		cin >> w[i];

	int table[n+1][c+1];

	for(int i=0;i<n+1;i++){
		for(int j=0;j<c+1;j++)
			table[i][j] = 0;
	}


	for(int i=1;i<=n;i++){
		table[i][0] = 0;
		for(int j=1;j<=c;j++){
			if(w[i] <= j){
				table[i][j] = max((p[i]+table[i-1][j-w[i]]),table[i-1][j]);
			}else{
				table[i][j] = table[i-1][j];
			}
		}
	}

	// cout << endl;
	// for(int i=0;i<=n;i++){
	// 	for(int j=0;j<=c;j++){
	// 		cout << table[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	cout << "Maximum Value : " << table[n][c] << endl;

	return 0;
}

int max(int a,int b){
	if(a>b)
		return a;
	else
		return b;
}
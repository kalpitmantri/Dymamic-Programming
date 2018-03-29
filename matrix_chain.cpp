//To-Do
//1. Print the Order Of Multiplication with Brackets!!

#include <iostream>
using namespace std;

int main(){

	int n;
	cin >> n;
	int p[n+1],a=0;
	
	for(int i=0;i<2*n;i++){
		int temp;
		cin >> temp;
		if((i%2 != 0) || (i==0)){
			p[a] = temp;
			a++;
		}
	}

	int length;
	int m[n][n],res[n][n];

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i == j){
				m[i][j] = 0;
				res[i][j] = 0;
			}
			else{
				m[i][j] = -1;
				res[i][j] = -1;
			}
		}
	}

	int x,j;
	for(length = 2;length<=n;length++){
		for(int i=0;i<=n-length;i++){
			j = i + length -1;
			m[i][j] = 999;
			for(int k=i;k<j;k++){
				x = m[i][k] + m[k+1][j] + (p[i]*p[k+1]*p[j+1]);
				if(x < m[i][j]){
					m[i][j] = x;
					res[i][j] = k+1;
				}
			}
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl ;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << res[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
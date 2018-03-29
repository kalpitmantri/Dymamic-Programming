#include <iostream>
using namespace std;

int main(){

	int n;
	cout << "Enter the number of elements: ";
	cin >> n;

	int arr[n+1];
	arr[0] = 0;
	cout << "Enter elemnents: " << endl;
	for(int i=1;i<=n;i++)
		cin >> arr[i];

	int w;
	cout << "Enter Sum" << endl;
	cin >> w;

	int res[n+1][w+1];

	for(int i=0;i<n+1;i++){
		for(int j=0;j<w+1;j++)
			res[i][j] = -1;
	}

	for (int i=0;i<n+1;i++){
		res[i][0] = 1;
	}	

	res[0][0] = 1;
	for(int i=1;i<w+1;i++){
		res[0][i] = 0;
	}

	for(int i=1;i<n+1;i++){
		for(int j=1;j<w+1;j++){
			if(arr[i] > j){
				res[i][j] = res[i-1][j];
			}
			else{
				res[i][j] = res[i-1][j-arr[i]] || res[i-1][j];
			}
		}
	}

	for(int i=0;i<n+1;i++){
		for(int j=0;j<w+1;j++)
			cout << res[i][j] << " ";

		cout << endl;
	}

	if(res[n][w] == 1)
		cout << "Possible!!" << endl;
	else
		cout << "Not Possible!!!" << endl;

	return 0;
}
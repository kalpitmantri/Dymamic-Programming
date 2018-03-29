#include <iostream>
using namespace std;

int max(int ,int);

int main(){
	cout << "Enter size :" <<endl;
	int n;
	cin >> n;

	int arr[n];
	cout << "Enter the Sequence:" << endl;
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}

	int result[n];
	int index[n];
	for(int i=0;i<n;i++){
		result[i] = 1;
		index[i] = -1;
	}

	for(int i=1;i<n;i++){
		int j=0;
		while(j<i){
			if(arr[j]<arr[i]){
				result[i] = max(result[j]+1,result[i]);
				if (result[i] == result[j]+1){
					index[i] = j;
				}
			}
			j++;
		}
	}

	// for(int i=0;i<n;i++)
	// 	cout << result[i] << " ";
	// cout << endl;

	// for(int i=0;i<n;i++)
	// 	cout << index[i] << " ";
	// cout << endl;

	int max = 0,max_index=-1;
	for(int i=0;i<n;i++){
		if(arr[i]>max){
			max = result[i];
			max_index = i;
		}
	}
	//cout << max << " " << max_index << endl;

	int seq[max];
	int k = max-1;
	seq[k] = max_index; 
	k--;
	for(int i=max_index;i>=0;){
		i = index[i];
		seq[k] = i;
		k--;
	}

	cout << "Length of Longest Increasing Sub-Sequence = " << max << endl << "Sequence : ";
	for(int i=0;i<max;i++){
		cout << arr[seq[i]] << " ";
	}
	cout << endl;
	return 0;
}

int max(int a,int b){
	if(a>=b){
		return a;
	}
	else
		return b;
}
#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int max(int,int);

int main(){

	string str1,str2,result="";
	
	cout << "Enter String1: " << endl;
	cin >> str1;
	cout << "Enter String2: " << endl;
	cin >> str2; 

	int l1,l2;
	l1 = str1.length();
	l2 = str2.length();

	int arr[l1+1][l2+1];
	for(int i=0;i<l1+1;i++){
		for(int j=0;j<l2+1;j++)
			arr[i][j] = 0;
	}

	for(int i=0;i<l1;i++){
		for(int j=0;j<l2;j++){
			if(str1[i] == str2[j]){
				arr[i+1][j+1] = arr[i][j]+1;
			}
			else{
				arr[i+1][j+1] = max(arr[i+1][j],arr[i][j+1]);
			}
		}
	 }

	int p=l1,q=l2;
	while(p!=0 && q!=0){
		if(str1[p-1] == str2[q-1]){
			result += str1[p-1];
			p = p-1;
			q = q-1;
		}
		else if((p!=0 && q!=0) && (arr[p-1][q]>arr[p][q-1])){
			p = p-1;
		}
		else if((p!=0 && q!=0) && (arr[p][q-1]>arr[p-1][q])){
			q = q-1;
		}
	}

	for(int i=0;i<l1+1;i++){
		for(int j=0;j<l2+1;j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}

	reverse(result.begin(),result.end());
	int length = arr[l1][l2];
	cout << length << endl << result << endl;

	return 0;

}

int max(int a,int b){
	if(a>=b){
		return a;
	}
	else
		return b;
}
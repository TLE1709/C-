#include<bits/stdc++.h>
using namespace std;

void merge(int l,int mid,int h,vector<int>&arr){
	
	int left=l;
	int right=mid+1;
	vector<int>temp;
	
	while(left<=mid && right<=h){
		
		if(arr[left]<arr[right]){
			temp.push_back(arr[left]);
			left++;
		}
		
		else{
			temp.push_back(arr[right]);
			right++;
		}
	}
	
	while(left<=mid){
		temp.push_back(arr[left]);
		left++;
	}
	
	while(right<=h){
		temp.push_back(arr[right]);
		right++;
	}
	
	for(int i=l;i<=h;i++){
		arr[i]=temp[i-l];
	}
}

void mergeSort(int l,int h,vector<int>&arr){
	
	if(l==h){
		return;
	}
	
	int mid=(l+h)/2;
	mergeSort(l,mid,arr);
	mergeSort(mid+1,h,arr);
	merge(l,mid,h,arr);
}


int main(){
	int n;
	cin>>n;
	vector<int>arr(n);
	
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}	
	
	cout<<"Before Sorting :- "<<endl;
	for(auto it:arr){
		cout<<it<<" ";
	}
	cout<<endl;
	int low=0,high=n-1;
	mergeSort(low,high,arr);
	cout<<"After Sorting :- "<<endl;
	for(auto it:arr){
		cout<<it<<" ";
	}
	cout<<endl;
	return 0;
}

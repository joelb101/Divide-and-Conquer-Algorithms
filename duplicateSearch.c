/*
Binary Search with Duplicates Problem
Find the index of the first occurrence of a key in
a sorted array.
--------------------------------------------------------------------------------------------------------------------
Input: A sorted array of integers (possibly with duplicates) and
an integer q.
--------------------------------------------------------------------------------------------------------------------
Output: Index of the first occurrence of q in the array or “−1”
if q does not appear in the array.
--------------------------------------------------------------------------------------------------------------------
Input format. The first two lines of the input contain an integer n and
a sequence k0 ≤ k1 ≤ · · · ≤ kn−1 of n positive integers in non-decreasing
order. The next two lines contain an integer m and m positive integers
q0, q1, . . . , qm−1.
--------------------------------------------------------------------------------------------------------------------
Output format. For all i from 0 to m − 1, output the index 0 ≤ j ≤ n − 1 of
the first occurrence of qi (i.e., kj = qi ) or −1, if there is no such index.
--------------------------------------------------------------------------------------------------------------------
Constraints. 1 ≤ n ≤ 3 · 104; 1 ≤ m ≤ 105; 1 ≤ ki ≤ 109 for all 0 ≤ i < n;
1 ≤ qj ≤ 109 for all 0 ≤ j < m.
-------------------------------------------------------------------------------------------------------------------
*/


#include<stdio.h>

int binarySearch(long arr[],int low,int high,long key){

	if(low>high)
		return -1;
		
	int mid=(low+high)/2;

	
	if(arr[mid]==key){
		int pos=binarySearch(arr,low,mid-1,key);
		if(pos!=-1)
			return pos;
		return mid;
	}
	if(arr[mid]>key)
		return binarySearch(arr,low,mid-1,key);
	if(arr[mid]<key)
		return binarySearch(arr,mid+1,high,key);
		
}

int main(void){
	int n,m;
	
	scanf("%d",&n);
	long arr[n];
	for(int i=0;i<n;i++)
		scanf("%ld",&arr[i]);
	
	scanf("%d",&m);
	long arr1[m];
	for(int i=0;i<m;i++)
		scanf("%ld",&arr1[i]);
	
	for(int i=0;i<m;i++){
		printf("%d ",binarySearch(arr,0,n-1,arr1[i]));
	}
	printf("\n");
	
	return 0;
}

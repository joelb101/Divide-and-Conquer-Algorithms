/*

Sorted Array Multiple Search Problem
Search multiple keys in a sorted sequence of keys.
--------------------------------------------------------------------------------------------------------------------
Input: A sorted array K of distinct integers and an array Q =[q0, . . . , qm−1] of integers.
--------------------------------------------------------------------------------------------------------------------
Output: For each qi , check whether it occurs in K.
--------------------------------------------------------------------------------------------------------------------
Input format. The first two lines of the input contain an integer n and a sequence k0 < k1 < . . . < kn−1 of n distinct positive integers in increasing
order. The next two lines contain an integer m and m positive integers q0, q1, . . . , qm−1.
--------------------------------------------------------------------------------------------------------------------
Output format. For all i from 0 to m − 1, output an index 0 ≤ j ≤ n − 1 such
that kj = qi , or −1, if there is no such index.
--------------------------------------------------------------------------------------------------------------------
Constraints. 1 ≤ n ≤ 3 · 104; 1 ≤ m ≤ 105; 1 ≤ ki ≤ 109 for all 0 ≤ i < n;
1 ≤ qj ≤ 109 for all 0 ≤ j < m.
*/


#include<stdio.h>

int binarySearch(long arr[],int low,int high,long key){

	if(low>high)
		return -1;
		
	int mid=(low+high)/2;

	
	if(arr[mid]==key)
		return mid;
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

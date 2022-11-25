/*
Speeding-up RandomizedQuickSort Problem
--------------------------------------------------------------------------------------------------------------------
Sort a given sequence of numbers (that may contain duplicates) using a 
modification of RandomizedQuickSort that works in O(n log n) expected time.
--------------------------------------------------------------------------------------------------------------------
Input: An integer array with n elements that may contain duplicates.
--------------------------------------------------------------------------------------------------------------------
Output: Sorted array (generated using a modification
of RandomizedQuickSort) that
works in O(n log n) expected time.
--------------------------------------------------------------------------------------------------------------------
Input format. The first line of the input contains an integer n. The next
line contains a sequence of n integers a0, a1, . . . , an−1.
--------------------------------------------------------------------------------------------------------------------
Output format. Output this sequence sorted in non-decreasing order.
--------------------------------------------------------------------------------------------------------------------
Constraints. 1 ≤ n ≤ 105; 1 ≤ ai ≤ 109 for all 0 ≤ i < n.
--------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>

void swap(long *p,long *q){
	long t=*p;
	*p=*q;
	*q=t;
}

long *randomisedPartition(long a[],long l,long r){
	static long partition[2]={0};
	long pivot=(rand() %(r-l+1))+l;
	swap(&a[pivot],&a[l]);
	pivot=l;
	long i=l;
	long m=l;
	int flag=0;
	for(long j=l+1;j<=r;j++){
		if(a[j] < a[pivot]){
			i++;
			swap(&a[i],&a[j]);
			if(a[j]==pivot)
				j--;
		}
		if(a[j]==a[pivot]){
			if(!flag){
				m=i;
				flag=1;
			}
			m++;
			swap(&a[j],&a[m]);
		}
	}
	swap(&a[i],&a[pivot]);
	partition[0]=i;
	partition[1]=m;
	return partition;
}

void randomisedQuickSort(long a[],long l,long r){
	if(l>=r)
		return;
	long *partition=randomisedPartition(a,l,r);
	//printf("%ld   %ld\n",partition[0]-1,partition[1]+1);
	randomisedQuickSort(a,l,partition[0]-1);
	randomisedQuickSort(a,partition[1]+1,r);
}

int main(void){
	long n;
	scanf("%ld",&n);
	long a[n];
	for(int i=0;i<n;i++)
		scanf("%ld",&a[i]);
		
	randomisedQuickSort(a,0,n-1);

	for(int i=0;i<n;i++)
		printf("%ld ",a[i]);
	printf("\n");
	
	return 0;
}

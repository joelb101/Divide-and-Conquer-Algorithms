/*
Majority Element Problem
Check whether a given sequence of numbers contains an element that appears more than half of
the times.
--------------------------------------------------------------------------------------------------------------------
Input: A sequence of n integers.
--------------------------------------------------------------------------------------------------------------------
Output: 1, if there is an element
that is repeated more than n/2
times, and 0 otherwise.
--------------------------------------------------------------------------------------------------------------------
Input format. The first line contains an integer n, the next one contains
a sequence of n non-negative integers. a0, . . . , an−1.
--------------------------------------------------------------------------------------------------------------------
Output format. Output 1 if the sequence contains an element that appears
more than n/2 times, and 0 otherwise.
--------------------------------------------------------------------------------------------------------------------
Constraints. 1 ≤ n ≤ 10^5; 0 ≤ ai ≤ 10^9 for all 0 ≤ i < n.
*/

#include<stdio.h>

long count(long a[],long l,long h,long key){
	int c=0;
	for(int i=l;i<=h;i++){
		if(a[i]==key)
			c++;
	}
	//if(c>((l+h)/2)+1)
		return c;
	//return 0;
}

long majority(long a[],long l,long h){
	if(l==h)
		return a[l];
	
	long mid=(l+h)/2;
	
	long left=majority(a,l,mid);
	long right=majority(a,mid+1,h);
	
	long leftC,rightC;

	if(left!=-1 && right!=-1){
		leftC=count(a,l,h,left);
		rightC=count(a,l,h,right);
		return leftC>rightC?((leftC>(h - l + 1) / 2)?left:0):((rightC>(h - l + 1) / 2)?right:0);
	}
	else if(left==-1 && right!=-1){
		rightC=count(a,l,h,right);
		return rightC>((h - l + 1) / 2)?right:0;
	}
	else if(left!=-1 && right==-1){
		leftC=count(a,l,h,left);
		return leftC>((h - l + 1) / 2)?left:0;
	}
	else
	{
		return 0;
	}
}
	

int main(void){
	long n,count;
	scanf("%ld",&n);
	long a[n];
	for(int i=0;i<n;i++)
		scanf("%ld",&a[i]);

	printf("%d\n",(majority(a,0,n-1))>0?1:0);
	
	return 0;
}

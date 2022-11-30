/*
Closest Points Problem
--------------------------------------------------------------------------------------------------------------------
Find the closest pair of points in a set of points on
a plane.
--------------------------------------------------------------------------------------------------------------------
Input: A list of n points on a plane.
--------------------------------------------------------------------------------------------------------------------
Output: The minimum distance between a pair of these points.
--------------------------------------------------------------------------------------------------------------------
Input format. The first line contains the number of points n. Each of the
following n lines defines a point (xi , yi ).
--------------------------------------------------------------------------------------------------------------------
Output format. The minimum distance.
--------------------------------------------------------------------------------------------------------------------
Constraints. 2 ≤ n ≤ 10^5; −10^9 ≤ xi , yi ≤ 10^9 are integers.
--------------------------------------------------------------------------------------------------------------------
********************************************************************************************************************
--------------------------------------------------------------------------------------------------------------------
The time complexity of the code below is O(n*logn*logn) .
Because during each recursive call a sorting of O(nlogn) is performed. As a result the recurrence relation
becomes T(n)=2*T(n/2)+O(nlogn)+O(n)+O(n).Solvinf this recurrence relation we get the time complexity to 
be O(n*logn*logn).
Here, the two O(n) term comes from copying the arrays and a call to the function closest_points_slice(which is
of O(n) ).
However, the code below can be further optimised to give a better time complexity of O(nlogn) if we avoid sorting
at every level of recursion, by passing a pre-sorted array
--------------------------------------------------------------------------------------------------------------------
There's a good chance that the naive algorithm may run faster than the divide and conquer algorithm for sufficiently 
small input sizes.The input size for which the divide and conquer starts to outperform naive algortihm
can be found out by testing both algorithms with different input sizes.
For simplicity, lets assume the size at which divide and conquer outperforms naive algorithm to be 3.
--------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Points{
	long x;
	long y;
}Points;

double min(double d1,double d2){
	return d1>d2?d2:d1;
}

double dist(Points p1,Points p2){
	double d;
	double d1=(double)( (p1.x-p2.x)*(p1.x-p2.x) );
	double d2=(double)( (p1.y-p2.y)*(p1.y-p2.y) );
	
	d = sqrt((d1+d2));
	
	return d;
}

int compare_x(const void* p,const void* q){
	if( ((Points*)p)->x < ((Points*)q)->x )
		return -1;
	if( ((Points*)p)->x > ((Points*)q)->x )
		return 1;
	if( ((Points*)p)->y < ((Points*)q)->y )
		return -1;
	if( ((Points*)p)->y > ((Points*)q)->y )
		return 1;
	return 0;
}

int compare_y(const void* p,const void* q){
	if( ((Points*)p)->y < ((Points*)q)->y )
		return -1;
	if( ((Points*)p)->y > ((Points*)q)->y )
		return 1;
	if( ((Points*)p)->x < ((Points*)q)->x )
		return -1;
	if( ((Points*)p)->x > ((Points*)q)->x )
		return 1;
	return 0;
}

double closestPoints_naive(Points p[],unsigned int low,unsigned int high){
	double min_dis=-1.0,temp_dis=0.0;
	
	for(unsigned int i=low;i<=high;i++){
		for(unsigned int j=i+1;j<=high;j++){
			temp_dis=dist(p[i],p[j]);
			if(min_dis>temp_dis || min_dis == -1.0)
				min_dis=temp_dis;
		}
	}
	
	return min_dis;
}

double closest_points_slice(Points y_sort_slice[],unsigned int size_slice,double min_dist){
	double min_slice_dist=min_dist,temp_dist=0.0;
	
	for(unsigned int i=0;i<size_slice;i++){
		for(int j=i+1;j<=i+7 && j<size_slice;j++){
			temp_dist=dist(y_sort_slice[i],y_sort_slice[j]);
			if(min_slice_dist > temp_dist)
				min_slice_dist=temp_dist;
		}
	}
	
	return min_slice_dist;
}

double _closest_points(Points x_sort_pts[],unsigned int low,unsigned int high){
	
	if( (high-low+1)<=3)
		return closestPoints_naive(x_sort_pts,low,high);
	
	unsigned int mid = (low+high)/2;
	
	double min_dist_left = _closest_points(x_sort_pts,low,mid);
	double min_dist_right = _closest_points(x_sort_pts,mid+1,high);
	
	double min_dist = min(min_dist_left,min_dist_right);
	
	Points y_sort_points[high-low+1];
	
	unsigned int size_slice=0;
	for(unsigned int i=low;i<=high;i++){
		if( ((x_sort_pts[mid].x)-min_dist)<=x_sort_pts[i].x && ((x_sort_pts[mid].x)+min_dist)>=x_sort_pts[i].x ){
			y_sort_points[size_slice++]=x_sort_pts[i];
		}
	}
	
	qsort(y_sort_points,size_slice,sizeof(Points),compare_y);
	double min_dist_slice = closest_points_slice(y_sort_points,size_slice,min_dist);
	
	return min(min_dist,min_dist_slice);
}

double closestPoints(Points pts[],unsigned int n){
	Points x_sort_pts[n];
	for(int i=0;i<n;i++)
		x_sort_pts[i]=pts[i];
	qsort(x_sort_pts,n,sizeof(Points),compare_x);
	return _closest_points(x_sort_pts,0,n-1);
}

int main(void){
	unsigned int n;
	
	scanf("%u",&n);
	Points pts[n];
	
	for(unsigned int i=0;i<n;i++){
		scanf("%ld",&pts[i].x);
		scanf("%ld",&pts[i].y);
	}
	
	printf("%.4lf\n",closestPoints(pts,n));

	return 0;
}

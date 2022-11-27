/*
Points and Segments Problem
--------------------------------------------------------------------------------------------------------------------
Given a set of points and a set of segments on
a line, compute, for each point, the number of
segments it is contained in.
--------------------------------------------------------------------------------------------------------------------
Input: A list of n segments and
a list of m points.
--------------------------------------------------------------------------------------------------------------------
Output: The number of segments
containing each point.
--------------------------------------------------------------------------------------------------------------------
Input format. The first line contains two non-negative integers n and m
defining the number of segments and the number of points on a line,
respectively. The next n lines contain two integers li , ri defining the
i-th segment [li , ri ]. The next line contains m integers defining points
p1, . . . , pm.
--------------------------------------------------------------------------------------------------------------------
Output format. m non-negative integers k1, . . . , kp where ki is the number
of segments that contain pi .
--------------------------------------------------------------------------------------------------------------------
Constraints. 1 ≤ n, m ≤ 50 000; −108 ≤ li ≤ ri ≤ 108 for all 1 ≤ i ≤ n;
−108 ≤ pj ≤ 108 for all 1 ≤ j ≤ m.
--------------------------------------------------------------------------------------------------------------------
*/


#include<stdio.h>
#include<stdlib.h>


struct segments{
	long left;
	long right;
};

struct points{
	long point;
	unsigned int count;
	unsigned int position;
};
/*
Left = -1
Point = 0
Right = 1
*/
struct points_segments{
	long value;
	int flag;
};

int compare_points_segments(const void*p,const void* q){
	if( ((struct points_segments*)p)->value < ((struct points_segments*)q)->value )
		return -1;
	if( ((struct points_segments*)p)->value > ((struct points_segments*)q)->value )
		return 1;
	
	/*To deal with corner cases like : [0,3],[1,3],[3,8],{-1,3,7}
	  These should be sorted in the format: left(opening point of the segment),point,
	  right(closing point of the segment).The code below does that.
	  If this corner case is ignored the output for the input above will be will be 
	  0 1 1 or 0 2 1 
	  Depends on what comes first.(The point or the opening point of the segment or 
	  the closing point of the segment).
	  Correct Output:
	  0 3 1
	*/
	if( ((struct points_segments*)p)->value == ((struct points_segments*)q)->value ){
		if(((struct points_segments*)p)->flag < ((struct points_segments*)q)->flag )
			return -1;
		if(((struct points_segments*)p)->flag > ((struct points_segments*)q)->flag )
			return 1;
		return 0;
	}
	return 0;
}

int compare_points(const void* p,const void* q){
	if( ((struct points*)p)->point < ((struct points*)q)->point )
		return -1;
	if( ((struct points*)p)->point > ((struct points*)q)->point )
		return 1;
	return 0;
}

int compare_points_position(const void* p,const void* q){
	if( ((struct points*)p)->position < ((struct points*)q)->position )
		return -1;
	if( ((struct points*)p)->position > ((struct points*)q)->position )
		return 1;
	return 0;
}

void count_of_segments(struct points_segments ps[],struct points pts[],unsigned int m,unsigned int size){
	qsort(ps,size,sizeof(struct points_segments),compare_points_segments);
	qsort(pts,m,sizeof(struct points),compare_points);
	
	unsigned int count=0,j=0;
	for(unsigned int i=0;i<size;i++){
		if(ps[i].flag==-1)
			count++;
		else if(ps[i].flag==0){
			pts[j].count=count;
			j++;
		}
		else
			count--;
	}
}

int main(void){
	unsigned int n,m,pos=0;
	scanf("%u",&n);
	scanf("%u",&m);
	
	struct segments smts[n];
	struct points pts[m];
	struct points_segments ps[2*n+m];
	
	for(unsigned int i=0;i<n;i++){
		scanf("%ld",&(smts[i].left));
		scanf("%ld",&(smts[i].right));
	}
	
	for(unsigned int i=0;i<m;i++){
		scanf("%ld",&(pts[i].point));
	}
	
	for(unsigned int i=0,j=0;j<n;j++){
		ps[i].value=(smts[j].left);
		ps[i].flag=-1;
		i++;
		ps[i].value=smts[j].right;
		ps[i].flag=1;
		i++;
	}
	
	for(unsigned int i=2*n,j=0;j<m;i++,j++){
		pts[j].count=0;
		pts[j].position=pos++;
		
		ps[i].value=pts[j].point;
		ps[i].flag=0;
	}

	count_of_segments(ps,pts,m,2*n+m);
	qsort(pts,m,sizeof(struct points),compare_points_position);
	
	for(unsigned int i=0;i<m;i++)
		printf("%u ",pts[i].count);
	
	return 0;
}
		















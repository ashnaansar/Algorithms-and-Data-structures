   /*Implementation of a simple greedy method to optimally solve the two-stage production (flow) scheduling problem/

#include<stdio.h>
#include<stdlib.h>
struct str
{
    int value;
    int index;
};

int cmp(const void *a, const void *b)
{
    struct str *a1 = (struct str *)a;
    struct str *a2 = (struct str *)b;
    if ((*a1).value > (*a2).value)
        return 1;
    else if ((*a1).value < (*a2).value)
        return -1;
    else
        return 0;
}
int main()
{   
	int i,n;
	printf("no of elements:\n");
	scanf("%d",&n);
	int w[n],d[n],a[n],j[n];
	int sw[n],ew[n],ds[n],de[n];
	struct str sa[n];                  //(using struct) https://stackoverflow.com/questions/36714030/c-sort-float-array-while-keeping-track-of-indices/36714204//
        printf("Enter values:\n" );
	for(i=0; i<n; i++)
	{
		scanf("%d%d",&w[i],&d[i]);

	}
	for(i=0; i<n; i++)                   //Finding the minimum of the two time//
	{ 
		if(w[i]<d[i])
{
        a[i]=w[i];
}
else
{
        a[i]=d[i];
}
	 
	}  
	for (i = 0; i < n; i++)
	{
	sa[i].value=a[i];
	  sa[i].index=i;
	}
	 qsort(sa, n, sizeof(sa[n]), cmp);
     int k=0;
     int l=n-1;
     for (i = 0; i < n; i++)  //sorting the array to get the job sequence//
     {
          	if (sa[i].value==w[sa[i].index])
     	{
     		j[k]=sa[i].index;
     		k++;
       	}
     	else 
     	{
     		j[l]=sa[i].index;
     		l--;
     	}
     	

     }                    //job sequences is found//
    
    sw[0]=0;
    ew[0]=w[j[0]];
    ds[0]=ew[0];
    de[0]=ds[0]+d[j[0]];
    for(i=1;i<n;i++)
{
	
	
  sw[i]=ew[i-1];
  ew[i]=sw[i]+w[j[i]];

}
for(i=1;i<n;i++)
{
  if(de[i-1]>=ew[i])
  {
  	ds[i]=de[i-1];
  }
  else if	(ew[i]>de[i-1])
  {
    ds[i]=(ew[i]);
  }
  de[i]=ds[i]+d[j[i]];
}
for (i=0;i<n;i++)
{   
	if(ew[i]>de[i-1])
	{
	  printf("dryer gap from %d to %d\n",de[i-1],ew[i]);           
/*the time when the dryer is idle*/
	}
	printf("%d\t%d\t%d\t%d\t%d\n",j[i],w[j[i]],d[j[i]],sw[i],ds[i]);
	
}
   	int make=(ds[n-1]+d[j[n-1]]);
 	printf("makespan=%d\n",make);
 	return 0;
}


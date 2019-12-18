 /*Implementation of order-preserving Huffman coding - using the dynamic programming formulation*/
 
#include <stdio.h>
double p[20];
int n;
double c[20][20];
int trace[20][20];
double t[100];
void tree(int left,int right,int indent)
{
int i;
if (left==right)
{
 for (i=0;i<indent;i++)
 printf("   ");
 printf("%d\n",left);
 return;
}
tree(trace[left][right]+1,right,indent+1);
for (i=0;i<indent;i++)
 printf("   ");
printf("%d %d  cost=%lf\n",left,right,c[left][right]);
tree(left,trace[left][right],indent+1);
}
int main()
{
int i,j,k,m,l;
double work;
scanf("%d",&n);
for (i=0;i<n;i++)
 {
 	scanf("%lf",&p[i]);
 }
double b=0;
 for ( m = 0; m<n; m++)
 {
 	b=b+p[m];
 	
 }
 printf("probabilities sum to %lf \n",b );
for (i=0;i<n;i++)
 c[i][i]=trace[i][i]=0;
for (i=1;i<n;i++)
{
 for (j=0;j<n-i;j++)
 {
 //printf("Compute c[%d][%d]\n",j,j+i);
 c[j][j+i]=999999;
 for (k=j;k<j+i;k++)
 {
 work=c[j][k]+c[k+1][j+i];
 //printf(" k=%d gives cost %lf=c[%d][%d]+c[%d][%d]",k,work,j,k,k+1,j+i);
 if (c[j][j+i]>work)
 {
 c[j][j+i]=work;
 trace[j][j+i]=k;
 }
 }
 double g=0;
 for ( l = j; l <= j+i; l++)
 {
 	g=g+p[l];
 	
 }
 c[j][j+i]=c[j][j+i]+g;
 //printf(" c[%d][%d]==%lf,trace[%d][%d]==%d\n",j,j+i,c[j][j+i],j,j+i,trace[j][j+i]);
 }
}
printf("Code tree for exact:\n");
tree(0,n-1,0);
printf("Codes & prob*# of bits\n");
for ( i = 0; i < n; i++)
{
	printf("%d ",i );
	int left=0;
	int right=n-1;
	int length=0;
	while(left<right)
	{
		if(i<=trace[left][right])
		{
			printf("0");
			right=trace[left][right];

		}
		else
		{
			printf("1");
			left=trace[left][right]+1;
		}
		length++;

	}
	
    t[i]=p[i]*length;
	printf(" %lf\n",t[i]);
}
double q=0;
for ( i = 0; i < n; i++)
{
	q=q+t[i];

}
printf("Expected bits per symbol %lf\n",q);
}

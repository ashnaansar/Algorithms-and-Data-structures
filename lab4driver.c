/ Reads a string for a serialized RB tree, deserializes it,
// performs some insertions, then serializes the revised tree.
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "RB.h"

int main()
{
int inputBytes;
char *inputString,*outputString;
char formatString[1000];
int insertKeys,i,key;

scanf("%d",&inputBytes);
inputString=(char*) malloc(inputBytes);
if (!inputString)
 { 
  printf("malloc failed %d\n",__LINE__);
  exit(0);
  }
sprintf(formatString,"%%%ds",inputBytes);
scanf(formatString,inputString);

 
STinit();
STdeserialize(inputString);
free(inputString);
//printTree();
scanf("%d",&insertKeys);
for (i=0;i<insertKeys;i++)
 {
  scanf("%d",&key);
  STinsert(key);
  }
outputString=STserialize();
//printf("  length = %lu \n",strlen(outputString)+1);
free(outputString);
}

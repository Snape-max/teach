#include <stdio.h>
#include "function.h"
void main(){
	int a,b;
	printf("please input a: ");
	scanf("%d",&a);
	printf("please input b: ");
	scanf("%d",&b);
	printf("the max number is %d",max(a,b));
}

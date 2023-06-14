#include<stdio.h>

int main()
{
    int n1,n2;
    printf("Enter Two Number");
    scanf("%d%d",&n1,&n2);
    if(n1>n2){
        printf("%d is greater than %d",n1,n2);
    }else if(n1==n2){
    	    printf("%d is Equal to %d",n2,n1);
    }
    else{
    	printf("%d is greater than %d",n2,n1);
	}
    
}
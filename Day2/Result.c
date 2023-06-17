#include <stdio.h>
#include <string.h>
void mark(int Total, float Percentage, int TotalMark, char* StudentName,char* Surname){
	Percentage=Total*100/TotalMark;
	printf("The percentage of %c %c is %f",StudentName,Surname,Percentage);
}
int main(){
	int P,M,C,Total,TotalMark;
	float Percentage;
	char StudentName[50], Surname[50];
	printf("Enter Student Name ");
	scanf("%s %s",&StudentName,&Surname);
	printf("Enter Physics Mark ");
	scanf("%d",&P);
	printf("Enter Math Mark ");
	scanf("%d",&M);
	printf("Enter Chemistry Mark ");
	scanf("%d",&C);
	printf("Enter Total Mark ");
	scanf("%d",&TotalMark);
	Total=P+M+C;
	printf("The total mark obtain is %d\n",Total);
	mark(Total,Percentage,TotalMark,StudentName,Surname);
	return 1;
}
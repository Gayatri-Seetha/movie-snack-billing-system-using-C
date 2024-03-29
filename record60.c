//60 customer records 
#include<stdio.h>
struct student{
	char name[50];
	float price;
};
main(){
	struct student s;
	FILE *f1;
	printf("Enter customer data:");
	f1=fopen("C:/Users/seeth/OneDrive/Documents/c/PROJECT/RECORD60.txt","w");
	while(fscanf(stdin,"%s%f",s.name,&s.price)!=EOF)
		fprintf(f1,"%s	%f",s.name,s.price);
	fclose(f1);
	f1=fopen("C:/Users/seeth/OneDrive/Documents/c/PROJECT/record60.txt","r");
	printf("\nName		Bill");
	while(fscanf(f1,"%s%f",s.name,&s.price)!=EOF){
		printf("\n---------------------------------------");
		fprintf(stdout,"\n%s	%f",s.name,s.price);	
	}
	fclose(f1);
}

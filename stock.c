#include<stdio.h>
FILE *f1;
struct stock{
	int p_stock,b_stock,f_stock,c_stock;
}g;
main(){
	printf("\nEnter the stock of popcorn,bevrage,fries and coffee: ");
	f1=fopen("C:/Users/seeth/OneDrive/Documents/c/PROJECT/stock.txt","w");
	fscanf(stdin,"%d%d%d%d",&g.p_stock,&g.b_stock,&g.f_stock,&g.c_stock);
	fprintf(f1,"%d\n%d\n%d\n%d",g.p_stock,g.b_stock,g.f_stock,g.c_stock);
	fclose(f1);
}

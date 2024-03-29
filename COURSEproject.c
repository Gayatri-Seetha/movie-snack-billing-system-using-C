#include<stdio.h>
#include<string.h>
FILE *f1,*f2;
struct stock update();
struct stock updated_stock();
struct stock left_stock();
struct stock{
	int p_stock,b_stock,c_stock,f_stock;
}g,c6,c7,c8;
struct customer display();
struct customer {
	char name[100];
}f;
struct bill popcorn();
struct bill beverage();
struct bill fries();
struct bill coffee();
struct bill price();
struct bill bill_display();
void display_menu();
struct bill{
	char name[50];
	int qty1;
	int qty2;
	int qty3;
	int qty4;
	int P_price;
	int B_price;
	int F_price;
	int C_price;
	float net_price;
}s,c1,c2,c3,c4,c5;
main(){
	int choice;char ch;
	display_menu();
	printf("\n========================================================================================================================\n");
	do{
		printf("\nEnter your choice to order:");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				c1=popcorn(s);
				break;
			case 2:
				c2=beverage(s);
				break;
			case 3:
				c3=fries(s);
				break;
			case 4:
				c4=coffee(s);
				break;
		}
		printf("\nDo you want to continue?[y/n]:");
		scanf(" %c",&ch);	
	}while(ch=='y');
	printf("Enter customer name: ");
	scanf("%s",s.name);
	c5=bill_display(s,c1,c2,c3,c4);
	printf("\n========================================================================================================================\n");
	
	int choice2;char ch2;
	do{
		printf("\n1.New stock\n2.Stock left");
		printf("\nEnter your choice[stock]:");
		scanf("%d",&choice2);
		switch(choice2){
			int np_stock,nb_stock,nf_stock,nc_stock;
			case 1:
				c6=update(g,c1,c2,c3,c4);
				printf("\nCurrent stock after updating:\n");
				updated_stock(c6,c1,c2,c3,c4);
				break;
			case 2:
				left_stock(g,c1,c2,c3,c4,c6);
				break;
		}
		printf("\nDo you want to continue[stock]?");
		scanf(" %c",&ch2);
	}while(ch2=='y');
	
	char file,ch1;int i,n,choice1;
	printf("\nDo you want to diplay records of customers? ");
	scanf(" %c",&file);
	if(file == 'y'){
		printf("\n---------------------------------------------");
		display(f);
	}
}
void display_menu()
{
	printf("						MOVIE SNACK BILLING");
	printf("\n------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n---------------------------------------------");
	printf("\nFood			Size		Price");
	printf("\n---------------------------------------------");
	printf("\n1.popcorn		1-small		50");
	printf("\n			2-medium	80");
	printf("\n			3-large		100");
	printf("\n---------------------------------------------");
	printf("\n2.Cold bevrages 	1-pepsi		60");printf("\n			2-sprite	60");printf("\n			3-water		40");
	printf("\n---------------------------------------------");
	printf("\n3.Fries			1-salted	70");printf("\n			2-masala	90");
	printf("\n---------------------------------------------");
	printf("\n4.Coffee		1-cold coffee	120");printf("\n			2-americano	150");printf("\n			3-cappuccino	160");
	printf("\n---------------------------------------------");
	printf("\nNOTE: 18percent tax on each product u buy.");
}
struct bill popcorn(struct bill s){
	int size1,i,pop1,pop2,pop3;
	printf("Enter no. of items for popcorn: ");
	scanf("%d",&s.qty1);
	pop1=pop2=pop3=0;
	for(i=0;i<s.qty1;i++){
		printf("Enter the size: ");
		scanf("%d",&size1);
	}
	if(size1==1)
		pop1+=(s.qty1*50)+(s.qty1*18);
	else if(size1==2)
		pop2+=(s.qty1*80)+(s.qty1*18);
	else if(size1==3)
		pop3+=(s.qty1*100)+(s.qty1*18);
	s.P_price=pop1+pop2+pop3;
	printf("%d",s.P_price);
	return s;
}
struct bill beverage(struct bill s){
	int size2,i,bev1,bev2,bev3;
	printf("Enter no. of items for bevrages: ");
	scanf("%d",&s.qty2);
	bev1=bev2=bev3=0;
	for(i=0;i<s.qty2;i++){
		printf("Enter the size: ");
		scanf("%d",&size2);
	}
	if(size2==1)
		bev1+=(s.qty2*70)+(s.qty2*18);
	else if(size2==2)
		bev2+=(s.qty2*90)+(s.qty2*18);
	else if(size2==3)
		bev3+=(s.qty2*40)+(s.qty2*18);
	s.B_price=bev1+bev2+bev3;
	printf("%d",s.B_price);
	return s;
}
struct bill fries(struct bill s){
	int size3,i,fry1,fry2;
	printf("Enter no. of items for fries: ");
	scanf("%d",&s.qty3);
	fry1=fry2=0;
	for(i=0;i<s.qty3;i++){
		printf("Enter the size: ");
		scanf("%d",&size3);
	}
	if(size3==1)
		fry1+=(s.qty3*70)+(s.qty3*18);
	else if(size3==2)
		fry2+=(s.qty3*90)+(s.qty3*18);
	s.F_price=fry1+fry2;
	printf("%d",s.F_price);
	return s;
}
struct bill coffee(struct bill s){
	int size4,i,cof1,cof2,cof3;
	printf("Enter no. of items for coffee: ");
	scanf("%d",&s.qty4);
	cof1=cof2=cof3=0;
	for(i=0;i<s.qty4;i++){
		printf("Enter the size: ");
		scanf("%d",&size4);
	}
	if(size4==1)
		cof1+=(s.qty4*50)+(s.qty4*18);
	else if(size4==2)
		cof2+=(s.qty4*90)+(s.qty4*18);	
	else if(size4==3)
		cof3+=(s.qty4*110)+(s.qty4*18);
	s.C_price=cof1+cof2+cof3;
	printf("%d",s.C_price);
	return s;
}
struct bill bill_display(struct bill s,struct bill c1,struct bill c2,struct bill c3, struct bill c4){
	s.net_price=c1.P_price+c2.B_price+c3.F_price+c4.C_price;
	printf("%f",s.net_price);
	printf("\n========================================================================================================================\n");
	printf("\n					Movie snack bill");
	printf("\n			---------------------------------------------");
	printf("\n			Name:	%s",s.name);
	printf("\n			Mobile number: 9121889441");
	printf("\n			---------------------------------------------");
	printf("\n			Food item	Qty	Price");
	printf("\n			---------------------------------------------");
	if(c1.qty1>0)
		printf("\n			Popcorn		%d	%d",c1.qty1,c1.P_price);
	if(c2.qty2>0)
		printf("\n			Cold bevrages	%d	%d",c2.qty2,c2.B_price);
	if(c3.qty3>0)
		printf("\n			Fries		%d	%d",c3.qty3,c3.F_price);
	if(c4.qty4>0)
		printf("\n			Coffee		%d	%d",c4.qty4,c4.C_price);
	printf("\n			---------------------------------------------");
	printf("\n			Total			%f",s.net_price);
	printf("\n			---------------------------------------------");
	printf("\n					Thankyou");
	f1=fopen("C:/Users/seeth/OneDrive/Documents/c/PROJECT/record60.txt","a");
	fprintf(f1,"%s  %f\n",s.name,s.net_price);
	fclose(f1);
	return s;
}
struct customer display(struct bill c5){
	f1=fopen("C:/Users/seeth/OneDrive/Documents/c/PROJECT/record60.txt","r");
	printf("\nName	Bill\n");
	while(fscanf(f1,"%s  %f\n",c5.name,&c5.net_price)!=EOF){
		printf("----------------------------------\n");
		fprintf(stdout,"%s  %f\n",c5.name,c5.net_price);	
	}
	fclose(f1);
}
struct stock update(struct stock g,struct bill c1,struct bill c2,struct bill c3, struct bill c4){
	int np_stock,nb_stock,nf_stock,nc_stock;
	printf("\nEnter the stock of popcorn,bevrage,fries and coffee to be appended: ");
	scanf("%d%d%d%d",&np_stock,&nb_stock,&nf_stock,&nc_stock);
	f2=fopen("C:/Users/seeth/OneDrive/Documents/c/PROJECT/stock.txt","w");
	fscanf(f2,"%d\n%d\n%d\n%d",&g.p_stock,&g.b_stock,&g.f_stock,&g.c_stock);
	g.p_stock+=np_stock;
	g.b_stock+=nb_stock;
	g.f_stock+=nf_stock;
	g.c_stock+=nc_stock;
	fprintf(f2,"%d\n%d\n%d\n%d",g.p_stock,g.b_stock,g.f_stock,g.c_stock);
	fclose(f2);
	printf("The new stock:");
	f2=fopen("C:/Users/seeth/OneDrive/Documents/c/PROJECT/stock.txt","a");
	fscanf(f2,"%d\n%d\n%d\n%d",&g.p_stock,&g.b_stock,&g.f_stock,&g.c_stock);
	fprintf(stdout,"\nPopcorn:%d\nBeverage:%d\nFries:%d\nCoffee:%d",g.p_stock,g.b_stock,g.f_stock,g.c_stock);
	fclose(f2);
	return g;
}
struct stock updated_stock(struct stock g,struct bill c1,struct bill c2,struct bill c3, struct bill c4){
	f2=fopen("C:/Users/seeth/OneDrive/Documents/c/PROJECT/stock.txt","r");
	fscanf(f2,"%d\n%d\n%d\n%d",&c6.p_stock,&c6.b_stock,&c6.f_stock,&c6.c_stock);
	c6.p_stock-=c1.qty1;
	c6.b_stock-=c2.qty2;
	c6.f_stock-=c3.qty3;
	c6.c_stock-=c4.qty4;
	fprintf(stdout,"\nPopcorn:%d\nBeverage:%d\nFries:%d\nCoffee:%d",c6.p_stock,c6.b_stock,c6.f_stock,c6.c_stock);
	fclose(f2);
	
	f2=fopen("C:/Users/seeth/OneDrive/Documents/c/PROJECT/stock.txt","w");
	fprintf(f2,"%d\n%d\n%d\n%d",c6.p_stock,c6.b_stock,c6.f_stock,c6.c_stock);
	fclose(f2);
	return c6;
}
struct stock left_stock(struct stock g,struct bill c1,struct bill c2,struct bill c3, struct bill c4,struct stock c6){
	printf("\nThe left over stock:\n");
	f2=fopen("C:/Users/seeth/OneDrive/Documents/c/PROJECT/stock.txt","r");
	fscanf(f2,"%d\n%d\n%d\n%d",&g.p_stock,&g.b_stock,&g.f_stock,&g.c_stock);
	g.p_stock-=c1.qty1;
	g.b_stock-=c2.qty2;
	g.f_stock-=c3.qty3;
	g.c_stock-=c4.qty4;
	fprintf(stdout,"Popcorn:%d\nBeverages:%d\nFries:%d\nCoffee:%d",g.p_stock,g.b_stock,g.f_stock,g.c_stock);
	fclose(f2);
	f2=fopen("C:/Users/seeth/OneDrive/Documents/c/PROJECT/stock.txt","w");
	fprintf(f2,"%d\n%d\n%d\n%d",g.p_stock,g.b_stock,g.f_stock,g.c_stock);
	fclose(f2);
}

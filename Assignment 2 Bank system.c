#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>


void Create_Acount();
void Transaction();
void Deposit();
void info();
void login();
void logout();


struct user_info{
	char Name[30];
	char Password[15];
	int acc_no;
	float deposite;
	float balance;
	float Total_Balance;
};
struct user_info U;

	FILE *fp,*ft, *fs;

time_t now;



int main(){
	int op;
	while(1){
	system("cls");
		printf("\n\t\t***********************\n\t\t WLECOME INTO OUR BANK\n\t\t***********************\n\n");
		printf("Please select the following opration.\n");
		printf("\n\n1. Login");
		printf("\n2. Create Account\n");
		printf("3. Exit\n");
		scanf("%d",&op);
	switch(op){
		case 1: login();
		break;
		case 2: Create_Acount();
		break;
		case 3: exit(0);
		default : printf("Please choose specific option");
		getch();
		}
	}
	return 0;
}



void login(){
	system("cls");
	
		printf("\n\t\t*******\n\t\t LOGIN\n\t\t*******\n\n");
	int option;
	int c, z = 0;
	char Pas[15];
	char ne[30];
	printf("\n Name : ");
	scanf("%s",ne);
	printf(" Password : ");

	while ((c=getch())!=13){
		if(c == 8){
		if(z>0){
		z--;
		printf("\b \b");
		}}else{	Pas[z++]=c;
		printf("%c",'*');
}}
	fp = fopen("Bank System.Dat","r+");
	
	while( fread(&U,sizeof(U),1,fp) ){
		if( strcmp(U.Password, Pas) == 0 ){
			
			system("cls");
			printf("\n\t\t*********************\n\t\t  LOGIN SUCCESSFUL\n\t\t*********************\n\n");
			printf("\n  WELCOME %s \n",U.Name);


xy:

			printf("\n PLease select a number 1 - 4 for Operation");
			printf("\n\n1. Transaction");
			printf("\n2. Deposite");
			printf("\n3. Acount Information");
			printf("\n4. logout\t");
			scanf("%d",&option);

	switch (option){
		case 1 : Transaction();
					goto xy;
		break;
		case 2 : Deposit();
					goto xy;
		break;
		case 3 : info();
					goto xy;
		break;
		case 4: logout();
				fclose(fp);
				break;
		default : printf("Invalid Entry");

	}}
	}
	
	}




void Create_Acount(){
	time(&now);
	char pa[15];	char n[40];
	char Tem_P[15];
	int c,z=0;
	fp = fopen("Bank System.Dat","a+");
	srand(time(NULL));
	int random = rand();
	system("cls");
	printf("\n\t\t****************\n\t\t CREATE ACCOUNT\n\t\t****************\n\n");
	printf("Enter your name : ");
	scanf("%s",U.Name);
	printf("Enter your Password : ");
	while((c = getch()) != 13){
		if(c == 8){
			if(z>0){
				z--;
				printf("\b \b");
			}
		}
		else{
			pa[z++] = c;
			printf("%c",'*');
		}
	}

	strncpy(Tem_P,pa,15);
	strncpy(U.Password,Tem_P,15);

	//scanf("%s",U.Password);
	printf("\nYour Account Number is %d\n",random);
	U.acc_no = random;
	printf("\nyour minimum Deposit is Rs.1000/- ");
	U.deposite = 1000;
	U.Total_Balance = U.deposite;
	fwrite(&U,sizeof(U),1,fp);
	strncpy(n,U.Name,30);
	ft = fopen (strcat(U.Name,".txt"),"w+");
	fprintf(ft,"\nName : %s\nPassword : %s\nAccount Number : %d\nBank Balance : %.4f\n\n%s",n,U.Password,U.acc_no,U.Total_Balance,ctime(&now));
	fprintf(ft,"===========================================\n");
	printf("\n\t\t*********************************\n\t\tYour acount created Successfully.\n\t\t*********************************");
	fclose(fp);
	fclose(ft);
	getch();

	
}





void Transaction(){
	char nm[40];
	time(&now);
	char pass[15];
	int a,b;
	float bal;
	char Fn[40];
	char N[30];
	strncpy(N,U.Name,30);
	
			system("cls");


			printf("\n\t\t*************\n\t\t TRANSACTION\n\t\t*************\n\n");
			printf("Login Successful.%s\n",U.Name);
			printf("Enter a value for transact : ");
			scanf("%f",&bal);
			U.Total_Balance = U.Total_Balance - bal;
			printf("Your remaining balance is %f",U.Total_Balance);

           fseek(fp,-(int)(sizeof(U)),SEEK_CUR);
           fwrite(&U,sizeof(U),1,fp);
           
        ft = fopen (strcat(N,".txt"),"a+");
		fprintf(ft,"\nTrasaction : %f\nRemaining Balance : %.3f\n\n%s",bal,U.Total_Balance,ctime(&now));
		fprintf(ft,"===========================================\n");
			fclose(fp);
			fclose(ft);
			fflush(stdin);
			getch();
			system("cls");
	}






void Deposit(){
	time(&now);
	char n[40],pas[12];
	char fn[30];
	strncpy(fn,U.Name,30);
	

	system("cls");
				printf("\n\t\t**********\n\t\t DEPOSITE\n\t\t**********\n\n");
			printf("Login Successful.%s\n",U.Name);

			printf("Enter Amount for Deposit : ");
			scanf("%f",&U.deposite);
			U.Total_Balance = U.Total_Balance + U.deposite;
			printf("now your total balance is %.2f",U.Total_Balance);
			fseek(fp,-(int)(sizeof(U)),SEEK_CUR);
			fwrite(&U,sizeof(U),1,fp);
			
	 ft = fopen (strcat(fn,".txt"),"a+");

			fprintf(ft,"\nDeposite : %.2f\nRemaining Balance : %.2f\n\n%s",U.deposite,U.Total_Balance,ctime(&now));
			fprintf(ft,"===========================================\n");
			fclose(fp);
			fclose(ft);
			fflush(stdin);
			getch();
			system("cls");
	}








void info(){
	time(&now);

	char ch,ps[15];
	int o,z= 0,c;
	char TP[15];
  	char pws[15];
  	char nme[30];
	system("cls");
	printf("\n\t\t*********************\n\t\t ACCOUNT INFORMATION\n\t\t*********************\n\n");
	printf("\n1. Change Password\n2. Account Inquiry");
	scanf("%d",&o);
switch(o){
  	case 1:
		strncpy(nme,U.Name,30);
	printf("\nEnter New password : ");
	while((c = getch()) != 13){
		if(c == 8){
			if(z>0){
				z--;
				printf("\b \b");
			}
		}
		else{
			pws[z++] = c;
			printf("%c",'*');
		}
	}
	strncpy(TP,pws,15);
	  //scanf("%s",pws);
	strncpy(U.Password,TP,15);
	ft = fopen(strcat(nme,".txt"),"a+");
  	printf("\n\t\t*******************************\n\t\t PASSWORD CHANGED SUCCESSFULLY\n\t\t*******************************");
	fprintf(ft,"\nPassword changed = %s\n\n%s",pws,ctime(&now));
	fprintf(ft,"===========================================\n");
  	fseek(fp,-(int)(sizeof(U)),SEEK_CUR);
  	fwrite(&U,sizeof(U),1,fp);
	fclose(fp);
	fclose(ft);
	fflush(stdin);
	getch();
	system("cls");
	break;

	
	case 2:
		ft = fopen (strcat(U.Name,".txt"),"r");
		printf("\n\nCurrent Balance is : %.2f\n==========================================\n",U.Total_Balance);
		while(1){
		ch = fgetc(ft);
		if (ch == EOF){
		break;
		}
		else{
		printf("%c",ch);
		}}
		fclose(ft);
		fclose(fp);
			getch();
			system("cls");
			break;

}}




void logout(){
	fflush(stdin);
	system("cls");
	fclose(fp);
	fclose(ft);
	fclose(fs);
	main();
	
}

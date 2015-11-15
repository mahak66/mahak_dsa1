#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"header.h"
int i,j;
int main_exit;
void printmenu();

struct date{
	int month,day,year;
};
struct {

	char name[64];
	int acc_no,age;
	char address[64];
	char citizenship[64];
	double phone;
	char acc_type[32];
	float amt;
	struct date dob;
	struct date deposit;
	struct date withdraw;

}add,upd,check,rem,transaction;

float interest(float t,float amount,int rate){
	return ((rate*t*amount)/100.0);
}
/* dis function prints the menu and welcome screen*/
/*INPUT=enter the number,OUTPUT=it will call d particular function */
void printmenu(void){
	int choice;
	printf("\n\n\t\t\tCUSTOMER ACCOUNT BANKING SERVICE");
	printf("\n\n\n\t\t\t ***** WELCOME TO THE MAIN MENU *****");
	printf("\n\n\t\tPRESS 1 : Create new account");
	printf("\n\t\tPRESS 2 : Remove account");
	printf("\n\t\tPRESS 3 : For transactions");
	printf("\n\t\tPRESS 4 : Update information of existing account");
	printf("\n\t\tPRESS 5 : Check the details of existing account");
	printf("\n\t\tPRESS 6 : View customer's list");
	printf("\n\t\tPRESS 7 : Exit");
	printf("\n\n\n\n\n\t\t Enter your choice:");
	scanf("%d",&choice);
/*it goes to the particular function from dis case*/
	switch(choice){

		case 1:new_acc();
		       break;
		case 2: dlt();
			break;
		case 3:transact();
		       break;
		case 4:update();
		       break;
		case 5:details();
		       break;
		case 6:customer_list();
		       break;
		case 7:exit_program();
		       break;
	}
}
int main() {
	printmenu();
	return 0;
}
/*dis function is use to make new account*/
/*INPUT=fill infrmtion, OUTPUT=creates ac of given info in it*/
void new_acc() {
	int choice;
	FILE *fp;
	fp=fopen("record.dat","a+");
	account_no:
	printf("\t\t\t ***** ADD RECORD  *****");
	printf("\n\n\nEnter today's date(mm/dd/yyyy):");
	scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
	printf("\nEnter the account number:");
	scanf("%d",&check.acc_no);
	while(fscanf(fp,"%d", &add.acc_no) != EOF){
		fscanf(fp, "%s", add.name);  
		fscanf(fp, "%d", &add.dob.month ); 
		fscanf(fp, "%d", &add.dob.day );
		fscanf(fp, "%d", &add.dob.year );
		fscanf(fp, "%d", &add.age );
		fscanf(fp, "%s", add.address );
		fscanf(fp, "%s", add.citizenship );
		fscanf(fp, "%lf", &add.phone );
		fscanf(fp, "%s", add.acc_type);
		fscanf(fp, "%f", &add.amt);
		fscanf(fp, "%d", &add.deposit.month);
		fscanf(fp, "%d", &add.deposit.day);
		fscanf(fp, "%d\n", &add.deposit.year );
		if (check.acc_no==add.acc_no) {
			printf("Account no. already in use!");
			goto account_no;
		}
	}
	add.acc_no=check.acc_no;
	printf("\nEnter the name:");
	scanf("%s",add.name);
	printf("\nEnter the date of birth(mm/dd/yyyy):");
	scanf("%d %d %d",&add.dob.month,&add.dob.day,&add.dob.year);
	printf("\nEnter the age:");
//	printf("dsfsd");
	scanf("%d",&add.age);
//	printf("fg");
	printf("\nEnter the address:");
	scanf("%s",add.address);
	printf("\nEnter the citizenship number:");
	scanf("%s",add.citizenship);
	printf("\nEnter the phone number: ");
	scanf("%lf",&add.phone);
	printf("\nEnter the amount to deposit:$");
	scanf("%f",&add.amt);
	printf("\nType of account:");
	printf("\n\t1 : Saving");
	printf("\n\t2 : Current");
	printf("\n\t3 : Fixed1(for 1 year)");
	printf("\n\t4 : Fixed2(for 2 years)");
	printf("\n\t5 : Fixed3(for 3 years)");
	printf("\n\n\tEnter your choice:");
	scanf("%s",add.acc_type);

	fprintf(fp,"%d\n", add.acc_no);
	fprintf(fp, "%s\n", add.name);  
	fprintf(fp, "%d\n", add.dob.month ); 
	fprintf(fp, "%d\n", add.dob.day );
	fprintf(fp, "%d\n", add.dob.year );
	fprintf(fp, "%d\n", add.age );
	fprintf(fp, "%s\n", add.address );
	fprintf(fp, "%s\n", add.citizenship );
	fprintf(fp, "%lf\n", add.phone );
	fprintf(fp, "%s\n", add.acc_type);
	fprintf(fp, "%f\n", add.amt);
	fprintf(fp, "%d\n", add.deposit.month);
	fprintf(fp, "%d\n", add.deposit.day);
	fprintf(fp, "%d\n", add.deposit.year );
	fclose(fp);
	printf("\nAccount created successfully!");
add_invalid:
	printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
	scanf("%d",&main_exit);
	if (main_exit==1)
		printmenu();
	else if(main_exit==0)
		exit_program();
	else {
		printf("\nInvalid!\a");
		goto add_invalid;
	}
}
/*dis function updates the information*/
/*INPUT=acnt no, OUTPUT=updated address n ph.no*/
void update(void) {
	int choice,test=0;
	FILE *old,*new;
	old=fopen("record.dat","r");
	new=fopen("new.dat","w");
	printf("\nEnter the account no. of the customer whose info you want to change:");
	scanf("%d",&upd.acc_no);
	while(fscanf(old,"%d", &(add.acc_no)) != EOF) {
		fscanf(old, "%s", add.name);  
		fscanf(old, "%d", &(add.dob.month)); 
		fscanf(old, "%d", &(add.dob.day) );
		fscanf(old, "%d", &(add.dob.year) );
		fscanf(old, "%d", &(add.age) );
		fscanf(old, "%s", add.address );
		fscanf(old, "%s", add.citizenship );
		fscanf(old, "%lf", &(add.phone) );
		fscanf(old, "%s", add.acc_type);
		fscanf(old, "%f", &(add.amt));
		fscanf(old, "%d", &(add.deposit.month));
		fscanf(old, "%d", &(add.deposit.day));
		fscanf(old, "%d\n", &(add.deposit.year) );
		if (add.acc_no==upd.acc_no) {
			 test=1;
			 printf("\nWhich information do you want to change?\n");
			 printf("1.Address\n");
			 printf("2.Phone\n\n");
			 printf("Enter your choice(1 for address and 2 for phone):");
			 scanf("%d",&choice);
			 if(choice==1) {
			 	printf("Enter the new address:");
				scanf("%s",upd.address);
				fprintf(new,"%d\n", add.acc_no);
				fprintf(new, "%s\n", add.name);  
				fprintf(new, "%d\n", add.dob.month ); 
				fprintf(new, "%d\n", add.dob.day );
				fprintf(new, "%d\n", add.dob.year );
				fprintf(new, "%d\n", add.age );
				fprintf(new, "%s\n", add.address );
				fprintf(new, "%s\n", add.citizenship );
				fprintf(new, "%lf\n", add.phone );
				fprintf(new, "%s\n", add.acc_type);
				fprintf(new, "%f\n", add.amt);
				fprintf(new, "%d\n", add.deposit.month);
				fprintf(new, "%d\n", add.deposit.day);
				fprintf(new, "%d\n", add.deposit.year );
				printf("Changes saved!");
			}
			else if(choice==2) {
				printf("Enter the new phone number:");
				scanf("%lf",&upd.phone);
				fprintf(new,"%d\n", add.acc_no);
				fprintf(new, "%s\n", add.name);  
				fprintf(new, "%d\n", add.dob.month ); 
				fprintf(new, "%d\n", add.dob.day );
				fprintf(new, "%d\n", add.dob.year );
				fprintf(new, "%d\n", add.age );
				fprintf(new, "%s\n", add.address );
				fprintf(new, "%s\n", add.citizenship );
				fprintf(new, "%lf\n", add.phone );
				fprintf(new, "%s\n", add.acc_type);
				fprintf(new, "%f\n", add.amt);
				fprintf(new, "%d\n", add.deposit.month);
				fprintf(new, "%d\n", add.deposit.day);
				fprintf(new, "%d\n", add.deposit.year );
				printf("\nChanges saved!\n");
			}

		}
		else {
			fprintf(new,"%d\n", add.acc_no);
			fprintf(new, "%s\n", add.name);  
			fprintf(new, "%d\n", add.dob.month ); 
			fprintf(new, "%d\n", add.dob.day );
			fprintf(new, "%d\n", add.dob.year );
			fprintf(new, "%d\n", add.age );
			fprintf(new, "%s\n", add.address );
			fprintf(new, "%s\n", add.citizenship );
			fprintf(new, "%lf\n", add.phone );
			fprintf(new, "%s\n", add.acc_type);
			fprintf(new, "%f\n", add.amt);
			fprintf(new, "%d\n", add.deposit.month);
			fprintf(new, "%d\n", add.deposit.day);
			fprintf(new, "%d\n", add.deposit.year );

		}
	}
	fclose(old);
	fclose(new);
	remove("record.dat");
	rename("new.dat","record.dat");

	if(test!=1) {  
		printf("\nRecord not found!!\a\a\a");
edit_invalid:
		printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
		scanf("%d",&main_exit);
		if (main_exit==1)
			printmenu();
		else if (main_exit==2)
			exit_program();
		else if(main_exit==0)
			update();
		else {
			printf("\nInvalid!\a");
			goto edit_invalid;
		}
	}
	else {
		printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
		scanf("%d",&main_exit);
		if (main_exit==1)
			printmenu();
		else
			exit_program();
	}
}
/*dis function is used 2 delete account*/
/*INPUT=enter ac no,OUTPUT=acnt vl b removed from file*/
void dlt() {

	FILE *old,*new;
	int test=0;
	char filename[32];
	old=fopen("record.dat","r");
	new=fopen("new.dat","w");
	printf("Enter the account no. of the customer you want to remove:");
	scanf("%d",&rem.acc_no);
	while (fscanf(old,"%d", &add.acc_no) != EOF) {
		fscanf(old, "%s", add.name);  
		fscanf(old, "%d", &add.dob.month); 
		fscanf(old, "%d", &add.dob.day);
		fscanf(old, "%d", &add.dob.year);
		fscanf(old, "%d", &add.age);
		fscanf(old, "%s", add.address);
		fscanf(old, "%s", add.citizenship);
		fscanf(old, "%lf", &add.phone);
		fscanf(old, "%s", add.acc_type);
		fscanf(old, "%f", &add.amt);
		fscanf(old, "%d", &add.deposit.month);
		fscanf(old, "%d", &add.deposit.day);
		fscanf(old, "%d\n", &add.deposit.year);

		if(add.acc_no!=rem.acc_no){
			fprintf(new,"%d\n", add.acc_no);
			fprintf(new, "%s\n", add.name);  
			fprintf(new, "%d\n", add.dob.month); 
			fprintf(new, "%d\n", add.dob.day);
			fprintf(new, "%d\n", add.dob.year);
			fprintf(new, "%d\n", add.age);
			fprintf(new, "%s\n", add.address);
			fprintf(new, "%s\n", add.citizenship);
			fprintf(new, "%lf\n", add.phone);
			fprintf(new, "%s\n", add.acc_type);
			fprintf(new, "%f\n", add.amt);
			fprintf(new, "%d\n", add.deposit.month);
			fprintf(new, "%d\n", add.deposit.day);
			fprintf(new, "%d\n", add.deposit.year);
		}
		else {
			test++;
			printf("\nRecord deleted successfully!\n");
		}
	}
	fclose(old);
	fclose(new);
	strcpy(filename, "record.dat");
	remove(filename);
	rename("new.dat","record.dat");
	if(test==0){
		printf("\nRecord not found!!\a\a\a");
dlt_invalid:
		printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
		scanf("%d",&main_exit);
		if (main_exit==1)
			printmenu();
		else if (main_exit==2)
			exit_program();
		else if(main_exit==0)
			dlt();
		else{
			printf("\nInvalid!\a");
			goto dlt_invalid;
		}
	}     
	else{
		printf("\nEnter 1 to go to the main menu and 0 to exit:");
		scanf("%d",&main_exit);
		if (main_exit==1)
			printmenu();
		else
			exit_program();

	}
}
/*dis function is used deposit n widraw money*/
/*INPUT=enter ac no n amount, OUTPUT=it vl deposit/widraw amt n update the ac*/
void transact(void) {
	int choice,test=0;
	FILE *old,*new;
	old=fopen("record.dat","r");
	new=fopen("new.dat","w");
	printf("Enter the account no. of the customer:");
	scanf("%d",&transaction.acc_no);
	while (fscanf(old,"%d", &add.acc_no) != EOF) {
		fscanf(old, "%s", add.name);  
		fscanf(old, "%d", &add.dob.month ); 
		fscanf(old, "%d", &add.dob.day );
		fscanf(old, "%d", &add.dob.year );
		fscanf(old, "%d", &add.age );
		fscanf(old, "%s", add.address );
		fscanf(old, "%s", add.citizenship );
		fscanf(old, "%lf", &add.phone );
		fscanf(old, "%s", add.acc_type);
		fscanf(old, "%f", &add.amt);
		fscanf(old, "%d", &add.deposit.month);
		fscanf(old, "%d", &add.deposit.day);
		fscanf(old, "%d\n", &add.deposit.year );
		if(add.acc_no==transaction.acc_no) {
			test=1;
			if(strcmp(add.acc_type,"fixed1")==0||strcmp(add.acc_type,"fixed2")==0||strcmp(add.acc_type,"fixed3")==0) {
			
				printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
				printmenu();

			}
			printf("\n\nDo you want to\n");
			printf("1.Deposit\n");
			printf("2.Withdraw?\n\n");
			printf("Enter your choice(1 for deposit and 2 for withdraw):");
			scanf("%d",&choice);
			if (choice==1){
				printf("Enter the amount you want to deposit:$ ");
				scanf("%f",&transaction.amt);
				add.amt+=transaction.amt;
				fprintf(new,"%d\n", add.acc_no);
				fprintf(new, "%s\n", add.name);  
				fprintf(new, "%d\n", add.dob.month); 
				fprintf(new, "%d\n", add.dob.day);
				fprintf(new, "%d\n", add.dob.year);
				fprintf(new, "%d\n", add.age);
				fprintf(new, "%s\n", add.address);
				fprintf(new, "%s\n", add.citizenship);
				fprintf(new, "%lf\n", add.phone);
				fprintf(new, "%s\n", add.acc_type);
				fprintf(new, "%f\n", add.amt);
				fprintf(new, "%d\n", add.deposit.month);
				fprintf(new, "%d\n", add.deposit.day);
				fprintf(new, "%d\n", add.deposit.year);
				printf("\n\nDeposited successfully!");
			}
			else {
				printf("Enter the amount you want to withdraw:$ ");
				scanf("%f",&transaction.amt);
				add.amt-=transaction.amt;
				fprintf(new,"%d\n", add.acc_no);
				fprintf(new, "%s\n", add.name);  
				fprintf(new, "%d\n", add.dob.month ); 
				fprintf(new, "%d\n", add.dob.day );
				fprintf(new, "%d\n", add.dob.year );
				fprintf(new, "%d\n", add.age );
				fprintf(new, "%s\n", add.address );
				fprintf(new, "%s\n", add.citizenship );
				fprintf(new, "%lf\n", add.phone );
				fprintf(new, "%s\n", add.acc_type);
				fprintf(new, "%f\n", add.amt);
				fprintf(new, "%d\n", add.deposit.month);
				fprintf(new, "%d\n", add.deposit.day);
				fprintf(new, "%d\n", add.deposit.year );
				printf("\n\nWithdrawn successfully!");
			}

		}
		else {
			fprintf(new,"%d\n", add.acc_no);
			fprintf(new, "%s\n", add.name);  
			fprintf(new, "%d\n", add.dob.month ); 
			fprintf(new, "%d\n", add.dob.day );
			fprintf(new, "%d\n", add.dob.year );
			fprintf(new, "%d\n", add.age );
			fprintf(new, "%s\n", add.address );
			fprintf(new, "%s\n", add.citizenship );
			fprintf(new, "%lf\n", add.phone );
			fprintf(new, "%s\n", add.acc_type);
			fprintf(new, "%f\n", add.amt);
			fprintf(new, "%d\n", add.deposit.month);
			fprintf(new, "%d\n", add.deposit.day);
			fprintf(new, "%d\n", add.deposit.year );
		}
	}
	fclose(old);
	fclose(new);
	remove("record.dat");
	rename("new.dat","record.dat");
	if(test!=1) {
		printf("\n\nRecord not found!!");
transact_invalid:
		printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
		scanf("%d",&main_exit);
		if (main_exit==0)
			transact();
		else if (main_exit==1)
			printmenu();
		else if (main_exit==2)
			exit_program();
		else {
			printf("\nInvalid!");
			goto transact_invalid;
		}

	}
	else {
	
		printf("\nEnter 1 to go to the main menu and 0 to exit:");
		scanf("%d",&main_exit);
		if (main_exit==1)
			printmenu();
		else
			exit_program();
	}

}
/*to view list of acount holders*/
void customer_list() {
	FILE *view;
	view=fopen("record.dat","r");
	int test=0;
	printf("\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");

	while(fscanf(view,"%d", &add.acc_no) != EOF){
		fscanf(view, "%s", add.name);  
		fscanf(view, "%d", &add.dob.month ); 
		fscanf(view, "%d", &add.dob.day );
		fscanf(view, "%d", &add.dob.year );
		fscanf(view, "%d", &add.age );
		fscanf(view, "%s", add.address );
		fscanf(view, "%s", add.citizenship );
		fscanf(view, "%lf", &add.phone );
		fscanf(view, "%s", add.acc_type);
		fscanf(view, "%f", &add.amt);
		fscanf(view, "%d", &add.deposit.month);
		fscanf(view, "%d", &add.deposit.day);
		fscanf(view, "%d\n", &add.deposit.year );
		printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf",add.acc_no,add.name,add.address,add.phone);
		test++;
	}   

	fclose(view);
	if (test==0)
		printf("\nNO RECORDS!!\n");

view_list_invalid:
	printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
	scanf("%d",&main_exit);
	if (main_exit==1)
		printmenu();
	else if(main_exit==0)
		exit_program();
	else {
		printf("\nInvalid!\a");
		goto view_list_invalid;
	}
}
/*dis function gives info about customer acount*/
/*INPUT=entr ac no, OUTPUT=it vl show all details abt ac*/
void details(void) {
	FILE *fp;
	int test=0,rate;
	int choice;
	float time;
	float intrst;
	fp=fopen("record.dat","r");
	printf("Do you want to check by\n1.Account no\n2.Name\nEnter your choice:");
	scanf("%d",&choice);
	if (choice==1) {
		printf("Enter the account number:");
		scanf("%d",&check.acc_no);

		while (fscanf(fp,"%d", &add.acc_no) != EOF){
			fscanf(fp, "%s", add.name);  
			fscanf(fp, "%d", &add.dob.month ); 
			fscanf(fp, "%d", &add.dob.day );
			fscanf(fp, "%d", &add.dob.year );
			fscanf(fp, "%d", &add.age );
			fscanf(fp, "%s", add.address );
			fscanf(fp, "%s", add.citizenship );
			fscanf(fp, "%lf", &add.phone );
			fscanf(fp, "%s", add.acc_type);
			fscanf(fp, "%f", &add.amt);
			fscanf(fp, "%d", &add.deposit.month);
			fscanf(fp, "%d", &add.deposit.day);
			fscanf(fp, "%d\n", &add.deposit.year );
			if(add.acc_no==check.acc_no) {
				test=1;
				printf("\nAccount NO.:%d\n", add.acc_no);
				printf(" Name:%s \n", add.name);
				printf(" DOB:%d/%d/%d \n", add.dob.month,add.dob.day,add.dob.year);
				printf(" Age:%d \n", add.age);
				printf(" Address:%s \n", add.address);
				printf(" Citizenship No:%s \n", add.citizenship);
				printf("Phone number:%.0lf \n", add.phone);
				printf("Type Of Account:%s \n",add.acc_type);
				printf(" Amount deposited:$ %.2f \n",add.amt);
				printf("Date Of Deposit:%d/%d/%d\n\n",add.deposit.month,add.deposit.day,add.deposit.year);
				if(strcmp(add.acc_type,"fixed1")==0) {
				
					time=1.0;
					rate=9;
					intrst=interest(time,add.amt,rate);
					printf("\n\nYou will get $%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
				}
				else if(strcmp(add.acc_type,"fixed2")==0) {
				
					time=2.0;
					rate=11;
					intrst=interest(time,add.amt,rate);
					printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);

				}
				else if(strcmp(add.acc_type,"fixed3")==0) {
				
					time=3.0;
					rate=13;
					intrst=interest(time,add.amt,rate);
					printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);

				}
				else if(strcmp(add.acc_type,"saving")==0) {
				
					time=(1.0/12.0);
					rate=8;
					intrst=interest(time,add.amt,rate);
					printf("\n\nYou will get $.%.2f as interest on %d of every month",intrst,add.deposit.day);

				}
				else if(strcmp(add.acc_type,"current")==0)
					printf("\n\nYou will get no interest\a\a");

				

			}
		}
	}
	else if (choice==2) {
	        printf("Enter the name:");
		scanf("%s",check.name);
		while (fscanf(fp,"%d",&add.acc_no) != EOF) {
			fscanf(fp, "%s", add.name);  
			fscanf(fp, "%d", &add.dob.month ); 
			fscanf(fp, "%d", &add.dob.day );
			fscanf(fp, "%d", &add.dob.year );
			fscanf(fp, "%d", &add.age );
			fscanf(fp, "%s", add.address );
			fscanf(fp, "%s", add.citizenship );
			fscanf(fp, "%lf", &add.phone );
			fscanf(fp, "%s", add.acc_type);
			fscanf(fp, "%f", &add.amt);
			fscanf(fp, "%d", &add.deposit.month);
			fscanf(fp, "%d", &add.deposit.day);
			fscanf(fp, "%d\n", &add.deposit.year );	
			if(strcmp(add.name,check.name)==0) {
				test=1;
				printf("\nAccount NO.:%d\n", add.acc_no);
				printf(" Name:%s \n", add.name);
				printf(" DOB:%d/%d/%d \n", add.dob.month,add.dob.day,add.dob.year);
				printf(" Age:%d \n", add.age);
				printf(" Address:%s \n", add.address);
				printf(" Citizenship No:%s \n", add.citizenship);
				printf("Phone number:%.0lf \n", add.phone);
				printf("Type Of Account:%s \n",add.acc_type);
				printf(" Amount deposited:$ %.2f \n",add.amt);
				printf("Date Of Deposit:%d/%d/%d\n\n",add.deposit.month,add.deposit.day,add.deposit.year);
				if(strcmp(add.acc_type,"fixed1")==0) {
				
					time=1.0;
					rate=9;
					intrst=interest(time,add.amt,rate);
					printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
				}
				else if(strcmp(add.acc_type,"fixed2")==0) {
				
					time=2.0;
					rate=11;
					intrst=interest(time,add.amt,rate);
					printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);

				}
				else if(strcmp(add.acc_type,"fixed3")==0) {
				
					time=3.0;
					rate=13;
					intrst=interest(time,add.amt,rate);
					printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);

				}
				else if(strcmp(add.acc_type,"saving")==0) {
				
					time=(1.0/12.0);
					rate=8;
					intrst=interest(time,add.amt,rate);
					printf("\n\nYou will get $.%.2f as interest on %d of every month",intrst,add.deposit.day);

				}
				else if(strcmp(add.acc_type,"current")==0)
					printf("\n\nYou will get no interest\a\a");

				
			}
		}
	}
	fclose(fp);
	if(test!=1) {
		printf("\nRecord not found!!\a\a\a");
see_invalid:
		printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
		scanf("%d",&main_exit);

		if (main_exit==1)
			printmenu();
		else if (main_exit==2)
			exit_program();
		else if(main_exit==0)
			details();
		else {
		
			printf("\nInvalid!\a");
			goto see_invalid;
		}
	}
	else{
		printf("\nEnter 1 to go to the main menu and 0 to exit:");
		scanf("%d",&main_exit);
	}
	if (main_exit==1)
		printmenu();
	else
		exit_program();


}
/*dis function ends d program*/
void exit_program() {
	printf("\n\n\n\nThank you...");
}


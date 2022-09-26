#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
struct patient
{
	int age;
	char Fname[20];
	char Lname[20];
	char Gender;
	char Address[30];
	char contact[20];
	char email[20];
	char problem[20];
	char prescripedDoctor[20];
};
struct patient p;
int choice;
void title(void);
void menu(void);
void login(void);
void title(void);
void add_item(void);
void menu(void);
void welcome()
{
	printf("\n\t\t\t\t********************");
	printf("\n\t\t\t\t     Welcome to\n");

	printf("\n\t\t\t         Sharda Hospital&\n\t\t\t\t  Management system \n");
	printf("\n\t\t\t\t********************");
	printf("\n\n\nPlease enter any key to continue...");
	getch();
	system("cls");
}
void login()
{
	title();
	char username[20];
	char n[20];
	char original_username[]="shubhi";
	char original_password[]="1234";
	int e=0;
	do
	{
	printf("\n\n\t\tenter username");
	scanf("%s",&username);
	printf("\n\n\t\tenter password");
	scanf("%s",&n);
	if(strcmp(original_username,username)==0&&strcmp(original_password,n)==0)
	{
		printf("\n....\tLogin successful...... :)");
		printf("\nplease enter any key...");
		getch();
		system("cls");
		e=0;
		menu();
	}
	else 
	{
		printf("\nIncorrect Id or password :(");
		e=1;
	}
    }while(e);
}
void title()
{
	printf("\n\t-----------------------------------------------------------");
	printf("\n\t\t\tSharda hospital");
	printf("\n\t-----------------------------------------------------------");
	
}
void add_item()
{
	
	int i;
	char ch;
//	struct patient p;
	FILE *fp;
	Start:
	fp=fopen("abc.txt","a");
	system("cls");
	title();
	printf("\n\t\t!!!!!!!!!!!!!!!!!!!!!Add record!!!!!!!!!!!!!!!!!!!!!!!\n");
	A:
		printf("\n\t\tFirst Name : ");
		fflush(stdin);
		scanf("%s",&p.Fname);
		if(strlen(p.Fname)<2||strlen(p.Fname)>20)
		{
			printf("\n\tInvalid first name \n");
			printf("\tTry Again :)");
			goto A;
		}
	else 
	{
		B:
			printf("\n\t\tLast Name : ");
			fflush(stdin);
			scanf("%s",&p.Lname);
			if(strlen(p.Lname)<2||strlen(p.Lname)>20)
		{
			printf("\n\tInvalid Last name \n");
			printf("\n\t\tTry Again :)");
			goto B;
		}
		else 
		{
			C:
				printf("\n\t\tGender :");
				fflush(stdin);
				scanf("%c",&p.Gender);
				if(p.Gender=='m'||p.Gender=='f'||p.Gender=='M'||p.Gender=='F')
				{
				  
				  printf("\n\t\tAge :");
				  scanf("%d",&p.age);
				  D:
				  printf("\n\t\tAddress :");
				  fflush(stdin);
				  scanf("%s",&p.Address);
				  if(strlen(p.Address)>20||strlen(p.Address)<2)
				  {
				  	printf("\n\t\tAddress Invalid\n");
				  	printf("\n\t\tTry again :)\n");
				  	goto D;
				  }	
				  else 
				  {
				    M:
				  	printf("\n\t\tContact Number :");
				  	scanf("%s",&p.contact);
				  	if(strlen(p.contact)<10||strlen(p.contact)>10)
				  	{
				  	printf("\n\tInvalid contact number");
				  	printf("\n\tTry Again :)");
				  	goto M;
				    }
				  	printf("\n\t\tE-mail address :");
				  	fflush(stdin);
				  	scanf("%s",&p.email);
				  	printf("\n\t\tProblem :");
				  	fflush(stdin);
				  	scanf("%s",&p.problem);
				  
				  	fflush(stdin);
				  	printf("\n\t\tPrescribed Doctor :");
				  	fflush(stdin);
				  	fflush(stdin);
				  	scanf("%s",&p.prescripedDoctor);
				  //	fprintf(fp,"%d \n%s \n%s \n%s \n%s \n%s \n%c \n%s \n%s\n",p.age,p.Address,p.contact,p.email,p.Fname,p.Lname,p.Gender,p.prescripedDoctor,p.problem);
				   
				   fprintf(fp,"%s\n %s\n %d\n %c\n %s\n %s\n %s\n %s\n %s\n",p.Fname,p.Lname,p.age,p.Gender,p.contact,p.Address,p.email,p.problem,p.prescripedDoctor);
		
				   printf("\n\t\t....Successfully record added...... ");
				    fclose(fp);
				    Z:
				    printf("\n\t\tDo you want to add more records(y/n)");
				    fflush(stdin);
				    scanf("%c",&ch);
				    if(ch=='y'||ch=='Y')
				    goto Start;
				    else if(ch=='N'||ch=='n')
				    menu();
				    else 
				    {
				    printf("\n\t\tEnter a valid choice");
				    goto Z;
				    }
			     }
				}
				else 
				{
					printf("Invalid Gender :(");
					goto C;
				}
	}
		}
}
void list_record()
{
	FILE *fp;
	
	fp=fopen("abc.txt","r");
	system("cls");
	title();
		printf("\n\t\t!!!!!!!!!!!!!!!!!!!!!List record!!!!!!!!!!!!!!!!!!!!!!!\n");
		printf("\n\n\n");
		
	//	printf("\n--------------------------------------------------------------------------------\n");
		while(fscanf(fp,"%s %s %d %c %s %s %s %s %s",&p.Fname,&p.Lname,&p.age,&p.Gender,&p.contact,&p.Address,&p.email,&p.problem,&p.prescripedDoctor)!=EOF)
		{
			printf(" \nFirst name ->%s ",p.Fname);
			printf(" \nLast name ->%s ",p.Lname);
			printf(" \nAge ->%d  ",p.age);
			printf(" \nGender ->%c ",p.Gender);
			printf(" \nContact ->%s ",p.contact);
			printf(" \nAddress ->%s ",p.Address);
			printf(" \nEmail ->%s ",p.email);
			printf(" \nProblem ->%s ",p.problem);
			printf(" \nDoctor ->%s ",p.prescripedDoctor);
			printf("\n\t--------------------------------------------------------\n");
		}
		getch();
		fclose(fp);
		
		menu();
}
void search()
{
	system("cls");
	char fname[20];
	char lname[20];
	int a,e=0;
	char ch;
	title();
	FILE *fp;
	fp=fopen("abc.txt","r");
	printf("\n\t!!!!!!!!!!!!!!!!!!!!!!!!Search record!!!!!!!!!!!!!!!!!!!!!!\n");
	printf("\nenter patient First-name to search :");
	scanf("%s",&fname);
	fflush(stdin);
	printf("\nenter patient Last-name to search :");
	scanf("%s",&lname);
	printf("\nAge :");
	scanf("%d",&a);
//	while(fscanf(fp,"%s %s %d",&p.Fname,&p.Lname,&p.age)!=EOF)
	while(fscanf(fp,"%s %s %d %c %s %s %s %s %s",&p.Fname,&p.Lname,&p.age,&p.Gender,&p.contact,&p.Address,&p.email,&p.problem,&p.prescripedDoctor)!=EOF)
	{
		if(strcmp(p.Fname,fname)==0&&strcmp(p.Lname,lname)==0&&p.age==a)
		{
			printf(" \nFirst name ->%s ",p.Fname);
			printf(" \nLast name ->%s ",p.Lname);
			printf(" \nAge ->%d  ",p.age);
			printf(" \nGender ->%c ",p.Gender);
			printf(" \nContact ->%s ",p.contact);
			printf(" \nAddress ->%s ",p.Address);
			printf(" \nEmail ->%s ",p.email);
			printf(" \nProblem ->%s ",p.problem);
			printf(" \nDoctor ->%s ",p.prescripedDoctor);
			e=1;
			break;
		}
	}
	if(e==0)
	printf("\n\t\tPatient record is not found :( ");
	H:
	printf("\n\tDo you want to search more records ");
	fflush(stdin);
	scanf("%c",&ch);
	if(ch=='y'||ch=='Y')
	search();
	else if(ch=='n'||ch=='N')
	{
	printf("\n\tThanks for searching :)");
	getch();
	fclose(fp);
	menu();
    }
    else 
    {
    	printf("\n\tEnter a valid choice");
    	goto H;
	}
}
void edit()
{
	system("cls");
	title();
	char fname[20],lname[20];
	char g;
	int e=0,a;
	FILE *fp,*ek;
	int found=0;
	fp=fopen("abc.txt","r");
	ek=fopen("shubhi.txt","w");

	printf("\n\t!!!!!!!!!!!!!!!!!!!!!!!!Edit record!!!!!!!!!!!!!!!!!!!!!!\n");
	printf("\n\tenter patient First-name to edit :");
	scanf("%s",&fname);
		printf("\n\tenter patient Last-name to edit :");
	scanf("%s",&lname);
	printf("\n\tAge :");
	scanf("%d",&a);
	fflush(stdin);
	while(fscanf(fp,"%s %s %d %c %s %s %s %s %s",&p.Fname,&p.Lname,&p.age,&p.Gender,&p.contact,&p.Address,&p.email,&p.problem,&p.prescripedDoctor)!=EOF)
    {
    if(strcmp(p.Fname,fname)!=0||strcmp(p.Lname,lname)!=0||a!=p.age)
    	fprintf(ek,"%s\n %s\n %d\n %c\n %s\n %s\n %s\n %s\n %s\n",p.Fname,p.Lname,p.age,p.Gender,p.contact,p.Address,p.email,p.problem,p.prescripedDoctor);
	else
	{
		printf("\n\tFirst name:");
		fflush(stdin);
		scanf("%s",&p.Fname);
		printf("\n\tLast name:");
		fflush(stdin);
		scanf("%s",&p.Lname);
		fflush(stdin);
		printf("\n\tAge: ");
		fflush(stdin);
		scanf("%d",&p.age);
		printf("\n\tGender: ");
		fflush(stdin);
		scanf("%d",&p.Gender);
		printf("\n\tContact: ");
		fflush(stdin);
		scanf("%s",&p.contact);
		printf("\n\tAddress: ");
		fflush(stdin);
		scanf("%s",&p.Address);
		printf("\n\tE-mail: ");
		fflush(stdin);
		scanf("%s",&p.email);
		printf("\n\tProblem: ");
		fflush(stdin);
		scanf("%s",&p.problem);
		printf("\n\tPrescripted Doctor: ");
		fflush(stdin);
		scanf("%s",&p.prescripedDoctor);
		fprintf(ek,"%s\n %s\n %d\n %c\n %s\n %s\n %s\n %s\n %s\n",p.Fname,p.Lname,p.age,p.Gender,p.contact,p.Address,p.email,p.problem,p.prescripedDoctor);
	    found=1;
	
    }   	
    }
    if(found==0)
    {
    	printf("\n\tRecord not edited ");
    	getch();
    	fclose(fp);
    	fclose(ek);
    	menu();
	}
	else 
	{
	fclose(fp);
		fclose(ek);
		remove("abc.txt");
		rename("shubhi.txt","abc.txt");
		printf("\n\n\t\tRecord Edited successfully........\n");
		getch();
		menu();	
	}
	
}
void Delete()
{
system("cls");
char fname[20];
title();
printf("\n\n\t-------------------------- Delete record -----------------------\n");
FILE *fp,*ek;
int found=0;
	fp=fopen("abc.txt","r");
	ek=fopen("shubhi.txt","w");
	printf("\n\tenter patient first name to delete");
	scanf("%s",&fname);
	fflush(stdin);
	while(fscanf(fp,"%s %s %d %c %s %s %s %s %s",&p.Fname,&p.Lname,&p.age,&p.Gender,&p.contact,&p.Address,&p.email,&p.problem,&p.prescripedDoctor)!=EOF)
    {
    	if(strcmp(p.Fname,fname)!=0)
    	fprintf(ek,"%s\n %s\n %d\n %c\n %s\n %s\n %s\n %s\n %s\n",p.Fname,p.Lname,p.age,p.Gender,p.contact,p.Address,p.email,p.problem,p.prescripedDoctor);
	    else 
	    found=1;
    }
    if(found==0)
    {
    	printf("Record not found\n");
    	fclose(fp);
    	fclose(ek);
    	getch();
    	menu();
	}
	else 
	{
		fclose(fp);
		fclose(ek);
		remove("abc.txt");
		rename("shubhi.txt","abc.txt");
		printf("\n\n\t\tRecord deleted successfully\n");
		getch();
		menu();
	}
}
void menu()
{
	
	//struct patient *p;
	//FILE *fp;
	system("cls");
    title();
	do
	{
		printf("\n\t\t1.Add patient record");
		printf("\n\t\t2.List patient record");
		printf("\n\t\t3.Search patient record");
		printf("\n\t\t4.Edit patient record");
		printf("\n\t\t5.Delete patient record");
		printf("\n\t\t6.exit");
		printf("\n\n\n\t\tChoose from 1 to 6 : ");
		scanf("%d",&choice);
		system("cls");
	    switch(choice)
	    {
	    	case 1:
	    		add_item();
	    		break;
	    	case 2:
	    		list_record();
	    		break;
	    	case 3:
	    		search();
	    		break;
	     	case 4:
	    		edit();
	    		break;
	    	case 5:
	    		Delete();
	    		break;
	    	case 6:
	    		printf("You are exit from program\n");
	    		printf("Thanks for visiting\n");
	    		getch();
	    		exit(0);
	    		break;
	    	default:
	    		printf("Enter a valid choice\n");
	    		getch();
	    		break;
		}
    }while(choice!=6);
    
}
void main()
{
	system("COLOR 0A");
	welcome();
    login();
    menu();
	//return 0;
}

#include <stdio.h>
#include <conio.h> 
#include <string.h> 
#include <windows.h> //for loading
#define PROGRESS_BAR_WIDTH 30//for loading 
#define LOADING_TIME_SECONDS 10 //for loading
struct withdraw{
	int amount;
};
struct deposit{
	int amount;
};
struct bill{
	int bill_amount;
	char dep[10];
	int card;
};
struct trans{
	char tname[30];
	int tam,timei;
};
int hard(char rn[100], char data[20], int pass, int mf1)
{
	int uc;
	FILE *pf;
	
		printf("\t\t\t\t\t\t\tYour Account\nName: %s\nBalance: %d\nPassword: %d",data,pass,mf1);
		fclose(pf);
		getch();
			printf("\n\n\nNow,\nWhat You Want To Do:\nFor \"WITHDRAW\" Type 1\nFor \"PAYING BILL\" Type 2\nFor \"TANSICTION\" Type 3\nFor \"DEPOSIT\" Type 4\nFor \"EXIT\" Type 5\nType: ");
		scanf("%d",&uc);
		switch (uc)
		{
			case 1:
			{withdraw(rn,data,pass,mf1);}
			break;
			case  2:
			{bill(rn,data,pass,mf1);}
			break;
			case 3:
			{transiction(rn,data,pass,mf1);}
			case 4:
			{deposit(rn,data,pass,mf1);}
			case 5:
			{ex();}	
		}
}
int load()//for loading
{
	HANDLE m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
 
    SetConsoleTextAttribute ( m_hConsole, 
                              FOREGROUND_RED);
	char progress_bar[PROGRESS_BAR_WIDTH + 1] ; 
    int progress_level = 0 ; 
    int percent ; 
    memset( progress_bar, '-', PROGRESS_BAR_WIDTH ) ; 
    progress_bar[PROGRESS_BAR_WIDTH] = '\0' ; 
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t              LOADING              \n"); 
    for( percent = 0; percent <= 100; percent++ )  
    {  
        progress_level = (percent * PROGRESS_BAR_WIDTH) / 100 ; 
        memset( progress_bar, '#', progress_level ) ; 
        printf( "\r\t\t\t\t\t\t\t\t%s(%d%%)", progress_bar, percent ) ; 
        Sleep( LOADING_TIME_SECONDS * 1.5 ) ; 
    } 
     SetConsoleTextAttribute ( m_hConsole,
                              FOREGROUND_RED |
                              FOREGROUND_GREEN |
                              FOREGROUND_BLUE );
	system("color 02");						  
  return 0;
}
int withdraw (char name[100], char naam[100], int pass, int mf1)
{
	FILE *r;
	struct withdraw w;
	int amou,imei,uc,status,choice,t;
	char nem[50];
	
	fflush(stdin);
	printf("\nEnter amount For Withdraw: ");
	scanf("%d",&w.amount);
	
	if(pass>=w.amount)
	{	
		status= remove(name);
		
		r=fopen(name,"r");
		fscanf(r,"%s\n%d\n%d",naam,&pass,&mf1);
		fclose(r);
		t=pass-w.amount;
		r=fopen(name,"w");
		fprintf(r,"%s\n%d\n%d",naam,t,mf1);
		fclose(r);
		load();
		system("cls");
		printf("\nCONGRATULATION! Successfully Done\nRECIPT:\n");
		printf(":----------------:\n:Name: %s     :\n:-----------------:\n:Withdraw Amount: %d:\n:---------------:",naam,w.amount);
		printf("\n\nType 1) Log Off\nType 2) Continue\nType: ");
		scanf("%d",&uc);
		if(uc==2)
		{
			system("cls");
			printf("\t\t\t\t\t\t\tYour Account\nName: %s\nBalance: %d\nPassword: %d",naam,t,mf1);
			getch();
			printf("\n\n\nNow,\nWhat You Want To Do:\nFor \"WITHDRAW\" Type 1\nFor \"PAYING BILL\" Type 2\nFor \"TANSICTION\" Type 3\nFor \"DEPOSIT\" Type 4\nFor \"EXIT\" Type 5\nType: ");
			scanf("%d",&uc);
			switch (uc)
			{
				case 1:
				{withdraw(name,naam,t,mf1);}
				break;
				case  2:
				{bill(name,naam,t,mf1);}
				break;
				case 3:
				{transiction(name,naam,t,mf1);}
				case 4:
				{deposit(name,naam,t,mf1);}	
				case 5:
				{ex();}	
			}	
		}
		else if(uc==1)
		{
			printf("\nYour Logged Off");
			while(choice!=3)
			{
				getch();
				system("cls");
				printf("\n\t\t\t\t\t\t\t\t\t\tMAIN PAGE\n");
				printf("For Login Type 1:\nFor Signup Type 2:\nFor Exit Type 3:\nType: ");
				scanf("%d",&choice);
				switch (choice)
				{
					case 1:
					{
						load();
						login();
					}
					break;
					case 2:
					{
						signup();
					}
					break;
					case 3:
					{
						ex();
					}
					break;
				}	
			}
			getch();
		}	
	}
	else if(pass<w.amount)
	{
	printf("\nSorry! You Have Not Enough Money to Transfer");
	getch();
	system("cls");
		printf("\t\t\t\t\t\t\tYour Account\nName: %s\nBalance: %d\nPassword: %d",naam,pass,mf1);
		getch();
		printf("\n\n\nNow,\nWhat You Want To Do:\nFor \"WITHDRAW\" Type 1\nFor \"PAYING BILL\" Type 2\nFor \"TANSICTION\" Type 3\nFor \"DEPOSIT\" Type 4\nFor \"EXIT\" Type 5\nType: ");
		scanf("%d",&uc);
		switch (uc)
		{
			case 1:
			{withdraw(name,naam,pass,mf1);}
			break;
			case  2:
			{bill(name,naam,pass,mf1);}
			break;
			case 3:
			{transiction(name,naam,pass,mf1);}
			case 4:
			{deposit(name,naam,pass,mf1);}
			case 5:
			{ex();}	
		}
	}
}
int deposit (char name[100], char naam[100], int pass, int mf1)
{
	FILE *r;
	struct deposit d;
	int amou,imei,uc,status,choice,t;
	char nem[50];
	
	fflush(stdin);
	printf("\nEnter amount For deposit: ");
	scanf("%d",&d.amount);	
		status= remove(name);
		
		r=fopen(name,"r");
		fscanf(r,"%s\n%d\n%d",naam,&pass,&mf1);
		fclose(r);
		t=pass+d.amount;
		r=fopen(name,"w");
		fprintf(r,"%s\n%d\n%d",naam,t,mf1);
		fclose(r);
		load();
		system("cls");
		printf("\nCONGRATULATION! Successfully Done\nRECIPT:\n");
		printf(":----------------:\n:Name: %s     :\n:-----------------:\n:Deposit Amount: %d:\n:---------------:",naam,d.amount);
		printf("\n\nType 1) Log Off\nType 2) Continue\nType: ");
		scanf("%d",&uc);
		if(uc==2)
		{
			system("cls");
			printf("\t\t\t\t\t\t\tYour Account\nName: %s\nBalance: %d\nPassword: %d",naam,t,mf1);
			getch();
			printf("\n\n\nNow,\nWhat You Want To Do:\nFor \"WITHDRAW\" Type 1\nFor \"PAYING BILL\" Type 2\nFor \"TANSICTION\" Type 3\nFor \"DEPOSIT\" Type 4\nFor \"EXIT\" Type 5\nType: ");
			scanf("%d",&uc);
			switch (uc)
			{
				case 1:
				{withdraw(name,naam,t,mf1);}
				break;
				case  2:
				{bill(name,naam,t,mf1);}
				break;
				case 3:
				{transiction(name,naam,t,mf1);}
				case 4:
				{deposit(name,naam,t,mf1);}	
				case 5:
				{ex();}	
			}	
		}
		else if(uc==1)
		{
			printf("\nYour Logged Off");
			while(choice!=3)
			{
				getch();
				system("cls");
				printf("\n\t\t\t\t\t\t\t\t\t\tMAIN PAGE\n");
				printf("For Login Type 1:\nFor Signup Type 2:\nFor Exit Type 3:\nType: ");
				scanf("%d",&choice);
				switch (choice)
				{
					case 1:
					{
						load();
						login();
					}
					break;
					case 2:
					{
						signup();
					}
					break;
					case 3:
					{
						ex();
					}
					break;
				}	
			}
			getch();
		}	
}
int bill (char name[100], char naam[100], int pass, int mf1)
{
	FILE *r;
	int amou,imei,uc,status,choice,t;
	char nem[50];
	struct bill b;
	
	fflush(stdin);
	printf("\nEnter amount Of Bill: ");
	scanf("%d",&b.bill_amount);
	fflush(stdin);
	printf("Enter Name Of departement You Want To Pay Bill\n(For Ex:  Gas, KE, Water): ");
	gets(b.dep);
	printf("Enter Your Card number: ");
	scanf("%d",&b.card);
	
	if(pass>=b.bill_amount)
	{	
		status= remove(name);
		
		r=fopen(name,"r");
		fscanf(r,"%s\n%d\n%d",naam,&pass,&mf1);
		fclose(r);
		t=pass-b.bill_amount;
		r=fopen(name,"w");
		fprintf(r,"%s\n%d\n%d",naam,t,mf1);
		fclose(r);
		load();
		system("cls");
		printf("\nCONGRATULATION! Bill Successfully Paid\nRECIPT\n");
		printf(":----------------:\n:Name: %s     :\n:-----------------:\n:Department Name: %s     :\n:-----------------:\n:Amount: %d:\n:---------------:",naam,b.dep,b.bill_amount);
		printf("\n\nType 1) Log Off\nType 2) Continue\nType: ");
		scanf("%d",&uc);
		if(uc==2)
		{
			system("cls");
			printf("\t\t\t\t\t\t\tYour Account\nName: %s\nBalance: %d\nPassword: %d",naam,t,mf1);
			getch();
			printf("\n\n\nNow,\nWhat You Want To Do:\nFor \"WITHDRAW\" Type 1\nFor \"PAYING BILL\" Type 2\nFor \"TANSICTION\" Type 3\nFor \"DEPOSIT\" Type 4\nFor \"EXIT\" Type 5\nType: ");
			scanf("%d",&uc);
			switch (uc)
			{
				case 1:
				{withdraw(name,naam,t,mf1);}
				break;
				case  2:
				{bill(name,naam,t,mf1);}
				break;
				case 3:
				{transiction(name,naam,t,mf1);}
				case 4:
				{deposit(name,naam,t,mf1);}	
				case 5:
				{ex();}		
			}	
		}
		else if(uc==1)
		{
			printf("\nYour Logged Off");
			while(choice!=3)
			{
				getch();
				system("cls");
				printf("\n\t\t\t\t\t\t\t\t\t\tMAIN PAGE\n");
				printf("For Login Type 1:\nFor Signup Type 2:\nFor Exit Type 3:\nType: ");
				scanf("%d",&choice);
				switch (choice)
				{
					case 1:
					{
						load();
						login();
					}
					break;
					case 2:
					{
						signup();
					}
					break;
					case 3:
					{
						ex();
					}
					break;
				}	
			}
			getch();
		}
	}
	else if(pass<b.bill_amount)
	{
	printf("\nSorry! You Have Not Enough Money to Pay Bill");
	getch();
	system("cls");
		printf("\t\t\t\t\t\t\tYour Account\nName: %s\nBalance: %d\nPassword: %d",naam,pass,mf1);
		getch();
		printf("\n\n\nNow,\nWhat You Want To Do:\nFor \"WITHDRAW\" Type 1\nFor \"PAYING BILL\" Type 2\nFor \"TANSICTION\" Type 3\nFor \"DEPOSIT\" Type 4\nFor \"EXIT\" Type 5\nType: ");
		scanf("%d",&uc);
		switch (uc)
		{
			case 1:
			{withdraw(name,naam,pass,mf1);}
			break;
			case  2:
			{bill(name,naam,pass,mf1);}
			break;
			case 3:
			{transiction(name,naam,pass,mf1);}
			case 4:
			{deposit(name,naam,pass,mf1);}
			case 5:
			{ex();}	
		}
	}
}
int transiction (char name[100], char naam[100], int pass, int mf1)
{
	FILE *r;
	int amou,imei,uc,status,choice,t;
	char nem[50];
	struct trans z;
	
	fflush(stdin);
	printf("\nEnter amount For Transfer: ");
	scanf("%d",&z.tam);
	fflush(stdin);
	printf("Enter Name Of That person You Want To Transfer: ");
	gets(z.tname);
	printf("Enter IMEI number Of that Person's Account: ");
	scanf("%d",&z.timei);
	
	if(pass>=z.tam)
	{	
		status= remove(name);
		
		r=fopen(name,"r");
		fscanf(r,"%s\n%d\n%d",naam,&pass,&mf1);
		fclose(r);
		t=pass-z.tam;
		r=fopen(name,"w");
		fprintf(r,"%s\n%d\n%d",naam,t,mf1);
		fclose(r);
		load();
		system("cls");
		printf("\nCONGRATULATION! Successfully Transfered\nRECIPT\n");
		printf("\n:---------------:\n:Name: %s:\n:---------------:\n:IMEI: %d   :\n:---------------:\n:Amount: %d   :\n:---------------:",z.tname,z.timei,z.tam);
		printf("\n\nType 1) Log Off\nType 2) Continue\nType: ");
		scanf("%d",&uc);
		if(uc==2)
		{
			system("cls");
			printf("\t\t\t\t\t\t\tYour Account\nName: %s\nBalance: %d\nPassword: %d",naam,t,mf1);
			getch();
			printf("\n\n\nNow,\nWhat You Want To Do:\nFor \"WITHDRAW\" Type 1\nFor \"PAYING BILL\" Type 2\nFor \"TANSICTION\" Type 3\nFor \"DEPOSIT\" Type 4\nFor \"EXIT\" Type 5\nType: ");
			scanf("%d",&uc);
			switch (uc)
			{
				case 1:
				{withdraw(name,naam,t,mf1);}
				break;
				case  2:
				{bill(name,naam,t,mf1);}
				break;
				case 3:
				{transiction(name,naam,t,mf1);}
				case 4:
				{deposit(name,naam,t,mf1);}
				case 5:
				{ex();}	
			}	
		}
		else if(uc==1)
		{
			printf("\nYour Logged Off");
			while(choice!=3)
			{
				getch();
				system("cls");
				printf("\n\t\t\t\t\t\t\t\t\t\tMAIN PAGE\n");
				printf("For Login Type 1:\nFor Signup Type 2:\nFor Exit Type 3:\nType: ");
				scanf("%d",&choice);
				switch (choice)
				{
					case 1:
					{
						load();
						login();
					}
					break;
					case 2:
					{
						signup();
					}
					break;
					case 3:
					{
						ex();
					}
					break;
				}	
			}
			getch();
		}
	}
	else if(pass<z.tam)
	{
	printf("\nSorry! You Have Not Enough Money to Transfer");
	getch();
	system("cls");
		printf("\t\t\t\t\t\t\tYour Account\nName: %s\nBalance: %d\nPassword: %d",naam,pass,mf1);
		getch();
		printf("\n\n\nNow,\nWhat You Want To Do:\nFor \"WITHDRAW\" Type 1\nFor \"PAYING BILL\" Type 2\nFor \"TANSICTION\" Type 3\nFor \"DEPOSIT\" Type 4\nFor \"EXIT\" Type 5\nType: ");
		scanf("%d",&uc);
		switch (uc)
		{
			case 1:
			{withdraw(name,naam,pass,mf1);}
			break;
			case  2:
			{bill(name,naam,pass,mf1);}
			break;
			case 3:
			{transiction(name,naam,pass,mf1);}
			case 4:
			{deposit(name,naam,pass,mf1);}
			case 5:
			{ex();}	
		}
	}
}
int ex()
{
	system("cls");
	system("color 04");
	printf("\nYour Logged Off");
	printf("\n\t\t\t\t\t\t\t\t\tThank you for using AN Bank! \n");
	getch();
	exit(-1);
}
int login()
{
	int user;
	fflush(stdin);
	system("cls");
	printf("Enter Your Account Password: ");
	scanf("%d",&user);
	load();
	system("cls");
	process(user);
}
int process(int net)
{
	FILE *pf;
	int age,uc,pass,mf1,a=0;
	char data[100],m[100],mf[100],name[100],rn[100];
	
	pf=fopen("Naeem[1].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	
		char rn[100]="Naeem[1].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[2].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	
		char rn[100]="Naeem[2].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[3].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	
		char rn[100]="Naeem[3].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[4].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	
		char rn[100]="Naeem[4].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[5].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	
		char rn[100]="Naeem[5].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[6].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	char rn[100]="Naeem[6].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[7].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	char rn[100]="Naeem[7].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[8].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	char rn[100]="Naeem[8].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[9].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	char rn[100]="Naeem[9].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[10].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	char rn[100]="Naeem[10].txt";
		a=5;
		hard(rn,data,pass,mf1);	
	}
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[11].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	char rn[100]="Naeem[11].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[12].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	char rn[100]="Naeem[12].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[13].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	char rn[100]="Naeem[13].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[14].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	char rn[100]="Naeem[14].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[15].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	char rn[100]="Naeem[15].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[16].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	char rn[100]="Naeem[16].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[17].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	char rn[100]="Naeem[17].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[18].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	char rn[100]="Naeem[18].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[19].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	char rn[100]="Naeem[19].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[20].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	char rn[100]="Naeem[20].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[21].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	char rn[100]="Naeem[21].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[22].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	char rn[100]="Naeem[22].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[23].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	char rn[100]="Naeem[23].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[24].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	char rn[100]="Naeem[24].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[25].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	char rn[100]="Naeem[25].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[26].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	char rn[100]="Naeem[26].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[27].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	char rn[100]="Naeem[27].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[28].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	char rn[100]="Naeem[28].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}	
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[29].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	char rn[100]="Naeem[29].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}	
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[30].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	char rn[100]="Naeem[30].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[31].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	char rn[100]="Naeem[31].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}	
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[32].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	char rn[100]="Naeem[32].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}	
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[33].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	char rn[100]="Naeem[33].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}	
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[34].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	char rn[100]="Naeem[34].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}	
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[35].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	char rn[100]="Naeem[35].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}	
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[36].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	char rn[100]="Naeem[36].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}	
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[37].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	char rn[100]="Naeem[37].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}	
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[38].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	char rn[100]="Naeem[38].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}	
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[39].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	
	{	char rn[100]="Naeem[39].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}	
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[40].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	char rn[100]="Naeem[40].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}	
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[41].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	char rn[100]="Naeem[41].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}	
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[42].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	char rn[100]="Naeem[42].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[43].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	char rn[100]="Naeem[43].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}	
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[44].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	char rn[100]="Naeem[44].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}	
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[45].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	char rn[100]="Naeem[45].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}	
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[46].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	char rn[100]="Naeem[46].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}	
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[47].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	char rn[100]="Naeem[47].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}	
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[48].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	char rn[100]="Naeem[48].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}	
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	pf=fopen("Naeem[49].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	char rn[100]="Naeem[49].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}
	pf=fopen("Naeem[50].txt","r");
	fscanf(pf,"%s\n%d\n%d",data,&pass,&mf1);
	if(mf1==net)
	{	char rn[100]="Naeem[50].txt";
		a=5;
		hard(rn,data,pass,mf1);
	}	
	else if(mf1!=net)
	{	fclose(pf);	 }
	
	if(a==0)
	{
		system("cls");
		printf("\nLogin UnsuccessFull\n\n");
		printf("OOPS!, \nSorry You Have No Account\nPlease SignUp First!");
	}
}
int signup()
{	FILE *c;
	FILE *pf;
	int coun,count,p,amount;
	char naam[100];
		
	c=fopen("countdown.txt","r");
	fscanf(c,"%d",&coun);
	fclose(c);
	c=fopen("countdown.txt","w");
	count=coun+1;
	fprintf(c,"%d",count);
	fclose(c);
				
	fflush(stdin);
	load();
	system("cls");
	printf("Enter Name: ");
	gets(naam);	
	printf("Enter amount: ");
	scanf("%d",&amount);
	printf("Enter password: ");
	scanf("%d",&p);
		
		if(p<151 && p>100)
		{
			printf("\n\nSORRY! Please Try Again Because your Typed password is Also Exist\n");
			getch();
		}
		
	else if(p>150 || p<100)
	{			
		if (coun==1)
		{	pf=fopen("Naeem[41].txt","w");	}
		else if (coun==2)
		{	pf=fopen("Naeem[42].txt","w");	}
		else if (coun==3)
		{	pf=fopen("Naeem[43].txt","w");	}
		else if (coun==4)
		{	pf=fopen("Naeem[44].txt","w");	}
		else if (coun==5)
		{	pf=fopen("Naeem[45].txt","w");	}
		else if (coun==6)
		{	pf=fopen("Naeem[46].txt","w");	}
		else if (coun==7)
		{	pf=fopen("Naeem[47].txt","w");	}
		else if (coun==8)
		{	pf=fopen("Naeem[48].txt","w");	}
		else if(coun==9)
		{	pf=fopen("Naeem[49].txt","w");	}
		else if(coun==10)
		{	pf=fopen("Naeem[50].txt","w");	}
		
			fprintf(pf,"%s\n%d\n%d",naam,amount,p);
			fclose(pf);
			load();
			system("cls");
			printf("\n!CONGRATULATIONS!\nSignUp SuccessFull!");
	}

}
int main()
{	
	system("color 02");
	int choice;
	printf("\t\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\n\t\t\t\t\xDB\t\t\t\t\t\t\t\t\t\t\t           \xDB\n\t\t\t\t\xDB\t\t\t\t\t\t\t\t\t\t\t           \xDB");
	printf("\n\t\t\t\t\xDB\t*           * ***** *        *****  ******  *     * *****    *****    ******               \xDB");
	printf("\n\t\t\t\t\xDB\t *         *  *     *      *       *      * * * * * *          *     *      *              \xDB");
	printf("\n\t\t\t\t\xDB\t  *   *   *   ***** *      *       *      * *  *  * *****      *     *      *              \xDB");
	printf("\n\t\t\t\t\xDB\t   * * * *    *     *      *       *      * *     * *          *     *      *              \xDB");
	printf("\n\t\t\t\t\xDB\t    *   *     ***** ******   *****  ******  *     * ******     *      ******               \xDB");
	printf("\n\t\t\t\t\xDB\t\t\t\t\t\t\t\t\t\t\t           \xDB\n\t\t\t\t\xDB\t\t\t\t\t\t\t\t\t\t\t           \xDB");
	printf("\n\t\t\t\t\xDB\t********************************************************************************           \xDB");
	printf("\n\t\t\t\t\xDB\t********************************************************************************           \xDB");
	printf("\n\t\t\t\t\xDB\t\t\t\t\t\t\t\t\t\t\t           \xDB\n\t\t\t\t\xDB\t\t\t\t\t\t\t\t\t\t\t           \xDB");
	printf("\n\t\t\t\t\xDB\t\t\t     *     *    *    * * *      *     *    * *   *                         \xDB");
	printf("\n\t\t\t\t\xDB\t\t\t    * *    * *  *    *    *    * *    * *  * *  *                          \xDB");
	printf("\n\t\t\t\t\xDB\t\t\t   * * *   *  * *    * * *    * * *   *  * * **                            \xDB");
	printf("\n\t\t\t\t\xDB\t\t\t  *     *  *   **    *    *  *     *  *   ** *  *                          \xDB");
	printf("\n\t\t\t\t\xDB\t\t\t *       * *    *    * * *  *       * *    * *   *                         \xDB");
	printf("\n\t\t\t\t\xDB\t\t\t\t\t\t\t\t\t\t\t           \xDB\n\t\t\t\t\xDB\t\t\t\t\t\t\t\t\t\t\t           \xDB");
	printf("\n\t\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\n\n\t\t\t\t\t\t\t\tFOR BETTER VIEW OPEN FULL SCREEN");
	printf("\n\n\t\t\t\t\t\t\t\t\tOUR SYSTEM FEATURES\n\n");
	printf("\t\t\t\tAN BANK offers you convenience of banking from home or your office because we understand that your time is important.\n");
	printf("\t\t\t\t\t\t\t   We provide you the secured banking experience.\n");
	printf("\t\t\t\t\t\t\t         We are trusted all over the country.\n");
	printf("\t\t\t\t\t\t      We will provide you the best possible service posssible\n");
	printf("\t\t\t\t\t\tFor any complaints please contact administration 0311-0237524,0348-2469484\nType Any Key:");
	while(choice!=3)
	{
		getch();
		system("cls");
		printf("\n\t\t\t\t\t\t\t\t\t\tMAIN PAGE\n");
		printf("For Login Type 1:\nFor Signup Type 2:\nFor Exit Type 3:\nType: ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
			{
				load();
				system("cls");
				login();
			}
			break;
			case 2:
			{
				load();
				system("cls");
				signup();
			}
			break;
			case 3:
			{
				system("cls");
				ex();
			}
			break;
		}	
	}
	getch();	
}

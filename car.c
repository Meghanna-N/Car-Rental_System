#include <stdio.h>
#include<string.h>
struct car
{
    char customer_name[50];
    int customer_phno;
    char customer_email[30];
    char customer_ID[13];
    char carrented[20];
    int n,rent,days;
    int dr,mr,yr,dret,mret,yret;
};
char carbrand[10][20]={"HYUNDAI","SUZUKI","HONDA","TOYOTA","FORD","TATA","MERCEDES","AUDI","ISUZU"};
char carmodel[10][20]={"Veloster","Celerio","Civic","Avalon","Explorer","Safari","E-Class","Q3","D-MAX"};
int carseat[10]={4,4,4,8,4,4,4,8,8};
int carrentperday[10]={950,850,450,950,750,550,1000,850,750};
int carrentpermontly[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int z=0,u=0;
struct car c,ca[10],cr[10],cn={0};
void login()
{
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="admin";
    do
{

    printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<  LOGIN FORM  >>>>>>>>>>>>>>>>>>>>>>>>>>  ");
    printf("\n\t\t\tENTER USERNAME:-");
	scanf("%s", &uname);
	printf(" \n\t\t\tENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';

	i=0;

		if(strcmp(uname,"user")==0 && strcmp(pword,"admin")==0)
	{
	printf("\n\n\nNOW YOU ARE LOGGED IN. WELCOME TO OUR SYSTEM !!");
	printf("\n\n\tPress any key to continue...");
	getch();
	break;
	}
	else
	{
		printf("\nSORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;

		getch();//holds the screen

	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();

		}
		system("cls");
}

void car_rent()
{
    int i,f;
    int t,days1=0,days2=0,days3=0;
    char ch;
    int j,x;
    printf("WELCOME DEAR CUSTOMER!!! \n");
    display();
    printf("ENTER THE BRAND OF CAR YOU WANT TO RENT: ");
    scanf("%s",c.carrented);
    printf("ENTER DATE ON WHICH YOU WILL TAKE THE CAR(dd mm yyyy): ");
    scanf("%d%d%d",&c.dr,&c.mr,&c.yr);
    printf("ENTER THE DATE ON WHICH YOU WILL RETURN THE CAR(dd mm yyyy): ");
    scanf("%d%d%d",&c.dret,&c.mret,&c.yret);
    printf("LETS CHECK WHETHER THE CAR IS AVAILABLE OR NOT\n");
    FILE *ptr;
    ptr=fopen("Car_rent.txt","r");
    fread(ca,sizeof(ca),1,ptr);
       for(i=0;i<10;i++)
       {
        if(strcmp(ca[i].carrented,c.carrented)==0)
        {
            for(t=0;t<=ca[i].mr;t++)
                days1+=carrentpermontly[t];
            for(t=0;t<=ca[i].mret;t++)
                days2+=carrentpermontly[t];
            for(t=0;t<=c.mr;t++)
                days3+=carrentpermontly[t];
            days1+=ca[i].dr;
            days2+=ca[i].dret;
            days3+=c.dr;
            if((days3-days1)*(days2-days3)>=0)
                f=1;
            else
            f=0;
               if(f==1)
               {
                 printf("Car not available.Are you interested in trying another car?\nIf yes enter Y else enter N\n");
                 getchar();
                 scanf("%c",&ch);
                 fclose(ptr);
                 if(ch=='y'||ch=='Y')
                    car_rent();
                 else
                 {
                     printf("THANKS FOR COMING!!PLEASE VISIT AGAIN \n\n\n");
                     fclose(ptr);
                     break;
                 }
               }
        }
        else if(strcmp(ca[i].carrented,c.carrented)!=0 ||f==0)
        {
            printf("CAR AVAILABLE!! \n");
            FILE *fp;
            fp=fopen("Car_rent","a");
            strcpy(ca[u].carrented,c.carrented);
            ca[u].dr=c.dr;
            ca[u].mr=c.mr;
            ca[u].yr=c.yr;
            ca[u].dret=c.dret;
            ca[u].mret=c.mret;
            ca[u].yret=c.yret;
            //u++;
            fwrite(&ca,sizeof(ca),1,fp);
            fclose(fp);
            printf("ENTER YOUR NAME: ");
            scanf("%s",c.customer_name);
            printf("ENTER YOUR ID NUMBER: ");
            scanf("%s",c.customer_ID);
            printf("ENTER PHONE NUMBER: ");
            scanf("%d",&c.customer_phno);
            printf("ENTER YOUR EMAIL ID: ");
            scanf("%s",c.customer_email);
            c.n=date(c.yr,c.yret,c.mr,c.mret,c.dr,c.dret);
            for(j=0;j<10;j++)
            {
                x=strcmp(c.carrented,carbrand[j]);
                if(x==0)
                    break;
            }
            c.rent=c.n*carrentperday[j];
            printf("WARNING: If any damage is done to the car then you are entirely responsible. The car has to be returned in its initial condition.\n");
            printf("Details:\n");
            printf("NAME:\t%s\nID:\t%s\nEMAIL:\t%s\nCAR RENTED:\t%s\nNUMBER OF DAYS:\t%d\nRENT:\t%d\n",c.customer_name,c.customer_ID,c.customer_email,c.carrented,c.n,c.rent);
            //fclose(ptr);
            strcpy(cr[z].customer_name,c.customer_name);
            strcpy(cr[z].customer_ID,c.customer_ID);
            strcpy(cr[z].carrented,c.carrented);
            cr[z].n=c.n;
            cr[z].rent=c.rent;
            //z++;
            FILE *fptr;
            fptr=fopen("Car_rent.txt","a+");
            fwrite(&cr,sizeof(cr),1,fptr);
            fclose(fptr);
            break;
        }
    }
}
int date(int y1,int y2,int m1,int m2,int d1,int d2)
{
    int i,days1=0,days2=0,days3=0 ;
        for(i=0;i<=m1;i++)
            days1+=carrentpermontly[i];
        for(i=0;i<=m2;i++)
            days2+=carrentpermontly[i];
        days1+=d1;
        days2+=d2;
        return(days2-days1);
}
void car_return()
{
    //FILE *fptr,*nptr;
    char id[13];
    int dd,mm,yy,d,m,y,flag=0,i,j;
    printf("Welcome back dear customer \n");
    printf("Please enter your id\n");
    scanf("%s",id);
    //fptr=fopen("Car_rent","r");
    //fread(cr,sizeof(struct car),1,fptr);
    for(i=0;i<10;i++)
    {
        if(strcmp(cr[i].customer_ID,id)==0)
        {
            flag=1;
            printf("HELLO %s\n",cr[i].customer_name);
            printf("For confirmation please enter the date on which you took the car and the date on which you are returning the date in(dd mm yyyy)format.\n");
            scanf("%d%d%d",&dd,&mm,&yy);
            scanf("%d%d%d",&d,&m,&y);
            cr[i].days=date(yy,y,mm,m,dd,d);
            if(cr[i].days>cr[i].n)
            {
                    cr[i].rent+=50*(cr[i].days-cr[i].n);
            }
            printf("NAME:\t%s\nID:\t%s\nEMAIL:\t%s\nCAR RENTED:\t%s\nNUMBER OF DAYS:\t%d\n",c.customer_name,c.customer_ID,c.customer_email,c.carrented,c.n);
            printf("FINAL AMOUNT:%d \n",cr[i].rent);
            printf("THANKYOU");

            break;
        }
    }
    if(flag==0)
           {
             printf("Customer not found\n");
            //fclose(fptr);
           }
        else
        {
            //nptr=fopen("Car_rent","w+");
            //fread(cr,sizeof(cr),1,nptr);
            for(j=0;j<10;j++)
            {
                if(j==i)
                    memset(&cr[j].carrented[0],0,sizeof(cr[j].carrented[0]));
            }
            //fclose(fptr);
            //remove("Car_rent");
            //rename("Car_temp","Car_rent");
           // fclose(nptr);
        }
}
void display()
{
    printf("#################################################################\n");
    printf("#    CAR BRAND   #  MODEL  # RENT PER DAY(Php) #  NO. OF SEATS  #\n");
    printf("#################################################################\n");
    printf("#     HYUNDAI    # Veloster #      950         #       4        #\n");
    printf("#     SUZUKI     #  Celerio #      850         #       4        #\n");
    printf("#      HONDA     #  Civic   #      450         #       4        #\n");
    printf("#     TOYOTA     #  Avalon  #      950         #       8        #\n");
    printf("#      FORD      # Explorer #      750         #       4        #\n");
    printf("#      TATA      #  Safari  #      550         #       4        #\n");
    printf("#    MERCEDES    #  E-Class #     1000         #       4        #\n");
    printf("#      AUDI      #  Q3      #      850         #       8        #\n");
    printf("#     ISUZU      #  D-MAX   #      750         #       8        #\n");
    printf("#################################################################\n");
}
int main()
{
    int q,p=0,g,h,ln,i=0;
    time_t t;
    time(&t);
	system("cls");

    for(g=1;g<=365;g++)
    {
        for(h=1;h<=10;h++)
        {
            printf("\nIS THERE A NEW CUSTOMER NOW??\nENTER 1 FOR YES AND 0 FOR NO\n");
            scanf("%d",&p);
            if(p==1)
            {
                label:
                printf("Press any number to login\n");
                scanf("%d",&ln);
                login();
                printf("\t\t|------------------------------------------------|\n");
	            printf("\t\t|                                                |\n");
	            printf("\t\t|       -----------------------------            |\n");
	            printf("\t\t|              CAR RENTAL SYSTEM                 |\n");
	            printf("\t\t|       -----------------------------            |\n");
	            printf("\t\t|                                                |\n");
	            printf("\t\t|                                                |\n");
	            printf("\t\t|                                                |\n");
	            printf("\t\t|------------------------------------------------|\n\n\n");
	            for(i=0;i<80;i++)
		        printf(">");
	            printf("\nCurrent date and time : %s",ctime(&t));
	            for(i=0;i<80;i++)
		        printf("<");
	            printf("\nHI!! ARE YOU HERE TO TAKE THE CAR SERVICE OR RETURN BACK THE CAR? \n 1.WANT TO RENT A CAR.\n 2.WANT TO RETURN THE CAR.\n");
                scanf("%d",&q);
                switch(q)
                {
                    case 1:{car_rent();u++;z++;
                    break;}
                    case 2:car_return();
                    break;
                    default:{printf("Wrong choice!! Try again.\n");
                    goto label;}
                }
            }
            else if(p==0)
            {
                 goto label;
            }
            else
            {
                return 0;
            }
        }

    }

}

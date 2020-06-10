#include<stdio.h>
#include<stdlib.h>

struct seatdata{
	int seatNum;
	char name[15];
	char surname[15];
	char gender[1];
};

//define structure
int enterChoice(void);
void textfile(FILE *seatsPtr);
void updateReservstion(FILE *fptr);
void newReservation(FILE *fptr);
void deleteReservation(FILE *fptr);
//functions prototype

int enterChoice(void)
{
	int a;
	printf("Enter your choice\n");
	printf("1 - store a formatted text file of seats reserved called seats.txt for printing\n");
	printf("2 - update a reservation\n");
	printf("3 - add a new reservation\n");
	printf("4 - delete a reservation\n");
	printf("5 - end program\n>>");
	//display menu
	scanf("%d",&a);
	//take a number from stdin
	return a;
//return number
}

void textfile(FILE *seatsPtr)
{
	struct seatdata a={0,"","",""};
	FILE *fptr;
	//define file pointer
	
	if((fptr=fopen("seats.dat","w"))==NULL)
	printf("File couldnt be open\n");
	//if file couldnt open

	else
	{//if file open
	
		rewind(seatsPtr);
		
		fprintf(fptr,"%-5s%-18s%-18s%-s\n","No","Name","Surname","Gender");
		//get the first of the file
		
		while(!feof(seatsPtr))
		{//wile not feof
			fread(&a,sizeof(struct seatdata),1,seatsPtr);
			//read datas from file
			
			if(a.seatNum!=0)
				fprintf(fptr,"%-5d%-18s%-18s%-s\n",a.seatNum,a.name,a.surname,a.gender);
				//if seat is not empty
		}

	//close file
	fclose(fptr);
	}
}

void updateReservstion(FILE *fptr)
{
	int seatnum;
	struct seatdata a={0,"","",""};
	
	printf("Enter seat number to update:");
	scanf("%d",&seatnum);
	//take seatnum from stdin

	fseek(fptr,(seatnum-1)*sizeof(struct seatdata),SEEK_SET);
	fread(&a,sizeof(struct seatdata),1,fptr);
	//seek the point seatnum and read data
	
	if(a.seatNum==0)
		printf("the seat is empty\n");

	else
	{
		a.seatNum=seatnum;
		printf("%d %s %s %s\n",a.seatNum,a.name,a.surname,a.gender);
		printf("Enter new name, surname, gender:");
		
		scanf("%s%s%s",a.name,a.surname,a.gender);
		//take data from stdin
		
		printf("%d %s %s %s\n",a.seatNum,a.name,a.surname,a.gender);
		
		fseek(fptr,(a.seatNum-1)*sizeof(struct seatdata),SEEK_SET);
		
		fwrite(&a,sizeof(struct seatdata),1,fptr);
		//seek the point seatnum and write to the file
	}
}

void newReservation(FILE *fptr)
{
	struct seatdata a={0,"","",""};
	int seatnum;

	printf("Enter new seat number to reserve: ");
	scanf("%d",&seatnum);
	//take setanum from stdin
	
	fseek(fptr,(seatnum-1)*sizeof(struct seatdata),SEEK_SET);
	fread(&a,sizeof(struct seatdata),1,fptr);
	//seek point andread data

	if(a.seatNum=0)
		printf("Seat have been already reserved\n");

	else
	{
		a.seatNum=seatnum;
		printf("Enter Name, Surname, Gender: ");
		scanf("%s%s%s",a.name,a.surname,a.gender);
		//take data from stdin
		
		fseek(fptr,(seatnum-1)*sizeof(struct seatdata),SEEK_SET);
		fwrite(&a,sizeof(struct seatdata),1,fptr);
	}
	//write to the file
}

void deleteReservation(FILE *fptr)
{
	int seatnum;
	struct seatdata b,a={0,"","",""};

	printf("Enter seat number to delete:");
	scanf("%d",&seatnum);
	
	fseek(fptr,(seatnum-1)*sizeof(struct seatdata),SEEK_SET);
	fread(&b,sizeof(struct seatdata),1,fptr);
	//read data from file
	
	if(b.seatNum==0)
		printf("seat is empty");
	
	else
	{
		fseek(fptr,(seatnum-1)*sizeof(struct seatdata),SEEK_SET);
		fwrite(&a,sizeof(struct seatdata),1,fptr);
    }
//write data from file
}

main()
{
	int a=1;
	FILE *fPtr;
	//define file ptr

	if((fPtr=fopen("bus.dat","rb+"))==NULL)
		printf("File couldnt open");
	//if file open

	else
	{
		while(a)
		{
			//while a is not zero
			a=enterChoice();
			//call the function and assign to a

		if(a==1)
			textfile(fPtr);
			//if a 1
		
		else if(a==2)
			updateReservstion(fPtr);
			//if a 2

		else if(a==3)
			newReservation(fPtr);
			//if a 3
		
		else if(a==4)
			deleteReservation(fPtr);
			//if a 4
		
		else if(a==5)
			exit(0);
			//if a 5
		
		else
			printf("Entered wrong number please try again\n");
		}
		//if a non of them

		fclose(fPtr);
	}
	//close file
}

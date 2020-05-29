#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
//include libraries


//definition of a new variable types 
//this are struct student and struct stats


struct student{		//Structure for the records in the file 
	char Name[30];  //name string 
	char Surname[30];  //surname string
	char address[50];   //address string
	unsigned long long No;   //student number 20xx502xxx
	unsigned int st_class;   //student class 1,2,3,4 
	unsigned int Section;    //sectionx {x=1,2,3,4,5,6}
	int grade; //grade 0-100
};
//definition of struct student

typedef struct student Students;
//changing name by typdef
//used Students instead of struct student


struct stats{		//Structure for number of students, maximum, minimum and average
    int no;			//number of students
	int max;		//maximum
	int min;		//minimum
	double avg;		//average
};
//definition of struct stats

typedef struct stats Statistics;
//changing name by typedef
//used Statistics instead of struct stats

int read_student_database(char *, Students []);
void count_students_in_sections(Students [], int, Statistics []);
double calculate_statistics(Students [], int, Statistics []);
void display_and_save_statistics(char *,Statistics [], int, double);
void sort_and_save_data(char *, Students [], int);
//function prototypes

//this functions read files name and assigns to student arr[]
//the informations returns the total element of the array after
//takes two arguments filename(string) and Student arr

int read_student_database(char *file_name, Students arr[])
{
	Students temp={"","","",0,0,0,0};
	//temp variable assign "" and 0 s
	
	int count=0;
	FILE *fptr;
	//file pointer
	
	
	if((fptr=fopen(file_name,"rb"))==NULL)
	    printf("The file could not open!\n");
	    //if file couldnt read in binary mode
	
	else
	{//if file could read in binary mode
	
		rewind(fptr);
	    //get the begingn of the file
		
		fread(&temp,sizeof(Students),1,fptr);
			//read from file copy to the tmep variable
			
		while(!feof(fptr))
		{//while the file line is empty
		//loops line of file
			arr[count]=temp;
			//assign temp to the array
			count++;
			//increment count
			
			fread(&temp,sizeof(Students),1,fptr);
			//read from file copy to the tmep variable
			
		}
		
		fclose(fptr);
		//close file
	}
	//end of the else
	
	return count;
	//return count 
}
//end of the function


//this functions is counting the sections in the Students array 
//it is counting the 
//returns void 

void count_students_in_sections(Students arr[], int num_of_arr, Statistics arr1[])
{
	int i;
	
	for(i=0;i<num_of_arr;i++)
	{//loops num_of_arr times
	
		switch(arr[i].Section)
		{//switch opearations 
		//take arr[i].section 
	
			case 1:
				//if arr[i].section is 1
				//it means the student is in the section 1
				arr1[0].no++;
				//so increment student number and break
				break;
	
			case 2:
				//if arr[i].section is 2
				//it means the student is in the section 2
				arr1[1].no++;
				//so increment student number and break
				break;
	
			case 3:
				//if arr[i].section is 3
				//it means the student is in the section 3
				arr1[2].no++;
				//so increment student number and break 
				break;
	
			case 4:
				//if arr[i].section is 4
				//it means the student is in the section 4
				arr1[3].no++;
				//so increment student number and break
				break;
	
			case 5:
				//if arr[i].section is 5
				//it means the student is in the section 5
				arr1[4].no++;
				//so increment student number and break
				break;
	
			case 6:
				//if arr[i].section is 6
				//it means the student is in the section 6
			    arr1[5].no++;
			    //so increment student number and break
			    break;
		}
		//end of the switch
	}
	//end of the for
}
//end of the function


//this function is calculating statistics its finding the max min avrg of 
//the each section and it this values is assigning to the arr1(statistic struct)
//return s the total average takes 3 argument Students arr
//takes 3 arguments students arr num_of_arr statistics arr1

double calculate_statistics(Students arr[], int num_of_arr, Statistics arr1[])
{
	//declarations assign (all elements)max1 to 0 min1 to 100
	int i,j,k,max1[6]={0,0,0,0,0,0},min1[6]={100,100,100,100,100,100},total_num_of_secs=0;
	long int sum_of_section_grade[6]={0,0,0,0,0,0},tsum=0;
    double avrg=0.0;
    //assign sum_of_section 0 (all elements)
    
  	for(i=0;i<num_of_arr;i++)
    {//for loop, loops num_of_arr
    
    	switch(arr[i].Section)
    	{//switch operation
    	//condition is arr[i].section
    	
    		case 1:
    			//if student is in the section 1
    			
    			if(max1[0]<arr[i].grade)
    			    max1[0]=arr[i].grade;
    			    //check the maximum grade
    			    //if it is bigger than max1
    			    //then assign max1 to the number
    			
				if(min1[0]>arr[i].grade)
    			    min1[0]=arr[i].grade;
    			//check the minumum grade
    			//if it is bigger than min1
    		    //then assign min1 to the number
				
				sum_of_section_grade[0]+=arr[i].grade;
    			//sum the total graddes in the section
    			//break
				break;
    			
    		case 2:
    			//if student is in the section 2
    			
				if(max1[1]<arr[i].grade)
    			    max1[1]=arr[i].grade;
    			//check the maximum note
    			//check then maximum grade
			    //if it is bigger than max1
    			//then assign max1 to the number
				
				if(min1[1]>arr[i].grade)
    			    min1[1]=arr[i].grade;
    			//check the minumum grade		
    		    //if it is bigger than min1
    		    //then assign min1 to the number
				
				sum_of_section_grade[1]+=arr[i].grade;
    			//sum the total grades in the section
    			//break
				break;
    		
			case 3:
				//if studetn in section 3
				
    			if(max1[2]<arr[i].grade)
    			    max1[2]=arr[i].grade;
    			//check the maximum grade
    		    //if it is bigger than max1
    			//then assign max1 to the number
				
				if(min1[2]>arr[i].grade)
    			    min1[2]=arr[i].grade;
    			//check the minumum grade
    		    //if it is bigger than min1
    		    //then assign min1 to the number
				
				sum_of_section_grade[2]+=arr[i].grade;
    			//sum the total grades in the section
    			//break
				break;
    		
			case 4:
				//if student in section 4
				
    			if(max1[3]<arr[i].grade)
    			    max1[3]=arr[i].grade;
    			//check the maximum grade
    		    //if it is bigger than max1
    		    //then assign max1 to the number
				
				if(min1[3]>arr[i].grade)
    			    min1[3]=arr[i].grade;
    			//check the minumum grade
    		    //if it is bigger than max1
    		    //then assign max1 to the number
				
				sum_of_section_grade[3]+=arr[i].grade;
				//sum the total grades in the section
				//break
    			break;
    		
			case 5:
				//if student in section 5
				
    			if(max1[4]<arr[i].grade)
    			    max1[4]=arr[i].grade;
    			//check the maximum grade
    		    //if it is bigger than max1
    		    //then assign max1 to the number
				
				if(min1[4]>arr[i].grade)
    			    min1[4]=arr[i].grade;
    			//check the minumum grade
    		    //if it is bigger than min1
    		    //then assign min1 to the number    
    			
				sum_of_section_grade[4]+=arr[i].grade;
				//sum the total grades in the section
				//break
				break;
    		
			case 6:
				//if student in section 6
				
    			if(max1[5]<arr[i].grade)
    			    max1[5]=arr[i].grade;
    			//check the maximum grade
    		    //if it is bigger than max1
    		    //then assign max1 to the number
				   
    			if(min1[5]>arr[i].grade)
    			    min1[5]=arr[i].grade;
				//check the minumum grade
    		    //if it is bigger than min1
    		    //then assign min1 to the number
    		    
    			sum_of_section_grade[5]+=arr[i].grade;
				//sum the total grades in the section
				//break
				break;	
		}
		//end of the switch
	}
	//end of the for
	
	for(j=0;j<6;j++)
	{
	//for loop loops 6 time due to 6 section
	
        arr1[j].avg=(double)sum_of_section_grade[j]/(double)arr1[j].no;    
        //assign arr1[j].avg (avg of jth section) 
		//total grades/number of the section
		
		arr1[j].max=max1[j];
		arr1[j].min=min1[j];
		//assign max and min statistics to max min
		//grdades to the section
		
		tsum+=sum_of_section_grade[j];
		//get the total sum of the grades
		total_num_of_secs+=arr1[j].no;
		//calculate the total of the students number
	}
	//end of the for 
	
    return (double)tsum/(total_num_of_secs);
    //return all grades/total_num_of_secs 
    //cast to double becaue of the reel division
}
//end of the function

//this functions jobs is displaying the statistics populTION of the sections max min grades 
//and grades averages of the sections and total statistics about in the course returns void
//takes 4 arguments file name ,statistics arr1 and num of studetnts in the course 
//and grafes average of the course

void display_and_save_statistics(char *file_name,Statistics arr1[], int num_of_stu, double avrg)
{
	//file pointer
	FILE *fptr;
	//declarations assigning 0
	int i,max1=0,min1=100,sumofstu=0;
	
	if((fptr=fopen(file_name,"w"))==NULL)
	    printf("file could not open!\n");
	    //if file couldnt open 
	    //sequential file access
	    
	else
	{
		//if file open
		
		for(i=0;i<6;i++)
		{//loops 6 time due to the 6 section
		    
		    printf("%-s%-d : %-s%-d\t %-s%-d\t %-s%-d\t %-s%.2lf\n","Section ",i+1,"Number of students= ",arr1[i].no,"Maximum= ",arr1[i].max,"Minimum= ",arr1[i].min,"Average= ",arr1[i].avg);
			//display statistics of the ith section
			
			
		    fprintf(fptr,"%-s%-d : %-s%-d\t %-s%-d\t %-s%-d\t %-s%.2lf\n","Section ",i+1,"Number of students= ",arr1[i].no,"Maximum= ",arr1[i].max,"Minimum= ",arr1[i].min,"Average= ",arr1[i].avg);
			//write to the file the statisticcs of the sections
			
			if(max1<arr1[i].max)
			    max1=arr1[i].max;
			    //find the maximum grade in the course
			
			if(min1>arr1[i].min)
			    min1=arr1[i].min;
			    //find the minumum grade in the course
		}
		//end of thefor
		
	    printf("\n%-s%-d\t%-s%-d\t %-s%-d \t%s%.2lf\n","All students taking the course : Number of students= ",num_of_stu,"Maximum grade= ",max1,"Minimum grade= ",min1,"Average grade= ",avrg);
		//display couse statistics
		
		fprintf(fptr,"\n%-s%-d\t%-s%-d\t %-s%-d\t %s%.2lf\n","All students taking the course : Number of students= ",num_of_stu,"Maximum grade= ",max1,"Minimum grade= ",min1,"Average grade= ",avrg);
		//write the statiscis to the file.
		
		fclose(fptr);
		//close file
	    
	    printf("\nFile name %s is succesfuly created.\n",file_name);
	}
	//end of the else
}
//end of the function

//this function is crating a file to save students records to respect ot hte their grades
//returns void
//takes 3 arguments filename students arr and number of students

void sort_and_save_data(char *file_name, Students arr[], int num_of_stu)
{
	//file pointer
	FILE *fptr;
	int i,j,temp,k,l;
	//declarations
	
	//buble sort algorithm
	for(i=0;i<num_of_stu-1;i++)
	{//for loop
		for(j=0;j<num_of_stu-i-1;j++)
		{//for loop
			if(arr[j].grade<arr[j+1].grade)
			{
			//if j th term is smaller than j+1th term
			    //swap operation
				temp=arr[j].grade;
				//hold arr[j].grade in temp
				arr[j].grade=arr[j+1].grade;
				//change arr[j]
				arr[j+1].grade=temp;
				//change arr[j+1]
			}
			//end of if
		}
		//end of for
	}
	//end of for
	
	
	if((fptr=fopen(file_name,"w"))==NULL)
	    printf("File could not open!\n");
	//if file couldnt open
	//sequential file access    
	
	else
	{//if file open
		
		for(k=0;k<num_of_stu;k++)
		{
		//for loop loop number of students time
				if(arr[k].grade>=90)
				    fprintf(fptr,"%-3d %-20s %-20s %-20s %-12lli %-2d %-2d %-6s%-d \t%s%s\n",k+1,arr[k].Name,arr[k].Surname,arr[k].address,arr[k].No,arr[k].st_class,arr[k].Section,"Grade:",arr[k].grade,"Letter Grade:","AA");
			    //if grade is AA THAT means grade>=90 write file the informations
			    
				else if(arr[k].grade<90 && arr[k].grade>=85)
			        fprintf(fptr,"%-3d %-20s %-20s %-20s %-12lli %-2d %-2d %-6s%-d \t%s%s\n",k+1,arr[k].Name,arr[k].Surname,arr[k].address,arr[k].No,arr[k].st_class,arr[k].Section,"Grade:",arr[k].grade,"Letter Grade:","BA");
			    //if grade is BA THAT means 90>grade>=85 write file informations
			    
			    else if(arr[k].grade<85 && arr[k].grade>=80)
			        fprintf(fptr,"%-3d %-20s %-20s %-20s %-12lli %-2d %-2d %-6s%-d \t%s%s\n",k+1,arr[k].Name,arr[k].Surname,arr[k].address,arr[k].No,arr[k].st_class,arr[k].Section,"Grade:",arr[k].grade,"Letter Grade:","BB");  
				//if grade is BB THAT means 85>grade>=80 write file informations
			    
				else if(arr[k].grade<80 && arr[k].grade>=75)
			        fprintf(fptr,"%-3d %-20s %-20s %-20s %-12lli %-2d %-2d %-6s%-d \t%s%s\n",k+1,arr[k].Name,arr[k].Surname,arr[k].address,arr[k].No,arr[k].st_class,arr[k].Section,"Grade:",arr[k].grade,"Letter Grade:","CB");
			    //if grade is 	CB THAT means 85>grade>=80 write file informations
			    
			    else if(arr[k].grade<75 && arr[k].grade>=70)
			        fprintf(fptr,"%-3d %-20s %-20s %-20s %-12lli %-2d %-2d %-6s%-d \t%s%s\n",k+1,arr[k].Name,arr[k].Surname,arr[k].address,arr[k].No,arr[k].st_class,arr[k].Section,"Grade:",arr[k].grade,"Letter Grade:","CC");
			    //if grade is CC THAT means 75>grade>=70 write file informations
			    
			    else if(arr[k].grade<70 && arr[k].grade>=65)
			        fprintf(fptr,"%-3d %-20s %-20s %-20s %-12lli %-2d %-2d %-6s%-d \t%s%s\n",k+1,arr[k].Name,arr[k].Surname,arr[k].address,arr[k].No,arr[k].st_class,arr[k].Section,"Grade:",arr[k].grade,"Letter Grade:","DC");
			    //if grade is DC THAT means 70>grade>=65 write file informations
				    
			    else if(arr[k].grade<65 && arr[k].grade>=60)
			        fprintf(fptr,"%-3d %-20s %-20s %-20s %-12lli %-2d %-2d %-6s%-d \t%s%s\n",k+1,arr[k].Name,arr[k].Surname,arr[k].address,arr[k].No,arr[k].st_class,arr[k].Section,"Grade:",arr[k].grade,"Letter Grade:","DD");
			    //if grade is DD THAT means 65>grade>=60 write file informations
				    
			    else if(arr[k].grade<60 && arr[k].grade>=50)
			        fprintf(fptr,"%-3d %-20s %-20s %-20s %-12lli %-2d %-2d %-6s%-d \t%s%s\n",k+1,arr[k].Name,arr[k].Surname,arr[k].address,arr[k].No,arr[k].st_class,arr[k].Section,"Grade:",arr[k].grade,"Letter Grade:","FD");
			    //if grade is FD THAT means 60>grade>=50 write file informations
				    
			    else
			        fprintf(fptr,"%-3d %-20s %-20s %-20s %-12lli %-2d %-2d %-6s%-d \t%s%s\n",k+1,arr[k].Name,arr[k].Surname,arr[k].address,arr[k].No,arr[k].st_class,arr[k].Section,"Grade:",arr[k].grade,"Letter Grade:","FF");
			    //if grade is FF THAT means 50>grade write file informations    
		}
		//end for       
		
		fclose(fptr);
		//close file
		
		printf("\nFile name %s is succesfuly creted\n",file_name);
	}
	//end else
}
//end function

int main()
{
	//DECLARATIONS of necessary variables
	Students arr[200]={"","","",0,0,0,0};
	//assign arr 0 and "" 200 elements will be enuogh 
	Statistics arr1[6]={0,0,0,0.0};
	//statistics need 6 elements due to the 6 section
	//assign 0 0 0 0.0
	char name[20]="",bin[20]=".bin",txt1[20]="_STATISTICS.txt",txt2[20]="_SORTED.txt",file_name[30]="";
	int stu_num=0;
	double average=0.0;
	
	printf("Enter your name_surname (in capital letters):");
	scanf("%s",name);
	//take string form stdin
	
	strcpy(file_name,name);
	//copy the name to file_name
	strcat(file_name,bin);
	//add bin to the end of the filename
	file_name[strlen(file_name)]='\0';
	//add null end of the file_name
	
	stu_num=read_student_database(file_name,arr);
	//call function read_student_database and assign the total student number to stu_num
	
	count_students_in_sections(arr,200,arr1);
	//call function count_students_in_sections 
	
	printf("There are %d students takeing EED1010 course\n",stu_num);
	//display the total students in the course 
	
	average=calculate_statistics(arr,200,arr1);
	//call function calculate statistics assign to the average grade to average
	
	file_name[0]=NULL;
	//assign file_name NULL make it empty
	strcpy(file_name,name);
	//copy the name to the file_name
	strcat(file_name,txt1);
	//concentrate two string
	file_name[strlen(file_name)]='\0';
	//dont forget add NULL due strcat function
	
	display_and_save_statistics(file_name,arr1,stu_num,average);
	//call function display_and_save_statistics
	
	file_name[0]=NULL;
	//assign file_name NULL make it empty
	strcpy(file_name,name);
	//copy name to file_name
	strcat(file_name,txt2);
	//conctrate two strings
	file_name[strlen(file_name)]='\0';
	//dont forget assign NULL due to the strcat
	
	sort_and_save_data(file_name,arr,stu_num);
	//call function sort_and_save_data
	
	return 0;
	//terminates program succesfully
}

//============================================================//
// I CLAIM THAT I HAVE WRITTEN ALL PARTS OF THE FINAL PROJECT //
// CODE MYSELF. THE TEXT FILES ARE ALSO PRODUCED BY ME.       // 	
// 2018502036 Enes Erten section 1 in theory, 4 in Lab        //
//============================================================//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// including libraries

struct student{		
// Structure for the records in the file
	char Name[30]; // student name
	char Surname[30]; // student surname
	char address[50]; // student address
	unsigned long long No;  // student number
	unsigned int st_class; // student class
	unsigned int Section; // student section 
	int grade;  // student grade
};
// end of the struct

typedef struct student Students;
// changing name by typedef

struct treeNode {
	// creating a tree data 
   struct treeNode *leftPtr;  // pointer to left subtree
   struct student data;       //data is struct student type
   struct treeNode *rightPtr; // pointer to right subtree
}; 
// end struct TreeNode

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;
// changing names by typedef

void read_student_database(char *, TreeNodePtr []);
void insertNode( TreeNodePtr *, Students );
int count_leaf_nodes( TreeNodePtr );
double sum_of_grades_in_leaf_nodes( TreeNodePtr );
int find_min_of_grades_in_tree( TreeNodePtr );
int find_max_of_grades_in_tree( TreeNodePtr );
void display_and_save_statistics(char *,TreeNodePtr []);
void inOrder(TreeNodePtr , FILE *);
void save_ordered_sections(char *,TreeNodePtr []);
// functions prototypes

// function definition
void read_student_database(char *file_name, TreeNodePtr arr[6])
{
	Students temp={"","","",0,0,0,0};
	FILE *fptr;
	// defining variables
	
	if((fptr=fopen(file_name, "rb")) == NULL)
		printf("ERROR!\nThe file could not read!");
	// if (Random acces file) file could not read 
		
	
	else
	{
		// if file could read
		
		rewind(fptr);
		// get in the begining of the file 
		
		fread(&temp,sizeof(Students),1,fptr);
		// read from file assign to the temp
		
		while(!feof(fptr))
		{	// read to the end of file
			
			if(temp.Section == 1)
				insertNode(&arr[0],temp);
			// if temp.Section is 1 
			// insert the record to the 1st section tree
				
			else if(temp.Section == 2)
				insertNode(&arr[1],temp);
			// if temp.Section is 12
			// insert the record to the 2nd section tree
			
			else if(temp.Section == 3)
				insertNode(&arr[2],temp);
			// if temp.Section is 3
			// insert the record to the 3rd section tree
				
				
			else if(temp.Section == 4)
				insertNode(&arr[3],temp);
			// if temp.Section is 4
			// insert the record to the 4th section tree
				
				
			else if(temp.Section == 5)
				insertNode(&arr[4],temp);
			// if temp.Section is 5
			// insert the record to the 5th section tree
			
				
			else if(temp.Section == 6)
				insertNode(&arr[5],temp);
			// if temp.Section is 16
			// insert the record to the 6th section tree
				
			else
				printf("Invalid process!\n sections are 1, 2, 3, 4, 5, and 6 is valid.\n");
			// if temp.Section is not 1,2,3,4,5,6 displays errors message
					
			fread(&temp,sizeof(Students),1,fptr);
			// read from file assign to the temp
		}
		// end of the while
		
		fclose(fptr);
		// close file
	}
	// end of else
}
// end of the function

// function definition
void insertNode( TreeNodePtr *tree_ptr, Students stu )
{
	if((*tree_ptr) == NULL)
	{
		// if tree node is empty
		
		(*tree_ptr) = (TreeNode *)malloc(sizeof(TreeNode));		
		// allocate memory
		
		if(*tree_ptr != NULL)
		{
			// if memory allocated
			
			(*tree_ptr)->data = stu;
			// assign student record to the tree node
			
			(*tree_ptr)->leftPtr = NULL;
			(*tree_ptr)->rightPtr = NULL;
			// assign NULL the left and right to the trees
		}
		//end of the if
	}
	// end of the if

	else
	{
		// if tree node is not empty
		
		if(stu.No > ((*tree_ptr)->data).No)		
		{
			// student number is bigger than tree->data.no 
			
			insertNode(&((*tree_ptr)->rightPtr),stu);	
			// call recuirsevly call in the right side of the tree
 	    }
 	    // end of the if
 	    
		else if(stu.No < ((*tree_ptr)->data).No)
		{
			// student number is smaller than tree->data.no 

			insertNode(&((*tree_ptr)->leftPtr),stu);		
			// call recuirsevly call in the left side of the tree	
	    }
	    // end of the else if
	    
	}
	// end of the else
}
// end of the function 

// function definition
int count_leaf_nodes( TreeNodePtr tree_ptr )
{
	if( tree_ptr == NULL )		
    	return 0;
	// if the tree node is empty
	
	if(tree_ptr->leftPtr == NULL && tree_ptr->rightPtr == NULL)
    	return 1;
	// if left side and right side of the free is empty return 1
	// base case of the recursieve function     

	else
    	return count_leaf_nodes(tree_ptr->leftPtr) + count_leaf_nodes(tree_ptr->rightPtr);
    // if not call recursievly call 
    // send to the function again the sub part of the tree(rightPtr and leftPtr)
}
//	end of the function

// function definition
double sum_of_grades_in_leaf_nodes( TreeNodePtr tree_ptr )
{
	if(tree_ptr == NULL)
		return 0.0;
		// if tree is empty return 0.0

    else if(tree_ptr->leftPtr == NULL && tree_ptr->rightPtr == NULL)  	
    	return (tree_ptr->data).grade;		
    	// if tree rightPtr and leftPtr is NULL 
    	// return the grade

    else
    	return (double)(sum_of_grades_in_leaf_nodes(tree_ptr->leftPtr) + sum_of_grades_in_leaf_nodes(tree_ptr->rightPtr));
    	
    // recursievly call it is sending the function the subtrees(left and right sides)
}
// end of the function

// function definition
int find_min_of_grades_in_tree( TreeNodePtr tree_ptr )
{
	int min = 0,r_min = 0, l_min = 0;
	// defining variable and initializing
	
	if(tree_ptr == NULL)
	{
		// if the tree_ptr is NULL
		printf("The Tree -> NULL\n");
		// display tree_node is NULL
		return 0;
		// return 0 
	}
	// end of the if
	
	else
	{
		// if tree_ptr is diffrent from NULL
		
		min = (tree_ptr->data).grade;
		// assign min the head of the tree
		
		if(tree_ptr->rightPtr != NULL)
		{
			// if (rigjt side) tree_ptr is diffrent from NULL
			
			r_min = find_min_of_grades_in_tree(tree_ptr->rightPtr);
			// recursievly call finding the minimum number 
			// in the right side 
						
			if(min > r_min)
				min = r_min;
			// if min > r_min assign min r_min because 
			// r_min is the smallest value in the tree
		}
		// end of the if
		
		if(tree_ptr->leftPtr != NULL)
		{
		// if left side of the tree is diffrent from NULL
			
			l_min = find_min_of_grades_in_tree(tree_ptr->leftPtr);
			// recursievly call look the left side of tree
				
			if(min > l_min)
				min = l_min;
				// compare min and l_min 
				// which one is small then assign to min
		}
		// end of the if
		
		return min;
		// return min
	}
	// end of the else	
}
// end of the function

// function definition
int find_max_of_grades_in_tree( TreeNodePtr tree_ptr )
{
	int l_max = 0, r_max = 0 , max = 0;
	// defining varaibles and initializings
	
	if(tree_ptr == NULL)
	{
		// if tree_ptr is NULL
		
		printf("The Tree -> NULL\n");
		// display error mesage
		
		return 0;
		// return 0 
	}
	// end of if
	
	else
	{
		// if tree_ptr is diffrent from NULL
		
		max = (tree_ptr->data).grade;
		// assign max the top of the tree
		
		if(tree_ptr->rightPtr != NULL)
		{
			// if the right sidde of the tree is exist
			
			r_max = find_max_of_grades_in_tree(tree_ptr->rightPtr);
			// recursievly call call the function for the right side of the tree
			
			if(max < r_max)
				max = r_max;
				// comparing max and r_max deu to the 
				// getting the maximum value
		}
		// end of the if
		
		if(tree_ptr->leftPtr != NULL)
		{
			// if left side of the tree is exist 
			
			l_max = find_max_of_grades_in_tree(tree_ptr->leftPtr);
			// recursievly call for the left side of the tree
			
			if(max < l_max)
				max = l_max;
				// comparing max and l_max 
				// due to the get the maximum value in the tree
		}
		// end of the if
		
		return max;
		// return the max which is the maximum value in the 
	}
	// end of the else
}
// end of the function

// function definition
void display_and_save_statistics(char *file_name,TreeNodePtr arr[6])
{
	int i = 0, j = 0;
	FILE *fptr;
	// declaring variables and FILE pointer which is *fptr
		
	for(;i<6;i++)
		printf("Section %d : Number of leaf nodes= %d\t Average grade of leaf nodes= %.2lf\t Maximum grade= %d\t Minimum grade= %-2d\n",i+1,count_leaf_nodes(arr[i]),sum_of_grades_in_leaf_nodes(arr[i])/count_leaf_nodes(arr[i]),find_max_of_grades_in_tree(arr[i]),find_min_of_grades_in_tree(arr[i]));
	// loops six times display statistics of sections 
	// section num, num of leaf, averafe grade, max and min grades 
	// for each section

	if((fptr=fopen(file_name,"w")) == NULL)
		printf("ERROR!\nThe file %s is not created!",file_name);
		// if the (sequential file acces) file could not read 
		// displays ERROR message

	for(;j<6;j++)		
		fprintf(fptr,"Section %d : Number of leaf nodes= %-2d\t Average grade of leaf nodes= %.2lf\t Maximum grade= %d\t Minimum grade= %-3d\n",j+1,count_leaf_nodes(arr[j]),sum_of_grades_in_leaf_nodes(arr[j])/count_leaf_nodes(arr[j]),find_max_of_grades_in_tree(arr[j]),find_min_of_grades_in_tree(arr[j]));
	// loop  six times  writes statistics of the sections the file
	// section num, num of leaf, averafe grade, max and min grades 
	// for each section
	
	fclose(fptr);
	// close file
	printf("\nFile name %s is successfully created.\n",file_name);
}
// end of the function

// function definition
void inOrder(TreeNodePtr tree_ptr, FILE *fptr)
{
	if (tree_ptr == NULL)
		return;
		// if tree_ptr is NULL tree is empty
		// return nothing

	inOrder(tree_ptr->leftPtr,fptr);		
	// recursievly call 
	// send the left  part of the tree

	fprintf(fptr,"%-11llu%-21s%-21s%-21s%-3u%-3u%-6s%-d\n",tree_ptr->data.No,tree_ptr->data.Name,tree_ptr->data.Surname,tree_ptr->data.address,tree_ptr->data.st_class,tree_ptr->data.Section,"GRADE:",tree_ptr->data.grade);	
	// write to the file the student records respect to the their student number and sections
	
    inOrder(tree_ptr->rightPtr,fptr);		
    // recursievly call 
	// send the right part of the tree 
}
// end of the function

// function definition 
void save_ordered_sections(char *file_name,TreeNodePtr arr[6])
{
	int i=0;
	FILE *fptr;
	// declaration of the variables and initializing

	if((fptr = fopen(file_name,"w")) == NULL)
		printf("ERROR!\nThe file %s could not created!\n",file_name);
	// if (sequnetial file access) file could not created
	
	
	for(;i<6;i++)
		inOrder(arr[i],fptr);
		// loop 6 times send the sections(tree) to the inOrder function

	fclose(fptr);
	// close file
	
	printf("\nFile name %s is successfully created.\n",file_name);
}
// end of the function

int main()
{
	TreeNodePtr arr[6]={NULL};
	// declaring an array which elements are a binary tree
	char name[20]="",bin[20]=".bin",txt1[20]="_STATISTICS.txt",txt2[20]="_SORTED.txt",file_name[40]="";
	// defining and initializing char arrays
	printf("Enter your NAME_SURNAME (in capital letters):");
	scanf("%s",name);
	
	strcpy(file_name,name);
	// copy the name to file_name
	strcat(file_name,bin);
	// add bin to the end of the filename
	file_name[strlen(file_name)]='\0';
	// add null end of the file_name
	
	read_student_database(file_name, arr);
	// call function
	file_name[0]='\0';
	// assign file_name NULL make it empty
	strcpy(file_name,name);
	// copy the name to the file_name
	strcat(file_name,txt1);
	// concentrate two string
	file_name[strlen(file_name)]='\0';
	// dont forget add NULL due strcat function
	
	display_and_save_statistics(file_name, arr);
	// call function
	file_name[0]='\0';
	// assign file_name NULL make it empty
	strcpy(file_name,name);
	// copy name to file_name
	strcat(file_name,txt2);
	// conctrate two strings
	file_name[strlen(file_name)]='\0';
	// dont forget assign NULL due to the strcat
	
	save_ordered_sections(file_name, arr);

	return 0;
	// terminates program successfully
}


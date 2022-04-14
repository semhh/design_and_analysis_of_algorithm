#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define MAX_SIZE 100

//MERGE SORT

// Merge Function
void merge(int arr[], int left, int medium, int right){
	
	int first_part = medium - left + 1;
	int second_part = right - medium;
	int Left[first_part]; 
	int Right[second_part];
	int i, j;
	
	for (i = 0; i < first_part; i++)
		Left[i] = arr[left + i];
		i = 0;
		
	for (int j = 0; j < second_part; j++)
		Right[j] = arr[medium + 1+ j];
		j = 0;
		
	int k = left;
	
	while (i < first_part && j < second_part){
		if (Left[i] <= Right[j]){
			arr[k] = Left[i];
			i++;
		}
		else{
			arr[k] = Right[j];
			j++;
		}
		k++;
	}
	
	while (i < first_part){
		arr[k] = Left[i];
		i++;
		k++;
	}
	
	while (j < second_part){
		arr[k] = Right[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int left, int right){

	if (left < right){
		int medium = left+(right-left)/2;
		mergeSort(arr, left, medium);
		mergeSort(arr, medium+1, right);
		merge(arr, left, medium, right);
	}
}


//QUICK SORT

// Partition function
int partition(int arr[], int l, int h){ 

	int i = (l - 1); 
	int pvt = arr[h];
	for (int j = l; j <= h - 1; j++) { 
		if (arr[j] <= pvt) { 
		i++;  
		int temp = arr[i]; 
		arr[i] = arr[j]; 
		arr[j] = temp; 
		}	 
	}
	int temp = arr[i + 1]; 
	arr[i + 1] = arr[h]; 
	arr[h] = temp;
	 
return (i + 1);
 
}
   
// QuickSort Function
void quickSort(int arr[], int l, int h){ 
	
	if (l < h){ 
		int pvt = partition(arr, l, h);  
		quickSort(arr, l, pvt - 1); 
		quickSort(arr, pvt + 1, h);	 
	} 
}
  
 
// Function to print array
void printArray(int A[], int size){

	int i;
	for (i=0; i < size; i++)
	printf("%d ", A[i]);
	printf("\n");
	
}

//Function to copy an array to another array
copy(int *a, int *b, int n){
	int i;
    for(i=0; i<n; i++)
        b[i]=a[i];    
}

//Function to print menu
int print_menu(){
      
      	int choice;
	  	printf("MENU\n****\n1-Merge Sort\n2-Quick Sort\n3-Exit\n\n");
		printf("What is your choice: ");
		scanf("%d",&choice);
		printf("\n");

      	return choice;
    }


int main(){
	
		int arr_size=0, arr[MAX_SIZE];
		int flag = 1;
		
	    printf("Enter numbers you want to be sorted (Enter a non integral value to terminate input):\n");
	  	
	    while(flag){
			while(scanf("%d",&arr[arr_size])){
	        	arr_size++;
	        	if(isdigit(arr[arr_size])){
	        		flag=1;
				}
				else
					flag=0;	
	    		}	
	    }
			
		getchar();
		printf("Given array is: \n");
		for(int i =0; i<arr_size;i++)
	    printf("%d ",arr[i]);
	    printf("\n");
	 	printf("The number of inputs are: %d\n\n",arr_size);
		
		int arr1[MAX_SIZE], arr2[MAX_SIZE];
		int choice = print_menu();
		
		while(1){
			
			switch(choice){
			
			case '0':
				
				print_menu();
				break;
			
			case 1:
				
				printf("MERGE SORT\n");
				printf("**********\n");
				printf("Given array is: \n");
				printArray(arr, arr_size);
				copy(arr, arr1, arr_size);
				mergeSort(arr1, 0, arr_size - 1);
				printf("\nSorted array is: \n");
				printArray(arr1, arr_size);
				printf("\n\n");
				choice = print_menu();
				
				break;
				
			case 2:
				
				printf("QUICK SORT\n");
				printf("**********\n");
				printf("Given array is: \n");
				printArray(arr, arr_size);
				copy(arr, arr2, arr_size);
				quickSort(arr2, 0, arr_size-1); 
				printf("\nSorted array is: \n"); 
				printArray(arr2, arr_size);
				printf("\n\n");
				choice = print_menu();
					
				break;
			
			case 3:
				
				printf("Program has been terminated.");
				return 0;
		
				break;
				
			default:
			
				printf("Wrong choice!\nTry again.\n\n");
				choice = print_menu();
				
				break;			
			}	
		}
}

















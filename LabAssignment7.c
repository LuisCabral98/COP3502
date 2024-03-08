#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n, int *totalSwaps, int swapsPerVal[]){
	int i, j; 
	*totalSwaps = 0;
	for(i = 0; i < n - 1; i++){
		for(j = 0; j < n-i-1;j++){
			if(arr[j] > arr[j+1]){
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp; 
				(*totalSwaps)++;
				swapsPerVal[arr[j]]++;
				swapsPerVal[arr[j+1]]++; 
			}
		}
	}
}

void selectionSort(int arr[], int n, int *totalSwaps, int swapsPerVal[]){
	int i, j, minIndx;
	*totalSwaps = 0;
	for(i = 0; i < n - 1; i++){
		minIndx = i;
		for(j = i+1; j < n; j++){
			if(arr[j] < arr[minIndx]){
				minIndx = j;
			}
		}
		if(minIndx != i){
			int tmp = arr[minIndx];
			arr[i] = arr[minIndx];
			arr[minIndx] = tmp;
		        (*totalSwaps)++;
	       		swapsPerVal[arr[i]]++;
	 		swapsPerVal[arr[minIndx]]++;		
		}
	}
}

int main(){
	int arr1[] = {97,16,45,63,13,22,7,58,72};
	int arr2[] = {90,80,70,60,50,40,30,20,10};
	int n = sizeof(arr1) / sizeof(arr1[0]);
	int totalBubbleSwaps = 0, totalSelectionSwaps = 0; 
	int swapsPerValBubble[100]  = {0}, swapsPerValSelection[100] = {0};

	//bubble sort arr1
	bubbleSort(arr1, n, &totalBubbleSwaps, swapsPerValBubble);
	printf("Bubble Sort:\n");
	printf("Total Swaps: %d\n", totalBubbleSwaps);
	printf("Swaps Per Value:\n");
	for(int i = 0; i < n; i++){
		printf("%d: %d\n", arr1[i], swapsPerValBubble[arr1[i]]);
	}
	printf("\n");

	//selection sort for arr1
	selectionSort(arr1, n, &totalSelectionSwaps, swapsPerValSelection);
	printf("Selection Sort: \n");
	printf("Total Swaps: %d\n", totalSelectionSwaps);
	printf("Swaps per Value:\n");
	for(int i = 0; i < n; i++){
		printf("%d: %d\n", arr1[i], swapsPerValSelection[arr1[i]]);
	}
	printf("\n"); 

	//bubble sort for arr2
	bubbleSort(arr2, n, &totalBubbleSwaps, swapsPerValBubble);
	printf("Bubble Sort: \n");
	printf("Total Swaps: %d\n", totalBubbleSwaps);
	printf("Swaps per Value: \n");
	for(int i = 0; i < n; i++){
		printf("%d: %d\n", arr2[i], swapsPerValBubble[arr2[i]]); 
	}
	printf("\n");

	//selection sort for arr2
	selectionSort(arr2, n, &totalSelectionSwaps, swapsPerValSelection);
	printf("Selection Sort:\n");
	printf("Total Swaps: %d\n", totalSelectionSwaps);
	printf("Swaps per Value:\n");
	for(int i = 0; i < n; i++){
		printf("%d: %d\n", arr2[i], swapsPerValSelection[arr2[i]]);
	}
	printf("\n");

	return 0; 
}

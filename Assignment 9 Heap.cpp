/*
Aman Munjewar 
SIB18
*/
#include <iostream>

using namespace std;


void heapify(int arr[], int n, int i)
{
	int largest = i; 
	int left = 2 * i + 1; 
	int right = 2 * i + 2; 


	if (left < n && arr[left] > arr[largest])
		largest = left;

	
	if (right < n && arr[right] > arr[largest])
		largest = right;

	
	if (largest != i) {
		swap(arr[i], arr[largest]);

		
		heapify(arr, n, largest);
	}
}


void heapSort(int arr[], int n)
{
	
	for (int i = n/2-1; i >= 0; i--)
		heapify(arr, n, i);

	
	for (int j = n-1; j>=0; j--) {
		
		swap(arr[0], arr[j]);

		
		heapify(arr, j, 0);
	}
}





void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}


int main()
{
	int n;
	cout<<"Enter the number of elements:";
	cin>>n;
	
	int arr[100];
	cout<<"Enter elements:\n";
	for(int i=0;i<n;i++){
		
		cin>>arr[i];
	}
	
	

	heapSort(arr, n);

	cout << "Sorted array is :\n";
	printArray(arr, n);
}


/*OUTPUT

Enter the number of elements:4
Enter elements:
1
6
8
4
Sorted array is :
1 4 6 8 

*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Sort { //stands for Generic Stack
  public:
    Sort(); //constructor
    Sort(int listSize); //overloaded constructor
    ~Sort(); //destructor

    int * myList;
    int listLength;

    void generateList(int listLength);
    void bubbleSort(double myArray[], int listLength);
		void selectionSort(double arr[], int n);
		void insertSort(double arr[], int listLength);
    void mergeSort(double dArray[], int low, int high);
    void merge(double dArray[], int low, int high, int mid);
    void quickSort(double dArray[], int low, int high);
    int partition(double dArray[], int low, int high);
};

Sort::Sort() {

}

Sort::Sort(int listSize) {
  listLength = listSize;
}

Sort::~Sort() {
  delete myList;
}

void generateList(int listLength) {

}


void Sort::bubbleSort(double myArray[], int listLength) {
	for (int i = 0; i < listLength; i++) {
		int temp = 0;
		for (int j = i; j < listLength - 1; j++) {
			if (myArray[j] > myArray[j+1]) {
				temp = myArray[j+1];
				myArray[j+1] = myArray[j];
				myArray[j] = temp;
			}
		}
	}
}

void Sort::selectionSort(double arr[], int n) {
  int i, j, minIndex, tmp;
  for (i = 0; i < n - 1; i++) {
    minIndex = i;
    for (j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
			}
		  if (minIndex != i) {
			  tmp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = tmp;
      }
    }
  }
}

void Sort::insertSort(double arr[], int listLength) {
	for (int j = 1; j < listLength; j++) { // marker
		double temp = arr[j]; //store marked item
		int k = j; //where to start shifting
		while (k>0 && arr[k-1] >= temp) { //while the thing to the left is larger, shift
			arr[k] = arr[k-1];
			k--;
		}
		arr[k] = temp; //put marked item in right spot
	}
}

void Sort::mergeSort(double dArray[], int low, int high) {
  int mid;
  if(low < high)
  {
    mid = (low + high) / 2;

    mergeSort(dArray, low, mid);
    mergeSort(dArray, mid+1, high);

    merge(dArray, low, high, mid);
  }
}

void Sort::merge(double dArray[], int low, int high, int mid) {
  int i = low;
  int j = mid + 1;
  int k = low;
  double dTempArray[high-low+1];

  while(i <= mid && j <= high)
  {
    if(dArray[i] < dArray[j])
    {
      dTempArray[k] = dArray[i];
      k++;
      i++;
    }
    else
    {
      dTempArray[k] = dArray[j];
      k++;
      j++;
    }
  }

  while(i <= mid)
  {
    dTempArray[k] = dArray[i];
    k++;
    i++;
  }

  while(j <= high)
  {
    dTempArray[k] = dArray[j];
    k++;
    j++;
  }

  for(int i = low; i < k; i++)
  {
    dArray[i] = dTempArray[i];
  }
}

void Sort::quickSort(double dArray[], int low, int high) {
  if(low < high)
  {
    int pivot = partition(dArray, low, high);

    quickSort(dArray, low, pivot-1);
    quickSort(dArray, pivot+1, high);
  }
}

int Sort::partition(double dArray[], int low, int high)
{
  int pivot = dArray[high];
  int i = (low - 1);

  for(int j = low; j <= high; j++)
  {
    if(dArray[j] <= pivot)
    {
      i++;
      swap(dArray[i], dArray[j]);
    }
  }

  swap(dArray[i+1], dArray[high]);
  return (i+1);
}

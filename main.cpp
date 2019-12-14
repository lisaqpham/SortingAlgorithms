#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <chrono>
#include "Sort.h"

using namespace std;
using namespace std::chrono;

int main(int argc, char** argv){

  int num = 0;
  double data[num];
  double a;
  int size = 0;
  double bubbleData[num], selectData[num], insertData[num], mergeData[num], quickData[num];

  ifstream infile;
  infile.open(argv[1]);

  if(!infile){
    cout << "Invalid Argument. Please try again." << endl;
    exit(1);
  }

  infile >> num;
  cout << "Number of elements: " << num << endl << endl;

  while(infile>>a)
  {
      data[size++]=a;
  }

  for (int i = 0; i < size; i++) {
    bubbleData[i] = data[i];
    selectData[i] = data[i];
    insertData[i] = data[i];
    mergeData[i] = data[i];
    quickData[i] = data[i];

  }

  auto start1 = high_resolution_clock::now();
  Sort bSort;
  bSort.bubbleSort(bubbleData, num);
  auto stop1 = high_resolution_clock::now();
  auto duration1 = duration_cast<microseconds>(stop1-start1);

  cout <<"Bubble Sort Duration: "<< duration1.count()<<" microseconds" <<endl;
  cout <<"\tStart Time: 0 microseconds" <<endl;
  cout <<"\tEnd Time: "<< duration1.count() <<" microseconds" <<endl << endl;



  auto start2 = high_resolution_clock::now();
  Sort sSort;
  sSort.selectionSort(selectData, num);
  auto stop2 = high_resolution_clock::now();
  auto duration2 = duration_cast<microseconds>(stop2-start2);
  cout <<"Selection Sort Duration: "<< duration2.count()<<" microseconds" <<endl;
  cout <<"\tStart Time: 0 microseconds" <<endl;
  cout <<"\tEnd Time: "<< duration2.count() <<" microseconds" <<endl << endl;

  auto start3 = high_resolution_clock::now();
  Sort iSort;
  iSort.insertSort(insertData,num);
  auto stop3 = high_resolution_clock::now();
  auto duration3 = duration_cast<microseconds>(stop3-start3);
  cout <<"Insertion Sort Duration: "<< duration3.count()<<" microseconds" <<endl;
  cout <<"\tStart Time: 0 microseconds" <<endl;
  cout <<"\tEnd Time: "<< duration3.count() <<" microseconds" <<endl << endl;

  auto start5 = high_resolution_clock::now();
  Sort qSort;
  qSort.quickSort(quickData, 0, num);
  auto stop5 = high_resolution_clock::now();
  auto duration5 = duration_cast<microseconds>(stop5-start5);
  cout <<"Quick Sort Duration: "<< duration5.count()<<" microseconds" <<endl;
  cout <<"\tStart Time: 0 microseconds" <<endl;
  cout <<"\tEnd Time: "<< duration5.count() <<" microseconds" <<endl << endl;

  auto start4 = high_resolution_clock::now();
  Sort mSort;
  mSort.mergeSort(mergeData, 0, num);
  auto stop4 = high_resolution_clock::now();
  auto duration4 = duration_cast<microseconds>(stop4-start4);
  cout <<"Merge Sort Duration: "<< duration4.count()<<" microseconds" <<endl;
  cout <<"\tStart Time: 0 microseconds" <<endl;
  cout <<"\tEnd Time: "<< duration4.count() <<" microseconds" <<endl << endl;




  return 0;

}

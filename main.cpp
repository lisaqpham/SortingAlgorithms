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
  double bubbleData[num], selectData[num], insertData[num];

  ifstream infile;
  infile.open(argv[1]);

  if(!infile){
    cout << "Invalid Argument. Please try again." << endl;
    exit(1);
  }

  infile >> num;
  cout << "Number of elements: " << num << endl;

  while(infile>>a)
  {
      data[size++]=a;
  }

  auto start1 = high_resolution_clock::now();
  Sort bSort;
  bSort.bubbleSort(data, num);
  auto stop1 = high_resolution_clock::now();
  auto duration1 = duration_cast<microseconds>(stop1-start1);
  cout <<"Bubble Sort Duration: "<< duration1.count()<<" microseconds" <<endl;

  auto start2 = high_resolution_clock::now();
  Sort sSort;
  sSort.selectionSort(data, num);
  auto stop2 = high_resolution_clock::now();
  auto duration2 = duration_cast<microseconds>(stop2-start2);
  cout <<"Selection Sort Duration: "<< duration2.count()<<" microseconds" <<endl;

  auto start3 = high_resolution_clock::now();
  Sort iSort;
  iSort.insertSort(data,num);
  auto stop3 = high_resolution_clock::now();
  auto duration3 = duration_cast<microseconds>(stop3-start3);
  cout <<"Insertion Sort Duration: "<< duration3.count()<<" microseconds" <<endl;

  return 0;

}

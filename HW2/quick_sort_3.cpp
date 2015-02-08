#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;
 
int median(int* list, int k){
int num1=*list, num2=*(list +(k-1)/2), num3=*(list+k-1);
if (k>2){
	if(((num1 > num2) && (num1 < num3)) | ((num1 > num3) && (num1 < num2)))
		return 0;
	else if(((num2 > num1) && (num2 < num3)) | ((num2 > num3) && (num2 < num1)))
		return (k-1)/2;
	else
		return (k-1);
}
else
		return 0;
}

void quick_sort( int* list, int l, int r,long int* count){
	int k=r-l;
	if ( k > 1 ){
		int pos = median(list,k);
		int pivot = *(list + pos);
		int temp, j=1;
		*(list+pos)=*list;
		*list = pivot;
		for (int i=1; i<k; i++){
			if(*(list + i) < pivot){
				temp = *(list + j);
				*(list + j) = *(list + i);
				*(list + i) = temp;
				j++;
			}
			*(count) = *(count) + 1;
		}
		temp = *list;
		*list = *(list + j-1);
		*(list + j-1) = temp;
		quick_sort(list,0,j-1,count);
		quick_sort((list+j),0,k-j,count);
	}
}

int  main(){

int length=10000, list[10000];
ifstream read("QuickSort_main.txt");
//int length=1000, list[1000];
//ifstream read("1000.txt");

for(int i=0; i<length;i++)
	read >> list[i];

long int count=0;

quick_sort(list,0,length,&count);

//for(int i=0; i<length;i++)
//	cout << list[i] << "\n";
cout << count <<"\n";
}

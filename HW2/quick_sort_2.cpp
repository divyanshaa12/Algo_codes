#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;
 
void quick_sort( int* list, int l, int r,long int* count){
	int k=r-l;
	if ( k > 1 ){
		int pivot = *(list + k -1);
		int temp, j=1;
		*(list+k-1)=*list;
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
cout << count;
}

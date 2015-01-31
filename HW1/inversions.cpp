#include <iostream>
#include <cstdio>
#include <fstream>
#include <stdlib.h>
using namespace std;

void merge(int* list, int len1, int len2, long int* num_inv){
	int i=0,j=0,length=len1+len2;
	int tmp_list[length];
	int* p = tmp_list;

	for(int k=0; k<length; k++){
		if (((*(list+i) <= *(list+len1+j)) | (j==len2)) && !(i==len1)){
			*(p+k) = *(list+i);
			i++;
		}
		else if((*(list+i) > *(list+len1+j)) | (i==len1)){
			*(p+k) = *(list+len1+j);
			j++;
			*num_inv = *num_inv + (len1 -i);
		}
	}
	for(int k=0; k<length; k++){
		*(list+k) = *(tmp_list+k);
	}
}

void mergesort(int* list, int length, long int* num_inv){
	if (length > 1){
		int mid = length/2;
		mergesort(list,mid,num_inv);
		mergesort(list+mid,length-mid,num_inv);
		merge (list,mid,length-mid,num_inv);
	}
}

int main(){

int list[100000];
long int length=100000;
long int* num_inv = (long int *)malloc(sizeof(long int));
*(num_inv) = 0;

ifstream read("IntegerArray.txt");

for(int i=0;i<length;i++)
	read>>list[i];

mergesort(list,length,num_inv);

cout << *num_inv << "\n";
}

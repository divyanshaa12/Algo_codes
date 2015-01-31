#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;

void merge(int* list, int len1, int len2){
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
		}
	}
	for(int k=0; k<length; k++){
		*(list+k) = *(tmp_list+k);
	}
}

void mergesort(int* list, int length){
	if (length > 1){
		int mid = length/2;
		mergesort(list,mid);
		mergesort(list+mid,length-mid);
		merge (list,mid,length-mid);
	}
}

int main(){

int list[100000];
int length=100000;
ifstream read("IntegerArray.txt");

for(int i=0;i<length;i++){
	read>>list[i];
}

mergesort(list,length);

for(int i=0;i<length;i++)
	cout<<list[i]<<'\n';
}

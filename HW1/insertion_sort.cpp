#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;
 
int  main(){

int length=100000, list[100000];
ifstream read("IntegerArray.txt");
//int length=13, list[13];
//ifstream read("in.txt");

for(int i=0; i<length;i++)
	read >> list[i];

for(int i=1;i<length;i++){
	int key = list[i];
	int j=i-1;
	while((key < list[j])&&(j>=0)){
		list[j+1]=list[j];
		list[j]=key;
		j--;
	}
}
for(int i=0; i<length;i++)
	cout << list[i] << "\n";
}

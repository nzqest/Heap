#include<iostream>
#include<Windows.h>
#include<fstream>
#include<string>

using namespace std;

typedef int Typedate; 


typedef struct _Heap{
	int *arr;
	int size;
	int capcity;

}Heap;

void adjustDown(Heap &heap,int index);
bool buildheap(Heap &heap,int index);
//1、堆的初始化
void initheap(Heap &heap,Typedate *date,int size){
	if(!date)return ;

	//堆的赋值3
	heap.arr=date;

	heap.size=size;

	buildheap(heap,size);
	


}

//2、堆的重建
bool buildheap(Heap &heap,int index){
	if(index<1)return false;
	int i=index/2-1;
	for(i;i>=0;i--){
	adjustDown(heap,i);
		}

}

//3、节点的向下调整
void adjustDown(Heap &heap,int index){
	//if(index<1)return ;
	int temp =heap.arr[index];
	int parent = index;
	int child ;
		
	for(parent;2*parent+1<heap.size;parent=child){
		child = parent*2+1;
	
		
			if(child+1<heap.size&&heap.arr[child+1]>heap.arr[child]){
				child++;
			}
			if(heap.arr[child]>heap.arr[parent]){
				heap.arr[parent]=heap.arr[child];
				heap.arr[child]=temp;
				//parent = child;
			
			}else{break;}

			
			
			
		}
	
}
//4、排序
void orderHeap(Heap &heap){
	if(heap.size<1)return ;

	while(heap.size>0){
		int temp = heap.arr[heap.size-1];
		heap.arr[heap.size-1]=heap.arr[0];
		heap.arr[0]=temp;
		heap.size--;
		adjustDown(heap,0);
	}



	}
int main(void){

	int tmp;
	int value[100];
	int i=-1;
	string name;

	ifstream stream;
	stream.open("user.txt");
	if(!stream.is_open()){
		cout<<"fail open!"<<endl;
		exit(-1);
	}

	
	while(1){
	
		if(stream.eof())break;
		stream>>tmp;
		i++;
	
		value[i]=tmp;
	
	}
		
	stream.close();

	for(int k=0;k<=i;k++){
		cout<<value[k]<<"\t";

		if((1+k)%12==0){
		cout<<endl;
	
		}
	}
	

	Heap hp;
	//插入
	cout<<"i="<<i<<endl;
	initheap(hp,value,i+1);
	cout<<"-----------------------------排序前---------------------------------"<<endl;
	for(int k=0;k<=i;k++){
		cout<<value[k]<<"\t";

		if((1+k)%12==0){
		cout<<endl;
	
		}
	}
	cout<<"-----------------------------排序后---------------------------------"<<endl;
	orderHeap(hp);
	for(int k=0;k<=i;k++){
		cout<<value[k]<<"\t";

		if((1+k)%12==0){
		cout<<endl;
	
		}
	}
	
	cout<<endl;
	system("pause");
	return 0;
}
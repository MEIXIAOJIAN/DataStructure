#include "Order.h"

void main(){
	printf("start\n");
	OLine order;
	orderline orderP;

	int i=0;

	order.len=5;
	for(i=0;i<order.len;i++){
		order.data[i]=i;
	}

	//orderP=(struct orderLine*)malloc(sizeof(struct orderLine));/*结构体指针需要初始化*/  
	orderP=(orderLine*)malloc(sizeof(orderLine));/*结构体指针需要初始化*/  
	orderP->len=5;
	for(i=0;i<orderP->len;i++){
		orderP->data[i]=i;
	}

	for(i=0;i<ListLenth;i++){
		printf("%d  ",order.data[i]);
		printf("\n");
		printf("%d  ",orderP->data[i]);
	}
	printf("end\n");
}
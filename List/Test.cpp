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

	//orderP=(struct orderLine*)malloc(sizeof(struct orderLine));/*�ṹ��ָ����Ҫ��ʼ��*/  
	orderP=(orderLine*)malloc(sizeof(orderLine));/*�ṹ��ָ����Ҫ��ʼ��*/  
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
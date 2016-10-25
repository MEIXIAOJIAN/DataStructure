#include "Order.h"


void unionList(orderLine &La,orderLine Lb){//合并两个列表
	//int la_len=La.len;
	int lb_len=Lb.len;
	for(int i=0;i<lb_len;i++){
		La.data[La.len++]=Lb.data[i];
	}
}

void MergeList(orderLine La,orderLine Lb,orderLine &Lc){
	int la_len=0;
	int lb_len=0;
	int lc_len=0;
	while(la_len<La.len && lb_len<La.len){
		if(La.data[la_len]<=Lb.data[lb_len]){
			Lc.data[lc_len++]=La.data[la_len++];
		}else{
			Lc.data[lc_len++]=Lb.data[lb_len++];
		}
	}
	while(la_len<La.len){
		Lc.data[lc_len++]=La.data[la_len++];
	}
	while(lb_len<Lb.len){
		Lc.data[lc_len++]=Lb.data[lb_len++];
	}
	Lc.len=lc_len;
}


void main(){
	printf("start\n");
	OLine order;
	orderline orderP;

	int i=0;

	order.len=6;
	for(i=0;i<order.len;i++){
		order.data[i]=i;
	}

	//orderP=(struct orderLine*)malloc(sizeof(struct orderLine));/*结构体指针需要初始化*/  
	orderP=(orderLine*)malloc(sizeof(orderLine));/*结构体指针需要初始化*/  
	orderP->len=5;
	for(i=0;i<orderP->len;i++){
		orderP->data[i]=i;
	}
/*
	for(i=0;i<ListLenth;i++){
		printf("%d  ",order.data[i]);
		printf("\n");
		printf("%d  ",orderP->data[i]);
	}
*/
	OLine La=order;
	orderline Lb=orderP;//并没有重新创建对象，两个指针指向同一个地址，固所指向东西相同

	unionList(*Lb,La);//用指针传递，改变原先的值
	for(i=0;i<orderP->len;i++){
		printf("%d  ",Lb->data[i]);
	}
	printf("\n");

	unionList(La,*Lb);
	for(i=0;i<order.len;i++){
		printf("%d  ",La.data[i]);
	}

	printf("\n列表合并到新表\n");
	La=order;
	Lb=orderP;
	OLine Lc;
	MergeList(order,*orderP,Lc);
	for(i=0;i<Lc.len;i++){
		printf("%d  ",Lc.data[i]);
	}
	printf("end\n");
}

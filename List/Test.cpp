#include "Order.h"


void unionList(orderLine &La,orderLine Lb){//�ϲ������б�
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

	//orderP=(struct orderLine*)malloc(sizeof(struct orderLine));/*�ṹ��ָ����Ҫ��ʼ��*/  
	orderP=(orderLine*)malloc(sizeof(orderLine));/*�ṹ��ָ����Ҫ��ʼ��*/  
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
	orderline Lb=orderP;//��û�����´�����������ָ��ָ��ͬһ����ַ������ָ������ͬ

	unionList(*Lb,La);//��ָ�봫�ݣ��ı�ԭ�ȵ�ֵ
	for(i=0;i<orderP->len;i++){
		printf("%d  ",Lb->data[i]);
	}
	printf("\n");

	unionList(La,*Lb);
	for(i=0;i<order.len;i++){
		printf("%d  ",La.data[i]);
	}

	printf("\n�б�ϲ����±�\n");
	La=order;
	Lb=orderP;
	OLine Lc;
	MergeList(order,*orderP,Lc);
	for(i=0;i<Lc.len;i++){
		printf("%d  ",Lc.data[i]);
	}
	printf("end\n");
}

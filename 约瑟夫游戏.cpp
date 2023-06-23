//ʹ��ѭ���������Լɪ���������ɱ˳��

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next; 	
}node;

//����һ���� 1 �� n ��ѭ������ 
node *create(int n)
{
	node *p = NULL, *head;
	head = (node *)malloc(sizeof(node))	;
	p = head;   //p��ָ��ǰ����ָ�� 
	node *s;
	int i = 1;
	
	if ( 0 != n)
	{
		while( i <= n )
		{
			s = (node *)malloc(sizeof(node));
			s->data = i++;  // Ϊѭ�������ʼ�� 1 2 3 �� 
			p->next = s;
			p = s;
		}
		s->next  = head->next ; //β���ָ���һ����� 
	}
	
	free(head); //ȥ��ͷ��� 
	
	return s->next ;  //���ص�һ����� 
} 

int main()
{
	int N;   //������ N
	int K;   //ʣ������ K
	int M;   //������� M 
	
	//�������������int�� ���� 
	if( scanf("%d %d %d",&N,&K,&M) != 3 )  
	{
		printf("ERROR"); 
		exit(0);
	}

	//���������Ϊ1��ʣ������Ϊ0 ����� 
	if(N == 1 && M == 0) 
	{ 
		printf("%d",0);
		exit(0);
	}
	//���ʣ���������������� ���� 
	if(K > N)  
	{
		printf("ERROR"); 
		exit(0);
	}
	//���ʣ������С��0 ���� 
	if(M < 0)  
	{
		printf("ERROR"); 
		exit(0);
	}

	int count=0;  //������ 
	int i;	
	node *p = create(N);   //������һ��ѭ������ 
	node* q = p;    //���ʣ����ʱ�� 
	node *temp; //ɾ�����ʱ�� 
	
	while(p != p->next) // ��ѭ��������ʱ 
	{
		for ( i=1; i<M; i++)
		{
			p = p->next ;
		 } 
		 
		 //printf("%d->",p->next->data);
		 if( p->next == q)   //Ҫɾ��q��ָ����� 
		 	q = q->next; 
		 
		 temp = p->next; 		//ɾ���� M+1 ����� 
		 p->next = temp->next ;  
		 
		 free(temp);
		 
		 p = p->next ;
		 
		 count++;
		 
		 if( N-count == K) 
		 	break;
	} 
	
	//һ�ѱ������� ������治֪�� 
	for(i=1; i<K; i++)
	{
		printf("%d,",q->data) ;
		q = q->next;
	}
	printf("%d",q->data) ;

	return 0;
 } 

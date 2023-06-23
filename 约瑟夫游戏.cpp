//使用循环链表，输出约瑟夫问题的自杀顺序

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next; 	
}node;

//创建一个从 1 到 n 的循环链表 
node *create(int n)
{
	node *p = NULL, *head;
	head = (node *)malloc(sizeof(node))	;
	p = head;   //p是指向当前结点的指针 
	node *s;
	int i = 1;
	
	if ( 0 != n)
	{
		while( i <= n )
		{
			s = (node *)malloc(sizeof(node));
			s->data = i++;  // 为循环链表初始化 1 2 3 … 
			p->next = s;
			p = s;
		}
		s->next  = head->next ; //尾结点指向第一个结点 
	}
	
	free(head); //去掉头结点 
	
	return s->next ;  //返回第一个结点 
} 

int main()
{
	int N;   //总人数 N
	int K;   //剩余人数 K
	int M;   //间隔人数 M 
	
	//如果输入人数非int型 错误 
	if( scanf("%d %d %d",&N,&K,&M) != 3 )  
	{
		printf("ERROR"); 
		exit(0);
	}

	//如果总人数为1，剩余人数为0 空输出 
	if(N == 1 && M == 0) 
	{ 
		printf("%d",0);
		exit(0);
	}
	//如果剩余人数大于总人数 错误 
	if(K > N)  
	{
		printf("ERROR"); 
		exit(0);
	}
	//如果剩余人数小于0 错误 
	if(M < 0)  
	{
		printf("ERROR"); 
		exit(0);
	}

	int count=0;  //计数器 
	int i;	
	node *p = create(N);   //创建了一个循环链表 
	node* q = p;    //输出剩余结点时用 
	node *temp; //删除结点时用 
	
	while(p != p->next) // 当循环链表不空时 
	{
		for ( i=1; i<M; i++)
		{
			p = p->next ;
		 } 
		 
		 //printf("%d->",p->next->data);
		 if( p->next == q)   //要删除q所指结点了 
		 	q = q->next; 
		 
		 temp = p->next; 		//删除第 M+1 个结点 
		 p->next = temp->next ;  
		 
		 free(temp);
		 
		 p = p->next ;
		 
		 count++;
		 
		 if( N-count == K) 
		 	break;
	} 
	
	//一堆报错的情况 输出上面不知道 
	for(i=1; i<K; i++)
	{
		printf("%d,",q->data) ;
		q = q->next;
	}
	printf("%d",q->data) ;

	return 0;
 } 

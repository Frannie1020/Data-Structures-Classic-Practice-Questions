#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 100 

int n;
/*
*已知二叉树的先序和中序遍历，求后序遍历 
*/
char pos[MAX_SIZE];
int flag=0;

int locationInMid(char mid[],int ms,int me,char h)		//传入中序遍历数组，头指针，尾指针，查找值 返回查找值的位置 
{
	int i;
	for(i=ms;i<=me;++i)
	{
		if(mid[i]==h)
			return i;
	}
	return -1;
}

void postOrder(char pre[],int ps,int pe,char mid[],int ms,int me) //传入前序遍历，头指针，尾指针，传入中序遍历，头指针，尾指针 
//有待改进的地方，函数的参数可以简化，因为数组的地址是0号元素的地址，知道头结点在mid中的位置后，左右子树的个数即可得到 
{
	int hm=0,cl=0,cr=0;		//hm 前序数组的值在中序数组中的定位 cl为左子树结点数，cr为右子树结点数 
	
	pos[--n]=pre[ps];		//后序遍历数组尾元素 = 前序遍历数组头元素 
	//--n;
	hm = locationInMid(mid,ms,me,pre[ps]);
	
	if(hm==-1) //在中序数组中没找到 前序数组的元素 
	{
	//	printf("error\n");
		flag=-1; //判断输入有误 
		return ;
	}
	else
	{
		cl=hm-ms;
		cr=me-hm;
		
		if(cr>0)			//如果右子树有结点 ，以同样的方法，把每个根 
			postOrder(pre,ps+cl+1,pe,mid,hm+1,me); //输入前序遍历数组，右子树头结点地址，尾节点地址 右子树中序遍历数组，头结点，尾结点 
		
		if(cl>0)			//如果左子树有结点 ，  
			postOrder(pre,ps+1,ps+cl,mid,ms,hm-1); //输入前序遍历数组，左子树头结点地址，尾节点地址 左子树中序遍历数组，头结点，尾结点
	}
	return ;
}

int  main()
{
	char pre[MAX_SIZE];
	char mid[MAX_SIZE];
	int i,t;

//	printf("请输入前序遍历结果：\n"); 
	scanf("%s",pre);
	
//	printf("请输入中序遍历结果：\n"); 
	scanf("%s",mid); 
	
	n = strlen(pre);
	
	int p = strlen(mid);
	if( n!=p )
	{
		printf("error");
		return 0;
	}
	
	t = n;
	
	postOrder(pre,0,n-1,mid,0,n-1);   //后序排序 
	if(flag==-1)
	{
		printf("error\n");
		flag=0;
	}
	else
	{
		for(i=0;i<t;++i)
		printf("%c",pos[i]);
		printf("\n");
	}
	
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 100 

int n;
/*
*��֪������������������������������ 
*/
char pos[MAX_SIZE];
int flag=0;

int locationInMid(char mid[],int ms,int me,char h)		//��������������飬ͷָ�룬βָ�룬����ֵ ���ز���ֵ��λ�� 
{
	int i;
	for(i=ms;i<=me;++i)
	{
		if(mid[i]==h)
			return i;
	}
	return -1;
}

void postOrder(char pre[],int ps,int pe,char mid[],int ms,int me) //����ǰ�������ͷָ�룬βָ�룬�������������ͷָ�룬βָ�� 
//�д��Ľ��ĵط��������Ĳ������Լ򻯣���Ϊ����ĵ�ַ��0��Ԫ�صĵ�ַ��֪��ͷ�����mid�е�λ�ú����������ĸ������ɵõ� 
{
	int hm=0,cl=0,cr=0;		//hm ǰ�������ֵ�����������еĶ�λ clΪ�������������crΪ����������� 
	
	pos[--n]=pre[ps];		//�����������βԪ�� = ǰ���������ͷԪ�� 
	//--n;
	hm = locationInMid(mid,ms,me,pre[ps]);
	
	if(hm==-1) //������������û�ҵ� ǰ�������Ԫ�� 
	{
	//	printf("error\n");
		flag=-1; //�ж��������� 
		return ;
	}
	else
	{
		cl=hm-ms;
		cr=me-hm;
		
		if(cr>0)			//����������н�� ����ͬ���ķ�������ÿ���� 
			postOrder(pre,ps+cl+1,pe,mid,hm+1,me); //����ǰ��������飬������ͷ����ַ��β�ڵ��ַ ����������������飬ͷ��㣬β��� 
		
		if(cl>0)			//����������н�� ��  
			postOrder(pre,ps+1,ps+cl,mid,ms,hm-1); //����ǰ��������飬������ͷ����ַ��β�ڵ��ַ ����������������飬ͷ��㣬β���
	}
	return ;
}

int  main()
{
	char pre[MAX_SIZE];
	char mid[MAX_SIZE];
	int i,t;

//	printf("������ǰ����������\n"); 
	scanf("%s",pre);
	
//	printf("������������������\n"); 
	scanf("%s",mid); 
	
	n = strlen(pre);
	
	int p = strlen(mid);
	if( n!=p )
	{
		printf("error");
		return 0;
	}
	
	t = n;
	
	postOrder(pre,0,n-1,mid,0,n-1);   //�������� 
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
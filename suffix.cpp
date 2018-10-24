#include <stdio.h> 
#include <iostream.h> 
#include <stdlib.h>
#define stacksize 100 
#define queuesize 100 
 
/*  队列的相关操作*/
 typedef char datatype;
 typedef struct { 
	 char data[100];
	 int front,rear;
 }seqqueue;        //定义队列类型 
 
/* 定义栈  */ 
 typedef struct
 {
	 datatype data[100];
	 int top;
 }seqstack;        //定义栈的类型 
 
//初始化队列
 void InitQueue(seqqueue *q) 
 {               
	 q->front=0;            
	 q->rear=0; 
 } 
 
//判空队列 
 int QueueEmpty(seqqueue  *q)  
 {              
	 return (q->front==q->rear?1:0);
 } 
 
//入队列 
 void EnQueue(seqqueue *q,datatype x) 
 {  
	 if ((q->rear>99 ))   
		 cout<<"queue overflow"<<endl; 
	 else 
	 {               
		 q->data[q->rear]=x;             
		 q->rear++; 
	 } 
 } 
 //出队列
 datatype DeQueue(seqqueue  *q)
 {
	  return q->data[q->front++]; 
 } 
 
//初始化栈
 void InitStack(seqstack *s) 
 {           
	 s->top=0; 
 } 
 
//入栈
 void Push(seqstack *s,datatype x) 
 { 
	 if (    s->top>=100        )     
		 cout<<"stack overflow"<<endl; 
	 else  
	 {                 
		 s->data[s->top]=x;              
		 s->top++;    
	 }
 } 
 
//出栈
 datatype Pop(seqstack *s) 
 {   
	 return s->data[--s->top]; 
 } 
 
//取栈顶元素
 datatype GetTop(seqstack *s) 
 {   
	 if (  !s->top) 
		 cout<<"stack empty"<<endl; 
	 else                  
		 return s->data[s->top-1]; 
 } 
 
//求运算符优先级函数 
 int Priority(datatype op) 
 {    
	 switch(op)   
	 {      
	 case '(':   
	 case ')': 
	 case '#':
		 return  1;      
	 case '-':    
	 case '+': 
		 return  2;    
	 case '*':     
	 case '/':
		 return  3;   
	 } 
 } 
 
//中缀表达式转换为后缀表达式
 void IntoPostExp(seqqueue *q) 
 { 
	 seqstack os;   
	 //运算符栈 
	 char c,t; 
	 seqstack *s;     
	 s=&os;
	 InitStack(s);  
	 //初始化栈 
	 Push(s,'#');   
	 //压入栈底元素'#'
	 fflush(stdin);
	 //扫描中缀表达式  
	 do   
	 {    
		 c=getchar();  
		 switch(c)  
		 {  
			 case ' ':   
				 break;//去除空格  
			 case '0':  
			 case '1': 
			 case '2':  
			 case '3':   
			 case '4': 
			 case '5':  
			 case '6': 
			 case '7':  
			 case '8': 
			 case '9':   
				 EnQueue(q,c);
				 break;
			 case '(': 
				 Push(s,c);
				 break;
		     case ')':
		     case '#':
		    	 do    
				 {
				    t=Pop(s);
				    if (t!='(' && t!='#')
				    EnQueue(q,t);
				 } while(s ->top &&t!='(' && t!='#' );     		         
				 break;
			 case '+':
			 case '-': 
			 case '*': 
			 case '/': 
				 while( Priority(c)<=Priority(GetTop(s)))
				 {   if(GetTop(s)!='(')          
						EnQueue(q,Pop(s));
				
				 }
				 Push(s,c);
				 break;
			} //endswitch
	 }while(c!='#');
 }
void main()
 { 
	seqqueue *q;  
	seqqueue postq;  
	//定义队列，存放后缀表达式  
	q=&postq;
	InitQueue(q);
    //初始化队列  
	IntoPostExp(q); 
    //中缀表达式转换为后缀表达式  
	while (!QueueEmpty(q)            )  
	//输出后缀表达式   
	cout<<DeQueue(q)<<"  "; 
}

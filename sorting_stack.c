#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int stacks[SIZE],stackT[SIZE];
int tops = -1,topT = -1;
void push(int stack[],int *top,int value){
    if(*top == SIZE -1){
        printf("stack overflow\n");
    }else{
        stack[++(*top)] = value;
    }
}
int pop(int stack[],int *top){
    if(*top == -1)printf("underflow!!");
    return stack[(*top)--];
}
int peek(int stack[],int top){
    if(top == -1) return -1;
    return stack[top];
}
void display(int stack[],int top,char *name){
    if(top ==-1){
        printf("%s is empty.\n",name);
    }else{
        printf("%s(Top to Bottom):", name);
        for(int i = top;i>=0;i--){
            printf("%d",stack[i]);
        }printf("\n");
    }
}
void sortStack(){
    while(tops != -1){
        int x = pop(stacks,&tops);
        while(topT != -1 && peek(stackT,topT)>x){
            push(stacks,&tops,pop(stackT,&topT));
        }
        push(stackT,&topT,x);
    }
    while(topT != -1){
        push(stacks,&tops,pop(stackT,&topT));
    }
    printf("\nstacks has been sorted \n");
}

int main(){
    int choice,value;
    do{
        printf("\n---Stack Menu---\n1.Push\n2.Pop\n3.Peek\n4.Sort\n5.Display\n6.Exit\nEnter choice :");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: printf("Enter value :");
                scanf("%d", &value);
                 push(stacks,&tops,value);
            break;
        case 2: value = pop(stacks,&tops);
                 if(value == -1) printf("popped: %d\n",value);
                 break;
        case 3: value = peek(stacks,tops);      
               if(value != -1) printf("Top elements: %d\n",value);
               else{printf("overflow!!");}
               break;
        case 4: sortStack();
            break;
        case 5: display(stacks,tops,"stacks");
              break;
        case 6: exit(0);                
        
    }
}while(choice != 6);
    return 0;
} 
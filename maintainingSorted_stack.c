#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
int stack[SIZE];
int top = -1;
void push(int data){
    if(top == SIZE -1){printf("Stack overflow\n");return;}
    stack[++top] = data;
}
int pop(){
    if(top == -1) return -1;
    return stack[top--];
}
void sortedInsert(int element){
    if(top == -1 || element> stack[top]){
        push(element);return;
    }
    int temp = pop();
    sortedInsert(element);
    push(temp);
}
void display(){
    if(top == -1){
        printf("stack is empty.\n");return;
    }
    printf("sorted stack(top to bottom): ");
    for(int i = top;i>=0;i--){
        printf("%d",stack[i]);
    }
    printf("\n");
}
int main(){
    int n ,val;
    printf("Enter number of elements to insert:");
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        printf("Enter element %d:",i+1);
        scanf("%d", &val);
        sortedInsert(val);

    }
    display();
    return 0;
}
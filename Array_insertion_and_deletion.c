#include<stdio.h>
#include <stdlib.h>
#define MAX 100
int arra[MAX];
int n = 0;
void Create(){
   printf("Enter the elements to store in array :") ;
   scanf("%d",&n);
   if(n>MAX){
    printf("No. of elements exceeds maximum capacity of array.Error!!");
    n = 0;
    return;
   }
   for(int i = 0;i <n;i++){
    scanf("%d",&arra[i]);
   }
}
void Insert(){
    int Input,index;
    if(n>= MAX){
        printf("Overflow!!");
        return;
    }
    printf("Enter input to be inserted in array");
    scanf("%d",&Input);
    printf("Enter the position :");
    scanf("%d",&index);
    for(int i = n-1;i>=index -1;i--){
        arra[i+1] = arra[i];
    }
    arra[index-1] = Input;
    n++;
    printf("your array after insertion is:\n");
    for(int i = 0;i<n;i++){
        printf("%d",arra[i]);
    }

}
void Delete(){
    int index;
    if(n == 0){
        printf("underflow!!");
        return;
    }
    printf("Enter index where element to be deleted");
    scanf("%d",&index);
    if(index<1 || index >n)
      {printf("Invalid index");return;} 
    printf("Deleted element is: %d\n", arra[index-1]);
    for(int i = index-1;i<n-1;i++){
        arra[i] = arra[i+1];
    }
    n--;
}
void Display(){
  if(n == 0){
    printf("underflow!!");

  }
  else {
    printf("Elements in array are :\n");
    for(int i = 0;i<n;i++){
        printf("%d",arra[i]);
    }
  }
  
}
int main(){
    int operation;

    do{
        printf("\n ---Array operations---");
    printf("\n1.Create(storing elements)");
    printf("\n2.Insert elements at positon");
    printf("\n3.Deleting an element at any position");
    printf("\n4.Display the array");
    printf("\n5.Exit from array");
    printf("\nEnter your choice to form operations on array(1-5):");
    scanf("%d",&operation);
    switch (operation)
    {
    case 1:Create();
        break;
    case 2:Insert();break;
    case 3: Delete();break;
    case 4:Display();break;
    case 5:exit(0);break;   
    default:printf("Enter valid operation(1-5)..");
        break;
    }
    }while (operation!=5);
    
    
    return 0;
}
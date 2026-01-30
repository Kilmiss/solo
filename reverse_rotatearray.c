#include<stdio.h>
#define SIZE 100
void reverse(int arr[],int i,int j){
    int temp;
    while(i<j){
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}
void leftRotate(int arr[],int n,int k){
   if(n == 0) return;
   k = k % n; 
   reverse(arr,0,k-1);
   reverse(arr,k,n-1);
   reverse(arr,0,n-1);
}
void rightRotate(int arr[],int n,int k){
   for(int i = 0;i<n;i++){
    printf("%d ",arr[i]);
   }printf("\n");
}
int main(){
    int arr[SIZE],n,k;
    printf("Enter number of elements in array: ");
    scanf("%d",&n);
    printf("Enter %d elements:\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    printf("\nchoose operation:\n1.Left Rotation\n2.Right Rotation\n3.Simple reverse\nchoice:");
    
    int choice;
    scanf("%d",&choice);
    if(choice == 1 || choice == 2){
        printf("Enter number of positions to rotate: ");
        scanf("%d",&k);
    }
    switch (choice)
    {
    case 1:leftRotate(arr,n,k);
           printf("Array after left rotation by %d positions:\n",k);
           break;
    case 2:rightRotate(arr,n,k);
           printf("Array after right rotation by %d positions:\n",k);
           break;
    case 3:reverse(arr,0,n-1);
           printf("Array after reversing:\n");
        break;
    
    default:
       printf("invalid choice\n");
        break;
    }
    for(int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    
    return 0;
}
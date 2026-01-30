#include<stdio.h>
void linearSearch(int arr[],int n,int key){
    for(int i = 0;i<n;i++){
        if(arr[i] == key){
            printf("Element %d found at index %d \n",key,i);
            return;
        }
        else
        {printf("element is not found!!");}
    }
}
void sorted(int arr[],int n){
    int temp;
    for(int i =0;i<n-1;i++){
        for(int j =0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                 temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void binarySearch(int arr[],int n,int key){
    int low = 0,high = n-1,mid,found = 0;
    sorted(arr,n);
    while(low <= high){
        mid = (low + high)/2;
        if(arr[mid] == key){
            printf("Element %d found at index %d \n",key,mid);
            found = 1;
            break;
        }
        else if(arr[mid] < key){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
     if(!found){
        printf("Element is not found!!");
    }
}
int main(){
    int arr[14],key,choice,n;
    printf("Enter number of elements in array:");
    scanf("%d",&n);
    printf("Enter %d elements:\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("\nEnter the element to be searched:");
    scanf("%d",&key);
    printf("\nChoose :\n1.Linear Search\n2.Binary Search\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:linearSearch(arr,n,key);
            break;
            
        case 2:binarySearch(arr,n,key);
            break;
            
        default:
            printf("Invalid choice");
    }
    return 0;
}
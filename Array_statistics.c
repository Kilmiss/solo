#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
int main(){
    int arr[SIZE],n,min,max,sum = 0,largeNo,secLargeNo;
    float average;
    printf("Enter number of elements in array(max %d)",SIZE);
    scanf("%d",&n);
    if(n<1){
        printf("Invalid array size.\n");
        return 1;
    }
    printf("Enter %d elements:\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    min = max = arr[0];
    for(int i = 0;i<n;i++){
        if(arr[i]>max){
            max = arr[i];
        }
        if(arr[i]<min){
            min = arr[i];
        }
        sum += arr[i];
    }
    average = (float)sum/n;
    largeNo = -2147483648; 
    secLargeNo = -2147483648;
    for(int i = 0;i<n;i++){
        if(arr[i]>largeNo){
            secLargeNo = largeNo;
            largeNo = arr[i];
        } if(arr[i]>secLargeNo && arr[i]!=largeNo){
            secLargeNo = arr[i];
        }
    }
    printf("\n---Array Statistics---\n");
    printf("Minimum element: %d\n",min);
    printf("Maximum element: %d\n",max);
    printf("Sum of elements: %d\n",sum);
    printf("Average of elements: %.2f\n",average);
    if(n<2 || secLargeNo == -2147483648){
        printf("Second largest element does not exists.\n");
    }else{
        printf("Second largest element: %d\n",secLargeNo);
    }printf("\n")    ;
    return 0;
}
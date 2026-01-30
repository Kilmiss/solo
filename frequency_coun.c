#include <stdio.h>
void freq(int arr[], int n) {
    int find[n], seen = 0,count = 1;
    for(int i = 0; i < n; i++) {
           for(int j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
                find[j] = seen; 
            }
        }
        if(find[i] != seen) {
            find[i] = count;
        }
    }
    for(int i = 0; i < n; i++) {
        if(find[i] != seen) {
            printf("%d occurs %d times\n", arr[i], find[i]);
        }
    }
}
int main() {
    int arr[100], n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter %d elements:\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    countFrequency(arr, n);
    return 0;
}
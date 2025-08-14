#include <stdio.h>
#include <stdlib.h>
#include<pthread.h>

int *a;
int number;
int s;
void *generate_fibonacci(void *arg){
    a = (int *)malloc((number+1)*sizeof(int));
    if(number == 0){
        a[0]=0;
        

    }
    else{
            a[1] = 1;
        for(int i=2;i<=number;i++){
            a[i]= a[i-1] + a[i-2];
        }
    }

    for(int i=0;i<=number;i++){
        printf("a[%d] = %d\n",i,a[i]);
    }

   
    pthread_exit(NULL);
}

void *search_result(void *arg){
    for(int i=1;i<=s;i++){
        printf("Enter search %d:\n",i);
        int j;
        scanf("%d",&j);
       
        if(0<= j && j<= number){
            printf("result of search #%d = %d\n",i,a[j]);
        }
        else{
            printf("result of search #%d = -1\n",i);
        }
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t t1 ,t2;
    

    printf("Enter the term of fibonacci sequence:\n");
    scanf("%d",&number);

    // generate_fibonacci(number);
    pthread_create(&t1,NULL,generate_fibonacci,NULL);
    pthread_join(t1,NULL);

    printf("How many numbers you are willing to search?:");
    scanf("%d",&s);
    // search_result(s);
    pthread_create(&t2,NULL,search_result,NULL);
    pthread_join(t2,NULL);
    return 0;
}

#include<stdio.h>
#include<math.h>
float f(float x){
    return sqrt(x);
}
float inputX(float *x ,int n){
    float upper , lower;
    printf("Enter the value of lower limit : ");
    scanf("%f",&lower);
    printf("Enter the value of upper limit : ");
    scanf("%f",&upper);
    x[0] = lower;
    float h = (upper - lower)/n;
    for(int i = 1 ; i<=n ;++i ){
        x[i] = x[i-1]+h;
    }
    return h ;
}
void calculateY(float *x , float *y , int n){
    for(int i = 0 ; i<=n ;++i){
        y[i] = f(x[i]);
    }
}
float simpson( float *y , float h , int n){
    float two = 0 , three = 0 ;
    for (int i = 1 ; i<n ;i++){
        if(i % 3 == 0) 
        {continue;}
        two = two + y[i];
    }
    for (int i = 3 ;i<n;i+=3){
        three = three + y[i];
    }
    float total  = (3*h)/8 * ( (y[0]+y[n]) + 3*(two) + 2*(three) ) ;
    return total;
}
void output(float *x,float n){
    for(int i = 0 ;i<=n ;++i){
        printf(" %f ",x[i]);
    }
}
int main(){
    const int Max = 10;
    float x[Max] , y[Max];
    int n ;
    printf("Enter value of sub-division : ");
    scanf("%d",&n);
    float h = inputX(x,n);
    calculateY(x,y,n);
    float answer = simpson(y,h,n);
    printf("\n X : ");
    output(x,n);
    printf("\n y : ");
    output(y,n);
    printf("\nThe Integration  : %.4f",answer);
}

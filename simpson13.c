#include<stdio.h>
#include<math.h>
float f(float x){
    return ( 2 / (1+ pow(x,3) ));
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
    float odd = 0 , even = 0;
    for(int i = 1;i<n;i+=2){
        odd = odd + y[i];
        even = even + y[i+1];
    }
    float total = h/3 * ((y[0]+y[n])+4*odd+2*even);
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

#include<stdio.h>
#include<math.h>
float f(float x , float y){
    return x+y;
}
float inputX(float *x , int n){
    printf("Enter the first two value of x : ");
    scanf("%f %f",&x[0],&x[1]);
    float h = x[1]-x[0];
    for(int i = 2 ; i<n ; ++i){
        x[i] = x[i-1]+h;
    }
    return h ;
}
void calculateY(float *x ,float *y , int n , float h){
    printf("Enter the initial value of y(0) : ");
    scanf("%f",&y[0]);
    float k1 , k2 , k3 , k4 ;
    for(int i = 1 ;i<n;++i){
        k1 = h * f(x[i-1],y[i-1]);
        k2 = h * f(x[i-1]+h/2,y[i-1]+k1/2);
        k3 = h * f(x[i-1]+h/2,y[i-1]+k2/2);
        k4 = h * f(x[i-1]+h,y[i-1]+k3);
        y[i] = y[i-1] + 1.0f/6.0f * (k1 + k4 + 2.0f*(k2+k3));
    }
}
void output(float *x , int n){
    for(int i = 0 ; i<n ; ++i ){
        printf("  %.4f  ",x[i]);
    }
    printf("\n");
}
int main(){
    float x[10] , y[10];
    int n ;
    printf("Enter the number of values : ");
    scanf("%d",&n);
    float h = inputX(x,n);
    calculateY(x,y,n,h);
    printf("X : ");
    output(x,n);
    printf("Y : ");
    output(y,n);
}

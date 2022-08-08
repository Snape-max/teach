#include <stdio.h>
int con1(){
    //while语句
    int i=1,sum=0;
    while(i<=100){
        sum=sum+i;
        i++;
    }
    return sum;
}
int con2(){
    //for语句
    int sum=0;
    for(int i=1;i<=100;i++)
        sum=sum+i;
    return sum;
}
void main(){
    int i=1,sum=0;
    link: if(i<=100){
        sum=sum+i;
        i++;
        goto link;
    }
    printf("goto: %d\nwhile: %d\nfor: %d",sum,con1(),con2());
    //goto语句
}
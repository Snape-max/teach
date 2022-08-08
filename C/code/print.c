#include <stdio.h>
void main(){
    int a=88;
    printf("%8c,%-8c.\n",a,a);
    //输出宽度为8，带负号-为左对齐右边填空格
    printf("%+d,%+d.\n",a,-a);
    //显示正负号
    printf("%o,%#o,%x,%#x,%#e,%#g,%#f\n",a,a,a,a+1.2,a+1.2,a+1.2); 
    //加#对c,s,d,u类无影响，对o,x类输出时前加前缀o,0x，对g,e,f类结果有小数时才给出小数
    printf("% d,% d\n",a,-a);
    //负显示负号，正显空格
    float b;
    b=1.23456;
    printf("%.5f,%.4f,%4.5f,%8.5f,%-8.5f",b,b,b,b,b);
    //%.5f精度为5,即保留5位小数点号前表示宽度，宽度小于精度按实际位数输出
}
 #include <stdio.h>
int main(){
    int sigh=1;
    float deno=2.0,sum=1.0,term;
    int need;
    printf("Please type the number: ");
    scanf("%d",&need);
    while (deno<need)
    {
        sigh=-sigh;
        term=sigh/deno;
        sum = sum + term;
        deno = deno + 1;
    }
    printf("%f",sum);
}

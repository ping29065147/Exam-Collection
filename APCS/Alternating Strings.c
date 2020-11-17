#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int k, a = 0, t, last = 0, b=0, re=0;
    char str[100000], *ptr, *roll;

    scanf("%d", &k);
    scanf("%s", str);

    t = 2*k-1;  //設變數t為2k-1
    ptr = str;
    roll = str; //將ptr roll 指到str

    while(*ptr != NULL){    //一直讀取直到輸入字串中的字元為空
        printf("\n%c", *ptr);
        printf("[t]:%d\t", t);
        printf("[A]:%d", a);
        if (isupper(*ptr)){     //isupper是用來判斷大小寫，大寫則為true
            //printf("upper");
            if (a == 0){    //第一次，如果是大寫則為正數
                a++;    //a為交錯字串長度
                t -= 2;
            }
            else{
                if (t > 0){ //t>0，也就是下一個應為大寫，則繼續
                    a++;
                    t -= 2;
                    if (t < 0)
                        t = -1*2*k+1;
                }
                else{   //若不符合，則斷掉
                    //printf("[t]:%d\t", t);
                    printf("[\n");
                    if (a >= k && a > last){    //計算並儲存當前交錯字串的長度
                         last = a;
                         last = last/k*k;
                    }
                    a = 0;  //將變數歸零
                    re = 1;
                    t = 2*k-1;
                    roll++;     //roll++則下一次重新判斷會從下一個字元開始
                    ptr = roll;
                }
            }
        }
        else{
            //printf("low");
            if (a == 0){
                t *= -1;    //如果是小寫則把t變為負數
                a++;
                t += 2;
            }
            else{
                if (t < 0){
                    a++;
                    t += 2;
                    if (t > 0)
                        t = 2*k-1;
                }
                else{
                    //printf("[t]:%d\t", t);
                    printf("\n");
                    if (a >= k && a > last){
                        last = a;
                        last = last/k*k;
                    }
                    a = 0;
                    re = 1;
                    t = 2*k-1;
                    roll++;
                    ptr = roll;
                }
            }
        }
        if (a != 0)     //如果條件符合就繼續下一個運算
            ptr++;
        b++;
    }
    if (re != 1)    //如果整個程式執行完沒有斷掉，則此字串長度即為交錯字串長度
        last = b;

    printf("\n\n%d", last);
    //printf("\n%d\n%s", k, str);

    return 0;
}


//
//  main.c
//  JSFirstCDemo
//
//  Created by drision on 2017/1/11.
//  Copyright © 2017年 drision. All rights reserved.
//

#include <stdio.h>
#include <string.h>

//指针作用1:形参的改变会影响到实参
void change(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//指针作用2:函数可以无限多个返回值
int sumAndMinus(int a, int b, int *minus) {
    *minus = a - b;
    return a + b;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
//    int a = 1;
//    int b = 2;
    int a = 1, b = 2;
    printf("变换前a = %i, b = %i\n", a, b);
    change(&a, &b);
    printf("变换后a = %i, b = %i\n", a, b);
    int sum, minus;
    sum = sumAndMinus(a, b, &minus);
    
    printf("打印和：%d\n", sum);
    printf("打印差：%d\n", minus);
    
    int *c, *d;
//    *c = 10;//这是错误的，指针在没有确定地址之前是不能使用的
    int i = 10;
    printf("i = %d, i的地址：%p\n", i, &i);
    d = &i;
    printf("c的地址：%p, c的内容：%p\n", &c, c);
    printf("d = %d, d的地址：%p, d的内容：%p\n", *d, &d, d);
    
    //字符串，C语言中没有这个类型
    //字符串初始化
    //以这种方式定义，必须以0作为结尾
    char s[5] = {'J', 'S', 'C', 'D', '\0'};
    printf("s = %s\n", s);
    //以这种方式定义，结尾自动加0，推荐做法
    char s1[] = "JSCD1";
    printf("s1 = %s\n", s1);
    //以这种方式定义字符串，分配的长度要比实际长度大，因为结尾会自动加0
    char s2[6] = "JSCD2";
    printf("s2 = %s\n", s2);
    char s4[20] = "JSCD4";
    printf("s4 = %s\n", s4);
    //字符串数组初始化
    char names[2][10] = { {'J','a','y','\0'}, {'J','i','m','\0'} };
    printf("names[0] = %s, names[1] = %s\n", names[0], names[1]);
    printf("names[0][0] = %c\n", names[0][0]);
    char names2[2][10] = { {"Jay"}, {"Jim"} };
    printf("names2[0] = %s, names2[1] = %s\n", names2[0], names2[1]);
    char names3[2][10] = { "Jay", "Jim" };
    printf("names3[0] = %s, names3[1] = %s\n", names3[0], names3[1]);
    char names4[][10] = {"Jay", "Jim"};
    printf("names4[0] = %s, names4[1] = %s\n", names4[0], names4[1]);
    //字符串赋值
    char s3[20] = "JSCD3temp";
//    s3 = "JSCD3";数组名代表当前数组的首地址，是一个常量不可修改
//    s3[20] = "JSCD3";s3[20]代表字符串数组里的第21个元素，是一个char类型，类型不匹配
    strcpy(s3, "JSCD3");//正确的赋值方式
    printf("s3 = %s\n", s3);
    strncpy(s3, "jscd3", sizeof("jscd3"));//另外一种赋值方式
    printf("s3 = %s\n", s3);
    return 0;
}

//해더 파일 정의부
#ifndef CLIENTFUNC_H
#define CLIENTFUNC_H

//include 할 해더 파일 명시부
#include<stdio.h> //standard input output
#include<stdlib.h> //standard library
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>


//메크로 정의부
#define MAX_CHILDS 16
//struct, type 정의부

//전역 변수 선언부

//함수 선언부
int check_threshold(int child_n);

#endif
#include "ClientFunc.h"

// 자식 프로세스 개수 제어 
int check_threshold(int child_n)
{
    //만약 만들려는 개수가 임계값보다 작거나 같다면 지정한 child 개수로 생성하고 
    if(MAX_CHILDS >= child_n) return child_n;
    //임계값을 넘었다면 임계값으로 return 해라 
    else return MAX_CHILDS;
}
#include <stdio.h>
int main()
{
    int var = 5; //var라는 변수에 5라는 value가 있다.
    printf("var: %d\n", var);

    // var의 주소는 &var으로 표현된다. 그리고 이것은 pointer type이다. 주소는 포인터다.
    printf("address of var: %p\n", &var);
    
    //이번에는 애시당초 pointer변수를 먼저 선언한다.
    int * ptr;
    //그 포인터 변수에다가 var의 주소값을 할당한다.
    ptr = &var;
    printf("%p", ptr);
    return 0;
}
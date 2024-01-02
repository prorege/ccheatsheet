#include <stdio.h>

void main(void) {
    unsigned i;
    for (i=10; i >= 0; i--) {
        printf("i is %u\n", i);
    }
}
//unsigned라는 type은 0>=i인 양수를 의미한다(원래는 부호가 없다는 것인데 양수와 동일한 결과).
//따라서 위의 조건문은 10~0이 아니라 수없는 양수를 계속 생산한다.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *numbers;
    int sum = 0;
    float average;

    // 사용자로부터 정수의 개수를 입력 받음
    printf("정수의 개수를 입력하세요: ");
    scanf("%d", &n);

    // 사용자가 입력한 개수만큼의 메모리를 동적으로 할당
    numbers = (int *)malloc(n * sizeof(int));
    
    // 메모리 할당이 성공했는지 확인
    if (numbers == NULL) {
        printf("메모리 할당 실패\n");
        return 1; // 실패 시 프로그램 종료
    }

    // 사용자로부터 정수들을 입력받아 배열에 저장
    printf("%d개의 정수를 입력하세요:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
        sum += numbers[i];
    }

    // 입력된 정수들의 평균을 계산
    average = (float)sum / n;

    // 결과 출력
    printf("입력된 정수들의 평균은 %.2f입니다.\n", average);

    // 동적으로 할당한 메모리를 해제
    free(numbers);

    return 0;
}

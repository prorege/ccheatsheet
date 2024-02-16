#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *numbers;
    int sum = 0;
    float average;

    // ����ڷκ��� ������ ������ �Է� ����
    printf("������ ������ �Է��ϼ���: ");
    scanf("%d", &n);

    // ����ڰ� �Է��� ������ŭ�� �޸𸮸� �������� �Ҵ�
    numbers = (int *)malloc(n * sizeof(int));
    
    // �޸� �Ҵ��� �����ߴ��� Ȯ��
    if (numbers == NULL) {
        printf("�޸� �Ҵ� ����\n");
        return 1; // ���� �� ���α׷� ����
    }

    // ����ڷκ��� �������� �Է¹޾� �迭�� ����
    printf("%d���� ������ �Է��ϼ���:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
        sum += numbers[i];
    }

    // �Էµ� �������� ����� ���
    average = (float)sum / n;

    // ��� ���
    printf("�Էµ� �������� ����� %.2f�Դϴ�.\n", average);

    // �������� �Ҵ��� �޸𸮸� ����
    free(numbers);

    return 0;
}

// #include <stdio.h>

// void main(int argc, char *argv[]) {
//     int i;
//     for (i=0; i < argc; i=i+1) {
//         printf("Argument %d is %s\n", i, argv[i]);
//     }
// }

/*
    C 언어에서 main 함수의 매개변수 argv는 명령행 인수(arguments)를 저장하는 배열이며,
    argc는 명령행 인수의 개수를 나타냅니다. 이 예시에서 argv[0]은 프로그램의 실행 파일 이름이 됩니다.

    프로그램을 실행할 때, 명령어 뒤에 입력된 첫 번째 문자열은 프로그램의 이름이 됩니다.
    따라서 argv[0]에는 실행 파일의 이름이 들어가게 됩니다.
    이 예시에서는 "for.exe"가 프로그램의 이름으로 사용되어 argv[0]에 저장됩니다.

    따라서 출력 결과에서 "Argument 0 is for.exe"는 argv[0]에 저장된 프로그램의 이름을 출력한 것입니다.
    이는 C 언어에서 표준적으로 사용되는 관례입니다. 명령행 인수의 실제 값은 argv[1]부터 시작하게 됩니다.
*/

//-------------------------------------//

#include <stdio.h>
void main(int argc, char *argv[]) {
    int i;
    i=0; // INITIALIZE
    while (i < argc) {
        printf("Argument %d is %s\n", i, argv[i]);
        i = i+1; // ITERATE
    }
}

/*같은 원리를 적용해서 for loop 에서 while loop으로 바꿔놓은 것*/
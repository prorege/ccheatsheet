#include <stdio.h>

void main(int argc, char *argv[]) {
    switch (argc) {
    case 0:
    case 1:
        printf("You need to enter at least 1 parameter\n");
        break;
    case 2:
    case 3:
        printf("Everything is OK\n");
        break;
    default:
        printf("You entered too many parameters.\n");
        break;
    }
}
//C:\Users\gms04\ccheatsheet>switch.exe arg1 arg2
//Everything is OK
//

//프로그램이 실행될 때 명령행 인수(arguments)는 프로그램에 대한 정보나 사용자로부터 입력을 받기 위해 사용됩니다. 
//명령행 인수는 프로그램을 실행할 때 명령행(Command Line)에 추가로 입력하는 값들을 말합니다.
//프로그램이 명령행 인수를 받는 경우, 일반적으로 다음과 같은 형식으로 명령어를 입력합니다.


//./프로그램이름 인수1 인수2 ... 인수N
//여기서 ./프로그램이름은 프로그램을 실행하는데 사용되는 명령어이며, 
//인수1, 인수2, ..., 인수N은 프로그램에 전달되는 인수들입니다. 
//이때 ./프로그램이름은 argv[0]에 해당하며, 인수1, 인수2, ..., 인수N은 argv[1], argv[2], ..., argv[N]에 각각 저장됩니다.

// 따라서 argc는 명령행 인수의 개수를 나타내고, 
//argv는 명령행 인수들의 배열을 나타냅니다. 
//argc는 프로그램을 실행할 때 입력된 명령행 인수의 개수이며, 
//argv는 실제 명령행 인수들을 담고 있는 배열입니다.
#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

typedef struct node
{
    int value; //값을 저장하는 변수
    struct node* next; //다음 노드의 주소를 저장하는 변수(포인터변수 : 8byte)
}node;

node * head; //첫 노드의 주소를 저장하는 head(포인터 변수 : 8바이트)

void insertFrontNode(int data);
void insertTailNode(int data);

void displayNode();
int getNodeCount();
void removeNodeFront();
void memoryFree();
void removeNodeValue(int target);


int main()
{
	int choice;
    int data;
    int count;
	while (1)
	{
		system("cls");
		printf("\n\n  *** 단일 연결 리스트(Singly Linked List) ***\n\n");
		printf("=====================================\n");
		printf(" 1. 맨 앞 삽입\n"); // 완료
		printf(" 2. 맨 뒤 삽입\n");
		printf(" 3. 앞에서부터 N번째 삽입\n");
		printf(" 4. 오름차순 정렬 삽입\n");
		printf("=====================================\n");
		printf(" 5. 맨 앞 삭제\n");//완료
		printf(" 6. 맨 뒤 삭제\n");
		printf(" 7. 전체 노드 삭제\n");
		printf(" 8. 특정 값 삭제\n");
		printf(" 9. 앞에서부터 N번째 삭제\n");
		printf("=====================================\n");
		printf("10. 단일 연결 리스트 출력(노드 순회)\n"); //완료
		printf("11. 노드의 개수 구하기\n"); //완료
		printf("12. 노드 검색\n");
		printf(" 0. 프로그램 종료\n");
		printf("=====================================\n");
		printf("\n메뉴 선택 : ");
		scanf("%d", &choice);
		while (getchar() != '\n');
        
		switch (choice)
		{
		case 1:
            printf("추가할 데이터를 입력하세요 : ");
            scanf("%d", &data);
            insertFrontNode(data);
			break;
		case 2:
            printf("추가할 데이터를 입력하세요 : ");
            scanf("%d", &data);
            insertTailNode(data);
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
            removeNodeFront(data);
			break;
		case 6:

			break;
		case 7:
            memoryFree();
			break;
		case 8:
            printf("\n\n삭제할 값 입력 : ");
            scanf("%d", &data);
            removeNodeValue(data);
			break;
		case 9:
			break;
		case 10:
            displayNode();
			break;
		case 11:
            count = getNodeCount();
            printf("노드의 개수는 %d개입니다.", count);
			break;
		case 12:
			break;
		case 0:
            memoryFree();
			exit(0); //프로그램 강제 종료
		}//end switch

		//switch문을 빠져 나오면 일시 대기 시킨다.
		printf("\n\n\t\t");
		system("pause"); //일시 대기

	}//end while
	return 0;
}


void insertFrontNode(int data){
    node* newNode; //생성된 노드의 주소를 저장하는 변수(포인터 변수)
    newNode = (node*)malloc(sizeof(node)); //노드 생성
    newNode -> value = data;
    newNode -> next = NULL;
    if(head == NULL)//생성된 노드가 없다, 첫 노드!
    {
        head = newNode;
        printf("case 1. 노드 맨 앞 삽입(첫 노드로 연결)\n");
        return;//호출한 곳으로 돌아간다.(함수 종료)
    }
    newNode-> next = head;
    head = newNode;
    printf("case 2. 노드 맨 앞 삽입(첫 노드가 아닌 경우)\n");
}

void displayNode(){
    node*curNode; //방문 노드의 주소 저장하는 포인터변수
    if(head == NULL)
        return; //종료
    system("cls");//화면 지우기
    printf("\n\nSimply LinkedList : ");
    
    curNode = head; //첫번째 node 방문 노드로 설정
    while(curNode -> next != NULL){
        printf("%d =>", curNode -> value);
        curNode = curNode -> next;
    }
    printf("%d\n", curNode->value);
    
}

int getNodeCount(){
    int count = 0;
    node* curNode;
    if(head == NULL)
        return 0;

    curNode = head;
    while(curNode != NULL){
        count ++;
        curNode = curNode -> next;
    }
    return count;
}

void removeNodeFront(){
    node*delnode; //제거할 노드
    if(head == NULL) //노드 생성전
        return ;
    delnode = head;//head가 가리키는 첫번째 노드
    head = head->next; //head는 두번째로 넘어감
    free(delnode); //첫번째 노드 삭제
    printf("\n\n\n\t 첫 번째 노드를 제거했습니다.");
}


void memoryFree(){
    node* delNode;

    if(head == NULL)
        return;
    
    while(head != NULL){
        delNode = head;
        head = head ->next;
        free(delNode);
    }
    printf("모든 노드를 제거했습니다. \n");
}

void insertTailNode(int data){
    node*curNode;//방문노드
    node*newNode;//생성된 노드
    newNode = (node*)malloc(sizeof(node));//새 노드 생성
    newNode -> value = data;// 새 노드 값 할당
    newNode -> next = NULL; //새 노드 포인터 할당

    if(head == NULL){ //만약 노드가 존재하지 않는다면
        head = newNode; //head가 곧 newnode
        return;
    }
    curNode = head;//노드가 존재한다면 curNode에 head값을 넣어준다.
    while(curNode -> next != NULL) //그 다음 node가 존재할 동안
        curNode = curNode ->next; //curnode는 넘어간다.
    curNode->next = newNode; //연결
}

void removeNodeValue(int target){
    node*prevNode;
    node*delNode;
    //case1. 연결리스트가 생성되지 않은 경우
    if(head == NULL)
    {
        printf("\n\n연결할 리스트가 없습니다.");
        return;
    }
    //case2. 삭제할 노드가 첫번째 노드인 경우(head값이 변경되어야 하기 때문)
    if(head->value == target)
    {
        delNode = head;
        head = head->next;
        free(delNode);
        return;
    }
    delNode = head;
    prevNode = head;

    while(prevNode->next != NULL)//일반적인 경우(중간 삭제)
    {
        delNode = prevNode->next;
        if(delNode->value == target)
        {
            prevNode -> next = delNode -> next;
            free(delNode);
            return;
        }
        prevNode = delNode;
    }
}

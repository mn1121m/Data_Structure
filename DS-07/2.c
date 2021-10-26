/* pass
2. Program 3.12 Maze search function을 사용하는 미로탐색 프로그램을 작성하여라. [프로그램 설명]
다음 1 ~ 5의 변수는 모두 전역으로 선언되며 정적할당을 사용함.
    1 maze
    - 입구는 left top, 출구는 right bottom으로 가정
    - 미로 데이터입력 (“input.txt”, 최대 10×10 행렬로 파일입력)
    45
    2 mark 3 move
    4 stack
    entrance (1, 1), exit (4, 5)
    
    #define MAX_STACK_SIZE 100 typedef struct {
    short int row; short int col; short int dir;
    } element;
    element stack[MAX_STACK_SIZE]; int top = -1;
    5 기호상수 : 전역변수 :
    #define TRUE 1
    #define FALSE 0
    int EXIT_ROW, EXIT_COL;
*/
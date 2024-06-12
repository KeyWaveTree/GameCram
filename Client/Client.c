#include "Client.h"
#include "ClientFunc.h"


//클라이언트 관련 시스템 구현 부
//클라이언트는 더미 데이터만 서버에 보내는 형식으로 개발 함. 

//명령 
//cram.out -cn 4: 더미 클라이언트 4개를 만들라. 2, 3
//cram.out -cn: 더미 클라이언트 1개 만들라.1, 2
//cram.out start: 만든 더미 클라이언트 실행, 1


//인자값 count, *인자값 목록
int main(int argc, char *argv[])
{
    //실험.1
     // printf("%d\n", argc);
    // for(int i=0; i < argc; i++)
    // {
    //     printf("%s\n", argv[i]);
    // }
    //

    //변수 부
    pid_t *pids = NULL; //자식 프로세스 배열
    pid_t pid;

    int state;
    int child_n = 1; //자식프로세스 1개(기본 옵션)
	int run_process = 0; //생성한 프로세스 수
	
    //명령 인자 확인부
    //명령 인자값 개수가 올바르지 않을때 
    if(!(2 <= argc && argc <= 3))
    {
        perror("The number of commands is not correct.");
        exit(0);
    }
    
    //명령어가 올바르지 않을때 
    if(strcmp(argv[1], "-cn") != 0)
    {
        printf("Command %s not found\n", argv[1]);
        perror("use command -cn or start\n");
        exit(0);
    }
    
    //자식 프로세스 배열 동적 할당부
    //동작전 child 프로세스 개수 확인 후 생성
    if(argc == 3) 
    {
        child_n = check_threshold(atoi(argv[2])); //프로세스 생성 개수 지정 후 임계값 확인
        pids = (pid_t*)malloc(sizeof(pid_t) * child_n);//child n 개수 만큼 저장 공간 할당
    }
    //기본 명령일때 child 프로세스 1개만 생성
    else if(argc == 2 && strcmp(argv[1], "-cn")==0) 
    {
        pids = (pid_t*)malloc(sizeof(pid_t) * child_n);
    }
    
    //자식은 하나라고 가정
    while(1)
    {
        while(run_process <= child_n)
        {
            pids[run_process] = fork();//자식 프로세스 생성 
            // 오류 
            if(pids[run_process]==-1)
            {
                printf("can not fork\n");
                exit(0);
            }

            //1. 자식 프로세스(더미데이터들을 보내는 n개의 클라이언트 역할)
            else if(pids[run_process])
            {
                //키보드 arrow 값, a, s, w, d, mouse 클릭 값들을 자식 프로세스들이 랜덤하게 서버에 input으로 전달
                //실행시간은 각각 랜덤한 시간으로 10초에서 100초 정도
                //exec
            }

            //2. 부모 프로세스(서버 데이터 response)
            else
            {   
                //부모 프로세스에서는 현재 자식 프로세스가 서버에 요청한 데이터 출력하는 역할
                //또한 데이터 저장
            }
        }    
        //자식 프로세스 메모리 할당 헤제 
        
    }
    free(pids);
    //1. 입력, 자식프로세스 만들어서 키보드 입력 처리
    //명령을 받으면 명령에 표시된 n개의 클라이언트를 만든다.
    //클라이언트의 파일 접근 - 왜 접근 하는가?
    //지금까지 수행한 컨트롤 명령 log, 
    //.Data폴더 안 파일이 접근 되야 됨.
    
    //폴더 접근 권한 
    //먼저 현재 클라이언트에서 다른 클라이언 데이터 접근되면 안됨. 
    //로그인을 해야 클라이언트 생성가능 - 로그인이라는 것은 각 리눅스 user 당 하나만 가능.
    
    //user 클라이언트 처음 생성:
    //데이터 폴더에 접근하여 user명 폴더 생성 후 file 생성. : 파일 권한, 폴더 권한
    //file은 각각 명령을 기록하는 로그 파일(서버에서 저장해도 될것 같음), 
    //서버로 데이터 전송 파일 : 파일 데이터 전송시 전송하는 데이터가 매칭된 클라이언트 입력만 관리해야 함. 

    //입력을 어떻게 동작할 것인가?
    //키보드 같은 키를 연달아서 누를때 
    //키보드 키를 한번만 누를 때
    
    //주의 사항.
    //키를 연달아서 누른 상태에서 다른 작업이 진행하고 있는 경우 
    //

    //스로틀링과 디바운싱
    


    return 0;
}
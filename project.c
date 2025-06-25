#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

int main() {
    srand(time(NULL));
    char start[] = {"start"};
    char play[100];
    int yes = 0;
    
    printf("시작하려면 start를 입력해주세요!\n");
    scanf("\n%s", play);
    
    for(int i = 0; i < strlen(play); i++){
        if(start[i]==play[i]){
            yes++;
        }
    }
    if(yes==5){
        int num;
        int random;
        char difficult[10];
        printf("게임을 시작합니다!\n");
        usleep(500000);
        printf("난이도를 선택해주세요!\n");
        usleep(500000);
        printf("존재하지 않는 난이도를 선택하면 처음으로 돌아가서 다시 start를 입력하셔야해요!\n");
        usleep(500000);
        printf("--------------\neasy (1~50)\nnormal (1~100)\nhard (1~300)\n--------------\n");
        scanf("%s", difficult);
        if(strcmp(difficult, "easy")!=0&&strcmp(difficult, "normal")!=0&&strcmp(difficult, "hard")!=0){
            printf("이건 존재하지 않는 난이도에요...\n처음으로 돌아갑니다..\n");
        }
        else if(strcmp(difficult, "easy")==0){
            printf("easy 난이도를 선택하셨어요!\n");
            usleep(500000);
            printf("숫자를 생성중이에요..\n");
            sleep(2);
            printf("숫자가 생성되었어요! 이제 맞춰보세요!\n");
            usleep(500000);
            printf("범위를 벗어난 수를 입력해도 횟수가 깎이는걸 명심하세요!\n");
            random = rand()%50+1;
            int i;
            for(i = 15; i >= 1; i--){
                printf("-------------------------------------\n수를 입력해주세요! (남은 기회 %d번)\n", i);
                scanf("%d", &num);
                if(num==random){
                    printf("축하해요! 정답을 맞추셨어요!\n");
                    break;
                }
                else if(num > 100 || num < 1){
                    printf("뭐하세요..?\n");
                }
                else if(num > random){
                    printf("그것보다 작아요!\n");
                }
                else if(num < random){
                    printf("그것보다는 커요..\n");
                }
            }
            if(i==0){
                printf("-------------------------------------\n저런.. 아쉽게됐네요.. 정답은 %d 였어요!", random);                   
            }

        }
        else if(strcmp(difficult, "normal")==0){
            printf("normal 난이도를 선택하셨어요!\n");
            usleep(500000);
            printf("숫자를 생성중이에요..\n");
            sleep(1);
            printf("숫자가 생성되었어요! 이제 맞춰보세요!\n");
            usleep(500000);
            printf("범위를 벗어난 수를 입력해도 횟수가 깎이는걸 명심하세요!\n");
            random = rand()%100+1;
            int i;
            for(i = 20; i >= 1; ){
                printf("-------------------------------------\n수를 입력해주세요! (남은 기회 %d번)\n", i);
                scanf("%d", &num);
                if(num==random){
                    printf("축하해요! 정답을 맞추셨어요!\n");
                    break;
                }
                else if(num > 50 || num < 1){
                    printf("뭐하세요..?\n");
                    i--;
                }
                else if(num > random){
                    printf("그것보다 작아요!\n");
                    i--;
                }
                else if(num < random){
                    printf("그것보다는 커요..\n");
                    i--;
                }
            }
            if(i==0){
                printf("-------------------------------------\n저런.. 아쉽게됐네요.. 정답은 %d 였어요!", random);                   
            }
        }
        else{
            int random2;
            printf("hard 난이도를 선택하셨어요!\n");
            usleep(500000);
            printf("hard 난이도는 숫자 두개를 맞추셔야해요!\n");
            usleep(500000);
            printf("숫자 2개를 생성중이에요..\n");
            sleep(1);
            printf("숫자가 생성되었어요! 이제 맞춰보세요!\n");
            usleep(500000);
            printf("범위를 벗어난 수를 입력해도 횟수가 깎이는걸 명심하세요!\n");
            random = rand()%300+1;
            random2 = rand()%300+1;
            int i;
            int clear;
            for(i = 20; i >= 1; ){
                printf("-------------------------------------\n첫번째 수를 입력해주세요! (남은 기회 %d번)\n", i);
                scanf("%d", &num);
                if(num==random){
                    usleep(500000);
                    printf("축하해요! 하나를 맞추셨어요!\n");
                    clear = 1;
                    usleep(500000);
                    for(i *= 2; i >= 1; i--){
                        printf("-------------------------------------\n두번째 수를 입력해주세요! (남은 기회 %d번)\n", i);
                        scanf("%d", &num);
                        if(num==random2){
                            printf("축하해요! 모든 정답을 맞추셨어요!\n");
                            break;
                        }
                        else if(num > 300 || num < 1){
                            printf("뭐하세요..?\n");
                            i--;
                        }
                        else if(num > random2){
                            printf("그것보다 작아요!\n");
                            i--;
                        }
                        else if(num < random2){
                            printf("그것보다는 커요..\n");
                            i--;
                        }
                    }
                    if(i==0){
                        printf("-------------------------------------\n저런.. 아쉽게됐네요.. 정답은 %d 였어요!\n", random2);
                        break;                
                    }
                }
                else if(num > 300 || num < 1){
                    printf("뭐하세요..?\n");
                    i--;
                }
                else if(num > random){
                    printf("그것보다 작아요!\n");
                    i--;
                }
                else if(num < random){
                    printf("그것보다는 커요..\n");
                    i--;
                }
            }
            if(i==0 && clear != 1){
                printf("-------------------------------------\n저런.. 아쉽게됐네요.. 정답은 %d과 %d 였어요!\n", random, random2);                   
            }
        }
    }
    else{
        printf("-------------------------------------\n안녕히가세요!\n");
    }
    return 0;
}
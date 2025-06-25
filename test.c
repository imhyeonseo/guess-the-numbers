#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
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
        char difficult[10];
        printf("게임을 시작합니다!\n");
        sleep(1);
        printf("난이도를 선택해주세요!\n");
        sleep(1);
        printf("easy\nnormal\nhard\n");
        scanf("%s", difficult);
        if(difficult!="easy"&&difficult!="normal"&&difficult!="hard"){
            printf("이건 존재하지 않는 난이도에요...");
        }
        else if(difficult=="easy"){
            printf("easy 난이도를 선택하셨어요!\n");
        }
        else if(difficult=="normal"){
            printf("normal 난이도를 선택하셨어요!\n");
        }
        else{
            printf("hard 난이도를 선택하셨어요!\n");
        }
    }
    else{
        printf("안녕히가세요!\n");
    }
}
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

#define LINE_SZ 128

char EventName[LINE_SZ];
char WPlayer[LINE_SZ];
char BPlayer[LINE_SZ];
char Result[LINE_SZ];
char Board[64][64];

void setEventName(char *);
void setWPlayerName(char *);
void setBPlayerName(char *);
void setResult(char *);
void setBoardPieces(char *);
void boardFiller(char *, int);
void boardVerifier(char *);
void printPaginatedComments(char *);

void readBoardGame(FILE *);

int main(int argc, char *argv[]){
    
    if(argc < 2){
        printf("[!] No game file provided.\n");
        printf("[-] Usage : %s FILENAME.pgn\n", argv[0]);
        exit(0);
    }

    size_t arg_sz = strlen(argv[1]);
    char *extptr = argv[1] + arg_sz - 4;

    if(strncmp(extptr, ".pgn", 4) != 0){
        printf("[!] Bad game file extension provided.\n");
        exit(0);
    }

    FILE *fboard_state = fopen(argv[1], "r");

    if(fboard_state == NULL){
        printf("[!] Bad game file provided.\n");
        exit(0);
    }

    readBoardGame(fboard_state);
    
    return 0;
}

void readBoardGame(FILE *board){

    char *linebuf = NULL;
    size_t len = 0;
    ssize_t n;

    // Read event name
    n = getline(&linebuf, &len, board);
    setEventName(linebuf);
    
    // Read white player name
    n = getline(&linebuf, &len, board);
    setWPlayerName(linebuf);

    // Read black player name
    n = getline(&linebuf, &len, board);
    setBPlayerName(linebuf);

    // Read results
    n = getline(&linebuf, &len, board);
    setResult(linebuf);

    // Read board pieces
    n = getline(&linebuf, &len, board);
    setBoardPieces(linebuf);

    printf("######## %s ########\n\n", EventName);
    
    printf("  White :: %s\n\n", WPlayer);
    int cnt = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; ++j){
            if(cnt % 2) printf("\033[37;41m");
            else printf("\033[41;40m");

            if(Board[i][j] == '.') printf("   ");
            else printf(" %c ", Board[i][j]);
            
            printf("\033[0m");
            cnt++;
        }
        cnt++;
        printf("\n");
    }
    printf("\n  Black :: %s\n", BPlayer);
    printf("\n  Results :: %s\n\n", Result);

    // Read comments start tag
    n = getline(&linebuf, &len, board);
    // Read actual comments
    n = getline(&linebuf, &len, board);
    printPaginatedComments(linebuf);
}

void setEventName(char *lines){
    char *chk = strtok(lines, "\"");
    chk = strtok(NULL, "\"");
    strcpy(EventName, chk);
}

void setWPlayerName(char *lines){
    char *chk = strtok(lines, "\"");
    chk = strtok(NULL, "\"");
    strcpy(WPlayer, chk);
}

void setBPlayerName(char *lines){
    char *chk = strtok(lines, "\"");
    chk = strtok(NULL, "\"");
    strcpy(BPlayer, chk);
}

void setResult(char *lines){
    char *chk = strtok(lines, "\"");
    chk = strtok(NULL, "\"");
    strcpy(Result, chk);
}

void setBoardPieces(char *lines){
    char *chk = strtok(lines, "\"");
    chk = strtok(NULL, "\"");
    
    // filling 8 rows of board
    char *ppl = strtok(chk, "/");
    boardVerifier(ppl);
    boardFiller(ppl, 0);

    ppl = strtok(NULL, "/");
    boardVerifier(ppl);
    boardFiller(ppl, 1);

    ppl = strtok(NULL, "/");
    boardVerifier(ppl);
    boardFiller(ppl, 2);

    ppl = strtok(NULL, "/");
    boardVerifier(ppl);
    boardFiller(ppl, 3);

    ppl = strtok(NULL, "/");
    boardVerifier(ppl);
    boardFiller(ppl, 4);

    ppl = strtok(NULL, "/");
    boardVerifier(ppl);
    boardFiller(ppl, 5);

    ppl = strtok(NULL, "/");
    boardVerifier(ppl);
    boardFiller(ppl, 6);

    ppl = strtok(NULL, "/");
    boardVerifier(ppl);
    boardFiller(ppl, 7);
}

void printPaginatedComments(char *lines){
    printf("######## COMMENTS ########\n");
    char cmnt[1024];
    memset(&cmnt, 0, sizeof(cmnt));
    strcpy(cmnt, lines);
    printf("%s", cmnt);
}

void boardFiller(char *ppl, int r){
    int c = 0;
    while(*ppl != '\0'){
        if(isdigit(*ppl)){
            int rl = atoi(ppl);
            while(rl--){
                Board[r][c] = '.';
                c++;
            }

        }else{
            Board[r][c] = (char)*ppl;
            c++;
        }
        ppl++;
    }
}

void boardVerifier(char *ppl){
    static int pwn, k, q, b, n, r;
    while(*ppl != '\0'){
        if(!isdigit(*ppl)){
            if(*ppl == 'k' || *ppl == 'K') k++;
            if(*ppl == 'q' || *ppl == 'Q') q++;
            if(*ppl == 'b' || *ppl == 'B') b++;
            if(*ppl == 'n' || *ppl == 'N') n++;
            if(*ppl == 'r' || *ppl == 'R') r++;
            if(*ppl == 'p' || *ppl == 'P') pwn++;
        }
        else{
            assert(atoi(ppl) < 9);
        }
        ppl++;
    }
    assert(pwn <= 16);
    assert(k <= 2);
    assert(q <= 2);
    assert(n <= 4);
    assert(b <= 4);
    assert(r <= 4);
}
#include <stdio.h>
#include "tn.h"
#include "glob.h"

int cErrors = 0;
int cLine = 1;

void main()
{
    enum tokentypes tn;
    // 표 머리
	printf("%18s %18s %18s %18s\n","Line number","Token type","ST-index","Token");
	while ((tn=yylex()) != TEOF){
		printtoken(tn);
        if(overflow) break;
	}

    // cErrors 개수 출력
	if (cErrors ==0) {
        printf("No errors detected");
    }
    else {
	printf ("%d errors detected",cErrors);
    }
}

void printtoken(enum tokentypes tn){
    printf("%18s", cLine);
    switch (tn)
    {
    case TCONST:
        printf("Const %18s %18s\n", "",yytext);
        break;
    case TELSE:
        printf("Else %18s %18s\n", "",yytext);
        break;
    case TIF:
        printf("If %18s %18s\n", "",yytext);
        break;
    case TINT:
        printf("Int %18s %18s\n", "",yytext);
        break;
    case TRETURN:
        printf("Return %18s %18s\n", "",yytext);
        break;
    case TVOID:
        printf("Void %18s %18s\n", "",yytext);
        break;
    case TWHILE:
        printf("While %18s %18s\n", "",yytext);
        break;
    //비교연산자
    case TEQUAL:
        printf("Equal %18s %18s\n", "",yytext);
        break;
    case TNOTEQU:
        printf("Not Equal %18s %18s\n", "",yytext);
        break;
    case TLESS :
        printf("Less %18s %18s\n", "",yytext);
        break;
    case TGREAT :
        pirntf("Great %18s %18s\n", "",yytext);
        break;
    case TLESSE:
        printf("Less Equal %18s %18s\n", "",yytext);
        break;
    case TGREATE:
        printf("Great Equal %18s %18s\n", "",yytext);
        break;
    //논리연산자
    case TAND:
        printf("And %18s %18s\n", "",yytext);
        break;
    case TOR:
        printf("Or %18s %18s\n", "",yytext);
        break;
    case TNOT:
        printf("Not %18s %18s\n", "",yytext);
        break;
    
    //증감연산자
    case TINC:
        printf("Increase %18s %18s\n", "",yytext);
        break;
    case TDEC:
        printf("Decrease %18s %18s\n", "",yytext);
        break;

    //대입연산자
    case TADDASSIGN:
        printf("Add Assign %18s %18s\n", "",yytext);
        break;
    case TSUBASSIGN:
        printf("Subscribe Assign %18s %18s\n", "",yytext);
        break;
    case TMULASSIGN:
        printf("Multify Assign %18s %18s\n", "",yytext);
        break;
    case TDIVASSIGN:
        printf("Divide Assign %18s %18s\n", "",yytext);
        break;
    case TMODASSIGN:
        printf("Mod Assign %18s %18s\n", "",yytext);
        break;
    case TASSIGN:
        printf("Assign %18s %18s\n", "",yytext);
        break;

    case TNEWLINE:
        printf("\n");
        break;
    case TIDENT:
        if(overflow){  
            printoverflowError();
            cErrors++;
        }
        else printf("Identifier %18d %18s\n", stindex,yytext);
        break;
    case TNUMBER:
        printf("Number : %18s %18s\n", "",yytext);
        break;

    // 에러처리 
    case TLONGIDERR: printtoolongError(); cErrors++; break;
    case TSWDIGITERR: printillidError(); cErrors++; break;
    case TILLSYMBOLERR: printillspError(); cErrors++; break;
    }
    printf("\n");
}
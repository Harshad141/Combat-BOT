#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>

void main(){

int i,ip=0,m,pp=0,op=0,j,dp=0;
char b[30],operators[30],identifiers[30],constants[30],delimiter[30];

printf("enter the string : ");
scanf("%[^\n]s",&b);
for(i=0;i<strlen(b);i++){

    if(isspace(b[i])){
        continue;
    }
    else if(isalpha(b[i])){
        identifiers[ip] =b[i];
         ip++;
    }
    else if(isdigit(b[i])){
        m=(b[i]-'0');
        i=i+1;
        while(isdigit(b[i])){
            m=m*10 + (b[i]-'0');
            i++;
        }
        i=i-1;
        constants[pp]=m;
        pp++;
    }
     else{
        if(b[i]=='*'){
            operators[op]='*';
            op++;
        }
        else if(b[i]=='-'){
            operators[op]='-';
            op++;
        }
        else if(b[i]=='+'){
            operators[op]='+';
            op++;
        }
         else if(b[i]=='='){
            operators[op]='=';
            op++;
        }
     else{
        if(b[i]=='('){
            delimiter[dp]='(';
            dp++;
        }
        else if(b[i]==')'){
            delimiter[op]=')';
            dp++;
        }    
     }

  }

}
// printing

    printf(" identifiers : ");
     for(j=0;j<ip;j++){
        printf("%c ",identifiers[j]);
     }
    printf("\n constants : ");
     for(j=0;j<pp;j++){
        printf("%d ",constants[j]);
     }
    printf("\n operators : ");
      for(j=0;j<op;j++){
        printf("%c ",operators[j]);
      }
    printf(" delimiters : ");
     for(j=0;j<ip;j++){
        printf("%c ", delimiter[j]);
     }  


}

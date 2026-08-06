#include <stdio.h>
#include <string.h>
char table[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
void encode(char input[]){
    int len=strlen(input);
    int i,j=0;
    char output[1000];
    for(i=0;i<len;i+=3){
        unsigned int value=0;
        int remain=len-i;
        value|=(unsigned char)input[i]<<16;
        if(remain>1) value|=(unsigned char)input[i+1]<<8;
        if(remain>2) value|=(unsigned char)input[i+2];
        output[j++]=table[(value>>18)&63];
        output[j++]=table[(value>>12)&63];
        if(remain>1) output[j++]=table[(value>>6)&63];
        else output[j++]='=';
        if(remain>2)output[j++]=table[value&63];
        else output[j++]='=';
    }
    output[j]='\0';
    printf("%s\n",output);
}

int main(){
    char input[1000];
    fgets(input,1000,stdin);
    input[strcspn(input,"\n")]=0;
    encode(input);
    return 0;
}
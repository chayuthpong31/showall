#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char ID[6];
    char ProductName[100];
    char ProductType[100];
    char DateIn[20];
    int AmountIn;
    char DateOut[20];
    int AmountOut;
    int Remainning;
}info;

void showall(){
    FILE *f = fopen("C:\\Users\\ASUS\\Desktop\\CPE100\\Project\\data.csv","r");
    char str[100] = "";
    info rec;
    char *token;
    char *delim = ",";
    while(fgets(str,sizeof(str),f) != NULL){
        int col = 0;
        token = strtok(str,delim);
        while(token != NULL){
            switch (col)
            {
            case 0:
                strcpy(rec.ID,token);
                break;
            case 1:
                strcpy(rec.ProductName,token);
                break;
            case 2:
                strcpy(rec.ProductType,token);
                break;
            case 3:
                strcpy(rec.DateIn,token);
                break;
            case 4:
                rec.AmountIn = atoi(token);
                break;
            case 5:
                strcpy(rec.DateOut,token);
                break;
            case 6:
                rec.AmountOut = atoi(token);
                break;
            case 7:
                rec.Remainning = atoi(token);
                break;
            }
            col++;
            token = strtok(NULL,delim);
        }
        printf("%5s | %40s | %20s | %10s | %4d | %10s | %4d | %4d\n",rec.ID,
        rec.ProductName,rec.ProductType,rec.DateIn,rec.AmountIn,
        rec.DateOut,rec.AmountOut,rec.Remainning);
    }
    fclose(f);
}

int main(){
    showall();
    return 0;
}
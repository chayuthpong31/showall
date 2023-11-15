#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// create a struct
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

int Arraysize(){
    FILE *f = fopen("C:\\Users\\ASUS\\Desktop\\CPE100\\Project\\data.csv","r");
    int count=0;
    char str[100] = "";
    while(fgets(str,sizeof(str),f) != NULL){
        count++;
    }
    fclose(f);
    return count;
}

void showall(info *rec){
    FILE *f = fopen("C:\\Users\\ASUS\\Desktop\\CPE100\\Project\\data.csv","r");
    char str[100] = "";
    char *token;
    char *delim = ",";
    while(fgets(str,sizeof(str),f) != NULL){
        int col = 0;
        token = strtok(str,delim);
        while(token != NULL){
            switch (col)
            {
            case 0:
                strcpy(rec->ID,token);
                break;
            case 1:
                strcpy(rec->ProductName,token);
                break;
            case 2:
                strcpy(rec->ProductType,token);
                break;
            case 3:
                strcpy(rec->DateIn,token);
                break;
            case 4:
                rec->AmountIn = atoi(token);
                break;
            case 5:
                strcpy(rec->DateOut,token);
                break;
            case 6:
                rec->AmountOut = atoi(token);
                break;
            case 7:
                rec->Remainning = atoi(token);
                break;
            }
            col++;
            token = strtok(NULL,delim);
        }
        printf("%5s | %40s | %20s | %10s | %4d | %10s | %4d | %4d\n",rec->ID,
        rec->ProductName,rec->ProductType,rec->DateIn,rec->AmountIn,
        rec->DateOut,rec->AmountOut,rec->Remainning);
        rec++;
    }
    fclose(f);
}

void addData(info *data){
    FILE *f = fopen("C:\\Users\\ASUS\\Desktop\\CPE100\\Project\\add.csv","a");

    printf("Enter ID: "); scanf("%s",data->ID);
    printf("Enter Product Name: "); scanf("%s",data->ProductName);
    printf("Enter Product Type: "); scanf("%s",data->ProductType);
    printf("Enter Date In: "); scanf("%s",data->DateIn);
    printf("Enter Amount In: "); scanf("%d",&data->AmountIn);
    printf("Enter Date Out: "); scanf("%s",data->DateOut);
    printf("Enter Amount Out: "); scanf("%d",&data->AmountOut);
    printf("Enter Remainning: "); scanf("%d",&data->Remainning);

    fprintf(f,"%s,%s,%s,%s,%d,%s,%d,%d\n",data->ID,data->ProductName
        ,data->ProductType,data->DateIn,data->AmountIn,data->DateOut,
        data->AmountOut,data->Remainning);
        
    printf("------------------------------------\n");
    printf("Add Product Success...\n");
    printf("------------------------------------\n");
    fclose(f);
}

int main(){
    info *rec,data[100];
    rec = data;
    showall(rec);
    addData(rec);
    
    return 0;
}

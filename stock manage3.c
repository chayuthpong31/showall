#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

void showall(info *data){
    FILE *f = fopen("C:\\Users\\ASUS\\Desktop\\CPE100\\Project\\data.csv","r");
    char str[200] = "";
    char *token;
    char *delim = ",";
    while(fgets(str,sizeof(str),f) != NULL){
        int col = 0; 
        token = strtok(str,delim);
        while(token != NULL){
            switch (col)
            {
            case 0:
                strcpy(data->ID,token);
                break;
            case 1:
                strcpy(data->ProductName,token);
                break;
            case 2:
                strcpy(data->ProductType,token);
                break;
            case 3:
                strcpy(data->DateIn,token);
                break;
            case 4:
                data->AmountIn = atoi(token);
                break;
            case 5:
                strcpy(data->DateOut,token);
                break;
            case 6:
                data->AmountOut = atoi(token);
                break;
            case 7:
                data->Remainning = atoi(token);
                break;
            }
            col++;
            token = strtok(NULL,delim);
        }
        printf("%5s | %40s | %20s | %10s | %4d | %10s | %4d | %4d\n",data->ID,
        data->ProductName,data->ProductType,data->DateIn,data->AmountIn,
        data->DateOut,data->AmountOut,data->Remainning);
        data++;
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

void RemoveData(info *data){
    FILE *file,*temp;
    char filename[100]="C:\\Users\\ASUS\\Desktop\\CPE100\\Project\\add.csv"
    ,temp_filename[100]="C:\\Users\\ASUS\\Desktop\\CPE100\\Project\\temp.csv";
    char buffer[200];
    char id[6],name[100];
    int option = 0,delete_line=1,current_line=1;
    bool keep_reading = true;

    file = fopen(filename,"r");
    temp = fopen(temp_filename,"w");

    if (file == NULL || temp == NULL){
        printf("Error opening file(s)\n");
    }

    while(option != 1 && option != 2){
        printf("-----------------------------------------------------------------\n");
        printf("1.ID\n");
        printf("2.Product Name\n");
        printf("Enter option:\n");
        scanf("%d",&option);
    }
    // find the line to remove
    if(option == 1){
        printf("Enter Product ID: "); scanf("%s",id);
        while((strcmp(data->ID,id))){
            delete_line++;
            data++;
        }
        // printf("%s %d\n",data->ID,delete_line);
    
    // find the line to remove
    }else if(option == 2){
        printf("Enter Product Name: "); scanf(" %[^\n]",name);
        while((strcmp(data->ProductName,name)) != 1){
            delete_line++;
            data++;
        }
        // printf("%s %d\n",name,delete_line);
    }
    //remove line
    do{
        fgets(buffer,200,file);
        if(feof(file)) keep_reading = false;
        else if (current_line != delete_line)
            fputs(buffer,temp);

        current_line++;

    }while(keep_reading);
    fclose(file);
    fclose(temp);

    remove(filename);
    rename(temp_filename,filename);
    printf("Remove success...\n");
}

int main(){
    info *rec,data[100];
    rec = data;
    showall(rec);
    //addData(rec);
    RemoveData(rec);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DynamicData{
    int* data;
    int numItems;
    int capacity;
};

void addNewElement(struct DynamicData* xDat, int capacity, int xIn);

int main(){
    char ch[100];
    struct DynamicData* data = malloc(sizeof(struct DynamicData));

    data -> numItems = 0; //Starts with 0 integers
    data -> capacity = 4; //Starts with space for 4 integers
    data -> data = malloc(sizeof(int)*(data -> capacity)); //Creating space in the memory for 4 integers

    printf("Starting with %d elements bytes.\n", data -> capacity*sizeof(int));
    printf("You can start entering integers now, enter \"~\" to stop.\n");
    while(fgets(ch, sizeof(ch), stdin)){
        if(strcmp(ch, "~\n") == 0){
            break;
        }
        int val = atoi(ch);
        addNewElement(data, data -> capacity, val);
    }

    
    printf("\n");
    printf("Resized to %d bytes.\n", data -> capacity*sizeof(int));
    for(int i = 0; i < data -> numItems; i++){
        printf("%d, ", data -> data[i]);
    }
    printf("\n");
    free(data);
}

void addNewElement(struct DynamicData* xDat, int capacity, int xIn){
    int newcapacity;
    int* tmp;
    if(xDat -> numItems == xDat -> capacity){
        newcapacity = capacity + sizeof(int)*2;
    }else{
        newcapacity = capacity;
    }
    tmp = realloc(xDat -> data, sizeof(int)*(newcapacity));
    tmp[xDat -> numItems] = xIn;
    xDat -> data = tmp;
    xDat -> numItems += 1;
    xDat -> capacity += 1;
}
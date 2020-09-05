/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int a;
    struct Node** l;
    int len;
}Node;

Node* newNode(void){
    return NULL;
}
Node* add( Node** lis, int c, int len){
    Node* b=( Node*) malloc(sizeof(Node));
    if (b==NULL){
        return NULL;
    }
    b->a=c;
    b->l=lis;
    b->len=len;
    return b;
}
void clean(Node* a){
    if (a!=NULL){
        int number=a -> len;
        Node** lis=a->l;
        for (int i=0; i<number; i++){
            clean(lis[i]);
        }
        free(a);
        printf("Cleand");
    }
}
int main(){
    Node* thing=newNode();
    Node** things=malloc(2*sizeof(Node*));
    things[0]=thing;
    things[1]=thing;
    Node* thing2=add(thing, 3, 2);
    clean(thing2);
    return 0;
}

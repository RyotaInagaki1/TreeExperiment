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
void PreOrder(Node* a){
    if (a!=NULL){
        int number=a -> len;
        Node** lis=a->l;
        printf("%d\n", a->a);
        for (int i=0; i<number; i++){
            PreOrder(lis[i]);
        }
    }
}
int main(){
    Node* thing=newNode();
    Node** things=malloc(2*sizeof(Node*));
    things[0]=thing;
    things[1]=thing;
    Node* thing2=add(things, 3, 2);
    Node** things2=malloc(2*sizeof(Node*));
    things2[0]=thing;
    things2[1]=thing;
    Node* thing3=add(things, 4, 2);
    Node** things3=malloc(2*sizeof(Node*));
    things3[0]=thing2;
    things3[1]=thing3;
    Node* thing4=add(things3, 5, 2);
    PreOrder(thing4);
    clean(thing4);
    return 0;
}

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
        printf("Cleand\n");
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
    Node** cosas=malloc(0);
    Node* thing=add(cosas, 22,0);
    Node* c1=add(cosas, 25, 0);
    Node* c2=add(cosas, -12, 0);
    Node* c3=add(cosas, 26, 0);
    Node* c4=add(cosas, 27, 0);
    Node** things[2];
    things[0]=c3;
    things[1]=c4;
    Node* thing2=add(things, 3, 2);
    Node** things2[2];
    things2[0]=c1;
    things2[1]=c2;
    Node* thing3=add(things2, 4, 2);
    Node** things3[2];
    things3[0]=thing2;
    things3[1]=thing3;
    Node* thing4=add(things3, 5, 2);
    PreOrder(thing4);
    clean(thing4);
    return 0;
}

#ifndef DLIST_h
#define DLIST_h
typedef struct DNode{
//float taille;	
struct DNode *next;
struct DNode *prev;
void *data;
}DNode;
typedef struct DList{
	struct DList *head;
	struct DList *tail;
}DList;	

#endif
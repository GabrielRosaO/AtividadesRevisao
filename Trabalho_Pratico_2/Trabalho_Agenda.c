
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void *pbuffer=NULL;
void *headContacts=NULL;



void CrateHead(void);
void CreateNewNode(void *head);
void DeleteName(void *head);
int Pop( void *deleted, void *befItem, void *nextItem);
void SearchContact(void *head);
void ListContacts(void *head);

void menu(void *pbuffer);

int main(){
    pbuffer=malloc( sizeof(int) + sizeof(int) + sizeof(int) + 10 * sizeof(char));
    *(int*)( pbuffer + sizeof(int) ) = ( sizeof(void *) + ( 10 * sizeof(char) ) + sizeof(int) + sizeof(int) );
    CrateHead();
    for(;;){
        menu( pbuffer );
        switch ( *(int*)pbuffer ){
            case 1:
                CreateNewNode( headContacts );
                break;
            case 2:
                DeleteName( headContacts );
                break; 
            case 3:
                SearchContact( headContacts );
                break;
            case 4:
                ListContacts( headContacts );
                break;
            case 5:
                exit( 0 );
        }
    }
}

void menu( void  *pbuffer ){
    do{
        printf("Insert an option:\n");
        printf("1- Add person\n");
        printf("2- Delete person\n");
        printf("3- Search\n");
        printf("4- List people\n");
        printf("5- exit\n");
        scanf("%d", (int *)pbuffer );
    }while( *(int *)pbuffer < 0 && *(int *)pbuffer > 6 );
}


void CrateHead( void ){
    headContacts=realloc( headContacts, sizeof(void *) + sizeof(void *) );
    *(void**)headContacts = NULL;
    *(void**)( headContacts + sizeof(void *) ) = NULL;
}

void CreateNewNode( void * head ){
    void *newContactsNode=malloc( sizeof(void *) + ( 10 * sizeof(char)) + sizeof(int) + sizeof(int) + sizeof(void*) );
    void *currentItemList;
    printf("Insert the new persons name:");
    scanf("%s",(char *)( newContactsNode + sizeof(void *) ) );
    printf("Insert the age:");
    scanf("%d",(int *)( newContactsNode + sizeof(void *) + ( 10 * sizeof(char) ) ) );
    printf("Insert the cel:");
    scanf("%d",(int *)( newContactsNode + sizeof(void *) + ( 10 * sizeof(char) ) + sizeof(int) ) );
    if(*( void** )( head + sizeof(void *) ) == NULL ){
        *( void** )( head + sizeof(void *) ) = newContactsNode;
        *( void** )( newContactsNode ) = head;
        *( void** )( newContactsNode + sizeof(void *) + ( 10 * sizeof(char) ) + sizeof(int) + sizeof(int) ) = NULL;
    }
    else{
        for( currentItemList = *(void **)( head + sizeof(void *) ); currentItemList != NULL; currentItemList = *(void **)( currentItemList + sizeof(void *) + ( 10 * sizeof(char) ) + sizeof(int) + sizeof(int) )){
            if ( strcmp( (char *)( newContactsNode + sizeof(void *) ),(char *)( currentItemList + sizeof(void *) ) ) < 0){
                *( void** )(newContactsNode + *(int*)( pbuffer + sizeof(int) ) ) = currentItemList;
                *( void** )newContactsNode = currentItemList;
                *( void** )(currentItemList + *(int*)( pbuffer + sizeof(int) ) ) = NULL;
                *( void** )currentItemList = newContactsNode;
            }
            else{
                *( void** )(currentItemList + sizeof(void *) + ( 10 * sizeof(char) ) + sizeof(int) + sizeof(int) ) = newContactsNode;
                *( void** )(newContactsNode + sizeof(void *) + ( 10 * sizeof(char) ) + sizeof(int) + sizeof(int) ) = NULL;
                *( void** )newContactsNode = currentItemList;
                break;
            }
        }
    }
}

void DeleteName(void *head){
    void *currentItemList;
    printf("Insert the name you want to delete: ");
    scanf("%s",(char *)(pbuffer + sizeof(int) + sizeof(int) ) );
    for(currentItemList = *(void **)( head + sizeof(void *) ); currentItemList != NULL; currentItemList = *(void **)( currentItemList + sizeof(void *) + ( 10 * sizeof(char) ) + sizeof(int) + sizeof(int) )){
        if( strcmp( (char *)( pbuffer + sizeof(int) + sizeof(int)), (char *)currentItemList + sizeof(void) ) == 0){
            *(int *)( pbuffer + sizeof(int) + sizeof(int)) = Pop( currentItemList, (void*)currentItemList, (void*)( currentItemList + *(int*)pbuffer ) );
            if( *(int *)( pbuffer + sizeof(int) + sizeof(int) ) == 0){
                printf("Name: %s\n",(char *)( currentItemList + sizeof(void*) ) );
                printf("Age: %d\n",*(int *)( currentItemList + sizeof(void*) + ( 10  *sizeof(char) ) ) );
                printf("Contact: %d\n",*(int *)( currentItemList + sizeof(void*) + ( 10 * sizeof(char) ) + sizeof(int) ) );
            }
        }
    }

}

int Pop( void *deleted, void *befItem, void *nextItem){
    if( befItem == NULL ){
        printf( "Empty List!" );
        return 0;
    } else {
        *(void**)nextItem = ( void * )deleted;
        *(void**)( befItem + *( int * )pbuffer ) = nextItem;
    }

    free( deleted );
    return 1;

}

void SearchContact( void * head ){
    void *currentItemList;
    printf("Insert the name you want: ");
    scanf("%s", (char *)( pbuffer + sizeof(int) + sizeof(int) ) );
    for(currentItemList = *( void ** )( head + sizeof(void *) ); currentItemList != NULL; currentItemList = *(void **)( currentItemList + sizeof(void *) + ( 10 * sizeof(char) ) + sizeof(int) + sizeof(int) ) ){
        if ( strcmp( (char *)( pbuffer + sizeof(int) + sizeof(int) + sizeof(int) ), (char *)currentItemList + sizeof(void) ) == 0){     
            *(int *)( pbuffer + sizeof(int) + sizeof(int) ) = Pop( currentItemList, (void*)currentItemList, (void*)( currentItemList + *(int *)pbuffer ) );
            if ( *(int *)( pbuffer + sizeof(int) + sizeof(int) ) == 0){
                printf("Name: %s\n",(char *)(currentItemList + sizeof(void *) ) );
                printf("Age: %d\n",*(int *)( currentItemList + sizeof(void *) + ( 10  *sizeof(char) ) ) );
                printf("Contact: %d\n",*(int *)( currentItemList + sizeof(void *) +( 10 * sizeof(char) ) + sizeof(int) ) );     
            printf("Name: %s\n",(char *)( currentItemList + sizeof(void *) ) );
            printf("Age: %d\n",*(int *)( currentItemList + sizeof(void *) + ( 10 * sizeof(char) ) ) );
            printf("Contact: %d\n",*(int *)( currentItemList + sizeof(void *) + ( 10 * sizeof(char) ) + sizeof(int) ) );
            }
        }
    }
}


void ListContacts(void *head){
    void *currentItemList;
    for(currentItemList = *(void **)( head + sizeof(void *) ); currentItemList != NULL; currentItemList = *(void **)( currentItemList + sizeof(void *) + ( 10 * sizeof(char) ) + sizeof(int) + sizeof(int) )){
        printf("Name: %s\n",(char *)( currentItemList + sizeof(void *) ) );
        printf("Age: %d\n",*(int *)( currentItemList + sizeof(void * ) + ( 10 * sizeof(char) ) ) );
        printf("Contact: %d\n",*(int *)( currentItemList + sizeof(void *) + ( 10 * sizeof(char) ) + sizeof(int) ) );
    }
}




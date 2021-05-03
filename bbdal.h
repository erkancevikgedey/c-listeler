//bbdal.h
//bir baðli dairesel liste
#include <iostream>
#include <conio.h>
#include<stdio.h>  
#include<stdlib.h>  
#include <time.h> 
using namespace std;

//node yapýsýný tanýmla -------------------------------------------------------
struct node
       {
       int data;
       node* link;
       };
       
//programda kullanýlacak listeleri tanýmla ------------------------------------       
node* list=NULL;
node* l1=NULL;
node* l2=NULL;

//01+---------------------------------------------------------------------------
//list listesini ekrana listele
void dumplist(node* list)
{
if(list!=NULL)   //eklendi
 {
int i=1;
node* ylist=list;
do{
   	     cout<< "Listenin "<<i++<<".Nodunun Adresi= "<<list
                                                           <<" Datasi= "<<list->data
                                                           <<" Linki= "<<list->link<<endl;
   	     list=list->link;
  	     }while(list!=ylist);
  }
}

//02+---------------------------------------------------------------------------
//hafýzadan yeni bir node al
node* newnode()
{
node* newnode=new node;
newnode->link=newnode;
return(newnode);
}

//03+---------------------------------------------------------------------------
//list listesinin son nodunu bul
node* last(node* list)
{
if(list!=NULL){
               node* ylist=list;      
               while(list->link!=ylist)
                    list=list->link;     
              }
node* last=list;                    
return(last);      
}
 
//04+--------------------------------------------------------------------------
//list listesinin baþýna node_ nodunu ekle
void addhead(node* node_, node*& list) 
{
if(node_!=NULL)                //eklendi
if(list==NULL)list=node_;
          else {node_->link=list;
                last(list)->link=node_;
                list=node_;
                }
}
//05+---------------------------------------------------------------------------
//l1 listesinin sonuna l2 listesini ekle
void concatenate(node*& l1, node* l2)
{
if(l2!=NULL)
if(l1==NULL) l1=l2;
           else {
                last(l1)->link=l2;
                last(l2)->link=l1;
                }
}
//06+---------------------------------------------------------------------------
//yeni bir node'un data'sýna data_ deðerini ata
node* cons(int data_) 
{
node* cons_;
cons_=newnode();
cons_->data=data_;
return(cons_);
}
//07+---------------------------------------------------------------------------
//list listesinin kopyasýný oluþtur
node* copy(node* list)
{
node* suret=NULL;
node* ylist=list;
if(list!=NULL)do{
                 concatenate(suret,cons(list->data));
                 list=list->link;
                 }while(list!=ylist);
return(suret);
}
//08+---------------------------------------------------------------------------
//list listesinde data'sý data_ olan node varsa adresini al
node* locate(int data_, node* list) 
{
node* locate=NULL;
if(list!=NULL){
               node* ylist=list;
               do{               
                  if(list->data!=data_) list=list->link;
                                 else {
                                       locate=list;                 
                                       break;
                                      }
                 }while(list!=ylist);                          
               }
return(locate);                           
}

//09---------------------------------------------------------------------------
//list listesinde node_ adresli node varmi
bool member(node* node_, node* list)
{
while(list!=NULL && list!=node_)
list=list->link;
bool member=(list==node_);
return(member);
}

//10---------------------------------------------------------------------------
//list listesinin ilk nodunu kes
void cuthead(node*& head)
{  
    struct node *ptr;  
    if(head == NULL){  
        printf("\nsilindi\n");      
    }else if(head->link == head){  
        head = NULL;  
        free(head);  
        printf("\nsilindi\n");   
    }else{     
        ptr = head;   
        while(ptr -> link != head){
        	ptr = ptr -> link;
		}     
        ptr->link = head->link;  
        free(head);  
        head = ptr->link;  
        printf("\nsilindi\n");   
    }  
}  

//11---------------------------------------------------------------------------
//list listesini iptal et
void free(node*& list)
{
delete list;//sor!
}

//12---------------------------------------------------------------------------
//adresi point olan node'dan sonra bir node varsa poin'i ilerlet
bool advance(node*& point)
{
bool advance=false;
if((point!=NULL)&&(point->link!=NULL)){
 point=point->link;
 advance=true;
}
return(advance);
}

int Length(struct node* head)
{
    struct node* current = head;
    int count = 0;
    if (head == NULL) {
        return 0;
    }
    else {
        do {
            current = current->link;
            count++;
        } while (current != head);
    }
    return count;
}
//13---------------------------------------------------------------------------
//list listesinde node_ adresli node varsa bul ve sil
void deletenode(node* head, int index)
{
    int len = Length(head);
    int count = 1;
    struct node *previous = head, *next =head;
    while (len > 0) {
        if (index == count) {
            previous->link = next->link;
            free(next);
            return;
        }
        previous = previous->link;
        next = previous->link;
        len--;
        count++;
    }
    return;
}

void liste_yap(node*& list, int count){
	int random;
	srand (time(NULL));
	for(int a=0;a<count;a++){
		random = rand() % 451 + 50;
		addhead(cons(random),list);
	}
}

node* terstensirala(node* list){
	node* newList = NULL;
	int i=1;
	node* ylist=list;
	do{
   	     addhead(cons(list->data),newList);
   	     list=list->link;
	}while(list!=ylist);
	return newList;
}


void datatopla(node* list, int sira, int& toplam, node* son){
	if(list != NULL && list != son){
		if(sira % 2 == 1){
			toplam = toplam + list->data;
			sira++;
			datatopla(list->link, sira, toplam, son);
		}else{
			sira++;
			datatopla(list->link, sira, toplam, son);
		}
	}else if(list == son && son != NULL){
		if(sira % 2 == 1){
			sira++;
			toplam = toplam + list->data;
		}
		
	}
	
}


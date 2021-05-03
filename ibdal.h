//ibdal.h
//iki baðli dairesel liste
#include <iostream>
#include <conio.h>
#include <bits/stdc++.h>
using namespace std;

//node yapýsýný tanýmla *-------------------------------------------------------
struct node
       {
       int data;
       node* blink;
       node* flink;
       };
       
//programda kullanýlacak listeleri tanýmla *------------------------------------       
node* list=NULL;
node* l1=NULL;
node* l2=NULL;

//01*----------------------------------------------------------
//list listesini ekrana listele
void dumplist(node* list)
{
int i=1;
node* ylist=list;
if(list!=NULL)do{
                 cout<< "Listenin "<<i++<<".Nodunun Adresi= "<<list
                                                                         <<" Datasi= "<<list->data
                                                                        <<" BLinki= "<<list->blink
                                                                        <<" FLinki= "<<list->flink<<endl;
                 list=list->flink;
                }while(list!=ylist);
}

//02*---------------------------------------------------------------------------
//hafýzadan yeni bir node al
node* newnode()
{
node* newnode=new node;
newnode->blink=newnode;
newnode->flink=newnode;
return(newnode);
}

//03*---------------------------------------------------------------------------
//list listesinin son nodunu bul
node* last(node* list)
{
node* last=NULL;
if(list!=NULL)last=list->blink;
return(last);      
}
 
//04*---------------------------------------------------------------------------
//list listesinin baþýna node_ nodunu ekle
void addhead(node* node_, node*& list) 
{
if(list!=NULL){node* ydk;
               ydk=last(list);
               node_->flink=list;
               list->blink=node_;
               node_->blink=ydk;
               ydk->flink=node_;//cout<<"+";
              }
list=node_;
}

//05*---------------------------------------------------------------------------
//l1 listesinin sonuna l2 listesini ekle
void concatenate(node*& l1, node* l2)
{
if(l2!=NULL)
if(l1==NULL) l1=l2;
           else {
                node* ydk=last(l2);
                l2->blink=last(l1);
                last(l1)->flink=l2;
                l1->blink=ydk;//incele
                ydk->flink=l1;
                }
}

//06*---------------------------------------------------------------------------
//yeni bir node'un data'sýna data_ 
node* cons(int data_) 
{
node* cons_;
cons_=newnode();
cons_->data=data_;
return(cons_);
}

//07*---------------------------------------------------------------------------
//list listesinin kopyasýný oluþtur
node* copy(node* list)
{
node* suret=NULL;
node* ylist=list;
if(list!=NULL)do{
                 concatenate(suret,cons(list->data));
                 list=list->flink;
                 }while(list!=ylist);
return(suret);
}

//08*---------------------------------------------------------------------------
//list listesinde data'sý data_ olan node varsa adresini al
node* locate(int data_, node* list) 
{
	node* locate=NULL;
	while(list!=NULL)
	if(list->data!=data_) list=list->flink;
	else {
		locate=list; 
		break;
	}
	return(locate); 
}

//09*---------------------------------------------------------------------------
//list listesinde node_ adresli node varmý
bool member(node* node_, node* list)
{
	while(list!=NULL && list!=node_)
	list=list->flink;
	bool member=(list==node_);
	return(member); 
}

//10*---------------------------------------------------------------------------
//list listesinin ilk nodunu kes
void cuthead(node*& list)  
{  
    struct node *temp;  
    if(list == NULL)  
    {  
        printf("\n list bos\n");  
    }else if(list->flink == list){  
        list = NULL;   
        free(list);  
        printf("\nveri silindi\n");  
    }else{  
        temp = list;   
        while(temp -> flink != list){  
            temp = temp -> flink;  
        }  
        temp -> flink = list -> flink;  
        list -> flink -> blink = temp;  
        free(list);  
        list = temp -> flink;  
        printf("\nveri silindi\n");  
    }
}  

//11*---------------------------------------------------------------------------
//list listesini iptal et
void freeF(node*& list)
{
	if(list != NULL) {
	    node *temp, *current;
	    current = list->flink;
	    while(current != list) {
	      temp = current->flink;
	      free(current);
	      current = temp;
	    }
	    free(list);
	    list = NULL;
  }
}

//12*---------------------------------------------------------------------------
//adresi point olan node'dan sonra bir node varsa poin'i ilerlet
bool advance(node*& point)
{
	bool advance=false;
	if((point!=NULL)&&(point->flink!=NULL)){
		 point=point->flink;
		 advance=true;
	}
	return(advance);
}

//13*---------------------------------------------------------------------------
//listeden veri sil
void deletenode(struct node** start, int key)
{
    if (*start == NULL)
        return;
    struct node *curr = *start, *prev_1 = NULL;
    while (curr->data != key) {
        if (curr->flink == *start) {
            printf("\nlistede bu veri yok: %d", key);
            return;
        }
        prev_1 = curr;
        curr = curr->flink;
    }
    if (curr->flink == *start && prev_1 == NULL) {
        (*start) = NULL;
        free(curr);
        return;
    }
    if (curr == *start) {
        prev_1 = (*start)->blink;
        *start = (*start)->flink;
        prev_1->flink = *start;
        (*start)->blink = prev_1;
        free(curr);
    }
    else if (curr->flink == *start) {
        prev_1->flink = *start;
        (*start)->blink = prev_1;
        free(curr);
    }
    else {
        struct node* temp = curr->flink;
        prev_1->flink = temp;
        temp->blink = prev_1;
        free(curr);
    }
}

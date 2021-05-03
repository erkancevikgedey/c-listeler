//bbdol.h
//bir baðli doðrusal liste
#include <iostream>
#include <conio.h>
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

//01---------------------------------------------------------------------------
//list listesini ekrana listele
void dumplist(node* list)
{
int i=1;

while(list!=NULL)
     {
     cout<< "Listenin "<<i++<<".Nodunun Adresi= "<<list
                                    <<" Datasi= "<<list->data
                                    <<" Linki= "<<list->link<<endl;
     list=list->link;
     }
}
//02---------------------------------------------------------------------------
//hafýzadan yeni bir node al
node* newnode()
{
node* newnode=new node;
newnode->link=NULL;
return(newnode);
}
//03---------------------------------------------------------------------------
//list listesinin son nodunu bul
node* last(node* list, node* link)
{
if(list!=NULL)      
if(link->link!=NULL){
	last(list, list->link);   
}else{
	node* last=list->link;
	return(last);   
}
   
}
//04---------------------------------------------------------------------------
//list listesinin baþýna node_ nodunu ekle
void addhead(node* node_, node*& list) 
{
node_->link=list;
list=node_;
}
 

//06---------------------------------------------------------------------------
//yeni bir node'un data'sýna data_ deðerlerini ata 
node* cons(int data_)
{
node* cons_;
cons_=newnode();
cons_->data=data_;
return(cons_);
}

//08---------------------------------------------------------------------------
//list listesinde data'sý data_ olan node varsa adresini al
node* locate(int data_, node* list) 
{
node* locate=NULL;
while(list!=NULL)
     if(list->data!=data_) list=list->link;
                      else {
                           locate=list;                 
                           break;
                           }
return(locate);                           
}
//09---------------------------------------------------------------------------
//list listesinde node_ adresli node varmý
bool member(node* node_, node* list)
{
while(list!=NULL && list!=node_)
list=list->link;
bool member=(list==node_);
return(member);     
}
//10---------------------------------------------------------------------------
//list listesinin ilk nodunu kes
node* cuthead(node*& list)
{
node* cuthead=list;
if (list!=NULL){
                list=list->link;
                cuthead->link=NULL;
                }
return(cuthead);
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
//13---------------------------------------------------------------------------
//list listesinde node_ adresli node varsa bul ve sil


void datatopla(node* list, int sira, int& toplam){
	if(list != NULL){
		if(sira % 2 == 1){
			toplam = toplam + list->data;
			sira++;
			datatopla(list->link, sira, toplam);
		}else{
			sira++;
			datatopla(list->link, sira, toplam);
		}
	}
}

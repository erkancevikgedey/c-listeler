//-----------------------------------------------------------------------------
//Ana program
#include <iostream>
#include <conio.h>
#include "bbdal.h"
using namespace std;

main(){
	node* newList = NULL;
  	liste_yap(newList, 5);
  	dumplist(newList);

  	int toplamKac = 0;
  	datatopla(newList, 1, toplamKac, last(newList));
  	
  	
  	cout << "Gonderilen listedeki tek sayili node data toplamlari: "<< toplamKac;
  	

  	
	getch();
	return 0;
}


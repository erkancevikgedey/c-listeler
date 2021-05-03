//-----------------------------------------------------------------------------
//Ana program
#include <iostream>
#include <conio.h>
#include "bbdol.h"
using namespace std;


 main()
   {
   	
	 addhead(cons(48),l2);
    addhead(cons(54),l2);
    addhead(cons(24),l2);
    addhead(cons(63),l2); //cons*& gerekiyor
    dumplist(l2);

	int toplamKac = 0;
  	datatopla(l2, 1, toplamKac);
  	
  	
  		cout << "Gonderilen listedeki tek sayili node data toplamlari: "<< toplamKac;
  	
 	return 0;
   }
 


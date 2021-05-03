//-----------------------------------------------------------------------------
//Ana program
#include <iostream>
#include <conio.h>
#include "ibdal.h"
using namespace std;
 main()
   {
        
    addhead(cons(64),l2);
    addhead(newnode(),l2);
    addhead(cons(55),l2);
	addhead(cons(48),l2);
    
    dumplist(l2);
    
    deletenode(&l2, 55);
    
    dumplist(l2);

	
  
	 return 0;
   }

#include <allegro.h>
#include <stdio.h>
#include "ds_header.h"
/*----------------------------------------------------------------------------------*
 Damian Ratajski   NR 248053                                                        *
 Z racji limitu 1MB na KNO, kilka bitmap z folderu bmp
 znajduj¹ siê pod adresem: http://www.sendspace.pl/file/f305fb3d34bb12bdb9dd8f1

                                                                                    *
*-----------------------------------------------------------------------------------*/
int main()
{
	a_init();

	while (!key[KEY_ESC])
	{
        menu_g();
	};
	a_deinit();
	return 0;
}
END_OF_MAIN()

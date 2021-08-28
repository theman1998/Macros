#include "KeysDefine.h"

unsigned int getKeyValue(char key)
{

	if (key >= 97 && key <= 127)
	{
		//a starts at 65 for key bindings
		return (key - 32);
	}




	return 0;








}


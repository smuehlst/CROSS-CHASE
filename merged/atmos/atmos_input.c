/* --------------------------------------------------------------------------------------- */ 
// 
// CROSS CHASE by Fabrizio Caruso
//
// Fabrizio_Caruso@hotmail.com
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from
// the use of this software.

// Permission is granted to anyone to use this software for non-commercial applications, 
// subject to the following restrictions:

// 1. The origin of this software must not be misrepresented; you must not
// claim that you wrote the original software. If you use this software in
// a product, an acknowledgment in the product documentation would be
// appreciated but is not required.

// 2. Altered source versions must be plainly marked as such, and must not
// be misrepresented as being the original software.

// 3. This notice may not be removed or altered from any source distribution.
/* --------------------------------------------------------------------------------------- */ 

#include <peekpoke.h>
#include "atmos_input.h"

unsigned char GET_CHAR(void)
{
	unsigned char polledValue = PEEK(0x208);

	switch(polledValue)
	{
		case 141:
			return 'I';
		break;
		case 129:
			return 'J';
		break;
		case 131:
			return 'K';
		break;
		case 143:
			return 'L';
		break;
		case 132:
			return ' ';
		break;
	}
	return '\0';
}
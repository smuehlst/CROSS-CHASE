/*****************************************************************************/
/*                                                                           */
/*                                		                                     */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/* (C) 2017      Fabrizio Caruso                                  		     */
/*                					                                         */
/*              				                                             */
/* EMail:        Fabrizio_Caruso@hotmail.com                                 */
/*                                                                           */
/*                                                                           */
/* This software is provided 'as-is', without any expressed or implied       */
/* warranty.  In no event will the authors be held liable for any damages    */
/* arising from the use of this software.                                    */
/*                                                                           */
/* Permission is granted to anyone to use this software for any purpose,     */
/* including commercial applications, and to alter it and redistribute it    */
/* freely, subject to the following restrictions:                            */
/*                                                                           */
/* 1. The origin of this software must not be misrepresented; you must not   */
/*    claim that you wrote the original software. If you use this software   */
/*    in a product, an acknowledgment in the product documentation would be  */
/*    appreciated but is not required.                                       */
/* 2. Altered source versions must be plainly marked as such, and must not   */
/*    be misrepresented as being the original software.                      */
/* 3. This notice may not be removed or altered from any source              */
/*    distribution.                                                          */
/*                                                                           */
/*****************************************************************************/

#ifndef _INPUT_MACROS
#define _INPUT_MACROS

	#include "character.h"

	
	#if defined(__CBM610__) || !(defined(__CBM__) || defined(__ATARI__) || defined(__ATARIXL__) || defined(__APPLE2__) || defined(__APPLE2ENH__)) 
	#else
		#include <joystick.h>
	#endif

	#if defined(__SPECTRUM__)
		#include "patch/z88dk_conio_implementation.h"
	#else
		#include <conio.h>
	#endif 
	
	#if defined(__ATMOS__)
		#include "atmos/atmos_input.h"
	// #elif defined(__AQUARIUS__)
		// #include "aquarius/aquarius_input.h"
	#endif


	#if (defined (__CBM__) && !defined(__CBM610__)) || defined(__ATARI__) || defined(__ATARIXL__)
		#define JOY_INSTALL() { joy_install(joy_static_stddrv); };
		#define GET_JOY1() joy_read (JOY_1);
		#define INIT_INPUT() JOY_INSTALL(); 
	#else
		#define INIT_INPUT()
	#endif
				
	// Move player
	void WAIT_PRESS(void);
	
	#if !defined(__CBM__) && !defined(__ATARI__) && !defined(__ATARIXL__) && !defined(__ATARI5200__) && !defined(__MSX__)
		void movePlayerByKeyboard(unsigned char kbInput);
	#elif defined(__CBM610__)
		void movePlayerByKeyboard(unsigned char kbInput);
	#elif defined(__MSX__)
		void movePlayerByKeyboard(unsigned char joyInput); // joystick and built-in keyboard arrows
	#else // All CBM except CBM610 + ATARI + ATARI XL
		void movePlayerByJoystick(unsigned char joyInput);
	#endif

	void MOVE_PLAYER(void);
#endif // _INPUT_MACROS
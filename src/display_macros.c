/* --------------------------------------------------------------------------------------- */ 
// 
// CROSS CHASE by Fabrizio Caruso
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
 
#include "display_macros.h"

unsigned char powerUpBlink = 0;
unsigned char gunBlink = 0;	
unsigned char extraPointsBlink = 0;
unsigned char extraLifeBlink = 0;	
unsigned char invincibilityBlink = 0;
unsigned char playerBlink = 0;	
	

Image PLAYER_IMAGE;
Image GHOST_IMAGE;
Image DEAD_GHOST_IMAGE;
Image INVINCIBLE_GHOST_IMAGE;
Image BOMB_IMAGE;
Image POWERUP_IMAGE;
Image MISSILE_IMAGE;
Image GUN_IMAGE;

#if defined(FULL_GAME)
	Image LEFT_ENEMY_MISSILE_IMAGE;
	Image RIGHT_ENEMY_MISSILE_IMAGE;

	Image BUBBLE_IMAGE;

	Image EXTRA_POINTS_IMAGE;
	Image EXTRA_LIFE_IMAGE;
	Image INVINCIBILITY_IMAGE;	
	
	Image BROKEN_WALL_IMAGE;
#endif

#if defined(__VG5K__)
	//
#elif defined(__C64__) && defined(REDEFINED_CHARS)
	// 
#elif defined(__ATMOS__) && defined(REDEFINED_CHARS)
	// 
#elif (defined(__ATARI__) || defined(__ATARIXL__)) && defined(ATARI_MODE1) && defined(REDEFINED_CHARS)
	// 
#elif (defined(__C16__)   || defined(__PLUS4__))   && defined(REDEFINED_CHARS)
	// 
#elif defined(__C128__) && defined(C128_80COL_VIDEO_MODE)
	// 
#elif defined(__SPECTRUM__)
	//	
#elif defined(__MSX__) && defined(REDEFINED_CHARS)
	// 
#elif defined(__MSX__) && !defined(MSX_MODE1)
	//
#elif defined(__SVI__) && defined(MSX_MODE0)
	//
#elif defined(__CPC__)
	//
#elif defined(__NES__) && defined(NES_COLOR)
	//	
#elif defined(__ZX80__) || defined(__ZX81__) || defined(__ACE__) || defined(__LAMBDA__)
	//
#else
	void INIT_GRAPHICS() {}
	
	void INIT_IMAGES(void)
	{		
		#if defined(COLOR)
			PLAYER_IMAGE._color = COLOR_CYAN;
			INVINCIBLE_GHOST_IMAGE._color = COLOR_YELLOW;
			POWERUP_IMAGE._color = COLOR_GREEN;
			GUN_IMAGE._color = COLOR_BLUE;
			BOMB_IMAGE._color = COLOR_RED;
			DEAD_GHOST_IMAGE._color = COLOR_RED;

			#if defined(FULL_GAME)
				EXTRA_POINTS_IMAGE._color = COLOR_YELLOW;			
				EXTRA_LIFE_IMAGE._color = COLOR_BLUE;
				INVINCIBILITY_IMAGE._color = COLOR_YELLOW;		
			#endif		
		#endif
			
		GHOST_IMAGE._imageData = 'o';
		INVINCIBLE_GHOST_IMAGE._imageData = '+';
		BOMB_IMAGE._imageData = 'X';
		PLAYER_IMAGE._imageData = '*';
		POWERUP_IMAGE._imageData = 'S';
		GUN_IMAGE._imageData = '!';
		MISSILE_IMAGE._imageData = '.';
		
		#if defined(__APPLE2ENH__) || defined(__PET__) || defined(__CBM610__) || defined(__ATARI__) || defined(__ATARIXL__) 			
			DEAD_GHOST_IMAGE._imageData = 'O';
		#elif defined(__APPLE2__) 
			DEAD_GHOST_IMAGE._imageData = '#';
		#elif defined(__ZX81__) || defined(__LAMBDA__) || defined(__ZX80__) || defined(__ACE__) 
			DEAD_GHOST_IMAGE._imageData = 'x';	
		#elif defined(__VZ__) || defined(__CMOC__)
			DEAD_GHOST_IMAGE._imageData = '#';				
		#elif defined(NO_COLOR)
			DEAD_GHOST_IMAGE._imageData = '_';		 
		#else
			DEAD_GHOST_IMAGE._imageData = 'o';
		#endif

		#if !defined(NO_COLOR)
			GHOST_IMAGE._color = COLOR_WHITE;
			MISSILE_IMAGE._color = COLOR_WHITE;
		#endif
		
		#if defined(FULL_GAME)
			#if !defined(NO_COLOR)
				LEFT_ENEMY_MISSILE_IMAGE._color = COLOR_WHITE;
				RIGHT_ENEMY_MISSILE_IMAGE._color = COLOR_WHITE;
				BUBBLE_IMAGE._color = COLOR_WHITE;	
				BROKEN_WALL_IMAGE._color = COLOR_RED;		
			#endif
			LEFT_ENEMY_MISSILE_IMAGE._imageData = '>';
			RIGHT_ENEMY_MISSILE_IMAGE._imageData = '<';
		
			BUBBLE_IMAGE._imageData = '^';
			
			EXTRA_POINTS_IMAGE._imageData = '$';
		
			EXTRA_LIFE_IMAGE._imageData = PLAYER_IMAGE._imageData;

			INVINCIBILITY_IMAGE._imageData = 'V';

			BROKEN_WALL_IMAGE._imageData = 'X';
		#endif
	}

	#if defined(FULL_GAME)
		void DRAW_BROKEN_WALL(unsigned char x, unsigned char y)
		{
			gotoxy((x+X_OFFSET),(y+Y_OFFSET)); 
			#if !defined(NO_COLOR)
				SET_TEXT_COLOR(BROKEN_WALL_IMAGE._color);
			#endif
			cputc(BROKEN_WALL_IMAGE._imageData); 		
		}
	#endif

	void _draw(unsigned char x, unsigned char y, Image * image) 
	{
		gotoxy((x+X_OFFSET),(y+Y_OFFSET)); 
		#if !defined(NO_COLOR)
			SET_TEXT_COLOR(image->_color);
		#endif
		cputc(image->_imageData); 
	}
	
	void _delete(unsigned char x, unsigned char y)
	{
		gotoxy(x+X_OFFSET,y+Y_OFFSET);
		cputc(' ');
	}

	void _blink_draw(unsigned char x, unsigned char y, Image * image, unsigned char * blink_counter) 
	{
		gotoxy((x+X_OFFSET),(y+Y_OFFSET)); 
		#if !defined(NO_COLOR)
			SET_TEXT_COLOR(image->_color);
		#endif
		if(*blink_counter) 
		{
			cputc(image->_imageData); 
			*blink_counter=0;
		} 
		else 
		{
			cputc(' '); 
			*blink_counter=1;
		}	
	}
#endif

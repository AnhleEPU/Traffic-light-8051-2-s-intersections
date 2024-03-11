/*
Creater : Pham Van Dung 
Faculty: automation of control - electric power university
Adress: 256 Hoang Quoc Viet sreet
Project: Traffic light for 2's intersctions using greenlight technic 
Microcontroller using in this protect: AT98C51 
Date: 16:46:20s , 11,3,2024. 
*/
#include <REGX51.H>
sbit REDX = P2^5;
sbit GREENX = P2^6;
sbit YELLOWX = P2^7;

sbit REDY = P1^5;
sbit GREENY = P1^6;
sbit YELLOWY = P1^7;

sbit clk1 = P2^3;
sbit clk2 = P2^4;
sbit clk3 = P2^2;
sbit clk4 = P2^1;

void program();
int chucx,donvix;
int chucy,donviy;
int x,y;
unsigned char maled[] = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09};
void delay_ms(unsigned int times)
{
	int x,y;
	for(x=0;x<=times;x++)
	{
		for(y=0;y<=124;y++);
	}
}



//----------------------------------------------------------
void display_REDY_GREENX()
{
	for(x=25,y=20;x>=0,y>=0;x=x-1,y=y-1)
	{
			REDX = GREENY = 1;
		  GREENX = YELLOWY = 0;
			YELLOWX = REDY = 0 ;
		
		  chucx = x/10;
		  donvix = x%10;
		  chucy = y/10;
		  donviy = y%10;
		
		  P0  = maled[chucx];
		  clk1 = 0;
		  clk1 = 1;
		  P0  = maled[donvix];
		  clk2 = 0;
		  clk2 = 1;
		
		  
		  P3 = maled[chucy];
		  clk3 = 0;
		  clk3 = 1;
		  P3 = maled[donviy];
		  clk4 = 0;
		  clk4 = 1;
		  
		  delay_ms(500);
	
			if(y == 0)  // in this case greenlight x_direction equal zero , turn on yellowlight
			{
					REDX = YELLOWY = 1;
					GREENX = GREENY = 0;
					YELLOWX = REDY = 0 ;
			  
				for(x=5;x>=0;x--)
				{
						chucx = x/10;
						donvix = x%10;
						chucy = x/10;
						donviy = x%10;
					
					
					  
						P0  = maled[chucx];
						clk1 = 0;
						clk1 = 1;
						P0  = maled[donvix];
						clk2 = 0;
						clk2 = 1;
		
		  
						P3 = maled[chucy];
						clk3 = 0;
						clk3 = 1;
						P3 = maled[donviy];
						clk4 = 0;
						clk4 = 1;
						delay_ms(500);
				if(x == 0)
				{
					program();
				}
					
				
				}
			}
	}
}
//----------------------------------------------------------
void main()
{

	REDX = REDY = 0;
	GREENX = GREENY = 0;
	YELLOWX = YELLOWY = 0;
	
	while(1)
	{
			display_REDY_GREENX();
	}

}

void program()
{
		for(x=20,y=25;x>=0,y>=0;x=x-1,y=y-1)
	{
			GREENX = REDY = 1;
		  REDX = YELLOWY = 0;
			YELLOWX = GREENY = 0 ;
		
		  chucx = x/10;
		  donvix = x%10;
		  chucy = y/10;
		  donviy = y%10;
		
		  P0  = maled[chucx];
		  clk1 = 0;
		  clk1 = 1;
		  P0  = maled[donvix];
		  clk2 = 0;
		  clk2 = 1;
		
		  
		  P3 = maled[chucy];
		  clk3 = 0;
		  clk3 = 1;
		  P3 = maled[donviy];
		  clk4 = 0;
		  clk4 = 1;
		  
		  delay_ms(500);
		  
			if (x == 0)
			{
			  YELLOWX = REDY = 1;
				REDX = YELLOWY = 0;
				GREENX = GREENY = 0 ;
				
			for(y=5 ;y>=0;y--)
			{
			
			chucx = y/10;
		  donvix = y%10;
		  chucy = y/10;
		  donviy = y%10;
		
		  P0  = maled[chucx];
		  clk1 = 0;
		  clk1 = 1;
		  P0  = maled[donvix];
		  clk2 = 0;
		  clk2 = 1;
		
		  
		  P3 = maled[chucy];
		  clk3 = 0;
		  clk3 = 1;
		  P3 = maled[donviy];
		  clk4 = 0;
		  clk4 = 1;
		  
		  delay_ms(500);
			
			}
		
			}
	}
}

// end code 
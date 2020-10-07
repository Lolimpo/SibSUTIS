#ifndef CLASS_H
#define CLASS_H

class tPoint
{
	private:
		int resolution = 1000;
struct dot
		{
			int x; // coordinates of each dot
			int y;
			int speedx;
			int speedy;
			char clr;
		};	
		dot dots[100];
	public:
		void create();
		void linear_move();
		void random_move();
};

void tPoint::create()
		{
			for(int i = 0; i < 100; i++) // placement of every dot
    		{
    			dots[i].x = rand()%resolution;
    			dots[i].y = rand()%resolution;
    			dots[i].clr = rand()%15+1;
       		 	dots[i].speedx = rand()%5+1;
				dots[i].speedy = rand()%5+1;
   			}		
		}
		
void tPoint::linear_move()
{
	while(!kbhit())
	{
		delay(1);
        for(int i = 0; i < 100; i++)
        {
        	if(dots[i].y >= resolution - 1 || dots[i].y <= 0) dots[i].speedy = (-1) * dots[i].speedy;
        	putpixel(dots[i].x, dots[i].y, 0);
        	dots[i].y += dots[i].speedy;
        	putpixel(dots[i].x, dots[i].y, dots[i].clr);
		}
    }
}

void tPoint::random_move()
{
	while(!kbhit())
	{
		delay(1);
        for(int i = 0; i < 100; i++)
        {
        	if(dots[i].x >= resolution - 1 || dots[i].x <= 0) dots[i].speedx = (-1) * dots[i].speedx;
        	if(dots[i].y  >= resolution - 1 || dots[i].y <= 0) dots[i].speedy = (-1) * dots[i].speedy;
        	putpixel(dots[i].x, dots[i].y, 0);
            dots[i].x += dots[i].speedx;
            dots[i].y += dots[i].speedy;
            putpixel(dots[i].x, dots[i].y, dots[i].clr);
        }
    }
}

#endif

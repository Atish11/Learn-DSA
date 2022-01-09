//graphics in c  write hello world in 15 diff. colors



#include<SFML/Graphics.h>
#include<conio.h>
int main()
{
	int gd =DETECT, gm;
	int i, x=100, y=50;
	initgraph(&gd, &gm, "c:\\turboc3\\bgi");
	for(i=1;i<16;i++)
	{
		setcolor(i);
		outtextxy(x, y, "Hello world....");
		y=y+30;
	}
	getch();
	closegreph();
	return 0;
}

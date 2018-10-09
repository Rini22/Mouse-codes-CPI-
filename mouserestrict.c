#include<dos.h>
#include<graphics.h>
#include<conio.h>
 
int initmouse();
void showmouseptr();
void hidemouseptr();
void restrictmouseptr(int, int, int, int);
 
union REGS i, o;
 
main()
{
   int status, gd = DETECT, gm;
 
   initgraph(&gd,&gm,"C:\\TC\\BGI");
   settextstyle(DEFAULT_FONT,0,2);
 
   status = initmouse();
 
   if ( status == 0 )
      outtext("Mouse support not available.\n");
   else
   {
      showmouseptr();
      rectangle(120,70,520,410);
      restrictmouseptr(120,70,520,410);
   }
 
   getch();
   return 0;
}
 
int initmouse()
{
   i.x.ax = 0;
   int86(0X33,&i,&o);
   return ( o.x.ax );
}
 
void showmouseptr()
{
   i.x.ax = 1;
   int86(0X33,&i,&o);
}
 
void restrictmouseptr(int x1, int y1, int x2, int y2)
{
   i.x.ax = 7;
   i.x.cx = x1;
   i.x.dx = x2;
   int86(0X33,&i,&o);
 
   i.x.ax = 8;
   i.x.cx = y1;
   i.x.dx = y2;
   int86(0X33,&i,&o);
}
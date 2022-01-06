#include<constream.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
int j=1;
char sscore[10];
class character
{
	public:
		void gun_man();
		void ground();
}body;
class target
{
	public:
		void dart_board(int x,int y,int count);
		int board_bullet(int i,int x, int y,int count);
		void sco_re(int score);
		void shots(int count);
}board;
class looks
{
	public:
		void border(int x,int y);
		void menu(int x,int y);
		void menu2(int x,int y,int score);

}l;

void looks::menu(int x,int y)
{
	cleardevice();
	int key,count=10;
	int score=0;
	setcolor(8);
	setfillstyle(11,5);
	bar(0,0,20,y);
	bar(0,0,x,20);
	bar(x-20,0,x,y);
	bar(0,y-20,x,y);
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL,YELLOW);
	rectangle(200,100,400,240);
	floodfill(210,150,YELLOW);
	setcolor(BLACK);
	outtextxy(200,105,"-----SHOOT YOUR LUCK-----");
	outtextxy(200,140,"a.Start Game");
	outtextxy(200,160,"b.Instructions");
	outtextxy(200,180,"c.Exit");
	outtextxy(200,200,"Press Your Choice");
	key=getch();
	if(key==97)
	{
		cleardevice();
		border(x,y);
		body.ground();
		body.gun_man();
		board.shots(count);
		board.sco_re(score);
		board.dart_board(x,y,count);
	}
	else if(key==98)
	{
		cleardevice();
		setcolor(8);
		setfillstyle(11,5);
		bar(0,0,20,y);
		bar(0,0,x,20);
		bar(x-20,0,x,y);
		bar(0,y-20,x,y);
		setcolor(YELLOW);
		setfillstyle(SOLID_FILL,YELLOW);
		rectangle(200,100,400,240);
		floodfill(210,150,YELLOW);
		setcolor(BLACK);
		outtextxy(200,105,"-----SHOOT YOUR LUCK-----");
		outtextxy(200,150,"Ansh se samaj lo!!!!");
		outtextxy(200,160,"Press any key");
		getch();
		menu(x,y);
	}
	else if(key==99)
	exit(0);
	else
	{menu(x,y);
	}

}
void looks::menu2(int x,int y,int score)
{
	cleardevice();
	setcolor(8);
	setfillstyle(11,5);
	bar(0,0,20,y);
	bar(0,0,x,20);
	bar(x-20,0,x,y);
	bar(0,y-20,x,y);
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL,YELLOW);
	rectangle(200,100,400,240);
	floodfill(210,150,YELLOW);
	setcolor(BLACK);
	outtextxy(200,105,"--Thanks for Playing--");
	outtextxy(200,130,"Your score:");
	itoa(score,sscore,10);
	outtextxy(300,130,sscore);
	outtextxy(200,170,"Press any key");
	getch();
	menu(x,y);
}



void character::gun_man()
{
	//character
	setcolor(BLUE);
	setfillstyle(SOLID_FILL,BLUE);
	circle(72,180,40);  //head
	floodfill(72,180,BLUE);
	setcolor(WHITE);
	line(62,220,62,225);  //neck
	line(82,220,82,225);
	line(62,225,82,225);
	setcolor(RED);
	setfillstyle(SOLID_FILL,RED);
	rectangle(22,225,122,300); //body
	floodfill(25,230,RED);
	setcolor(BLUE);
	setfillstyle(SOLID_FILL,BLUE);
	rectangle(72,250,142,260); //hands
	floodfill(75,255,BLUE);
	rectangle(122,245,137,250);//hands;
	floodfill(125,246,BLUE);
	setcolor(WHITE);
	line(122,250,142,250);
	setfillstyle(SOLID_FILL,WHITE);
	circle(147,255,13);//hands circle
	floodfill(147,255,WHITE);
	setcolor(BLUE);
	setfillstyle(SOLID_FILL,BLUE);
	rectangle(62,300,77,340);//legs
	floodfill(63,310,BLUE);
	rectangle(80,300,82,340); //legs
	floodfill(81,310,BLUE);
	setcolor(RED);
	setfillstyle(SOLID_FILL,RED);
	rectangle(62,340,87,350);
	floodfill(63,344,RED);
	setcolor(WHITE);
}
void character::ground()
{
	int poly1[]={22,350,150,350,250,450,22,450};
	setfillstyle(SOLID_FILL,GREEN);  //land
	fillpoly(4,poly1);
}
void target::sco_re(int score)
{

       itoa(score,sscore,10);
       setcolor(BLACK);
       setfillstyle(SOLID_FILL,BLACK);
       bar(300,30,330,50);
       setcolor(WHITE);
       outtextxy(300,40,sscore);

}
void target::shots(int count)
{
       char shot[10];
       itoa(count,shot,10);
       setcolor(BLACK);
       setfillstyle(SOLID_FILL,BLACK);
       bar(115,50,135,60);
       setcolor(WHITE);
       outtextxy(120,50,shot);
}
int target::board_bullet(int i,int x, int y,int count)
{
	count--;
	shots(count);
	static int score=0;
	int l=1,col=0;
	for(int k=i;k<1000;k=k+j)
       {
	setcolor(YELLOW);  //dart board
	setfillstyle(SOLID_FILL,YELLOW);
	bar((x-27),32+k,x-22,92+k);
	setcolor(GREEN);
	setfillstyle(SOLID_FILL,GREEN);
	bar((x-32),42+k,(x-27),82+k);
	setcolor(BLUE);
	setfillstyle(SOLID_FILL,BLUE);
	bar((x-37),52+k,(x-32),72+k);
	setcolor(RED);
	setfillstyle(SOLID_FILL,RED);
	bar((x-42),57+k,(x-37),67+k);
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,BLACK);
	bar((x-27),22+k,x-22,32+k);
	bar((x-32),22+k,(x-27),42+k);
	bar((x-37),22+k,(x-32),52+k);
	bar((x-42),22+k,(x-37),57+k); //upper board
	bar((x-27),92+k,x-22,93+k);       //lower board
	bar((x-32),82+k,(x-27),93+k);
	bar((x-37),72+k,(x-32),93+k);
	bar((x-42),67+k,(x-37),93+k);
	for(int a=l;a<l+1;a++)
	{
		col=getpixel(178+a,254);
		if(col==4)
		{
			score=score+100;
			sco_re(score);
			l=0;

		}
		else if(col==1)
		{
			score=score+50;
			sco_re(score);
			l=0;
		}
		else if(col==2)
		{
			score=score+30;
			sco_re(score);
			l=0;
		}
		else if(col==14)
		{
			score=score+10;
			sco_re(score);
			l=0;
		}
		setcolor(BLACK);
		setfillstyle(SOLID_FILL,BLACK);
		bar(170+a,253,172+a,255);
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,WHITE);
		bar(172+a,253,178+a,255);
		if(l==441 || l==0)
		{   	setcolor(BLACK);
			setfillstyle(SOLID_FILL,BLACK);
			bar(172+a,253,178+a,255);
		}
	}
	if(k==365)
	j=-1;
	else if(k==0)
	j=1;
	if(l==441 || l==0)
	break;
	l=l+2;
	delay(10);
	}
	if(count==0)
	{ looks l1;
	l1.menu2(x,y,score);}
	return k;}


void target::dart_board(int x,int y,int count)
{       int i;
	int key;
	for(i=0;i<1000;i=i+j)
       {
	setcolor(YELLOW);  //dart board
	setfillstyle(SOLID_FILL,YELLOW);
	bar((x-27),32+i,x-22,92+i);
	setcolor(GREEN);
	setfillstyle(SOLID_FILL,GREEN);
	bar((x-32),42+i,(x-27),82+i);
	setcolor(BLUE);
	setfillstyle(SOLID_FILL,BLUE);
	bar((x-37),52+i,(x-32),72+i);
	setcolor(RED);
	setfillstyle(SOLID_FILL,RED);
	bar((x-42),57+i,(x-37),67+i);
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,BLACK);
	bar((x-27),22+i,x-22,32+i);
	bar((x-32),22+i,(x-27),42+i);
	bar((x-37),22+i,(x-32),52+i);
	bar((x-42),22+i,(x-37),57+i); //upper board
	bar((x-27),92+i,x-22,93+i);       //lower board
	bar((x-32),82+i,(x-27),93+i);
	bar((x-37),72+i,(x-32),93+i);
	bar((x-42),67+i,(x-37),93+i);
	if(kbhit())
	{
		key=getch();
		if(key==27)
		{l.menu(x,y);}
		else{i=board_bullet(i,x,y,count);
		count--;
		}
	}
	if(i==365)
	j=-1;
	else if(i==0)
	j=1;
	delay(10);
	}

}
void looks::border(int x,int y)
{
	setcolor(8);
	setfillstyle(11,5);
	bar(0,0,20,y);
	bar(0,0,x,20);
	bar(x-20,0,x,y);
	bar(0,y-20,x,y);
	setcolor(WHITE);
	outtextxy(250,5,"SHOOT YOUR LUCK");
	outtextxy(30,30,"Press Escape for Menu");
	outtextxy(30,40,"Press Space bar to Shoot");
	outtextxy(250,40,"Score:");
	outtextxy(30,50,"Shots Left:");
}
int main()
{
	int gd=DETECT,gm,err,xmax,ymax;

	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	 /* read result of initialization */
	err= graphresult();

	if (err!= grOk)  /* an error occurred */
	{
	cout<<"Graphics error:\n"<<grapherrormsg(err);
	cout<<"Press any key to halt:";
	getch();
	exit(1); /* terminate with an error code */
	}
	setcolor(getmaxcolor());
	xmax = getmaxx();
	ymax = getmaxy();
	l.menu(xmax,ymax);
	getch();
	closegraph();
	return 0;
}
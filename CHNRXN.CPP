#include<stdio.h>
#include<math.h>
#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
#include<time.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#define r rectangle(0,0,getmaxx(),getmaxy());rectangle(2,2,getmaxx()-2,getmaxy()-2);
#define dl delay(300);
#define s sound();
static int S,siz,N,X,Y,cht,H;
union REGS gate,rog;
class cal;
struct cord{
int x1,x2,y1,y2,block,flag,i,j,col,sud,sudu,input,sucol;};
void first(cal*);
class btn{
int x,y,size,col,*text;
public:
cord button(int x,int y,int size,int col,char *p){
cord d;
int _t;
setfillstyle(SOLID_FILL,col);
bar(x,y,18*size+x,5*size+y);
setcolor(1);
settextstyle(3,HORIZ_DIR,size/3) ;
outtextxy(((11*size+x)+x)/2,((2*size+y)+y)/2,p);
d.x1=x;
d.x2=(18*size)+x ;
d.y2=(5*size)+y;
d.y1=y;
return d;
}};
void help(int);
 void matrix(int lx,int ly){
for(int i=1;i<=N;i++)
{for(int j=1;j<=N;j++){
rectangle(lx,ly,lx+siz,ly+siz);
lx+=siz;}
lx=lx-siz*j+siz;
ly+=siz;}}

int set(int a,int b){
		 int c=1;
if(a==1)
       return b;
if(a==2){
	c=b+3;}
if(a==3){
	c=b+6;}
if(a==4){
	c=b+1;}
if(a==5){
	c=b+4;}
if(a==6){
	c=b+7;}
if(a==7){
	c=b+2;}
if(a==8){
	c=b+5;}
if(a==9){
	c=b+8;}
    if(c>9)
	c=c-9;
return c;}
void obam(int a,int b,int c,int sud[10][10]){
    int temp,j;
if(c==2||c==4){
    a=a+3;
    b=b+3;
} if(c==3||c==6){
    a=a+6;
    b=b+6;
}  if(c<=3){
    for(j=1;j<=9;j++){
	    temp=sud[a][j];
	    sud[a][j]=sud[b][j];
	    sud[b][j]=temp;
    }}else{
    for(j=1;j<=9;j++){
	    temp=sud[j][a];
	    sud[j][a]=sud[j][b];
	    sud[j][b]=temp;
}}}
void suduko(int sud[10][10]){
for(int i=1;i<=9;i++){
for(int j=1;j<=9;j++){
     sud[i][j]=set(i,j);
}}       time_t t;
   srand((unsigned)time(&t));
	for(int p=1;p<=6;){
       x:
       int z=rand()%4;
      int y=rand()%4;

   if(z&&y)
   { obam(z,y,p,sud);
p++;}
   else{
       goto x;
}}}

void slogo(int,int);
class image{
private:
void *j,*k;
public:
image(){
int area;
for(int i=0;i<=5;i++) {
setcolor(1);
circle(5,5,i);
setcolor(2);
circle(25,25,i);}
area=imagesize(0,0,10,10);
j=malloc(area);
getimage(0,0,10,10,j);
area=imagesize(20,20,30,30);
k=malloc(area);
getimage(20,20,30,30,k);
};
void setimg(int lx,int ly,int col){
if(col==1)
putimage(lx,ly,j,0);
if(col==2)
putimage(lx,ly,k,0);}};

 void sound(){if(S)
{sound(500);delay(5);
nosound();}
if(!S)
delay(5);}

class cal{
public:
cord pos;
cal(int blk=0){
int i=0,j=0;
pos.block=blk;
pos.flag=0;
pos.col=0;
pos.sud=0;
pos.input=0;
pos.sucol=1;
pos.sudu=0;
i=(pos.block/N)+1;
if(pos.block%N==0)
i=i-1;
j=pos.block-(i-1)*N;
pos.x2=X+(j*siz);
pos.x1=pos.x2-siz;
pos.y2=Y+(i*siz);
pos.y1=pos.y2-siz;
pos.i=i;
pos.j=j;
}
cord cal::details(){
int i,j;
i=(pos.block/N)+1;
if(pos.block%N==0)
i=i-1;
j=pos.block-(i-1)*N;
pos.x2=X+(j*siz);
pos.x1=pos.x2-siz;
pos.y2=Y+(i*siz);
pos.y1=pos.y2-siz;
pos.i=i;
pos.j=j;
return pos;
}
void change(int user){
pos.flag=pos.flag+1;
pos.col= user;
}};
class mouse{
public:
void show(){
gate.x.ax=1;
int86(0X33,&gate,&rog);}
void hide(){
gate.x.ax=2;
int86(0X33,&gate,&rog);}
void move(int &but,int &x,int &y){
gate.x.ax=3;
int86(0X33,&gate,&rog);
but=rog.x.bx;
x=rog.x.cx;
y=rog.x.dx;}};
class click:public mouse{
public:
int loc(cal *c);};
int click::loc(cal *c){
btn b;cord chk;
int but=0,x,y;
show();
while(1){
but=0;
move(but,x,y);
if(x>X&&x<(X+(siz*N))&&y>Y&&y<(Y+(siz*N))){
for(int i=1;i<=(N*N);i++){
chk=c[i].details();
if(chk.x1<=x&&chk.x2>=x&&chk.y1<=y&&chk.y2>=y){
if(but==1)
return chk.block;} }
}
setfillstyle(SOLID_FILL,4);
bar(545,320,615,390) ;
setcolor(0);
outtextxy(560,340,"EXIT");
if(545<=x&&615>=x&&320<=y&&390>=y)
if(but==1) {
setbkcolor(0);
cleardevice();
exit(0);    }
slogo(545,230);
if(x>545&&x<615&&y>230&&y<300)
if(but==1)
if(S)S=0;else S=1;
delay(30);
}}
class process:public click,public image{
public:
 void check1(cal *c,int);
 void check2(cal *c,int);
 void run(cal *c,int user);
};
void process::run(cal *c,int user){
int bl;
while(1){
bl=loc(c);
cht=0;
dl;
if(c[bl].pos.col==user||c[bl].pos.col==0){
c[bl].change(user);
 check1(c,user);
 break;}
else
{ hide();
setcolor(4);
rectangle(c[bl].pos.x1,c[bl].pos.y1,c[bl].pos.x2,c[bl].pos.y2);
line(c[bl].pos.x1,c[bl].pos.y1,c[bl].pos.x2,c[bl].pos.y2);}
show();
}};

void process::check2(cal *c,int user){
int hel;
cleardevice();
{if(user==1)
user=2 ;
else
user=1;}
 setcolor(user);
 r;
 line(520,0,520,479);
hide();
 matrix(X,Y);
for(int i=1;i<=N*N;i++) {
hel=c[i].pos.flag;
if(hel==1){setimg((c[i].pos.x1+c[i].pos.x2)/2-(siz/5),(c[i].pos.y1+c[i].pos.y2)/2-(siz/5),c[i].pos.col);
s }if(hel==2){
s setimg((c[i].pos.x1+c[i].pos.x2)/2-(siz/3),(c[i].pos.y1+c[i].pos.y2)/2-(siz/3),c[i].pos.col)  ;
s setimg((c[i].pos.x1+c[i].pos.x2)/2+(siz/8),(c[i].pos.y1+c[i].pos.y2)/2+(siz/8),c[i].pos.col)  ;
}if(hel==3){
s setimg((c[i].pos.x1+c[i].pos.x2)/2-(siz/6),(c[i].pos.y1+c[i].pos.y2)/2-(siz/3),c[i].pos.col)  ;
s setimg((c[i].pos.x1+c[i].pos.x2)/2-(siz/3),(c[i].pos.y1+c[i].pos.y2)/2+(siz/10),c[i].pos.col)  ;
s setimg((c[i].pos.x1+c[i].pos.x2)/2+(siz/10),(c[i].pos.y1+c[i].pos.y2)/2+(siz/10),c[i].pos.col)  ;
}}show();}
void process::check1(cal *c,int user){
int beki=0,bekj=0,bekz,beks,arti,artj;

int fat=0;
for(int t=1;t<=N*N;t++){
arti=c[t].pos.i;
artj=c[t].pos.j;
if((c[t].pos.i==1||c[t].pos.i==N)&&(c[t].pos.j==1||c[t].pos.j==N)){
if(c[t].pos.flag>1){
fat=1;
c[t].pos.flag=0;
if((arti+1)<N)
{beki=t+N;}
else { beki=t-N;}
if((artj+1)<N)
{ bekj=t+1;}
else     {
bekj=t-1; }
c[beki].pos.flag=c[beki].pos.flag+1;
c[beki].pos.col=c[t].pos.col;
c[bekj].pos.flag=c[bekj].pos.flag+1;
c[bekj].pos.col=c[t].pos.col;
c[t].pos.col=0;
}}
if((arti==1||arti==N)&&(artj<N&&artj>1)){
if(c[t].pos.flag>2){
fat=1;
c[t].pos.flag=0;
beki=t-1;
bekj=t+1;
if((arti+1)<N){
bekz=t+N;
}else{bekz=t-N;}
c[beki].pos.flag=c[beki].pos.flag+1;
c[beki].pos.col=c[t].pos.col;
c[bekj].pos.flag=c[bekj].pos.flag+1;
c[bekj].pos.col=c[t].pos.col;
c[bekz].pos.flag=c[bekz].pos.flag+1;
c[bekz].pos.col=c[t].pos.col;
c[t].pos.col=0;
}}
if((artj==1||artj==N)&&(arti<N&&arti>1)){
if(c[t].pos.flag>2){
fat=1;
c[t].pos.flag=0;

beki=t-N;
bekj=t+N;
if((artj+1)<N){
bekz=t+1;
}else{bekz=t-1;}
c[beki].pos.flag=c[beki].pos.flag+1;
c[beki].pos.col=c[t].pos.col;
c[bekj].pos.flag=c[bekj].pos.flag+1;
c[bekj].pos.col=c[t].pos.col;
c[bekz].pos.flag=c[bekz].pos.flag+1;
c[bekz].pos.col=c[t].pos.col;
c[t].pos.col=0;
}}
if(arti>1&&arti<N&&artj>1&&artj<N)
{if(c[t].pos.flag>3){
fat=1;
c[t].pos.flag=0;

bekj=t+1;
bekz=t-1;
beks=t-N;
beki=t+N;
c[beki].pos.flag=c[beki].pos.flag+1;
c[beki].pos.col=c[t].pos.col;
c[bekj].pos.flag=c[bekj].pos.flag+1;
c[bekj].pos.col=c[t].pos.col;
c[bekz].pos.flag=c[bekz].pos.flag+1;
c[bekz].pos.col=c[t].pos.col;
c[beks].pos.flag=c[beks].pos.flag+1;
c[beks].pos.col=c[t].pos.col;
c[t].pos.col=0;}}}
 check2(c,user);
if(!fat||cht==21)
return ;
cht++;
check1(c,user);}

class player{
public:
void startup(process p1,cal *c);
void win(cal *c);
void cresud(cal *c){
N=9;
int sud[10][10],k=1;
suduko(sud);
for(int i=1;i<=N;i++)
{for(int j=1;j<=N;j++){
c[k].pos.sud=sud[i][j];
c[k].pos.sudu=sud[i][j];
k++;}}};
void final(cal *c){
int i,p,q,l;
outtextxy(285,240,"Processing.....");
time_t t;
srand((unsigned)time(&t));
for(i=1;i<=N*N;i++){
  p=rand()%5;
  delay(19);
  q=rand()%9;
  delay(3);
  l=rand()%3;
if(p==q||q==l||p==l)
{c[i].pos.input=1;
 }
 else
 c[i].pos.sud=0;
}}

void draw(cal *c){
char ch[4];
settextstyle(3,HORIZ_DIR,2);
for(int i=1;i<=81;i++)
{
 if(c[i].pos.input==1)
{ setcolor(c[i].pos.sucol);
itoa(c[i].pos.sud,ch,10);
outtextxy((c[i].pos.x1+siz/3),(c[i].pos.y1+siz/4),ch);
}
if(c[i].pos.input==2)
{
setcolor(c[i].pos.sucol);
itoa(c[i].pos.sud,ch,10);
outtextxy((c[i].pos.x1+siz/3),(c[i].pos.y1+siz/4),ch);
}
}
}

 void tm(clock_t start){
 clock_t ed;
 int hh=00,mm=00,ss=00,tmp=00;
char tt[8];
 ed=clock();
  tmp=(ed-start)/CLK_TCK;;
 if(tmp>59) {
     ss=ss+tmp%60;
     tmp=tmp/60;

       if(tmp>59) {
       mm=mm+tmp%60;
	tmp=tmp/60;
	hh=tmp;
	}
	else
	mm=tmp;
 }else
  ss=tmp;
  sprintf(tt,"%d:%d:%d",hh,mm,ss);
   rectangle(100,100,540,380);
   setfillstyle(1,15);
    bar(101,101,539,379);
  setcolor(1);
  settextstyle(3,HORIZ_DIR,5);
  outtextxy(220,200,"TIME TAKEN");
  outtextxy(270,237,tt);
delay(3000);}
void check(cal *c){
for(int i=1;i<=N*N;i++)
{ if(c[i].pos.input==2)
{ if(c[i].pos.sud!=c[i].pos.sudu)
c[i].pos.sucol=4;

}}
}
void wins(cal *c,clock_t start){
int fat=0;
for(int i=1;i<=N*N;i++)
{
if(c[i].pos.sud!=c[i].pos.sudu)
{fat=1;
break; }}
if(fat==0)
{delay(200);tm(start);
setbkcolor(0);
cleardevice();
exit(0); }
}
void fill(cal *c)
{  for(int i=1;i<=N*N;i++)
{
if(c[i].pos.input==0)
{c[i].pos.sud=c[i].pos.sudu;
c[i].pos.input=2;
c[i].pos.sucol=8;

}
}
}

void sudoku(cal *c){
int but,x,y;N=9;siz=32;X=100,Y=100;
mouse m;
cresud(c);
final(c);
cleardevice();
btn b;int de;
clock_t start;

setbkcolor(7);
cord d,b1,b2,b3,b4,b5;
start=clock();
while(1){
but=0;
de=0;
m.show();
m.move(but,x,y);
setcolor(4);
r;
setcolor(9);
matrix(X,Y);
line(470,0,470,getmaxy());
b1=b.button(500,90,7,2,"CHECK");
b2=b.button(500,150,7,2,"FILL");
b4=b.button(500,330,7,4,"EXIT");
b5=b.button(500,270,7,2,"HELP");

setcolor(1);
rectangle(X,Y,N*siz+X,N*siz+Y);
for(int j=3;j<=9;j+=3) {
line(X+siz*j,Y,X+siz*j,Y+N*siz);
line(X,Y+siz*j,X+siz*N,Y+j*siz);
}

for(int i=1;i<=(N*N);i++)
{ d=c[i].details();
if(d.x1<=x&&d.x2>=x&&d.y1<=y&&d.y2>=y)
{ setcolor(2);
m.hide();
rectangle(d.x1,d.y1,d.x2,d.y2);
if(but==1)
{
setcolor(6);
rectangle(d.x1,d.y1,d.x2,d.y2);
de=getche();
if(de==8&&c[i].pos.input==2) {
c[i].pos.input=0; cleardevice();}
de=de-48;
if(de<=9&&de>=1&&c[i].pos.input==0||c[i].pos.input==2)
{if(de!=c[i].pos.sudu&&H==2)
c[i].pos.sucol=4;
else
c[i].pos.sucol=8;
{if(c[i].pos.input==2)
{c[i].pos.input=0;
cleardevice();}
c[i].pos.sud=de;
c[i].pos.input=2;
}
}}

if(but==2&&c[i].pos.input==2){
c[i].pos.input=0;
cleardevice(); }
}}
if(b4.x1<x&&b4.x2>x&&b4.y1<y&&b4.y2>y)
{ setcolor(9);
m.hide();
rectangle(b4.x1,b4.y1,b4.x2,b4.y2);
if(but==1)
{
tm(start);
setbkcolor(0);
cleardevice();
exit(0); } }

if(b3.x1<x&&b3.x2>x&&b3.y1<y&&b3.y2>y)
{if(but==1)
{if(H==2)
H=8;
else
H=2;}}
b3=b.button(500,210,7,H,"atCRRCT");
if(b5.x1<x&&b5.x2>x&&b5.y1<y&&b5.y2>y)
{if(but)    {
cleardevice();
help(1);
getch();
cleardevice();
setbkcolor(7);
}
}

if(b2.x1<x&&b2.x2>x&&b2.y1<y&&b2.y2>y)
{ if(but==1)
{ fill(c);
draw(c);
delay(500);
}}

if(b1.x1<x&&b1.x2>x&&b1.y1<y&&b1.y2>y)
{ if(but==1||but==2)
{check(c);
}}
draw(c);
wins(c,start);
delay(240);
}}


};

void player::startup(process p1,cal *c1){
setbkcolor(0);
delay(200);
matrix(X,Y);

int i=0;
while(1){
if(i%2==0)  {
p1.run(c1,1);
}else   {
p1.run(c1,2);
}i++;
if(i>1)
win(c1);
}
}
void player::win(cal *c){
int ply1=0,ply2=0;char p[4];
mouse m;
for(int i=1;i<=N*N;i++)
{ if(c[i].pos.col==1)
ply1=ply1+c[i].pos.flag;
if(c[i].pos.col==2)
 ply2=ply2+c[i].pos.flag;
}
setcolor(1) ;
rectangle(545,45,615,115);
settextstyle(1,HORIZ_DIR,4);
itoa(ply1,p,10);
 outtextxy(570,65,p);
setcolor(2) ;
rectangle(545,135,615,205);
settextstyle(1,HORIZ_DIR,4);
itoa(ply2,p,10);
outtextxy(570,155,p);
if(ply2==0)    {
m.hide();
setcolor(1);
rectangle(100,100,540,380);
   setfillstyle(1,8);
    bar(101,101,539,379);
settextstyle(3,HORIZ_DIR,5);
outtextxy(150,190,"PLAYER 1 WON");
delay(3000);
setbkcolor(0);
cleardevice();
exit(0);}
if(!ply1){
setcolor(2);
m.hide();
rectangle(100,100,540,380);
   setfillstyle(1,8);
    bar(101,101,539,379);

settextstyle(3,HORIZ_DIR,5);
outtextxy(150,190,"PLAYER 2 WON");
 delay(3000);
 setbkcolor(0);
 cleardevice();
exit(0);}
}
class conf:public mouse,public btn{
public:
 void mov();
 void baar();
 void grid();
void sise();
};
void conf::mov(){
int but,x,y;
while(1){
but=0;
cleardevice();
move(but,x,y);
matrix(x,y);
delay(200);
if(but==2)
{X=x;Y=y;
break;}
}}
 void conf::baar(){
setcolor(15);
rectangle(590,20,630,420);
 setfillstyle(9,7);
bar(592,22,628,418);
}
 void bar(int y1,int i,int n){
char p[3];
itoa(n,p,10);
if(i){
setcolor(1);
rectangle(587,y1-2,633,y1+32);
setfillstyle(SOLID_FILL,15);
bar(589,y1,631,y1+30);
outtextxy(610,y1+10,p);
}
else
{ setfillstyle(SOLID_FILL,15);
bar(589,y1,631,y1+30);
setcolor(1);
outtextxy(610,y1+10,p);}};

void conf::sise(){
int but,x,y,z;
while(1){
cleardevice();
but=0;
show();
move(but,x,y);
z=(y/30)+14;
if(z>14)
z=14-(y/30);
baar();
matrix(X,Y);
if(y<420&&y>20&&x>588&&x<632){
if(but==1)  {
siz=25+z;
hide();
bar(y,1,z);
show();}}
else
bar(388,0,siz-25);
if(but==2)
break;;
delay(200);
}}

void conf::grid(){
int but,x,y,z;
while(1){but=0;
cleardevice();
show();
move(but,x,y);
z=(y/60)+9;
if(z>9)
z=9-(y/60);
baar();
matrix(X,Y);
if(y<420&&y>20&&x>588&&x<632){
if(but==1)  {
N=z;
hide();
bar(y,1,N);
show();}}
else
bar(388,0,N);
if(but==2)
break;;
delay(200);
}
}  void help(int u){
fstream file("conf.sys",ios::in);
char ch;
gotoxy(0,3);
cleardevice();
setbkcolor(8);
u=u+48;
while(file){
       file.get(ch);
	if((ch+'z')=='@'){
	  file.get(ch);
	  if((ch+'z')==(char)u)
	   { if((ch+'z')!=(char)51)
	   while(file)
	     {file.get(ch);
	     if((ch+'z')=='@')
	     break;
	     cout<<(char)(ch+'z');
	     }
	     else
	     {
		while(file&&(ch+'z')!='^')
		{ file.get(ch);
		cout<<(char)(ch+'z');
		}
		while(file)
		{ getch();
		file.get(ch);
		cout<<(char)(ch+'z');
		while((ch+'z')!='\n'&&file)
		{file.get(ch);
		cout<<(char)(ch+'z');}
		}

	     }

	   }

       if((ch+'z')=='@'&&!file)
       break;}
      }
 getch();
 file.close();
}


 void slogo(int x,int y){
setcolor(0);
rectangle(x,y,x+70,y+70);
setfillstyle(SOLID_FILL,15);
bar(x+2,y+2,x+68,y+68);
rectangle(x+23,y+23,x+29,y+47);
line(x+40,y+10,x+40,y+60);
line(x+40,y+10,x+29,y+23);
line(x+40,y+60,x+29,y+47);
if(!S){
setcolor(4);
line(x,y,x+70,y+70);
line(x+70,y,x,y+70);}
}
void loading(){
void *j,*k;
int area,x,y,h=200,t=0,fix=4;
setfillstyle(SOLID_FILL,8);
bar(0,0,640,480);
setcolor(15);
for(int i=1;i<=10;i++)
circle(100,100,i);
area=imagesize(90,90,110,110);
j=malloc(area);
getimage(90,90,110,110,j);
cleardevice();
setcolor(8);
for(i=90;i<=110;i++)
circle(200,200,i);
area=imagesize(90,90,320,320);
k=malloc(area);
getimage(90,90,320,320,k);
cleardevice();
setcolor(14);
setbkcolor(0);
settextstyle(4,HORIZ_DIR,5);
outtextxy(390,200,"CHAIN RXN");
while(t<=50){
if(t<=38)
fix=fix+4;
else
fix=fix-13;
for(int i=100;i<=300;i+=fix){
setcolor(1);
settextstyle(1,HORIZ_DIR,3);
y=10000-pow((h-i),2);
if(y<0)
y=(-1)*y;
x=h+sqrt(y);
y=h-sqrt(y);
putimage(h/2,h/2,k,0);
putimage(i,y,j,0);
putimage(400-i,400-y,j,0);
putimage(x,i,j,0);
putimage(400-x,400-i,j,0);
if(t>=43)
{ setcolor(2);
outtextxy(160,200,"Starting...");
settextstyle(2,HORIZ_DIR,6);
outtextxy(22,380,"Loaded...!");}else {
outtextxy(160,200,"Loading...");
}
delay(2);}
for(i=300;i>=100;i-=fix){
setcolor(1);
settextstyle(1,HORIZ_DIR,3);
y=10000-pow((h-i),2);
if(y<0)
y=(-1)*y;
x=h-sqrt(y);
y=h+sqrt(y);
putimage(h/2,h/2,k,0);
putimage(i,y,j,0);
putimage(400-i,400-y,j,0);
putimage(x,i,j,0);
putimage(400-x,400-i,j,0);
if(t>=43)
{setcolor(2);
outtextxy(160,200,"Starting...");
settextstyle(2,HORIZ_DIR,6);
outtextxy(22,380,"Loaded...!");
}else{
outtextxy(160,200,"Loading...");
 }
delay(2);
}t++;}
}
inline void rect(cord t){
rectangle(t.x1-2,t.y1-2,t.x2+2,t.y2+2);

};
void info(){
char ch;
setbkcolor(15);
setcolor(4);
fstream file("conf.sys",ios::in);
if(!file)
{outtextxy(240,230,"Cannot open \"conf.sys\" file");
delay(2500);
exit(0);
}
file.get(ch);
if(ch=='A'){
file.get(ch);
if(ch=='e'){
file.get(ch);
if(ch=='~');
else
{outtextxy(280,240,"\nInvailid conf.sys file\n");
 delay(2500);
 exit(0);}
}else
{outtextxy(280,240,"\nInvailid conf.sys file\n");
 delay(2500);
 exit(0);}
}
else {
outtextxy(280,240,"\nInvailid conf.sys file\n");
delay(2500);
exit(0);
}file.close();}

int passwd() {
int pass=0; int j=0, p=1000;
cleardevice();
cout<<"PassWord: "   ;
while(1){

pass=getch();
if((pass>48&&pass<109)||pass==13){
if(pass==13)
break;
cout<<"*";
pass=pass-48;
pass=pass*p;
j=j+pass;
p=p/10;}
}
return (j==4123?1:0);
}
void first(cal *c){
cord d1,d2,d3,d4;
process pr;
btn b;  conf con;
mouse m;
player pl;int but,x,y;
loading();
cleardevice();
setbkcolor(8);
while(1){
m.show();
cleardevice();
m.move(but,x,y);
d1=b.button(250,80,8,7,"PLAY");
if(x>d1.x1&&x<d1.x2&&y>d1.y1&&y<d1.y2)
{rect(d1);
if(but==1) {
m.hide();
cleardevice();dl;
while(1){
but=0;
cord f1,f2;
cleardevice();
m.show();
m.move(but,x,y);
f1=b.button(160,80,8,15,"CHrxn");
if(x>f1.x1&&x<f1.x2&&y>f1.y1&&y<f1.y2)
{rect(f1);
if(but==1) {
m.hide();
cleardevice();
dl;dl;
pl.startup(pr,c);
break;
}}
f2=b.button(360,80,8,15,"SUDOKU");
{if(x>f2.x1&&x<f2.x2&&y>f2.y1&&y<f2.y2)
rect(f2);
if(but==1) {
m.hide();
cleardevice();
dl;dl;
pl.sudoku(c);
break;
}}

delay(200);} } }

d4=b.button(250,360,8,4,"EXIT");
if(x>d4.x1&&x<d4.x2&&y>d4.y1&&y<d4.y2)
{rect(d4);
if(but)
{
setbkcolor(0);
cleardevice();
exit(0);} }
d2=b.button(250,150,8,7,"SETTINGS");
if(x>d2.x1&&x<d2.x2&&y>d2.y1&&y<d2.y2)
{ rect(d2);
if(but==1){
cleardevice();
dl;
cout<<"press mouse right-clk for save settings";
while(1){
but=0;
m.move(but,x,y);
cord e1,e2,e3,e4;
e2=b.button(250, 150,8,7,"GRID");
if(x>e2.x1&&x<e2.x2&&y>e2.y1&&y<e2.y2)
if(but==1){
con.grid();
cleardevice();
gotoxy(37,12);
cout<<"SAVED";
dl;dl;dl;
break;
}
e1=b.button(250,80,8,7,"MOVE");
if(x>e1.x1&&x<e1.x2&&y>e1.y1&&y<e1.y2)
if(but==1) {
con.mov();
cleardevice();
gotoxy(37,12);
cout<<"SAVED";
dl;dl;

break;}
e3=b.button(250,220,8,7,"SIZE");
if(x>e3.x1&&x<e3.x2&&y>e3.y1&&y<e3.y2)
if(but==1) {
con.sise();
cleardevice();
gotoxy(37,12);
cout<<"SAVED";
dl;dl;

break;}
e4=b.button(250,290,8,4,"BACK");
if(x>e4.x1&&x<e4.x2&&y>e4.y1&&y<e4.y2)
if(but==1){
cleardevice();
gotoxy(37,12);
cout<<"SAVED";
dl;dl;

break;
}
delay(100);
}}}
m.move(but,x,y);
d3=b.button(250,220,8,7,"HELP");
if(x>d3.x1&&x<d3.x2&&y>d3.y1&&y<d3.y2)
{  rect(d3);
if(but==1)
{help(1);
}}
cord d5=b.button(250,290,8,7,"ABOUT");
if(x>d5.x1&&x<d5.x2&&y>d5.y1&&y<d5.y2)
{rect(d5);
if(but){
help(2);
while(1){
cord a1=b.button(500,50,7,15,"CODES");
m.move(but,x,y);
if(a1.x1<x&&a1.x2>x&&y>a1.y1&&y<a1.y2)
{if(but);
if(passwd())
help(3);
else
{cout<<"\nInvalid password\n\n";
dl;dl;dl;}
break;
}
delay(200);}
}}
delay(150);}}


void main(){
N=9;X=100;Y=100;siz=30,H=2;
cal c[83];   char ch;
int gd=DETECT,gm;
initgraph(&gd,&gm,"c://tc//bgi");
info();
for(int i=1;i<=N*N;i++)
c[i]=i;
first(c);
setbkcolor(0);
closegraph();
}



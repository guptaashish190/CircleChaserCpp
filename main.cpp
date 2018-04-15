#include <iostream>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <dos.h>
using namespace std;
int main (){
int driver = DETECT , mode;
initgraph(&driver, & mode,"C:\\Users\\user\\Desktop\\1.jpg");
int x,y,r,px,py,n,pr,score,level;
int color;
x=50;
y=50;
r =5;
n=1;
pr = 5;
px =rand() % 100 * 2;
py = rand() % 100 * 2;
score = 0;
level = 1;
circle(px,py,pr);
floodfill(px,py,WHITE);
circle(x,y,r);
int temp = 1;
int temp2 = 2;

while(temp==1){
	int ax;
	int ay;
	if(temp2 == 2){
	x+=n;
	ax = 1;
	ay = 0;
	delay(10);
	}
	while(kbhit()){

	int keyp = getch();

	if(keyp == 'w' && ay == 0 ){
	y-=n;
	temp2 = 3;
	delay(10);
	ay = 1;
	ax = 0;
	}else if(keyp == 's' && ay == 0 ){
	y+=n;
	temp2 = 3;
	delay(10);
	ay = -1;
	ax = 0;
	}else if (keyp == 'a' && ax == 0){
	x-=n;
	temp2=3;
	delay(10);
	ax = -1;
	ay = 0;
	}else if (keyp == 'd' && ax == 0){
	x+=n;
	temp2=3;
	delay(10);
	ax = 1;
	ay = 0;
	}
	else if (keyp == 't'){
	temp =4;
	}
	}
	if (ax == -1 && ay ==0){
	x-=n;
	delay(10);
	temp2 = 3;
	}else if (ax == 1 && ay ==0){
	x+=n;
	delay(10);
	temp2 = 3;
	}else if (ax == 0 && ay ==1){
	y-=n;
	delay(10);
	temp2 = 3;
	}else if (ax == 0 && ay ==-1){
	y+=n;
	delay(10);
	temp2 = 3;
	}if(ax==0 && ay == -1 && y >= 393){
	y=0;
	}else if(ax==0 && ay == 1 && y <= 0){
	y=getmaxy();
	}else if(ax==1 && ay == 0 && x >= getmaxx()){
	x=0;
	}else if(ax==-1 && ay == 0 && x <= 0){
	x=getmaxx();
	}
	cleardevice();
	 rectangle(0,0,getmaxx(),getmaxy());
	 circle(x,y,r);
	 if(px<=x+r && px+pr>x-r && y+r>=py-pr && y-r<py+pr){
	   srand(time(0));

	   px = rand() % 200;
	   py = rand() % 200;
	   score+=20;
	   circle(px,py,pr);
	   floodfill(px,py,WHITE);

	   if(score % 100 == 0 && score != 0){
	      n+=2;
	      level++;
	   }

	 }else{
	 circle(px,py,10);
	 floodfill(px,py,WHITE);

	 }
system("CLS");
	cout<<"Score: " << score<<endl;
	cout<<"max-x : " << getmaxx()<<endl;
	cout<<"max-y : " << getmaxy() << endl;
	cout<<"x : " << x <<endl;
	cout<<"y : " << y << endl;
	cout<<"ax : " << ax<<endl;
	cout<<"ay : " << ay << endl;
	cout<<"Level : " << level;
	}

exit(0);
getch();
return 0;
}

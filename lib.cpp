#include<cstring>
#include<iostream>
#include <winbgim.h> 

bool Check_Mouse(int x1,int y1,int x2,int y2,int x,int y){
	if(x1<x&&x<x2&&y1<y&&y<y2) return true; else return false;
}

void Ve_Nut(int x1,int y1, int x2, int y2,int color,int bgcolor, int thickness){ 
	setfillstyle(1,bgcolor);
	setcolor(color);
	setbkcolor(bgcolor); 
	bar(x1,y1,x2,y2);
	for (int i=0; i<=thickness; i++){
		rectangle(x1+i,y1+i,x2+i,y2+i);
	}
}

void Nut_So_Luong_Trang(bool test)
{
	if (test == true){
		setbkcolor(14);
		setcolor(1);
		Ve_Nut(40,260,200,300,0,14,1);
		outtextxy(80,270,"So Trang");
	}
	else if(test == false){
		Ve_Nut(40,260,200,300,0,14,1);
		setbkcolor(14);
		setcolor(0);
		outtextxy(80,270,"Bat dau");
	}
}

void Nut_Khung_Trang(bool test)
{
	if (test == true){
		Ve_Nut(275,260,435,300,0,14,1);
		setbkcolor(14);
		outtextxy(315,270,"So khung ");
	}
	else
		Ve_Nut(275,260,435,300,0,10,1);
		setcolor(0);
		outtextxy(315,270,"So khung ");
}

void Nut_Them_Trang(bool test)
{
	if (test == true){
		setbkcolor(14);
		setcolor(0);
		Ve_Nut(505,260,665,300,0,14,1);
		outtextxy(532,270,"(+) Trang");		
	}
	else{
		Ve_Nut(505,260,665,300,0,10,1);
		setcolor(0);
		setbkcolor(10);
		outtextxy(532,270,"(+) Trang");		
	}
}

void Nut_Bam(){
	settextstyle(8, HORIZ_DIR, 1);
	Nut_So_Luong_Trang(false);
	Nut_Khung_Trang(false);
	Nut_Them_Trang(false);
}

void VeHinhChuNhat(int x1,int y1, int x2, int y2,int color, int thickness){
	settextstyle(0,0,1);
	setcolor(color);
	for (int i=0; i<=thickness; i++){
		rectangle(x1+i,y1+i,x2+i,y2+i);
	}
}

void InPut(){
	setfillstyle(1,15);		
	bar(15,345,715,465);
	VeHinhChuNhat(20,350,720,470,4,1);
	settextstyle(8, HORIZ_DIR, 2);
	setcolor(1);
   	setbkcolor(15);
	outtextxy(30, 360, "InPut:   ");
	settextstyle(8, HORIZ_DIR, 1);
	setcolor(2);
	outtextxy(280, 360, "(Enter: Xac nhan  Backspace: Xoa ki tu	)");
}

void OutPut(){
	setfillstyle(1,15);
	bar(25,505,715,725);
	VeHinhChuNhat(20,500,720,720,4,1);
	settextstyle(8, HORIZ_DIR, 2);
   	setbkcolor(15);
   	setcolor(1);
	outtextxy(30,510,"OutPut: ");
} 

void Char_to_Str(int x,int y,char a){
	if(a=='1') outtextxy(x,y,"1");
	if(a=='2') outtextxy(x,y,"2");
	if(a=='3') outtextxy(x,y,"3");
	if(a=='4') outtextxy(x,y,"4");
	if(a=='5') outtextxy(x,y,"5");
	if(a=='6') outtextxy(x,y,"6");
	if(a=='7') outtextxy(x,y,"7");
	if(a=='8') outtextxy(x,y,"8");
	if(a=='9') outtextxy(x,y,"9");
	if(a=='0') outtextxy(x,y,"0");
}

void KhoiDong(){
	initwindow(750,750);
	int x,y;
	x=getmaxx();y=getmaxy();
	setbkcolor(15);	
	cleardevice();	

	Nut_Bam(); //cac phim
	InPut();//input
	OutPut(); //output
	
	setcolor(12);
	VeHinhChuNhat(20,90,720,230,4,1);//khung cho info 
	VeHinhChuNhat(10,10,730,730,4,1);//khung cho ca phan mem  
	settextstyle(1, 0, 4);
	setcolor(2);
	setbkcolor(15);
	outtextxy(100,20,"Mon: HE DIEU HANH");
	line(185,50,517,50);
	setcolor(1);
	settextstyle(8, HORIZ_DIR, 2);
	outtextxy(30,95,"Giang vien:   Huynh Thanh Tam");
	outtextxy(30,120,"Ho va Ten SV: Vo Quang Tuong");
	outtextxy(30,145,"MSSV:         N19DCCN185");
	outtextxy(30,180,"De tai 7:     Mo phong cac giai thuat thay the trang ");
	outtextxy(160,205,"   theo thuat toan FIFO (First In First Out)");
	//hang ngang
}

#include <winbgim.h>
#include "queue.h" 
#include "lib.h"
#include <math.h>
#include<iostream>
using namespace std;
//----------------------------------------------------------------
bool DaCoNumPages = false;
bool DaCoNumFrames = false;

int SoLuongTrang = 0;
int SoLuongKhungTrang = 0;
int DemSoTrang = 0;
int DemTrangLoi = 0;

Queue deBai;//Hang doi chua cac trang nhap tu ban phim
Queue FIFO;//hang doi khung trang

//==========================Xu Ly Mang============================
void insert_first(int A[], int n, int x){
	for(int i=n;i>=1;i--){
	   A[i]=A[i-1];
	}
	A[0]=x; 
	n++;
	}

int Find_Address_X(int A[], int n, int x){
    for(int i=0;i<n;i++)
        if(A[i]==x)
            return i;
}

void insert_index(int A[], int x, int address){
	A[address] = x;
}

int KiemTraTrung(int A[], int n, int x){
	int flag=0;
	for(int i=n-1; i>=0 && !flag; i--)		
		if(A[i] == x)
			flag=1;
	return flag;
}
//==========================Do Hoa OutPut============================
void int_to_char_seted(int value, int i, int j,int bgcolor){//i: chieu ngang(trang), j: chieu doc (khung trang)
	char arr0[50];
	setcolor(0);
	setbkcolor(bgcolor);
	sprintf(arr0,"%d",value);
	outtextxy(70+(i*31),(557+j*31),arr0);	
}
void int_to_char_default(int value, int i, int j){//i: chieu ngang(trang), j: chieu doc (khung trang)
	char arr1[50];
	sprintf(arr1,"%d",value);
	setbkcolor(15);
	outtextxy(i,j,arr1);	
}

void load_khung(int page, int frame){	//hang doc
	OutPut();
	setcolor(0);
	for (int i = 0; i <=page; i++){
		line(90+31*i, 550, 90+31*i, 550 +31*frame);
	}
	
	for (int i = 0; i <= frame; i++){	//hang ngang
		line(90,550+31*i,90+31*page, 550+31*i);
	}
	setcolor(4);
	for(int i=0;i<SoLuongKhungTrang;i++){
		settextstyle(8, HORIZ_DIR, 2);
		int_to_char_default(i+1,70, 557+(i*31));//in so khung trang
		}
	}

//==========================InPut============================
void input_Num_Pages(){
	InPut();//ve khung input ra man hinh
   	settextstyle(8, HORIZ_DIR, 2);
   	setbkcolor(15);
   	setcolor(0);
	outtextxy(30, 400, "Nhap so luong trang:                   (0 < N <= 20)");
	VeHinhChuNhat(310,390,390,440,4,1);//hinh chu nhat bao quanh so nhap vao
	setcolor(0);
	char s[20];
	int d = 0;
	setcolor(4);
	while (true){
		s[d] = getch();
		if (!(('0' <= s[d] && s[d] <= '9') || s[d] == 13 || s[d] == 8 ))//nhan phim != 0-9, backspace, enter thi nhap lai
			continue;
		if (d == 3){//chi cho nhap toi da 3 ki tu
			if (s[d] != 13 && s[d] != 8){
				s[2] = s[3];
				d--;
			}
		} 
		if (s[d] == 13){//phim enter
			if (d == 0)//chuoi rong =>> nhap lai
				continue;
			else{
				settextstyle(8, HORIZ_DIR, 2);
				char xau[d];
				for (int i = 0; i <= d - 1; i++){
					xau[i] = s[i];
					xau[d] = '\0';
				}
				int t = atoi(xau); //atoi: chuyen doi str sang int
				settextstyle(8, HORIZ_DIR, 2);
				if(t<=20){
					SoLuongTrang = t;
					break;
				}
				else{
					setcolor(4);
					outtextxy(105,445, "So trang vuot qua 20! Vui long nhap lai !!");
					continue;
				}
			}
		}
		else if (s[d] == 8){//phim backspace de xoa ki tu (phai sang trai)
			setfillstyle(1, 15);
			bar(330 + 15 * (d - 1), 400, 330 + 15 * (d), 420);
			d--;
			if (d == -1)
				d = 0;
			continue;
		}
		else
			setcolor(2);
			settextstyle(8, HORIZ_DIR, 3);
		Char_to_Str(330+ 15 * d, 400 , s[d]);
		d++;
	}
	bar(277,262,434,299);
	outtextxy(315,270,"So khung ");
}

void input_Num_Frames(){
	InPut();
   	settextstyle(8, HORIZ_DIR, 2);
   	setbkcolor(15);
   	setcolor(0);
	outtextxy(30, 400, "Nhap so khung trang:                   (3 <= N <= 4)");
	VeHinhChuNhat(310,390,390,440,4,1);
	setcolor(0);
	char s[20];
	int d = 0;
	setcolor(4);
	while (true){
		s[d] = getch();
		if (!(('0' <= s[d] && s[d] <= '9') || s[d] == 13 || s[d] == 8))
			continue;
		if (d == 3){
			if (s[d] != 13 && s[d] != 8){
				s[2] = s[3];
				d--;
			}
		} 
		if (s[d] == 13){
			if (d == 0)
				continue;
			else{ 
				settextstyle(8, HORIZ_DIR, 2);
				char xau[d];
				for (int i = 0; i <= d - 1; i++){
					xau[i] = s[i];
					xau[d] = '\0';
				}
				int t = atoi(xau); 
				settextstyle(8, HORIZ_DIR, 2);
				if(t==3 or t==4){
					SoLuongKhungTrang = t;
					break;
				}
				else{
					setcolor(4);
					outtextxy(95,445, "So khung trang khong hop le! Vui long nhap lai !!");
					continue;
				}
			}
		}
		else if (s[d] == 8){
			setfillstyle(1, 15);
			bar(330 + 15 * (d - 1), 400, 330 + 15 * (d), 420);
			d--;
			bar(95,445,720,470);
			if (d == -1)
				d = 0;
			continue;
		}
		else
			setcolor(2);
			settextstyle(8, HORIZ_DIR, 3);
		Char_to_Str(330+ 15 * d, 400 , s[d]);
		d++;
	}
		bar(507,262,664,299);
		outtextxy(532,270,"(+) Trang");
	}

void input_Num_Values(){
	InPut();
   	settextstyle(8, HORIZ_DIR, 2);
   	setbkcolor(15);
	setcolor(0);
	outtextxy(30, 390, "Nhap ten trang thu   :");
	int_to_char_default(DemSoTrang+1,260, 390);
	VeHinhChuNhat(310,380,390,430,4,1);
	
	setcolor(2);
	settextstyle(8, HORIZ_DIR, 2);
	outtextxy(30,440,"(So luong trang:");
	line(45,460,250,460);
	setcolor(4);
	int_to_char_default(SoLuongTrang,230,440);

	setcolor(2);
	outtextxy(490,440,"So luong khung:  )");
	line(500,460,690,460);
	setcolor(4);
	int_to_char_default(SoLuongKhungTrang,675,440);

	char s[20];
	int d = 0;
	setcolor(4);
	while (true){
		s[d] = getch();
		if (!(('0' <= s[d] && s[d] <= '9') || s[d] == 13 || s[d] == 8))
			continue;
			
		if (d == 3){
			if (s[d] != 13 && s[d] != 8){
				s[2] = s[3];
				d--;
			}
		} 				
		if (s[d] == 13){
			if (d == 0)
				continue;
			else{ 
				settextstyle(8, HORIZ_DIR, 2);
				char xau[d];
				for (int i = 0; i <= d - 1; i++){
					xau[i] = s[i];
					xau[d] = '\0';
				}
				int t = atoi(xau); 
				settextstyle(8, HORIZ_DIR, 2);
				setcolor(4);
	  			int_to_char_default(t,101+DemSoTrang*31,526);
				if(DemSoTrang == SoLuongTrang -1 ){
   					setcolor(4);
   					outtextxy(415,390, "Da nhap du so luong !!");
   					deBai.push(t);
   					break;
	  			}
	  			deBai.push(t);
				DemSoTrang++;
				input_Num_Values();	
				break;
			}
		}
		else if (s[d] == 8){
			setfillstyle(1, 15);
			bar(330 + 15 * (d - 1), 390, 330 + 15 * (d), 410);
			d--;
			if (d == -1)
				d = 0;
			continue;
		}
		else
			setcolor(2);
			settextstyle(8, HORIZ_DIR, 3);
			Char_to_Str(330+ 15 * d, 390 , s[d]);
			d++;
	}
}

void RUN(){
	int A[SoLuongKhungTrang];
	for(int i=0;i<SoLuongKhungTrang; i++){
		A[i]= 99*(pow(10,i));
	}
	int count = 0;
	int dem =0;
	bool khoitao = false;
	int old0 = 999;
	int old1 = 999;
	int old2 = 999;
	int old3 = 999;	
	while (!deBai.empty()){
		int tempdeBai;
		deBai.pop(tempdeBai); //lay trang dau tien trong tong so trang da nhap vao
		if (KiemTraTrung(A,SoLuongKhungTrang,tempdeBai) == true){//neu trang lay vao da co trong bo nho , bo qua, lay trang khac
			dem++;
			delay(1000);
			int_to_char_seted(old0,dem,0,15);
			int_to_char_seted(old1,dem,1,15);
			int_to_char_seted(old2,dem,2,15);	
			if (SoLuongKhungTrang == 4){
				int_to_char_seted(old3,dem,3,15);	
			}	
			continue;	
		}
		 //khoi tao cac khung trang dau tien	
		if(khoitao == false ){	
			insert_first(A, SoLuongKhungTrang, tempdeBai);
			DemTrangLoi++;
			dem++;	
			if(count == 0){
				delay(1000);
				int_to_char_seted(tempdeBai,dem,0,15);				
				old0 = tempdeBai;
				count++;			
			}
			else if(count == 1){
				delay(1000);
				int_to_char_seted(old0,dem,0,15);
				delay(1000);
				int_to_char_seted(tempdeBai,dem,1,15);					
				old1 = tempdeBai;
				count++;
			}
			else if (count == 2){
				delay(1000);
				int_to_char_seted(old0,dem,0,15);
				int_to_char_seted(old1,dem,1,15);
				delay(1000);
				int_to_char_seted(tempdeBai,dem,2,15);					
				old2 = tempdeBai;
				if(SoLuongKhungTrang == 4){
					count = 3;
				}
				else{				
					count=0;
					khoitao = true;
				}
			}
			else if (count == 3){
				delay(1000);
				int_to_char_seted(old0,dem,0,15);
				int_to_char_seted(old1,dem,1,15);
				int_to_char_seted(old2,dem,2,15);
				delay(1000);
				int_to_char_seted(tempdeBai,dem,3,15);					
				old3 = tempdeBai;
				count = 0;
				khoitao = true;				
			}
			FIFO.push(tempdeBai);
			setbkcolor(15);
			outtextxy(70+(dem*31), 557 + (SoLuongKhungTrang*31),"*");	
		}
//===============mang da day =>bat dau thay the trang================				
		else if(khoitao == true){
			dem++;//bien dung de tinh toan khoang cach & in ra cac trang
			DemTrangLoi++; //
			int address = 0;
			int tempFiFo = 0;
			//lay ra va xoa trang nam trong bo nho lau nhat 
			FIFO.pop(tempFiFo);
			//dia chi cua trang cu	
			address = Find_Address_X(A,SoLuongKhungTrang,tempFiFo);	
			//thay the trang cu thanh trang moi
			insert_index(A, tempdeBai, address);	
	 		if(count == 0){
	 			delay(1000);
	 			int_to_char_seted(tempFiFo,dem-1,0,10);
	 			delay(1000);
				if (SoLuongKhungTrang==4){
					int_to_char_seted(old3,dem,3,15);	
				}
	 			int_to_char_seted(old1,dem,1,15);
	 			int_to_char_seted(old2,dem,2,15);
	 			delay(1000);
	 			int_to_char_seted(tempdeBai,dem,0,15);	
	 			old0 = tempdeBai;
	 			count = 1;	
	 		}			
			else if (count == 1){
	 			delay(1000);
	 			int_to_char_seted(tempFiFo,dem-1,1,10);
				delay(1000);		
	 			int_to_char_seted(old0,dem,0,15);
	 			int_to_char_seted(old2,dem,2,15);
				if (SoLuongKhungTrang==4){
					int_to_char_seted(old3,dem,3,15);	
				}
	 			delay(1000);
	 			int_to_char_seted(tempdeBai,dem,1,15);
				old1 = tempdeBai;
				count = 2;	
			}			
			else if (count == 2){
	 			delay(1000);
	 			int_to_char_seted(tempFiFo,dem-1,2,10);				
				delay(1000);			
				int_to_char_seted(old0,dem,0,15);
				int_to_char_seted(old1,dem,1,15);
				if (SoLuongKhungTrang==4){
					int_to_char_seted(old3,dem,3,15);
					count = 3;	
				}
				else{
					count=0;
				}
				delay(1000);
				int_to_char_seted(tempdeBai,dem,2,15);		
				old2 = tempdeBai;
			}
			else if (count == 3){
	 			delay(1000);
	 			int_to_char_seted(tempFiFo,dem-1,3,10);					
				delay(1000);	
				int_to_char_seted(old0,dem,0,15);
				int_to_char_seted(old1,dem,1,15);
				int_to_char_seted(old2,dem,2,15);
				delay(1000);
				int_to_char_seted(tempdeBai,dem,3,15);					
				old3 = tempdeBai;	
				count = 0;			
			}
			FIFO.push(tempdeBai);
			//in ra dau * cho trang bi loi
			setbkcolor(15);
			outtextxy(70+(dem*31), 557 + (SoLuongKhungTrang*31),"*");			
		}
//=============================================================
	}
}

//==========================Main============================
int main(int argc, char *argv[])
{
	HWND hWnd = GetConsoleWindow();	
	ShowWindow(hWnd, SW_HIDE);
	KhoiDong();
	bool start = true; //dung de ngan chan click chuot sau khi da chay xong chuong trinh
	while (true){
		int x = mousex();
		int y = mousey();
		if (ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if(Check_Mouse(40,260,200,300,x,y) and start ==true){//Nut_So_Luong_Trang
				Nut_So_Luong_Trang(false);
				InPut(); // ve khung input
				OutPut();// ve khung onput
				DaCoNumPages = true;
				input_Num_Pages();
				start = true;
			}
			if(DaCoNumPages and start ==true){//Nut_Khung_Trang
				Nut_Khung_Trang(true);
				InPut();
				input_Num_Frames();
				load_khung(SoLuongTrang,SoLuongKhungTrang);
				DaCoNumFrames = true;
				start = true;
			}
			if(DaCoNumFrames and start == true){//Nut_Them_Trang
				Nut_Them_Trang(true);
				input_Num_Values();
				RUN();
				setbkcolor(15);
				outtextxy(100,695,"Ki hieu * la co loi trang va co   loi trang");
				setcolor(1);
				int_to_char_default(DemTrangLoi,480,695);
				start = false;
			}
		}	
		while (kbhit()){
			char s = getch();
				if (s == 27){
					setcolor(4);
					outtextxy(280,680,"Tam Biet!!");
					delay(2000);
				return 0;
			}
		}
	delay(0.1);
	}
	return 0;
}

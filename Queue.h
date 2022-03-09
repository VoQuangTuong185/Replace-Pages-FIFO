struct qNode{
	int data;
	qNode *next;
};
struct Queue{
	qNode *VTxoa;//xo�
	qNode *VTthem;//th�m
	Queue(){
		VTxoa=NULL;
		VTthem=NULL;
	}
	bool empty(){
		return (VTxoa==NULL);
	}
	void push(int value){//th�m v�o
		qNode *p= new qNode;
		p->data=value; //g�n gi� tri value duoc nhap v�o cho data cua con tri n�t p 
		p->next=NULL; // xo� o dau, th�m o cuoi=> cho p tro den NULL
		if (VTxoa==NULL){
			VTxoa = p;//th�m o cuoi
		}else {
			VTthem->next = p;//th�m o vitri bat ky
		}
		VTthem = p;
	}

	int pop(int &tmp){//lay ra v� xo�
		if (empty()) return -1;
		qNode *p = VTxoa;
		tmp = VTxoa->data; //loy gi� tro coa VTxoa do g�n cho bion tom tmp
		VTxoa = VTxoa->next;//cap nhat lai noi dung cua n�t VTxoa bang n�t ko sau n�
		delete p; //xo� con tro p
		return 1;
	}
	int get(int &tmp){//lay ra 
		if (empty()) return -1;
		qNode *p = VTxoa;
		tmp = VTxoa->data; 
		return 1;
	}
	// giai phong bo nho
	~Queue()
	{
		while (VTxoa != NULL) //khi d�y kh�c rong
		{
			qNode *tmp;//tao con tro tmp thuoc sNode 
			tmp = VTxoa;//g�n tmp bang n�t VTxoa
			VTxoa = VTxoa->next;//cap nhat node cu th�nh node ko sau cua n�
			delete tmp;//xo� tro tmp;
		}
	}
	
};




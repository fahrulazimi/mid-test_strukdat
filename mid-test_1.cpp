/*
	Nama 	  : Muhamad Fahrul Azimi
	NPM 	  : 140810180027
	Kelas	  : A
	Tahun	  : 2019
	Deskripsi : Program ini 
*/

// nama file : mid-test_1.cpp
#include <iostream>
using namespace std;

struct ElemtList{
	int no;
	char tim[20];
	char asal[20];
	int gol;
	ElemtList* next;
};

typedef ElemtList* pointer;
typedef pointer List;

void createList(List& First){
	First = NULL;
}

void createElement(pointer& pBaru){
	pBaru = new ElemtList;
	cout << "Input No Daftar : "; cin >> pBaru->no;
	cout << "Input Tim : "; cin >> pBaru->tim;
	cout << "Input Asal Daerah : "; cin >> pBaru->asal;
	pBaru->next = NULL;
}
void createGol(List& First, pointer& pBaru){
	pointer q;
	q=First;
	for (int i=0; i<6; i++){
		cout << "Input GOL : "; cin >> q->gol;
		q=q->next;
	}
}

void insertLast(List& First, pointer pBaru){
	pointer last;
	if (First==NULL){
		First=pBaru;
	}
	else {
		last=First;
		while (last->next!=NULL){
			last=last->next;
		}
		last->next=pBaru;
	}
}

void sorting(List& First){
    pointer pPindah;
    for (int i=0; i<6; i++){
		pPindah = First;
		for (int j=0; j<5; j++){
			if(pPindah->gol < pPindah->next->gol){
			swap(pPindah->tim, pPindah->next->tim);
			swap(pPindah->asal, pPindah->next->asal);
			swap(pPindah->gol, pPindah->next->gol);
			}
			pPindah = pPindah->next;
		}
	}
}

void traversal(List First){
	pointer pB;
    cout<<"\tDAFTAR TIM\n";
    cout<<"( NO DAFTAR TIM	ASAL DAERAH GOL)\n\n";
    if (First==NULL){
        cout<<"    ^^LIST TIM KOSONG^^\n";
    }
    else{
        pB=First;
        while(pB!=NULL){
            cout << pB->no << "	" << pB->tim << "	" << pB->asal <<endl;
            pB=pB->next;
        }
    }
}

void traversalGol(List First){
	pointer pB;
    cout<<"\tDAFTAR TIM\n";
    cout<<"( NO DAFTAR TIM	ASAL DAERAH GOL)\n\n";
    if (First==NULL){
        cout<<"    ^^LIST TIM KOSONG^^\n";
    }
    else{
        pB=First;
        while(pB!=NULL){
            cout << pB->no << "	" << pB->tim << "	" << pB->asal << "	" << pB->gol <<endl;
            pB=pB->next;
        }
    }
}

int main(){
	pointer p,q;
	List a;
	cout << "TIM SEPAK BOLA\n\n";
	createList(a);
	for (int i=0; i<6; i++){
		createElement(p);
		insertLast(a,p);
	}
	traversal(a);
	createGol(a,p);
	sorting(a);
	traversalGol(a);
}

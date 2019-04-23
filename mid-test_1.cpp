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
void createGol(pointer& pBaru){
	cout << "Input GOL : "; cin >> pBaru->gol;
	pBaru->next = NULL;
}


void insertFirst(List& First, pointer pBaru){
	if (First==NULL){
		First=pBaru;
	}
	else{
		pBaru->next=First;
		First=pBaru;
	}
}

void tukar(pointer& a,pointer& b){
    int temp = a->gol;
    a->gol = b->gol;
    b->gol = temp;
}

void sorting(List& First){
    int swapped, i;
    pointer ptr1;
    pointer lptr = NULL;

    if (First == NULL)
        return;
    do{
        swapped = 0;
        ptr1 = First;

        while(ptr1->next!=lptr){
            if (ptr1->gol>ptr1->next->gol){
                tukar(ptr1,ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while(swapped);
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
            cout << pB->no << "	" << pB->tim << "	" << pB->asal << "	" << pB->gol <<endl;
            pB=pB->next;
        }
    }
}

int main(){
	pointer p;
	List a;
	int pil;
	createList(a);
	do{
		system("cls");
		traversal(a);
		cout << "Menu" <<endl;
		cout << "1. Insert Tim" <<endl;
		cout << "2. Update Gol" <<endl;
		cout << "3. Sorting Gol" <<endl;
		cout << "4. Exit" <<endl;
		cout << "Pilih (1-4): "; cin >> pil;
		switch(pil){
			case 1 :
			system("cls");
			createElement(p);
			insertFirst(a,p);
			break;
			case 2 :
			createGol(a);
			case 3 :
			system("cls");
			sorting(a);
			break;
			case 4 :
			cout << "^^Terima Kasih Telah Menggunakan Program Ini^^";
			break;
			default :
			cout << "^^ANGKA YANG ANDA INPUT SALAH^^" <<endl;
			break;
		}
	}while(pil!=4);
	
}

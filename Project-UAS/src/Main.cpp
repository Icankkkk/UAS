#include "linked_list.h"
#include "queue.h"

// fungsi ini digunkan untuk menampilkan menu utama
// yang terdiri dari menu linked_list dan queue
void menu_utama(short int& n)
{	
	system("clear");
	cout << "1. Linked List\n"
		 << "2. Queue\n"
		 << "3. Keluar\n\n"
		 << "[1/2/3]... ? "; cin >> n;
}

// fungsi utama
int main() 
{
   short int pil;	// digunakan untuk switch case

   do {
   	// menampilkan menu utama
   	menu_utama(pil);
   	switch(pil) {
   		case 1: linked_list(); break;
   		case 2: queue_menu(); break;
   		case 3: system("clear"); exit(0);
   	}
   	
   } while (pil != 3);
   
	return 0;
}

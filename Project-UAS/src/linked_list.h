/* Nama : Muhamad Faisal
   NIM : 191011401460
   Kelas : 04TPLP014
*/
#include "library.h"

#ifndef LINKED_LIST
#define LINKED_LIST

// class untuk node
class Node {
public:
	string nama_pasien;	// untuk nama pasien
	short int id_pasien; // untuk no urut pasien

	Node* next;	// pointer
};

// fungsi untuk mencetak seluruh data pasien
void cetak_pasien(Node* n) {
	short int data = 0;	// untuk menjumlah total pasien

	cout << "\nData pasien didalam daftar:\n";
	// jika pointer tidak null, maka looping akan terus dijalankan (mencetak)
	while(n != nullptr)
	{	
		cout << "Data ke-" << data++ << ":\n";
		cout << "Nama Pasien\t: " << n -> nama_pasien << '\n';
		cout << "ID Pasien\t: " << n -> id_pasien << '\n';

		n = n -> next;	// menunjuk ke alamat pointer selanjutnya
	}
	cout << '\n';
}

// fungsi ini digunakan untuk mengisi data pada sebuah node pointer
// yang mana user menginput melalui keyboard
void isi_data_pasien(Node* nilai) {
	cout << "Masukan nama pasien\t: "; cin >> nilai -> nama_pasien;
	cout << "Masukan ID pasien\t: "; cin >> nilai -> id_pasien;
}

// fungsi ini digunakan untuk menambah data dari depan (head)
void push_head(Node** ref) {
	Node* node_baru = new Node();	// alokasi pada memori menggunakan key 'new' 

	isi_data_pasien(node_baru);	// memanggil fungsi isi_data_pasien
	node_baru -> next = *ref;	// pointer ke atau diisi pointer
	*ref = node_baru;
}

// fungsi ini digunakan untuk menambah data dari belakang (back)
void push_back(Node** ref) {
	Node* node_baru = new Node();	// alokasi memori atau node baru
	Node* last = *ref;	// pointer to pointer

	isi_data_pasien(node_baru);	// memanggil fungsi untuk mengisi data
	node_baru -> next = nullptr;	// node baru dialamatkan ke pointer next dan diisi dengan null

	// kondisi
	while(last -> next != nullptr) 
		last = last -> next;
		last -> next = node_baru;	
}

// fungsi ini digunakan untuk menghapus data atau node
// sesuai posisi yang ditentukan oleh user
void hapus_data(Node** ref, short int &pos) {
	// kondisi, jika list kosong
	if(*ref == nullptr) return;
	// store node depan
	Node* temp = *ref;
	// memberikan posisi data atau node sesuai input atau posisi
	cout << "Data keberapa yang ingin di hapus ?\n"
		 << "key (posisi) : "; cin >> pos;

		 if(pos == 0) {
		 	// ubah node depan
		 	*ref = temp -> next;
		 	// free
		 	delete(temp);
		 	return;
		 }

		 for(int i = 0; temp != nullptr && i < pos - 1; i++)
		 	temp = temp -> next;
		    // If position is more than number of nodes
		    if(temp == nullptr || temp -> next == nullptr)
		    return;

		    // Node temp->next is the node to be deleted
		    // Store pointer to the next of node to be deleted
		    Node *next = temp->next->next;
		    // Unlink the node from linked list
		    delete(temp->next);
		    // unlink the deleted node from list
		    temp->next = next;  
}

// fungsi ini digunakan untuk menghapus atau mengosongkan
// seluruh data 
void hapus_daftar(Node** ref) {
	Node* current = *ref;
	Node* next = nullptr;	// alokasi pointer next ke null

	// looping 
	while(current != nullptr) {
		next = current -> next;
		delete(current);	// hapus pointer atau node "current"
		current = next;
	}
	*ref = nullptr;
}

// fungsi untuk keluar
void keluar() {
    cout << "Keluar dari menu linked list...\n";
		sleep(1);	// digunakan untuk menjeda selama 1 detik
		system("clear");	// untuk clear screen
}

// tampilan menu untuk linked list
void linked_list() {
	// deklarasi atau inisialisasi awal dengan null
	Node* tmp = nullptr;
	short int n, posisi;

	// membersihkan layar (linux or unix)
	system("clear");
	cout << "  MENU LINKED LIST\n"
		 << "--------------------\n"
		 << "1. tambah depan\n"	
		 << "2. tambah belakang\n"	
		 << "3. cetak\n"	
		 << "4. hapus data\n"	
		 << "5. hapus daftar\n"
		 << "6. keluar\n\n";

	do {
		cout << "\nMasukan pilihan\t: "; cin >> n;	
		switch(n)
		{
			case 1: push_head(&tmp); break;	// sisip melalui depan
			case 2: push_back(&tmp); break;	// sisip melalui belakang
			case 3: cetak_pasien(tmp); break;	// mencetak daftar pasien
			case 4: hapus_data(&tmp, posisi); break;	// menghapus node atau data sesuai posisi 
			case 5: hapus_daftar(&tmp); break;	// menghapus seluruh node atau data
			case 6: keluar(); break;	// keluar dari menu 
			default: printf("Tidak ada dalam menu!\n\n"); break;
		}
		
	}while(n != 6);	// perulangan
	
}
#endif // LINKED_LIST

/*
	pengimplementasian queue 
	menggunakan array
	studi kasus:
	dimana sebuah rumah sakit membutuhkan program untuk mendata antrian
	pasien nya, maka dibuatlatsebuah program queue dengan konsep FIFO (first in first out).
*/

#include "library.h"

struct Queue {
	int front;	// untuk depan
	int rear; // untuk blakang
	int size; // untuk jumlah kapasitas antrian

	// pointer
	string *queue;
	// constructor
	Queue(int n) {
		front = rear = 0;	// inisialisasi atau deklarasi dengan 0
		size = n; // store var size dengan var n
		queue = new string;	// alokasi
	}

	// fungsi untuk memasukan sebuah elemen pada bagian belakang queue
	void queue_enqueue(string data) {
		// cek apakah queue penuh atau tidak
		if (size == rear) {
			cout << "\nAntrian sudah penuh\n";
			return;
		}
		// memasukan element ke belakang
		else {
			queue[rear] = data;
			rear++; // ditambahan sebesar 1
		}
		return;
	}
	// fungsi ini digunakan untuk menghapus sebuah element
	// dari depan dalam antrian
	void queue_dequeue() {
		// jika antrian masih kosong
		if (front == rear) {
			cout << "\nAntrian masih kosong\n";
			return;
		}
		// geser semua elemen dari inedeks 2 hingga belakang
		// ke kiri satu persatu
		else {
			for (int i = 0; i < rear - 1; i++) {
				queue[i] = queue[i+1];
			}
			// decrememt rear
			rear--; // di ambil atau di kurang sebesar 1
		}
		return;
	}

	// fungsi ini digunakan untuk mencetak semua element
	// yang terdaftar pada antrian
	void queue_cetak() {
		int i;
		// jika antrian kosong
		if (front == rear) {
			cout << "\nAntrian masih kosong\n";
			return;
		}
		// traverse atau balik bagian depan ke belakang
		// dan lalu cetak element
		cout << "dalam antrian : ";
		for (i = front; i < rear; i++) {
			cout << queue[i] << " <-- ";
		}
		cout << '\n';
		return;
	}

	// fungsi ini digunakan untuk mencetak bagian depan pada antrian
	void queue_front() {
		// cek jika queue kosong
		if (front == rear) {
			cout << "\nAntrian masih kosong\n";
			return;
		}
		cout << "\nElement atau antrian depan : " << queue[front] << '\n';
		return;
	}

}; // bracket struct
// menu
void menu() {
	cout << "  MENU PADA QUEUE\n"
		 << "-------------------\n"
		 << "1. Input\n"
		 << "2. Hapus\n"
		 << "3. Cetak antrian\n"
		 << "4. Cetak bagian depan\n"
		 << "5. Keluar\n";
}

// fungsi untuk keluar
void exit() {
    cout << "Keluar dari menu queue...\n";
    sleep(1);
    system("clear");
}
	
void queue_menu() {
	// membuat kapasitas antrian
	Queue q(4);
	// untuk argument fungsi
	string nama_pasien;
	// untuk switch case
	short int pil;

	// membersihkan layar pada linux
	system("clear");
	// menu
	menu()
		 do {
		 	cout << "\nMasukan pilihan : "; cin >> pil;
		 	switch(pil) {
		 		case 1: cout << "Masukan nama pasien : "; cin.ignore();
		 			    getline(cin, nama_pasien);
		 				q.queue_enqueue(nama_pasien); break;
		 		case 2: q.queue_dequeue(); break;
		 		case 3: q.queue_cetak(); break;
		 		case 4: q.queue_front(); break;
		 		case 5: exit(); break;
		 		default: printf("Tidak ada dalam menu!\n\n"); break;
		 	}
		 	
		 } while (pil != 5);
		 /*
		 	ketika pilihan selain 5 maka nilai nya akan true
			dan akan terus melakukang perulangan
		 */		 
}







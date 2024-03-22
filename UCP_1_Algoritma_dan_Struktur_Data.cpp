/*1. Bubble sort membandingan elemen membandingan array yang bersebelahan.
	 Misalnya Array[0] akan dibandinkan dengan array[1], Apabila elemen
	 Array[0] lebih besar dari elemen Array[1] maka elemen pada kedua array
	 tersebut ditukar. Selanjutnya Array[1] akan dibandingkan dengan Array[2]
	 lalu akan dicek lagi apakah elemen Array[1] lebih besar dari elemen Array[2],
	 jika iya maka kedua elemen tersebut ditukar, jika tidak dilanjutkan scanning ke
	 array berikutnya. begitu seterusnya sampai dengan pass n - 1.
  2. Algoritma shell sort akan membagi array yang akan dicek dengan menggunakan
	 interval. Misalnya array dibagi menjadi 3 bagian menggunakan interval.
	 pada setiap interval akan dilakukan pengecekan dan penukaran elemen apabila
	 kondisinya terpenuhi. Pengecekan dan penukaran ini mengunakan algoritma insertion
	 sort. Yang dimana array akan dibagi menjadi dua bagian yaitu bagian yang sudah terurut
	 dan yang belum.
	 Elemen pertama pada array yang belum terurut akan dimasukkan kedalam variable temp
	 lalu akan dilakukan pengecekan yang dimana apabila counter j >= 0 && arr[j] > temp
	 maka arr[j+1] akan dimasukkan nilai dari variable temp.
	 lalu counter j akan diturunkan nilainya.
	 Pengecekan ini berlangsung sampai dengan n-1. lalu semua pembagian array akan disatukan
	 kembali. dan dibagi lagi menjadi interval yang lebih kecil dan dilakukan pengecekan lagi.
	 yang menggunakan langkah yang sama seperti sebelumnya sampai semua data terurut.
  3. Jika kasusnya sudah banyak data yang terurut. Maka algoritma yang paling efisien adalah
	 algoritma insertion sort. Pada algoritma insertsion sort, jika data sudah banyak terurut
	 kita hanya perlu melakukan satu perbandingan dalam satu pass sehingga tidak banyak kode
	 yang dieksekusi. Hal ini mengakibatkan kecepatan dalam menggurutkan data meningkat.
  4. 	 */
#include <iostream>
using namespace std;

int n;				//Deklarasi variable global
int Zhilal[95];

void input() {	//Prosedur input
	while (true) {		//Perulangan untuk input jumlah elemen array
		cout << "Masukkan jumlah elemen array = ";
		cin >> n;
		if (n <= 95) {
			break;
		}
		else {		//Peringatan jumlah elemen array melebihi batas maksimal
			cout << "Jumlah maksimal elemen array adalah 95" << endl;
			cout << "Silahkan coba lagi" << endl;
			cout << "=======================================" << endl;
		}
	}

	for (int i = 0; i < n; i++) {	//Perulangan untuk input nilai ke dalam array
		cout << "Masukkan data ke - " << i + 1 << " = ";
		cin >> Zhilal[i];
	}
}

void algoritmaSortir() {	//Prosedur sortir dan menampilkan data yang disortir
	for (int j = 0; j <= n - 2; j++) {	//step 1
		int min_index = j;	//step 2a
		for (int i = j + 1; i <= n - 1; i++) {	//step 2b
			if (Zhilal[i] < Zhilal[min_index]) {	//step 2c
				min_index = i;
			}
		}
		int temp = Zhilal[j];	//step 3
		Zhilal[j] = Zhilal[min_index];
		Zhilal[min_index] = temp;

		cout << "\nPass " << j + 1 << " = ";	//Menampilkan data yan disortir setiap pass
		for (int k = 0; k < n; k++) {
			cout << Zhilal[k] << " ";
		}
		cout << endl;
	}
}

void display() {	//Prosedur display
	cout << "========================" << endl;
	cout << "Nilai yang sudah terurut" << endl;
	cout << "========================" << endl;
	for (int i = 0; i < n; i++) {	//Perulangan untuk menampilkan array yang sudah tersusun
		cout << Zhilal[i];
		if (i < n - 1) {
			cout << " --> ";
		}
	}
}

int main() {
	input();	//Memanggil prosedur untuk dijalankan
	algoritmaSortir();
	display();

	return 0;
}
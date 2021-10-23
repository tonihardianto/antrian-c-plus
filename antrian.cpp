#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>

using namespace std;

const int MAX_ANTRIAN = 8;

struct orang
{
    string nama;
    int umur;
};

void buatAntrian(); // mengisi antrian kosong sebanyak MAX_ANTRIAN dengan variabel kontrol
void tampilkanMenu(); // menampilkan menu yang ada
void eksekusiPilihan(); // mengambil pilihan dari user dan eksekusi pilihan tersebut
void tambahAntrian(); // menambah antrian paling belakang
void kurangiAntrian(); // mengurangi antrian paling depan dan menampilkan orang yang keluar dari antrian
void printAntrian(); // menampilkan seluruh antrian yang ada
void printOrang(); // menampilkan data satu orang saja

//inisisalisasi variabel yang akan dipakai
orang antrian[MAX_ANTRIAN];
int pil, pripil, antri;

bool isEmpty = true; // penanda apakah antrian sedang kosong
bool isFull = false; // penanda apakah antrian sudah penuh
bool isOver = false; // penanda bahwa program selesai atau tidak

/**
* ================== MAIN PROGRAM ===================
*/
int main()
{
    buatAntrian();
    while(!isOver)
    {
        tampilkanMenu();
        eksekusiPilihan();
    }
    system("pause");
    return 0;
}
/**
* ============== END OF MAIN PROGRAM ================
*/

//mengisi data awal dari antrian
void buatAntrian()
{
    int i;
    for(i=0; i<MAX_ANTRIAN; i++)
    {
        antrian[i].nama = "null"; // antrian dikatakan kosong apabila nama = null
        antrian[i].umur = -1; // dan umur = -1
    }
}

//menampilkan menu utama
void tampilkanMenu()
{
    system("cls");
    cout << "(1) tambah antrian" << endl;
    cout << "(2) kurangi antrian" << endl;
    cout << "(3) print antrian" << endl;
    cout << "(4) keluar dari program" << endl;
    cout << "masukkan pilihan anda: ";
    cin >> pil; //kesatu
}

//pemrosesan pilihan dari menu utama
void eksekusiPilihan()
{
    if (pil == 1)
    {
        tambahAntrian();
    }
    else if (pil == 2)
    {
        kurangiAntrian();
    }
    else if (pil == 3)
    {
        //pada pilihan ini ditambahkan submenu print semua atau satu saja
		cout << "(1) print semua antrian" << endl;
        cout << "(2) print satu antrian" << endl;
        cout << "pilihan : ";
        cin >> pripil;
        if (pripil == 1)
        {
            printAntrian();
        }
        else if (pripil == 2)
        {
            printOrang();
        }
    }
    else if (pil == 4)
    {
        isOver = true;
    }
}

//prosedur untuk penambahan data antrian
void tambahAntrian()
{
    //diatur perulangan untuk memeriksa apakah ada antrian yang kosong
	int i;
    for(i=0; i<MAX_ANTRIAN; i++)
    {
        //jika ada antrian yang kosong, maka data bisa dimasukkan
		if(antrian[i].nama == "null" && antrian[i].umur == -1)
        {
            cout << "antrian ke-" << i+1 << " > " << endl;
            cout << "masukkan nama: ";
            cin >> antrian[i].nama;
            cout << "masukkan umur: ";
            cin >> antrian[i].umur;
            break;
        }
		//jika tidak ada yang kosong, maka tampilkan antrian penuh
        else
        {
            if (i == MAX_ANTRIAN-1)
            {
                cout << "antrian penuh" << endl;
            }
        }
    }
    system("pause");
}

//prosedur untuk mengurangi pengantri pertama, lalu antrian setelahnya maju.
void kurangiAntrian()
{
    int i;
	//tampilkan data yang akan dihapus
    cout << "antrian ke-1 telah dihapus" << endl;
    cout << "nama: " << antrian[0].nama << endl;
    cout << "umur: " << antrian[0].umur << endl;
	//hapus data dengan mengisi "null" dan -1
    antrian[0].nama = "null";
    antrian[0].umur = -1;
	
	//menggeser antrian ke atas
    for(i=0; i<MAX_ANTRIAN-1; i++)
    {
        antrian[i].nama = antrian[i+1].nama;
        antrian[i].umur = antrian[i+1].umur;
    }
	
	//mengisi antrian terakhir dengan data kosong
    antrian[MAX_ANTRIAN-1].nama = "null";
    antrian[MAX_ANTRIAN-1].umur = -1;
    system("pause");
}

//prosedur menampilkan data semua antrian 
void printAntrian()
{
    int i;
    for(i=0; i<MAX_ANTRIAN; i++)
    {
        cout << "antrian ke-" << i+1 << " > " << endl;
        if(antrian[i].nama == "null" && antrian[i].umur == -1)
        {
            cout << "KOSONG" << endl;
        }
        else
        {
            cout << "nama: " << antrian[i].nama << endl;
            cout << "umur: " << antrian[i].umur << endl;
        }
    }
    system("pause");
}

//prosedur untuk menampilkan data antrian perorang
void printOrang()
{
    cout << "antrian ke: ";
    cin >> antri;
    if(antrian[antri].nama == "null" && antrian[antri].umur == -1)
    {
        cout << "KOSONG" << endl;
    }
    else
    {
        cout << "nama: " << antrian[antri-1].nama << endl;
        cout << "umur: " << antrian[antri-1].umur << endl;
    }
    system("pause");
}

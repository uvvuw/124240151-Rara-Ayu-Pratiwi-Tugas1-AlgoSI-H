#include <iostream>
using namespace std;

string soldier[3] = {"Infantry", "Archer", "Kavaleri"};

struct data
{
    int ID;
    string general;
    string type;
    int jumlah;
};

data batalyon[100];
int jumlahBatalyon = 0;

bool cekTipePasukan(string type)
{
    string *ptr = soldier;
    for (int i = 0; i < 3; i++)
    {
        if (*(ptr + i) == type)
        {
            return true;
        }
    }
    return false;
}

bool cekJendral(string general)
{
    for (int i = 0; i < jumlahBatalyon; i++)
    {
        if (batalyon[i].general == general)
            return true;
    }
    return false;
}

bool logout()
{
    char pilihan;
    do
    {
        cout << "\nApakah Anda ingin kembali ke log out? (Y/N) : ";
        cin >> pilihan;
        if (pilihan == 'Y' || pilihan == 'y')
            return true;
        if (pilihan == 'N' || pilihan == 'n')
            return false;
        cout << "Pilihan tidak valid!" << endl;
    } while (true);
}

void tambahBatalyon()
{
    if (jumlahBatalyon >= 100)
    {
        cout << "\nBatas maksimal batalyon tercapai" << endl;
        return;
    }

    data newBatalyon;
    newBatalyon.ID = jumlahBatalyon + 1;

    cout << "Input General Name : ";
    cin.ignore();
    getline(cin, newBatalyon.general);

    if (cekJendral(newBatalyon.general))
    {
        cout << "\nNama jenderal sudah terdaftar" << endl;
        return;
    }

    cout << "Input Soldier Type (Infantry, Kavaleri, Archer) : ";
    cin >> newBatalyon.type;

    if (!cekTipePasukan(newBatalyon.type))
    {
        cout << "\nTipe pasukan tidak valid" << endl;
        return;
    }

    cout << "Input Soldier Qty : ";
    cin >> newBatalyon.jumlah;

    if (newBatalyon.jumlah < 1)
    {
        cout << "\nJumlah pasukan harus lebih dari 0" << endl;
        return;
    }

    batalyon[jumlahBatalyon++] = newBatalyon;
    cout << "\nBatalyon berhasil ditambahkan!" << endl;

    if (!logout())
    {
        cout << "\nKeluar dari program" << endl;
        exit(0);
    }
}

int binarySearch(string general)
{
    int left = 0, right = jumlahBatalyon - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (batalyon[mid].general == general)
            return mid;
        else if (batalyon[mid].general < general)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

void cariBatalyon()
{
    string nama;
    cout << "\nNama General yang ingin anda cari : ";
    cin.ignore();
    getline(cin, nama);

    int hasil = binarySearch(nama);
    if (hasil != -1)
    {
        cout << "\nGeneral ditemukan!\n";
        cout << "ID : " << batalyon[hasil].ID << endl;
        cout << "Nama : " << batalyon[hasil].general << endl;
        cout << "Tipe Pasukan : " << batalyon[hasil].type << endl;
        cout << "Jumlah Pasukan : " << batalyon[hasil].jumlah << endl;
    }
    else
    {
        cout << "\nBatalyon dengan nama general tersebut tidak ditemukan!" << endl;
    }

    if (!logout())
    {
        cout << "\nKeluar dari program" << endl;
        exit(0);
    }
}

void tampilkanMenu()
{
    int pilihan;
    while (true)
    {
        cout << "\nDaftar Menu\n";
        cout << "1. Tambah Batalyon\n";
        cout << "2. Cari Batalyon\n";
        cout << "Pilih Menu : ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            tambahBatalyon();
            break;
        case 2:
            cariBatalyon();
            break;
        default:
            cout << "\nPilihan tidak valid!" << endl;
        }
    }
}

int main()
{
    tampilkanMenu();
    return 0;
}
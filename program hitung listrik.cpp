#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

struct Alat
{
    string nama;
    float daya;  // Watt
    float jam;   // Jam
    float kwh;   // daya
    float biaya; // harga
};

const float TARIF = 1500; // harga per watt

// SUB PROGRAM
//  Input
void inputDataAlat(vector<Alat> &data)
{
    int n;
    cout << "Jumlah alat yang ingin dimasukkan: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        Alat a;
        cout << "\nAlat ke-" << i + 1 << endl;
        cout << "Nama alat: ";
        cin >> ws;
        getline(cin, a.nama);
        cout << "Daya (Watt): ";
        cin >> a.daya;
        cout << "Lama pemakaian (jam per hari): ";
        cin >> a.jam;

        a.kwh = (a.daya * a.jam) / 1000.0;
        a.biaya = a.kwh * TARIF;

        data.push_back(a);
    }
}

// Menampilkan tabel
void tampilkanData(const vector<Alat> &data)
{
    cout << "\n=====================================================================\n";
    cout << left << setw(5) << "No"
         << setw(20) << "Nama Alat"
         << setw(10) << "Watt"
         << setw(10) << "Jam"
         << setw(12) << "kWh/Hari"
         << setw(12) << "Biaya(Rp)"
         << endl;
    cout << "=====================================================================\n";

    for (int i = 0; i < data.size(); i++)
    {
        cout << left << setw(5) << i + 1
             << setw(20) << data[i].nama
             << setw(10) << data[i].daya
             << setw(10) << data[i].jam
             << setw(12) << fixed << setprecision(2) << data[i].kwh
             << setw(12) << fixed << setprecision(0) << data[i].biaya
             << endl;
    }
    cout << "=====================================================================\n";
}

// Hitung total
void hitungTotal(const vector<Alat> &data)
{
    float totalKwh = 0, totalBiaya = 0;

    for (auto &a : data)
    {
        totalKwh += a.kwh;
        totalBiaya += a.biaya;
    }

    cout << "\nTotal Konsumsi Listrik per Hari : " << totalKwh << " kWh";
    cout << "\nTotal Biaya Listrik per Hari    : Rp " << totalBiaya << endl;
}

// Sort besar-kecil
void sortingDesc(vector<Alat> &data)
{
    for (int i = 0; i < data.size() - 1; i++)
    {
        for (int j = 0; j < data.size() - i - 1; j++)
        {
            if (data[j].kwh < data[j + 1].kwh)
            {
                swap(data[j], data[j + 1]);
            }
        }
    }
    cout << "\nData diurutkan (boros → hemat).\n";
}

// Sort kecil-besar
void sortingAsc(vector<Alat> &data)
{
    for (int i = 0; i < data.size() - 1; i++)
    {
        for (int j = 0; j < data.size() - i - 1; j++)
        {
            if (data[j].kwh > data[j + 1].kwh)
            {
                swap(data[j], data[j + 1]);
            }
        }
    }
    cout << "\nData berhasil diurutkan (hemat → boros).\n";
}

// Edit data
void editData(vector<Alat> &data)
{
    if (data.empty())
    {
        cout << "Data masih kosong!\n";
        return;
    }

    int id;
    tampilkanData(data);
    cout << "\nPilih nomor alat yang ingin diedit: ";
    cin >> id;

    if (id < 1 || id > data.size())
    {
        cout << "Nomor tidak valid!\n";
        return;
    }

    id--; // index array

    cout << "Nama baru: ";
    cin >> ws;
    getline(cin, data[id].nama);
    cout << "Daya baru (Watt): ";
    cin >> data[id].daya;
    cout << "Jam baru: ";
    cin >> data[id].jam;

    data[id].kwh = (data[id].daya * data[id].jam) / 1000.0;
    data[id].biaya = data[id].kwh * TARIF;

    cout << "\nData berhasil diperbarui!\n";
}

// Hapus data
void hapusData(vector<Alat> &data)
{
    if (data.empty())
    {
        cout << "Data masih kosong!\n";
        return;
    }

    int id;
    tampilkanData(data);
    cout << "\nPilih nomor alat yang ingin dihapus: ";
    cin >> id;

    if (id < 1 || id > data.size())
    {
        cout << "Nomor tidak valid!\n";
        return;
    }

    data.erase(data.begin() + (id - 1));
    cout << "Data berhasil dihapus!\n";
}

// MAIN PROGRAM
void mainMenu()
{
    vector<Alat> data;
    int pilihan;

    do
    {
        cout << "\n========== PROGRAM PELACAK BIAYA & KONSUMSI LISTRIK ==========\n";
        cout << "1. Input Data Alat\n";
        cout << "2. Tampilkan Data\n";
        cout << "3. Hitung Total Biaya & Konsumsi\n";
        cout << "4. Urutkan Boros → Hemat (DESC)\n";
        cout << "5. Urutkan Hemat → Boros (ASC)\n";
        cout << "6. Edit Data\n";
        cout << "7. Hapus Data\n";
        cout << "0. Keluar\n";
        cout << "===============================================================\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            inputDataAlat(data);
            break;
        case 2:
            tampilkanData(data);
            break;
        case 3:
            hitungTotal(data);
            break;
        case 4:
            sortingDesc(data);
            break;
        case 5:
            sortingAsc(data);
            break;
        case 6:
            editData(data);
            break;
        case 7:
            hapusData(data);
            break;
        case 0:
            cout << "Keluar program...\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);
}

// Main
int main()
{
    mainMenu();
    return 0;
}

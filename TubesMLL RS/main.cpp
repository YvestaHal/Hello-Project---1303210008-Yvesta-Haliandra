#include "rs.h"

int main(){
    list_pasien LP;
    list_dokter LD;
    adr_dokter PD;
    adr_pasien PP;
    adr_relasi PR;
    infotype_pasien P;
    infotype_dokter D;
    string namapasien, namadokter, poli;
    int umur;

    createListPasien(LP);
    createListDokter(LD);
    int pilihan = Menu();
    while (pilihan != 0){
        switch(pilihan){
            case 1:
                cout << "Masukkan nama dokter: ";
                cin >> namadokter;
                cout << "Masukkan poli dokter: ";
                cin >> poli;
                D.nama = namadokter;
                D.poli = poli;
                PD = newDokter(D);
                insertFirstDokter(LD, PD);
                cout << "Berhasil ditambahkan." << endl;
                break;
            case 2:
                cout << "Masukkan nama pasien: ";
                cin >> namapasien;
                cout << "Masukkan umur pasien: ";
                cin >> umur;
                P.nama = namapasien;
                P.umur = umur;
                PP = newPasien(P);
                insertFirstPasien(LP, PP);
                cout << "Berhasil ditambahkan." << endl;
                break;
            case 3:
                cout << "Masukkan nama dokter: ";
                cin >> namadokter;
                PD = findDokter(LD, namadokter);
                if (PD != nil){ // Jika dokternya ada, maka ditampilkan
                    cout << "Berikut adalah data dokter " << namadokter << endl;
                    cout << "Nama: " << info(PD).nama << endl;
                    cout << "Poli: " << info(PD).poli << endl;
                } else {
                    cout << "Dokter tidak ditemukan" << endl;
                }
                break;
            case 4:
                cout << "Masukkan nama pasien yang ingin ditambahkan relasi: ";
                cin >> namapasien;
                PP = findPasien(LP, namapasien);
                if (PP != nil){ // Jika pasiennya ada, maka dilanjut ke proses berikutnya
                    cout << "Masukkan nama dokter yang ingin ditambahkan relasi: ";
                    cin >> namadokter;
                    PD = findDokter(LD, namadokter);
                    if (PD != nil){ // Jika dokternya ada, barulah relasinya ditambahkan
                        PR = newRelasi(PD);
                        insertRelasi(PP, PR);
                        cout << "Relasi berhasil ditambahkan" << endl;
                    } else {
                        cout << "Dokter tidak ditemukan" << endl;
                    }
                } else {
                    cout << "Pasien tidak ditemukan" << endl;
                }
                break;
            case 5:
                cout << "Masukkan nama dokter: ";
                cin >> namadokter;
                PP = findPasienByDokter(LP, namadokter);
                if (PP != nil){
                    cout << "Berikut adalah data pasien yang ditangani dokter " << namadokter << endl;
                    cout << "Nama: " << info(PP).nama << endl;
                    cout << "Umur: " << info(PP).umur << endl;
                } else {
                    cout << "Pasien tidak ditemukan" << endl;
                }
                break;
            case 6:
                cout << "Masukkan nama dokter yang ingin dihapus relasi: ";
                cin >> namadokter;
                PD = findDokter(LD, namadokter);
                if(PD != nil){
                    deleteDokterRelasi(LD, LP, namadokter);
                    cout << "Dokter " << namadokter << " dan relasinya berhasil dihapus" << endl;
                } else {
                    cout << "Dokter tidak ditemukan, tidak bisa dihapus" << endl;
                }
                break;
            case 7:
                cout << "Masukkan nama dokter yang ingin dihapus pasiennya: ";
                cin >> namadokter;
                PD = findDokter(LD, namadokter);
                if (PD != nil){
                    deletePasienByDokter(LP, namadokter);
                    cout << "Pasien yang ditangani dokter " << namadokter << " berhasil dihapus" << endl;
                } else {
                    cout << "Dokter tidak ditemukan, tidak bisa dihapus" << endl;
                }
                break;
            case 8:
                if (first(LD) == nil && first(LP) == nil){
                    cout << "List kosong, tidak bisa di print. Isi list terlebih dahulu." <<endl;
                } else{
                    printAll(LD, LP);
                }
                break;
            case 9:
                cout << "Masukkan nama dokter yang ingin dihitung pasiennya: ";
                cin >> namadokter;
                PD = findDokter(LD, namadokter);
                if (PD != nil){
                    cout << "Jumlah pasien yang ditangani dokter " << namadokter << " adalah " << countPasienByDokter(LP, namadokter) << endl;
                } else {
                    cout << "Dokter tidak ditemukan, tidak bisa dihitung" << endl;
                }
                break;
            case 10:
                if (first(LD) == nil && first(LP) == nil){
                    cout << "List kosong, tidak bisa di print. Isi list terlebih dahulu." << endl;
                } else{
                    printPoli(LD, LP);
                }
                break;
            default:
                cout << "Pilihan tidak ada" << endl;
                break;
        }
        pilihan = Menu();
    }
    return 0;
}

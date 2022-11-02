#include <iostream>

using namespace std;

struct TNode
{
    int data;
    TNode *next;
};
TNode *head, *head2; // global variabel

int isEmpty()
{
    if (head == NULL)
        return 1;
    else
        return 0;
}

void insertDepan(int databaru)
{
    TNode *baru;
    baru = new TNode;
    baru->data = databaru;
    baru->next = NULL;
    if (isEmpty() == 1)
    { // kosong
        head = baru;
    }
    else
    { // isi
        baru->next = head;
        head = baru;
    }
    cout << "Data masuk\n";
}

void insertBelakang(int databaru)
{
    TNode *baru;
    baru = new TNode;
    baru->data = databaru;
    baru->next = NULL;
    if (isEmpty() == 1)
    {
        head = baru;
    }
    else
    {
        TNode *bantu;
        bantu = head;
        while (bantu->next != NULL)
        {
            bantu = bantu->next;
        }
        bantu->next = baru;
    }
    cout << "Data masuk\n";
}

void insertBelakang2(int databaru)
{
    TNode *baru;
    baru = new TNode;
    baru->data = databaru;
    baru->next = NULL;
    if (head2 == NULL)
    {
        head2 = baru;
    }
    else
    {
        TNode *bantu;
        bantu = head2;
        while (bantu->next != NULL)
        {
            bantu = bantu->next;
        }
        bantu->next = baru;
    }
    cout << "Data masuk\n";
}


void insertBefore(int databaru, int dataBefore)
{
    TNode *baru, *bantu, *bantu2;
    baru = new TNode;
    baru->data = databaru;
    baru->next = NULL;
    if (isEmpty() == 1)
    {
        head = baru;
    }
    else
    {
        bantu = head;
        bantu2 = head;

        while (bantu->data != dataBefore)
        {
            bantu2 = bantu;
            bantu = bantu->next;
            if (bantu == NULL)
            {
                cout << "Data Before Tidak Ditemukan " << endl;
                return;
            }
        }
        if (bantu == head)
        {
            baru->next = head;
            head = baru;
        }
        else
        {
            baru->next = bantu;
            bantu2->next = baru;
        }
    }

    cout << "Data Masuk " << endl;
}

int nbEl()
{
    TNode *bantu;
    bantu = head;
    int nb = 0;
    if (isEmpty() == 0)
    {
        do
        {
            bantu = bantu->next;
            nb++;
        } while (bantu != NULL);
        cout << endl;
    }
    else
        cout << "Masih kosong\n";
    return nb;
}

void tambahPosisi(int databaru, int posisi)
{
    if (posisi == 1)
    { // tambah depan
        insertDepan(databaru);
    }
    else if (posisi == nbEl() + 1)
    { // tambah belakang
        insertBelakang(databaru);
    }
    else if (posisi > 1 && posisi <= nbEl())
    { // tambah tengah
        if (isEmpty() == 0)
        {
            TNode *baru;
            baru = new TNode;
            baru->data = databaru;
            baru->next = NULL;
            int counter = 1;
            TNode *bantu1, *bantu2;
            bantu1 = head;
            while (counter < posisi)
            {
                if (bantu1->next != NULL)
                {
                    bantu2 = bantu1;
                    bantu1 = bantu1->next;
                }
                counter++;
            }
            bantu2->next = baru;
            baru->next = bantu1;
        }
        else
        {
            cout << "list masih kosong\n";
        }
    }
    else
    {
        cout << "diluar index" << endl;
    }
}

void insertDepan2(int databaru)
{
    if (databaru % 2 == 0)
    {
        databaru--;
    }
    TNode *baru;
    baru = new TNode;
    baru->data = databaru;
    baru->next = NULL;
    if (head2 == NULL)
    { // kosong
        head2 = baru;
    }
    else
    { // isi
        baru->next = head2;
        head2 = baru;
    }
    cout << "Data masuk\n";
}

void tampil()
{
    TNode *bantu;
    bantu = head;
    if (isEmpty() == 0)
    {
        while (bantu != NULL)
        {
            cout << bantu->data << " ";
            bantu = bantu->next;
        }
        cout << endl;
    }
    else
        cout << "Masih kosong\n";
}

void tampil2()
{
    TNode *bantu;
    bantu = head2;
    if (head2 != NULL)
    {
        while (bantu != NULL)
        {
            cout << bantu->data << " ";
            bantu = bantu->next;
        }
        cout << endl;
    }
    else
        cout << "Masih kosong\n";
}

void hapusDepan()
{
    if (!isEmpty())
    {
        TNode *bantu;
        bantu = head;
        head = head->next;
        bantu->next = NULL;
        cout << bantu->data << " berhasil dihapus\n";
        delete bantu;
    }
    else
        cout << "Sudah kosong\n";
}

void hapusBelakang()
{
    if (!isEmpty())
    {
        TNode *bantu1, *bantu2;
        bantu1 = head;
        if (bantu1->next == NULL)
        { // sisa1
            head = NULL;
            cout << bantu1->data << " berhasil dihapus\n";
            delete bantu1;
        }
        else
        {
            while (bantu1->next != NULL)
            {
                bantu2 = bantu1;
                bantu1 = bantu1->next;
            }
            bantu2->next = NULL;
            cout << bantu1->data << " berhasil dihapus\n";
            delete bantu1;
        }
    }
    else
        cout << "Sudah kosong\n";
}

void hapusPosisi(int posisi)
{
    if (posisi == 1)
    { // hapus depan minim ada 1 elemen
        hapusDepan();
    }
    else if (posisi == nbEl())
    { // hapus belakang minim ada 1 elemen
        hapusBelakang();
    }
    else if (posisi > 1 && posisi < nbEl())
    { // posisi tengah, minim ada 3 elemen
        TNode *bt1, *bt2, *del;
        bt2 = head;
        del = bt2->next;
        bt1 = del->next;
        int c = 2;
        while (c < posisi)
        {
            bt1 = bt1->next;
            del = del->next;
            bt2 = bt2->next;
            c++;
        }
        bt2->next = bt1;
        cout << del->data << " berhasil dihapus\n";
        delete (del);
    }
    else
    {
        cout << "posisi tidak valid, tidak ada yang dihapus\n";
    }
}

void hapusAll()
{
    while (isEmpty() == 0)
    { // selama tidak kosong
        hapusDepan();
    }
}



int main()
{
    int databaru, posisi;
    /*cout<<"Masukan Data Depan= ";cin>>databaru;
    insertDepan(databaru);
    cout<<"Masukan Data Depan= ";cin>>databaru;
    insertDepan(databaru);
    cout<<"Masukan Data Depan= ";cin>>databaru;
    insertDepan(databaru);*/


    cout << "Masukan Data Belakang = ";
    cin >> databaru;
    insertBelakang(databaru);
    cout << "Masukan Data Belakang = ";
    cin >> databaru;
    insertBelakang(databaru);
    cout << "Masukan Data Belakang = ";
    cin >> databaru;
    insertBelakang(databaru);

    cout << "Masukkan Data Before = ";
    cin >> databaru;
    cout << "Masukkan Posisi = ";
    cin >> posisi;
    insertBefore(databaru, posisi);
    tampil();
    // cout << "Masukan Data tengah = ";
    // cin >> databaru;
    // cout << "Posisi/index Data tengah = ";
    // cin >> posisi;
    // tambahPosisi(databaru, posisi);
    // tampil();
    /*cout<<"Masukan Data tengah = ";cin>>databaru;
    cout<<"Posisi/index Data tengah = ";cin>>posisi;
    tambahPosisi(databaru,posisi);
    tampil();*/
    // cout << "Masukan Data tengah = ";
    // cin >> databaru;
    // cout << "Posisi/index Data tengah = ";
    // cin >> posisi;
    // tambahPosisi(databaru, posisi);
    // tampil();
    // cout << nbEl() << endl;
    // hapusAll();
    /*cout<<"Hapus posisi = ";cin>>posisi;
    hapusPosisi(posisi);
    tampil();
    cout << nbEl()<<endl;
    cout<<"Hapus posisi = ";cin>>posisi;
    hapusPosisi(posisi);
    tampil();
    cout << nbEl()<<endl;
    cout<<"Hapus posisi = ";cin>>posisi;
    hapusPosisi(posisi);*/
    // tampil();
    // cout << nbEl() << endl;
    /*hapusDepan();
    tampil();
    hapusDepan();
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    hapusBelakang();
    tampil();
    hapusBelakang();
    tampil();
    hapusBelakang();
    hapusDepan();*/
}

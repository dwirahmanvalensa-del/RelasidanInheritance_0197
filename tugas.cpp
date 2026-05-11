#include <iostream>
#include <string>

using namespace std;

class User {
public:
    static int globalId; 
    int id;             
    string nama;        
    string email;      

    int generateId() {
        return ++globalId;
    }

    User(string pNama, string pEmail) : nama(pNama), email(pEmail) {
        id = generateId();
        cout << "User \"" << nama << "\" telah dibuat ke dalam sistem.\n";
    }

    virtual ~User() {
        cout << "User \"" << nama << "\" telah dihapus dari sistem.\n";
    }
};

int User::globalId = 0;

class Member : public User { 
public:
    bool status; 

    Member(string pEmail, string pNama) : User(pNama, pEmail) {
        status = true; 
        cout << "Role: Member aktif.\n";
    }

    void showProfile() {
        cout << "\n===== DETAIL MEMBER =====" << endl;
        cout << "ID     : " << id << endl;
        cout << "Nama   : " << nama << endl;
        cout << "Email  : " << email << endl;
        cout << "Status : " << (status ? "Aktif" : "Non-Aktif") << endl;
        cout << "=========================" << endl;
    }
};

class Admin : public User { 
public:
    Admin(string pNama, string pEmail) : User(pNama, pEmail) {
        cout << "Role: Admin aktif.\n";
    }

    void showAllMember(Member* m1, Member* m2) {
        m1->showProfile();
        m2->showProfile();
    }

    void toggleStatusActiovation(Member* m) {
        m->status = !m->status; 
        cout << "System: Status " << m->nama << " berhasil diubah oleh Admin.\n";
    }
};

int main() {

    Admin* adminUtama = new Admin("Dwi Rahman", "admin@mail.com");

    Member* Caca = new Member("caca@mail.com", "Caca");
    Member* cacaValensa = new Member("cacaValensa@mail.com", "Caca Valensa");

    cout << "\n[Laporan Awal]" << endl;
    adminUtama->showAllMember(Caca, cacaValensa);

    adminUtama->toggleStatusActiovation(Caca);

    cout << "\n[Laporan Setelah Update]" << endl;
    adminUtama->showAllMember(Caca, cacaValensa);

    cout << endl;

    delete adminUtama;
    delete Caca;

    return 0;
}
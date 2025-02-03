#include <stdio.h>   // di include untuk mengakses fungsi standar input dan output
#include <string.h>  // di include untuk mengakses fungsi standar pemrosesan string
#include <stdlib.h>  // di include untuk mengakses fungsi standar alokasi memori
#define MAX_CHAR 128 // Mendefinisikan ukuran maksimum character yang dapat disimpan

/* =================================START====================================== */

// Deklarasi struktur TrieNode untuk menyimpan data dalam Trie
struct TrieNode
{
    // Mendifinisikan char character dalam node Trie
    char character;

    // Mendifinisikan array of char description dalam node Trie
    char description[MAX_CHAR];

    // Mendifinisikan array pointer yang menunjuk ke child node
    struct TrieNode *child[MAX_CHAR];

    // Mendifinisikan flag yang menandakan apakah node adalah akhir dari kata
    int isWord;
};

/*  ================
    struct TrieNode
    ================
    Mendefinisikan Struct TrieNode untuk merepresentasikan sebuah node dalam
    struktur data Trie. Terdiri dari beberapa variable seperti character yang
    digunakan untuk menampung data char, description yang digunakan untuk menampung
    string sebanyak MAX_CHAR, array child yang digunakan untuk menampung pointer
    ke struct TrieNode. Setiap elemen dalam array ini menunjuk ke child node Trie,
    dan isWord digunakan untuk menandai apakah node merupakan akhir dari sebuah
    kata atau bukan.
*/

/* ==================================END======================================= */


/* =================================START====================================== */

TrieNode *createNode(char chara)
{
    // Mengalokasikan memori untuk node baru
    TrieNode *node = (TrieNode *)malloc(sizeof(TrieNode));

    node->character = chara; // Menginisialisasi char node
    node->isWord = 0; // Menginisialisasi status isWord

    // Mengosongkan array pointer ke child node
    memset(node->child, 0, sizeof(node->child));
    return node; // Mengembalikan pointer ke node yang dibuat
}

/*  =================================
    TrieNode *createNode(char chara)
    =================================
    Function ini bertujuan untuk menginisialisasi dan membuat sebuah node Trie baru.
    Function ini mepunyai parameter chara yang merupakan character yang
    akan disimpan dalam node. Pertama, function ini mengalokasikan memori untuk node
    baru menggunakan malloc. Kemudian, character chara disimpan dalam node tersebut,
    lalu flag isWord diinisialisasi sebagai 0 untuk menandai bahwa node tersebut
    belum mencapai akhir sebuah kata. Selanjutnya, semua child node diatur menjadi
    NULL menggunakan memset. Dan terakhir, function ini mengembalikan node yang baru
    saja dibuat.
*/

/* ==================================END======================================= */


/* =================================START====================================== */

void insertWord(TrieNode **root, char word[], char desc[])
{
    // Jika Trie kosong, buat node baru sebagai root
    if (*root == NULL)
    {
        *root = createNode('*');
    }

    // Inisialisai pointer untuk menelusuri Trie
    TrieNode *current = *root;
    while (*word) // Iterasi melalui setiap karakter dalam word
    {
        if (current->child[*word] == NULL)
        {
            // Jika child node belum ada, buat node baru
            current->child[*word] = createNode(*word);
        }
        // Pindah ke child node
        current = current->child[*word];
        word++; // Lanjutkan ke karakter berikutnya dalam kata
    }
    current->isWord = 1;                // Tandai node terakhir sebagai akhir kata
    strcpy(current->description, desc); // Salin deskripsi ke node terakhir
}

/*  ===========================================================
    void insertWord(TrieNode **root, char word[], char desc[])
    ===========================================================
    Function ini digunakan untuk memasukkan sebuah kata slang baru beserta
    deskripsinya ke dalam Trie. Function ini mepunyai parameter seperti root yang
    merupakan pointer ke root Trie, word yang merupakan array of character untuk
    menampung kata slang, dan desc yang merupakan array of character yang menampung
    deskripsi dari kata slang tersebut. Pertama, function memeriksa apakah Trie
    sudah ada atau belum. Jika belum, maka akan dibuat node root baru. Selanjutnya,
    menginisialisasi sebuah pointer current yang menunjuk ke root Trie. lalu,
    melakukan loop sepanjang character didalam word. Untuk setiap character, function
    membuat node baru jika node tersebut belum ada, lalu menggeser pointer current
    ke child node yang sesuai. Setelah loop selesai, node terakhir ditandai sebagai
    akhir kata dengan mengatur isWord menjadi 1 dan menyimpan deskripsi kata slang
    ke dalam node tersebut.
*/

/* ==================================END======================================= */


/* =================================START====================================== */

int cekExisting(TrieNode *root, char word[])
{
    // Inisialisasi Pointer untuk menelusuri Trie.
    TrieNode *current = root;
    while (*word) // Iterasi melalui setiap karakter dalam word
    {
        // Jika node atau child node tidak ada, kata tidak ditemukan
        if (current == NULL || current->child[*word] == NULL)
            return 0; // Mengembalikan 0 jika tidak ditemukan

        // Pindah ke child node
        current = current->child[*word];
        word++; // Lanjutkan ke karakter berikutnya dalam kata
    }
    return current != NULL && current->isWord;
}

/*  =============================================
    int cekExisting(TrieNode *root, char word[])
    =============================================
    Function ini berfungsi untuk memeriksa apakah kata slang sudah ada di dalam Trie.
    Function ini mepunyai parameter seperti root yang merupakan pointer ke root
    Trie dan word yang merupakan array of character yang berisi kata slang yang akan
    dicek keberadaannya. Pertama, function menginisialisasi pointer current yang
    menunjuk ke root Trie. lalu, melakukan loop sepanjang character dalam word. Pada
    setiap perulangan, dilakukan pemeriksaan apakah pointer current tidak NULL dan
    apakah node child yang sesuai sudah ada. Jika tidak, function akan mengembalikan
    0 untuk menandakan bahwa kata slang belum ada di dalam Trie. Jika loop selesai tanpa
    menemukan masalah, function akan mengembalikan nilai isWord dari node terakhir yang
    ditemukan.
*/

/* ==================================END======================================= */


/* =================================START====================================== */

void printContent(TrieNode *node, char *buffer, int depth, int *counter)
{
    // Jika node kosong, return.
    if (node == NULL)
        return;

    // Menambahkan karakter node ke buffer
    buffer[depth] = node->character;

    // Jika node merupakan akhir kata, cetak kata
    if (node->isWord)
    {
        buffer[depth + 1] = '\0';
        printf("%d. %s\n", ++(*counter), buffer);
    }

    // Iterasi melalui setiap child node
    for (int i = 0; i < MAX_CHAR; i++)
    {
        // Jika ada child node, jalankan rekursif untuk child node tersebut
        if (node->child[i] != NULL)
        {
            printContent(node->child[i], buffer, depth + 1, counter);
        }
    }
}

/*  =========================================================================
    void printContent(TrieNode *node, char *buffer, int depth, int *counter)
    =========================================================================
    Function ini digunakan untuk mencetak semua kata slang yang tersimpan di 
    dalam Trie secara rekursif. Function ini mempunyai parameter node yang 
    merupakan pointer ke node Trie yang sedang diproses, buffer yang merupakan 
    array of character untuk menampung kata yang telah diproses, depth yang 
    merupakan kedalaman saat ini dalam Trie, dan counter yang merupakan pointer 
    ke variabel untuk menghitung jumlah kata yang sudah dicetak. Pertama, 
    function memeriksa apakah node tidak NULL. Jika tidak, maka akan memasukan 
    character dari node ke dalam buffer pada indeks depth. Jika node merupakan 
    akhir kata, maka kata tersebut dicetak beserta nomor urutnya menggunakan 
    printf. Selanjutnya, dilakukan loop untuk setiap child node. Untuk setiap 
    child, function memanggil dirinya sendiri secara rekursif dengan child node 
    tersebut, menambahkan 1 pada depth, dan memperbarui nilai counter.
*/

/* ==================================END======================================= */


/* =================================START====================================== */

void searchPref(TrieNode *root, char prefix[])
{
    // Jika Trie kosong, cetak tidak ada kata yang bisa ditemukan
    if (root == NULL)
    {
        printf("\nThere is no prefix \"%s\" in the dictionary.\n", prefix);
        return;
    }

    // Inisialisasi pointer untuk menelusuri Trie
    TrieNode *current = root;

    // Deklarasi buffer untuk menyimpan kata yang ditemukan
    char buffer[MAX_CHAR];

    // Inisialisasi kedalaman dalam Trie
    int depth = 0;

    // Inisialisasi nomor urut kata
    int counter = 0;

    // Inisiliasi tempC untuk menyalin prefix
    const char *tempC = prefix;

    while (*prefix) // Iterasi melalui setiap karakter dalam prefix
    {
        // Jika child node tidak ada, cetak prefix tidak ditemukan
        if (current->child[*prefix] == NULL)
        {
            printf("\nThere is no prefix \"%s\" in the dictionary.\n", tempC);
            return;
        }
        buffer[depth++] = *prefix; // Tambahkan karakter prefix ke buffer
        current = current->child[*prefix++]; // Pindah ke child node
    }

    printf("\nWords starting with \"%s\":\n", tempC);

    // Cetak semua kata yang dimulai dengan prefix
    printContent(current, buffer, depth - 1, &counter);
    puts(" "); // Cetak baris kosong
}

/*  ===============================================
    void searchPref(TrieNode *root, char prefix[])
    ===============================================
    Function ini bertujuan untuk mencari semua kata slang yang dimulai dengan
    prefix tertentu yang tersimpan di dalam Trie. Function ini mepunyai parameter
    root yang merupakan pointer ke root Trie dan prefix yang merupakan array of
    character yang berisi awalan kata yang akan dicari. Pertama, function memeriksa
    apakah Trie sudah ada atau belum. Jika belum, function akan langsung mencetak
    pesan bahwa tidak ada kata yang berawalan "prefix" yang ditemukan. Jika Trie sudah
    ada, function menginisialisasi pointer current yang menunjuk ke root Trie dan array
    buffer untuk menampung kata-kata yang ditemukan. Selanjutnya,function melakukan
    loop sepanjang character dalam prefix. Pada setiap perulangan, function memeriksa
    apakah child node yang sesuai sudah ada. Jika tidak, function mencetak pesan
    bahwa tidak ada kata yang berawalan "prefix" yang ditemukan. Jika loop selesai
    tanpa masalah, function mencetak semua kata yang ditemukan menggunakan function
    printContent.
*/

/* ==================================END======================================= */


/* =================================START====================================== */

void printAll(TrieNode *root)
{
    // Jika Trie kosong, cetak belum ada kata yang tersimpan
    if (root == NULL)
    {
        printf("\nThere is no slang word yet in the dictionary.\n");
        return;
    }

    // Deklarasi buffer untuk menyimpan kata yang ditemukan
    char buffer[MAX_CHAR];

    // Inisialisasi nomor urut kata
    int counter = 0;

    printf("\nList of all slang words in the dictionary:\n");

    // Panggil fungsi rekursif untuk mencetak semua kata
    printContent(root, buffer + 1, -1, &counter);
    puts(" "); // Cetak baris kosong
}

/*  ==============================
    void printAll(TrieNode *root)
    ==============================
    Function ini digunakan untuk mencetak semua kata slang yang tersimpan di 
    dalam Trie. Function ini mempunyai parameter root yang merupakan pointer 
    ke root Trie. Pertama, function memeriksa apakah Trie sudah ada atau belum. 
    Jika belum, function mencetak pesan bahwa belum ada kata slang yang tersimpan 
    di dalam trie. Jika Trie sudah ada, function menginisialisasi array buffer 
    untuk menampung kata-kata yang ditemukan. Selanjutnya, function akan mencetak 
    semua kata yang ditemukan menggunakan function printContent.
*/

/* ==================================END======================================= */


/* =================================START====================================== */

void searchSlang(TrieNode *root, char word[])
{
    // Jika Trie kosong, cetak belum ada kata yang tersimpan
    if (root == NULL)
    {
        printf("\nThere is no word \"%s\" in the dictionary.\n", word);
        return;
    }

    // Inisialisasi pointer untuk menelusuri Trie
    TrieNode *current = root;

    // Inisialisasi buffer untuk menyimpan kata yang ditemukan
    char buffer[MAX_CHAR] = "";

    // Inisiliasi tempC untuk menyalin word
    const char *tempC = word;

    while (*word) // Iterasi melalui setiap karakter dalam kata
    {
        // Jika node atau child tidak ada, ceetak kata tidak ditemukan
        if (current == NULL || current->child[*word] == NULL)
        {
            printf("\nThere is no word \"%s\" in the dictionary.\n", tempC);
            return;
        }
        // Pindah ke node anak
        current = current->child[*word];

        // Tambahkan karakter ke buffer
        buffer[strlen(buffer)] = *word;
        word++; // Lanjutkan ke karakter berikutnya dalam kata
    }

    // Jika node terakhir merupakan akhir kata, cetak kata dan deskripsi
    if (current != NULL && current->isWord)
    {
        printf("\nSlang word  : %s\n", buffer);
        printf("Description : %s\n\n", current->description);
    }
    else
    {
        printf("\nThere is no word \"%s\" in the dictionary.\n", tempC);
        return;
    }
}

/*  ==============================================
    void searchSlang(TrieNode *root, char word[])
    ==============================================
    Function ini bertujuan untuk mencari kata slang yang tersimpan di dalam 
    Trie. Function ini mempunyai parameter root yang merupakan pointer ke root 
    Trie dan word yang merupakan array of character yang berisi kata slang yang 
    akan dicari. Pertama, function memeriksa apakah Trie sudah ada atau belum. 
    Jika belum, function mencetak pesan bahwa tidak ada kata slang yang ditemukan 
    berdasarkan parameter word. lalu, function menginisialisasi pointer current 
    yang menunjuk ke root Trie dan array buffer untuk menampung kata yang ditemukan. 
    Selanjutnya, function melakukan perulangan sepanjang karakter dalam word. Pada
    setiap langkah, function memeriksa apakah child node yang sesuai sudah ada. 
    Jika tidak, function mencetak pesan bahwa tidak ada kata slang yang ditemukan 
    berdasarkan parameter word. Jika perulangan selesai tanpa masalah, function 
    mencetak kata slang dan deskripsi dari kata yang ditemukan.
*/

/* ==================================END======================================= */


/* =================================START====================================== */

void clear_screen()
{
    for (int i = 0; i < 100; i++)
        printf("\n");
}

/*  ====================
    void clear_screen()
    ====================
    Function ini digunakan untuk membersihkan layar konsol dengan
    mencetak 100 karakter newline.
*/

/* ==================================END======================================= */


/* =================================START====================================== */

void enter_line()
{
    printf("Press enter to continue...");
    getchar();      // Menunggu user menekan tombol enter
    clear_screen(); // Membersihkan layar konsol
}

/*  ==================
    void enter_line()
    ==================
    Function ini digunakan untuk menunggu user menekan tombol enter sebelum melanjutkan
    eksekusi program. Menampilkan pesan "Press enter to continue..." , lalu menunggu
    input dengan menggunakan getchar dan membersihkan layar konsol
*/

/* ==================================END======================================= */


/* =================================START====================================== */

void printMenu()
{
    clear_screen(); // Membersihkan layar konsol
    printf("Boogle\n");
    printf("1. Release a new slang word\n");
    printf("2. Search a slang word\n");
    printf("3. View all slang words starting with a certain prefix word\n");
    printf("4. View all slang words\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

/*  =================
    void printMenu()
    =================
    Function ini bertujuan untuk mencetak menu pilihan untuk user.
    Sebelum mencetak menu, function ini menjalankan clear_screen untuk membersihkan
    layar konsol. lalu setiap baris printf mencetak satu opsi pilihan menu yang
    tersedia, diikuti dengan nomor opsi dan deskripsi pilihan tersebut. Setelah itu,
    program mencetak pesan "Enter your choice: " untuk meminta user memasukkan
    pilihan menu.
*/

/* ==================================END======================================= */


/* =================================START====================================== */

void caseOne(TrieNode **root)
{
    char word[MAX_CHAR]; // Deklarasi word untuk menampung slang
    char description[MAX_CHAR]; // Deklarasi desc untuk menampung deskripsi

    do
    {
        printf("Input a new slang word [Must be more than 1 characters and contains no space]: ");
        scanf(" %[^\n]", word); // Menerima input user
        getchar();
    } while (strlen(word) <= 1 || strchr(word, ' ') != NULL); // Validasi Input

    do
    {
        printf("Input a new slang word description [Must be more than 2 words]: ");
        scanf(" %[^\n]", description); // Menerima input user
        getchar();
    } while (strlen(description) <= 1 || strchr(description, ' ') == NULL); // Validasi

    // Memeriksa keberadaan kata slang
    int isExist = cekExisting(*root, word);

    // Menyimpan kata slang dan description ke dalam Trie
    insertWord(root, word, description);

    if (isExist)
    {
        // Mencetak pesan jika kata slang sudah ada
        printf("\nSuccessfully updated a slang word.\n");
    }
    else
    {
        // Mencetak pesan jika kata slang belum ada
        printf("\nSuccessfully released new slang word.\n");
    }
    
    // Menunggu user menekan enter
    enter_line();
}

/*  ==============================
    void caseOne(TrieNode **root)
    ==============================
    Function ini merupakan pemisahan kode untuk case pertama yaitu untuk 
    menambahkan kata slang baru beserta deskripsinya ke dalam Trie. Function 
    ini mempunyai parameter root yang merupakan pointer ke root Trie. Pertama, 
    function ini mendeklarasi array of char word dan description untuk menampung 
    input dari user. Selanjutnya, Function  melakukan dua loop yang meminta user 
    untuk memasukkan kata slang baru dan deskripsinya. di loop pertama, function 
    mencetak pesan dan menggunakan scanf untuk membaca input user ke dalam variabel 
    word. Loop akan terus berlanjut jika panjang kata kurang dari atau sama dengan 
    1 karakter, atau jika kata mengandung spasi. dan di loop kedua function akan 
    mencetak pesan dan menggunakan scanf untuk membaca input user ke dalam variabel 
    description. Loop akan terus berlanjut jika panjang deskripsi kurang dari atau 
    sama dengan 1 karakter, atau jika deskripsi tidak mengandung spasi. Dengan 
    demikian, function memastikan bahwa kata slang  dan deskripsi yang dimasukkan 
    oleh user sesuai dengan kriteria yang ditetapkan. Selanjutnya, function memeriksa 
    apakah kata tersebut sudah ada dalam Trie menggunakan function cekExisting(). 
    Jika kata tersebut sudah ada, maka deskripsinya saja yang akan diperbarui 
    dan jika tidak, kata slang baru dan deskripsinya dimasukkan ke dalam Trie 
    menggunakan function insertWord(). Terakhir, function mencetak pesan, 
    yang berisi apakah kata tersebut berhasil diperbarui atau ditambahkan, 
    dan menunggu user menekan enter sebelum melanjutkan menggunakan 
    function enter_line().
*/

/* ==================================END======================================= */


/* =================================START====================================== */

void caseTwo(TrieNode *root)
{
    char word[MAX_CHAR]; // Deklarasi variabel untuk menampung kata slang

    do
    {
        printf("Input a slang word to be searched [Must be more than 1 characters and contains no space]: ");
        scanf(" %[^\n]", word); // Menerima input user
        getchar();
    } while (strlen(word) <= 1 || strchr(word, ' ') != NULL); // Validasi Input

    // Mencari kata slang dalam Trie
    searchSlang(root, word);

    // Menunggu user menekan enter
    enter_line();
}
/*  =============================
    void caseTwo(TrieNode *root)
    =============================
    Function ini merupakan pemisahan kode untuk case kedua yaitu untuk mencari 
    kata slang yang berada di dalam Trie. Function ini mempunyai parameter root 
    yang merupakan pointer ke root Trie. Pertama, function ini menginisialisasi 
    array of char word untuk menampung input dari user. Selanjutnya, Function 
    melakukan loop yang meminta user memasukkan kata slang yang ingin dicari.
    Program mencetak pesan untuk meminta user memasukkan kata slang yang akan 
    dicari. di loop ini, function mencetak pesan dan menggunakan scanf untuk 
    membaca input user ke dalam variabel word. Loop akan terus berlanjut jika 
    panjang kata kurang dari atau sama dengan 1 karakter, atau jika kata mengandung 
    spasi. Lalu, function ini akan  memanggil function searchSlang() dengan argumen 
    root yang merupakan pointer ke root Trie dan word yang merupakan kata slang 
    yang akan dicari. Terakhir, function menanggil function enter_line() untuk 
    menunggu user menekan enter sebelum melanjutkan.
*/

/* ==================================END======================================= */


/* =================================START====================================== */

void caseThree(TrieNode *root)
{
    char word[MAX_CHAR]; // Deklarasi variabel untuk menampung kata slang.

    do
    {
        printf("Input a prefix to be searched: ");
        scanf(" %[^\n]", word); // Menerima input user
        getchar();
    } while (strlen(word) < 1 || strchr(word, ' ') != NULL); // Validasi Input

    // Mencari kata slang dengan prefix tertentu dalam Trie
    searchPref(root, word);

    // Menunggu user menekan enter
    enter_line();
}
/*  ===============================
    void caseThree(TrieNode *root)
    ===============================
    Function ini merupakan pemisahan kode untuk case ketiga yaitu untuk mencari 
    kata slang dengan prefix yang diinginkan. Function ini mempunyai parameter 
    root yang merupakan pointer ke root Trie. Pertama, function ini menginisialisasi 
    array of char word untuk menampung input dari user.Selanjutnya, Function 
    melakukan loop yang meminta user memasukkan kata slang yang ingin dicari.
    Program mencetak pesan untuk meminta user memasukkan prefix yang akan dicari.
    di loop ini, function mencetak pesan dan menggunakan scanf untuk membaca 
    input user ke dalam variabel word. Loop akan terus berlanjut jika panjang 
    kata kurang dari 1 karakter, atau jika kata mengandung spasi. Lalu, function 
    ini akan  memanggil function searchPref() dengan argumen root yang merupakan 
    pointer ke root Trie dan word yang merupakan prefix yang akan dicari. Terakhir, 
    function menanggil function enter_line() untuk menunggu user menekan enter sebelum 
    melanjutkan.
*/

/* ==================================END======================================= */


/* =================================START====================================== */

void caseFour(TrieNode *root)
{   
    // Mencetak mencetak semua kata slang yang tersimpan di dalam Trie
    printAll(root); 

    getchar();

    // Menunggu user menekan enter
    enter_line();
}
/*  void caseFour(TrieNode *root)
    ===============================
    Function ini merupakan pemisahan kode untuk case keempat yaitu untuk menampilkan 
    semua kata slang yang tersimpan di Trie. Function ini mempunyai parameter root 
    yang merupakan pointer ke root Trie. Pertama, function akan memanggil printAll() 
    dengan dengan argumen root yang merupakan pointer ke root Trie.
    Terakhir, function menanggil enter_line() untuk menunggu user menekan enter 
    sebelum melanjutkan.
*/

/* ==================================END======================================= */

int main()
{
    TrieNode *root = NULL; // Deklarasi root Trie.
    int choice; // Deklarasi variabel untuk menampung pilihan user.

    do
    {
        printMenu(); // menampilkan Menu Pilihan

        if (scanf("%d", &choice) != 1 || choice > 5)
        {
            clear_screen();
            printf("\nInvalid input. Please enter a valid number.\n\n");
            while (getchar() != '\n');
            continue;
        }
        /*
            Kode diatas berfungsi untuk memeriksa apakah input dari user valid 
            dalam hal nomor menu. Jika input tidak valid (tidak berupa angka 
            atau melebihi batas menu yang tersedia), maka program akan 
            membersihkan layar, lalu menampilkan pesan kesalahan, dan kemudian kembali
            meminta input sampai input dari user valid.
        */

        switch (choice) // Memproses Pilihan User
        {
        case 1:
        {
            // Memanggil Function untuk Menambahkan Kata Slang Baru
            caseOne(&root); 
        }
        break;
        case 2:
        {
            // Memanggil Function Untuk Mencari Kata Slang
            caseTwo(root); 
        }
        break;
        case 3:
        {
            // Memanggil Function Untuk Mencari Kata Slang Berdasarkan Prefix
            caseThree(root); 
        }
        break;

        case 4:
        {
            // Memanggil Function Untuk Menampilkan Semua Kata Slang Yang Tersimpan
            caseFour(root); 
        }
        break;
        case 5:
        {
            // Mencetak Pesan Selamat Tinggal
            printf("Thank you... Have a nice day :)\n"); 
        }
        break;
        }
    } while (choice != 5); // Loop Berakhir Jika User Menginput "5"

    return 0;
}
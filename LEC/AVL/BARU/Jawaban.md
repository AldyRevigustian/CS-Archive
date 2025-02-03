  1. Disjoint set:
      - pengertian
        Disjoint set adalah struktur data yang mengelompokkan elemen ke dalam himpunan terpisah (disjoint). Setiap elemen hanya berada di satu himpunan
      
      - function yg ada dan penjelasan (makeSet, findSet, union)
        - makeSet(x): Membuat himpunan baru yang hanya berisi elemen x.
        - findSet(x): Menemukan perwakilan (representatif) dari himpunan yang berisi x.
        - union(x, y): Menggabungkan dua himpunan yang masing-masing berisi x dan y.
      
      - Real world example
        - Network Connectivity: Digunakan untuk memantau hubungan atau koneksi dalam jaringan, misalnya dalam jaringan komputer atau sosial.
        - Connected Components in Graphs: Digunakan untuk menemukan komponen-komponen yang saling terhubung dalam sebuah graf.

      - Union by Rank & Path Compression
        - Union by Rank: Menggabungkan dua himpunan berdasarkan tinggi pohon mereka untuk menjaga pohon tetap seimbang. (dilakukan saat union ngebandingin x sama y kalo y rank nya lebih gede maka swap dengan x, nanti gabungin ke x)
        - Path Compression: Mengoptimalkan operasi findSet dengan memperpendek jalur dari elemen ke akar selama pencarian. (dilakukan saat finde set, merubah parent langsung ke representatif)

  2. B-Tree Deletion
    
  3. Dikasih angka trus disuruh insert & gambar secara step by step ke:
      (a) AVL Tree
      (b) Red Black Tree
      (c) disuruh tulis path/step buat nyari satu data & disuruh pilih antara AVL sama RBT yg mana yg lebih bagus untuk cari data banyak + alasan
      avl lebih cepat saat searching akan tetapi lambat saat insert karena memakan waktu saat proses balancing

  4. heap:
      - penjelasan
        Heap adalah struktur data yang berbentuk pohon biner dan digunakan untuk mengatur data secara efisien. Heap sangat berguna buat nyari elemen terbesar atau terkecil dengan cepat. Ada dua jenis heap utama, yaitu max-heap dan min-heap.

      - Bandingkan struktur & fungsionalitas dibanding BST
        Heap adalah jenis binary tree yang mengikuti sifat heap (max-heap atau min-heap) di mana setiap parent node lebih besar atau lebih kecil dari anak-anaknya, tetapi tidak mengikuti aturan urutan seperti binary search tree (BST). BST adalah binary tree di mana setiap node di subtree kiri memiliki nilai lebih kecil dan di subtree kanan memiliki nilai lebih besar dari node itu sendiri. Dengan demikian, heap tidak termasuk binary search tree karena tidak menjaga urutan elemen seperti yang dilakukan BST.

        heap : Priority Queue
        bst : Autocomplete Features

  Coding:
  1. AVL yg bisa insert + delete. untuk printnya dia minta angka ke-x paling kecil.

  - misal datanya 10, 20, 30, 40, 50
  - x = 3
  - delete 20 trus print angka ke-x (disini jadi 40)
  - delete 40 trus print angka ke-x (disini jadi 50)

  void inOrder(Node* root, int* arr, int* index) {
      if (root != NULL) {
          inOrder(root->left, arr, index);
          arr[(*index)++] = root->key;
          inOrder(root->right, arr, index);
      }
  }

  int findKthSmallest(Node* root, int k) {
      int arr[100];
      int index = 0;
      inOrder(root, arr, &index);
      return arr[k - 1];
  }

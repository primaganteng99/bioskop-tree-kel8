# Program Manajemen Bioskop

# Pembuat
1. Ihsan Ertansa Azhar
2. Prima Aji Akbar
3. Timothy El Roy

## Deskripsi

Program Manajemen Bioskop adalah aplikasi berbasis konsol yang memungkinkan admin bioskop untuk mengelola data bioskop, termasuk menambah studio, film, jadwal tayang, dan kursi. Pengguna juga dapat melakukan pemesanan tiket melalui menu yang disediakan.

## Fitur Utama

1. **Login Admin**
   - Admin dapat login menggunakan username dan password yang terdaftar.
   
2. **Registrasi Admin**
   - Admin baru dapat mendaftarkan diri dengan username dan password baru.

3. **Manajemen Bioskop**
   - Admin dapat memuat data bioskop dari file.
   - Admin dapat memasukkan data bioskop baru jika belum ada data yang dimuat.
   - Admin dapat menambah studio, film, jadwal tayang, dan kursi untuk bioskop.
   - Admin dapat melihat struktur data bioskop dalam bentuk tree.
   - Admin dapat mencari dan menampilkan informasi node tertentu dalam tree.
   - Admin dapat menghapus node tertentu dari tree.

4. **Pemesanan Tiket**
   - Pengguna dapat memesan tiket bioskop melalui menu yang disediakan.

## Struktur Program

- **main()**
  - Fungsi utama yang mengatur alur program.
  - Menampilkan menu utama dan menangani input dari pengguna.
  - Mengelola login admin dan registrasi admin.
  - Memanggil fungsi-fungsi untuk manajemen bioskop dan pemesanan tiket.

- **loginAdmin()**
  - Fungsi untuk menangani proses login admin.

- **registerAdmin()**
  - Fungsi untuk menangani registrasi admin baru.

- **menuMasuk()**
  - Menampilkan menu setelah admin berhasil login.

- **menuBioskop()**
  - Menampilkan menu untuk manajemen bioskop.

- **menuPesan()**
  - Menampilkan menu untuk pemesanan tiket.

- **tampilkanTree()**
  - Menampilkan struktur tree dari data bioskop.

- **tambahStudio(), tambahFilm(), tambahJamTayang(), tambahKursi()**
  - Fungsi-fungsi untuk menambah data studio, film, jadwal tayang, dan kursi ke dalam tree bioskop.

- **cariNodeDanTampilkanHasil()**
  - Mencari dan menampilkan informasi node tertentu dalam tree bioskop.

- **hapusNodeEx()**
  - Menghapus node tertentu dari tree bioskop.

- **muatTreeDariFile()**
  - Memuat data bioskop dari file.

- **masukkanNamaBioskop()**
  - Memasukkan nama bioskop baru jika belum ada data yang dimuat.

## Cara Menggunakan

1. **Kompilasi Program**
   - Pastikan semua file header dan source code berada dalam satu direktori.
   - Kompilasi program menggunakan compiler C, misalnya `gcc`.
   - Contoh: `gcc main.c -o bioskop -l<library_name>`

2. **Menjalankan Program**
   - Jalankan executable yang telah dikompilasi.
   - Contoh: `./bioskop`

3. **Login atau Registrasi**
   - Pada menu utama, pilih opsi untuk login atau registrasi admin.

4. **Manajemen Bioskop**
   - Setelah berhasil login, pilih opsi untuk mengelola bioskop.
   - Tambah studio, film, jadwal tayang, atau kursi sesuai kebutuhan.
   - Lihat struktur data bioskop dan cari informasi node tertentu.

5. **Pemesanan Tiket**
   - Pilih opsi untuk memesan tiket dan ikuti instruksi yang diberikan.

## Kebutuhan Sistem

- Sistem operasi yang mendukung eksekusi aplikasi C (misalnya Windows, Linux).
- Compiler C (misalnya GCC).
- Library tambahan yang diperlukan untuk kompilasi (misalnya `windows.h` untuk Windows).

## Catatan

- Pastikan file `adminAccount.txt` dan `treeBioskop.txt` berada di direktori `database` untuk kemudahan akses oleh program.
- Gunakan path yang sesuai jika file berada di lokasi yang berbeda.


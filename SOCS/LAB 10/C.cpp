#include <stdio.h>

struct Keluarga
{
  char namaAyah[31];
  char namaIbu[31];
  int jumlahSaudara;
};

struct Mahasiswa
{
  char kodeMahasiswa[31];
  char namaMahasiswa[31];
  char jenisKelamin[12];
  struct Keluarga detilKeluarga;
};

struct Dosen
{
  char kodeDosen[31];
  char namaDosen[31];
  char jenisKelamin[12];
  int jumlahMahasiswa;
  struct Mahasiswa mahasiswas[100];
};

int main()
{
  int N, K;
  scanf("%d", &N);

  struct Dosen dosen[N];

  for (int i = 0; i < N; i++)
  {
    scanf("%s %s %s %d", dosen[i].kodeDosen, dosen[i].namaDosen, dosen[i].jenisKelamin, &dosen[i].jumlahMahasiswa);

    for (int j = 0; j < dosen[i].jumlahMahasiswa; j++)
    {
      scanf("%s %s %s %s %s %d",
            dosen[i].mahasiswas[j].kodeMahasiswa,
            dosen[i].mahasiswas[j].namaMahasiswa,
            dosen[i].mahasiswas[j].jenisKelamin,
            dosen[i].mahasiswas[j].detilKeluarga.namaAyah,
            dosen[i].mahasiswas[j].detilKeluarga.namaIbu,
            &dosen[i].mahasiswas[j].detilKeluarga.jumlahSaudara);
    }
  }

  scanf("%d", &K);

  printf("Kode Dosen: %s\n", dosen[K - 1].kodeDosen);
  printf("Nama Dosen: %s\n", dosen[K - 1].namaDosen);
  printf("Gender Dosen: %s\n", dosen[K - 1].jenisKelamin);
  printf("Jumlah Mahasiswa: %d\n", dosen[K - 1].jumlahMahasiswa);

  for (int i = 0; i < dosen[K - 1].jumlahMahasiswa; i++)
  {
    printf("Kode Mahasiswa: %s\n", dosen[K - 1].mahasiswas[i].kodeMahasiswa);
    printf("Nama Mahasiswa: %s\n", dosen[K - 1].mahasiswas[i].namaMahasiswa);
    printf("Gender Mahasiswa: %s\n", dosen[K - 1].mahasiswas[i].jenisKelamin);
    printf("Nama Ayah: %s\n", dosen[K - 1].mahasiswas[i].detilKeluarga.namaAyah);
    printf("Nama Ibu: %s\n", dosen[K - 1].mahasiswas[i].detilKeluarga.namaIbu);
    printf("Jumlah Saudara Kandung: %d\n", dosen[K - 1].mahasiswas[i].detilKeluarga.jumlahSaudara);
  }

  return 0;
}

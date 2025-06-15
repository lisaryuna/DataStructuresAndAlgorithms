# 🧠 Trivia: Random Number Generator (RNG) di C++

Ini sebenarnya trivial aja, tapi penting buat kalian yang ingin paham lebih dalam soal _random number_ di C++.

---

## 🎲 Perbandingan `rand()` vs `mt19937_64`

Kalau kalian lihat di lembar soal, contoh random number generator ditulis seperti ini:

```cpp
srand(time(NULL));
int x = rand();
```

Nah, di template program yang kukasih itu pakai yang sedikit lebih modern dan kuat (aku yakin kalian sangat sangat asing dengan ini), yaitu:
```cpp
#include <random>
mt19937_64 rng(random_device{}());
int x = dist(rng); // misal uniform_int_distribution<int> dist(1, 100);
```

## ❓ Kenapa pakai `mt19937_64`?

Karena `rand()` sering menghasilkan angka yang tidak merata distribusinya, terutama kalau program dijalankan berulang kali dalam waktu singkat (ini terjadi pas aku praktikum dulu, jadi rada aneh hasil generate random number nya).

Beberapa alasannya:

- Hasil dari `rand()` bisa sangat timpang (misalnya data terlalu besar-besar atau terlalu kecil).

- `rand()` hanya 15-bit di banyak compiler, jadi rentang acaknya sempit.

- `mt19937_64` punya rentang 64-bit dan periode `2^19937 - 1`, artinya siklus angkanya sangat panjang.

## ⚙️ Cara RNG Bekerja

Yang kita pakai di program ini sebenarnya adalah _pseudo-random_ — bukan benar-benar acak, tapi kelihatan acak.

- Semua PRNG (termasuk `rand()` dan `mt19937`) sebenarnya menghasilkan angka deterministik dari seed.

- Kalau seed-nya sama, hasilnya akan selalu sama.

Kita kasih `random_device{}` sebagai seed supaya dapat nilai awal yang lebih “unik”.

## 🔒 True Randomness vs Pseudo-Randomness

True Random itu datang dari sumber fisik yang tidak bisa diprediksi, misalnya:

- noise listrik,

- gerakan mouse,

- bahkan radiasi partikel kuantum 

Komputer biasa tidak bisa menghasilkan angka benar-benar acak karena semuanya berdasarkan logika deterministik. Makanya kita pakai PRNG yang "cukup acak untuk kebanyakan kasus".
#include <iostream>
#include <chrono>
#include <unistd.h>
#include <vector>
#include <numeric>
#include <algorithm>
#include "SortingAlgorithm.hpp"

using namespace std;
using namespace SortLibrary;

// Questa funzione genera un vettore random di dimensione n, la dimensione è richiesta dall'utente
vector<int> randomVector(unsigned int n, unsigned int r)
{
    // Creo un vetore di dimensione n, ordinato partendo da 1.
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);

    // Sostituisco i valori del vettore in numeri random compresi tra 0 e 100.
    srand(r);
    for(unsigned int i = 0; i < n; i++)
        v[i] = rand() % 100;

    return v;
}


// In questo main intendo confrontare la velocità degli algoritmi di BubbleSort e di MergeSort. So che l'algoritmo di MergeSort ha un costo in tempo nlog(n) mentre il
// BubbleSort ha un costo in tempo di O(n^2).

int main()
{
    unsigned int r = 0;

    // Chiedo all'utente la dimensione dei vettori.
    cout << "Enter the dimension of the vector: " << endl;
    unsigned int n;
    cin >> n;

    // Inizializzo il numero di iterazioni del ciclo while per calcolare i tempi
    unsigned int t = 50;

    /// MODIFICO IL SEME:
    // Nel seguente ciclo while modifico il seme per ogni misurazione del tempo, in modo da generare ogni volta vettori random con valori diversi, mantenendo uguale la dimensione.

    cout << "Test 1: change the seed" << endl;

    // Inizializzo il numero di iterazioni del ciclo while per creare vettori diversi
    unsigned int d = 50;

    while(r < d)
    {
        unsigned int a = 0;
        unsigned int b = 0;
        double duration_m = 0;
        double duration_b = 0;

        // MERGESORT:

        // Questo ciclo while ripete la chiamata al MergeSort per calcolare un tempo medio più attendibile
        while(a <= t)
        {
            // Genero un vettore random con la funzione randomVector per MergeSort
            vector<int> v = randomVector(n, r);

            chrono::steady_clock::time_point t_begin = chrono::steady_clock::now();
            MergeSort(v);
            chrono::steady_clock::time_point t_end = chrono::steady_clock::now();

            double duration = chrono::duration_cast<chrono::microseconds>(t_end - t_begin).count();
            duration_m += duration;
            a++;
        }

        // Calcolo la media dei tempi
        double avg_m = duration_m / t;
        cout << "Average duration for MergeSort: " << avg_m << " microseconds" << endl;


        // BUBBLESORT:


        // Questo ciclo while ripete la chiamata al BubbleSort per calcolare un tempo medio più attendibile
        while(b <= t)
        {
            // Genero un vettore random con la funzione randomVector per BubbleSort
            vector<int> w = randomVector(n, r);

            chrono::steady_clock::time_point t_begin = chrono::steady_clock::now();
            BubbleSort(w);
            chrono::steady_clock::time_point t_end = chrono::steady_clock::now();

            double duration = chrono::duration_cast<chrono::microseconds>(t_end - t_begin).count();
            duration_b += duration;
            b++;
        }

        // Calcolo la media dei tempi
        double avg_b = duration_b / t;
        cout << "Average duration for BubbleSort: " << avg_b << " microseconds" << endl;
        cout << endl;

        // Aumento di 10 il seme e ripeto il ciclo.
        r += 10;
    }
    // CONSIDERAZIONI FINALI:
    // Si noti che, modificando i valori dei vettori random ma mantenendo invariata la dimensione, i tempi rimangono simili.
    // L'algoritmo di BubbleSort risulta essere più efficiente dell'algoritmo di MergeSort.

    cout << endl;

    /// MODIFICO LA DIMENSIONE:
    // Nel seguente ciclo while modifico la dimensione dei vettori per ogni misurazione del tempo, mantenendo invariato il seme

    cout << "Test 2: change the dimension" << endl;

    // Inizializzo il numero di iterazioni del ciclo while per creare vettori diversi
    unsigned int p = n * n;

    while(n < p)
    {
        unsigned int a = 0;
        unsigned int b = 0;
        double duration_m = 0;
        double duration_b = 0;

        // MERGESORT:

        // Questo ciclo while ripete la chiamata al MergeSort per calcolare un tempo medio più attendibile
        while(a <= t)
        {
            // Genero un vettore random con la funzione randomVector per MergeSort
            vector<int> v = randomVector(n, r);

            chrono::steady_clock::time_point t_begin = chrono::steady_clock::now();
            MergeSort(v);
            chrono::steady_clock::time_point t_end = chrono::steady_clock::now();

            double duration = chrono::duration_cast<chrono::microseconds>(t_end - t_begin).count();
            duration_m += duration;
            a++;

        }

        // Calcolo la media dei tempi
        double avg_m = duration_m / t;
        cout << "Average duration for MergeSort: " << avg_m << " microseconds" << endl;


        // BUBBLESORT:

        // Questo ciclo while ripete la chiamata al BubbleSort per calcolare un tempo medio più attendibile
        while(b <= t)
        {
            // Genero un vettore random con la funzione randomVector per BubbleSort
            vector<int> w = randomVector(n, r);

            chrono::steady_clock::time_point t_begin = chrono::steady_clock::now();
            BubbleSort(w);
            chrono::steady_clock::time_point t_end = chrono::steady_clock::now();

            double duration = chrono::duration_cast<chrono::microseconds>(t_end - t_begin).count();
            duration_b += duration;
            b++;

        }

        // Calcolo la media dei tempi
        double avg_b = duration_b / t;
        cout << "Average duration for BubbleSort: " << avg_b << " microseconds" << endl;
        cout << endl;
        n += n;
    }
    // CONSIDERAZIONI FINALI:
    // Si noti che modificando la dimensione dei vettori e mantenendo invariati i valori random, i tempi crescono al crescere della dimensione.
    // In particolare si noti che l'algoritmo di BubbleSort rimane più efficiente dell'algoritmo di MergeSort finchè le dimensioni non sono troppo
    // elevate. Per dimensioni grandi invece l'algoritmo di MergeSort risulta essere più efficiente. Provando per esempio con n = 50, si nota che
    // si ha questo scambio di efficienza per n tra 100 e 200.


    return 0;
}


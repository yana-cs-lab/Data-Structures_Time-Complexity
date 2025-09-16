//ID: 323607457 - Yana Antonets
//ID: 214303661 - Shahar Akiva

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <utility> 
#include <iomanip> 

using namespace std;

int Search1(int V[], int m, int x, int& comparisons);
int Search2(int V[], int m, int x, int& comparisons);
int Search3(int V[], int m, int x, int& comparisons);



int main() {
    
    srand(time(0));

    const int NUM_TESTS = 500; 
    const int m = 1000; //array length

    double total_comps1 = 0;
    double total_comps2 = 0;
    double total_comps3 = 0;

    // Creating 500 random arrays
    for (int i = 0; i < NUM_TESTS; ++i) {

        // Randomizing 'n'
        int n = 200 + rand() % 101; // number between 200 - 300

        // filling arrays with random sorted numbers
        vector<int> temp_nums;
        for (int j = 0; j < n; ++j) {
            temp_nums.push_back(1 + rand() % 10000); // between 1 - 10000
        }
        sort(temp_nums.begin(), temp_nums.end());

        int V[m] = { 0 }; 
        for (int j = 0; j < n; ++j) {
            V[j] = temp_nums[j];
        }

        // Randomizing 'x'
        int x;
        x = 1 + rand() % 10000;


        int comparisons1 = 0, comparisons2 = 0, comparisons3 = 0;

        //Running algorithms
        Search1(V, m, x, comparisons1);
        total_comps1 += comparisons1;

        Search2(V, m, x, comparisons2);
        total_comps2 += comparisons2;

        Search3(V, m, x, comparisons3);
        total_comps3 += comparisons3;
    }

    // Calculating avarages and printing
    cout << "200<=n<=300" << std::endl;
    cout << "Search1: " << total_comps1 / NUM_TESTS << endl;
    cout << "Search2: " << total_comps2 / NUM_TESTS << endl;
    cout << "Search3: " << total_comps3 / NUM_TESTS << endl;

    return 0;
}



// Search1 O(n) 

int Search1(int V[], int m, int x, int& comparisons) {
    comparisons = 0; 
    for (int i = 0; i < m; ++i) {

        comparisons++;
        if (V[i] > x || V[i] == 0) {
            return -1;
        }

        comparisons++;
        if (V[i] == x) {
            return i; 
        }
    }
    return -1;
}


// Search2 O(log m) - divide and conquer

int Search2(int V[], int m, int x, int& comparisons) {
    comparisons = 0;
    int low = 0;
    int high = m - 1;

    while (low <= high) 
    {
        int mid = low + (high - low) / 2;
        
        comparisons++; 
        //checking middle and go left
        if (V[mid] == 0 || V[mid] > x) {
                high = mid - 1;
        }
        else
        {
            comparisons++; 
            //checking middle and go right
            if (V[mid] < x) {
                low = mid + 1;
            }
            else
            {
                return mid;
            }
        }
    }

    return -1;
}


// Search3 O(log n) 
int Search3(int V[], int m, int x, int& comparisons) {
    comparisons = 0;

    int bound = 1;
    while (bound < m && V[bound] != 0 && V[bound] < x) {
        comparisons += 3; 
        bound *= 2;
    }

    int low = bound / 2;
    int high;     
    if (bound < m) {
        high = bound;
    }
    else {
        high = m - 1;
    }


    while (low <= high) {
        int mid = low + (high - low) / 2;

        comparisons++;
        if (V[mid] == x) {
            return mid;
        }

        comparisons++;
        if (V[mid] != 0 && V[mid] < x) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1;
}



# Data Structures – Time Complexity Analysis 📊

Understanding how fast or slow an algorithm runs is a key concept in Computer Science.  
In this project, I tested and compared three different search algorithms on random arrays to see how their **time complexity**  
(O(n), O(log m), O(log n)) affects real performance.  

The goal is to bridge the **theory of algorithms** with practical experiments by measuring the **average number of comparisons** each search requires.  

This project demonstrates the performance differences between three search algorithms by measuring the **average number of comparisons** required.

## Algorithms Compared 🔍

The project includes three classic search algorithms, each with a different efficiency level:

- **Search1 – Linear Search (O(n))**  
  Goes through the array one element at a time until it finds the target or reaches the end. Simple, but slow for large arrays.  

- **Search2 – Binary Search (O(log m))**  
  Works on sorted arrays by repeatedly cutting the search space in half, making it much faster.  

- **Search3 – Exponential + Binary Search (O(log n))**  
  Quickly finds a range where the target might be (by doubling the index), then applies Binary Search in that range. Efficient for very large or unbounded arrays.

## How It Works ⚙️
- Generates multiple sorted arrays of random integers.  
- Searches for random values using all three algorithms.  
- Tracks and outputs the average number of comparisons for each algorithm.  

## Example Output 🖥️
200 <= n <= 300  
Search1: 150.23  
Search2: 8.42  
Search3: 6.17  

## Purpose 🚀
This project illustrates how **time complexity** directly impacts algorithm efficiency, bridging theoretical concepts with practical experiments.

## How to Run▶️
1. Clone the repository:
   ```bash
   git clone https://github.com/YanaAnnt/Data-Structures_Time-Complexity.git

2. Compile the code:  
   ```
   g++ searches.cpp -o searches
   ```

3. Run the program:
   ```
   ./searches
   ```

 
© 2025 Yana Annt. All rights reserved.

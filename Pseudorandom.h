#pragma once
#include<iostream>
#include<stdexcept>
using namespace std;

class Pseudorandom
{
private:
    int seed;        
    int multiplier;  
    int increment;   
    int modulus;     
    bool initialized = false;

public:
    // Constructor
    // Pre-condition: s, m, i, mod are valid integers (mod > 0)
    // Post-condition: A pseudorandom generator is created with given parameters
    Pseudorandom(int s, int m, int i, int mod)
    {
        seed = s;
        multiplier = m;
        increment = i;
        modulus = mod;
    }

    // --- Default constructor ---
    // Pre-condition: None. This constructor can be called without any arguments.
    // Post-condition: A Pseudorandom object is created with default values:
    //                 seed = 1, multiplier = 40, increment = 725, modulus = 729.
    Pseudorandom()
    {
        seed = 1;
        multiplier = 40;
        increment = 725;
        modulus = 729;
    }

   

    // ================================= Accessors ==================================
    // Pre-condition: The PseudoRandom object has been initialized
    // Post-condition: Returns current seed value
    int getSeed() const { return seed; }

    // Pre-condition: The PseudoRandom object has been initialized
    // Post-condition: Returns current multiplier value
    int getMultiplier() const { return multiplier; }

    // Pre-condition: The PseudoRandom object has been initialized
    // Post-condition: Returns current increment value
    int getIncrement() const { return increment; }

    // Pre-condition: The PseudoRandom object has been initialized
    // Post-condition: Returns current modulus value
    int getModulus() const { return modulus; }

    // =================================== Mutators ====================================
    // Pre-condition: s is a valid integer
    // Post-condition: Seed is updated to s
    void setSeed(int s) { seed = s; }

    // Pre-condition: m is a valid integer
    // Post-condition: Multiplier is updated to m
    void setMultiplier(int m) { multiplier = m; }

    // Pre-condition: i is a valid integer
    // Post-condition: Increment is updated to i
    void setIncrement(int i) { increment = i; }

    // Pre-condition: mod > 0
    // Post-condition: Modulus is updated to mod
    void setModulus(int mod)
    {
        if (mod <= 0) throw runtime_error("Modulus must be > 0.");
        modulus = mod;
        initialized = true;
    }


    // --- Generate next number ---
    // Pre-condition: modulus > 0
    // Post-condition: Computes (multiplier * seed + increment) % modulus,
    //                 updates seed, and returns new number
    int getNextNumber() 
    {
        unsigned long long temp = static_cast<unsigned long long>(multiplier) * seed + increment;
        seed = static_cast<unsigned int>(temp % modulus);
        return seed;
    }

    // --- Generate indirect next number (two steps ahead) ---
    // Pre-condition: modulus > 0
    // Post-condition: Advances generator twice and returns the second value
    int getIndirectNextNumber()
    {
        getNextNumber();       
        return getNextNumber(); 
    }

    // --- Run experiment ---
    // Pre-condition: n > 0
    // Post-condition: Prints n generated numbers to console without changing stored seed
    void runExperiment(int n) 
    {
        cout << "Experiment (" << n << " numbers): ";
        int temp = seed;
        for (int i = 0; i < n; i++) {
            temp = (multiplier * temp + increment) % modulus;
            cout << temp << " ";
        }
        cout << "\n";
    }

    // --- Generate next double in [0,1) ---
    // Pre-condition: modulus > 0
    // Post-condition: Returns next pseudorandom number divided by modulus
    double getNextDouble() {
        return static_cast<double>(getNextNumber()) / static_cast<double>(modulus);
    }

    // --- Run experiment: distribution in 10 intervals (no vector) ---
    // Pre-condition: modulus > 0; iterations > 0
    // Post-condition: Prints a table of number occurrences in 10 equal intervals [0,1) 
    //                 after generating 'iterations' pseudorandom numbers
    void runDistributionExperiment(int iterations = 1000000)
    {

        if (iterations <= 0) throw runtime_error("Iterations must be positive.");

        int counts[10] = { 0 };

        for (int i = 0; i < iterations; i++)
        {
            double val = getNextDouble();
            int index = static_cast<int>(val * 10);
            if (index == 10) index = 9; // fix edge case val == 1.0
            counts[index]++;
        }

        cout << "\nRange\t\tNumber of Occurrences\n";
        for (int i = 0; i < 10; i++)
            cout << "[" << i * 0.1 << " ... " << (i + 1) * 0.1 << ")\t" << counts[i] << "\n";
    }

};


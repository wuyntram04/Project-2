#pragma once

#include<algorithm>
class Statistician
{
private:
    int count;          // number of elements
    double total;       // sum of elements
    double lastValue;   // last number entered
    double smallest;    // minimum value
    double largest;     // maximum value
    bool isEmpty = false;       // to handle empty case

public:
    // Constructor
   // Pre-condition: None
   // Post-condition: Statistician is initialized and empty
    Statistician()
    {
        reset();
    }

     //Reset all values
    //Pre-condition: Statistician object exists
   //Post-condition: Sequence is cleared; count, total, lastValue, smallest, largest reset; isEmpty = true
    void reset()
    {
        count = 0;
        total = 0.0;
        lastValue = 0.0;
        smallest = 0.0;
        largest = 0.0;
        isEmpty = true;
    }

    // Add next number to the sequence
    // Pre-condition: Statistician object exists; num is a valid double
    // Post-condition: Number added; count, total, lastValue updated; smallest/largest updated; isEmpty = false
    void next_number(double num)
    {
        if (isEmpty) // first number
        {
            lastValue = smallest = largest = total = num;
            count = 1;
            isEmpty = false;
        }
        else
        {
            lastValue = num;
            total += num;
            count++;
            if (num < smallest) smallest = num;
            if (num > largest) largest = num;
        }
    }

    // Get the number of elements
    // Pre-condition: The Statistician object has been created.
    // Post-condition: Returns count of numbers in sequence
    int length() const { return count; }

    // Get the sum of elements
    // Pre-condition: Statistician object exists
    // Post-condition: Returns total sum
    double sum() const { return total; }

    // Get the last number
    // Pre-condition: Sequence is not empty
    // Post-condition: Returns last number; throws exception if empty
    double last() const
    {
        if (isEmpty) throw runtime_error("No numbers entered. Cannot get last number.");
        return lastValue;
    }

    // Get mean of sequence
   // Pre-condition: Sequence is not empty
   // Post-condition: Returns mean; throws exception if empty
    double mean() const
    {
        if (isEmpty) throw runtime_error("No numbers entered. Cannot calculate mean.");
        return total / count;
    }

    // Get minimum
    // Pre-condition: Sequence is not empty
    // Post-condition: Returns smallest number; throws exception if empty
    double minimum() const
    {
        if (isEmpty) throw runtime_error("No numbers entered. Cannot get minimum.");
        return smallest;
    }

    // Get maximum
   // Pre-condition: Sequence is not empty
   // Post-condition: Returns largest number; throws exception if empty
    double maximum() const
    {
        if (isEmpty) throw runtime_error("No numbers entered. Cannot get maximum.");
        return largest;
    }

    // Combine two statisticians
    // Pre-condition: Two Statistician objects exist
    // Post-condition: Returns a new Statistician containing all numbers from s1 and s2; lastValue = s2.lastValue; smallest/largest updated
    friend Statistician operator+(const Statistician& s1, const Statistician& s2)
    {
        Statistician result;

        if (s1.isEmpty && s2.isEmpty) return result;
        if (s1.isEmpty) return s2;
        if (s2.isEmpty) return s1;

        result.count = s1.count + s2.count;
        result.total = s1.total + s2.total;
        result.lastValue = s2.lastValue;
        result.smallest = (s1.smallest < s2.smallest) ? s1.smallest : s2.smallest;
        result.largest = (s1.largest > s2.largest) ? s1.largest : s2.largest;
        result.isEmpty = false;

        return result;
    }
};



#pragma once
#include <stdexcept>
class Statistician
{
private:
    int count;          // number of elements
    double total;       // sum of elements
    double lastValue;   // last number entered
    double smallest;    // minimum value
    double largest;     // maximum value
    bool isEmpty;       // to handle empty case

public:
    // Constructor
    Statistician()
    {
        count = 0;
        total = 0.0;
        isEmpty = true;
    }

    // Erase sequence
    void reset()
    {
        count = 0;
        total = 0.0;
        isEmpty = true;
    }


    bool isEmptyFlag()
    {
        if (count == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Feed next number
    void next_number(double num)
    {
        lastValue = num;
        total += num;
        count++;

        if (isEmptyFlag())
        {
            smallest = largest = num;
            isEmpty = false;
        }
        else {
            if (num < smallest) smallest = num;
            if (num > largest) largest = num;
        }
    }

    // Getters
    int length() const { return count; }
    double sum() const { return total; }



    double last() const
    {
        if (isEmpty)
            return lastValue;
    }

    double mean() const
    {
        if (isEmpty)
            return total / count;
    }

    double minimum() const
    {
        if (isEmpty)
            return smallest;
    }

    double maximum() const
    {
        if (isEmpty)
            return largest;
    }

    // Friend operator+ to combine two statisticians
    friend Statistician operator+(const Statistician& s1, const Statistician& s2) {
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



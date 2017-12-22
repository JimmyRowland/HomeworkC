

#ifndef SEARCHING_LISTS_SEQUENTIAL_BINARY_AND_FIBONACCI_SEARCHES_EASTERCALCULATOR_H
#define SEARCHING_LISTS_SEQUENTIAL_BINARY_AND_FIBONACCI_SEARCHES_EASTERCALCULATOR_H


class EasterCalculator{
public:
    EasterCalculator();
    explicit EasterCalculator(int year);
    int getYear() const;

    void setYear(int year);

    void printEasterDay() const;
    ~EasterCalculator();
private:
    int year;
    };

#endif //SEARCHING_LISTS_SEQUENTIAL_BINARY_AND_FIBONACCI_SEARCHES_EASTERCALCULATOR_H

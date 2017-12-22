#ifndef SEARCHING_LISTS_SEQUENTIAL_BINARY_AND_FIBONACCI_SEARCHES_WALLET_H
#define SEARCHING_LISTS_SEQUENTIAL_BINARY_AND_FIBONACCI_SEARCHES_WALLET_H

class Wallet{
public:
    Wallet(double a, double b);
    Wallet();
    void printChange();

    void setA();
    void setA(double cash);
    void setB();
    void setB(double cash);
    double getA() const;
    double getB() const;
    ~Wallet();

private:
    double a,b;
};
#endif //SEARCHING_LISTS_SEQUENTIAL_BINARY_AND_FIBONACCI_SEARCHES_WALLET_H

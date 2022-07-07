#include<iostream>
using namespace std;

class Fraction {
    int numerator;
    int denominator;
    public:
        Fraction(int numerator, int denominator) {
            this->numerator = numerator;
            this->denominator = denominator;
            simplify();
        }
        void setNumerator(int numerator) {
            this->numerator = numerator;
        }
        void setDenominator(int denominator) {
            this->denominator = denominator;
        }
        int getNumerator() const {
            return numerator;
        }
        int getDenominator() const {
            return denominator;
        }
        void display() const {
            cout << this->numerator << " / " << denominator << "\n";
        }
        void simplify() {
            int gcd = min(numerator, denominator);
            while(gcd >= 1) {
                if(numerator % gcd == 0 && denominator % gcd == 0) {
                    break;
                }
                gcd--;
            }
            numerator = numerator / gcd;
            denominator = denominator / gcd;
        }
        Fraction add(Fraction const &f2) const {
            int newNumerator = (numerator * f2.denominator) + (denominator * f2.numerator);
            int newDenominator = denominator * f2.denominator;
            Fraction newFraction(newNumerator, newDenominator);
            newFraction.simplify();
            return newFraction;
        }
        Fraction multiply(Fraction const &f2) const {
            int newNumerator = numerator * f2.numerator;
            int newDenominator = denominator * f2.denominator;
            Fraction newFraction(newNumerator, newDenominator);
            newFraction.simplify();
            return newFraction;
        }
        Fraction operator+(Fraction const &f2) const {
            int newNumerator = (numerator * f2.denominator) + (denominator * f2.numerator);
            int newDenominator = denominator * f2.denominator;
            Fraction newFraction(newNumerator, newDenominator);
            newFraction.simplify();
            return newFraction;
        }
        Fraction operator*(Fraction const &f2) const {
            int newNumerator = numerator * f2.numerator;
            int newDenominator = denominator * f2.denominator;
            Fraction newFraction(newNumerator, newDenominator);
            newFraction.simplify();
            return newFraction;
        }
        bool operator==(Fraction const &f2) const {
            return numerator == f2.numerator && denominator == f2.denominator;
        }
        Fraction& operator++() {
            numerator = numerator + denominator;
            return *this;
        }
        Fraction operator++(int) {
            Fraction returnValue(numerator, denominator);
            numerator = numerator + denominator;
            return returnValue;
        }
        Fraction& operator+=(Fraction const& f2) {
            numerator = (numerator * f2.denominator) + (denominator * f2.numerator);
            denominator = denominator * f2.denominator;
            simplify();
            return *this;
        }
};
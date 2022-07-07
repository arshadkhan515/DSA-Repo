#include<iostream>
using namespace std;

class Fraction {
    int numerator;
    int denominator;
    public:
        Fraction(int numerator, int denominator) {
            this->numerator = numerator;
            this->denominator = denominator;
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
        void add(Fraction const &f2) {
            numerator = (numerator * f2.denominator) + (denominator * f2.numerator);
            denominator = denominator * f2.denominator;
            simplify();
        }
        void multiply(Fraction const &f2) {
            numerator = numerator * f2.numerator;
            denominator = denominator * f2.denominator;
            simplify();
        }
};
#include "ComplexNumber.h"
#include <cmath>

ComplexNumber::ComplexNumber(const RationalNumber realPart, const RationalNumber imaginaryPart)
    : realPart(realPart), imaginaryPart(imaginaryPart) {}

RationalNumber ComplexNumber::getRealPart() const {
    return this->realPart;
}

RationalNumber ComplexNumber::getImaginaryPart() const {
    return this->imaginaryPart;
}

void ComplexNumber::setRealPart(const RationalNumber real_part) {
    realPart = real_part;
}

void ComplexNumber::setImaginaryPart(const RationalNumber imaginary_part) {
    imaginaryPart = imaginary_part;
}

ComplexNumber& ComplexNumber::operator=(const ComplexNumber& complex_number) {
    if (this == &complex_number) {
        return *this;
    }

    realPart = complex_number.realPart;
    imaginaryPart = complex_number.imaginaryPart;
    return *this;
}

ComplexNumber ComplexNumber::operator-() const {
    return {-this->realPart, -this->imaginaryPart};
}

ostream& operator<<(ostream& os, const ComplexNumber& complex_number) {
    if (complex_number.realPart != RationalNumber(0, 1)) {
        if (complex_number.imaginaryPart > RationalNumber(0, 1))
            return os << complex_number.realPart << "+" << complex_number.imaginaryPart << "i";
        else if (complex_number.imaginaryPart == RationalNumber(0, 1))
            return os << complex_number.realPart;
        else
            return os << complex_number.realPart << "-" << -complex_number.imaginaryPart << "i";
    } else {
        if (complex_number.imaginaryPart != RationalNumber(0, 1))
            return os << complex_number.imaginaryPart << "i";
        else
            return os << 0;
    }
}

bool operator==(const ComplexNumber& lhs, const ComplexNumber& rhs) {
    return (lhs.realPart == rhs.realPart) && (lhs.imaginaryPart == rhs.imaginaryPart);
}

bool operator!=(const ComplexNumber& lhs, const ComplexNumber& rhs) {
    return !(lhs == rhs);
}

ComplexNumber operator+(const ComplexNumber &lhs, const ComplexNumber &rhs) {
    return {
        lhs.realPart + rhs.realPart,
        lhs.imaginaryPart + rhs.imaginaryPart
    };
}

ComplexNumber operator-(const ComplexNumber &lhs, const ComplexNumber &rhs) {
    return {
        lhs.realPart - rhs.realPart,
        lhs.imaginaryPart - rhs.imaginaryPart
    };
}

ComplexNumber operator*(const ComplexNumber &lhs, const ComplexNumber &rhs) {
    return {
        lhs.realPart * rhs.realPart - lhs.imaginaryPart * rhs.imaginaryPart,
        lhs.realPart * rhs.imaginaryPart + rhs.realPart * lhs.imaginaryPart
    };
}

ComplexNumber operator/(const ComplexNumber &lhs, const ComplexNumber &rhs) {
    return {
        (lhs.realPart * rhs.realPart + lhs.imaginaryPart * rhs.imaginaryPart)
        / (pow(rhs.realPart, 2) + pow(rhs.imaginaryPart, 2)),
        (rhs.realPart * lhs.imaginaryPart - lhs.realPart * rhs.imaginaryPart)
        / (pow(rhs.realPart, 2) + pow(rhs.imaginaryPart, 2))
    };
}

ComplexNumber operator+=(ComplexNumber &lhs, const ComplexNumber &rhs) {
    lhs = lhs + rhs;
    return lhs;
}

ComplexNumber operator-=(ComplexNumber &lhs, const ComplexNumber &rhs) {
    lhs = lhs - rhs;
    return lhs;
}

ComplexNumber operator*=(ComplexNumber &lhs, const ComplexNumber &rhs) {
    lhs = lhs * rhs;
    return lhs;
}

ComplexNumber operator/=(ComplexNumber &lhs, const ComplexNumber &rhs) {
    lhs = lhs / rhs;
    return lhs;
}
#pragma once
#include <ostream>

#include "../RationalNumber/RationalNumber.h"

using namespace std;

class ComplexNumber {

private:

    // Действительная часть
    RationalNumber realPart;

    // Мнимая часть
    RationalNumber imaginaryPart;

public:

    [[nodiscard]] RationalNumber getRealPart() const;

    [[nodiscard]] RationalNumber getImaginaryPart() const;

    void setRealPart(RationalNumber real_part);

    void setImaginaryPart(RationalNumber imaginary_part);

    ComplexNumber(RationalNumber realPart, RationalNumber imaginaryPart);

    ComplexNumber& operator=(const ComplexNumber& complex_number);

    ComplexNumber operator-() const;

    friend ostream& operator<<(ostream& os, const ComplexNumber& complex_number);

    friend bool operator==(const ComplexNumber& lhs, const ComplexNumber& rhs);

    friend bool operator!=(const ComplexNumber& lhs, const ComplexNumber& rhs);

    friend ComplexNumber operator+(const ComplexNumber& lhs, const ComplexNumber& rhs);

    friend ComplexNumber operator-(const ComplexNumber& lhs, const ComplexNumber& rhs);

    friend ComplexNumber operator*(const ComplexNumber& lhs, const ComplexNumber& rhs);

    friend ComplexNumber operator/(const ComplexNumber& lhs, const ComplexNumber& rhs);

    friend ComplexNumber operator+=(ComplexNumber& lhs, const ComplexNumber& rhs);

    friend ComplexNumber operator-=(ComplexNumber& lhs, const ComplexNumber& rhs);

    friend ComplexNumber operator*=(ComplexNumber& lhs, const ComplexNumber& rhs);

    friend  ComplexNumber operator/=(ComplexNumber& lhs, const ComplexNumber& rhs);
};




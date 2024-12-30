#include "RationalNumber.h"

#include <numeric>
#include <stdexcept>
#include <cmath>

using namespace std;

RationalNumber::RationalNumber(const int m, const unsigned int n) {
    if (n == 0)
        throw invalid_argument("n must be natural number");

    const int GCD = gcd(m, static_cast<int>(n));
    this->m = m / GCD;
    this->n = n / GCD;
}

int RationalNumber::getNumerator() const {
    return this->m;
}

int RationalNumber::getDenominator() const {
    return this->n;
}

void RationalNumber::setNumerator(const int m) {
    this->m = m;
}

void RationalNumber::setDenominator(const unsigned int n) {
    if (n != 0)
        this->n = n;
    else
        throw invalid_argument("n must be natural number");
}

RationalNumber::operator float() const {
    return static_cast<float>(m) / n;
}

RationalNumber::operator double() const {
    return static_cast<double>(m) / n;
}

RationalNumber::operator int() const {
    return static_cast<int>(static_cast<double>(*this));
}

RationalNumber RationalNumber::operator-() const {
    return {-m, n};
}

bool RationalNumber::operator==(const int i) const {
    return static_cast<int>(*this) == i;
}

bool RationalNumber::operator>(const int i) const {
    return static_cast<int>(*this) > i;
}

bool RationalNumber::operator!=(const int i) const {
    return !(*this == i);
}


std::ostream& operator<<(std::ostream& os, const RationalNumber& obj) {
    if (obj.m == 0) {
        return os << 0;
    } else if (obj.m < 0) {
        return os << "-(" << std::abs(obj.m) << "/" << obj.n << ")";
    } else {
        return os << "(" << obj.m << "/" << obj.n << ")";
    }
}


bool operator==(const RationalNumber &lhs, const RationalNumber &rhs) {
    return (lhs.m * rhs.n == rhs.m * lhs.n);
}

bool operator!=(const RationalNumber &lhs, const RationalNumber &rhs) {
    return !(lhs == rhs);
}

bool operator<(const RationalNumber &lhs, const RationalNumber &rhs) {
    return (lhs.m * rhs.n < rhs.m * lhs.n);
}

bool operator<=(const RationalNumber &lhs, const RationalNumber &rhs) {
    return !(rhs < lhs);
}

bool operator>(const RationalNumber &lhs, const RationalNumber &rhs) {
    return rhs < lhs;
}

bool operator>=(const RationalNumber &lhs, const RationalNumber &rhs) {
    return !(lhs < rhs);
}

RationalNumber operator+(const RationalNumber &lhs, const RationalNumber &rhs) {
    return {
        static_cast<int>(lhs.m * rhs.n + rhs.m * lhs.n),
        lhs.n * rhs.n
    };
}

RationalNumber operator-(const RationalNumber &lhs, const RationalNumber &rhs) {
    return {
        static_cast<int>(lhs.m * rhs.n - rhs.m * lhs.n),
        lhs.n * rhs.n
    };
}

RationalNumber operator*(const RationalNumber &lhs, const RationalNumber &rhs) {
    return {
        lhs.m * rhs.m,
        lhs.n * rhs.n
    };
}

RationalNumber operator/(const RationalNumber &lhs, const RationalNumber &rhs) {
    return {
        static_cast<int>(lhs.m * rhs.n),
        lhs.n * rhs.m
    };
}

RationalNumber operator+=(RationalNumber &lhs, const RationalNumber &rhs) {
    lhs = lhs + rhs;
    return lhs;
}

RationalNumber operator-=(RationalNumber &lhs, const RationalNumber &rhs) {
    lhs = lhs - rhs;
    return lhs;
}

RationalNumber operator*=(RationalNumber &lhs, const RationalNumber &rhs) {
    lhs = lhs * rhs;
    return lhs;
}

RationalNumber operator/=(RationalNumber &lhs, const RationalNumber &rhs) {
    lhs = lhs / rhs;
    return lhs;
}

RationalNumber pow(const RationalNumber &base, const int exponent) {
    if (exponent == 0) {
        return {1, 1};
    }

    RationalNumber result = base;
    for (int i = 1; i < abs(exponent); ++i) {
        result = result * base;
    }

    if (exponent < 0) {
        return {result.getDenominator(), static_cast<unsigned int>(result.getNumerator())};
    }

    return result;
}

RationalNumber abs(const RationalNumber &number) {
    return {abs(number.getNumerator()), static_cast<unsigned int>(number.getDenominator())};
}




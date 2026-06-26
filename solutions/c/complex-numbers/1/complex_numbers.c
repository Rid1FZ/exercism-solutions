#include "complex_numbers.h"

#include <math.h>

complex_t c_add(complex_t a, complex_t b)
{
    return (complex_t){
        .real = a.real + b.real,
        .imag = a.imag + b.imag,
    };
}

complex_t c_sub(complex_t a, complex_t b)
{
    return (complex_t){
        .real = a.real - b.real,
        .imag = a.imag - b.imag,
    };
}

complex_t c_mul(complex_t a, complex_t b)
{
    return (complex_t){
        .real = (a.real * b.real) - (a.imag * b.imag),
        .imag = (a.real * b.imag) + (a.imag * b.real),
    };
}

complex_t c_div(complex_t num, complex_t den)
{
    complex_t result;

    double denom_mag = (den.real * den.real) + (den.imag * den.imag);

    if (denom_mag == 0.0) {
        result.real = NAN;
        result.imag = NAN;
        return result;
    }

    result.real = ((num.real * den.real) + (num.imag * den.imag)) / denom_mag;
    result.imag = ((num.imag * den.real) - (num.real * den.imag)) / denom_mag;

    return result;
}

double c_abs(complex_t x)
{
    return sqrt(pow(x.real, 2) + pow(x.imag, 2));
}

complex_t c_conjugate(complex_t x)
{
    return (complex_t){
        .real = x.real,
        .imag = -x.imag,
    };
}

double c_real(complex_t x)
{
    return x.real;
}

double c_imag(complex_t x)
{
    return x.imag;
}

complex_t c_exp(complex_t x)
{
    double e_x = exp(x.real);

    return (complex_t){
        .real = e_x * cos(x.imag),
        .imag = e_x * sin(x.imag),
    };
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct complex{
    double p_real;
    double p_imag;
    void (*func_io)(struct complex *numar);
    void (*func_op)(struct complex *numar1, struct complex *numar2);
};

void citire_numar(struct complex *numar){
    printf("Partea reala: ");
    scanf("%lf", &numar->p_real);
    printf("Partea imaginara: ");
    scanf("%lf", &numar->p_imag);
}

void afisare_numar(struct complex *numar){
    printf("Numarul complex este: %lf + i* %lf \n", numar->p_real, numar->p_imag);
}

struct complex adunare_complexe(struct complex *numar1, struct complex *numar2){
    struct complex suma;
    suma.p_real = numar1->p_real + numar2->p_real;
    suma.p_imag = numar1->p_imag + numar2->p_imag;
    return suma;
}

struct complex diferenta_complexe(struct complex *numar1, struct complex *numar2){
    struct complex diferenta;
    diferenta.p_real = numar1->p_real - numar2->p_real;
    diferenta.p_imag = numar1->p_imag - numar2->p_imag;
    return diferenta;
}

///(a+ib)(c+id)= a*c + i*ad + i*bc - bd = ac-bd + i(ad+bc)

struct complex inmultire_complexe(struct complex *numar1, struct complex *numar2){
    struct complex inmultire;
    inmultire.p_real = numar1->p_real * numar2->p_real - numar1->p_imag * numar2->p_imag;
    inmultire.p_imag = numar1->p_real * numar2->p_imag + numar1->p_imag * numar2->p_real;
    return inmultire;
}

///(a+ib)/(c+id) = (a+ib)(c-id) / c^2 + d^2 = a*c - i*ad +i*bc +bd / c^2 + d^2 = ac + bd / c^2 + d^2     + i * (bc-ad)/c^2 + d^2

struct complex impartire_complexe(struct complex *numar1, struct complex *numar2){
    struct complex impartire;
    impartire.p_real = (numar1->p_real*numar2->p_real + numar1->p_imag*numar2->p_imag)/(pow(numar2->p_real, 2) + pow(numar2->p_imag, 2));
    impartire.p_imag = (numar1->p_imag*numar2->p_real - numar1->p_real*numar2->p_imag)/(pow(numar2->p_real, 2) + pow(numar2->p_imag, 2));
    return impartire;
}

int main()
{
    int counter;
    struct complex numar1, numar2, inmultire, inmultire_aux, *complex_ptr;
    //citire_numar(&numar1);
    //citire_numar(&numar2);
    //inmultire = inmultire_complexe(&numar1, &numar2);
    printf("Numarul de complexe: ");
    scanf("%d", &counter);
    complex_ptr = (struct complex*)malloc(counter*sizeof(struct complex));
    for(int i = 0 ; i < counter ; i++){
        printf("Partea Reala:");
        scanf("%lf", &(complex_ptr + i)->p_real);
        printf("Partea Imaginara:");
        scanf("%lf", &(complex_ptr + i)->p_imag);
    }
    inmultire_aux = inmultire_complexe((complex_ptr),(complex_ptr + 1));
    inmultire = inmultire_aux;
    for(int i = 2 ; i < counter ; i++){
        inmultire = inmultire_complexe(&inmultire, (complex_ptr + i));
    }
    afisare_numar(&inmultire);
    //afisare_numar(&inmultire);
    return 0;
}

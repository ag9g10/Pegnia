#ifndef GUARD_MERSENNE_TWISTER
#define GUARD_MERSENNE_TWISTER

void init_genrand(unsigned long s);
void init_by_array(unsigned long init_key[], int key_length);

// integer random functions
unsigned long genrand_int32(void);
long genrand_int31(void);

// floating point random functions
double genrand_real1(void);
double genrand_real2(void);
double genrand_real3(void);
double genrand_res53(void);

#endif

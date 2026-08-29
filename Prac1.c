/******************************************************************************
Código de ejemplos
******************************************************************************/

#include <stdio.h>
#include <inttypes.h>
/*
    Ejercicios de enmascaramientos.
    Se busca que imprima el valor que está comentado,
    alterando únicamente el valor anterior utilizando los operadores bitwise.
    Todas las conversiones deberían ser posibles con una sola operación.
*/

#define TEST_ASSERT(cond, msg) \
    if (!(cond)) { \
        printf("  ❌ [FAIL] %s\n", msg); \
        return 1; \
    } \
    printf("  ✅ [PASS] %s\n", msg); \

int main()
{
    uint16_t a = 0;
    uint32_t b = 0x1155;
    uint8_t arreglo[] = {0x18, 0x13, 0x15, 0x8, 0x3, 0x9};


    printf("\na = %X", a);
//  Como ejemplo se da el analisis de la primera operacion

//1 B0B0 
//       hex           bin
//  a = 0000 = 0000 0000 0000 0000  (valor original)
//      B0B0 = 1011 0000 1011 0000  (valor que se desea)
//  Observamos que todas las diferencias radica en que los bits tienen que estar habilitados,
//  por lo tanto usaremos el operador OR (|) para convertir esos bits en '1's

//    0000 0000 0000 0000  (valor original)
// OR 1011 0000 1011 0000  (mascara para lograrlo) = (1<<15) | (3<<12) | (1<<7) | (3<<4)
//------------------------------------------------
//    1011 0000 1011 0000  (valor que se desea)
    a |= (1<<15) | (3<<12) | (1<<7) | (3<<4);
    printf("\na = %X", a);
    TEST_ASSERT(a == 0xB0B0, "Ejercicio 1");
    
//2 BABA 
//      hex           bin
//  a = 0000 = 0000 0000 0000 0000  (valor original)
//      BABA = 1011 1010 1011 1010  (valor que se desea)
//  Observamos que todas las diferencias radica en que los bits tienen que estar habilitados,
//  por lo tanto usaremos el operador OR (|) para convertir esos bits en '1's

//    0000 0000 0000 0000  (valor original)
// OR 1011 1010 1011 1010  (mascara para lograrlo) 
//------------------------------------------------
//    1011 1010 1011 1010  (valor que se desea)
    a |= (1<<15) | (3<<12) | (1<<11) | (1<<9) | (1<<7) | (3<<4)| (1<<3)| (1<<1);
    printf("\na = %X", a);
    TEST_ASSERT(a == 0xBABA, "Ejercicio 2");

//3 BEBE
//      hex           bin
//  a = 0000 = 0000 0000 0000 0000  (valor original)
//      BEBE = 1011 1110 1011 1110  (valor que se desea)
//  Observamos que todas las diferencias radica en que los bits tienen que estar habilitados,
//  por lo tanto usaremos el operador OR (|) para convertir esos bits en '1's

//    0000 0000 0000 0000  (valor original)
// OR 1011 1110 1011 1110  (mascara para lograrlo) 
//------------------------------------------------
//    1011 1110 1011 1110  (valor que se desea)
    // TO-DO
    a |= (1<<15) | (3<<12) | (1<<11) | (6<<9) | (1<<7) | (3<<4)| (1<<3)| (6<<1);
    printf("\na = %X", a);
    TEST_ASSERT(a == 0xBEBE, "Ejercicio 3");

//4 FE00
//      hex           bin
//  a = 0000 = 0000 0000 0000 0000  (valor original)
//      FE00 = 1111 1110 0000 0000  (valor que se desea)
//  Observamos que todas las diferencias radica en que los bits tienen que estar habilitados,
//  por lo tanto usaremos el operador OR (|) para convertir esos bits en '1's

//    0000 0000 0000 0000  (valor original)
// OR 1111 1110 0000 0000  (mascara para lograrlo) 
//------------------------------------------------
//    1111 1110 0000 0000  (valor que se desea)
    // TO-DO
    a=0;
    a |= (1<<15) | (1<<14) |( 1<<13) | (1<<12) | (1<<15) | (7<<11) | (1<<10) | (1<<9);
    printf("\na = %X", a);
    TEST_ASSERT(a == 0xFE00, "Ejercicio 4");

//5 FEAA
//      hex           bin
//  a = 0000 = 0000 0000 0000 0000  (valor original)
//      FEAA = 1111 1110 1010 1010  (valor que se desea)
//  Observamos que todas las diferencias radica en que los bits tienen que estar habilitados,
//  por lo tanto usaremos el operador OR (|) para convertir esos bits en '1's

//    0000 0000 0000 0000  (valor original)
// OR 1111 1110 1010 1010  (mascara para lograrlo) 
//------------------------------------------------
//    1111 1110 1010 1010  (valor que se desea)
    // TO-DO
    a |= (1<<15) | (1<<14) |( 1<<13) | (1<<12) | (1<<15) | (7<<11) | (1<<10) | (1<<9) | (1<<7) | (1<<5) | (1<<3) | (1<<1);
    printf("\na = %X", a);
    TEST_ASSERT(a == 0xFEAA, "Ejercicio 5");

//6 0155
//      hex           bin
//  a = 0000 = 0000 0000 0000 0000  (valor original)
//      0155 = 0000 0001 0101 0101  (valor que se desea)
//  Observamos que todas las diferencias radica en que los bits tienen que estar habilitados,
//  por lo tanto usaremos el operador OR (|) para convertir esos bits en '1's

//    0000 0000 0000 0000  (valor original)
// OR 0000 0001 0101 0101   (mascara para lograrlo) 
//------------------------------------------------
//    0000 0001 0101 0101   (valor que se desea)
    // TO-DO
    a=0;
    a |= (1<<8) | (5<<4) | (5<<0);
    printf("\na = %X", a);
    TEST_ASSERT(a == 0x0155, "Ejercicio 6");

//7 0001

    // TO-DO
    a=0;
    a |= (1<<0);
    printf("\na = %X", a);
    TEST_ASSERT(a == 0x0001, "Ejercicio 7");

//8 0100
    // TO-DO
    a=0;
    a |= (1<<8);
    printf("\na = %X", a);
    TEST_ASSERT(a == 0x0100, "Ejercicio 8");

/************************************
* Ejercicios de apuntadores
************************************/
    b = ((~b) << 16) | b;
    uint16_t *ptr16 = (uint16_t *) &b; //CASTEO
    uint8_t *ptr8 = (uint8_t *) &b;

//9 DEADBEEF, utilizar los apuntadores para manipular el contenido de 'b' y lograr el valor deseado
    ptr8[0] = 0xEF;
    ptr8[1] = 0xBE;
    ptr8[2] = 0xAD;
    ptr8[3] = 0xDE;
    printf("\nb = %X", b);
    TEST_ASSERT(b == 0xDEADBEEF, "Ejercicio 9");


    /************************************
     * Ejercicios de structs con campos de bits
     ************************************/
    // Crear una esturctura de 32 bits y mappearla sobre la variable 'b'

//10 BADDC0DE
    typedef struct{
        uint32_t byte0 : 8;
        uint32_t byte1 : 8;
        uint32_t byte2 : 8;
        uint32_t byte3 : 8;
    } bytes_t;
    typedef union{
        uint32_t valor;
        bytes_t campos;
    } b_union_t;
   b_union_t *u = (b_union_t *) &b;

    u->campos.byte0 = 0xDE;
    u->campos.byte1 = 0xC0;
    u->campos.byte2 = 0xDD;
    u->campos.byte3 = 0xBA;
    printf("\nb = %X", b);
    TEST_ASSERT(b == 0xBADDC0DE, "Ejercicio 10");
    
// 11 Bitfiddling, toma el arreglo de 6 bytes y empaqueta los 5 LSB de cada elemento de 'arreglo'
// en 'b' como un valor de 32 bits en little-endian, dejando los 3 MSB en 0.
    b = 0;
    for(int i = 0; i<6; i++){
        b |=((uint32_t)(arreglo[i] & 0x1F))<<(5 * i);
    }
    printf("\nb = %X", b);
    
    return 0;
}

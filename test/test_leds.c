#include "unity.h"
#include "leds.h"

uint16_t puerto_virtual; // it is necessary for this test

// Se ejecuta antes de cada prueba
void setUp(void) {
    LedsCreate(&puerto_virtual);
}

// Se ejecuta luego de cada prueba
void tearDown(void) {
}

// 1 - Iniciar leds. Todos los leds deben iniciar apagados.
void test_todos_los_leds_inician_apagados(void) {
    uint16_t puerto_virtual =
        0xFFFF; // Necesaria a pesar de eclipsar variable global

    LedsCreate(&puerto_virtual);

    TEST_ASSERT_EQUAL_HEX16(0, puerto_virtual);
}

// 2 - Prender un led individual
void test_prender_un_led_individual(void) {

    LedsSetOn(3);

    TEST_ASSERT_EQUAL_HEX16(1 << 2, puerto_virtual);
}

// 3 - Apagar un led individual
void test_prender_y_apagar_un_led_individual(void) {

    LedsSetOn(3);
    LedsSetOff(3);

    TEST_ASSERT_EQUAL_HEX16(0, puerto_virtual);
}

// 4 - Encender y apagar varios leds a la vez
void test_prender_y_apagar_varios_leds(void) {

    LedsSetOn(7);
    LedsSetOn(5);
    LedsSetOff(2);
    LedsSetOff(7);

    TEST_ASSERT_EQUAL_HEX16(1 << 4, puerto_virtual);
}

// 5 - Apagar todos los leds a la vez
void test_apagar_todos_los_leds(void) {

    LedsSetAllOff();

    TEST_ASSERT_EQUAL_HEX16(0, puerto_virtual);
}

// 6 - Encender todos los leds a la vez
void test_prender_todos_los_leds(void) {

    LedsSetAllOn();

    TEST_ASSERT_EQUAL_HEX16(0xFFFF, puerto_virtual);
}

// 7 - Consultar por un led que está encendido
void test_consultar_por_led_encendido(void) {

    TEST_ASSERT_TRUE(LedsSetOn(5));
    TEST_ASSERT_TRUE(LedsIsOn(5));
}

// 8 - Consultar por un led que está apagado
void test_consultar_por_led_apagado(void) {

    TEST_ASSERT_FALSE(LedsIsOn(5));
}

// 9 - Creacion con puerto nulo
void test_creacion_puerto_nulo(void) {
    uint16_t * puerto_virtual_local_nulo = NULL;

    TEST_ASSERT_FALSE(LedsCreate(puerto_virtual_local_nulo));
}

// 10 - Encender leds de los bordes
void test_encendido_leds_en_los_limites(void) {

    TEST_ASSERT_TRUE(LedsSetOn(1));
    TEST_ASSERT_TRUE(LedsSetOn(16));
    TEST_ASSERT_EQUAL_HEX16((1 << 0) | (1 << 15), puerto_virtual);
}

// 11 - Encender leds fuera de los límites
void test_encendidos_leds_fuera_de_los_limites(void) {

    TEST_ASSERT_FALSE(LedsSetOn(0));
    TEST_ASSERT_FALSE(LedsSetOn(17));
    TEST_ASSERT_EQUAL_HEX16(0, puerto_virtual);
}

// 12 - Apagar leds fuera de los límites
void test_apagado_leds_fuera_de_los_limites(void) {

    TEST_ASSERT_FALSE(LedsSetOff(0));
    TEST_ASSERT_FALSE(LedsSetOff(17));
    TEST_ASSERT_EQUAL_HEX16(0, puerto_virtual);
}

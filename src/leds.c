#include "leds.h"
#include <stddef.h>

/**
 * @brief Máscara del bit menos significativo para los LEDs.
 */
#define LEDS_LSB 0x0001

/**
 * @brief Número del primer LED.
 */
#define LEDS_FIRST_LED 1

/**
 * @brief Número del último LED.
 */
#define LEDS_LAST_LED 16

/**
 * @brief Desplazamiento para la posición de los LEDs.
 */
#define LEDS_OFFSET 1

/**
 * @brief Máscara para apagar todos los LEDs.
 */
#define LEDS_ALL_OFF 0x0000

/**
 * @brief Máscara para encender todos los LEDs.
 */
#define LEDS_ALL_ON 0xFFFF

/**
 * @brief Puntero al puerto donde están conectados los LEDs.
 *
 * Esta variable almacena la dirección del puerto de los LEDs, permitiendo el
 * control de los mismos mediante las funciones correspondientes.
 */
static uint16_t * puerto;

/**
 * @brief Verifica si el LED especificado está dentro de los límites permitidos.
 *
 * @param led Índice del LED a verificar.
 * @return true si el LED está dentro de los límites, false en caso contrario.
 */
static bool LedIsInsideLimits(int led);

/**
 * @brief Convierte el índice de un LED a una máscara correspondiente.
 *
 * @param led Índice del LED a convertir.
 * @return Máscara de bits correspondiente al LED.
 */
uint16_t LedToMask(int led);

static bool LedIsInsideLimits(int led) {

    return ((LEDS_LAST_LED >= led) && (LEDS_FIRST_LED <= led));
}

uint16_t LedToMask(int led) {
    return (LEDS_LSB << (led - LEDS_OFFSET));
}

bool LedsCreate(uint16_t * direccion) {

    if (NULL == direccion) {
        return false;
    }

    puerto = direccion;
    LedsSetAllOff();

    return true;
}

bool LedsSetOn(int led) {

    if (!LedIsInsideLimits(led)) {
        return false;
    }

    *puerto |= LedToMask(led);

    return true;
}

bool LedsSetOff(int led) {

    if (!LedIsInsideLimits(led)) {
        return false;
    }

    *puerto &= ~LedToMask(led);

    return true;
}

void LedsSetAllOn(void) {
    *puerto = LEDS_ALL_ON;
}

void LedsSetAllOff(void) {
    *puerto = LEDS_ALL_OFF;
}

bool LedsIsOn(int led) {
    return (LedToMask(led) == (*puerto & LedToMask(led)));
}

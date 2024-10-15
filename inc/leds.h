/**
 * @file leds.h
 * @author Iván Podoroska
 * @brief Archivo de encabezado para el control de LEDs en un puerto.
 *
 * Este archivo proporciona funciones para controlar los LEDs conectados a un
 * puerto específico. Incluye funciones para inicializar el puerto, encender y
 * apagar LEDs individuales o todos los LEDs al mismo tiempo, además de
 * verificar el estado de los LEDs.
 */

#ifndef LEDS_H
#define LEDS_H

#include <stdint.h>
#include "stdbool.h"

/**
 * @brief Inicializa el puerto de LEDs y apaga todos los LEDs.
 *
 * Esta función configura el puerto utilizado para controlar los LEDs,
 * asegurándose de que todos los LEDs estén apagados inicialmente.
 *
 * @param puerto Puntero al puerto donde están conectados los LEDs.
 * @return true si la inicialización fue exitosa, false en caso contrario.
 */
bool LedsCreate(uint16_t * puerto);

/**
 * @brief Enciende el LED especificado.
 *
 * Enciende un LED en particular identificado por su número de índice.
 *
 * @param led Índice del LED a encender (número del LED).
 * @return true si el LED se encendió correctamente, false en caso contrario.
 */
bool LedsSetOn(int led);

/**
 * @brief Apaga el LED especificado.
 *
 * Apaga un LED en particular identificado por su número de índice.
 *
 * @param led Índice del LED a apagar (número del LED).
 * @return true si el LED se apagó correctamente, false en caso contrario.
 */
bool LedsSetOff(int led);

/**
 * @brief Enciende todos los LEDs conectados al puerto.
 *
 * Esta función enciende todos los LEDs al mismo tiempo.
 */
void LedsSetAllOn(void);

/**
 * @brief Apaga todos los LEDs conectados al puerto.
 *
 * Esta función apaga todos los LEDs al mismo tiempo.
 */
void LedsSetAllOff(void);

/**
 * @brief Verifica si un LED está encendido.
 *
 * Comprueba si un LED específico, identificado por su índice, está actualmente
 * encendido.
 *
 * @param led Índice del LED a verificar.
 * @return true si el LED está encendido, false en caso contrario.
 */
bool LedsIsOn(int led);

#endif // LEDS_H

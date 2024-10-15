# Testing de Software en Sistemas Embebidos - Trabajo Práctico Número 4

Proyecto basado en el TP2 de la materia donde se desarrollo un test para una biblioteca de un controlador de leds.

## Objetivo

Este repositorio implementa un flujo de trabajo de **Integración Continua (CI)** utilizando **GitHub Actions**. Se han configurado **pre-commits** para asegurar que el código siga un formato consistente y que, antes de cada commit, se ejecuten automáticamente los tests con Ceedling. De esta manera, se garantiza la integridad del código y se automatiza el proceso de pruebas, mejorando la calidad y eficiencia del desarrollo.

## Uso del repositorio

Este repositorio utiliza [pre-commit](https://pre-commit.com) para validaciones de formato y [Ceedling](http://www.throwtheswitch.org/ceedling) como framework de pruebas. Para trabajar con este repositorio, debes tener instalado lo siguiente:

1. pre-commit (<https://pre-commit.com/#install>)
2. Ceedling (<http://www.throwtheswitch.org/ceedling>)

Después de clonar el repositorio, debes ejecutar el siguiente comando para habilitar los **pre-commits**:

```
pre-commit install
```

- Para generar la **documentación** del proyecto, ejecuta:

```
make doc

```

- Para **compilar** el proyecto, usa:

```
make all

```

- Para ejecutar las pruebas unitarias utilizando **Ceedling**, ejecuta:

```
ceedling test:all
```

## Autor

Ing. Iván Podoroska

## License

Esta obra se distribuye bajo los términos de la [licencia MIT](https://spdx.org/licenses/MIT.html).

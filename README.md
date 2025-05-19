[![Estado de la compilación](https://travis-ci.org/bodastage/bts-ce-lite.svg?branch=master)](https://travis-ci.org/bodastage/bts-ce-lite) ![Versión de GitHub](https://img.shields.io/github/release/bodastage/bts-ce-lite.svg) ![Todas las versiones de GitHub](https://img.shields.io/github/downloads/bodastage/bts-ce-lite/total.svg) [![Licencia de GitHub](https://img.shields.io/github/license/bodastage/bts-ce-lite.svg)](https://github.com/bodastage/bts-ce-lite/blob/master/LICENSE) [![GitHub Problemas](https://img.shields.io/github/issues/bodastage/bts-ce-lite.svg)](https://github.com/bodastage/bts-ce-lite/issues)

# Boda-Lite

Boda-Lite es una versión con funcionalidades limitadas de [bts-ce](https://github.com/bodastage/bts-ce). Es una aplicación de escritorio multiplataforma para la gestión de telecomunicaciones.

## Características
* Análisis y carga de volcados de gestión de configuración de telecomunicaciones (CM) para diversos proveedores (Ericsson, Huawei, Nokia, ZTE)
* Análisis y carga de volcados de red de gestión del rendimiento de las telecomunicaciones (PM)
* Módulo de informes que admite informes tabulares, gráficos y compuestos (similares a un panel de control)
* Módulo GIS avanzado
* Auditoría de línea base de red
* Utilidades: Conversión de CSV a Excel, generador KML

## Desarrollado con
* [Electron](https://electronjs.org)
* [ReactJs](https://reactjs.org/)
* [SQLite3](https://www.sqlite.org/index.html)

## Capturas de pantalla
![BTS-CE-Lite Dashboard and Reports](/dashboard_and_reports.png?raw=true "Dashboard and Reports")

![BTS-CE-Lite SIG](/gis.jpeg?raw=true "GIS")

## Ejecutando modo de desarrollo
``` bash
export SKIP_PREFLIGHT_CHECK=true
yarn run start

#
yarn run electron-dev-unix
```

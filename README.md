# Optimización de Control de Pitch para Turbina Eólica de 1.5 MW

Este repositorio contiene los modelos y scripts desarrollados para el Trabajo Fin de Máster (TFM) enfocado en la **optimización del controlador de ángulo de pala (Pitch)** de una turbina eólica mediante algoritmos evolutivos (**Differential Evolution**).

## 🎯 Objetivo del Proyecto

El objetivo principal fue minimizar el *overshoot* de potencia y las cargas mecánicas en una turbina eólica comercial (basada en el modelo Simscape de MATLAB) ante ráfagas de viento extremas. Se partió de un controlador PI base mal sintonizado para encontrar la configuración óptima que acercara el desempeño al límite físico del sistema.

## 🛠️ Tecnologías Utilizadas

*   **MATLAB / Simulink / Simscape** (R2025b)
*   **Differential Evolution (DE)**: Algoritmo de optimización global.
*   **Control PID & Feed-Forward**: Arquitectura de control híbrida.

## 🚀 Historia del Proyecto: Del Problema a la Solución

### 1. El Problema Inicial
El modelo original presentaba un comportamiento subóptimo con un **overshoot de potencia del 106.08%** ante una ráfaga de prueba.
*   **Diagnóstico**: Se descubrió que el controlador PI original no tenía efecto alguno sobre la salida.
*   **Causa Raíz**: Un bloque de `Saturation` interno tenía un límite inferior de `0`, lo que impedía al controlador corregir errores negativos (exceso de potencia). Además, el control *Feed-Forward* (basado en tabla de viento) dominaba la acción al 100%.

### 2. Modificaciones al Modelo
Para habilitar la optimización, se realizaron correcciones estructurales:
*   🔓 **Desbloqueo de Saturación**: Se modificó el límite inferior a `-inf` para permitir acción correctiva total.
*   ⚖️ **Rebalanceo de Control**: Se redujo la ganancia del *Feed-Forward* para dar autoridad al algoritmo de optimización sobre el PI.
*   ⚙️ **Parametrización**: Se sustituyeron las ganancias fijas por variables (`Kp_pitch`, `Ki_pitch`) inyectables desde MATLAB.

### 3. Proceso de Optimización
Se implementó el algoritmo **Differential Evolution (DE)** con una función de coste basada en ITAE (Integral del Error Absoluto ponderado por Tiempo) y penalización por barrera dura para overshoots > 1.05 pu.

*   **Población**: 20 individuos.
*   **Iteraciones**: 15 (convergencia rápida observada).
*   **Resultado**: El algoritmo convergió hacia un control Proporcional alto ($K_p \approx 1.5$) e Integral bajo ($K_i \approx 0.2$).

### 4. Resultados Clave 📊

El análisis final reveló un hallazgo científico interesante sobre la arquitectura de control:

| Escenario | Overshoot (%) | Análisis |
| :--- | :--- | :--- |
| **Límite Físico (Solo Feed-Forward)** | **103.46%** | El control predictivo puro es el óptimo teórico del sistema. |
| **Control Original (PI Malo)** | 106.08% | El PI mal sintonizado **degradaba** la respuesta (+2.62%). |
| **Control Optimizado (IA)** | **104.05%** | La optimización **redujo la degradación en un 77%**, dejando el PI "transparente" y eficiente. |

**Conclusión**: La optimización no solo sintonizó el controlador, sino que demostró que el límite de desempeño para esta turbina lo dicta el actuador y la predicción (Feed-Forward), logrando una configuración que roza el óptimo físico.

## 📂 Estructura de Archivos

Este repositorio se ha limpiado para incluir solo los archivos esenciales para reproducir los resultados:

*   `lanzador_optimizacion.m`: Script principal. Configura y ejecuta el algoritmo Differential Evolution. Incluye modo acelerado.
*   `coste_turbina.m`: Función objetivo que evalúa cada individuo simulando el modelo Simulink.
*   `generar_graficas.m`: Script de post-procesamiento. Ejecuta las simulaciones finales y genera las Figuras 6, 7 y 8 para la memoria académica.
*   `devec3.m`: Implementación del algoritmo Differential Evolution.
*   `sscv_wind_turbine.slx`: Modelo Simulink de la turbina (modificado).

##  ▶️ Cómo Ejecutar

1.  **Para Optimizar**: Ejecuta `lanzador_optimizacion` en MATLAB.
2.  **Para Ver Resultados**: Ejecuta `generar_graficas`. Generará las tablas de datos y las figuras comparativas listas para publicación.

---
*Trabajo de Máster Robótica y Automática (UC3M), asignatura Control Inteligente*

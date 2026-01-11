%% LANZADOR DE OPTIMIZACIÓN (Consolidado)
% Este script configura y ejecuta la optimización con Differential Evolution.
% Configuración optimizada para balance entre velocidad y precisión.

clear; clc;

% 1. Configuración del Algoritmo DE
VTR = 0.01;         % Valor objetivo (Value To Reach)
D = 2;              % Dimensión (Kp, Ki)
XVmin = [0.1 0.1];  % Límite inferior [Kp Ki]
XVmax = [10 5];     % Límite superior [Kp Ki]
y = [];             % Sin estado inicial
NP = 20;            % Población (reducido de 50 para velocidad)
itermax = 15;       % Iteraciones máximas
F = 0.7;            % Factor de mutación
CR = 0.5;           % Probabilidad de cruce
strategy = 2;       % DE/best/1/exp
refresh = 1;        % Mostrar progreso cada iteración

% 2. Configuración de Simulación
% Pre-cargar modelo para acelerar
load_system('sscv_wind_turbine');
sscv_wind_turbine_input;
set_param('sscv_wind_turbine', 'SimulationMode', 'accelerator'); % MODO ACELERADO

fprintf('Iniciando Optimización de PID Pitch...\n');
fprintf('Población: %d, Iteraciones: %d\n', NP, itermax);
fprintf('Modo Simulación: Accelerator\n\n');

% 3. Ejecutar Optimización
tic;
[bestmem, bestval, bestF] = devec3('coste_turbina', VTR, D, XVmin, XVmax, y, NP, itermax, F, CR, strategy, refresh);
tiempo_total = toc;

% 4. Mostrar Resultados
fprintf('\n========================================\n');
fprintf('OPTIMIZACIÓN COMPLETADA\n');
fprintf('Tiempo total: %.1f minutos\n', tiempo_total/60);
fprintf('========================================\n');
fprintf('Mejor valor de coste: %.4f\n', bestval);
fprintf('Parámetros Óptimos:\n');
fprintf('Kp = %.4f\n', bestmem(1));
fprintf('Ki = %.4f\n', bestmem(2));

% 5. Validación Final (Simulación con mejores parámetros)
fprintf('\nEjecutando validación final...\n');
assignin('base', 'Kp_pitch', bestmem(1));
assignin('base', 'Ki_pitch', bestmem(2));
sim('sscv_wind_turbine');
sscv_wind_turbine_plotResponse;
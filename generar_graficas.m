%% GENERACIÓN DE GRÁFICAS
% Este script genera las figuras profesionales para la memoria.
% Escenarios:
%   1. Límite Físico (Solo Feed-Forward, Kp=0)
%   2. Original (Base, Kp=0.1)
%   3. Optimizado (Propuesto, Kp=1.5)

clear all; clc; close all;

fprintf('========================================\n');
fprintf('GENERANDO GRÁFICAS\n');
fprintf('========================================\n\n');

%% 1. CONFIGURACIÓN DEL MODELO
sscv_wind_turbine_input;
windProfile = 2; % Perfil de ráfaga
simT = 150;      % Tiempo suficiente para ver el transitorio

% Cargar modelo
load_system('sscv_wind_turbine');

% Rutas de bloques
ruta_Kp = 'sscv_wind_turbine/Pitch Controller/Turbine State 2 : Power Generation Condition/Turbine State 2/Gain';
ruta_Ki = 'sscv_wind_turbine/Pitch Controller/Turbine State 2 : Power Generation Condition/Turbine State 2/Gain1';
ruta_FF = 'sscv_wind_turbine/Pitch Controller/Turbine State 2 : Power Generation Condition/Turbine State 2/FF_Reduction ';
ruta_Sat = 'sscv_wind_turbine/Pitch Controller/Turbine State 2 : Power Generation Condition/Turbine State 2/Saturation';

% ASEGURAR CONDICIONES DE LA SOLUCIÓN
% 1. Feed-Forward al 10%
try
    set_param(ruta_FF, 'Gain', '0.1');
catch
    % Intentar sin espacio si falla
    try set_param(strtrim(ruta_FF), 'Gain', '0.1'); catch end
end

% 2. Saturación desbloqueada
set_param(ruta_Sat, 'LowerLimit', '-inf');

% Configuración de simulación
set_param('sscv_wind_turbine', 'SimulationMode', 'accelerator');

%% 2. EJECUCIÓN DE SIMULACIONES

% --- ESCENARIO A: LÍMITE FÍSICO (SOLO FF) ---
fprintf('Simulando Escenario A (Solo FF)...\n');
set_param(ruta_Kp, 'Gain', '0');
set_param(ruta_Ki, 'Gain', '0');
out_A = sim('sscv_wind_turbine');
logs_A = out_A.logsout;

% --- ESCENARIO B: ORIGINAL (BASELINE) ---
fprintf('Simulando Escenario B (Original)...\n');
set_param(ruta_Kp, 'Gain', '0.1');
set_param(ruta_Ki, 'Gain', '1.0');
out_B = sim('sscv_wind_turbine');
logs_B = out_B.logsout;

% --- ESCENARIO C: OPTIMIZADO (PROPUESTO) ---
fprintf('Simulando Escenario C (Optimizado)...\n');
set_param(ruta_Kp, 'Gain', '1.4983');
set_param(ruta_Ki, 'Gain', '0.1959');
out_C = sim('sscv_wind_turbine');
logs_C = out_C.logsout;

% Restaurar modelo
set_param(ruta_Kp, 'Gain', 'Kp_pitch');
set_param(ruta_Ki, 'Gain', 'Ki_pitch');
set_param('sscv_wind_turbine', 'SimulationMode', 'normal');

%% 3. PROCESAMIENTO DE DATOS
% Extraer señal de potencia
sig_A = logs_A.get('Generator Power (MW)').Values;
sig_B = logs_B.get('Generator Power (MW)').Values;
sig_C = logs_C.get('Generator Power (MW)').Values;

% Extraer señal de Pitch (para gráfica de control)
pitch_B = logs_B.get('Pitch Angle (deg)').Values;
pitch_C = logs_C.get('Pitch Angle (deg)').Values;

% Zona de Zoom (Pico)
t_zoom_min = 115;
t_zoom_max = 135;

%% 4. GENERACIÓN DE FIGURAS

% DEFINICIÓN DE ESTILOS (Ajustados para visibilidad cuando hay superposición)
lineWidthFF = 1.0;
lineWidthOrig = 4.0; % Muy gruesa para que se vea "detrás"
lineWidthOpt = 1.5;  % Más fina para ver detalle encima

colorFF = [0.6 0.6 0.6];    % Gris claro
colorOrig = [0.85 0.33 0.1]; % Naranja/Rojo (Original)
colorOpt = [0 0.45 0.74];    % Azul profesional (Optimizado)

estiloFF = '--';
estiloOrig = '-';  % Sólida gruesa de fondo
estiloOpt = '-';   % Sólida fina encima

% --- CÁLCULO DE DATOS PARA TABLA ---
% Estos son los valores que pones en la memoria
ref_nominal = 1.0;
max_A = max(sig_A.Data);
max_B = max(sig_B.Data);
max_C = max(sig_C.Data);

overshoot_A = (max_A - ref_nominal) * 100;
overshoot_B = (max_B - ref_nominal) * 100;
overshoot_C = (max_C - ref_nominal) * 100;

degradacion_B = overshoot_B - overshoot_A;
degradacion_C = overshoot_C - overshoot_A;

% MOSTRAR TABLA EN CONSOLA
fprintf('\n================================================================\n');
fprintf('TABLA 3.3: DATOS GENERADOS (Copiar a Memoria)\n');
fprintf('================================================================\n');
fprintf('| Escenario           | Pico (pu) | Overshoot | Degradación |\n');
fprintf('|---------------------|-----------|-----------|-------------|\n');
fprintf('| Límite Teórico (FF) | %.4f    | %.2f%%     | --          |\n', max_A, overshoot_A);
fprintf('| Original (PI+FF)    | %.4f    | %.2f%%     | +%.2f%%      |\n', max_B, overshoot_B, degradacion_B);
fprintf('| Optimizado (PI+FF)  | %.4f    | %.2f%%     | +%.2f%%      |\n', max_C, overshoot_C, degradacion_C);
fprintf('================================================================\n\n');


% --- FIGURA 6: COMPARATIVA GLOBAL ---
f1 = figure('Name', 'Figura 6: Respuesta Global', 'Color', 'w', 'Position', [100, 100, 800, 500]);
plot(sig_A.Time, sig_A.Data, 'Color', colorFF, 'LineWidth', lineWidthFF, 'LineStyle', estiloFF); hold on;
% Orden importa: Primero la gruesa (Original), luego la fina (Optimizado)
plot(sig_B.Time, sig_B.Data, 'Color', colorOrig, 'LineWidth', lineWidthOrig, 'LineStyle', estiloOrig);
plot(sig_C.Time, sig_C.Data, 'Color', colorOpt, 'LineWidth', lineWidthOpt, 'LineStyle', estiloOpt);
yline(1.0, 'k:', 'LineWidth', 1); % Referencia

grid on;
legend('Límite Físico (Solo FF)', 'Control Original', 'Control Optimizado', 'Referencia Nominal', 'Location', 'Best');
xlabel('Tiempo (s)', 'FontSize', 12, 'FontWeight', 'bold');
ylabel('Potencia Generada (pu)', 'FontSize', 12, 'FontWeight', 'bold');
title('Comparativa de Respuesta Transitoria ante Ráfaga', 'FontSize', 14);
xlim([0 simT]);
ylim([0 2.2]);

% --- FIGURA 7: ZOOM AL OVERSHOOT (DETALLE) ---
f2 = figure('Name', 'Figura 7: Detalle Overshoot', 'Color', 'w', 'Position', [150, 150, 800, 500]);
plot(sig_A.Time, sig_A.Data, 'Color', colorFF, 'LineWidth', lineWidthFF, 'LineStyle', estiloFF); hold on;
plot(sig_B.Time, sig_B.Data, 'Color', colorOrig, 'LineWidth', lineWidthOrig, 'LineStyle', estiloOrig);
plot(sig_C.Time, sig_C.Data, 'Color', colorOpt, 'LineWidth', lineWidthOpt, 'LineStyle', estiloOpt);
yline(1.0, 'k:', 'LineWidth', 1);

grid on;
% Añadir anotaciones de pico
[~, idx_B] = max(sig_B.Data);
[~, idx_C] = max(sig_C.Data);
% Ajustar posición texto para que no se solapen
text(sig_B.Time(idx_B), max_B+0.05, sprintf('  Original: %.3f pu (+%.2f%%)', max_B, degradacion_B), 'Color', colorOrig, 'FontSize', 10, 'FontWeight', 'bold');
text(sig_C.Time(idx_C)+2, max_C, sprintf('  Optimizado: %.3f pu (+%.2f%%)', max_C, degradacion_C), 'Color', colorOpt, 'FontSize', 10, 'FontWeight', 'bold');

legend('Límite Físico (Solo FF)', 'Control Original', 'Control Optimizado', 'Location', 'NorthEast');
xlabel('Tiempo (s)', 'FontSize', 12, 'FontWeight', 'bold');
ylabel('Potencia Generada (pu)', 'FontSize', 12, 'FontWeight', 'bold');
title('Detalle de la Reducción del Pico de Potencia', 'FontSize', 14);
xlim([t_zoom_min t_zoom_max]);
ylim([0.8 2.2]);

% --- FIGURA 8: ESFUERZO DE CONTROL (PITCH) ---
f3 = figure('Name', 'Figura 8: Acción de Control', 'Color', 'w', 'Position', [200, 200, 800, 500]);
plot(pitch_B.Time, pitch_B.Data, 'Color', colorOrig, 'LineWidth', lineWidthOrig, 'LineStyle', estiloOrig); hold on;
plot(pitch_C.Time, pitch_C.Data, 'Color', colorOpt, 'LineWidth', lineWidthOpt, 'LineStyle', estiloOpt);

grid on;
legend('Control Original', 'Control Optimizado', 'Location', 'SouthEast');
xlabel('Tiempo (s)', 'FontSize', 12, 'FontWeight', 'bold');
ylabel('Ángulo de Pitch (deg)', 'FontSize', 12, 'FontWeight', 'bold');
title('Comparativa de la Acción de Control (Ángulo de Pala)', 'FontSize', 14);
xlim([110 140]); % Zoom en la zona de acción

fprintf('Gráficas generadas exitosamente.\n');
fprintf('Puedes guardarlas desde las ventanas de figura.\n');

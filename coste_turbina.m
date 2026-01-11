function [cost] = coste_turbina(x)
% COSTE_TURBINA Función de coste para optimización de turbina eólica
% Entradas:
%   x(1): Kp_pitch
%   x(2): Ki_pitch

    % 1. Asignar variables al workspace base
    Kp_val = x(1);
    Ki_val = x(2);
    assignin('base', 'Kp_pitch', Kp_val);
    assignin('base', 'Ki_pitch', Ki_val);

    % 2. Configuración de simulación
    % Usamos un tiempo reducido suficiente para ver el pico (transitorio)
    % Esto acelera drásticamente la optimización
    t_sim = 150; 
    
    try
        % 3. Ejecutar simulación
        % Usamos evalc para silenciar la salida de consola de simulink
        [~, out] = evalc('sim(''sscv_wind_turbine'', ''StopTime'', num2str(t_sim))');
        
        % 4. Extraer datos
        % Asumiendo que tenemos logsout o un Outport 1 con la potencia
        if isfield(out, 'logsout')
            potencia_mw = out.logsout.get('Generator Power (MW)').Values.Data;
            tiempo = out.logsout.get('Generator Power (MW)').Values.Time;
        else
            % Fallback si no hay logsout
            potencia_mw = out.yout{1}.Values.Data;
            tiempo = out.yout{1}.Values.Time;
        end
        
        % 5. Calcular Coste (ITAE + Penalización Overshoot)
        ref = 1.0; % Referencia 1 pu
        error = abs(ref - potencia_mw);
        
        % ITAE (Integral del Tiempo por Error Absoluto)
        % Penaliza errores que persisten en el tiempo
        itae = sum(tiempo .* error) * (tiempo(2)-tiempo(1)); 
        
        % Penalización por Overshoot (Barrera dura)
        max_potencia = max(potencia_mw);
        penalizacion_overshoot = 0;
        if max_potencia > 1.05 % Si supera 1.05 pu
            penalizacion_overshoot = (max_potencia - 1.05) * 10000; % Penalización muy fuerte
        end
        
        cost = itae + penalizacion_overshoot;
        
    catch
        % Si la simulación falla (inestabilidad), devolver coste altísimo
        cost = 1e6;
    end

end
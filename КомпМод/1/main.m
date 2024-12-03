% Определение системы дифференциальных уравнений
function dydx = ode_system(x, y)
    dydx = zeros(2, length(x));
    dydx(1, :) = y(2, :);
    dydx(2, :) = (3/4) * y(1, :) ./ x - (1/2) * (x.^(-1/2)) .* y(2, :);
end

% Определение краевых условий
function res = bc(ya, yb)
    res = [ya(1) - 2; yb(1) - 4.5];
end

% Начальная сетка и предположение для y и y'
x = linspace(1, 4, 100);
y_guess = zeros(2, length(x));
y_guess(1, :) = 2 + (4.5 - 2) * (x - 1) / (4 - 1);  % Линейное предположение между граничными значениями

% Решение задачи краевых значений
sol = bvpinit(x, y_guess);
sol = bvp4c(@ode_system, @bc, sol);

% Проверка успешности решения
if sol.status == 0
    disp('Решение найдено успешно.');
else
    disp('Решение не удалось.');
end

% Построение результата
plot(sol.x, sol.y(1, :), 'DisplayName', 'y(x)');
xlabel('x');
ylabel('y(x)');
title('Решение задачи краевых значений');
legend;
grid on;

% Определяем переменную x и функцию y(x)
syms x y(x)

% Находим производную y по x
y_prime = diff(y, x);

% Определение функционала
L = sqrt(x) * y_prime^2 + (y^2) / (2 * x * sqrt(x));

% Применение уравнения Эйлера-Лагранжа
% Находим частные производные лагранжиана по y и y'
dL_dy_prime = diff(L, y_prime);
dL_dy = diff(L, y);

% Производная по x от dL/dy'
d_dx_dL_dy_prime = diff(dL_dy_prime, x);

% Уравнение Эйлера-Лагранжа
euler_lagrange_eq = d_dx_dL_dy_prime - dL_dy == 0;

% Решаем уравнение Эйлера-Лагранжа относительно y(x)
solution = dsolve(euler_lagrange_eq, y);
disp(solution);

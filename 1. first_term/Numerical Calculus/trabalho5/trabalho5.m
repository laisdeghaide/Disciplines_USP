display("miniprojeto 5")

% txt com as direções dos 210 sensores
G = load("pp_2021_dire.txt");

% txt com as mediçoes obtidas, contendo ruído
Y = load("p67_2021_y.txt");


% a) Primeira estimação de ˜X

% temos a relação linear dada por: Y = G*X + ruído
% vetor 1071 x 3
X = G\Y';
X = X';

hold on
scatter3(X(:, 1), X(:, 2), X(:, 3), "r", "filled")
x = X(:, 1);
y = X(:, 2);
z = X(:, 3);

% cálculo dos máximos e mínimos quadrados
display("Máximos e mínimos de x, y, z: ")
minx = min(x)
maxx = max(x)
display("\n")

miny = min(y)
maxy = max(y)
display("\n")

minz = min(z)
maxz = max(z)
display("\n")


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% b) Ajuste do plano por mínimos quadrados
% Temos que o ajuste pode ser dado da seguinte forma: Ak = b

% realizando 3 ajustes de planos com os mesmos dados x,y,z e dois vetores k1 e k2

% primeiro ajuste: z = k1*x + k2*y
A_z = [x y];
k_z = A_z\z;
n_z = [k_z(1), k_z(2), -1];
norma_z = n_z / sqrt(n_z(1)^2 + n_z(2)^2 + n_z(3)^2);

% calculo do resíduo do plano ajustado
residuo_z = A_z * k_z - z;
erro_resz = vecnorm(residuo_z)


% segundo ajuste: x = k1*y + k2*z
A_x = [y z];
k_x = A_x\x;
n_x = [-1, k_x(1), k_x(2)];
norma_x = n_x / sqrt(n_x(1)^2 + n_x(2)^2 + n_x(3)^2);


% calculo do resíduo do plano ajustado
residuo_x = A_x * k_x - x;
erro_resx = vecnorm(residuo_x)


% terceiro ajuste: y = k1*z + k2*x
A_y = [z x];
k_y = A_y\y;
n_y = [k_y(1), -1, k_y(2)];
norma_y = n_y / sqrt(n_y(1)^2 + n_y(2)^2 + n_y(3)^2);

% calculo do resíduo do plano ajustado
residuo_y = A_y * k_y - y;
erro_resy = vecnorm(residuo_y)


% encontrando o resíduo mínimo
min_res = min([erro_resx erro_resy erro_resz]);

% plotando os planos
if(0)

[xx, yy] = meshgrid(-1:1, -1:1);
zz = (-n_z(1)*xx - n_z(2)*yy) / n_z(3);
surf(xx, yy, zz)

endif


if(0)

[yy, zz] = meshgrid(-1:1, -1:1);
xx = (-n_x(1)*xx - n_x(2)*yy) / n_x(3);
surf(xx, yy, zz)

endif


if(0)

[zz, xx] = meshgrid(-1:1, -1:1);
yy = (-n_y(1)*zz - n_y(2)*xx) / n_y(3);
surf(xx, yy, zz)

endif

display("\nA menor norma é: ");
display(min_res);



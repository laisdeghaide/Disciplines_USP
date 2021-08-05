display("Miniprojeto 6")

%%%%%%%%%%%%%%%%%%%%%%%%% PARTE A %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

global H c area Cd g massa_inicial massa_foguete rho_inicial tempo_queima
H = 8000;                   % Altura
c = 3000;                  % Velocidade de expulsão do combustível  
area = 1;                   % Area do foguete
Cd = 0.2;                   % Coeficiente de arrasto
g = 9.8;                    % Gravidade
massa_inicial = 1000;        % Massa do combustível
massa_foguete = 100;        % Massa do foguete
rho_inicial = 1.2;          % Densidade inical   
tempo_queima = 220 - (20 * 7);  % Tempo de queima do combustível do foguete


% Função que define a aceleracao do foguete
function A = funcaoFoguete(q, t)
  global H c area Cd g massa_inicial massa_foguete rho_inicial tempo_queima

  z = q(1);
  v = q(2);
  A(1) = v;
  
  if t <= tempo_queima
    m = massa_foguete + (massa_inicial * (1 - t/tempo_queima));
    A(2) = ((c * massa_inicial/tempo_queima) - (m * g) - (0.5 * (rho_inicial * exp(-z/H)) * Cd * area * abs(v) * v)) / m;
  else
    m = massa_foguete;
    A(2) = (- (m * g) - (0.5 * (rho_inicial * exp(-z/H)) * Cd * area * abs(v) * v)) / m;
 endif  
endfunction

T = [1:0.02:2000];
[X, ISTATE, MSG] = lsode("funcaoFoguete",[0 0], T);

% Encontrando a aceleracao
aceleracao = diff(X(:,2)) / 0.02;
Taceleracao = [1:0.02:1999.98];

% Plot do gráfico de posicao
if(0)
  plot(T, X(:,1), "linewidth", 1, "k")
  set(gca, "fontsize", 18)
  title("Altura x Tempo");
  xlabel("tempo");
  ylabel("altura");
endif

% Plot do gráfico de velocidade
if(0)
  plot(T, X(:, 2), "linewidth", 1,  "k")
  set(gca, "fontsize", 18)
  title("Velocidade x Tempo");
  xlabel("tempo");
  ylabel("velocidade");
endif

% Plot do gráfico de aceleracao
if(0)
  plot(Taceleracao, aceleracao, "linewidth", 1)
  set(gca, "fontsize", 18)
  title("Aceleração x Tempo");
  xlabel("tempo");
  ylabel("aceleração");
endif

display(""); % Pula linha


%%%%%%%%%%%%%%%%%%%%%%% PARTE B %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Qual a altura maxima que o foguete alcança?
display("1. Qual a altura maxima que o foguete alcança?")
altura_max = max(X(:,1))
display("");


% Qual e a máxima aceleração e a que altura acontece?
display("2. Qual é a máxima aceleração e a que altura acontece?")
[max_aceleracao, posicao_aceleracao] = max(aceleracao) %max_aceleracao = maxima aceleracao, posicao_aceleracao = posicao em que a max_aceleracao ocorre
display("");


% Quanto demora até o foguete voltar ao chão? 
display("3. Quanto demora até o foguete voltar ao chão? ");
posicao_voo = sum(X(:,1) >= 0)
tempo_voo = posicao_voo * 0.02
display("");


% São importantes os efeitos do arrasto? Qual seria a altura máxima se o Cd = 0.1?
display("4. São importantes os efeitos do arrasto? Qual seria a altura máxima se o Cd = 0.1?");
display("Sim, são importantes os efeitos do arrasto, pois é essa força que desacelera o foguete e o equilibra até chegar ao chão, ");
display("impedindo que o foguete colida drasticamente com o solo.");
display("")
display("Se modificarmos o Cd para 0.1, chamarmos a funcao lsode e depois calcularmos a altura maxima com max(X(:,1)), ");
display("encontraremos a nova altura máxima que é: 1.9515e+06.");
display("");


% Qual é o custo (em massa de combustível) de um kg adicional de carga? 
% Em outras palavras, quanto mais combustível deveriamos adicionar para que o foguete chegue até
% a mesma altura sendo que a carga é de 101 kg e não de 100 kg? 
display("5. Qual é o custo (em massa de combustível) de um kg adicional de carga?");
display("Será necessário colocar 7.65 kg a mais de combustível para atingir a mesma altura máxima de quando o foguete tinha 100kg.")
display("");

%%%%%%%%%%%%%%%%%%%%%%% PARTE C %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Método de Euler Explícito
dt = 0.02;
TT = [0:dt:2000];
y(1,:) = [0 0];
for nt = 1:(2000/dt)
 y(nt+1,:) = y(nt,:) + dt * funcaoFoguete(y(nt,:), TT(nt));
endfor


% Plot do gráfico de altura
if(0)
  plot(TT, y(:, 1), "linewidth", 1, "--")
  set(gca, "fontsize", 18)
  title("Altura x Tempo (Euler Explicito)");
  xlabel("tempo");
  ylabel("altura");
endif

% Plot do gráfico de velocidade
if(0)
  plot(TT, y(:, 2), "linewidth", 1, "--")
  set(gca, "fontsize", 18)
  title("Velocidade x Tempo (Euler Explicito)");
  xlabel("tempo");
  ylabel("velocidade");
endif


% Método RK2
function [y time] = rk2(f,y0,t0,dt,nt)
time(1) = t0;
y0 = y0';
y(:,1) = y0;
nstage = 2;
a = [0 0;1 0];
c = [0; 1];
b = [0.5 0.5];
for n = 1:nt
 K(:,1) = feval(f,y(:,n),time(n));
 for m = 2:nstage
  tt = time(n)+c(m)*dt;
  yy = y(:,n)+dt*K(:,1:m-1)*a(m,1:m-1)';
  K(:,m) = feval(f,yy,tt);
 endfor
 y(:,n+1) = y(:,n) + dt * K(:,1:nstage) * b';
 time(n+1) = time(n) + dt;
endfor
y = (y(:,1:nt+1))';
end

dt2 = 0.02;
[yrk2 timerk2] = rk2("funcaoFoguete", [0 0], 0, dt2, 2000/dt2);

% Gráfico de altura
if(0)
  plot(timerk2, yrk2(:,1), "linewidth", 1, "linestyle", "--")
  set(gca, "fontsize", 18)
  title("Altura x Tempo (RK2)");
  xlabel("tempo");
  ylabel("altura");
endif

% Gráfico de velocidade
if(0)
  plot(timerk2, yrk2(:,2), "linewidth", 1, "linestyle", "--")
  set(gca, "fontsize", 18)
  title("Velocidade x Tempo (RK2)");
  xlabel("tempo");
  ylabel("altura");
endif


% Método RK4
function [y time] = rk4(f,y0,t0,dt,nt)
time(1) = t0;
y0 = y0';
y(:,1) = y0;
nstage = 4;
a = [0 0 0 0;0.5 0 0 0;0 0.5 0 0;0 0 1 0];
c = [0; 0.5; 0.5; 1];
b = [1/6 2/6 2/6 1/6];
for n = 1:nt
 K(:,1) = feval(f, y(:,n), time(n));
 for m = 2:nstage
  tt = time(n) + c(m) * dt;
  yy = y(:,n) + dt * K(:,1:m-1) * a(m,1:m-1)';
  K(:,m) = feval(f,yy,tt);
 end
 y(:,n+1) = y(:,n)+dt*K(:,1:nstage)*b';
 time(n+1) = time(n) + dt;
end
y = (y(:,1:nt+1))';
end

dt4 = 0.02;
[yrk4 timerk4] = rk4("funcaoFoguete", [0 0], 0, dt4, 2000/dt4);

% Grafico de altura
if(0)
  plot(timerk4, yrk4(:,1), "linewidth", 1)
  set(gca, "fontsize", 18)
  title("Altura x Tempo (RK4)");
  xlabel("tempo");
  ylabel("altura");
endif

% Grafico de velocidade
if(0)
  plot(timerk4, yrk4(:,2), "linewidth", 1)
  set(gca, "fontsize", 18)
  title("Velocidade x Tempo (RK4)");
  xlabel("tempo");
  ylabel("velocidade");
endif


%%%%%%%%%%%%%%%%%%%%%%% PARTE D %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Altere os dts e rode as velocidades calculadas por cada método

% Velocidade pelo lsode
X(posicao_voo, 2)

% Velocidade pelo Euler Explicito
posicao_voo2 = sum(y(:,1) >= 0);
y(posicao_voo2, 2)

% Velocidade pelo RK2
posicao_voo3 = sum(yrk2(:,1) >= 0);
yrk2(posicao_voo3, 2)

% Velocidade pelo RK4
posicao_voo4 = sum(yrk4(:,1) >= 0);
yrk4(posicao_voo4, 2)

display("Miniprojeto 4 parte 1") 

function res = resultado(h)
  x = [0; 0.1; 0.2; 0.5; 0.8; 0.9; 1];
  
  % Valores que estarão no polinomio p para encontrar a máxima diferença
  % c1 possui maior intervalo entre os pontos (0.001), e é minha primeira estimativa, menos aproximada, para encontrar o A
  c1 = 0:0.001:1;
  c2 = 0:0.0005:1;
  
  
  % Criando a matriz M*a = h, a fim de ter a para montar meu polinômio
  n=length(x);
  M=ones(n,1);
  
  for k = 1:(n-1)
   M = [M x.^k];
  endfor
  a = M\h;
  
  % Construindo o polinômio p e por consequencia achando A1
  for k=1:length(c1)
    p(k) = a(1);
    
    for m = 1:(n-1)
      p(k) = p(k) + a(m+1) * c1(k) ^ m;
    endfor
  endfor
  A1 = max(p) - min(p);
  
  % Construindo o polinomio q e por consequencia achando A2, diferença mais aproximada
  for k=1:length(c2)
    q(k) = a(1);
    
    for m = 1:(n-1)
      q(k) = q(k) + a(m+1) * c2(k) ^ m;
    endfor
  endfor
  A2 = max(q) - min(q);
  
  % Cálculo do erro
  maxi = max(abs(A2), abs(A1))
  
  if(maxi == 0)
    erro = 0;
  else
    erro = (abs(A2-A1)) / maxi;
  endif
  
  % Checando se o erro é menor que 1%
  if(erro <= 0.01)
    res = A2;
  else 
    res = -1;
  endif
  
  % Gráfico da interpolada
  scatter(x, h)
  hold on
  plot(c1, p, c2, q)

end

display("Miniprojeto 4 parte 2")

%Função que gera as bases do polinômio. 
function res = phi(k, x)
  res=x.^(k-1);
end
 
%Função que gera a função f 
function res = fmodel(theta, x)
  m = length(theta);
  res = theta(1)*phi(1,x);
  for k = 2:m
   res = res+theta(k)*phi(k, x);
  end
end
 
%Função que gera a função perda 
function ll = perda(theta)
  global xx %% vetor linha
  global yy %% vetor linha
  x = xx; 
  y = yy; 
  nx = length(x);
  fx = fmodel(theta,x);
  ll = (fx-y)*(fx-y)'/nx;
end

%Função que calcula a derivada parcial da função f 
function res = dfmodel(theta,x,k)
  res = phi(k, x);
end

%Função que calcula o gradiente da função perda
function res = gradperda(theta)
  global xx
  global yy
  x = xx; 
  y = yy; 
  nx = length(x); 
  m = length(theta);
  fx = fmodel(theta, x);
  for k = 1:m
    dfx = dfmodel(theta ,x, k);
    res(k) = 2/nx*(y-fx)*(-dfx');
  end
end

function res=resultado2(x, h) 
  global xx 
  global yy 
  
  % tornando meus paramentros globais
  xx = x;
  yy = h;
  
  m = 7;
  
  %% condicao inicial randomica N(0,1)
  theta = randn(1, m);
  
  %% parametros
  lrate = 0.235; 
  iter = 1; 
  tol = 0.001; 
  update = 1e10; 
  itermax = 5000;
  
  %% iteracoes
  while (update > tol && iter < itermax)
    resperda(iter) = perda(theta);
    dtheta = -lrate*gradperda(theta);
    update = norm(dtheta);
    iter = iter+1;
    theta = theta+dtheta;
    postagem = [iter-1 resperda(iter-1) update]

    %Plot da função em tempo real mostrando a aproximação da função (polinômio) dos pontos.
    figure 1
    scatter(xx,yy,150,"+r")
    hold on
    xg = 0:.05:1;
    fxg = fmodel(theta,xg);
    plot(xg,fxg,"linewidth",3)
    hold off
    pause(0.01)
  end
   
  %Plot da função perda em tempo real mostrando o valor do erro a cada iteração.
  figure 2
  semilogy(1:iter-1,resperda(1:iter-1),"linewidth",2)
  display("Resultado do metodo do gradiente:")

  theta   
  c = 0:0.0005:1;
  h = fmodel(theta, c);
  A = max(h)-min(h);
  res = A;  
end























  

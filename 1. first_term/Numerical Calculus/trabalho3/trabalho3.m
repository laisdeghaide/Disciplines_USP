display("trabalho3")

% Função dada que gera o grafo
function [nnos, narestas, C, coord] = geragrafo(n, m)
  
  nnos = n*m;
  narestas = (n-1)*m + (m-1)*n;
  
  % Arestas horizontais
  for j=1:m
    for i=1:n-1
    k = (j-1)*(n-1) + i;
    C(k,1) = (j-1)*n + i;
    C(k,2) = (j-1)*n + i+1;
    end
  end
  
  % Arestas verticais
  for i=1:n
    for j=1:m-1
    k = (n-1)*m + (j-1)*n + i;
    C(k,1) = i + (j-1)*n;
    C(k,2) = i + j*n;
    end
  end
  
  % Coordenadas (para desenhar)
  for i=1:n
    for j=1:m
      ig = i + (j-1)*n;
      coord(ig,1) = i-1;
      coord(ig,2) = j-1;
    end
  end
  return
end

% Função que calcula o sistema linear, a probabilidade e plota o grafo
function [r, q, f, R, C, narestas, nnos, coord] = sistema(N1, N2)
  
  % Lista de arestas e coordenadas para conseguir calcular a matriz e plotar o gráfico
  [nnos, narestas, C, coord] = geragrafo(N1, N2);
  
  % Fontes de tensão
  b = zeros(narestas, 1);
  
  %probabilidade de obstrução
  probabilidade = 0.05 + 0.02*7;
  
  
  % Impedância (em Ohm)
  for k=1:narestas
    if(rand() <= probabilidade)
      R(k) = 10;
    else
       R(k) = 1;
    endif
  endfor
  
  
  % Nós cuja pressão é dada
  i_dado = [0];
  nt = length(i_dado);
  dado = zeros(nt, 1);
 
 
  % Construção da matriz de incidência
  J=zeros(narestas, nnos); 
  for k=1:narestas  
   J(k,C(k,1)) = 1; 
   J(k,C(k,2)) = -1; 
  end

  
  % Construção do sistema linear do problema
  D = zeros(nnos, nnos); 
  B = [diag(R) -J; J' D];
  d = [b; ones(nnos, 1)*-1]; % Fluxos ingressando de fora são -1
  
  
  % Modificação da pressão do nó dado (nó 1)
  Ident = eye(narestas + nnos);
  
  for k=1:nt
    B(narestas+1, :) = Ident(narestas+1, :);
    d(narestas+1) = i_dado(k);
  endfor

  
  % Calculo das pressões e fluxos
  x = B\d;
  % Fluxo
  f = x(1:narestas);
  % Pressão
  q = x(narestas+1 : narestas+nnos);
  % Pressão mínima
  r = min(q);
end


% Função que retorna a probabilidade de a pressão mínima ser menor que -40
function [probabilidade, erro] = amostra(n, N1, N2)
  
  for k=1:n
    Y(k) = sistema(N1, N2);
  endfor
  
  % Média amostral
  media = mean(Y)
  % Desvio amostral
  desvio = std(Y) / sqrt(n)
  
  % Probabilidade de a pressão ser menor que -40 devido a obstrução
  probabilidade = mean(Y < -40);
  % Erro obtido
  erro = std(Y < -40) / sqrt(n);
end


% Função que plota os gráficos
function r = geragraficos(N1, N2)
  
  % função que retorna elementos necessários para o plot do gráfico
  [r, q, f, R, C, narestas, nnos, coord] = sistema(N1,N2);

  
% Visualização do grafo que possibilita visualizar a vazão em cada cano
  if(1)
    hold on
    for i=1:narestas
      xaux=[coord(C(i,1),1) coord(C(i,2),1)];
      yaux=[coord(C(i,1),2) coord(C(i,2),2)];
      if (f(i)<0)
        l=0;
      else
        l = f(i);
      endif
      if(R(i) == 1) 
        plot(xaux, yaux, "g-", "linewidth", ceil(l+1))
      else
        plot(xaux, yaux, "r-", "linewidth", ceil(l+1))
      endif
    endfor
    scatter(coord(:,1), coord(:,2), 400, q, "filled");
 endif  
 
 %Visualização gráfico 3d.
  if(1)
  hold on
  [xx yy] = meshgrid((1:N2)-1,(1:N1)-1);
  zz = reshape(q, N2, N1)';
  surf(xx, yy, zz);
  endif
end

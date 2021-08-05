display("Uma epidemia de Bernoulli - Exercício 45-b\n")
display("Beta pode ser dividido por 1, 2, 3 ou 4")
display("Passe um desses valores como parâmetro da função epidemia")
display("Por exemplo: epidemia(1), epidemia(2), epidemia(3), epidemia(4)\n")

display("Para encontrar o valor esperado (x*) para cada um desses beta: ")
display("Rode a função estimativa passando como parametro o divisor de beta que deseja (1, 2, 3, 4).\n")


%função que calcula a fracao da população que ficou doente, uma vez acabado o periodo
function res = epidemia(divisor)
  N = 10^4;                                                 %quantidade populacional
  S(1) = N-20;                                              %quantidade inicial de individuos sucetiveis 
  I(1) = 20;                                                %quantidade inicial de individuos infectados
  R(1) = 0;                                                 %quantidade inicial de recuperados
  beta = 1.8e-04 / divisor;                                 %valor de beta que pode ser beta/1, beta/2, beta/3 e beta/4
  dt = 1;                                                   %variação do tempo
  
  for t = 2:600001                              
    p = dt*beta*I(t-1)*S(t-1) / N;                          %probabilidade de se produzir um novo contágio
    novosInfectados = (rand() < p);
    
    q = dt*4.96e-05*I(t-1);                                 %probabilidade de se produzir uma recuperação
    novosRecuperados = (rand() < q);
    
    S(t) = S(t-1) - novosInfectados;                        %quantidade de pessoas sucetiveis em dt
    I(t) = I(t-1) + novosInfectados - novosRecuperados;     %quantidade de pessoas infectadas em dt
    R(t) = R(t-1) + novosRecuperados;
  endfor
  
  res = R(600001) / N;                                     %fração da população que ficou doente
end



function [valor_estimado valor_x erro_x media desvio] = estimativa(divisor)     %função que vai me retornar o valor estimado para cada valor de beta, o erro de x*, a média e o desvio amostral
  n = 1000;
  
  for k = 1:n                                                          %rodando a função epidemia n vezes e armazenando os n valores em Y
    Y(k) = epidemia(divisor);
  endfor
                                                                       %valor estimado respectivo para cada beta
  if(divisor == 1)
    valor_estimado = 0.974;
  endif
  
  if(divisor == 2)
    valor_estimado = 0.7555;
  endif
  
  if(divisor == 3)
    valor_estimado = 0.3684;
  endif
  
  if(divisor == 4)
    valor_estimado = 0.0475;
  endif
  
  valor_x = mean(Y > valor_estimado);                                 %x*
  erro_x = std(Y > valor_estimado) / sqrt(n);                         %erro obtido pelo valor esperado
  media = mean(Y);                                                    %média amostral
  desvio = std(Y) / sqrt(n);                                          %desvio padrão amostral
end

display("exerc�cio 5")

%fun��o para retirar um numero aleatorio entre 1 e 52
function res = cartas()
  res = ceil(rand()*52);
end


%fun��o que retorna o intervalo entre a apari��o de duas copas
function res = entrecopas()
  x = [];
  quantidade_copas = 0;
  intervalo = 0;
  
  for i = 1:52
    valor = cartas();
    
    while(sum(x == valor))
      valor = cartas();
    endwhile
    
    x(i) = valor; 
    
    %checo se o valor tirado foi copas, se sim, incremento meu contador e atualizo meu intervalo
    if x(i) <= 13
      quantidade_copas = quantidade_copas + 1;
      intervalo = i - intervalo;
    endif
    
    %se eu j� tiver encontrado duas copas, encerro o loop e retorno o intervalo entre elas
    if quantidade_copas == 2 
      break      
    endif
    
  endfor
  res = intervalo - 1;
end


%fun��o que repete entrecopas() 1000 vezes e plota o histograma
function res = teste1000()
  for i = 1:1000
    y(i) = entrecopas();
  endfor
  res = sum(y);
  hist(y,[0:max(y)]);
end
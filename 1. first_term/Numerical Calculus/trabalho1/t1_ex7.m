display("exerc�cio 7")

%fun��o para retirar um numero aleatorio entre 1 e 52
function res = cartas()
  res = ceil(rand()*52);
end

%fun��o que retorna a soma das cartas at� aparecer um as (1)
function res = ateoas()
  x = [];
  soma = 0;
  
  for i = 1:52
    valor = cartas();
    
    while(sum(x == valor))
      valor = cartas();
    endwhile
    
    x(i) = valor; 

    %se o valor tirado n�o for as, eu acrescento na soma 
    if(x(i) != 1) 
      soma = soma + x(i);
      
    %se for, eu encerro o loop e retorno o valor da soma
    else 
      break
    endif
    
  endfor
  res = soma;
end

%fun��o que repete ateoas() 1000 vezes e plota o histograma
function res = teste1000()
  for i = 1:1000
    y(i) = ateoas();
  endfor
  res = sum(y);
  hist(y,[0:max(y)]);
end
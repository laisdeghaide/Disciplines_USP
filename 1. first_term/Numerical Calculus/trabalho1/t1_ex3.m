display("exercício 3")

%função para retirar um numero aleatorio entre 1 e 52
function res = cartas()
  res = ceil(rand()*52);
end


%função que booleana que retorna se duas cartas são copas
function res = duascopas()
  x = [];
  quantidade_copas = 0;
  for i = 1:2
    valor = cartas();
    
    while(sum(x == valor))
      valor = cartas();
    endwhile
    
    x(i) = valor; 
    
    %checo se o valor tirado foi copas, se sim, incremento meu contador
    if x(i) <= 13
      quantidade_copas = quantidade_copas + 1;
    endif
    
  endfor
  
  %se as duas cartas tiradas forem copas, retorno 1
  if quantidade_copas == 2
    res = 1;
  else 
    res = 0;
  endif
end


%função que repete duascopas() 1000 vezes e plota o histograma
function res = teste1000()
  for i = 1:1000
    y(i) = duascopas();
  endfor
  res = sum(y);
  hist(y,[0:1]);
end
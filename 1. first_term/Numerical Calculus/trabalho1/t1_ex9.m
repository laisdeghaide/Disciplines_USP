display("exercício 9")

%função para retirar um numero aleatorio entre 1 e 52
function res = cartas()
  res = ceil(rand()*52);
end

%função que retorna se é ou não fullhouse
function res = fullhouseb()
  x = [];
  
  %retirando 5 cartas
  for i = 1:5
    valor = cartas();
    
    while(sum(x == valor))
      valor = cartas();
    endwhile
    
    x(i) = valor; 
  endfor
  
  x_sorted = sort(x);
  
  if(x_sorted(1) == x_sorted(2) && x(4) == x_sorted(5) && (x_sorted(3) == x_sorted(2) || x_sorted(3) == x_sorted(4)))
    res = 1;
  else 
    res = 0;
  endif
end

%função para repetir fullhouseb() 1000 vezes e mostrar o histograma%
function res = teste1000()
  for k = 1:1000
    y(k) = fullhouseb();
  endfor
  res = sum(y);
  hist(y,[0:1]);
end
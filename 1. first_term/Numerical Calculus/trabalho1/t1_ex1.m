display("exercício 1")

%função para retirar um numero aleatorio de 1 a 20
function res = bolas()
  res = ceil(rand()*20);
end

%função que calcula quantas bolas são verdes
function res = tresbolas20()
  x = [];
  for i = 1:3
    valor = bolas();
    
    while(sum(x == valor))
      valor = bolas();
    endwhile
    
    x(i) = valor;  
  endfor
  res = sum(x <= 10);
end
  
%função que repete tresbolas2() 1000 vezes e plota o histograma
function res = teste1000()
  for i = 1:1000
    y(i) = tresbolas20();
  endfor
  res = sum(y);
  hist(y,[0:3]);
end
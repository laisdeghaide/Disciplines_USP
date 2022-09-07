
/*
Alert = método do window que recebe apenas um parametro(string)
Prompt - método do window que recebe um parametro (string) e retorna o valor da caixa
Confirm - método do window que retorna true ou false
*/

//let nome = window.prompt("Digite seu nome")
let resposta = confirm("tem certeza que deseja excluir esse item? ")
if (resposta == true)
    alert("Item excluido com sucesso!")
else
    alert("Exclusao cancelada")


//AULA 30
/*
Functions

function soma(x, y) {
    return x + y;
}

//console.log(soma(4, 5))
document.getElementById("resultado").innerHTML = soma(7, 5)
*/

// AULA 29
/* loops:
for in
for of

let fruta = { nome: "Banana", preco: 9.99, unidade: 1 }
let aparelhos = ["Celular", "Fone de ouvido", "Microfone"]

for (let valor of aparelhos) {
    console.log(valor)
}

/*for (let valor in fruta) {
    console.log(fruta[valor])
}
*/


//AULA 28
/* loops
for
while

let paises = document.getElementsByClassName('pais')
let i = 0

for (let i = 0; i < paises.length; i++) {
    console.log(paises[i].innerHTML)
}

while (i < paises.length) {
    console.log(paises[i].innerHTML)
    i++
}
*/

//AULA 27
/* Condicionais:
If
Else
ElseIf
Switch


let pais = "brasil"
let estado = "sp"

switch (pais) {
    case 'brasil':
        console.log("Sim, Brasil")
        break
    case
        'canada': console.log("opa, Canadá")
        break
}

if (pais == "brasil") {
    console.log("sou brasileiro")
}
else if (estado == "sp") {
    console.log("sou paulista")
}
else {
    console.log("sou gringo")
}
*/

/* AULA 26
/* Operadores:
Lógicos
Comparacao
Operador ternario

let x = 5
console.log(x === "5") // comparacao de tipo de dado: um é numero outro é string

let media = 8
let frequencia = 80
console.log(media >= 7 && frequencia >= 80)


let idade = 12
let eleitor = (idade > + 16) ? "Pode votar" : "Não pode voltar"
console.log(eleitor)
*/

/* AULA 24 e 25
/* Operadores:
Aritimeticos
Atribuição

let x = 10
let y = 5

x += y

console.log(x + y)
*/

/* AULA 23
// Objeto
let pessoa = {
    nome: "jonatas",
    idade: 35,
    feliz: true,
    pets: ["cachorro", "gato"],
    carros: {
        camaro: {
            placa: "1232443",
            cor: "verde"
        },
        uno: {
            placa: "342134",
            cor: "branco"
        }
    },
    andar: function (km) {
        alert(pessoa.nome + " andou " + km + "km")
    }
}
pessoa.andar(20)
console.log(pessoa.nome)
*/

/*AULA 22
// Array
let meuarray = ['notebook', 'mouse'];
console.log(meuarray.length);
*/

/* AULA 21
// Variaveis
// escopo globalThis, escopo local
// var (escopo global), let(dentro do bloco), const

if (true) {
    let nome = "daniel"
}

console.log(nome)
*/

/* AULA 20
// Tipos de dados

// String
var nome = "Laís Deghaide"

// Number
var idade = 22;

// Boolean
var solteira = false;

// array
var frutas = ["goiaba", "maça"]

// object
var carro = new Object()
carro.fabricacao = "2012"
carro.cor = "azul"

// function
var soma = function(a,b) {return a+b}

alert(typeof (solteira))
*/


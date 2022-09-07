
//AULA 18 e 19
var lista = document.getElementsByTagName("ul")[0]
var itens = lista.children

var novoItem = document.createElement("li")
novoItem.textContent = "Suco de laranja"

lista.insertBefore(novoItem, itens[0])

var lista2 = document.getElementsByTagName("ul")[1]
var itens2 = lista2.children

var novoItem2 = document.createElement("li")
novoItem2.textContent = "Margarina"

lista2.replaceChild(novoItem2, itens2[2])

console.log(lista2)

//AULA 17
// var titulo = document.querySelector("h1")
// var texto = document.createTextNode("Um texto qualquer")

// titulo.appendChild(texto)

// titulo.textContent = "Um novo texto"

//AULA 16
// document.getElementById("btn-set").addEventListener("click", function () {
//     document.getElementById("title").setAttribute("class", "red")
// })

// document.getElementById("btn-remove").addEventListener("click", function () {
//     document.getElementById("title").removeAttribute("class")
// })

// document.getElementById("btn-get").addEventListener("click", function () {
//     var value = document.getElementById("title").getAttribute("class")
//     document.getElementById("class").innerHTML = value
// })

//AULA 15
// console.log(
//     document.getElementById("ilheus").parentNode.parentNode
// )

//AULA 13 e 14
// console.log(
//     document.body.childNodes
// )

// var lista = document.body.childNodes
// alert(lista[6].childNodes[2])

//AULA 12
// var p = document.createElement("p")
// p.innerHTML = "Olá pessoal"

// var img = document.createElement("img")
// img.scr = "html.png"
// document.getElementById("conteudo").appendChild(p) // appendChild serve para inserir um elemento dentro de outro
// document.getElementById("conteudo").appendChild(img)

//AULA 11
// var image = document.createElement("img")
// image.src = "js.png"

// var paragrafo = document.createElement("p")
// paragrafo.innerHTML = "Olá pessoal"

// console.log(
//     image, paragrafo
// )
// console.log(
//     document.createElement("div")
// )

//AULA 10
// var image = document.getElementById("image")
// image.src = "html.png"
// image.alt = "Teste"
// image.width = "30"
// var paragrafo = document.getElementById("p1")
// paragrafo.innerHTML = "Novo conteúdo"
// paragrafo.style.color = "red"
// paragrafo.style.backgroundColor = "#333"
// paragrafo.style.height = "400px"

// console.log(
//     document.getElementById("p1").innerHTML
// )
// document.getElementById("p1").innerHTML = "Novo conteudo"

//AULA 9
// console.log(
//     document.getElementById("futebol-europeu").querySelectorAll(".times")
// )

//AULA 8
// console.log(
//     // document.getElementsByTagName("div")
//     document.querySelector("p")
// )


//AULA 7
// console.log(
//     document.getElementsByClassName("carro")[0].innerHTML
// )



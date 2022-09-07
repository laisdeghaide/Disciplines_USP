// 1
var paragrafo = document.querySelector("p")
var wordCount = paragrafo.innerHTML.match(/(\w+)/g).length;

var a = document.createElement("a")
var link = document.createTextNode("Home")
a.appendChild(link)
a.title = "Home"
a.href = "#"

paragrafo.appendChild(a)


// 2
var result = paragrafo.innerHTML.match(/[^\.!\?]+[\.!\?]+/g)
var paragrafo2 = document.createElement("p")

var str = ""

for (let i = 0; i < result.length; i++) {
    str += result[i]
    str += "\n"
}

// var text = document.createTextNode(str)
// paragrafo2.appendChild(text)

// var body = document.querySelector("body")
// body.appendChild(paragrafo2)

// 3
alert(wordCount)
console.log(paragrafo.innerHTML)
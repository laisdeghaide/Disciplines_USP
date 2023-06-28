let resposta = prompt("Digite seu nome:")
let size = 0;
for (let i = 0; i < resposta.length; i++) {
    if (resposta[i].toUpperCase() != resposta[i].toLowerCase())
        size++;
}

alert(resposta + ": " + size + " characters")


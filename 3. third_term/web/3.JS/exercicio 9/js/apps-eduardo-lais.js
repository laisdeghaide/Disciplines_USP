'use strict'

// Exercicio 1
// a.
function requestColor() {
    const url = "https://reqres.in/api/unknown/";

    const id = document.getElementsByClassName("id-color")[0].value;
    if (!id) {
        alert("Informe um id!");
        return;
    }

    const file = url + id;

    fetch(file)
        .then(x => x.json())
        .then(y => {
            const colorhex = document.getElementById("p-1");
            colorhex.innerHTML = 'Color: ' + y.data.color;

            const colorname = document.getElementById("p-2");
            colorname.innerHTML = y.data.name;

            const background = document.getElementById("color");
            background.style.background = y.data.color;

        })
        .catch(() => {
            alert("Desculpe a cor não existe!");
        });
}

// b.
function createChangeButton() {
    const button = document.getElementById("button");
    button.addEventListener("click", requestColor);
}

createChangeButton();
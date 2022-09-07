// Exercise 2:

const colors = ["brown", "green", "purple", "yellow", "pink", "blue", "white", "black"];

// a.
window.addEventListener("DomContentLoaded", (event) => {
    console.log("DOM fully loaded and parsed");
});


// b. 
let heading = document.getElementById("change_heading");
heading.innerHTML = "Select your color!";


// c.
let box = document.getElementsByTagName("section")[0];
let divs = box.childNodes;

divs.forEach(color => {
    color.addEventListener("mouseover", () => {
        document.getElementsByClassName("selected")[0].innerText = color.className;
    })
})


// d.
function getRandomArbitrary(min, max) {
    return Math.random() * (max - min) + min;
  }

let random = document.createElement("div");
random.className = colors[Math.floor(getRandomArbitrary(1, colors.length)) - 1];
setInterval(function () {
    let section = document.getElementsByTagName("section")[0];
    let curr = section.lastChild.className;
    let color = colors[Math.floor(getRandomArbitrary(1, colors.length)) - 1];

    while(curr = color) {
        color = colors[Math.floor(getRandomArbitrary(1, colors.length)) - 1];
    }

    section.lastChild.className = color;

}, 1000)


// Exercise 3:
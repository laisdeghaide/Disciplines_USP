// Exercise 1:
// a.
document.getElementById("lib-button").addEventListener("click", makeMadTalk);

// b. i. e b. ii.
function makeMadTalk() {
    var noun = document.getElementById("noun").value;
    var adjective = document.getElementById("adjective").value;
    var person = document.getElementById("person").value;

    const div = document.getElementById('story');
    div.textContent = person + " really likes " + adjective + " " + noun + ".";
}


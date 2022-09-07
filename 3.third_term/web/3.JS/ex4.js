var color = ["Blue", "Green", "Red", "Orange", "Violet", "Indigo"];
var order = [2, 1, 4, 5, 6, 3];
var result = [];

function Ordinal(n) {
    var o = ["th", "st", "nd", "rd"],
        x = order[n - 1];
    return x + (o[(x - 20) % 10] || o[x] || o[0]);
}

for (n = 1; n <= color.length; n++) {
    var output = (Ordinal(n) + " choice is " + color[n - 1] + ".");
    result.push(output);
}

result.sort();

for (n = 1; n <= color.length; n++) {
    console.log(result[n - 1]);
}


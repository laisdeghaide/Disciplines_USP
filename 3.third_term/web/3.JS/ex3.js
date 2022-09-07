const arr1 = [3, 'a', 'a', 'a', 'a', 3, 'a', 3, 'a', 2, 4, 9];
var map = {};
var mostFrequentElement = arr1[0];
for (var i = 0; i < arr1.length; i++) {
    if (!map[arr1[i]]) {
        map[arr1[i]] = 1;
    } else {
        ++map[arr1[i]];
        if (map[arr1[i]] > map[mostFrequentElement]) {
            mostFrequentElement = arr1[i];
        }
    }
}
alert(mostFrequentElement + " ( " + map[mostFrequentElement] + " times )");

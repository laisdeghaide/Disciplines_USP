// Question 1:
const home = document.createElement('a');
home.textContent = 'Home';
home.href = '#';

document.getElementsByTagName('body')[0].append(home);


// Question 2:

const aliceText = document.querySelector("p").textContent;
const wordCount = aliceText.split(' ').filter(word => /\w+/.test(word)).length;

const text = document.createElement('p');
text.textContent = `There are ${wordCount} words in this text.`;

document.getElementsByTagName('body')[0].prepend(text);

// Question 3:

const sentences = aliceText.match(/[^\.!\?]+[\.!\?]+/g);

for (const sentence of sentences) {
  const sentenceElement = document.createElement('p');
  sentenceElement.textContent = sentence;
  document.getElementsByTagName('body')[0].append(sentenceElement);
}

// Question 4:

const newText = document.createElement('p');


const wordsAndPontuation = aliceText.match(/([^.,!?;:()"' ]|'\S)+|[.,!?;:()"' ]+/g);


for (const word of wordsAndPontuation) {
  if (word.length >= 8) {
    const wordSpan = document.createElement('span');
    wordSpan.classList.add('pink');
    wordSpan.textContent = word;
    newText.append(wordSpan);
  } else if (word.length === 6) {
    const wordSpan = document.createElement('span');
    wordSpan.classList.add('purple');
    wordSpan.textContent = word;
    newText.append(wordSpan);
  } else if (word.length === 5 || word.length === 4) {
    const wordSpan = document.createElement('span');
    wordSpan.classList.add('blue');
    wordSpan.textContent = word;
    newText.append(wordSpan);
  } else {
    const textNode = document.createTextNode(word);
    newText.append(textNode);
  }
}

document.getElementsByTagName('body')[0].append(newText);
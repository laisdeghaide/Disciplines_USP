'use strict'

// Exercicio 2

// a.
const getJoeHappinessOriginal = (happy, callback) => {
    setTimeout(() => {
        const happiness = Math.random();
        if (happiness > happy) {
            callback(happiness);
        } else {
            callback(new Error("Joe is sad!"));
        }
    }, 2000);
}

function measureJoeHappinessCallback() {
    const threshold = Number(document.querySelector("input[type='text']").value);


    if (isNaN(threshold) || threshold > 1 || threshold < 0) {
        alert("Please, enter a value between 0 and 1!");
        return;
    }

    getJoeHappinessOriginal(threshold, (happiness) => {
        if (happiness instanceof Error) {
            document.querySelector("p").textContent = "No! ! ! " + happiness.message;
            document.querySelector("p").style.color = "red";
        } else {
            document.querySelector("p").textContent = "Yes! By " + Math.round(happiness * 100) + " %"
            document.querySelector("p").style.color = "black";
        }
    });
}

//b.

const getJoeHappinessPromise = (happy) => {
    const promise = new Promise((resolve, reject) => {
        setTimeout(() => {
            const happiness = Math.random();
            if (happiness > happy) {
                resolve(happiness);
            } else {
                reject(new Error("Joe is sad!"));
            }
        }, 2000);
    });
    return promise;
}

function measureJoeHappinessPromise() {
    const threshold = Number(document.querySelector("input[type='text']").value);


    if (isNaN(threshold) || threshold > 1 || threshold < 0) {
        alert("Please, enter a value between 0 and 1!");
        return;
    }

    getJoeHappinessPromise(threshold).then((happiness) => {
        document.querySelector("p").textContent = "Yes! By " + Math.round(happiness * 100) + " %"
        document.querySelector("p").style.color = "black";
    }).catch((error) => {
        document.querySelector("p").textContent = "No! ! ! " + error.message;
        document.querySelector("p").style.color = "red";
    });
}

//c.

const getJoeHappinessAsync = async (happy) => {

    const asyncSetTimeout = (timeout) => new Promise((resolve) => setTimeout(resolve, timeout));
    await asyncSetTimeout(2000);

    const happiness = Math.random();
    if (happiness > happy) {
        return happiness;
    }
    throw new Error("Joe is sad!");
}

async function measureJoeHappinessAsync() {
    const threshold = Number(document.querySelector("input[type='text']").value);


    if (isNaN(threshold) || threshold > 1 || threshold < 0) {
        alert("Please, enter a value between 0 and 1!");
        return;
    }

    try {
        const happiness = await getJoeHappinessAsync(threshold);
        document.querySelector("p").textContent = "Yes! By " + Math.round(happiness * 100) + " %"
        document.querySelector("p").style.color = "black";
    }
    catch (error) {
        document.querySelector("p").textContent = "No! ! ! " + error.message;
        document.querySelector("p").style.color = "red";
    }
}

document.querySelector("input[type='submit']").addEventListener("click", measureJoeHappinessAsync);
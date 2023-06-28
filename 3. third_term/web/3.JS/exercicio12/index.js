'use strict'

const express = require('express');
const cors = require('cors');
const app = express()
const port = 3000

app.use(cors());
app.use(express.json());
app.use(express.urlencoded({ extended: true }));

const db = {};

app.get('/store/:id', (req, res) => {
    const { id } = req.params;
    if (db[id] === undefined) {
        res.send();
    } else {
        res.json(db[id]);
    }
});


app.put('/store/:id', (req, res) => {
    const { id } = req.params;
    const data = req.body;
    console.log(data);
    db[id] = data;
    res.send("OK");
});

app.delete('/store/:id', (req, res) => {
    const { id } = req.params;
    delete db[id];
    res.send("OK");
});

app.listen(port, () => {
    console.log(`App listening at http://localhost:${port}`)
}
);
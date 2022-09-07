'use strict';

const { MongoClient, Db } = require('mongodb');
const express = require('express');
const app = express();
const port = 3000;

app.use(express.json());
app.use(express.urlencoded({ extended: true }));
app.use(express.static('public'));

const client = new MongoClient('mongodb://localhost:27017');
let db;

app.get('/store/:id', async (req, res) => {
  const { id } = req.params;
  const result = await db.findOne({ id });
  if (result === null) {
    res.status(404).send();
  } else {
    res.json(result);
  }
});

app.put('/store/:id', async (req, res) => {
  const { id } = req.params;
  const data = req.body;
  const result = await db.updateOne({ id }, { $set: { id, ...data } }, { upsert: true });
  res.send('OK');
});

app.delete('/store/:id', async (req, res) => {
  const { id } = req.params;

  const result = await db.deleteOne({ id });

  if (result.deletedCount === 0) {
    res.status(404).send();
  } else {
    res.send('OK');
  }
});

client.connect().then(() => {
  console.log('MongoDB Client Connected Succesfully!');
  db = client.db('LAIS_11369767').collection('products');
  app.listen(port, () => {
    console.log(`App listening at http://localhost:${port}`);
  });
}).catch((e) => {
  console.log('Error connecting to MongoDB!', e);
})

const cleanup = () => {
  client.close();
  process.exit();
}

process.on('SIGINT', cleanup);
process.on('SIGTERM', cleanup);
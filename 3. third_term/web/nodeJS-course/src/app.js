'use strict'

const express = require('express')
const bodyParser = require('body-parser')
const mongoose = require('mongoose')

const app = express()
const router = express.Router()

// Conecta ao banco
mongoose.connect('mongodb://localhost:27017')

// Carra os Models
const Product = require('./models/product')

// Carrega as rotas
const indexRoute = require('./routes/index')
const productsRoute = require('./routes/products')

app.use(bodyParser.json())
app.use(bodyParser.urlencoded({ extended: false }))


app.use('/', indexRoute)
app.use('/products', productsRoute)

module.exports = app
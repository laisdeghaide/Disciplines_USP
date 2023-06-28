"use strict"

const PORT = 8080;
const http = require('http');
const fs = require('fs');
const path = require('path');

const randomNumber = (min, max) => {
    return Math.random() * (max - min) + min;
}

http.createServer(async (request, response) => {
    console.log('request ', request.url);

    let filePath = '.' + request.url;
    if (filePath === './') {
        filePath = './index.html';
    }

    const extname = String(path.extname(filePath)).toLowerCase();
    const mimeTypes = {
        '.html': 'text/html',
        '.js': 'text/javascript',
        '.css': 'text/css',
        '.json': 'application/json',
        '.png': 'image/png',
        '.jpg': 'image/jpg',
        '.gif': 'image/gif',
        '.svg': 'image/svg+xml',
        '.wav': 'audio/wav',
        '.mp4': 'video/mp4',
        '.woff': 'application/font-woff',
        '.ttf': 'application/font-ttf',
        '.eot': 'application/vnd.ms-fontobject',
        '.otf': 'application/font-otf',
        '.wasm': 'application/wasm'
    };

    const contentType = mimeTypes[extname] ?? 'application/octet-stream';

    if (filePath.split('?')[0] === './random') {

        const getParam = request.url.match(/max=(\d+)/);

        const max = getParam ? parseInt(getParam[1]) : 1;

        response.writeHead(200, { 'Content-Type': 'text/plain-text' });
        response.end(randomNumber(0, max).toString(), 'utf-8');
    } else {

        try {
            const content = await fs.promises.readFile(filePath);
            response.writeHead(200, { 'Content-Type': contentType });
            response.end(content, 'utf-8');
        } catch (error) {
            if (error.code == 'ENOENT') {
                const content = await fs.promises.readFile('./404.html');
                response.writeHead(404, { 'Content-Type': 'text/html' });
                response.end(content, 'utf-8');
            }
            else {
                response.writeHead(500);
                response.end('Sorry, check with the site admin for error: ' + error.code + ' ..\n');
            }
        }
    }

}).listen(PORT);
console.log('Server running at http://127.0.0.1:' + PORT + '/');

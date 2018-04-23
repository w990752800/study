const express = require('express');
const expressStatic = require('express-static');

var server = express();




server.listen(8081);

server.use(expressStatic('./www'));

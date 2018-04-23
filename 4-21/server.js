const express = require('express');

var server = express();

server.use('/',function(req,res){
  res.send({'a':'a','b','b'})
  res.end();
})

server.listen(8080);

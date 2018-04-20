const http = require('http');

var server = http.createServer(function(req,res){
  console.log(req.url);
  res.write('aaa');
  res.end();
}).listen(1111);

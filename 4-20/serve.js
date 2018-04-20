const http = require('http');

http.createServer(function(req,res){

  res.write('aaa');
  res.end();

}).listen(8080);

const http = require('http');
const urlLib = require('url');

http.createServer(function(req,res){

  var GET = urlLib.parse(req.url,true);
  console.log(GET.query);
  console.log(GET.pathname)
  res.end();


}).listen(8080);

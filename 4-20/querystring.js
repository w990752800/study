const http = require('http');
const querystring = require('querystring');

http.createServer(function(req,res){
  var arr = req.url.split('?');
  var GET = querystring.parse(arr[1]);
  console.log(GET);
  res.end();

}).listen(8080);

const http = require('http');
const querystring = require('querystring');

http.createServer(function(req,res){
  var str = '';
  req.on('data',function(data){
    str+=data;
  });
  req.on('end',function(){
    //console.log(str);
    var POST = querystring.parse(str);
    console.log(POST);
    res.end();
  });
}).listen(8080);

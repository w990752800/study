const http = require('http');

var serve = http.createServer(function(request,response){
  console.log(request.url);
  response.end('hello world');

})

serve.listen(3333)

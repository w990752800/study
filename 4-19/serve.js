const http =  require('http');
var fs = require('fs');

var serve = http.createServer(function(req,res){
  fs.readFile('./www'+req.url,function(err,data){
    if(err){
      console.log(err);
    }else{
      res.write(data);
      res.end();
    }
  })


})

serve.listen(1111);

const http = require('http');
const fs = require('fs');

var serve = http.createServer(function(req,res){

  fs.readFile('aaa.txt',function(err,data){

    if(err){
      console.log('读取失败')
    }else{
      console.log(data);
    }
  })

  res.end();
})

serve.listen(6666)

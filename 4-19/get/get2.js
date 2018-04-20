const http = require('http');

var server = http.createServer(function(req,res){
  //得到 get 请求的用户名和密码
  console.log(req.url);
  var GET = {};
  if(req.url.indexOf('?') != -1){
    var arr1 = req.url.split('?');
    var url = arr1[0];
    var arr2 = arr1[1].split('&');
    for(var i=0;i<arr2.length;i++){
      var arr3 = arr2[i].split('=');
      GET[arr3[0]] = arr3[1];
    }

  }else{
    var url = req.url;
  }

  res.end();


}).listen(2222);

const http = require('http');
const fs = require('fs');
const querystring = require('querystring');
const urlLib = require('url');

//创建服务器
http.createServer(function(req, res) {
  //解析get数据
  var data = urlLib.parse(req.url, true);
  var url = data.pathname;
  const GET = data.query;
  //解析post数据
  var str = '';
  req.on('data', function(data) {
    str += data;
  })
  req.on('end', function() {
    const POST = querystring.parse(str);
  })

  /* 文件读取 */
  var file_name = './www'+url;
  fs.readFile(file_name,function(err,data){
    if(err){
      res.write('404');
    }else{
      res.write(data);
      console.log(data);
    }
    res.end();
  })





}).listen(8081); //监听8081端口

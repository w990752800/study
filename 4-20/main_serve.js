const http = require('http');
const fs = require('fs');
const querystring = require('querystring');
const urlLib = require('url');

http.createServer(function(req, res) {

  var data = urlLib.parse(req.url, true);
  var url = data.pathname;
  const GET = data.query;

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





}).listen(8081);

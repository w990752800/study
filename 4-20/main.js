const http = require('http');
const fs = require('fs');
const urlLib = require('url');
const querystring = require('querystring');

var server = http.createServer(function(req, res) {
var users = {};
  var str = ''
  req.on('data', function(data) {
    str += data;
  })
  req.on('end', function() {
    var obj = urlLib.parse(req.url);
    var url = obj.pathname;
    var GET = obj.query;
    var POST = querystring(str);

    if(url == '/user'){
      switch (GET.act) {
        case 'reg':
          if(users[GET.user]){
            res.write('{"ok":false,"msg":"此用户已存在"}')
          }else{
            users[GET.user] = GET.pass;
            res.write('{"ok":true,"msg":"注册成功"}')
          }
          break;
        case 'login':
          if(users[GET.user]!=GET.pass){
            res.write('{"ok":false,"mag":"密码错误"}')
          }
          break;
        default:

      }
    }

    var file_name = './www' + url;
    fs.readFile(file_name, function(err, data) {
      if (err) {
        res.write('404');
      } else {
        res.write(data);
      }
    })
    res.end();
  })
})

server.listen(8080);

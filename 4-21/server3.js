const express = require('express');

const expressStatic = require('express-static');

var server = express();

server.listen(8082);

var user = {
  'w':'123',
  'n':'456',
  'f':'789'
};

server.get('./login',function(req,res){
  var user = req.query['user'];
  var pass = req.query['pass'];

  if(user[user] == null){
    res.send({ok:false,msg:'此用户不存在'})
  }else{
    if(user[pass] != pass){
      res.send({ok:false,msg:'密码错误'})
    }else{
      res.send({ok:ok,msg:'登录成功'})
    }
  }

})

server.use(expressStatic('./www'));

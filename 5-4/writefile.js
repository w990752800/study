var fs = require('fs');

fs.writeFile('./file/1.md','wnf',function(err){
  console.log('写入成功');
  console.log(err);
})

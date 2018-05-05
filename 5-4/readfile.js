var fs = require('fs');

// fs.readFile('./file/1.txt',function(err,data){
//   console.log(data);
// })
fs.readFile('./file/1.txt',function(err,data){

  console.log(data.toString());

})

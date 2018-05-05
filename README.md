# 好好学习，天天向上

## 每天学一点nodejs

- ###### nodejs中没有BOM 和 DOM

- ###### 文件读取 ，写文件   file-system

  ```
  var fs = require('fs');
  fs.readFile('文件的路径'，function(err,data){
      console.log(data); //<Buffer 77 6e 66 0d 0a> 二进制数据
      console.log(data.toString());   //toString()把二进制转换为人能看懂的字符
  })
  ```

  ```
  var fs = require('fs');
  fs.writeFile('./file/1.txt','写入的内容',function(err){
  	console.log('写入成功');
  	console.log(err);
  })
  ```

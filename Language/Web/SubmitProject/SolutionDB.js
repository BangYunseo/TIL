const express = require('express');
const mysql = require('mysql2');
const { Client } = require('ssh2');
var http = require('http');

const app = express();
const sshClient = new Client();


const dbConfig = {
    host: 'localhost',
    port: 33060,
    user: 'tmp_usr',
    password: '1234',
    database: 'DBtmp_usr'
};

const tunnelConfig = {
    host: 'classnet.mju.ac.kr',
    port: 1004,
    username: '본인 SSH_USER', //SSH_USER
    password: '본인 SSH_PASSWORD' // SSH_PASSWORD 또는 privateKey
};

const forwardConfig = {
    srcHost: '127.0.0.1',
    srcPort: 33060,
    dstHost: dbConfig.host,
    dstPort: dbConfig.port
};


// 🔁 미들웨어에서 SSH 연결 및 DB 쿼리
app.use('/data.json', (req, res, next) => {
  const ssh = new Client();

  ssh.on('ready', () => {
    ssh.forwardOut(
      forwardConfig.srcHost,
      forwardConfig.srcPort,
      forwardConfig.dstHost,
      forwardConfig.dstPort,
      (err, stream) => {
        if (err) {
          ssh.end();
          return next(err);
        }

        const updatedDbConfig = { ...dbConfig, stream: stream };
        const connection = mysql.createConnection(updatedDbConfig);

        connection.connect(error => {
          if (error) {
            ssh.end();
            return next(error);
          }

          connection.query('SELECT * FROM Class_Order', (err, results) => {
            connection.end();
            ssh.end();

            if (err) return next(err);
            req.queryResults = results; // 결과를 req에 저장
            next();
          });
        });
      }
    );
  }).connect(tunnelConfig);
});

// 📄 /data.json 라우터에서 출력
app.get('/data.json', (req, res) => {
  const results = req.queryResults;

  if (!results) {
    return res.status(500).send('No data found.');
  }

  let html = '<table border="1"><tr><th>Num</th><th>Product</th><th>Customer</th></tr>';
  results.forEach(row => {
    html += `<tr><td>${row.Order_Num}</td><td>${row.Order_Product}
    </td><td>${row.Order_Customer}</td></tr>`;
  });
  html += '</table>';

  res.send(html);
});


// 서버 실행
http.createServer(app).listen(52273, function () {
    console.log('Server Running at http://127.0.0.1:52273');
});


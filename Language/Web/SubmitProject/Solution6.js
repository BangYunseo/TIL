// 모듈을 추출합니다.
var http = require('http');
var express = require('express');

// 변수를 선언합니다.
var items = [{
    name: "홍길동",
    dept: '정보통신공학과',
    sID : "s60161234"
}, {
    name: "김희자",
    dept: "컴퓨터공학과",
    sID : "s60191234"
}, {
    name: "박영희",
    dept: "전자공학과",
    sID : "s60131234"
}];

// 웹 서버를 생성합니다.
var app = express();
var router = express.Router();

app.use(express.static('public'));
app.use(router);

app.get('/', function (request, response) {
    response.send('<h1>Welcome to the Home Page</h1>');
});
// 라우트합니다.
app.all('/a', function (request, response) {
    response.send("<h1> Page A</h1>");
});
app.all('/b', function (request, response) {
    response.send("<h1> Page B</h1>");
});
app.all('/data.html', function (request, response) {
    var output = '';
    output += '<!DOCTYPE html>';
    output += '<html>';
    output += '<head>';
    output += '    <title>Data HTML</title>';
    output += '</head>';
    output += '<body>';
    items.forEach(function (item) {
        output += '<div>';
        output += '    <h1>' + item.name + '</h1>';
        output += '    <h2>' + item.price + '</h2>';
        output += '</div>';
    });
    output += '</body>';
    output += '</html>';
    response.send(output);
});

app.all('/data.json', function (request, response) {
    response.send(items);
});

app.all('/data.xml', function (request, response) {
    var output = '';
    output += '<?xml version="1.0" encoding="UTF-8" ?>';
    output += '<products>';
    items.forEach(function (item) {
        output += '<product>';
        output += '    <name2>' + item.name + '</name2>';
        output += '    <price>' + item.price + '</price>';
        output += '</product>';
    });
    output += '</products>';
    response.type('text/xml');
    response.send(output);
});

app.all('/parameter', function (request, response) {
    // 변수를 선언합니다.
    var name = request.query.name
    var dept = request.query.dept
    var sID = request.query.sID

    // 응답합니다.
    response.send('<h1>' + name + ':' + dept + ':' + sID + '</h1>');
});

app.all('/parameter/:id', function (request, response) {
    // 변수를 선언합니다.
    var id = request.params.id
    // 응답합니다.
    response.send('<h1>' + id + '</h1>');
});

app.get('/products', function (request, response) {
    response.send(items);
});

app.get('/products/:id', function (request, response) {
    // 변수를 선언합니다.
    var id = Number(request.params.id)
    if (isNaN(id)) {
        // 오류: 잘못된 경로
        response.send({
            error: '숫자를 입력하세요!'
        });
    } else if (items[id]) {
        // 정상
        response.send(items[id]);
    } else {
        // 오류: 요소가 없을 경우
        response.send({
            error: '존재하지 않는 데이터입니다!'
        });
    }
});

app.post('/products', function (request, response) {
    // 변수를 선언합니다.
    var name = request.query.name;
    var dept = request.query.dept;
    var sID = request.query.sID;

    console.log(name)
    var item = {
        name: name,
        dept: dept,
        sID : sID
    };

    // 데이터를 추가합니다.
    items.push(item);
    // 응답합니다.
    response.send({
        message: '데이터를 추가했습니다.',
        data: item
    });
});

app.put('/products/:id', function (request, response) {
    // 변수를 선언합니다.
    var id = Number(request.params.id);
    
    var name = request.query.name;
    var dept = request.query.dept;
    var sID = request.query.sID;

    if (items[id]) {
        // 데이터를 수정합니다.
        if (name) { items[id].name = name; }
        if (dept) { items[id].dept = dept; }
        if (sID) { items[id].sID = sID; }

        // 응답합니다.
        response.send({
            message: '데이터를 수정했습니다.',
            data: items[id]
        });
    } else {
        // 오류: 요소가 없을 경우
        response.send({
            error: '존재하지 않는 데이터입니다!'
        });
    }
});

app.delete('/products/:id', function (request, response) {
    // 변수를 선언합니다.
    var id = Number(request.params.id);

    if (isNaN(id)) {
        // 오류: 잘못된 경로
        response.send({
            error: '숫자를 입력하세요!'
        });
    } else if (items[id]) {
        // 정상: 데이터 삭제
        items.splice(id, 1);
        response.send({
            message: '데이터를 삭제했습니다.'
        });
    } else {
        // 오류: 요소가 없을 경우
        response.send({
            error: '존재하지 않는 데이터입니다!'
        });
    }
});

// 웹 서버를 실행합니다.
http.createServer(app).listen(52273, function () {
    console.log('Server Running at http://127.0.0.1:52273');
});
